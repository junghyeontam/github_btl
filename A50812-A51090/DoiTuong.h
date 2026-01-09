#ifndef DOITUONG_H
#define DOITUONG_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class DoiTuong {
protected:
    string ma;
    string ten;

public:
    DoiTuong();
    DoiTuong(string ma, string ten);
    virtual ~DoiTuong();
    
    virtual void nhapThongTin() = 0;
    virtual void hienThiThongTin() const = 0;
    virtual void ghiFile(ofstream& file) const = 0;
    virtual void docFile(ifstream& file) = 0;
    
    string layMa() const;
    string layTen() const;
    void datMa(string ma);
    void datTen(string ten);
};

#endif