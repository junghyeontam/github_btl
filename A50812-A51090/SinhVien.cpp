#include "SinhVien.h"
#include <iostream>
#include <algorithm>
using namespace std;

SinhVien::SinhVien() : DoiTuong(), lop(""), khoa("") {}

void SinhVien::nhap() {
    cin.ignore();
    cout << "Ma SV: "; getline(cin, ma);
    cout << "Ten SV: "; getline(cin, ten);
    cout << "Lop: "; getline(cin, lop);
    cout << "Khoa: "; getline(cin, khoa);
}

void SinhVien::xuat() const {
    cout << "Ma: " << ma << " | Ten: " << ten << endl;
    cout << "Lop: " << lop << " | Khoa: " << khoa << endl;
    cout << "So sach muon: " << dsSachMuon.size() << endl;
}

void SinhVien::xoaSach(string maSach) {
    auto it = find(dsSachMuon.begin(), dsSachMuon.end(), maSach);
    if (it != dsSachMuon.end()) {
        dsSachMuon.erase(it);
    }
}

void SinhVien::ghiFile(ofstream& f) const {
    size_t len;
    len = ma.size(); f.write((char*)&len, sizeof(len)); f.write(ma.c_str(), len);
    len = ten.size(); f.write((char*)&len, sizeof(len)); f.write(ten.c_str(), len);
    len = lop.size(); f.write((char*)&len, sizeof(len)); f.write(lop.c_str(), len);
    len = khoa.size(); f.write((char*)&len, sizeof(len)); f.write(khoa.c_str(), len);
    
    size_t n = dsSachMuon.size();
    f.write((char*)&n, sizeof(n));
    for (const string& s : dsSachMuon) {
        len = s.size(); f.write((char*)&len, sizeof(len)); f.write(s.c_str(), len);
    }
}

void SinhVien::docFile(ifstream& f) {
    size_t len;
    f.read((char*)&len, sizeof(len)); ma.resize(len); f.read(&ma[0], len);
    f.read((char*)&len, sizeof(len)); ten.resize(len); f.read(&ten[0], len);
    f.read((char*)&len, sizeof(len)); lop.resize(len); f.read(&lop[0], len);
    f.read((char*)&len, sizeof(len)); khoa.resize(len); f.read(&khoa[0], len);
    
    size_t n;
    f.read((char*)&n, sizeof(n));
    dsSachMuon.clear();
    for (size_t i = 0; i < n; i++) {
        string s;
        f.read((char*)&len, sizeof(len)); s.resize(len); f.read(&s[0], len);
        dsSachMuon.push_back(s);
    }
}