#ifndef ROUNDINGOPS_H
#define ROUNDINGOPS_H

/**
 * @file RoundingOps.h
 * @brief Declares the RoundingOps class for rounding and value comparison.
 *
 * Covers round, ceiling, floor, and finding the min/max of two values.
 */

class RoundingOps {
public:
    // Rounds n to the nearest integer
    double round(double n);

    // Returns the smallest integer greater than or equal to n
    double ceil(double n);

    // Returns the largest integer less than or equal to n
    double floor(double n);

    // Returns the smaller of two values
    double min(double a, double b);

    // Returns the larger of two values
    double max(double a, double b);
};

#endif // ROUNDINGOPS_H