#include "quanly.h"
#include <iomanip>
#include <sstream>
#include <fstream>
void QuanLy::luuMenuVaoFile(){
    ofstream file("menu.txt"); 
    if (file.is_open()) {
        for (int i = 0; i < dsMon.size(); i++) {
            // Ghi theo định dạng: Tên món,Giá tiền (ngăn cách bằng dấu phẩy)
            file << dsMon[i].getTenMon() << "," << (int)dsMon[i].getGia() << endl;}
        file.close(); // Ghi xong phải đóng file
    } else {
        cout << "Loi: Khong the mo file de ghi du lieu!\n";
    }
}
void QuanLy::khoiTaoMenu(){
    // ifstream dùng để đọc dữ liệu từ file menu.txt
    ifstream file("menu.txt"); 
    if (file.is_open()) {
        string line;
        // Đọc từng dòng trong file text ra
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            stringstream ss(line);
            string ten;
            string giaStr;
            
            // Tách tên món và giá tiền dựa vào dấu phẩy ','
            if (getline(ss, ten, ',') && getline(ss, giaStr)) {
                MonAn mon;
                // stod chuyển chuỗi giá tiền thành kiểu double
                mon.setThongTin(ten, stod(giaStr)); 
                dsMon.push_back(mon);
            }
        }
        file.close();
    }
    else{
    dsMon.clear();
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
        70000, 75000, 68000, 62000, 90000,

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
this->luuMenuVaoFile();}
}
void QuanLy::HienThiMenu() {
    // 1. Xóa danh sách món cũ trên RAM để tránh bị trùng lặp dữ liệu
    this->dsMon.clear();
    // 2. Gọi lại hàm khởi tạo để nạp lại toàn bộ món ăn mới nhất từ file menu.txt vào RAM
    this->khoiTaoMenu();
    cout << left;

    // ==================== PHẦN MÓN ĂN (30 MÓN) ====================
    cout << "\n======================== BURGER CORTIS MENU - FOOD ========================\n\n";
    int tongsomon= dsMon.size();
    int somonnuoc=10;
    int somonan=tongsomon-somonnuoc;//so mon an sau khi da them bot
    //tinh so hang can thiet cho mon an khi chia thanh 3 cot
    int sohangmonan=(somonan+2)/3;
    for (int i = 0; i < sohangmonan; i++) {
        // In 3 cột món ăn tự động theo số hạng tính toán
        for (int j = 0; j < 3; j++) {
            int index = i + (j*sohangmonan);
            if (index < somonan) {
                string giaKemDonVi = to_string((int)dsMon[index].getGia()) + "VND";
                
                cout << left
                     << setw(3)  << index + 1
                     << setw(20) << dsMon[index].getTenMon()
                     << setw(10) << giaKemDonVi;
            }
        }
        cout << endl;
    }
    // ==================== PHẦN NƯỚC UỐNG (10 MÓN) ====================
// ==================== PHẦN NƯỚC UỐNG ====================

cout << "\n======================= BURGER CORTIS MENU - DRINKS =======================\n\n";
//chia số nước ra thành 2 cột
int sohangnuocuong=(somonnuoc +1)/2;
int indexbatdaunuoc=somonan;//Vị trí bắt đầu của nước trong vector
for (int i = 0; i < sohangnuocuong; i++) {
    for (int j = 0; j < 2; j++) {
        int index = indexbatdaunuoc + i +(j*sohangnuocuong);
        if (index < tongsomon) {
            string giaNuocKemDonVi =
                to_string((int)dsMon[index].getGia()) + "VND";
            cout << left
                 << setw(3)  << index + 1
                 << setw(20) << dsMon[index].getTenMon()
                 << setw(10) << giaNuocKemDonVi;   }}
    cout << endl;
}

    cout << "\n===========================================================================\n";
}
void QuanLy::TaoHoaDon(){
    HoaDon hd;
    while(true){
        string line;
        cout << "\nQuy khach vui long nhap id mon(vui long co dau cach) ";
        getline(cin >> ws, line);
        stringstream ss(line);
        int id;
        bool hopLe = true;
        while(ss >> id){
            if(id >= 1 && id <= dsMon.size()){
                hd.themMon(dsMon[id - 1]);
                cout<<"Da them"<<" "<<dsMon[id - 1].getTenMon()<<" vao hoa don."<<endl;
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
    cout<<"Chuc quy khach co bua an ngon mieng tai Burger Cortis Restaurant!"<<endl<<endl<<endl;
    cout<<"Bam nut 1 de xem hoa don cua ban!"<<endl;
    int chon;
    do{
        cout << "Nhap lua chon: ";
        cin >> chon;
        if(chon != 1){
            cout << "Lua chon khong hop le,vui long nhap!\n";
        }
    }while(chon != 1);
    if(chon == 1){
        hd.tinhTongTien();
        hd.xuat();
    }
}
void QuanLy::role(){
    int chon;
    while(true){
        cout << "\n===== Burger Cortis Restaurant =====\n";
        cout << "1. Quan ly\n";
        cout << "2. Nhan vien\n";
        cout << "3. Khach hang\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        if(chon == 1){
            int solannhapsai=0;
            bool dangnhap=false;
            while(solannhapsai<3){
            string matkhau;
            cout<<"nhap mat khau quan ly\n";
            cin>>matkhau;
            if(matkhau =="26122007AH"){
                    cout<<"dang nhap thanh cong\n";
                    dangnhap=true;
                     break;
            }
            else {
                solannhapsai++;
                cout<<"nhap mat khau khong dung , vui long nhap lai\n";
            }
        if(solannhapsai==3){
                cout<<"ban da nhap sai qua gioi han , vui long dang nhap lai\n";
                dangnhap=false;
             }}
            //=======MENU QUAN LY===============
        if(dangnhap){
                     int luachon;
             do{
        cout << "\n======= QUAN LY =======\n";
        cout << "1. Them hamburger\n";
        cout << "2. Xoa mon an\n";
        cout << "3. Sua lai mon an\n";
        cout << "4. Tim mon an theo ten\n";
        cout << "5. Xep lich cho nhan vien\n";
        cout << "6. Hien thi lich truc\n";
        cout << "0. Dang xuat\n";
        cout << "Nhap lua chon: ";
        cin>>luachon;
          if(luachon == 1){
                    string ten;
                    double gia;
                    cin.ignore();
                    cout << "Nhap ten mon moi: ";
                    getline(cin, ten);
                    cout << "Nhap gia mon: ";
                    cin >> gia;
                    MonAn mon;
                    mon.setThongTin(ten, gia);
                    dsMon.insert(dsMon.end()-10,mon);//thêm đúng logic món ăn
                    cout << "Them mon thanh cong!\n";
                    luuMenuVaoFile();
                }
            else if(luachon == 2){
                    int id;
                    HienThiMenu();
                    cout << "Nhap ID mon can xoa: ";
                    cin >> id;
                    if(id >= 1 && id <= dsMon.size()){
                        dsMon.erase(dsMon.begin() + (id - 1));
                        cout << "Xoa mon thanh cong!\n";
                        luuMenuVaoFile();
                    }
                    else{
                        cout << "ID khong hop le!\n";}}
            else if(luachon == 3){
                    int id;
                    HienThiMenu();
                    cout << "Nhap ID mon can sua: ";
                    cin >> id;
                    if(id >= 1 && id <= dsMon.size()){
                        string tenMoi;
                        double giaMoi;
                        cin.ignore();
                        cout << "Nhap ten moi: ";
                        getline(cin, tenMoi);
                        cout << "Nhap gia moi: ";
                        cin >> giaMoi;
                        dsMon[id - 1].setThongTin(tenMoi, giaMoi);
                        cout << "Cap nhat thanh cong!\n";
                    luuMenuVaoFile(); }
                    else{
                        cout << "ID khong hop le!\n";}}
            else if(luachon == 4){
                    string tenTim;
                    cin.ignore();
                    cout << "Nhap ten mon can tim: ";
                    getline(cin, tenTim);
                    this->dsMon.clear();
                    this->khoiTaoMenu();
                    bool timThay = false;
                    for(int i = 0; i < dsMon.size(); i++){
                        if(dsMon[i].getTenMon() == tenTim){
                            cout << "\nTim thay:\n";
                            cout << i + 1
                                 << " - "
                                 << dsMon[i].getTenMon()
                                 << " - "
                                 << dsMon[i].getGia()
                                 << "đ\n";
                            timThay = true;}}
                    if(timThay == false){
                        cout << "Khong tim thay mon!\n";}}
            else if(luachon==5){
                this->quanLySapXepCa();
            }
            else if(luachon==6){
                this->hienThiLichLamViec();
            }
            else if(luachon == 0){
                            cout << "Dang xuat thanh cong!\n";
                }
                else{
                            cout << "Lua chon khong hop le!\n";
                        }}while(luachon!=0 );}}
        else if(chon == 2){
            int nvchon;
            string tenNV;
            cin.ignore();
            cout<<"moi nhap ten nhan vien: \n";
            getline(cin, tenNV);
 do{
        cout << "\n======= NHAN VIEN =======\n";
        cout << "1. Dang ky lich truc\n";
        cout << "2. Xem lich lam viec chung\n";
        cout << "0. Dang xuat\n";
        cout << "Nhap lua chon: ";
        cin>>nvchon;
        if(nvchon==1){
            this->nhanVienDangKyCa(tenNV);
        }
        if(nvchon==2){
            this->hienThiLichLamViec();
        }
              }while(nvchon!=0);
        }
        else if(chon == 3){
            cout << "Xin chao khach hang!\n";
            cout << "Chuc ban co mot bua an ngon mieng tai Burger Cortis Restaurant!\n";
    int choice;
        cout << "\n===== Xin moi chon mon =====\n";
        HienThiMenu();
        TaoHoaDon();

    }
        else if(chon == 0){
            cout << "Cam on ban da su dung phan mem. Hen gap lai!\n";
            system("pause");
            break;
        }
        else{
            cout << "Lua chon khong hop le. Vui long nhap lai!\n";}}}
void QuanLy::khoiTaoCacCaTruc() {
    string cacThu[] = {"Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7", "Chu Nhat"};
    string cacTenCa[] = {"Ca Sang (6h-12h)", "Ca Chieu (12h-18h)", "Ca Toi (18h-23h)"};
    dsCatructrongtuan.clear();//xóa bộ nhớ trước khi nạp
    for (string thu : cacThu) { // duyệt vòng 1 qua từng thứ(lập cho tới hết chủ nhật)
        for (int i = 0; i < 3; i++) {//duyệt xomg thứ thì qua duyệt các ca vd duyệt vòng 1 thứ 2 có 3 ca
            catruc ca;
            ca.idCa = i + 1;//gán ID ca(1,2 và 3)
            ca.tenCa = cacTenCa[i];//gán tên ca tương ứng từ mảng cacTenCa
            ca.thu = thu;//gán thứ tương ứng vòng lặp
            dsCatructrongtuan.push_back(ca);//thêm ca vào vector tổng hợp
        }
    }
}
//HÀM NHÂN VIÊN ĐĂNG KÝ CA TRỰC
void QuanLy::nhanVienDangKyCa(string tenNV) {
    cout << "\n===== DANG KY CA TRUC CHO NHAN VIEN: " << tenNV << " =====\n";
    // Hiển thị danh sách ca
    for (int i = 0; i < dsCatructrongtuan.size(); i++) { 
        cout << i + 1 << ". " << dsCatructrongtuan[i].thu //danh sách hiển thị ca trực chạy từ 0->21
             << " - " << dsCatructrongtuan[i].tenCa << "\n";
    }
    cout << "\nNhap cac ID ca ban muon dang ky (cach nhau bang dau cach, an Enter de HOAN TAT): ";
    string line;

    // getline(cin >> ws, line) giúp xóa sạch ký tự '\n' còn kẹt ở đợt nhập trước
    getline(cin >> ws, line); 
    stringstream ss(line);
    int chon;
    bool coDangKy = false;
    // Tách từng ID ra để xử lý, không sợ bị kẹt dòng
    while (ss >> chon) { 
        if (chon >= 1 && chon <= dsCatructrongtuan.size()) { 
            dsCatructrongtuan[chon - 1].dsnhanviendangky.push_back(tenNV);
            cout << "  -> Da ghi nhan nguyen vong ca [" << chon << "]\n";
            coDangKy = true;
        } else {
            cout << "  -> ID ca [" << chon << "] khong hop le! (Bo qua)\n";
        }
    }
    if (coDangKy) {
        cout << "==> Dang ky ca hoan tat!\n";
    } else {
        cout << "==> Ban chua dang ky ca nao.\n";
    }
}
void QuanLy::quanLySapXepCa() {
    cout << "\n======= QUAN LY SAP XEP CA TRUC =======\n";
    for (int i = 0; i < dsCatructrongtuan.size(); i++) {
        catruc &ca = dsCatructrongtuan[i];
        cout << "\n[" << i + 1 << "] " << ca.thu << " - " << ca.tenCa << "\n";
        // Hiện danh sách nhân viên đã đăng ký ca này
        //hàm emty kiểm tra danh sách nvdangky có bị trống hay không và nhanvientrucchinhthuc có hay không
        // nghĩa là nó sẽ hiện ra có ai muốn làm ca này và ca nào đã có nhân viên đăng kí hay chưa 
        cout << "   Nhan vien dang ky: ";
        if (ca.dsnhanviendangky.empty()) cout << "(Trong)";
        for (string nv : ca.dsnhanviendangky) cout << nv << " | ";
        cout << "\n";
        // Hiện danh sách đã được duyệt trước đó (nếu có)
        cout << "   Chinh thuc hien tai: ";
        if (ca.dsnhanvientrucchinhthuc.empty()) cout << "(Chua co)";
        for (string nv : ca.dsnhanvientrucchinhthuc) cout << nv << " | ";
        cout << "\n";
        // Tiến hành sắp xếp
        int luaChon;
        cout << "   1. Them NV vao ca nay | 2. Bo qua ca nay: ";
        cin >> luaChon;
        if (luaChon == 1) {
            string tenNV;
            cin.ignore();
            cout << "   Nhap ten nhan vien chinh thuc cho ca nay: ";
            getline(cin, tenNV);
            ca.dsnhanvientrucchinhthuc.push_back(tenNV);
            cout << "   => Da xep " << tenNV << " vao ca lam chinh thuc!\n";}}
    cout << "\nDa hoan thanh sap xep lich truc cho toan bo cac ca!\n";
    //lặp lại 21 ca trực để chọn nhân viên
}
void QuanLy::hienThiLichLamViec() {
    cout << "\n==================== LICH LAM VIEC CHINH THUC BIEU ====================\n";
    for (const auto& ca : dsCatructrongtuan) {
        // auto là từ khóa yêu cầu C++ tự động nhận diện kiểu dữ liệu (ở đây là catruc)
        //const yêu cầu trình biên dịch chỉ xem thông tin chứ không dùng để thay đổi dữ liệu của ca trực
        //=> yêu cầu lấy ca trực để xem chỉ xem và không sửa
        cout << left << setw(12) << ca.thu 
             << left << setw(25) << ca.tenCa << " -> NV Chinh thuc: ";
        if (ca.dsnhanvientrucchinhthuc.empty()) { //emty tìm ra nếu ca trực chưa có ai thì in là chưa xếp lịch
            cout << "CHUA XEP LICH\n";
        } else {
            for (string nv : ca.dsnhanvientrucchinhthuc) {
                cout << nv << "   ";}
            cout << "\n";}}
    cout << "========================================================================\n";
}
