#ifndef SACH_H
#define SACH_H

#include "TaiLieu.h"

class Sach : public TaiLieu {
private:
    string tacGia;
    string theLoai;

public:
    Sach();

    void nhap() override;
    void xuat() const override;
    
    void ghiFile(ofstream& f) const;
    void docFile(ifstream& f);
    
    void setTacGia(string tg) { tacGia = tg; }
    void setTheLoai(string tl) { theLoai = tl; }
    void setNXB(string nxb) { nhaXuatBan = nxb; }
    void setNam(int n) { namXuatBan = n; }
};

#endif