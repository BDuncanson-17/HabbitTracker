//
// Created by bryan on 6/28/23.
//
#include "Util.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <ctime>
#include <chrono>
#include <iostream>
#include <sstream>



Time::Time() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *local_time = std::localtime(&now_time);

    year = (1900 + local_time->tm_year) % 100; // Get the last two digits
    month = 1 + local_time->tm_mon;
    day = local_time->tm_mday;
    hours = local_time->tm_hour;
    minutes = local_time->tm_min;
    seconds = local_time->tm_sec;
}

void Time::PrintTimeStamp() {
    std::cout << "Time Stamp: " << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Month: " << month << std::endl;
    std::cout << "Day: " << day << std::endl;
    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Minutes: " << minutes << std::endl;
    std::cout << "Seconds: " << seconds << std::endl;
}

std::string Time::TimeToCSVSting() {
    std::stringstream ss;
    ss << month << "," << day << "," << year << "," 
        << hours << "," << minutes << "," << seconds;
    return ss.str();
}




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