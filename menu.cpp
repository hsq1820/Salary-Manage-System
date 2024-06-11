#include "menu.h"
#include "employees.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

vector<employees> emps;
vector<string> departments;

void menu::showmenu(){
    system("cls");
    cout << "****************************\n\n";
    cout << "       工资管理系统\n\n";
    cout << "      1.数据录入" << endl;
    cout << "      2.数据统计" << endl;
    cout << "      3.数据打印及修改" << endl;
    cout << "      4.数据备份" << endl;
    cout << "      5.退出\n\n\n\n";
    cout << "****************************" << endl;
    
    char in=_getch();
    switch (in)
    {
    case '1':
        input();
        break;
    case '2':
        statistics();
        break;
    case '3':
        output();
        break;
    case '4':
        backups();
        break;
    case '5':
        exit(0);
        break;
    }
}

void input1(){
    system("cls");
    cout<<"职业栏输入对应字母A.经理B.技术员C.销售员D.销售经理"<<endl;
    cout<<"经理固定月薪8000，可不输入工资"<<endl;
    cout<<"技术员工资可先输入1再输入输入工作时间，自动计算"<<endl;
    cout<<"销售员和销售经理工资可先输入1再输入销售额，自动计算"<<endl;
    cout<<"部门没有的话输入\"无\""<<endl;
    cout<<"输入0结束录入"<<endl;
    int id=1,age,rank,worktime;
    string name,gender,place;
    char job;
    double salary,value;
    emps.clear();
    cout<<left<<setw(11)<<"职工号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(15)<<"职业"<<setw(10)<<"部门"<<setw(10)<<"工资"<< '\n';
    while (1)
    {
        cout<<left<<setw(10)<<id;
        cin>>name;
        if(name=="0") break;
        cin>>gender>>age>>job>>place;
        if(job=='A'||job=='a'){
            //不换行则输入工资，换行则工资为8000
            if(cin.peek()=='\n'){
                salary=8000;
            }
            else cin>>salary;
        }
        else cin>>salary;
        switch (job)
        {
        case 'B':
        case 'b':
            {
                if (salary==1)
                {
                    cin>>worktime;
                    salary=worktime*100;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                break;
            }
        case 'C':
        case 'c':
            {
                if (salary==1)
                {
                    cin>>value;
                    salary=0.04*value;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                if (salary==1)
                {
                    emps.back().setvalue(value);
                }
                break;
            }
        case 'D':
        case 'd':
            {
                if (salary==1){
                    cin>>value;
                    salary=0;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                if (salary==1)
                {
                    emps.back().setvalue(value);
                }
                break;
            }
        case 'A':
        case 'a':
            {
                emps.emplace_back(id,name,gender,age,job,place,salary);
                break;
            }
        default:
            {
                cerr<<"错误的职业"<<endl;
                continue;
            }
        }
        id++;
    }
}
void inputtxt(string filename){
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "文件打开失败" << endl;
        return;
    }
    emps.clear();
    int id,age,rank;
    double salary;
    string name,gender,job,place;
    //跳过第一行
    inFile.ignore(1000,'\n');
    //读取文件
    while(inFile>>id>>name>>gender>>age>>job>>place>>salary>>rank){
        if(job=="技术员"){
            char j='B';
            emps.emplace_back(id,name,gender,age,j,place,salary,rank);
        }
        else if(job=="销售员"){
            char j='C';
            emps.emplace_back(id,name,gender,age,j,place,salary,rank);
        }
        else if(job=="销售经理"){
            char j='D';
            emps.emplace_back(id,name,gender,age,j,place,salary,rank);
        }
        else if(job=="经理"){
            char j='A';
            emps.emplace_back(id,name,gender,age,j,place,salary,rank);
        }
        else{
            cerr<<"错误的职业，按任意键返回"<<endl;
            _getch();
        }
    }
    inFile.close();
}
void input2(){
    system("cls");
    cout<<"请输入文件名，仅支持.txt文件"<<endl;
    string filename;
    
    while (1)
    {
        cin>>filename;
        //判断文件后缀名
        if (filename.substr(filename.find_last_of('.')+1)=="txt")
        {
            ifstream inFile(filename);
            if (!inFile)
            {
                inFile.close();
                cerr<<"文件打开失败，请重新输入"<<endl;
                Sleep(2000);
            }
            else
            {
                inFile.close();
                inputtxt(filename);
                break;
            }
        }
        else
        {
            cerr<<"文件格式错误，请重新输入"<<endl;
            Sleep(2000);
        }
    }
}

void menu::input(){
    system("cls");
    bool isinput=true;
    while(isinput){
        system("cls");
        cout << "****************************\n\n";
        cout << "       数据录入\n\n";
        cout << "      1.手动录入数据"<<endl;
        cout << "      2.根据文档录入数据"<<endl;
        cout << "      3.返回\n\n\n\n";
        cout << "****************************" << endl;
        switch (_getch())
        {
        case '1':
            input1();
            isinput=false;
            break;
        case '2':
            input2();
            isinput=false;
            break;
        case '3':
            isinput=false;
            break;
        }
    }
}

void menu::statistics(){
    system("cls");
    departments.clear();
    // 按照职工号排序
    sort(emps.begin(), emps.end(), [](const employees &a, const employees &b) {
        return a.getid() < b.getid();
    });

    //统计有几种不同的部门
    for (const auto& employee : emps) {
        if ((find(departments.begin(), departments.end(), employee.getplace()) == departments.end())&&employee.getplace()!="无") {
            departments.push_back(employee.getplace());
        }
    }
    //计算销售经理的销售额
    for(const auto& department : departments){
        double sum = 0,smvalue;
        employees *s;
        for (const auto& employee : emps) {
            if (employee.getplace() == department) {
                if(employee.getjob()=='D'||employee.getjob()=='d'){
                    s=(employees*)&employee;
                }
                else{
                    sum += employee.getvalue();
                }
            }
        }
        if(s!=nullptr&&s->getsalary()!=1){
            smvalue=(s->getsalary()-5000-0.005*sum)/0.045;
            s->setvalue(smvalue);
        }
    }
    // 按照工资排序
    sort(emps.begin(), emps.end(), [](const employees &a, const employees &b) {
        return a.getsalary() < b.getsalary();
    });
    for(int i=0;i<emps.size();i++){//设置排名
        emps[i].setrank(i+1);
    }
    // 按照职工号排序
    sort(emps.begin(), emps.end(), [](const employees &a, const employees &b) {
        return a.getid() < b.getid();
    });
    cout<<"统计完成,按任意键返回"<<endl;
    _getch();
}

void update(){
    cout<<"输入已有职工号修改信息，输入新的职工号增加信息，只输入职工号删除信息"<<endl;
    cout<<"职业栏输入对应字母A.经理B.技术员C.销售员D.销售经理"<<endl;
    cout<<"经理固定月薪8000，可不输入工资"<<endl;
    cout<<"技术员工资可先输入1再输入输入工作时间，自动计算"<<endl;
    cout<<"销售员和销售经理工资可先输入1再输入销售额，自动计算"<<endl;
    cout<<"部门没有的话输入\"无\""<<endl;
    cout<<"输入0结束"<<endl;
    int id=1,age,rank,worktime;
    string name,gender,place;
    char job;
    double salary,value;
    cout<<left<<setw(11)<<"职工号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(15)<<"职业"<<setw(10)<<"部门"<<setw(10)<<"工资"<< '\n';
    while (1)
    {
        cin>>id;
        if(id==0) break;
        if(cin.peek()=='\n'){
            for (auto it = emps.begin(); it != emps.end(); it++) {
                if (it->getid() == id) {
                    emps.erase(it);
                    break;
                }
            }
            continue;
        }
        cin>>name;
        if(name=="0") break;
        for (auto it = emps.begin(); it != emps.end(); it++) {
            if (it->getid() == id) {
                emps.erase(it);
                break;
            }
        }
        cin>>gender>>age>>job>>place;
        if(job=='A'||job=='a'){
            //不换行则输入工资，换行则工资为8000
            if(cin.peek()=='\n'){
                salary=8000;
            }
            else cin>>salary;
        }
        else cin>>salary;
        switch (job)
        {
        case 'B':
        case 'b':
            {
                if (salary==1)
                {
                    cin>>worktime;
                    salary=worktime*100;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                break;
            }
        case 'C':
        case 'c':
            {
                if (salary==1)
                {
                    cin>>value;
                    salary=0.04*value;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                if (salary==1)
                {
                    emps.back().setvalue(value);
                }
                break;
            }
        case 'D':
        case 'd':
            {
                if (salary==1){
                    cin>>value;
                    salary=0;
                }
                emps.emplace_back(id,name,gender,age,job,place,salary);
                if (salary==1)
                {
                    emps.back().setvalue(value);
                }
                break;
            }
        case 'A':
        case 'a':
            {
                emps.emplace_back(id,name,gender,age,job,place,salary);
                break;
            }
        default:
            {
                cerr<<"错误的职业"<<endl;
                continue;
            }
        }
    }
}
void menu::output(){
    system("cls");
    cout<<left<<setw(11)<<"职工号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(15)<<"职业"<<setw(10)<<"部门"<<setw(10)<<"工资"<<setw(10)<<"排名"<< '\n';

    // 打印所有员工的信息
    for (const auto& employee : emps) {
        char job=employee.getjob();
        string j;
        if(job=='B'||job=='b'){
            j="技术员";
        }
        else if(job=='C'||job=='c'){
            j="销售员";
        }
        else if(job=='D'||job=='d'){
            j="销售经理";
        }
        else if(job=='A'||job=='a'){
            j="经理";
        }
        cout << left << setw(8) << employee.getid()
             << setw(10) << employee.getname()
             << setw(9) << employee.getgender()
             << setw(8) << employee.getage()
             << setw(15) << j
             << setw(10) << employee.getplace()
             << setw(10) << employee.getsalary()
             << setw(10) << employee.getrank()
             << '\n';
    }
    cout<<endl<<endl;

    double allsum = 0;
    for(const auto& department : departments){
        double sum = 0;
        cout << "部门：" << department << '\n';
        cout << left << setw(11) << "职工号"<< setw(10) << "姓名"<< setw(10) << "销售额"<< '\n';
        for (const auto& employee : emps) {
            if (employee.getplace() == department) {
                cout << left << setw(8) << employee.getid()
                    << setw(10) << employee.getname()
                    << setw(10) << employee.getvalue()
                    << '\n';
                sum += employee.getvalue();
            }
        }
        allsum += sum;
        cout << "销售额合计：" << sum << "\n\n";
    }
    cout << "总销售额：" << allsum << '\n';
    cout<<"按enter键增删改，按其他任意键返回"<<endl;
    if(_getch()==13){
        update();
    }
}

void backups1(){
    ofstream outFile1("employees.txt");
    if (!outFile1) {
        cerr << "无法打开文件";
        return;
    }

    outFile1<<left<<setw(10)<<"职工号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(15)<<"职业"<<setw(10)<<"部门"<<setw(10)<<"工资"<<setw(10)<<"排名"<< '\n';
    for (const auto& employee : emps) {
        char job=employee.getjob();
        string j;
        if(job=='B'||job=='b'){
            j="技术员";
        }
        else if(job=='C'||job=='c'){
            j="销售员";
        }
        else if(job=='D'||job=='d'){
            j="销售经理";
        }
        else if(job=='A'||job=='a'){
            j="经理";
        }
        outFile1 << left << setw(11) << employee.getid()
             << setw(10) << employee.getname()
             << setw(10) << employee.getgender()
             << setw(10) << employee.getage()
             << setw(15) << j
             << setw(10) << employee.getplace()
             << setw(10) << employee.getsalary()
             << setw(10) << employee.getrank()
             << '\n';
    }
    outFile1.close();

    ofstream outFile2("value.txt");
    if (!outFile2) {
        cerr << "无法打开文件";
        return;
    }

    for (const auto& employee : emps) {
        if ((find(departments.begin(), departments.end(), employee.getplace()) == departments.end())&&employee.getplace()!="无") {
            departments.push_back(employee.getplace());
        }
    }
    double allsum = 0;
    for(const auto& department : departments){
        double sum = 0;
        outFile2 << "部门：" << department << '\n';
        outFile2 << left << setw(10) << "职工号"<< setw(10) << "姓名"<< setw(10) << "销售额"<< '\n';
        for (const auto& employee : emps) {
            if (employee.getplace() == department) {
                outFile2 << left << setw(11) << employee.getid()
                    << setw(10) << employee.getname()
                    << setw(10) << employee.getvalue()
                    << '\n';
                sum += employee.getvalue();
            }
        }
        allsum += sum;
        outFile2 << "销售额合计：" << sum << "\n\n";
    }
    outFile2 << "总销售额：" << allsum << '\n';
    outFile2.close();
}
void menu::backups(){
    system("cls");
    bool isinput=true;
    while(isinput){
        system("cls");
        cout << "****************************\n\n";
        cout << "       数据备份\n\n";
        cout << "      1.导出.txt文件"<<endl;
        cout << "      2.返回\n\n\n\n";
        cout << "导出的文件前缀为employees和value"<<endl;
        cout << "****************************" << endl;
        char in=_getch();
        switch (in)
        {
        case '1':
            backups1();
            isinput=false;
            break;
        case '2':
            isinput=false;
            break;
        }
    }
}