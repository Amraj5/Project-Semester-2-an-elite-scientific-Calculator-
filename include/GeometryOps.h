#ifndef GEOMETRYOPS_H
#define GEOMETRYOPS_H

/**
 * @file GeometryOps.h
 * @brief Declares the GeometryOps class for 3D geometric shape calculations.
 *
 * Each shape exposes two methods: volume and surface area.
 * This is your team's discretionary addition to the original spec.
 * Teammate 4 owns implementation decisions (e.g. additional shapes).
 *
 * Shapes currently covered:
 *   - Cylinder
 *   - Cone
 *   - Frustum (truncated cone)
 *   - Sphere
 *   - Cuboid
 */

class GeometryOps {
public:
    // --- Cylinder ---
    double cylinderVolume(double radius, double height);
    double cylinderSurfaceArea(double radius, double height);

    // --- Cone ---
    double coneVolume(double radius, double height);
    double coneSurfaceArea(double radius, double height);  // includes base

    // --- Frustum (truncated cone) ---
    // r1 = bottom radius, r2 = top radius
    double frustumVolume(double r1, double r2, double height);
    double frustumSurfaceArea(double r1, double r2, double height);

    // --- Sphere ---
    double sphereVolume(double radius);
    double sphereSurfaceArea(double radius);

    // --- Cuboid ---
    double cuboidVolume(double length, double width, double height);
    double cuboidSurfaceArea(double length, double width, double height);
};

#endif // GEOMETRYOPS_H
