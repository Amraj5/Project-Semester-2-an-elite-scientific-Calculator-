#include <iostream>
#include <vector>
#include <limits>

#include "BasicOps.h"
#include "PowerOps.h"
#include "RoundingOps.h"
#include "NumberTheory.h"
#include "TrigOps.h"
#include "GeometryOps.h"

/**
 * @file main.cpp
 * @brief Entry point for the Console-Based Calculator.
 *
 * Displays a numbered menu, reads the user's choice, and dispatches
 * to the relevant class. Loops until the user selects Exit.
 *
 * All class instances are created once at the top of main() and reused
 * for every operation — this avoids unnecessary object creation inside
 * the loop and keeps the design clean OOP practice.
 */

using namespace std;

// ─── Forward declarations of helper functions ───────────────────────────────
void displayMenu();
double getNumber(const string& prompt);
int getInteger(const string& prompt);
void clearInputBuffer();

int main() {
    // One instance of each class — created once, reused throughout
    BasicOps basicOps;
    PowerOps powerOps;
    RoundingOps roundingOps;
    NumberTheory numberTheory;
    TrigOps trigOps;
    GeometryOps geometryOps;

    int choice = 0;

    // Main program loop — runs until the user selects Exit
    while (true) {
        displayMenu();
        choice = getInteger("Enter your choice: ");

        switch (choice) {

            // ─── Basic Arithmetic ───────────────────────────────────────────
            case 1: { // Addition
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << basicOps.add(a, b) << endl;
                break;
            }
            case 2: { // Subtraction
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << basicOps.subtract(a, b) << endl;
                break;
            }
            case 3: { // Multiplication
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << basicOps.multiply(a, b) << endl;
                break;
            }
            case 4: { // Division
                double a = getNumber("Enter numerator: ");
                double b = getNumber("Enter denominator: ");
                double result;
                if (basicOps.divide(a, b, result)) {
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            }

            // ─── Power & Roots ──────────────────────────────────────────────
            case 5: { // Power
                double base = getNumber("Enter base: ");
                double exp = getNumber("Enter exponent: ");
                cout << "Result: " << powerOps.power(base, exp) << endl;
                break;
            }
            case 6: { // Square
                double n = getNumber("Enter number: ");
                cout << "Result: " << powerOps.square(n) << endl;
                break;
            }
            case 7: { // Cube
                double n = getNumber("Enter number: ");
                cout << "Result: " << powerOps.cube(n) << endl;
                break;
            }
            case 8: { // Square Root
                double n = getNumber("Enter number: ");
                double result;
                if (powerOps.squareRoot(n, result)) {
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Cannot compute square root of a negative number." << endl;
                }
                break;
            }

            // ─── Rounding & Comparison ──────────────────────────────────────
            case 9: { // Round
                double n = getNumber("Enter number: ");
                cout << "Result: " << roundingOps.round(n) << endl;
                break;
            }
            case 10: { // Ceiling
                double n = getNumber("Enter number: ");
                cout << "Result: " << roundingOps.ceil(n) << endl;
                break;
            }
            case 11: { // Floor
                double n = getNumber("Enter number: ");
                cout << "Result: " << roundingOps.floor(n) << endl;
                break;
            }
            case 12: { // Min
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << roundingOps.min(a, b) << endl;
                break;
            }
            case 13: { // Max
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << roundingOps.max(a, b) << endl;
                break;
            }

            // ─── Trigonometric Functions ─────────────────────────────────────
            case 14: { // Sin
                double deg = getNumber("Enter angle in degrees: ");
                cout << "Result: " << trigOps.sinDeg(deg) << endl;
                break;
            }
            case 15: { // Cos
                double deg = getNumber("Enter angle in degrees: ");
                cout << "Result: " << trigOps.cosDeg(deg) << endl;
                break;
            }
            case 16: { // Asin
                double x = getNumber("Enter value (must be between -1 and 1): ");
                double result;
                if (trigOps.asinDeg(x, result)) {
                    cout << "Result: " << result << " degrees" << endl;
                } else {
                    cout << "Error: Input must be between -1 and 1." << endl;
                }
                break;
            }
            case 17: { // Acos
                double x = getNumber("Enter value (must be between -1 and 1): ");
                double result;
                if (trigOps.acosDeg(x, result)) {
                    cout << "Result: " << result << " degrees" << endl;
                } else {
                    cout << "Error: Input must be between -1 and 1." << endl;
                }
                break;
            }
            case 18: { // Atan
                double x = getNumber("Enter value: ");
                cout << "Result: " << trigOps.atanDeg(x) << " degrees" << endl;
                break;
            }
            case 19: { // Exponential
                double x = getNumber("Enter exponent (e^x): ");
                cout << "Result: " << trigOps.exponential(x) << endl;
                break;
            }

            // ─── Number Theory ───────────────────────────────────────────────
            case 20: { // Palindrome
                int n = getInteger("Enter a number with at least 3 digits: ");
                // Enforce minimum 3-digit requirement from the spec
                if (n < 100 && n > -100) {
                    cout << "Error: Number must have at least 3 digits." << endl;
                } else {
                    bool result = numberTheory.isPalindrome(n);
                    cout << n << " is " << (result ? "a palindrome." : "not a palindrome.") << endl;
                }
                break;
            }
            case 21: { // Armstrong
                int n = getInteger("Enter a number: ");
                bool result = numberTheory.isArmstrong(n);
                cout << n << " is " << (result ? "an Armstrong number." : "not an Armstrong number.") << endl;
                break;
            }
            case 22: { // Prime
                int n = getInteger("Enter a number: ");
                bool result = numberTheory.isPrime(n);
                cout << n << " is " << (result ? "a prime number." : "not a prime number.") << endl;
                break;
            }
            case 23: { // Average
                int count = getInteger("Enter number of entries: ");
                if (count <= 0) {
                    cout << "Error: Number of entries must be greater than zero." << endl;
                    break;
                }
                vector<double> numbers;
                for (int i = 0; i < count; i++) {
                    double val = getNumber("Enter value " + to_string(i + 1) + ": ");
                    numbers.push_back(val);
                }
                cout << "Average: " << numberTheory.average(numbers) << endl;
                break;
            }
            case 24: { // GCD
                int a = getInteger("Enter first integer: ");
                int b = getInteger("Enter second integer: ");
                cout << "Result: " << numberTheory.gcd(a, b) << endl;
                break;
            }
            case 25: { // LCM
                int a = getInteger("Enter first integer: ");
                int b = getInteger("Enter second integer: ");
                cout << "Result: " << numberTheory.lcm(a, b) << endl;
                break;
            }

            // ─── Geometry (Team Discretionary Additions) ──────────────────────
            case 26: { // Cylinder
                double r = getNumber("Enter radius: ");
                double h = getNumber("Enter height: ");
                cout << "Volume: " << geometryOps.cylinderVolume(r, h) << endl;
                cout << "Surface Area: " << geometryOps.cylinderSurfaceArea(r, h) << endl;
                break;
            }
            case 27: { // Cone
                double r = getNumber("Enter radius: ");
                double h = getNumber("Enter height: ");
                cout << "Volume: " << geometryOps.coneVolume(r, h) << endl;
                cout << "Surface Area: " << geometryOps.coneSurfaceArea(r, h) << endl;
                break;
            }
            case 28: { // Frustum
                double r1 = getNumber("Enter bottom radius: ");
                double r2 = getNumber("Enter top radius: ");
                double h = getNumber("Enter height: ");
                cout << "Volume: " << geometryOps.frustumVolume(r1, r2, h) << endl;
                cout << "Surface Area: " << geometryOps.frustumSurfaceArea(r1, r2, h) << endl;
                break;
            }
            case 29: { // Sphere
                double r = getNumber("Enter radius: ");
                cout << "Volume: " << geometryOps.sphereVolume(r) << endl;
                cout << "Surface Area: " << geometryOps.sphereSurfaceArea(r) << endl;
                break;
            }
            case 30: { // Cuboid
                double l = getNumber("Enter length: ");
                double w = getNumber("Enter width: ");
                double h = getNumber("Enter height: ");
                cout << "Volume: " << geometryOps.cuboidVolume(l, w, h) << endl;
                cout << "Surface Area: " << geometryOps.cuboidSurfaceArea(l, w, h) << endl;
                break;
            }

            // ─── Exit ───────────────────────────────────────────────────────
            case 0:
                cout << "Exiting calculator. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option from the menu." << endl;
                break;
        }

        cout << endl; // spacing before menu reprints
    }

    return 0;
}

/**
 * Displays the full menu of available operations.
 * Grouped by category for readability, matching the class structure.
 */
void displayMenu() {
    cout << "========================================" << endl;
    cout << "       CONSOLE-BASED CALCULATOR" << endl;
    cout << "========================================" << endl;
    cout << " Basic Arithmetic" << endl;
    cout << "  1. Addition          2. Subtraction" << endl;
    cout << "  3. Multiplication    4. Division" << endl;
    cout << " Power & Roots" << endl;
    cout << "  5. Power             6. Square" << endl;
    cout << "  7. Cube              8. Square Root" << endl;
    cout << " Rounding & Comparison" << endl;
    cout << "  9. Round            10. Ceiling" << endl;
    cout << " 11. Floor            12. Min" << endl;
    cout << " 13. Max" << endl;
    cout << " Trigonometry" << endl;
    cout << " 14. Sin              15. Cos" << endl;
    cout << " 16. Asin             17. Acos" << endl;
    cout << " 18. Atan             19. Exponential (e^x)" << endl;
    cout << " Number Theory" << endl;
    cout << " 20. Palindrome Check 21. Armstrong Check" << endl;
    cout << " 22. Prime Check      23. Average" << endl;
    cout << " 24. GCD              25. LCM" << endl;
    cout << " Geometry" << endl;
    cout << " 26. Cylinder         27. Cone" << endl;
    cout << " 28. Frustum          29. Sphere" << endl;
    cout << " 30. Cuboid" << endl;
    cout << "----------------------------------------" << endl;
    cout << "  0. Exit" << endl;
    cout << "========================================" << endl;
}

/**
 * Prompts the user with the given message and reads a double.
 * Re-prompts on invalid input (e.g. letters typed instead of a number).
 */
double getNumber(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a numeric value: ";
        clearInputBuffer();
    }
    return value;
}

/**
 * Prompts the user with the given message and reads an integer.
 * Re-prompts on invalid input.
 */
int getInteger(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter an integer value: ";
        clearInputBuffer();
    }
    return value;
}

/**
 * Clears the input stream's fail state and discards bad input
 * so the next read attempt doesn't loop forever on the same bad token.
 */
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
