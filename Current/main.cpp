// Emanuel Wertman
// Company Consistency Lab
// 5/20/2025
// Extra: Allowed the user to say how much their total was, made the discount code lower, 
#include <iostream>
#include "comms.h"
#include "discounts.h"
#include <string>

using namespace std;

// Function I made to make the discount codes into lowercase
void lower(string &word) {
    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    string name;
    cout << "What is your name?\n>>> ";
    getline(cin, name);
    string greet = greeting(name);      // Puts greeting into a string
    cout << greet << endl;

    string adress;
    cout << "What is your street adress?\n>>> ";
    getline(cin, adress);
    format(adress);                     // Formats the adress
    cout << adress << endl;

    string product;
    double total;
    cout << "Which product did you buy?\n>>> ";
    getline(cin, product);
    cout << "How much did that item cost?\n>>> ";
    cin >> total;                       // Gets the total for later
    cin.ignore();                       // Needed because of switch from cin to getline

    string discount;
    cout << "Do you have any discount codes(student, military, senior)?\n>>> ";
    getline(cin, discount);
    lower(discount);                    // Lowers the discount code

    if (discount == "student") {
        student(total);
    }
    if (discount == "military") {
        military(total);
    }
    if (discount == "senior") {
        senior(total);
    }

    string close = closing(product, total);
    cout << close << endl;

    return 0;
}

