#ifndef TRIGOPS_H
#define TRIGOPS_H

/**
 * @file TrigOps.h
 * @brief Declares the TrigOps class for trigonometric and exponential operations.
 *
 * All trig functions accept input in degrees. Conversion to radians
 * is handled internally — callers do not need to convert.
 * Inverse trig functions (asin, acos, atan) return results in degrees.
 */

class TrigOps {
public:
    // Returns the sine of angle (in degrees)
    double sinDeg(double degrees);

    // Returns the cosine of angle (in degrees)
    double cosDeg(double degrees);

    /**
     * Returns the arcsine of x in degrees.
     * @param x  Must be in the range [-1, 1]. Returns false otherwise.
     */
    bool asinDeg(double x, double& result);

    /**
     * Returns the arccosine of x in degrees.
     * @param x  Must be in the range [-1, 1]. Returns false otherwise.
     */
    bool acosDeg(double x, double& result);

    // Returns the arctangent of x in degrees
    double atanDeg(double x);

    // Returns e raised to the power of x
    double exponential(double x);

private:
    // Converts degrees to radians for internal cmath calls
    double toRadians(double degrees);

    // Converts radians to degrees for returning inverse trig results
    double toDegrees(double radians);
};

#endif // TRIGOPS_H
