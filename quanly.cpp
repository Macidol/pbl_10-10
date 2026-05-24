#include "quanly.h"
#include <iomanip>
#include <sstream>
void QuanLy::khoiTaoMenu(){
    string tenMon[] = {
        "Classic Burger", "Cheese Burger", "Double Beef Burger","Chicken Burger", "Spicy Burger",
        "BBQ Burger", "Bacon Burger", "Mushroom Burger", "Egg Burger", "Mega Burger", 
        "French Fries", "Cheese Fries",  "Chicken Nuggets", "Onion Rings", "Hot Dog",
        "Fried Chicken", "Chicken Wings", "Fish and Chips", "Taco Beef", "Nachos",
        "Pizza Seafood", "Pizza Beef", "Pizza Cheese", "Spaghetti","Carbonara",
        "Beef Steak", "Grilled Chicken", "Caesar Salad", "Greek Salad", "Soup Pumpkin",
        "Coca Cola", "Pepsi","7 Up", "Orange Juice", "Lemon Tea",
        "Peach Tea", "Milk Tea", "Black Coffee", "Latte", "Mineral Water"
};
    double gia[] = {
        45000, 50000, 65000, 55000, 60000,
        70000, 75000, 68000, 620100, 90000,

        30000, 35000, 40000, 35000, 45000,
        80000, 85000, 95000, 70000, 65000,

        120000, 130000, 110000, 85000, 95000,
        180000, 140000, 60000, 65000, 50000,

         15000, 15000, 15000, 25000, 30000,
        35000, 40000, 30000, 45000, 10000
    };
    for(int i = 0; i < 40; i++){
        MonAn mon;
        mon.setThongTin(tenMon[i], gia[i]); //Gọi hàm setThongTin ở file MonAn để gán tên món và giá cho đối tượng mon
        dsMon.push_back(mon); //dsMon là vector<MonAn> nằm ở file quanly.h
    }
}
void QuanLy::HienThiMenu() {
    cout << left;

    // ==================== PHẦN MÓN ĂN (30 MÓN) ====================
    cout << "\n======================== BURGER CORTIS MENU - FOOD ========================\n\n";
    
    for (int i = 0; i < 10; i++) {
        // In 3 cột món ăn (Cột 1: 1-10, Cột 2: 11-20, Cột 3: 21-30)
        for (int j = 0; j <= 20; j += 10) {
            int index = i + j;
            if (index < dsMon.size()) {
                string giaKemDonVi = to_string((int)dsMon[index].getGia()) + "đ";
                
                cout << left
                     << setw(3)  << index + 1
                     << setw(20) << dsMon[index].getTenMon()
                     << setw(10) << giaKemDonVi;
            }
        }
        cout << endl;
    }

    // ==================== PHẦN NƯỚC UỐNG (10 MÓN) ====================
    cout << "\n======================= BURGER CORTIS MENU - DRINKS =======================\n\n";
    
    // Nước uống có 10 món, mình có thể in 2 cột cho gọn (mỗi cột 5 món)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 5; j += 5) {
            int index = i + j;
            if (index < dsMon.size()) {
                string giaNuocKemDonVi = to_string((int)dsMon[index].getGia()) + "đ";
                
                cout << left
                     << setw(3)  << index + 31 // Đánh số từ 31-40 cho nước uống
                     << setw(20) << dsMon[index + 30].getTenMon()
                     << setw(10) << giaNuocKemDonVi;
            }
        }
        cout << endl;
    }

    cout << "\n===========================================================================\n";
}

void QuanLy::TaoHoaDon(){
    HoaDon hd;
    while(true){
        string line;
        cout << "\nQuý khách vui lòng nhập id món (cách nhau bởi dấu cách): ";
        getline(cin >> ws, line);
        stringstream ss(line);
        int id;
        bool hopLe = true;
        while(ss >> id){
            if(id >= 1 && id <= 40){
                hd.themMon(dsMon[id - 1]);
                cout<<"Đã thêm"<<" "<<dsMon[id - 1].getTenMon()<<" vào hóa đơn."<<endl;
            }
            else{
                cout << "ID "
                     << id
                     << " khong hop le!\n";
                hopLe = false;
                break;
            }
        }
        if(hopLe){
            break;
        }
        else{
            hd = HoaDon();
            cout << "Vui long nhap lai toan bo mon!\n";
        }
    }
    hd.Soban(); hd.Sothe();
    cout<<endl;
    cout<<"Chúc quý khách có một bữa ăn ngon miệng tại Burger Cortis Restaurant!"<<endl<<endl<<endl;
    cout<<"Bấm nút 1 để xem hóa đơn của bạn!"<<endl;
    int chon;
    do{
        cout << "Nhập lựa chọn: ";
        cin >> chon;
        if(chon != 1){
            cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại!\n";
        }
    }while(chon != 1);
    if(chon == 1){
        hd.tinhTongTien();
        hd.xuat();
    }
}
void QuanLy::role(){
    int chon;
    do{
        cout << "\n===== Burger Cortis Restaurant =====\n";
        cout << "1. Quan ly, nhan vien\n";
        cout << "2. Khach hang\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        if(chon == 1){cou<"Bú cặc"}
        else if(chon == 2){
            cout << "Xin chao khach hang!\n";
            cout << "Chúc bạn có một bữa ăn ngon miệng tại Burger Cortis Restaurant!\n";
    int choice;
        cout << "\n===== Xin mời chọn món =====\n";
        khoiTaoMenu();
        HienThiMenu();
        TaoHoaDon();

    }
        else if(chon == 0){
            cout << "Cam on ban da su dung phan mem. Hen gap lai!\n";
        }
        else{
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    }while(chon != 0 && chon != 1 && chon != 2);
}