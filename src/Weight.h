#ifndef WEIGHTDATA_H
#define WEIGHTDATA_H

#include <ctime>
#include <string>
#include "Util.h"

class WeightDataPoint {
private:
    int Weight;
    int Month;
    int Year;
    int Day;
    int Hour;
    int Min;
    int Second;
public:
    // Constructor that takes weight as a parameter
    WeightDataPoint(int weight);

    std::string CreateDBString();

    void AddToDatabase() {
        Util::AppendToDatabase(CreateDBString());
    }
};

#endif  // WEIGHTDATA_H
