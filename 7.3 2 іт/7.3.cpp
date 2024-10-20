#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int CalculateSumOfRowsWithNegatives(int** a, const int rowCount, const int colCount);
void FindSaddlePoints(int** a, const int rowCount, const int colCount);
bool IsMinInRow(int** a, const int n, const int k, const int colCount);
bool IsMaxInCol(int** a, const int n, const int k, const int rowCount);

int main() {
    srand((unsigned)time(NULL));

    int Low = -17;
    int High = 15;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int sum = CalculateSumOfRowsWithNegatives(a, rowCount, colCount);
    cout << "Sum of elements in rows with at least one negative element: " << sum << endl;

    FindSaddlePoints(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int CalculateSumOfRowsWithNegatives(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int i = 0; i < rowCount; i++) {
        bool hasNegative = false;
        int rowSum = 0;
        for (int j = 0; j < colCount; j++) {
            rowSum += a[i][j];
            if (a[i][j] < 0)
                hasNegative = true;
        }
        if (hasNegative) {
            sum += rowSum;
        }
    }
    return sum;
}

bool IsMinInRow(int** a, const int n, const int k, const int colCount) {
    for (int j = 0; j < colCount; j++)
        if (a[n][j] < a[n][k])
            return false;
    return true;
}

bool IsMaxInCol(int** a, const int n, const int k, const int rowCount) {
    for (int i = 0; i < rowCount; i++)
        if (a[i][k] > a[n][k])
            return false;
    return true;
}

void FindSaddlePoints(int** a, const int rowCount, const int colCount) {
    cout << "Saddle points (minimum in row and maximum in column):" << endl;
    cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
    int No = 0;
    for (int n = 0; n < rowCount; n++) {
        for (int k = 0; k < colCount; k++) {
            if (IsMinInRow(a, n, k, colCount) && IsMaxInCol(a, n, k, rowCount)) {
                cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
            }
        }
    }
}
