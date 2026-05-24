#ifndef HOADON_H
#define HOADON_H
#include <iostream>
#include <vector>
#include "monan.h"
using namespace std;

class HoaDon{
private:
    int soBan;
    string maHD;
    vector<MonAn> dsMon;
    double tongTien;
    static int dem;
    int stt;

public:
    HoaDon();
    void Sothe();
    void Soban();
    void nhap();
    void themMon(MonAn mon);
    void tinhTongTien();
    void xuat();
};

#endif