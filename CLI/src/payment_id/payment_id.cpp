#include <fstream>
#include <iomanip>
#include <iostream>
#include "payment_id.h"
extern "C" {
  #include "../../../src/crypto/blake256.h"
}

namespace {
  std::vector<uint8_t> read_invoice(char const * const path) {
    std::ifstream file(path, std::ios::binary|std::ios::ate);
    if (file.is_open()) {
      std::streampos file_size = file.tellg();
      std::vector<uint8_t> buffer(file_size);
      file.seekg(0, std::ios::beg);
      file.read((char*)buffer.data(), file_size);
      file.close();
      return buffer;
    }
    throw std::invalid_argument("The provided file could not be opened");
  }

  uint_fast64_t normalize_vat_endianness(uint_fast64_t const vat) {
    uint_fast32_t const test = 0xAA0000BB;
    bool const is_little = *((uint8_t *)&test) == 0xBB;
    if (is_little) {
      uint_fast64_t big_vat;
      big_vat = (vat & 0x0000000000FF) << 40;
      big_vat |= (vat & 0x00000000FF00) << 24;
      big_vat |= (vat & 0x000000FF0000) << 8;
      big_vat |= (vat & 0x0000FF000000) >> 8;
      big_vat |= (vat & 0x00FF00000000) >> 24;
      big_vat |= (vat & 0xFF0000000000) >> 40;
      return big_vat;
    }
    return vat;
  }

  std::string buffer_to_hex(std::vector<uint8_t> const & buf) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (uint8_t const byte : buf) {
      ss << std::setw(2) << (unsigned)byte;
    }
    return ss.str();
  }

  std::vector<uint8_t> append_vat(std::vector<uint8_t> & hash, uint_fast64_t const vat) {
    uint8_t const * const vat_ptr = (uint8_t *)&vat;
    uint8_t * hash_ptr = hash.data() + 26;
    *hash_ptr++ = vat_ptr[0];
    *hash_ptr++ = vat_ptr[1];
    *hash_ptr++ = vat_ptr[2];
    *hash_ptr++ = vat_ptr[3];
    *hash_ptr++ = vat_ptr[4];
    *hash_ptr++ = vat_ptr[5];
    return hash;
  }

  uint_fast64_t vat_prompt() {
    uint_fast64_t vat, max_vat = 0x0000FFFFFFFFFFFF;
    do {
      std::cout << "Insert an integral VAT number between 0 and " << max_vat << ": ";
      std::cin >> vat;
    } while (vat > max_vat);
    return normalize_vat_endianness(vat);
  }
}

namespace payment_id {
  std::vector<uint8_t> create(char const * const invoice_path) {
    std::vector<uint8_t> invoice = read_invoice(invoice_path);
    std::vector<uint8_t> hash(32);
    blake256_hash(hash.data(), invoice.data(), invoice.size());
    return append_vat(hash, vat_prompt());
  }

  void print(std::vector<uint8_t> const & payment_id) {
    std::cout << buffer_to_hex(payment_id) << std::endl;
  }
}
