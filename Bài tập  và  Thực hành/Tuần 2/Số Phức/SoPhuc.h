#pragma once
#include "PhanSo.h"

#ifndef _ComplexNumber

typedef class SoPhuc
{
private:
	PS t, a; //t-> that; a->ao

public: 
	~SoPhuc();
	SoPhuc();
	SoPhuc(PS);
	SoPhuc(PS , PS );
	SoPhuc(int , int , int , int );
	SoPhuc(const SoPhuc&);

	PS GetT() const;
	PS GetA() const;
	void SetT(PS);
	void SetA(PS);
	void SetSP(PS, PS);

	void Nhap();
	//void Xuat();

	friend SoPhuc operator+(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator-(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator*(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator/(const SoPhuc&, const SoPhuc&);

	friend ostream& operator<<(ostream&, const SoPhuc&);
	friend istream& operator>>(istream&, SoPhuc&);

	//operator double()const;

	friend bool operator!=(const SoPhuc&, const SoPhuc&);
	friend bool operator<=(const SoPhuc&, const SoPhuc&);
	friend bool operator<(const SoPhuc&, const SoPhuc&);
	friend bool operator==(const SoPhuc&, const SoPhuc&);
	friend bool operator>=(const SoPhuc&, const SoPhuc&);
	friend bool operator>(const SoPhuc&, const SoPhuc&);

	SoPhuc operator++();
	SoPhuc operator++(int);
	SoPhuc operator--();
	SoPhuc operator--(int);

	/*void Cong2SoPhuc(const SoPhuc&) const;
	void Tru2SoPhuc(const SoPhuc&) const;
	void Nhan2SoPhuc(const SoPhuc& ) const;
	void Chia2SoPhuc(const SoPhuc&) const;*/

	/*double TinhModun() const;
	void TimSoPhucLienHop() const;*/

}SP;

#endif