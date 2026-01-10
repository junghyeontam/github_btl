#ifndef DOITUONG_H
#define DOITUONG_H
#include <string>
using namespace std;
class DoiTuong { // tao lop co so
protected:
    string ma;
    string ten;
public:
    DoiTuong();
    DoiTuong(string ma, string ten);
    virtual ~DoiTuong();
    
    virtual void nhap() = 0; // phuong thuc thuan ao
    virtual void xuat() = 0;
    
    string getMa(); // tinh dong goi
    string getTen();
    void setMa(string m);
    void setTen(string t);
};
#endif