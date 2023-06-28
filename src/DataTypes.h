#ifndef WEIGHTDATA_H
#define WEIGHTDATA_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <string>
#include "HabitUtilities.h"

class Time {
private:
    int month;
    int day;
    int year;
    int hours;
    int minutes;
    int seconds;

public:
    Time();

    std::string TimeToCSVSting();

    void PrintTime();

    std::string LeadingZero(int timeData);

    int GetMonth() const {
        return month;
    }

    int GetDay() const {
        return day;
    }

    int GetYear() const {
        return year;
    }

    int GetHours() const {
        return hours;
    }

    int GetMinutes() const {
        return minutes;
    }

    int GetSeconds() const {
        return seconds;
    }
};

class DataPoint {
private:
    std::string DataType;
    int Data;
    Time DataPointTime;
public:
    // Constructor that takes weight as a parameter
    DataPoint(std::string dataType, int data);

    std::string CreateDBString();

    void AddToDatabase();
};


class WeightData {
private:


public:
    WeightData();
    std::vector<std::vector<int>> data;

};



#endif  // WEIGHTDATA_H
