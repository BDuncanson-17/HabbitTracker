//
// Created by bryan on 6/28/23.
//

#include "Weight.h"
#include <sstream>
#include <iomanip>

WeightDataPoint::WeightDataPoint(int weight) {
    Weight = weight;

    // Get the current time
    std::time_t now = std::time(0);

    // Convert it to local time
    std::tm* localTime = std::localtime(&now);

    // Populate the other member variables
    Month = localTime->tm_mon + 1;  // Months are represented as 0-11, so add 1
    Year = localTime->tm_year;  // Year
    Day = localTime->tm_mday;  // Day of the month
    Hour = localTime->tm_hour;  // Hours since midnight, 0-23
    Min = localTime->tm_min;  // Minutes after the hour, 0-59
    Second = localTime->tm_sec;  // Seconds after the minute, 0-61
}

std::string WeightDataPoint::CreateDBString(){
    std::ostringstream ss;

    // Add time
    ss << std::setw(2) << std::setfill('0') << Hour
       << std::setw(2) << std::setfill('0') << Min
       << std::setw(2) << std::setfill('0') << Second
       << ",";

    // Add date
    ss << std::setw(2) << std::setfill('0') << Day
       << ","
       << std::setw(2) << std::setfill('0') << Month
       << ","
       << std::setw(2) << std::setfill('0') << (Year % 100)  // Get the last two digits of the year
       << ",";

    // Add weight
    ss << Weight;

    return ss.str() +"\n";
}

