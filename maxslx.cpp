#include "OpenXLSX-master/OpenXLSX/OpenXLSX.hpp"
#include <iostream>
#include <exception>

using namespace OpenXLSX;
/*
int main() {
    system("chcp 65001");
    system("cls");
    try {
        // ����һ���µ�.xlsx�ļ�
        XLDocument doc;
        doc.create("./newDoc.xlsx");

        // ��ӹ�����
        //doc.workbook().addWorksheet("Sheet1");
        XLWorksheet wks = doc.workbook().worksheet("Sheet1");

        // д������
        wks.cell("A1").value() = "��˼��";
        wks.cell("B2").value() = "adsx";

        // ���沢�ر��ĵ�
        doc.save();
        doc.close();

        // ��ȡ.xlsx�ļ�
        XLDocument doc2;
        doc2.open("./newDoc.xlsx");

        // ��ȡ������
        XLWorksheet wks2 = doc2.workbook().worksheet("Sheet1");

        // ��ȡ���ݲ���ʽת��Ϊ�ַ�������
        std::string cellA1 = wks2.cell("A1").value().get<std::string>();
        std::string cellB2 = wks2.cell("B2").value().get<std::string>();

        std::cout << "A1: " << cellA1 << std::endl;
        std::cout << "B2: " << cellB2 << std::endl;

        // �ر��ĵ�
        doc2.close();
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1; // Return a non-zero value to indicate failure
    }
    _sleep(5000);
    return 0;
}
*/