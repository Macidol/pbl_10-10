#include "monan.h"

MonAn::MonAn(){

    maMon = "";

    tenMon = "";

    gia = 0;

}
string MonAn::getMaMon(){
    return maMon;
}
string MonAn::getTenMon(){
    return tenMon;
}
double MonAn::getGia(){
    return gia;
}
void MonAn::setGia(double gia){
    if(gia >= 0){
        this->gia = gia;
    }
}
void MonAn::nhap(){
    cin.ignore();
    cout << "Nhap ten mon: ";
    getline(cin, tenMon);
    cout << "Nhap gia: ";
    cin >> gia;
}
void MonAn::xuat(){

    cout << tenMon
         << " - "
         << gia
         << endl;
}

