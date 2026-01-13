#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "DoiTuong.h"
#include <vector>
#include <fstream>

// TÍNH KẾ THỪA
class SinhVien : public DoiTuong {
private:
    string lop;
    string khoa;
    vector<string> dsSachMuon;

public:
    SinhVien();
    SinhVien(string ma, string ten, string lop, string khoa);
    
    // TÍNH ĐA HÌNH - Override
    void nhap();
    void xuat();
    
    void ghiFile(ofstream& f);
    void docFile(ifstream& f);
    
    void themSach(string ma);
    void xoaSach(string ma);
    bool dangMuonSach();
    vector<string> getDsSach();
    
    string getLop();
    string getKhoa();
    void setLop(string l);
    void setKhoa(string k);
};

#endif