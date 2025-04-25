#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2;

    cout << "输入运算符 (+, -, *, /): ";
    cin >> op;

    cout << "输入两个操作数: ";
    cin >> num1 >> num2;

    switch (op) {
    case '+':
        cout << "结果: " << num1 + num2;
        break;
    case '-':
        cout << "结果: " << num1 - num2;
        break;
    case '*':
        cout << "结果: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0.0)
            cout << "结果: " << num1 / num2;
        else
            cout << "错误: 除数不能为零";
        break;
    default:
        cout << "错误: 无效的运算符";
    }

    return 0;
}