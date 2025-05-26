#ifndef COORD_H
#define COORD_H

#include "../include.h"

/**
 * Basic implementation of an (X,Y,Z) Coordinate
 */
class Vector3D
{
public:
    float x, y, z;
    constexpr Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
};

/*
 * Just a way to define angles with posibility to add extra functionality
 */
class Point
{
public:
    float angle;
    constexpr Point(float angle = 0) : angle(angle) {}
};

// NOT SET UP YET!
constexpr array<Vector3D, 7>
    ColumnToVector = {
        /* A */ Vector3D(0.0f, 0.0f, 0.0f),
        /* B */ Vector3D(1.0f, 0.0f, 0.0f),
        /* C */ Vector3D(0.0f, 1.0f, 0.0f),
        /* D */ Vector3D(0.0f, 0.0f, 1.0f),
        /* E */ Vector3D(1.0f, 1.0f, 0.0f),
        /* F */ Vector3D(1.0f, 0.0f, 1.0f),
        /* G */ Vector3D(0.0f, 1.0f, 1.0f)};

#endif