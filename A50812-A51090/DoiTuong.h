#ifndef DOITUONG_H
#define DOITUONG_H
#include <iostream>
#include <fstream>
#include <string>
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
    virtual void hienThiThongTin() = 0;
    virtual void ghiFile(ofstream& file) const = 0;
    virtual void docFile(ifstream& file) = 0;

    string getMa() const;
    string getTen() const;
    void setMa(string& ma);
    void setTen(string& ten);

};
#endif