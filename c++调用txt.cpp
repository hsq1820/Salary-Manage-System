#include <fstream>
#include <iostream>
using namespace std;
int main() {
    // 创建一个ofstream对象用于写入文件
    ofstream outFile("example.txt");

    // 检查文件是否成功打开
    if (!outFile) {
        cerr << "无法打开文件";
        return 1;
    }

    // 写入文件
    outFile << "这是一行文本\n";
    outFile.close();

    // 创建一个ifstream对象用于读取文件
    ifstream inFile("example.txt");

    // 检查文件是否成功打开
    if (!inFile) {
        cerr << "无法打开文件";
        return 1;
    }

    // 读取文件
    string line;
    while (getline(inFile, line)) {
        cout << line << '\n';
    }
    inFile.close();

    return 0;
}