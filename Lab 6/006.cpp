#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

const int n = 8;

vector<int> findMatchingRowsColumns(const vector<vector<int>>& matrix) {
    vector<int> matchingIndices;
    for (int i = 0; i < n; ++i) {
        bool match = true;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                match = false;
                break;
            }
        }
        if (match) {
            matchingIndices.push_back(i);
        }
    }
    return matchingIndices;
}

int sumRowsWithNegative(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        bool hasNegative = false;
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        if (hasNegative)
            for (int j = 0; j < n; ++j)
                sum += matrix[i][j];
    }
    return sum;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ifstream inputFile("matrix.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    cout << "Матриця:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> matchingRowsColumns = findMatchingRowsColumns(matrix);

    cout << "\nНомери рядків, які збігаються зі стовпцями: ";
    outputFile << "Номери рядків, які збігаються зі стовпцями: ";
    for (int k : matchingRowsColumns) {
        cout << k << " ";
        outputFile << k << " ";
    }
    cout << endl;

    int sum = sumRowsWithNegative(matrix);
    cout << "Сума елементів у рядках з від'ємними елементами: " << sum << endl;
    outputFile << "\nСума елементів у рядках з від'ємними елементами: " << sum << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
