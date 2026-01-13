#ifndef TAILIEU_H
#define TAILIEU_H
#include "DoiTuong.h"
#include <fstream>

class TaiLieu : public DoiTuong {
protected:
    string nhaXuatBan;
    int namXuatBan;
    bool dangMuon;
    string maNguoiMuon;

public:
    TaiLieu();
    TaiLieu(string ma, string ten, string nxb, int nam);
    virtual ~TaiLieu();

    string getNhaXuatBan();
    int getNamXuatBan();
    bool isDangMuon();
    string getMaNguoiMuon();
    
    void setNhaXuatBan(string nxb);
    void setNamXuatBan(int nam);
    void setDangMuon(bool dm);
    void setMaNguoiMuon(string ma);
};
#endif