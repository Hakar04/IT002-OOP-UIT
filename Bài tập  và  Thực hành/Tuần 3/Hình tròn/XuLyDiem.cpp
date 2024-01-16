#include "DIEM.h"
#define epsilon 0.0000000001
DIEM::~DIEM(){}

DIEM::DIEM(double x, double y) : x(x), y(y)
{
}

void DIEM::SetX(double x)
{
    this->x = x;
}

void DIEM::SetY(double y)
{
    this->y = y;
}

void DIEM::SetXY(double x, double y)
{
    SetX(x);
    SetY(y);
}

double DIEM::GetX() const
{
    return x;
}

double DIEM::GetY() const
{
    return y;
}

void DIEM::Nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}

void DIEM::Xuat() const
{
    cout << "(" << x << ", " << y << ")\n";
}

void DIEM::DiChuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool DIEM::KiemTraTrung(const DIEM& d) const
{
    return x == d.x && y == d.y;
}

double DIEM::TinhKhoangCach(const DIEM& d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

DIEM DIEM::TimDiemDoiXung() const
{
    return DIEM(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b;
}

double DIEM::ChuViTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    return KiemTraTamGiacHopLe(d1, d2) ? a + b + c : 0;
}

double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    double p = (a + b + c) / 2;
    return KiemTraTamGiacHopLe(d1, d2) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
    double a = TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = d2.TinhKhoangCach(*this);
    string chuoikq = " ";
    if (!KiemTraTamGiacHopLe(d1, d2))
        chuoikq = "Tam giac khong hop le!!!!";
    else if (a == b && b == c)
        chuoikq = "Tam giac deu.";
    else if (a == b || b == c || c == a)
        if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
            chuoikq = "Tam giac vuong can.";
        else
            chuoikq = "Tam giac can.";
    else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
        chuoikq = "Tam giac vuong.";
    else
        chuoikq = "Tam giac thuong.";
    return chuoikq;
}
istream& operator>>(istream& is, DIEM& d)
{
    d.Nhap();
    return is;
}

ostream& operator<<(ostream& os, const DIEM& d)
{
    d.Xuat();
    return os;
}