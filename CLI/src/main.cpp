#include <iostream>
#include "payment_id/payment_id.h"

int main (int argc, char *argv[]) {
  if (argc == 2) {
    try {
      std::vector<uint8_t> const id = payment_id::create(argv[1]);
      payment_id::print(id);
      return 0;
    } catch(std::invalid_argument &e) {
      std::cerr << e.what() << std::endl;
    }
  } else {
    std::cerr << "Usage: " << argv[0] << " <invoice path>" << std::endl;
  }
  return 1;
}
