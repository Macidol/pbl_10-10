#ifndef MONAN_H
#define MONAN_H
#include <iostream>
using namespace std;
class MonAn{
private:
    string maMon;
    string tenMon;
    double gia;
public:
    MonAn();
    void nhap();
    void xuat();
    string getMaMon();
    string getTenMon();
    double getGia();
    void setGia(double gia);
};

#endif

