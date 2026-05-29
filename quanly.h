#ifndef QUANLY_H
#define QUANLY_H
#include <iostream>
#include <vector>
#include "hoadon.h"
#include "catruc.h"
using namespace std;
class QuanLy{
private:
    vector<MonAn> dsMon;
    vector<HoaDon> dsHoaDon;
    vector<catruc> dsCatructrongtuan;
public:
    void role();//vai trò
    void khoiTaoMenu();//tạo menu
    void HienThiMenu();//hiển thị menu
    void TaoHoaDon();//tạo hóa đơn
    void xuatDanhSachHoaDon();//Xuất hóa đơn
    void menu();
    void luuMenuVaoFile();//tạo file để lưu vào cpu
    void khoiTaoCacCaTruc();         // Tạo sẵn các ca Sáng/Chiều/Tối từ Thứ 2 đến CN
    void nhanVienDangKyCa(string tenNV); // Hàm cho nhân viên chọn ca
    void quanLySapXepCa();           // Hàm cho quản lý duyệt và sắp xếp
    void hienThiLichLamViec();       // Hàm xem lịch trực chung
};
#endif
