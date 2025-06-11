# ROBOTICA/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(RoboticaProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Zoek externe pakketten
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Voeg de modules toe
add_subdirectory(modules/ik-lib)

# --- Executable: ik_project (enige die we willen) ---
add_executable(ik_project main.cpp)

target_include_directories(ik_project PRIVATE
    modules/ik-lib/ik_solver/include
    modules/ik-lib/robot_arm/include
)

target_link_libraries(ik_project PRIVATE
    robot_arm
    ik_solver
    Eigen3::Eigen
)
