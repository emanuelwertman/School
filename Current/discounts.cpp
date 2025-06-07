#include "discounts.h"
#include <iostream>

using namespace std;

void student(double &total) {
    total*=0.9;
}

void military(double &total) {
    total*=0.85;
}

void senior(double &total) {
    total*=0.8;
}
