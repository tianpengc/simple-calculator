#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2;

    cout << "��������� (+, -, *, /): ";
    cin >> op;

    cout << "��������������: ";
    cin >> num1 >> num2;

    switch (op) {
    case '+':
        cout << "���: " << num1 + num2;
        break;
    case '-':
        cout << "���: " << num1 - num2;
        break;
    case '*':
        cout << "���: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0.0)
            cout << "���: " << num1 / num2;
        else
            cout << "����: ��������Ϊ��";
        break;
    default:
        cout << "����: ��Ч�������";
    }

    return 0;
}