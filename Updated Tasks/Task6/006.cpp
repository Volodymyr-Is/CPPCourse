#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

const int n = 8;

void findMatchingRowsColumns(int matrix[n][n], int matchingIndices[n], int& matchCount) {
    matchCount = 0;
    for (int k = 0; k < n; ++k) {
        bool match = true;
        for (int i = 0; i < n; ++i) {
            if (matrix[k][i] != matrix[i][k]) {
                match = false;
                break;
            }
        }
        if (match) {
            matchingIndices[matchCount++] = k;
        }
    }
}

int sumRowsWithNegative(int matrix[n][n]) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        bool hasNegative = false;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int j = 0; j < n; ++j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    ifstream inputFile("matrix.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error with file openning!" << endl;
        return 1;
    }

    int matrix[n][n];
    int matchingIndices[n];
    int matchCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    cout << "Martix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    findMatchingRowsColumns(matrix, matchingIndices, matchCount);


    cout << "\nMatching rows and columns: ";
    outputFile << "Matching rows and columns: ";
    for (int i = 0; i < matchCount; ++i) {
        cout << matchingIndices[i] << " ";
        outputFile << matchingIndices[i] << " ";
    }
    cout << endl;


    int sum = sumRowsWithNegative(matrix);
    cout << "Sum of elements in rows with negative elements: " << sum << endl;
    outputFile << "\nSum of elements in rows with negative elements: " << sum << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
