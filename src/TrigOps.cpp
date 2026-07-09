#include "../include/TrigOps.h"
#include <cmath>

/**
 * @file TrigOps.cpp
 * @brief Implements the TrigOps class — trigonometric and exponential operations.
 *
 * All public functions accept and return values in degrees.
 * Internally, toRadians() and toDegrees() handle conversion
 * before and after every <cmath> call, since <cmath> works in radians.
 *
 * The private helpers are defined at the bottom of this file.
 */

// The value of PI used for degree/radian conversion
static const double PI = 3.14159265358979323846;

// ─── Trigonometric Functions ─────────────────────────────────────────────────

/**
 * Returns the sine of an angle given in degrees.
 * Converts to radians internally before calling std::sin.
 */
double TrigOps::sinDeg(double degrees) {
    return std::sin(toRadians(degrees));
}

/**
 * Returns the cosine of an angle given in degrees.
 * Converts to radians internally before calling std::cos.
 */
double TrigOps::cosDeg(double degrees) {
    return std::cos(toRadians(degrees));
}

/**
 * Returns the arcsine of x in degrees.
 *
 * Domain restriction: x must be in [-1, 1].
 * If x is outside this range, std::asin returns NaN — we guard
 * against this and return false so main.cpp can show an error.
 *
 * @param x       Input value, must be in [-1.0, 1.0]
 * @param result  Written with the arcsine in degrees if successful
 * @return true if x is in valid domain, false otherwise
 */
bool TrigOps::asinDeg(double x, double& result) {
    // Guard: asin is only defined for x in [-1, 1]
    if (x < -1.0 || x > 1.0) {
        return false;
    }

    result = toDegrees(std::asin(x));
    return true;
}

/**
 * Returns the arccosine of x in degrees.
 *
 * Domain restriction: x must be in [-1, 1].
 * Same guard pattern as asinDeg.
 *
 * @param x       Input value, must be in [-1.0, 1.0]
 * @param result  Written with the arccosine in degrees if successful
 * @return true if x is in valid domain, false otherwise
 */
bool TrigOps::acosDeg(double x, double& result) {
    // Guard: acos is only defined for x in [-1, 1]
    if (x < -1.0 || x > 1.0) {
        return false;
    }

    result = toDegrees(std::acos(x));
    return true;
}

/**
 * Returns the arctangent of x in degrees.
 *
 * atan has no domain restriction — it accepts all real numbers
 * and returns a value in (-90°, 90°).
 */
double TrigOps::atanDeg(double x) {
    return toDegrees(std::atan(x));
}

// ─── Exponential Function ────────────────────────────────────────────────────

/**
 * Returns e raised to the power of x (e^x).
 * Uses std::exp from <cmath>.
 *
 * Example: exponential(1)  → 2.71828...
 *          exponential(0)  → 1.0
 *          exponential(-1) → 0.36787...
 */
double TrigOps::exponential(double x) {
    return std::exp(x);
}

// ─── Private Helpers ─────────────────────────────────────────────────────────

/**
 * Converts an angle from degrees to radians.
 * Formula: radians = degrees × (π / 180)
 */
double TrigOps::toRadians(double degrees) {
    return degrees * (PI / 180.0);
}

/**
 * Converts an angle from radians to degrees.
 * Formula: degrees = radians × (180 / π)
 */
double TrigOps::toDegrees(double radians) {
    return radians * (180.0 / PI);
}
