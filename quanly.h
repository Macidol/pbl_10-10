#ifndef QUANLY_H
#define QUANLY_H
#include <vector>
#include "monan.h"
#include "hoadon.h"
using namespace std;
class QuanLy{
private:
    vector<MonAn> dsMon;
    vector<HoaDon> dsHoaDon;
public:
    void menu();
    void themMon();
    void hienThiMenu();
    void taoHoaDon();
};
#endif