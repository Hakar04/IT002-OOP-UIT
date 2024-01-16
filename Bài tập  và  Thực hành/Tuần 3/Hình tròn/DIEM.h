#pragma once
#ifndef _DIEM
#include <iostream>
#include <math.h>
using namespace std;

class DIEM
{
private:
    double x, y;
public:
    ~DIEM();
    DIEM(double = 0, double = 0);
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    double GetX() const;
    double GetY() const;
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    double TinhKhoangCach(const DIEM&) const;
    bool KiemTraTrung(const DIEM&) const;
    DIEM TimDiemDoiXung() const;
    bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
    double ChuViTamGiac(const DIEM&, const DIEM&) const;
    double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
    string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
    friend ostream& operator<<(ostream&, const DIEM&);
    friend istream& operator>>(istream&, DIEM&);
};
#endif