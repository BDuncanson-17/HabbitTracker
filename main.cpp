#include <iostream>
#include "src/Weight.h"
#include "src/Util.h"
int main() {
    WeightDataPoint wdp(190);
    std::cout << wdp.CreateDBString();
    wdp.AddToDatabase();
}
