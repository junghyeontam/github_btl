#include "QuanLyThuVien.h"
#include <iostream>
using namespace std;

int main() {
    QuanLyThuVien ql;
    int chon;
    do {
        cout << "___________________________________________" << endl;
        cout << "HE THONG QUAN LY THU VIEN " << endl;
        cout << "1.Nhap them 1 cuon sach: " << endl;
        cout << "2.Sua thong tin sach (theo ma): " << endl;
        cout << "3.Xoa 1 cuon sach (theo ma): " << endl;
        cout << "4.Nhap thong tin sinh vien: " << endl;
        cout << "5.Sua thong tin SV : " << endl;
        cout << "6.Xoa thong tin SV: " << endl;
        cout << "7.Muon sach: " << endl;
        cout << "8.Tra sach: " << endl;
        cout << "9.Liet ke toan bo sach trong thu vien: " << endl;
        cout << "10.Liet ke sach cua mot sinh vien: " << endl;
        cout << "11.Liet ke toan bo sach duoc muon: " << endl;
        cout << "12.Thoat khoi he thong: " << endl;
        cout << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;
        
        switch (chon) {
            case 1: ql.themSach(); break;
            case 2: ql.suaSach(); break;
            case 3: ql.xoaSach(); break;
            case 4: ql.themSV(); break;
            case 5: ql.suaSV(); break;
            case 6: ql.xoaSV(); break;
            case 7: ql.muonSach(); break;
            case 8: ql.traSach(); break;
            case 9: ql.lietKeToanBoSach(); break;
            case 10: ql.lietKeSachCuaSV(); break;
            case 11: ql.lietKeSachDangMuon(); break;
            case 12: cout << "Thoat chuong trinh  " << endl; break;
            default:
                cout << "CHON 1-12   " << endl;
        }
        
        if (chon >= 1 && chon <= 11) {
            cout << "\nNhan enter tiep tuc   " << endl;
            cin.ignore();
            cin.get();
        }
        
    } while (chon != 12);
    return 0;
}