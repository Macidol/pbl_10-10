#include "hoadon.h"
#include <ctime>
#include <algorithm>
#include <sstream>
HoaDon::HoaDon(){
    tongTien = 0;
    dem++; stt = dem;
}
int HoaDon::dem = 0;
void HoaDon::Soban(){
    srand(time(0));
    soBan = rand() % 100 + 1;
    cout<<"Số bàn của bạn là: "<<soBan<<endl;
}
void HoaDon::Sothe(){
    cout << "Thứ tự nhận món của bạn là: "<< stt << endl;   
}
void HoaDon::themMon(MonAn mon){
    dsMon.push_back(mon);
}
void HoaDon::tinhTongTien(){
    tongTien = 0;
    for(auto mon : dsMon){
        tongTien += mon.getGia();
    }
}
void HoaDon::xuat(){
    cout << "\n===== HOA DON =====\n";
    // cout << "Ma hoa don: " << maHD << endl;
    cout << "\nDanh sach mon:\n";
    for(auto mon : dsMon){
        mon.xuat();
    }
    cout<<"=============================================\n\n";
    cout << "Tong tien: " << tongTien << " VND\n";
}