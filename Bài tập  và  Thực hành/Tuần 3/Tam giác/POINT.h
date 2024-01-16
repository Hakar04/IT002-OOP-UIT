
#pragma once
#ifndef _TRIANGLE

#include <iostream>
#include <math.h>
using namespace std;

class POINT
{
private:
    double x, y;
public:
    ~POINT();
    POINT(double = 0, double = 0);
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    double GetX() const;
    double GetY() const;
    void Input();//nhập
    void Output() const;//xuất
    void Move_POINT(double, double);
    double Find_Distance(const POINT&) const;//Calculate khoang cach
    bool Check_Duplicate(const POINT&) const;//Checktrung
    POINT Find_POINT_Symmetry() const;//tim diem doi xung
    bool Check_TRIANGLE_Valid(const POINT&, const POINT&) const;//kiểm tra tam giác hợp lệ
    double Calculate_Perimeter_TRIANGLE(const POINT&, const POINT&) const;//tính chu vi tam giác
    double Calculate_Area_TRIANGLE(const POINT&, const POINT&) const;//tính diện tích tam giác
    string Classify_TRIANGLE(const POINT&, const POINT&) const;//phân loại tam giác
    friend ostream& operator<<(ostream&, const POINT&);
    friend istream& operator>>(istream&, POINT&);
};
#endif