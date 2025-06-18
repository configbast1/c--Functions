#include <iostream>
#include <windows.h>
#include <algorithm>
using namespace std;

const int N = 3;
void initMatrix(int mat[N][N]) {
    int val = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = val++;
}

void initMatrix(double mat[N][N]) {
    double val = 1.1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = val++;
}

void initMatrix(char mat[N][N]) {
    char val = 'A';
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = val++;
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++, cout << endl)
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << "\t";
}

void printMatrix(double mat[N][N]) {
    for (int i = 0; i < N; i++, cout << endl)
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << "\t";
}

void printMatrix(char mat[N][N]) {
    for (int i = 0; i < N; i++, cout << endl)
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << "\t";
}

void minMaxDiag(int mat[N][N]) {
    int minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < N; i++) {
        minVal = min(minVal, mat[i][i]);
        maxVal = max(maxVal, mat[i][i]);
    }
    cout << "Минимум: " << minVal << ", Максимум: " << maxVal << endl;
}

void minMaxDiag(double mat[N][N]) {
    double minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < N; i++) {
        minVal = min(minVal, mat[i][i]);
        maxVal = max(maxVal, mat[i][i]);
    }
    cout << "Минимум: " << minVal << ", Максимум: " << maxVal << endl;
}

void minMaxDiag(char mat[N][N]) {
    char minVal = mat[0][0], maxVal = mat[0][0];
    for (int i = 1; i < N; i++) {
        minVal = min(minVal, mat[i][i]);
        maxVal = max(maxVal, mat[i][i]);
    }
    cout << "Минимум: " << minVal << ", Максимум: " << maxVal << endl;
}


void sortRows(int mat[N][N]) {
    for (int i = 0; i < N; i++)
        sort(mat[i], mat[i] + N);
}

void sortRows(double mat[N][N]) {
    for (int i = 0; i < N; i++)
        sort(mat[i], mat[i] + N);
}

void sortRows(char mat[N][N]) {
    for (int i = 0; i < N; i++)
        sort(mat[i], mat[i] + N);
}


int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   
    int im[N][N];
    cout << "--- int ---\n";
    initMatrix(im);
    printMatrix(im);
    minMaxDiag(im);
    sortRows(im);
    cout << "После сортировки:\n";
    printMatrix(im);

    
    double dm[N][N];
    cout << "\n--- double ---\n";
    initMatrix(dm);
    printMatrix(dm);
    minMaxDiag(dm);
    sortRows(dm);
    cout << "После сортировки:\n";
    printMatrix(dm);

   
    char cm[N][N];
    cout << "\n--- char ---\n";
    initMatrix(cm);
    printMatrix(cm);
    minMaxDiag(cm);
    sortRows(cm);
    cout << "После сортировки:\n";
    printMatrix(cm);

    return 0; 
 
}
