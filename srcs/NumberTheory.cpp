#include "NumberTheory.h"
#include <cmath>
#include <vector>
#include <string>

/**
 * @file NumberTheory.cpp
 * @brief Implements the NumberTheory class — number-based logic and calculations.
 *
 * Covers GCD, LCM, prime checking, Armstrong checking,
 * palindrome checking, and average of a list of numbers.
 */

/**
 * Computes the Greatest Common Divisor of two integers
 * using the Euclidean algorithm.
 *
 * Logic: repeatedly replace (a, b) with (b, a % b) until b == 0.
 * The last non-zero remainder is the GCD.
 *
 * Example: gcd(48, 18)
 *   48 % 18 = 12  → (18, 12)
 *   18 % 12 = 6   → (12, 6)
 *   12 %  6 = 0   → GCD = 6
 */
int NumberTheory::gcd(int a, int b) {
    // Euclidean algorithm — loop until remainder is zero
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a; // a holds the GCD when b reaches 0
}

/**
 * Computes the Least Common Multiple of two integers.
 *
 * Logic: LCM(a, b) = (a * b) / GCD(a, b)
 * We divide before multiplying to reduce risk of integer overflow.
 */
int NumberTheory::lcm(int a, int b) {
    // Divide first to avoid overflow on large inputs
    return (a / gcd(a, b)) * b;
}

/**
 * Checks whether n is a prime number.
 *
 * Logic:
 *   - Numbers <= 1 are not prime by definition.
 *   - 2 and 3 are prime.
 *   - Even numbers and multiples of 3 are not prime.
 *   - For all remaining candidates, we only check divisors up to sqrt(n)
 *     in steps of 6 (i.e. checking i and i+2), which covers all primes
 *     efficiently without checking every number.
 */
bool NumberTheory::isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    if (n <= 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // eliminate even numbers and multiples of 3

    // Check divisors of the form 6k ± 1 up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; // found a divisor — not prime
        }
    }
    return true;
}

/**
 * Checks whether n is an Armstrong number.
 *
 * An Armstrong number (narcissistic number) is one where the sum of
 * its digits each raised to the power of the number of digits equals n.
 *
 * Example: 153 → digits: 1, 5, 3 → count: 3
 *   1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153 ✓
 *
 * Example: 9474 → digits: 9, 4, 7, 4 → count: 4
 *   9^4 + 4^4 + 7^4 + 4^4 = 6561 + 256 + 2401 + 256 = 9474 ✓
 */
bool NumberTheory::isArmstrong(int n) {
    int original = n;
    int digitCount = 0;
    int temp = n;

    // Count the number of digits in n
    while (temp != 0) {
        digitCount++;
        temp /= 10;
    }

    // Sum each digit raised to the power of digitCount
    int sum = 0;
    temp = n;
    while (temp != 0) {
        int digit = temp % 10;                          // extract last digit
        sum += (int)std::pow(digit, digitCount);        // raise to power and accumulate
        temp /= 10;                                     // remove last digit
    }

    return sum == original; // Armstrong if sum matches the original number
}

/**
 * Checks whether n is a palindrome.
 *
 * Logic: convert n to a string, then compare it against its reverse.
 * The 3-digit minimum is enforced by main.cpp before this is called.
 *
 * Example: 121 → "121" reversed → "121" → palindrome ✓
 * Example: 123 → "123" reversed → "321" → not a palindrome ✗
 */
bool NumberTheory::isPalindrome(int n) {
    std::string original = std::to_string(n);
    std::string reversed = std::string(original.rbegin(), original.rend());
    return original == reversed;
}

/**
 * Computes the arithmetic mean of a list of numbers.
 *
 * Logic: sum all values, divide by the count.
 * The caller (main.cpp) is responsible for collecting the numbers
 * from the user and passing them in as a vector.
 *
 * Returns 0.0 if the vector is empty to avoid division by zero.
 */
double NumberTheory::average(const std::vector<double>& numbers) {
    // Guard: empty list has no meaningful average
    if (numbers.empty()) {
        return 0.0;
    }

    double sum = 0.0;

    // Accumulate all values in the list
    for (double num : numbers) {
        sum += num;
    }

    return sum / numbers.size(); // arithmetic mean
}
