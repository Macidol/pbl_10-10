#ifndef MONAN_H
#define MONAN_H
#include <iostream>
using namespace std;
class MonAn{
private:
    string tenMon;
    double gia;
public:
    MonAn();
    void setThongTin(string ten, double g);
    string getTenMon();
    double getGia();
    void xuat();
};
#endif