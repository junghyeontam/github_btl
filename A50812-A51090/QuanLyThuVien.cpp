#include "QuanLyThuVien.h"
#include <iostream>
using namespace std;

QuanLyThuVien::QuanLyThuVien() { 
    doc(); 
}

QuanLyThuVien::~QuanLyThuVien() {
    for (int i = 0; i < dsSach.size(); i++) {
        delete dsSach[i];
    }
    for (int i = 0; i < dsSV.size(); i++) {
        delete dsSV[i];
    }
}

Sach* QuanLyThuVien::timSach(string ma) {
    for (int i = 0; i < dsSach.size(); i++) {
        if (dsSach[i]->getMa() == ma) {
            return dsSach[i];
        }
    }
    return nullptr;
}

SinhVien* QuanLyThuVien::timSV(string ma) {
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->getMa() == ma) {
            return dsSV[i];
        }
    }
    return nullptr;
}

void QuanLyThuVien::luu() {
    ofstream f1("sach.dat", ios::binary);
    size_t n = dsSach.size();
    f1.write((char*)&n, sizeof(n));
    for (int i = 0; i < dsSach.size(); i++) {
        dsSach[i]->ghiFile(f1);
    }
    f1.close();
    
    ofstream f2("sinhvien.dat", ios::binary);
    n = dsSV.size();
    f2.write((char*)&n, sizeof(n));
    for (int i = 0; i < dsSV.size(); i++) {
        dsSV[i]->ghiFile(f2);
    }
    f2.close();
}

void QuanLyThuVien::doc() {
    ifstream f1("sach.dat", ios::binary);
    if (f1) {
        size_t n;
        f1.read((char*)&n, sizeof(n));
        for (size_t i = 0; i < n; i++) {
            Sach* s = new Sach();
            s->docFile(f1);
            dsSach.push_back(s);
        }
        f1.close();
    }
    
    ifstream f2("sinhvien.dat", ios::binary);
    if (f2) {
        size_t n;
        f2.read((char*)&n, sizeof(n));
        for (size_t i = 0; i < n; i++) {
            SinhVien* sv = new SinhVien();
            sv->docFile(f2);
            dsSV.push_back(sv);
        }
        f2.close();
    }
}

void QuanLyThuVien::themSach() {
    Sach* s = new Sach();
    s->nhap();
    
    if (timSach(s->getMa()) != nullptr) {
        cout << "Ma da ton tai!" << endl;
        delete s;
        return;
    }
    
    dsSach.push_back(s);
    luu();
    cout << "Them thanh cong!" << endl;
}

void QuanLyThuVien::suaSach() {
    string ma;
    cout << "Ma sach: ";
    cin >> ma;
    
    Sach* s = timSach(ma);
    if (s == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    s->nhap();
    luu();
    cout << "Sua thanh cong!" << endl;
}

void QuanLyThuVien::xoaSach() {
    string ma;
    cout << "Ma sach: ";
    cin >> ma;
    
    Sach* s = timSach(ma);
    if (s == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    if (s->isDangMuon() == true) {
        cout << "Sach dang muon!" << endl;
        return;
    }
    
    for (int i = 0; i < dsSach.size(); i++) {
        if (dsSach[i]->getMa() == ma) {
            delete dsSach[i];
            dsSach.erase(dsSach.begin() + i);
            break;
        }
    }
    
    luu();
    cout << "Xoa thanh cong!" << endl;
}

void QuanLyThuVien::themSV() {
    SinhVien* sv = new SinhVien();
    sv->nhap();
    
    if (timSV(sv->getMa()) != nullptr) {
        cout << "Ma da ton tai!" << endl;
        delete sv;
        return;
    }
    
    dsSV.push_back(sv);
    luu();
    cout << "Them thanh cong!" << endl;
}

void QuanLyThuVien::suaSV() {
    string ma;
    cout << "Ma SV: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    sv->nhap();
    luu();
    cout << "Sua thanh cong!" << endl;
}

void QuanLyThuVien::xoaSV() {
    string ma;
    cout << "Ma SV: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    if (sv->dangMuon() == true) {
        cout << "SV dang muon sach!" << endl;
        return;
    }
    
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->getMa() == ma) {
            delete dsSV[i];
            dsSV.erase(dsSV.begin() + i);
            break;
        }
    }
    
    luu();
    cout << "Xoa thanh cong!" << endl;
}

void QuanLyThuVien::muonSach() {
    string maSV, maSach;
    cout << "Ma SV: ";
    cin >> maSV;
    cout << "Ma sach: ";
    cin >> maSach;
    
    SinhVien* sv = timSV(maSV);
    Sach* s = timSach(maSach);
    
    if (sv == nullptr || s == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    if (s->isDangMuon() == true) {
        cout << "Sach da muon!" << endl;
        return;
    }
    
    s->setDangMuon(true, maSV);
    sv->themSach(maSach);
    luu();
    cout << "Muon thanh cong!" << endl;
}

void QuanLyThuVien::traSach() {
    string maSV, maSach;
    cout << "Ma SV: ";
    cin >> maSV;
    cout << "Ma sach: ";
    cin >> maSach;
    
    SinhVien* sv = timSV(maSV);
    Sach* s = timSach(maSach);
    
    if (sv == nullptr || s == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    if (s->isDangMuon() == false) {
        cout << "Sach chua duoc muon!" << endl;
        return;
    }
    
    if (s->getMaNguoiMuon() != maSV) {
        cout << "SV khong muon sach nay!" << endl;
        return;
    }
    
    s->setDangMuon(false);
    sv->xoaSach(maSach);
    luu();
    cout << "Tra thanh cong!" << endl;
}

void QuanLyThuVien::inSach() {
    cout << "\n=== DANH SACH SACH ===" << endl;
    for (int i = 0; i < dsSach.size(); i++) {
        dsSach[i]->xuat();
    }
}

void QuanLyThuVien::inSachSV() {
    string ma;
    cout << "Ma SV: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay!" << endl;
        return;
    }
    
    cout << "\n=== SACH CUA " << sv->getTen() << " ===" << endl;
    vector<string> ds = sv->getDsSach();
    for (int i = 0; i < ds.size(); i++) {
        Sach* s = timSach(ds[i]);
        if (s != nullptr) {
            s->xuat();
        }
    }
}

void QuanLyThuVien::inSachDangMuon() {
    cout << "\n=== SACH DANG MUON ===" << endl;
    for (int i = 0; i < dsSach.size(); i++) {
        if (dsSach[i]->isDangMuon() == true) {
            dsSach[i]->xuat();
            SinhVien* sv = timSV(dsSach[i]->getMaNguoiMuon());
            if (sv != nullptr) {
                cout << "  -> Nguoi muon: " << sv->getTen() << endl;
            }
        }
    }
}