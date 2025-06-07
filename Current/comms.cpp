#include "comms.h"
#include <iostream>

using namespace std;

string greeting(string name) {
    return "Welcome to \"M&H Clothing\" the greatest clothing store to ever exist, take a look around, " + name;    
}

void format (string &adress) {
    for (int i = 0; i < adress.length(); i++) {
        adress[i] = toupper(adress[i]);
    }
}

string closing(string product, double total) {
    return "Thanks for buying a " + product + ". Your total is " + to_string(total) + " We hope you enjoy your purchase!";
}
