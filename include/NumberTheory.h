#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H

#include <vector>

/**
 * @file NumberTheory.h
 * @brief Declares the NumberTheory class for number-based logic and calculations.
 *
 * Covers GCD, LCM, prime checking, Armstrong checking, palindrome checking,
 * and computing the average of a user-supplied list of numbers.
 */

class NumberTheory {
public:
    // Returns the Greatest Common Divisor of two integers
    int gcd(int a, int b);

    // Returns the Least Common Multiple of two integers
    int lcm(int a, int b);

    // Returns true if n is a prime number
    bool isPrime(int n);

    // Returns true if n is an Armstrong number
    bool isArmstrong(int n);

    /**
     * Checks if a number is a palindrome.
     * The number must have at least 3 digits (enforced by the caller via main).
     * @return true if the number reads the same forwards and backwards.
     */
    bool isPalindrome(int n);

    /**
     * Computes the average of a list of numbers.
     * @param numbers  A vector of values supplied by the user.
     * @return The arithmetic mean of all values in the vector.
     */
    double average(const std::vector<double>& numbers);
};

#endif // NUMBERTHEORY_H
