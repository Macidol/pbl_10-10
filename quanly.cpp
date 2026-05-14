#include <iostream>
#include "quanly.h"
using namespace std;
void QuanLy::themMon(){
    MonAn mon;
    mon.nhap();
    dsMon.push_back(mon);
}
void QuanLy::hienThiMenu(){
    cout << "\n===== MENU =====\n";
    for(auto mon : dsMon){
        mon.xuat();
    }
}
void QuanLy::menu(){
    int choice;
    do{
        cout << "\n===== HAMBURGER MANAGEMENT =====\n";
        cout << "1. Them mon\n";
        cout << "2. Hien thi menu\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch(choice){
            case 1:
                themMon();
                break;
            case 2:
                hienThiMenu();
                break;
        }
    }while(choice != 0);

}