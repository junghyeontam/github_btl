#include "QuanLyThuVien.h"
#include <iostream>
using namespace std;

int main() {
    QuanLyThuVien ql;
    int chon;
    
    do {
        cout << "\n=== QUAN LY THU VIEN ===\n";
        cout << "1. Them sach\n";
        cout << "2. Sua sach\n";
        cout << "3. Xoa sach\n";
        cout << "4. Them SV\n";
        cout << "5. Sua SV\n";
        cout << "6. Xoa SV\n";
        cout << "7. Muon sach\n";
        cout << "8. Tra sach\n";
        cout << "9. In sach\n";
        cout << "10. In sach cua SV\n";
        cout << "11. In sach dang muon\n";
        cout << "12. Thoat\n";
        cout << "Chon: "; cin >> chon;
        
        switch (chon) {
            case 1: ql.themSach(); break;
            case 2: ql.suaSach(); break;
            case 3: ql.xoaSach(); break;
            case 4: ql.themSV(); break;
            case 5: ql.suaSV(); break;
            case 6: ql.xoaSV(); break;
            case 7: ql.muonSach(); break;
            case 8: ql.traSach(); break;
            case 9: ql.inSach(); break;
            case 10: ql.inSachSV(); break;
            case 11: ql.inSachDangMuon(); break;
            case 12: cout << "Bye!\n"; break;
            default: cout << "Sai!\n";
        }
    } while (chon != 12);
    
    return 0;
}