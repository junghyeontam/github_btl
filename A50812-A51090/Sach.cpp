#include "Sach.h"
#include <iostream>
using namespace std;

Sach::Sach() : TaiLieu() {
    tacGia = "";
    theLoai = "";
}

Sach::Sach(string ma, string ten, string tg, string nxb, int nam, string tl) 
    : TaiLieu(ma, ten, nxb, nam) {
    tacGia = tg;
    theLoai = tl;
}

void Sach::nhap() {
    cin.ignore();
    cout << "ma sach: "; getline(cin, ma);
    cout << "ten sach: "; getline(cin, ten);
    cout << "tac gia: "; getline(cin, tacGia);
    cout << "the loai: "; getline(cin, theLoai);
    cout << "nha xuat ban: "; getline(cin, nhaXuatBan);
    cout << "nam xuat ban: "; cin >> namXuatBan;
}

void Sach::xuat() {
    cout << ma << " | " << ten << " | " << tacGia << " | " 
         << theLoai << " | " << nhaXuatBan << " (" << namXuatBan << ") | ";
    if (dangMuon == true) {
        cout << "Dang muon";
    } else {
        cout << "Con trong";
    }
    cout << endl;
}

void Sach::ghiFile(ofstream& f) {
    size_t len;
    
    len = ma.size();
    f.write((char*)&len, sizeof(len));
    f.write(ma.c_str(), len);
    
    len = ten.size();
    f.write((char*)&len, sizeof(len));
    f.write(ten.c_str(), len);
    
    len = tacGia.size();
    f.write((char*)&len, sizeof(len));
    f.write(tacGia.c_str(), len);
    
    len = theLoai.size();
    f.write((char*)&len, sizeof(len));
    f.write(theLoai.c_str(), len);
    
    len = nhaXuatBan.size();
    f.write((char*)&len, sizeof(len));
    f.write(nhaXuatBan.c_str(), len);
    
    f.write((char*)&namXuatBan, sizeof(int));
    f.write((char*)&dangMuon, sizeof(bool));
    
    len = maNguoiMuon.size();
    f.write((char*)&len, sizeof(len));
    f.write(maNguoiMuon.c_str(), len);
}

void Sach::docFile(ifstream& f) {
    size_t len;
    
    f.read((char*)&len, sizeof(len));
    ma.resize(len);
    f.read(&ma[0], len);
    
    f.read((char*)&len, sizeof(len));
    ten.resize(len);
    f.read(&ten[0], len);
    
    f.read((char*)&len, sizeof(len));
    tacGia.resize(len);
    f.read(&tacGia[0], len);
    
    f.read((char*)&len, sizeof(len));
    theLoai.resize(len);
    f.read(&theLoai[0], len);
    
    f.read((char*)&len, sizeof(len));
    nhaXuatBan.resize(len);
    f.read(&nhaXuatBan[0], len);
    
    f.read((char*)&namXuatBan, sizeof(int));
    f.read((char*)&dangMuon, sizeof(bool));
    
    f.read((char*)&len, sizeof(len));
    maNguoiMuon.resize(len);
    f.read(&maNguoiMuon[0], len);
}

string Sach::getTacGia() {
    return tacGia;
}

string Sach::getTheLoai() {
    return theLoai;
}

void Sach::setTacGia(string tg) {
    tacGia = tg;
}

void Sach::setTheLoai(string tl) {
    theLoai = tl;
}