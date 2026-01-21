#include "SinhVien.h"
#include <iostream>
using namespace std;

SinhVien::SinhVien() : DoiTuong() {
    lop = "";
    khoa = "";
}

SinhVien::SinhVien(string ma, string ten, string lop, string khoa) : DoiTuong(ma, ten) {
    this->lop = lop;
    this->khoa = khoa;
}

void SinhVien::nhap() {
    cin.ignore();
    cout << "Ma sinh vien: "; getline(cin, ma);
    cout << "Ten sinh vien: "; getline(cin, ten);
    cout << "Lop: "; getline(cin, lop);
    cout << "Khoa: "; getline(cin, khoa);
}

void SinhVien::xuat() {
    cout << "  Ma sinh vien : " << ma << endl;
    cout << "  Ten sinh vien: " << ten << endl;
    cout << "  Lop          : " << lop << endl;
    cout << "  Khoa         : " << khoa << endl;
    cout << "  So sach muon : " << dsSachMuon.size() << endl;
}

void SinhVien::ghiFile(ofstream& f) {
    size_t len;
    
    len = ma.size();
    f.write((char*)&len, sizeof(len));
    f.write(ma.c_str(), len);
    
    len = ten.size();
    f.write((char*)&len, sizeof(len));
    f.write(ten.c_str(), len);
    
    len = lop.size();
    f.write((char*)&len, sizeof(len));
    f.write(lop.c_str(), len);
    
    len = khoa.size();
    f.write((char*)&len, sizeof(len));
    f.write(khoa.c_str(), len);
    
    len = dsSachMuon.size();
    f.write((char*)&len, sizeof(len));
    for (int i = 0; i < dsSachMuon.size(); i++) {
        size_t l = dsSachMuon[i].size();
        f.write((char*)&l, sizeof(l));
        f.write(dsSachMuon[i].c_str(), l);
    }
}

void SinhVien::docFile(ifstream& f) {
    size_t len;
    
    f.read((char*)&len, sizeof(len));
    ma.resize(len);
    f.read(&ma[0], len);
    
    f.read((char*)&len, sizeof(len));
    ten.resize(len);
    f.read(&ten[0], len);
    
    f.read((char*)&len, sizeof(len));
    lop.resize(len);
    f.read(&lop[0], len);
    
    f.read((char*)&len, sizeof(len));
    khoa.resize(len);
    f.read(&khoa[0], len);
    
    f.read((char*)&len, sizeof(len));
    dsSachMuon.clear();
    for (size_t i = 0; i < len; i++) {
        string s;
        size_t l;
        f.read((char*)&l, sizeof(l));
        s.resize(l);
        f.read(&s[0], l);
        dsSachMuon.push_back(s);
    }
}

void SinhVien::themSach(string ma) {
    dsSachMuon.push_back(ma);
}

void SinhVien::xoaSach(string ma) {
    for (int i = 0; i < dsSachMuon.size(); i++) {
        if (dsSachMuon[i] == ma) {
            dsSachMuon.erase(dsSachMuon.begin() + i);
            break;
    }}
}

bool SinhVien::dangMuonSach() {
    if (dsSachMuon.size() > 0) {
        return true;
    }
    return false;
}

vector<string> SinhVien::getDsSach() {
    return dsSachMuon; }

string SinhVien::getLop() {
    return lop; }

string SinhVien::getKhoa() {
    return khoa; }

void SinhVien::setLop(string l) {
    lop = l; }

void SinhVien::setKhoa(string k) {
    khoa = k; }