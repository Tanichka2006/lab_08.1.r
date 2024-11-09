#include <iostream>
#include <cstring>
using namespace std;

// ������� ��� ������ �������� ������ � ����
int FindFourthDot(char* str, int i, int dotCount) {
    if (i < 0) return -1; // ���� ����� �� ������� ����� � �� ������� ��������� ������
    if (str[i] == '.') dotCount++;
    if (dotCount == 4) return i; // ���� �������� �������� ������, ��������� �� �������
    return FindFourthDot(str, i - 1, dotCount); // ������� ��� ���������� ������� � ����
}

// ���������� ������� ��� ����� ��� ������ �� "**"
void ReplaceDots(char* dest, const char* str, int i, int j) {
    if (str[i] == '\0') { // ���� ����� �����
        dest[j] = '\0';
        return;
    }
    if (str[i] == '.') { // ���� �������� ������ - ������
        dest[j++] = '*';
        dest[j++] = '*';
    }
    else {
        dest[j++] = str[i]; // ������� ������, ���� �� �� ������
    }
    ReplaceDots(dest, str, i + 1, j); // ������� ��� ���������� �������
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // ��������� ������� �������� ������ � ����
    int fourthDotPos = FindFourthDot(str, strlen(str) - 1, 0);
    if (fourthDotPos != -1) {
        cout << "Position of the fourth dot from the end: " << fourthDotPos << endl;
    }
    else {
        cout << "There are less than four dots in the string." << endl;
    }

    // �������� �� ������ �� "**"
    char modifiedStr[201]; // �������� ��������� ���'�� ��� ������� ���� �����
    ReplaceDots(modifiedStr, str, 0, 0);
    cout << "Modified string: " << modifiedStr << endl;

    return 0;
}
