#include "DoiTuong.h"

DoiTuong::DoiTuong() {
    ma = "";
    ten = ""; }

DoiTuong::DoiTuong(string ma, string ten) {
    this->ma = ma;
    this->ten = ten; }

DoiTuong::~DoiTuong() {}

string DoiTuong::getMa() { return ma; }

string DoiTuong::getTen() { return ten; }

void DoiTuong::setMa(string m) { ma = m; }

void DoiTuong::setTen(string t) { ten = t; }