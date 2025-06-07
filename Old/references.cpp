// Emanuel Wertman
// 5/12/2025
// References Lab
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void q1 (string &word) {
    // Iterates through the string and changes each letter to lowercase
    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]);
    }

}

void q2 (int &num) {
    num *= 2;
}

int q3 (int num2) { 
    int randomNum = rand() % 11;
    // Returns result
    return num2 + randomNum;

}

void q4 (vector<int> &vec) {
    vec.push_back(40);
    vec.push_back(50);
}

int main() {
    srand(time(0));
    // -------------------------------
    //           Question 1
    // -------------------------------
    string w;
    cout << "What word would you like to see turned into lowercase? \n >>> ";
    cin >> w;
    q1(w);
    cout << w << endl;

    // -------------------------------
    //           Question 2
    // -------------------------------
    int n;
    cout << "What number would you like to see multiplied by 2? \n >>> ";
    cin >> n;
    q2(n);
    cout << n << endl;

    // -------------------------------
    //           Question 3
    // -------------------------------
    int n2;
    cout << "What number would you like to see added to a random number? \n >>> ";
    cin >> n2;
    int result = q3(n2);
    cout << result << endl;

    // -------------------------------
    //           Question 4
    // -------------------------------
    vector<int> nums = {10, 20, 30};
    cout << "Vector Before: " << endl;
    // Prints by iterating using a for each
    for (int i : nums) {
        cout << i << endl;
    }

    q4(nums);
    cout << "Vector After: " << endl;
    for (int i : nums) {
        cout << i << endl;
    }

    return 0;
}
