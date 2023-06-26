/**
 * @file
 * @brief A happy number is a number whose sum of digits is calculated until the
 * sum is a single digit, and this sum turns out to be 1
 */

#include <iostream>

/**
 * Checks if a decimal number is a happy number
 * \returns true if happy else false
 */
template <typename T>
bool is_happy(T n) {
    T s;              // stores sum of digits
    while (n > 9) {       // while number is > 9, there are more than 1 digit
        s = 0;
        for(;n != 0;n /= 10) // get digit
            s += n % 10;
        n = s;
    }
    return (n == 1);  // true if k == 1
}

/** Main function */
// 55 is happy
int main() {
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;

    if (is_happy(n))
        std::cout << n << " is a happy number" << std::endl;
    else
        std::cout << n << " is not a happy number" << std::endl;
    return 0;
}
