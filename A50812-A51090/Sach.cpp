#include "Sach.h"
#include <iostream>
using namespace std;

Sach::Sach() : TaiLieu(), tacGia(""), theLoai("") {}

void Sach::nhap() {
    cin.ignore();
    cout << "Ma sach: "; getline(cin, ma);
    cout << "Ten sach: "; getline(cin, ten);
    cout << "Tac gia: "; getline(cin, tacGia);
    cout << "The loai: "; getline(cin, theLoai);
    cout << "NXB: "; getline(cin, nhaXuatBan);
    cout << "Nam XB: "; cin >> namXuatBan;
}

void Sach::xuat() const {
    cout << "Ma: " << ma << " | Ten: " << ten << endl;
    cout << "Tac gia: " << tacGia << " | The loai: " << theLoai << endl;
    cout << "NXB: " << nhaXuatBan << " (" << namXuatBan << ")" << endl;
    cout << "Trang thai: " << (dangMuon ? "Dang muon" : "Con trong") << endl;
}

void Sach::ghiFile(ofstream& f) const {
    size_t len;
    len = ma.size(); f.write((char*)&len, sizeof(len)); f.write(ma.c_str(), len);
    len = ten.size(); f.write((char*)&len, sizeof(len)); f.write(ten.c_str(), len);
    len = tacGia.size(); f.write((char*)&len, sizeof(len)); f.write(tacGia.c_str(), len);
    len = theLoai.size(); f.write((char*)&len, sizeof(len)); f.write(theLoai.c_str(), len);
    len = nhaXuatBan.size(); f.write((char*)&len, sizeof(len)); f.write(nhaXuatBan.c_str(), len);
    f.write((char*)&namXuatBan, sizeof(namXuatBan));
    f.write((char*)&dangMuon, sizeof(dangMuon));
    len = maNguoiMuon.size(); f.write((char*)&len, sizeof(len)); f.write(maNguoiMuon.c_str(), len);
}

void Sach::docFile(ifstream& f) {
    size_t len;
    f.read((char*)&len, sizeof(len)); ma.resize(len); f.read(&ma[0], len);
    f.read((char*)&len, sizeof(len)); ten.resize(len); f.read(&ten[0], len);
    f.read((char*)&len, sizeof(len)); tacGia.resize(len); f.read(&tacGia[0], len);
    f.read((char*)&len, sizeof(len)); theLoai.resize(len); f.read(&theLoai[0], len);
    f.read((char*)&len, sizeof(len)); nhaXuatBan.resize(len); f.read(&nhaXuatBan[0], len);
    f.read((char*)&namXuatBan, sizeof(namXuatBan));
    f.read((char*)&dangMuon, sizeof(dangMuon));
    f.read((char*)&len, sizeof(len)); maNguoiMuon.resize(len); f.read(&maNguoiMuon[0], len);
}