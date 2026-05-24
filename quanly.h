#ifndef QUANLY_H
#define QUANLY_H
#include <iostream>
#include <vector>
#include "hoadon.h"
using namespace std;
class QuanLy{
private:
    vector<MonAn> dsMon;
    vector<HoaDon> dsHoaDon;

public:
    void role();
    void khoiTaoMenu();
    void HienThiMenu();
    void TaoHoaDon();
    void xuatDanhSachHoaDon();
    void menu();
};
#endif