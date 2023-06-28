//
// Created by bryan on 6/28/23.
//

#include "DataTypes.h"
#include <sstream>
#include <chrono>


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


std::string Time::TimeToCSVSting() {
    std::vector<std::string> formattedStrings(5);
    formattedStrings[0] = LeadingZero(hours);
    formattedStrings[1] = LeadingZero(minutes);
    formattedStrings[2] = LeadingZero(seconds);
    formattedStrings[3] = LeadingZero(month);
    formattedStrings[4] = LeadingZero(day);

    std::string csvString;
    for(const std::string& str : formattedStrings ){
        csvString += str + ",";
    }
    csvString.pop_back();
    csvString + std::to_string(year);
    return csvString;
}

std::string Time::LeadingZero(int timeData){
    if(timeData/10) return std::to_string(timeData);
    return "0" + std::to_string(timeData);
}




DataPoint::DataPoint(std::string dataType, int data) {
    DataType = dataType;
    Data = data;
    Time DataPointTime;
}
std::string DataPoint::CreateDBString() {
    return DataType + "," + DataPointTime.TimeToCSVSting() + std::to_string(Data) + "\n";
}

void DataPoint::AddToDatabase() {
    HabitUtilities::AppendToDatabase(CreateDBString());
}





WeightData::WeightData() {
    std::vector<std::string> dbstrs = HabitUtilities::ReadFromDatabaseFile();
    for(const std::string& dpstr : dbstrs){
        std::vector<int> datapt(5);
        int i = 0;
        std::stringstream ss(dpstr);
        std::string token;

        while (std::getline(ss, token, ',')) {
            int value = std::stoi(token);
            datapt[i++]=value;
        }
        data.push_back(datapt);
    }
}
