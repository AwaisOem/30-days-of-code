

#include <cassert>   /// for assert
#include <iostream>  /// for IO operations

/**
 * @namespace bit_manipulation
 * @brief Bit manipulation algorithms
 */
namespace bit_manipulation {
/**
 * @namespace count_of_trailing_ciphers_in_factorial_n
 * @brief Functions for the [Count the number of
 * ciphers](https://www.tutorialspoint.com/count-trailing-zeros-in-factorial-of-a-number-in-cplusplus)
 * in `n!` implementation
 */
namespace count_of_trailing_ciphers_in_factorial_n {
/**
 * @brief Function to count the number of the trailing ciphers
 * @param n number for which `n!` ciphers are returned
 * @return count, Number of ciphers in `n!`.
 */
uint64_t numberOfCiphersInFactorialN(uint64_t n) {
    // count is to store the number of 5's in factorial(n)
    uint64_t count = 0;

    // Keep dividing n by powers of
    // 5 and update count
    for (uint64_t i = 5; n / i >= 1; i *= 5) {
        count += static_cast<uint64_t>(n) / i;
    }

    return count;
}
}  // namespace count_of_trailing_ciphers_in_factorial_n
}  // namespace bit_manipulation

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    // 1st test
    std::cout << "1st test ";
    assert(bit_manipulation::count_of_trailing_ciphers_in_factorial_n::
               numberOfCiphersInFactorialN(395) == 97);
    std::cout << "passed" << std::endl;

    // 2nd test
    std::cout << "2nd test ";
    assert(bit_manipulation::count_of_trailing_ciphers_in_factorial_n::
               numberOfCiphersInFactorialN(977) == 242);
    std::cout << "passed" << std::endl;

    // 3rd test
    std::cout << "3rd test ";
    assert(bit_manipulation::count_of_trailing_ciphers_in_factorial_n::
               numberOfCiphersInFactorialN(871) == 215);
    std::cout << "passed" << std::endl;

    // 4th test
    std::cout << "4th test ";
    assert(bit_manipulation::count_of_trailing_ciphers_in_factorial_n::
               numberOfCiphersInFactorialN(239) == 57);
    std::cout << "passed" << std::endl;

    // 5th test
    std::cout << "5th test ";
    assert(bit_manipulation::count_of_trailing_ciphers_in_factorial_n::
               numberOfCiphersInFactorialN(0) == 0);
    std::cout << "passed" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // run self-test implementations
    return 0;
}
