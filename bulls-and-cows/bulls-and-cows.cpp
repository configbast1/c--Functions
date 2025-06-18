

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int CODE_LENGTH = 4; 

void generateNumber(char number[CODE_LENGTH + 1]) {
    srand(static_cast<unsigned>(time(nullptr)));
    int i = 0;
    while (i < CODE_LENGTH) {
        char digit = '0' + rand() % 10;
        bool exists = false;
        for (int j = 0; j < i; j++) {
            if (number[j] == digit) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            number[i] = digit;
            i++;
        }
    }
    number[CODE_LENGTH] = '\0';
}

void inputGuess(char guess[CODE_LENGTH + 1]) {
    while (true) {
        cout << "Введите 4-значное число: ";
        cin >> guess;

        bool valid = true;
        if (strlen(guess) != CODE_LENGTH) valid = false;
        for (int i = 0; i < CODE_LENGTH && valid; i++) {
            if (!isdigit(guess[i])) valid = false;
            for (int j = i + 1; j < CODE_LENGTH; j++) {
                if (guess[i] == guess[j]) valid = false;
            }
        }

        if (!valid) {
            cout << "ошибка: должно быть 4 уникальные цифры!\n";
        }
        else break;
    }
}

void countBullCow(const char secret[CODE_LENGTH + 1], const char guess[CODE_LENGTH + 1], int& bulls, int& cows) {
    bulls = cows = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == secret[i]) bulls++;
        else {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (guess[i] == secret[j]) {
                    cows++;
                    break;
                }
            }
        }
    }
}

void playGame(const char secret[CODE_LENGTH + 1], int attempt = 1) {
    char guess[CODE_LENGTH + 1];
    inputGuess(guess);

    int bulls = 0, cows = 0;
    countBullCow(secret, guess, bulls, cows);

    if (bulls == CODE_LENGTH) {
        cout << "поздравляем Вы угадали число за " << attempt << " попыток!\n";
        return;
    }

    cout << bulls << " быков, " << cows << " коров.\n";
    playGame(secret, attempt + 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== игра Быки и Коровы ===\n";

    char secret[CODE_LENGTH + 1];
    generateNumber(secret);

    playGame(secret);

    cout << "спасибо за игру!\n";
    return 0;
}
