#ifndef SC_H
#define SC_H

#include "../include.h"

class SystemControl
{
public:
    SystemControl()
    {
    }
    /**
     * Set the robot arm in its default position
     */
    void goHome() {}

    /**
     * Fetch a disc from the queue
     */
    void fetchDisc() {}

    /**
     * Open the gripper and then close it
     */
    void dropDisc()
    {
    }

    /**
     * Go to a location
     */
    void goTo() {}

    /**
     * Convert a Column to a 3D coordinate
     * @param column The column to convert
     * @return The 3D coordinate of the column
     */
    Vector3D ColumnToCoord(Column column)
    {
        return ColumnToVector[column];
    }

    /**
     * Run the robot arm to fetch a disk and then play it
     * @param move The column to drop the disc in
     * @param IK The Inverse Kinematics object to calculate the angles
     */
    void run(Column move, InverseKinematica IK)
    {
        goHome();
        fetchDisc();
        Vector3D coord = ColumnToCoord(move);
        array<Point, 6> angles = IK.coordToPoint(coord);

        // for each angle, turn motors on
        dropDisc();
        goHome();
    }
};

#endif