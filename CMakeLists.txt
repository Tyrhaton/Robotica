# ROBOTICA/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Zet policy zodat we targets van subdirectories correct kunnen linken
if(POLICY CMP0079)
    cmake_policy(SET CMP0079 NEW)
endif()

project(RoboticaProject LANGUAGES CXX)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Zoek externe pakketten
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(OpenCV REQUIRED)

# Voeg de modules toe
add_subdirectory(modules/ik-lib)

# --- Executable: ik_project (enige die we willen) ---
add_executable(ik_project main.cpp src/file_writer.cpp)

target_include_directories(ik_project PRIVATE
    src
    modules/ik-lib/ik_solver/include
    modules/ik-lib/robot_arm/include
    ${OpenCV_INCLUDE_DIRS}
)


target_link_libraries(ik_project PRIVATE
    robot_arm
    ik_solver
    Eigen3::Eigen
    ${OpenCV_LIBS}
)
