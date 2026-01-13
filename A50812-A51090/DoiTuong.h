#ifndef DOITUONG_H
#define DOITUONG_H

#include <string>
using namespace std;


class DoiTuong { // lop co so(truu tuong)
protected:
    string ma;
    string ten;

public:
    DoiTuong();
    DoiTuong(string ma, string ten);
    virtual ~DoiTuong();
    
    virtual void nhap() = 0; // ham thuan ao 
    virtual void xuat() = 0;
    
    
    string getMa(); // tinh dong goi
    string getTen();
    void setMa(string m);
    void setTen(string t);
};

#endif