#ifndef BASICOPS_H
#define BASICOPS_H

/**
 * @file BasicOps.h
 * @brief Declares the BasicOps class for fundamental arithmetic operations.
 *
 * Covers addition, subtraction, multiplication, and division.
 * Division guards against divide-by-zero by returning a boolean
 * success flag and writing the result to an output parameter.
 */

class BasicOps {
public:
    // Returns the sum of two numbers
    double add(double a, double b);

    // Returns the difference of two numbers (a - b)
    double subtract(double a, double b);

    // Returns the product of two numbers
    double multiply(double a, double b);

    /**
     * Divides a by b.
     * @param result  Written with the quotient if division succeeds.
     * @return true if division was successful, false if b == 0.
     */
    bool divide(double a, double b, double& result);
};

#endif // BASICOPS_H
