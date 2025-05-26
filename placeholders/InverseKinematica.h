#ifndef IK_H
#define IK_H

#include "../include.h"

class InverseKinematica
{
public:
    InverseKinematica()
    {
    }

    /**
     * Calculate the angles of each joint
     * @param coordinates The 3D coordinates to calculate the angles for
     * @return An array of angles for each joint
     */
    array<Point, 6> coordToPoint(Vector3D coordinates)
    {
    }
};

#endif