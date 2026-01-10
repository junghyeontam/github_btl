#ifndef DOITUONG_H
#define DOITUONG_H

#include <string>
#include <fstream>
using namespace std;
class DoiTuong {
protected:
    string ma;
    string ten;

public:
    DoiTuong();
    DoiTuong(string ma, string ten);
    virtual ~DoiTuong();
    
    virtual void nhap() = 0;
    virtual void xuat() const = 0;
    
    string getMa() const { return ma; }
    string getTen() const { return ten; }
    void setMa(string m) { ma = m; }
    void setTen(string t) { ten = t; }
};

#endif