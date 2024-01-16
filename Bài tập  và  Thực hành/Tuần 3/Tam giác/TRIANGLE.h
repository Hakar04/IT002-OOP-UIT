#pragma once
#ifndef _TRIANGLE

#include "POINT.h"

typedef class TRIANGLE
{
private:
	POINT A, B, C;

public:
	~TRIANGLE();
	TRIANGLE();
	TRIANGLE(const POINT&, const POINT&, const POINT&);
	TRIANGLE(double, double, double, double, double, double);
	POINT GetA() const;
	POINT GetB() const;
	POINT GetC() const;
	void SetA(const POINT&);
	void SetB(const POINT&);
	void SetC(const POINT&);
	void SetTG(const POINT&, const POINT&, const POINT&);
	void Input();
	void Output()const;
	bool Check_Valid() const;
	string Classify() const;
	double Calculate_Perimeter() const;//tính chu vi tam giác
	double Calculate_Area() const;//tính diện tích tam giác
	friend istream& operator>>(istream&, TRIANGLE&);
	friend ostream& operator<<(ostream&, const TRIANGLE&);
	void Move();
}TG;



#endif // !_Triangle
