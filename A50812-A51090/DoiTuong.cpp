#include "DoiTuong.h"
DoiTuong::DoiTuong() : ma(" "), ten(" ") {}
DoiTuong::DoiTuong(string ma, string ten) : ma(ma), ten(ten) {}
DoiTuong::~DoiTuong() {}
string DoiTuong::getMa() const {return ma;}
string DoiTuong::getTen() const {return ten;}

void DoiTuong::setMa(string& ma) {this->ma = ma;}
void DoiTuong::setTen(string& ten) {this->ten = ten;}
    