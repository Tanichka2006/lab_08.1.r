#include <iostream>
#include <cstring>
using namespace std;

// Функція для пошуку четвертої крапки з кінця
int FindFourthDot(char* str, int i, int dotCount) {
    if (i < 0) return -1; // Якщо дійшли до початку рядка і не знайшли достатньо крапок
    if (str[i] == '.') dotCount++;
    if (dotCount == 4) return i; // Якщо знайдено четверту крапку, повертаємо її позицію
    return FindFourthDot(str, i - 1, dotCount); // Рекурсія для наступного символу з кінця
}

// Рекурсивна функція для заміни всіх крапок на "**"
void ReplaceDots(char* dest, const char* str, int i, int j) {
    if (str[i] == '\0') { // Якщо кінець рядка
        dest[j] = '\0';
        return;
    }
    if (str[i] == '.') { // Якщо поточний символ - крапка
        dest[j++] = '*';
        dest[j++] = '*';
    }
    else {
        dest[j++] = str[i]; // Копіюємо символ, якщо це не крапка
    }
    ReplaceDots(dest, str, i + 1, j); // Рекурсія для наступного символу
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Знаходимо позицію четвертої крапки з кінця
    int fourthDotPos = FindFourthDot(str, strlen(str) - 1, 0);
    if (fourthDotPos != -1) {
        cout << "Position of the fourth dot from the end: " << fourthDotPos << endl;
    }
    else {
        cout << "There are less than four dots in the string." << endl;
    }

    // Замінюємо всі крапки на "**"
    char modifiedStr[201]; // Виділяємо достатньо пам'яті для заміненої версії рядка
    ReplaceDots(modifiedStr, str, 0, 0);
    cout << "Modified string: " << modifiedStr << endl;

    return 0;
}
