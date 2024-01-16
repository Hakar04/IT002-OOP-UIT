#include "POINT.h"
#define epsilon 0.0000000001
POINT::~POINT() {}

POINT::POINT(double x, double y) : x(x), y(y)
{
}

void POINT::SetX(double x)
{
    this->x = x;
}

void POINT::SetY(double y)
{
    this->y = y;
}

void POINT::SetXY(double x, double y)
{
    SetX(x);
    SetY(y);
}

double POINT::GetX() const
{
    return x;
}

double POINT::GetY() const
{
    return y;
}

void POINT::Input()
{
    cout << "Enter Abscissa (Nhap hoanh do) : ";
    cin >> x;
    cout << "Enter ordinate (Nhap tung do) : ";
    cin >> y;
}

void POINT::Output() const
{
    cout << "(" << x << "; " << y << ")";
}

void POINT::Move_POINT(double dx, double dy)
{
    x += dx;
    y += dy;
}

bool POINT::Check_Duplicate(const POINT& d) const
{
    return x == d.x && y == d.y;
}

double POINT::Find_Distance(const POINT& d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

POINT POINT::Find_POINT_Symmetry() const
{
    return POINT(x == 0 ? 0 : -x, y == 0 ? 0 : -y);
}

bool POINT::Check_TRIANGLE_Valid(const POINT& d1, const POINT& d2) const
{
    double a = Find_Distance(d1);
    double b = d1.Find_Distance(d2);
    double c = d2.Find_Distance(*this);
    return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b;
}

double POINT::Calculate_Perimeter_TRIANGLE(const POINT& d1, const POINT& d2) const
{
    double a = Find_Distance(d1);
    double b = d1.Find_Distance(d2);
    double c = d2.Find_Distance(*this);
    return Check_TRIANGLE_Valid(d1, d2) ? a + b + c : 0;
}

double POINT::Calculate_Area_TRIANGLE(const POINT& d1, const POINT& d2) const
{
    double a = Find_Distance(d1);
    double b = d1.Find_Distance(d2);
    double c = d2.Find_Distance(*this);
    double p = (a + b + c) / 2;
    return Check_TRIANGLE_Valid(d1, d2) ? sqrt(p * (p - a) * (p - b) * (p - c)) : 0;
}

string POINT::Classify_TRIANGLE(const POINT& d1, const POINT& d2) const
{
    double a = Find_Distance(d1);
    double b = d1.Find_Distance(d2);
    double c = d2.Find_Distance(*this);
    string chuoikq = " ";
    if (!Check_TRIANGLE_Valid(d1, d2))
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
istream& operator>>(istream& is, POINT& d)
{
    d.Input();
    return is;
}

ostream& operator<<(ostream& os, const POINT& d)
{
    d.Output();
    return os;
}