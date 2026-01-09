#include "DoiTuong.h"
DoiTuong::DoiTuong() : ma(""), ten("") {}
DoiTuong::DoiTuong(string ma, string ten) : ma(ma), ten(ten) {}
DoiTuong::~DoiTuong() {}

string DoiTuong::layMa() const { return ma;}

string DoiTuong::layTen() const { return ten;}

void DoiTuong::datMa(string ma) { this->ma = ma;}

void DoiTuong::datTen(string ten) { this->ten = ten;}