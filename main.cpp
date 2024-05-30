#include "menu.h"
#include "employees.h"
#include <iostream>
using namespace std;
int main(){
    system("chcp 65001");
    system("cls");
    while (1)
    {
        menu::showmenu();
    }
    return 0;
}