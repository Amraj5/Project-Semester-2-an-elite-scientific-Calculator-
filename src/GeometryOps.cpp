#include "include/GeometryOps.h"
#include <cmath>

/**
 * @file GeometryOps.cpp
 * @brief Implements the GeometryOps class — 3D geometric shape calculations.
 *
 * Each shape exposes two methods: volume and surface area.
 * All formulas use the PI constant defined below.
 *
 * Shapes covered:
 *   - Cylinder
 *   - Cone
 *   - Frustum (truncated cone)
 *   - Sphere
 *   - Cuboid
 */

static const double PI = 3.14159265358979323846;

// ─── Cylinder ────────────────────────────────────────────────────────────────

/**
 * Returns the volume of a cylinder.
 * Formula: V = π × r² × h
 *
 * @param radius  Radius of the circular base
 * @param height  Height of the cylinder
 */
double GeometryOps::cylinderVolume(double radius, double height) {
    return PI * radius * radius * height;
}

/**
 * Returns the total surface area of a cylinder (both bases + lateral).
 * Formula: A = 2π × r × (r + h)
 *
 * Breakdown:
 *   - Two circular bases: 2 × π × r²
 *   - Lateral surface:    2 × π × r × h
 *   - Combined:           2 × π × r × (r + h)
 *
 * @param radius  Radius of the circular base
 * @param height  Height of the cylinder
 */
double GeometryOps::cylinderSurfaceArea(double radius, double height) {
    return 2 * PI * radius * (radius + height);
}

// ─── Cone ────────────────────────────────────────────────────────────────────

/**
 * Returns the volume of a cone.
 * Formula: V = (1/3) × π × r² × h
 *
 * @param radius  Radius of the circular base
 * @param height  Perpendicular height of the cone
 */
double GeometryOps::coneVolume(double radius, double height) {
    return (1.0 / 3.0) * PI * radius * radius * height;
}

/**
 * Returns the total surface area of a cone (base + lateral).
 * Formula: A = π × r × (r + l)
 *   where slant height l = √(r² + h²)
 *
 * Breakdown:
 *   - Circular base:  π × r²
 *   - Lateral surface: π × r × l
 *   - Combined:        π × r × (r + l)
 *
 * @param radius  Radius of the circular base
 * @param height  Perpendicular height of the cone
 */
double GeometryOps::coneSurfaceArea(double radius, double height) {
    // Compute slant height using Pythagoras
    double slantHeight = std::sqrt(radius * radius + height * height);
    return PI * radius * (radius + slantHeight);
}

// ─── Frustum (Truncated Cone) ────────────────────────────────────────────────

/**
 * Returns the volume of a frustum (a cone with its top cut off).
 * Formula: V = (1/3) × π × h × (r1² + r2² + r1 × r2)
 *
 * @param r1      Radius of the bottom base (larger)
 * @param r2      Radius of the top base (smaller)
 * @param height  Perpendicular height of the frustum
 */
double GeometryOps::frustumVolume(double r1, double r2, double height) {
    return (1.0 / 3.0) * PI * height * (r1 * r1 + r2 * r2 + r1 * r2);
}

/**
 * Returns the total surface area of a frustum (both bases + lateral).
 * Formula: A = π × (r1 + r2) × l + π × r1² + π × r2²
 *   where slant height l = √(h² + (r1 - r2)²)
 *
 * Breakdown:
 *   - Bottom base:     π × r1²
 *   - Top base:        π × r2²
 *   - Lateral surface: π × (r1 + r2) × l
 *
 * @param r1      Radius of the bottom base
 * @param r2      Radius of the top base
 * @param height  Perpendicular height of the frustum
 */
double GeometryOps::frustumSurfaceArea(double r1, double r2, double height) {
    // Slant height along the angled side of the frustum
    double slantHeight = std::sqrt(height * height + (r1 - r2) * (r1 - r2));
    return PI * (r1 + r2) * slantHeight + PI * r1 * r1 + PI * r2 * r2;
}

// ─── Sphere ──────────────────────────────────────────────────────────────────

/**
 * Returns the volume of a sphere.
 * Formula: V = (4/3) × π × r³
 *
 * @param radius  Radius of the sphere
 */
double GeometryOps::sphereVolume(double radius) {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

/**
 * Returns the surface area of a sphere.
 * Formula: A = 4 × π × r²
 *
 * @param radius  Radius of the sphere
 */
double GeometryOps::sphereSurfaceArea(double radius) {
    return 4 * PI * radius * radius;
}

// ─── Cuboid ──────────────────────────────────────────────────────────────────

/**
 * Returns the volume of a cuboid.
 * Formula: V = l × w × h
 *
 * @param length  Length of the cuboid
 * @param width   Width of the cuboid
 * @param height  Height of the cuboid
 */
double GeometryOps::cuboidVolume(double length, double width, double height) {
    return length * width * height;
}

/**
 * Returns the total surface area of a cuboid.
 * Formula: A = 2 × (l×w + w×h + l×h)
 *
 * Breakdown — three unique face pairs:
 *   - Top & bottom:  l × w  (×2)
 *   - Front & back:  l × h  (×2)
 *   - Left & right:  w × h  (×2)
 *
 * @param length  Length of the cuboid
 * @param width   Width of the cuboid
 * @param height  Height of the cuboid
 */
double GeometryOps::cuboidSurfaceArea(double length, double width, double height) {
    return 2 * (length * width + width * height + length * height);
}
