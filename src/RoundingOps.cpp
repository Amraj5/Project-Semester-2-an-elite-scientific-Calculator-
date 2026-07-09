#include "../include/RoundingOps.h"
#include <cmath>

/**
 * @file RoundingOps.cpp
 * @brief Implements the RoundingOps class — rounding and value comparison.
 *
 * Uses <cmath> for std::round, std::ceil, and std::floor.
 * min() and max() are implemented with a simple ternary — no need
 * for <algorithm> since we are only comparing two values.
 */

// Rounds n to the nearest integer (0.5 rounds up)
double RoundingOps::round(double n) {
    return std::round(n);
}

// Returns the smallest integer not less than n (rounds up)
double RoundingOps::ceil(double n) {
    return std::ceil(n);
}

// Returns the largest integer not greater than n (rounds down)
double RoundingOps::floor(double n) {
    return std::floor(n);
}

// Returns the smaller of two values
double RoundingOps::min(double a, double b) {
    return (a < b) ? a : b;
}

// Returns the larger of two values
double RoundingOps::max(double a, double b) {
    return (a > b) ? a : b;
}
