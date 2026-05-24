#include "monan.h"
#include <iomanip>
using namespace std;

// ================= MON AN =================
MonAn::MonAn(){
    tenMon = "";
    gia = 0;
}
void MonAn::setThongTin(string ten, double g){
    tenMon = ten;
    gia = g;
}
string MonAn::getTenMon(){
    return tenMon;
}
double MonAn::getGia(){
    return gia;
}
void MonAn::xuat(){
    cout << left << setw(25) << tenMon << gia << " VND"<<endl;
}
