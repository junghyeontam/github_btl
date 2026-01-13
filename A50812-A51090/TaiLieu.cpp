#include "TaiLieu.h"

TaiLieu::TaiLieu() : DoiTuong() {
    nhaXuatBan = "";
    namXuatBan = 0;
    dangMuon = false;
    maNguoiMuon = "";
}

TaiLieu::TaiLieu(string ma, string ten, string nxb, int nam) : DoiTuong(ma, ten) {
    nhaXuatBan = nxb;
    namXuatBan = nam;
    dangMuon = false;
    maNguoiMuon = "";
}

TaiLieu::~TaiLieu() {}

string TaiLieu::getNhaXuatBan() {
    return nhaXuatBan;
}

int TaiLieu::getNamXuatBan() {return namXuatBan;}

bool TaiLieu::isDangMuon() {return dangMuon;}

string TaiLieu::getMaNguoiMuon() {return maNguoiMuon;}

void TaiLieu::setNhaXuatBan(string nxb) {nhaXuatBan = nxb;}

void TaiLieu::setNamXuatBan(int nam) {namXuatBan = nam;}

void TaiLieu::setDangMuon(bool dm) { dangMuon = dm;}

void TaiLieu::setMaNguoiMuon(string ma) {maNguoiMuon = ma;}