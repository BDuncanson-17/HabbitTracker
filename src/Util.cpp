//
// Created by bryan on 6/28/23.
//
#include "Util.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::unordered_map<std::string, int> Constants::g_MonthMap = {
            {"Jan", 1},
            {"Feb", 2},
            {"Mar", 3},
            {"Apr", 4},
            {"May", 5},
            {"Jun", 6},
            {"Jul", 7},
            {"Aug", 8},
            {"Sep", 9},
            {"Oct", 10},
            {"Nov", 11},
            {"Dec", 12}
};


  // Assuming Constants::g_DBPath is defined here


std::vector<std::string> Util::ReadFromDatabaseFile() {
    std::ifstream file(Constants::g_DBPath);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + Constants::g_DBPath);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

void Util::AppendToDatabase(const std::string& data){
    std::ofstream file(Constants::g_DBPath, std::ios::app);

    // Check if the file was opened successfully
    if (!file) {
        throw std::runtime_error("Could not open file " + Constants::g_DBPath);
    }

    // Write the data to the file
    file << data;

    // Close the file
    file.close();
}