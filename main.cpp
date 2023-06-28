#include <iostream>
#include "src/DataTypes.h"
#include "src/HabitUtilities.h"
#include <algorithm>
int main() {
    DataPoint weight("Weight",190);
    std::cout << weight.CreateDBString() << std::endl;
    weight.AddToDatabase();
}
