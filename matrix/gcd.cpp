#include <iostream>
#include <windows.h> 
using namespace std;


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
} 


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    int a, b;
    cout << "Введите два целых числа: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "наибольший общий делитель чисел " << a << " и " << b << " = " << result << endl;

    return 0; 
