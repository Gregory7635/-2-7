#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ofstream outputFile2("матрицы с четными суммами.txt");
// Функция для вычисления суммы положительных четных элементов матрицы
int sumPositiveEvenElements(const vector<vector<int>>& matrix) {
    int sum = 0;
    for (const auto& row : matrix) {
        for (int element : row) {
            if (element > 0 and element % 2 == 0) {
                sum += element;
            }
        }
    }
    return sum;
}

// Функция для замены матрицы на единичную матрицу
void replaceMatrixWithIdentity(vector<vector<int>>& matrix) {
    cout << "Четная матрица" << endl;
            for (const auto& row : matrix) {
                for (int element : row) {
                    outputFile2 << element << " ";
                    cout << element<<" ";
                }
                cout << endl;
                outputFile2 << endl;
            }
            cout << endl;
            outputFile2 << endl;
        
    int size = matrix.size();
    matrix = vector<vector<int>>(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        matrix[i][i] = 1;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("input.txt");
    ofstream outputFile1("Все матрицы.txt");

    int k, m, n;
    inputFile >> k >> m >> n;

    vector<vector<vector<int>> > matrices;
    for (int i = 0; i < k; ++i) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < n; ++l) {
                inputFile >> matrix[j][l];
            }
        }
        matrices.push_back(matrix);
    }

    // Вычисление суммы положительных четных элементов и замена матриц
    for (auto& matrix : matrices) {
        int sum = sumPositiveEvenElements(matrix);
        if (sum % 2 == 0 and sum != 0) {
            replaceMatrixWithIdentity(matrix);
        }
    }

    // Вывод содержимого первого 
    cout << "Все матрицы" << endl;
    for (const auto& matrix : matrices) {
        for (const auto& row : matrix) {
            for (int element : row) {
                cout << element << " ";
                outputFile1 << element << " ";
            }
            cout << endl;
            outputFile1 << endl;
        }
        cout << endl;
        outputFile1 << endl;
    }


    inputFile.close();
    outputFile1.close();
    outputFile2.close();
    return 0;
}
