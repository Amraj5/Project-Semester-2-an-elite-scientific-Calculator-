#include "BasicOps.h"

/**
 * @file BasicOps.cpp
 * @brief Implements the BasicOps class — fundamental arithmetic operations.
 *
 * All four operations work on double-precision floating point numbers
 * so the calculator handles both integers and decimals seamlessly.
 */

// Adds two numbers and returns the result
double BasicOps::add(double a, double b) {
    return a + b;
}

// Subtracts b from a and returns the result
double BasicOps::subtract(double a, double b) {
    return a - b;
}

// Multiplies two numbers and returns the result
double BasicOps::multiply(double a, double b) {
    return a * b;
}

/**
 * Divides a by b.
 * If b is zero, the function writes nothing to result and returns false.
 * The caller (main.cpp) is responsible for displaying an error message
 * when false is returned.
 */
bool BasicOps::divide(double a, double b, double& result) {
    // Guard: division by zero is undefined — signal failure to caller
    if (b == 0) {
        return false;
    }

    result = a / b;
    return true;
}
