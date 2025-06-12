#pragma once
#include "include.h"

namespace StandardPositions
{

    struct Position
    {
        Vector3D pos;
        Eigen::Matrix3f orientation;
    };

    // Oriëntatie voor fiches (Z wijst naar beneden)
    inline Eigen::Matrix3f defaultChipOrientation()
    {
        Eigen::Matrix3f R;
        R.col(0) = Eigen::Vector3f(0, 0, 0);  // X-as niet gebruikt
        R.col(1) = Eigen::Vector3f(1, 0, 0);  // Y-as naar rechts
        R.col(2) = Eigen::Vector3f(0, 0, -1); // Z-as naar beneden
        return R;
    }

    // Oriëntatie voor home-positie
    inline Eigen::Matrix3f homeOrientation()
    {
        Eigen::Matrix3f R;
        R.col(0) = Eigen::Vector3f(0, 0, 1); // X-as (placeholder)
        R.col(1) = Eigen::Vector3f(0, 0, 0); // Y-as (niet gebruikt)
        R.col(2) = Eigen::Vector3f(0, 0, 0); // Z-as (placeholder)
        return R;
    }

    // Standaardposities
    const Position HOME = {Vector3D(0.0f, 0.0f, 0.25f), homeOrientation()};

    const Position COL_A = {Vector3D(0.25f, -0.18f, 0.300f), defaultChipOrientation()};
    const Position COL_B = {Vector3D(0.25f, -0.12f, 0.300f), defaultChipOrientation()};
    const Position COL_C = {Vector3D(0.25f, -0.06f, 0.300f), defaultChipOrientation()};
    const Position COL_D = {Vector3D(0.25f, 0.00f, 0.300f), defaultChipOrientation()};
    const Position COL_E = {Vector3D(0.25f, 0.06f, 0.300f), defaultChipOrientation()};
    const Position COL_F = {Vector3D(0.25f, 0.12f, 0.300f), defaultChipOrientation()};
    const Position COL_G = {Vector3D(0.25f, 0.18f, 0.300f), defaultChipOrientation()};

    // Ophalen via karakter ('A' t/m 'G' of 'H' voor home)
    inline Position getPosition(char col)
    {
        switch (col)
        {
        case 'A':
            return COL_A;
        case 'B':
            return COL_B;
        case 'C':
            return COL_C;
        case 'D':
            return COL_D;
        case 'E':
            return COL_E;
        case 'F':
            return COL_F;
        case 'G':
            return COL_G;
        case 'H':
            return HOME;
        case '0':
            return HOME; // eventueel fallback
        default:
            throw std::out_of_range("Ongeldige kolomletter (alleen 'A'-'G' of 'H' voor home)");
        }
    }

    // Ophalen via index (0 t/m 6 → 'A' t/m 'G')
    inline Position getPosition(int colIndex)
    {
        if (colIndex < 0 || colIndex > 7)
            throw std::out_of_range("Ongeldige kolomindex (alleen 0 t/m 6 zijn toegestaan)");

        char colChar = 'A' + colIndex;
        return getPosition(colChar);
    }

}
