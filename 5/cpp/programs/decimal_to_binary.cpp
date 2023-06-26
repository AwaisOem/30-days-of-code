/**
 * @file
 * @brief Function to convert decimal number to binary representation
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/**
 * This method converts the bit representation and stores it as a decimal
 * number.
 */
int method1(int number) {
    int binary=0;
    for(int var = 1; number > 0; number /= 2 , var *= 10)
        binary += ((number % 2) * var);
    return binary;
}

/**
 * This method stores each bit value from LSB to MSB and then prints them back
 * from MSB to LSB
 */
string method2(int number) {
    string bits;
    for(;number > 0;number >>= 1) bits+= number & 0x01 ? '1':'0';
    reverse(bits.begin() , bits.end());
    return bits;
}

int main() {
    int number;
    std::cout << "Enter a number:";
    std::cin >> number;

    cout<< method1(number)<<endl;
    cout<< method2(number)<< endl;

    return 0;
}
