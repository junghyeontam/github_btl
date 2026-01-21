#include "QuanLyThuVien.h"
#include <iostream>
using namespace std;

QuanLyThuVien::QuanLyThuVien() { 
    docDuLieu(); 
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

void QuanLyThuVien::luuDuLieu() {
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

void QuanLyThuVien::docDuLieu() {
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
        cout << "Ma sach da ton tai!" << endl;
        delete s;
        return;
    }
    
    dsSach.push_back(s);
    luuDuLieu();
    cout << "Them sach thanh cong" << endl;
}

void QuanLyThuVien::suaSach() {
    string ma;
    cout << "Nhap ma sach can sua: ";
    cin >> ma;
    
    Sach* s = timSach(ma);
    if (s == nullptr) {
        cout << "Khong tim thay sach!" << endl;
        return;
    }
    
    cout << "Nhap thong tin moi:" << endl;
    s->nhap();
    luuDuLieu();
    cout << "Sua sach thanh cong!" << endl;
}

void QuanLyThuVien::xoaSach() {
    string ma;
    cout << "Nhap ma sach can xoa: ";
    cin >> ma;
    
    Sach* s = timSach(ma);
    if (s == nullptr) {
        cout << "Khong tim thay sach!" << endl;
        return;
    }
    
    if (s->isDangMuon() == true) {
        cout << "Khong the xoa sach dang duoc muon!" << endl;
        return;
    }
    
    for (int i = 0; i < dsSach.size(); i++) {
        if (dsSach[i]->getMa() == ma) {
            delete dsSach[i];
            dsSach.erase(dsSach.begin() + i);
            break;
        }
    }
    
    luuDuLieu();
    cout << "Xoa sach thanh cong!" << endl;
}

void QuanLyThuVien::themSV() {
    SinhVien* sv = new SinhVien();
    sv->nhap();
    
    if (timSV(sv->getMa()) != nullptr) {
        cout << "Ma sinh vien da ton tai!" << endl;
        delete sv;
        return;
    }
    
    dsSV.push_back(sv);
    luuDuLieu();
    cout << "Them sinh vien thanh cong!" << endl;
}

void QuanLyThuVien::suaSV() {
    string ma;
    cout << "Nhap ma sinh vien can sua: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    
    cout << "Nhap thong tin moi (khong sua thong tin muon sach):" << endl;
    sv->nhap();
    luuDuLieu();
    cout << "Sua sinh vien thanh cong!" << endl;
}

void QuanLyThuVien::xoaSV() {
    string ma;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    
    if (sv->dangMuonSach() == true) {
        cout << "Khong the xoa sinh vien dang muon sach!" << endl;
        return;
    }
    
    for (int i = 0; i < dsSV.size(); i++) {
        if (dsSV[i]->getMa() == ma) {
            delete dsSV[i];
            dsSV.erase(dsSV.begin() + i);
            break;
        }
    }
    
    luuDuLieu();
    cout << "Xoa sinh vien thanh cong!" << endl;
}

void QuanLyThuVien::muonSach() {
    string maSV, maSach;
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cout << "Nhap ma sach: ";
    cin >> maSach;
    
    SinhVien* sv = timSV(maSV);
    Sach* s = timSach(maSach);
    
    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    
    if (s == nullptr) {
        cout << "Khong tim thay sach!" << endl;
        return;
    }
    
    if (s->isDangMuon() == true) {
        cout << "Sach da duoc muon!" << endl;
        return;
    }
    
    s->setDangMuon(true);
    s->setMaNguoiMuon(maSV);
    sv->themSach(maSach);
    
    luuDuLieu();
    cout << "Muon sach thanh cong!" << endl;
}

void QuanLyThuVien::traSach() {
    string maSV, maSach;
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cout << "Nhap ma sach: ";
    cin >> maSach;
    
    SinhVien* sv = timSV(maSV);
    Sach* s = timSach(maSach);
    
    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    
    if (s == nullptr) {
        cout << "Khong tim thay sach!" << endl;
        return;
    }
    
    if (s->isDangMuon() == false) {
        cout << "Sach chua duoc muon!" << endl;
        return;
    }
    
    if (s->getMaNguoiMuon() != maSV) {
        cout << "Sinh vien nay khong muon sach nay!" << endl;
        return;
    }
    
    s->setDangMuon(false);
    s->setMaNguoiMuon("");
    sv->xoaSach(maSach);
    
    luuDuLieu();
    cout << "Tra sach thanh cong!" << endl;
}

void QuanLyThuVien::lietKeToanBoSach() {
    if (dsSach.size() == 0) {
        cout << "Chua co sach nao trong thu vien!" << endl;
        return;
    }
    
    cout << "\n_____________DANH SACH TOAN BO SACH____________" << endl;
    for (int i = 0; i < dsSach.size(); i++) {
        cout << "STT " << (i + 1) << ":" << endl;
        dsSach[i]->xuat();
        cout << "______________________________________________" << endl;
    }
}

void QuanLyThuVien::lietKeSachCuaSV() {
    string ma;
    cout << "Nhap ma sinh vien: ";
    cin >> ma;
    
    SinhVien* sv = timSV(ma);
    if (sv == nullptr) {
        cout << "Khong tim thay sinh vien!" << endl;
        return;
    }
    
    vector<string> ds = sv->getDsSach();
    if (ds.size() == 0) {
        cout << "Sinh vien chua muon sach nao!" << endl;
        return;
    }
    
    cout << "\n____________SACH CUA SINH VIEN " << sv->getTen() << "______________" << endl;
    for (int i = 0; i < ds.size(); i++) {
        Sach* s = timSach(ds[i]);
        if (s != nullptr) {
            cout << "STT " << (i + 1) << ":" << endl;
            s->xuat();
            cout << "_______________________________________" << endl;
        }
    }
}

void QuanLyThuVien::lietKeSachDangMuon() {
    bool coSachMuon = false;
    
    cout << "\n___________________DANH SACH SACH DANG DUOC MUON__________________" << endl;
    int stt = 1;
    for (int i = 0; i < dsSach.size(); i++) {
        if (dsSach[i]->isDangMuon() == true) {
            coSachMuon = true;
            cout << "STT " << stt << ":" << endl;
            dsSach[i]->xuat();
            
            SinhVien* sv = timSV(dsSach[i]->getMaNguoiMuon());
            if (sv != nullptr) {
                cout << "Nguoi muon: " << sv->getTen() << " (Ma: " << sv->getMa() << ")" << endl;
            }
            cout << "_______________________________________" << endl;
            stt = stt + 1;
        }
    }
    
    if (coSachMuon == false) {
        cout << "Chua co sach nao duoc muon!" << endl;
    }
}