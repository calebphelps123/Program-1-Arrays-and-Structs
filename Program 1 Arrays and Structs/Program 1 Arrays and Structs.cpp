// Program 1 Arrays and Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // For setw()

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Function to read and store runner names and miles run each day
void readData(string names[], int miles[][NUM_DAYS]) {
    cout << "Enter data for " << NUM_RUNNERS << " runners:" << endl;
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> names[i];
        cout << "Enter miles run for each day of the week:" << endl;
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << "Day " << j + 1 << ": ";
            cin >> miles[i][j];
        }
    }
}

// Function to calculate total miles run by each runner
void calculateTotals(const string names[], const int miles[][NUM_DAYS], int totals[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        totals[i] = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totals[i] += miles[i][j];
        }
    }
}

// Function to display the results
void displayResults(const string names[], const int miles[][NUM_DAYS], const int totals[]) {
    cout << setw(15) << "Runner Name";
    for (int j = 0; j < NUM_DAYS; ++j) {
        cout << setw(10) << "Day " << j + 1;
    }
    cout << setw(15) << "Total Miles" << setw(15) << "Avg Miles" << endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(15) << names[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << miles[i][j];
        }
        double avgMiles = static_cast<double>(totals[i]) / NUM_DAYS;
        cout << setw(15) << totals[i] << setw(15) << fixed << setprecision(2) << avgMiles << endl;
    }
}

int main() {
    string runnerNames[NUM_RUNNERS];
    int milesRun[NUM_RUNNERS][NUM_DAYS];
    int totalMiles[NUM_RUNNERS];

    readData(runnerNames, milesRun);
    calculateTotals(runnerNames, milesRun, totalMiles);
    displayResults(runnerNames, milesRun, totalMiles);

    return 0;
}