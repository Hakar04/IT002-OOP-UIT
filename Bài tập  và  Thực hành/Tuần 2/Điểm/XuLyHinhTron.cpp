#include "HinhTron.h"
#define PI atan(1)*4
HinhTron::~HinhTron(){}

HinhTron::HinhTron(double x, double y, double R) : O(x, y)
{
    SetR(R);
}

HinhTron::HinhTron(DIEM O, double R) : O(O)
{
    SetR(R);
}

void HinhTron::SetO(DIEM O)
{
    this->O = O;
}

void HinhTron::SetR(double R)
{
    while (R <= 0)
    {
        cout << "Nhap lai ban kinh R>0: ";
        cin >> R;
    }
    this->R = R;
}

void HinhTron::SetHT(DIEM O, double R)
{
    SetO(O);
    SetR(R);
}

DIEM HinhTron::GetO() const
{
    return O;
}

double HinhTron::GetR() const
{
    return R;
}

void HinhTron::DiChuyen(double x, double y)
{
    O.DiChuyen(x, y);
}

double HinhTron::TinhChuVi() const
{
    return 2 * PI * R;
}

double HinhTron::TinhDienTich() const
{
    return PI * R * R;
}

void HinhTron::Nhap()
{
    cout << "Nhap toa do tam O:\n";
    cin >> O;
    do
    {
        cout << "Nhap ban kinh R>0: ";
        cin >> R;
    } while (R <= 0);
}

void HinhTron::Xuat() const
{
    cout << "Hinh tron tam O=" << O << "Ban kinh R=" << R << endl;
}

istream& operator>>(istream& is, HinhTron& HT)
{
    HT.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const HinhTron& HT)
{
    HT.Xuat();
    return os;
}