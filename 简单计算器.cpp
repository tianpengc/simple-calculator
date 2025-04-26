#include <iostream>
#include <limits>
#include <iomanip> // 用于格式化输出
#include <cmath>   // 用于数学运算
#include <vector>  // 用于历史记录
#include <string>  // 用于字符串操作

using namespace std;

// 清除输入缓冲区
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// 显示欢迎信息
void displayWelcomeMessage() {
    cout << "\n╔══════════════════════════╗\n"
         << "║       高级计算器         ║\n"
         << "╚══════════════════════════╝\n"
         << "支持运算: +, -, *, /, ^ (幂), % (模)\n"
         << "特殊命令: q(退出) h(历史) c(清除历史)\n"
         << "════════════════════════════\n\n";
}

// 获取有效的运算符输入
char getValidOperator() {
    char op;
    while (true) {
        cout << "输入运算符 (+, -, *, /, ^, %) 或命令: ";
        cin >> op;
        
        if (op == 'q' || op == 'h' || op == 'c') return op;
        
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%') {
            return op;
        }
        
        cerr << "错误: 无效的运算符或命令，请重新输入\n";
        clearInputBuffer();
    }
}

// 获取有效的数字输入
double getValidNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        cin >> num;
        
        if (cin.fail()) {
            cerr << "错误: 请输入有效的数字\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return num;
        }
    }
}

// 执行计算并返回结果
double performCalculation(char op, double num1, double num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 == 0) throw runtime_error("除数不能为零");
            return num1 / num2;
        case '^': return pow(num1, num2);
        case '%': 
            if (num2 == 0) throw runtime_error("模数不能为零");
            return fmod(num1, num2);
        default: throw runtime_error("无效的运算符");
    }
}

int main() {
    vector<string> calculationHistory;
    bool running = true;
    
    displayWelcomeMessage();

    while (running) {
        try {
            char op = getValidOperator();
            
            // 处理特殊命令
            if (op == 'q') {
                running = false;
                continue;
            } else if (op == 'h') {
                if (calculationHistory.empty()) {
                    cout << "暂无计算历史\n\n";
                } else {
                    cout << "\n=== 计算历史 ===\n";
                    for (const auto& entry : calculationHistory) {
                        cout << entry << "\n";
                    }
                    cout << "===============\n\n";
                }
                continue;
            } else if (op == 'c') {
                calculationHistory.clear();
                cout << "已清除计算历史\n\n";
                continue;
            }
            
            // 获取操作数
            double num1 = getValidNumber("输入第一个操作数: ");
            double num2 = getValidNumber("输入第二个操作数: ");
            
            // 执行计算
            double result = performCalculation(op, num1, num2);
            
            // 格式化并显示结果
            string calculation = to_string(num1) + " " + op + " " + to_string(num2) + " = " + to_string(result);
            cout << fixed << setprecision(4); // 设置4位小数精度
            cout << "结果: " << result << "\n\n";
            cout << defaultfloat; // 恢复默认格式
            
            // 保存到历史记录
            calculationHistory.push_back(calculation);
            
            // 限制历史记录数量
            if (calculationHistory.size() > 10) {
                calculationHistory.erase(calculationHistory.begin());
            }
            
        } catch (const exception& e) {
            cerr << "错误: " << e.what() << "\n\n";
            clearInputBuffer();
        }
    }
    
    cout << "感谢使用计算器，再见！\n";
    return 0;
}
