#pragma once
#include <iostream>
#include <math.h>
using namespace std;

#ifndef _PS
typedef class PHANSO
{
private:
	int ts, ms;
public:
	~PHANSO();
	//PHANSO(int = 0, int = 1);
	PHANSO();
	PHANSO(int);
	PHANSO(int, int);
	PHANSO(const PHANSO&);

	int GetTS()const;
	int GetMS()const;
	void SetTS(int);
	void SetMS(int);
	void SetTM(int, int);

	void Nhap();
	void Xuat() const;

	int TimUscln( int, int) const;
	void RutGon( );

	friend PHANSO operator+(const PHANSO&, const PHANSO&);
	friend PHANSO operator-(const PHANSO&, const PHANSO&);
	friend PHANSO operator*(const PHANSO&, const PHANSO&);
	friend PHANSO operator/(const PHANSO&, const PHANSO&);

	friend ostream& operator<<(ostream&, const PHANSO&);
	friend istream& operator>>(istream&, PHANSO&);

	operator double()const;

	friend bool operator!=(const PHANSO&, const PHANSO&);
	friend bool operator<=(const PHANSO&, const PHANSO&);
	friend bool operator<(const PHANSO&, const PHANSO&);
	friend bool operator==(const PHANSO&, const PHANSO&);
	friend bool operator>=(const PHANSO&, const PHANSO&);
	friend bool operator>(const PHANSO&, const PHANSO&);

	PHANSO operator++();//++ps
	PHANSO operator++(int);//ps++
	PHANSO operator--();//--ps
	PHANSO operator--(int);//ps--
}PS;
#endif
