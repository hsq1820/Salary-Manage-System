#include "OpenXLSX-master/OpenXLSX/OpenXLSX.hpp"
#include <iostream>
#include <exception>

using namespace OpenXLSX;
/*
int main() {
    system("chcp 65001");
    system("cls");
    try {
        // 创建一个新的.xlsx文件
        XLDocument doc;
        doc.create("./newDoc.xlsx");

        // 添加工作表
        //doc.workbook().addWorksheet("Sheet1");
        XLWorksheet wks = doc.workbook().worksheet("Sheet1");

        // 写入数据
        wks.cell("A1").value() = "黄思琦";
        wks.cell("B2").value() = "adsx";

        // 保存并关闭文档
        doc.save();
        doc.close();

        // 读取.xlsx文件
        XLDocument doc2;
        doc2.open("./newDoc.xlsx");

        // 获取工作表
        XLWorksheet wks2 = doc2.workbook().worksheet("Sheet1");

        // 读取数据并显式转换为字符串类型
        std::string cellA1 = wks2.cell("A1").value().get<std::string>();
        std::string cellB2 = wks2.cell("B2").value().get<std::string>();

        std::cout << "A1: " << cellA1 << std::endl;
        std::cout << "B2: " << cellB2 << std::endl;

        // 关闭文档
        doc2.close();
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate failure
    }
    _sleep(5000);
    return 0;
}
*/