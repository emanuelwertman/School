// Emanuel Wertman
// 5/7/2025
// Pointers Lab
#include <iostream>
using namespace std;

int main() {
    // Number 1
    int num = 50;
    int* ptr = &num;
    *ptr = 75;

    cout << "Original Variable: " << num << endl;
    cout << "Dereferneced Pointer: " << *ptr << endl;


    // Number 2
    int nums[5] = {10, 20, 30, 40, 50};
    
    cout << "First value: " << *nums << endl;
    cout << "Second value: " << *(nums + 1) << endl;
    cout << "Third value: " << *(nums + 2) << endl;
    cout << "Fourth value: " << *(nums + 3) << endl;
    cout << "Fifth value: " << *(nums + 4) << endl;
    cout << "What happens if you leave off the ()? " << *nums + 1 << endl;
    *(nums + 2) = 100;
    cout << "First value: " << *nums << endl;
    cout << "Second value: " << *(nums + 1) << endl;
    cout << "Third value: " << *(nums + 2) << endl;
    cout << "Fourth value: " << *(nums + 3) << endl;
    cout << "Fifth value: " << *(nums + 4) << endl;


    // Optional Challenge
    char c = 'w';
    char* charPtr = &c;
    cout << "Letter: " << c << endl;
    cout << "Memory Adress : " << &charPtr << endl;
    *charPtr = 'l';
    cout << "Letter: " << c << endl;
    cout << "Memory Adress : " << (void*)y << endl;

    return 0;
}
