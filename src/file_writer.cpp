#include "../include/file_writer.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

void writeToFile(const std::vector<float>& jointAnglesInDegrees, const std::string& filename)
{
    std::ofstream outfile(filename);
    if (!outfile)
    {
        std::cerr << "Kan bestand niet openen voor schrijven: " << filename << std::endl;
        return;
    }

    for (size_t i = 0; i < jointAnglesInDegrees.size(); ++i)
    {
        float radians = jointAnglesInDegrees[i] * (M_PI / 180.0f);
        outfile << radians;
        if (i != jointAnglesInDegrees.size() - 1)
            outfile << ",";
    }
    outfile << std::endl;
}
