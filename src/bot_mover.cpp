// #include "../include.h"

void executeBotMove(RobotArm &robotArm, int column)
{
    cout << "[+] Moving robot arm to play the move..." << endl;

    // Haal doelpositie op
    StandardPositions::Position p = StandardPositions::getPosition(column);

    // Beweeg robot fysiek
    robotArm.moveTo(p.pos, p.orientation);
    cout << "[+] Move physically executed." << endl;

    // Sla hoeken op NA het bewegen
    std::vector<float> finalAngles;
    for (const Joint &joint : robotArm.joints)
    {
        finalAngles.push_back(joint.getAngle());
    }
    std::string filename = "/home/nout/ros2_ws/joints.txt";
    writeToFile(finalAngles, filename);
}
