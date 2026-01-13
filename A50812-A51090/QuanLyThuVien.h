#ifndef QUANLYTHUVIEN_H
#define QUANLYTHUVIEN_H

#include "Sach.h"
#include "SinhVien.h"
#include <vector>


class QuanLyThuVien {
private:
    vector<Sach*> dsSach;
    vector<SinhVien*> dsSV;
    
    Sach* timSach(string ma);
    SinhVien* timSV(string ma);
    void luuDuLieu();
    void docDuLieu();

public:
    QuanLyThuVien();
    ~QuanLyThuVien();
    
    void themSach();              
    void suaSach();               
    void xoaSach();                
    void themSV();               
    void suaSV();                 
    void xoaSV();                 
    void muonSach();               
    void traSach();                
    void lietKeToanBoSach();       
    void lietKeSachCuaSV();        
    void lietKeSachDangMuon();    
};

#endif