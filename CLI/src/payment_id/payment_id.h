#pragma once

#include <vector>

namespace payment_id {
  /**
   * @brief Compute a payment ID for the given invoice,
   * by reading the VAT number from stdin.
   * 
   * @param invoice_path The path of the invoice
   */
  std::vector<uint8_t> create(char const * const invoice_path);

  /**
   * @brief Print the payment ID in hex format on stdout.
   */
  void print(std::vector<uint8_t> const & payment_id);
}
