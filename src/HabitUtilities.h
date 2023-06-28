//
// Created by bryan on 6/28/23.
//

#ifndef HABBITTRACKER_HABITUTILITIES_H
#define HABBITTRACKER_HABITUTILITIES_H

#include <string>
#include <vector>
#include <unordered_map>

namespace Constants {
    const std::string g_DBPath = "..//data//habbittracker.db";
    extern std::unordered_map<std::string, int> g_MonthMap;
}

class HabitUtilities {
public:

    static std::vector<std::string> ReadFromDatabaseFile();

    static void AppendToDatabase(const std::string& data);

};

    
    

#endif //HABBITTRACKER_HABITUTILITIES_H
