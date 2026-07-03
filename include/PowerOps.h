#ifndef POWEROPS_H
#define POWEROPS_H

/**
 * @file PowerOps.h
 * @brief Declares the PowerOps class for exponent and root operations.
 *
 * Covers raising to a power, squaring, cubing, and square root.
 * Square root guards against negative input using a boolean return pattern.
 */

class PowerOps {
public:
    // Returns base raised to the power of exponent
    double power(double base, double exponent);

    // Returns the square of a number (n * n)
    double square(double n);

    // Returns the cube of a number (n * n * n)
    double cube(double n);

    /**
     * Computes the square root of n.
     * @param result  Written with the square root if n >= 0.
     * @return true if successful, false if n is negative.
     */
    bool squareRoot(double n, double& result);
};

#endif // POWEROPS_H
