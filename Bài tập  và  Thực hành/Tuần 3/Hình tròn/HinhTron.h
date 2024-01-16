#ifndef _HinhTron
#define _HinhTron
#include "DIEM.h"

using namespace std;
class HinhTron
{
private:
    DIEM O;
    double R;
public:
    ~HinhTron();
    HinhTron(double = 0, double = 0, double = 1);
    HinhTron(DIEM, double = 1);
    void SetO(DIEM);
    void SetR(double);
    void SetHT(DIEM, double);
    DIEM GetO() const;
    double GetR() const;
    void DiChuyen(double, double);
    double TinhChuVi() const;
    double TinhDienTich() const;
    void Nhap();
    void Xuat() const;
    friend istream& operator>>(istream&, HinhTron&);
    friend ostream& operator<<(ostream&, const HinhTron&);
};
#endif
