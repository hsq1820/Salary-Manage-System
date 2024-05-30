#include <iostream>
#include "OpenXLSX-master/OpenXLSX/OpenXLSX.hpp"

using namespace std;
using namespace OpenXLSX;

int main() {
    system("chcp 65001");
    system("cls");

    // 创建一个新的.xlsx文件
    XLDocument doc;
    doc.create("./employees.xlsx");

    // 添加工作表
    //doc.workbook().addWorksheet("Sheet1");
    XLWorksheet wks = doc.workbook().worksheet("Sheet1");

    // 写入表头
    //wks.cell("A1").value() = "职工号";
    //wks.cell("B1").value() = "姓名";
    wks.cell("C1").value() = "性别";
    wks.cell("D1").value() = "年龄";
    wks.cell("E1").value() = "职业";
    wks.cell("F1").value() = "部门";
    wks.cell("G1").value() = "工资";

    // 写入数据
    string name, gender, age, job, place, salary;
    int id = 1;
    cout << "姓名 性别 年龄 职业 部门 工资: \n";
    while (true) {
        
        cin >> name;
        if (name == "0") break;
        cin >> gender >> age >> job >> place >> salary;

        wks.cell("A" + to_string(id + 1)).value() = id;
        wks.cell("B" + to_string(id + 1)).value() = name;
        wks.cell("C" + to_string(id + 1)).value() = gender;
        wks.cell("D" + to_string(id + 1)).value() = age;
        wks.cell("E" + to_string(id + 1)).value() = job;
        wks.cell("F" + to_string(id + 1)).value() = place;
        wks.cell("G" + to_string(id + 1)).value() = salary;

        id++;
    }

    // 保存并关闭文档
    doc.save();
    doc.close();

    // 读取.xlsx文件
    XLDocument doc2;
    doc2.open("./employees.xlsx");

    // 获取工作表
    XLWorksheet wks2 = doc2.workbook().worksheet("Sheet1");

    // 打印表格内容
    unsigned int maxRow = 1;
    unsigned int maxCol = 7; // 因为我们知道有7列

    // 手动计算最大行数（这里假设已知数据行数，实际使用时可以通过更复杂的逻辑确定）
    for (unsigned int row = 2; row <= id; ++row) {
        maxRow = row;
    }

    // 读取并打印表格内容
    for (unsigned int row = 1; row <= maxRow; ++row) {
        for (unsigned int col = 1; col <= maxCol; ++col) {
            auto cell = wks2.cell(row, col);
            if (cell.value().type() == XLValueType::Integer) {
                cout << cell.value().get<int>() << "\t";
            }
            else if (cell.value().type() == XLValueType::Float) {
                cout << cell.value().get<double>() << "\t";
            }
            else if (cell.value().type() == XLValueType::Boolean) {
                cout << (cell.value().get<bool>() ? "TRUE" : "FALSE") << "\t";
            }
            else if (cell.value().type() == XLValueType::String) {
                cout << cell.value().get<string>() << "\t";
            }
            else {
                cout << "UNKNOWN" << "\t";
            }
        }
        cout << endl;
    }

    // 关闭文档
    doc2.close();
    return 0;
}
