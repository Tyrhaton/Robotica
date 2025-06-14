#ifndef INCLUDE_H
#define INCLUDE_H

#include <iostream>
#include <string>
#include <array>
#include <stdexcept>
#include <vector>
#include <set>
#include <unistd.h>
#include <cstddef> 


using namespace std;

#include "./modules/ik-lib/robot_arm/include/Vector3D.hpp"

#include "standard_positions.hpp"

#include "./modules/connect4GameTheorie/include.h"
#include "./modules/connect4vision/Connect4Vision/GameVision.h"
#include "./modules/ik-lib/ik_solver/include/IKSolver.hpp"
#include "./modules/ik-lib/ik_solver/include/InverseKinematics.hpp"
#include "./modules/ik-lib/robot_arm/include/RobotArm.hpp"
#include "include/file_writer.hpp"


#endif // INCLUDE_H