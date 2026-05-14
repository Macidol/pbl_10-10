#ifndef HOADON_H
#define HOADON_H

#include <iostream>
#include <vector>

#include "monan.h"

using namespace std;

class HoaDon{

private:
    string maHD;
    vector<MonAn> dsMon;
    double tongTien;

public:

    HoaDon();

    void nhap();

    void themMon(MonAn mon);

    void tinhTongTien();

    void xuat();

    string getMaHD();

    double getTongTien();
};

#endif