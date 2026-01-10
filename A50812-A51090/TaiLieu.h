#ifndef TAILIEU_H
#define TAILIEU_H

#include "DoiTuong.h"

// Lớp trung gian - TÍNH KẾ THỪA
class TaiLieu : public DoiTuong {
protected:
    string nhaXuatBan;
    int namXuatBan;
    bool dangMuon;
    string maNguoiMuon;

public:
    TaiLieu();
    virtual ~TaiLieu();
    
    bool isDangMuon() const { return dangMuon; }
    string getMaNguoiMuon() const { return maNguoiMuon; }
    
    void setDangMuon(bool dm) { dangMuon = dm; }
    void setMaNguoiMuon(string m) { maNguoiMuon = m; }
};

#endif