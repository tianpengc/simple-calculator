#include <iostream>
#include <limits> // 用于输入验证
using namespace std;

void clearInput() {
    cin.clear(); // 清除错误状态
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略错误输入
}

int main() {
    char op;
    double num1, num2;
    bool continueCalculation = true;

    cout << "===== 简单计算器 =====\n";
    cout << "支持运算: +, -, *, /\n";
    cout << "输入'q'退出程序\n\n";

    while (continueCalculation) {
        // 获取运算符
        while (true) {
            cout << "输入运算符 (+, -, *, /) 或 'q' 退出: ";
            cin >> op;

            if (op == 'q') {
                continueCalculation = false;
                break;
            }

            if (op == '+' || op == '-' || op == '*' || op == '/') {
                break;
            }

            cout << "错误: 无效的运算符，请重新输入\n";
            clearInput();
        }

        if (!continueCalculation) break;

        // 获取操作数
        cout << "输入两个操作数: ";
        while (!(cin >> num1 >> num2)) {
            cout << "错误: 请输入有效的数字: ";
            clearInput();
        }

        // 执行计算
        switch (op) {
        case '+':
            cout << "结果: " << num1 + num2 << "\n\n";
            break;
        case '-':
            cout << "结果: " << num1 - num2 << "\n\n";
            break;
        case '*':
            cout << "结果: " << num1 * num2 << "\n\n";
            break;
        case '/':
            if (num2 != 0.0) {
                cout << "结果: " << num1 / num2 << "\n\n";
            }
            else {
                cout << "错误: 除数不能为零\n\n";
            }
            break;
        }

        clearInput(); // 为下一次计算准备
    }

    cout << "计算器已退出\n";
    return 0;
}
