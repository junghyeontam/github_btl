#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "DoiTuong.h"
#include <vector>

// TÍNH KẾ THỪA
class SinhVien : public DoiTuong {
private:
    string lop;
    string khoa;
    vector<string> dsSachMuon;

public:
    SinhVien();
    
    // TÍNH ĐA HÌNH - Override
    void nhap() override;
    void xuat() const override;
    
    // Đọc/ghi file
    void ghiFile(ofstream& f) const;
    void docFile(ifstream& f);
    
    // Quản lý mượn sách
    void themSach(string maSach) { dsSachMuon.push_back(maSach); }
    void xoaSach(string maSach);
    bool dangMuonSach() const { return !dsSachMuon.empty(); }
    vector<string> getDsSach() const { return dsSachMuon; }
    
    // Setter
    void setLop(string l) { lop = l; }
    void setKhoa(string k) { khoa = k; }
};

#endif