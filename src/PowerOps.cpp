#include "./include/PowerOps.h"
#include <cmath>

/**
 * @file PowerOps.cpp
 * @brief Implements the PowerOps class — exponent and root operations.
 *
 * Uses <cmath> for the power() and sqrt() calls.
 * square() and cube() are computed directly to avoid unnecessary
 * floating-point overhead from std::pow for simple cases.
 */

// Raises base to the power of exponent using std::pow
double PowerOps::power(double base, double exponent) {
    return std::pow(base, exponent);
}

// Returns n squared — computed directly as n * n
double PowerOps::square(double n) {
    return n * n;
}

// Returns n cubed — computed directly as n * n * n
double PowerOps::cube(double n) {
    return n * n * n;
}

/**
 * Computes the square root of n.
 * If n is negative, square root is not real — returns false.
 * The caller (main.cpp) handles the error message.
 */
bool PowerOps::squareRoot(double n, double& result) {
    // Guard: square root of a negative number is not real
    if (n < 0) {
        return false;
    }

    result = std::sqrt(n);
    return true;
}
