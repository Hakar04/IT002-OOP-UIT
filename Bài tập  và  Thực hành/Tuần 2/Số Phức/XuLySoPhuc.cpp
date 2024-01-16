#include "SoPhuc.h"

SP::~SoPhuc()
{
	this->t = 0;
	this->a = 0;
}

SP::SoPhuc() : t(0), a(0){}
SP::SoPhuc(PS t):t(t), a(0){}
SP::SoPhuc(PS t, PS a): t(t), a(a){}
SP::SoPhuc(int x1, int y1, int x2, int y2):t(x1, y1), a(x2, y2){}
SP::SoPhuc(const SP& z): t(z.t), a(z.a) {}

PS SP::GetA() const
{
	return a;
}

PS SP::GetT() const
{
	return t;
}

void SP::SetT(PS t)
{
	this->t = t;
}
void SP::SetA(PS a)
{
	this->a = a;
}
void SP::SetSP(PS t, PS a)
{
	this->t = t;
	this->a = a;
}

void SP::Nhap()
{
	cout << "Nhap Phan that: \n";
	cin >> t;
	cout << endl;
	cout << "Nhap Phan ao: \n";
	cin >> a;
}

//void SP::Xuat()
//{
//	PS temp(0, 1);
//	if (t == temp)
//		cout << "(" << a << ")i\n";
//	else if (a == temp)
//		cout << t << endl;
//	else if (a == temp && t== temp)
//		cout << 0 << endl;
//	else
//		cout <<"("<< t << ") + (" << a << ")i\n";
//}
SoPhuc operator+(const SoPhuc& z1, const SoPhuc& z2) {
	return SoPhuc(z1.t + z2.t, z1.a + z2.a);
 }
SoPhuc operator-(const SoPhuc& z1, const SoPhuc& z2) {
	return SoPhuc(z1.t - z2.t, z1.a - z2.a);
 }
SoPhuc operator*(const SoPhuc& z1, const SoPhuc& z2) {
	return SoPhuc(z1.t * z2.t - z1.a * z2.a, z1.t * z2.a + z1.a + z2.t);
 }
SoPhuc operator/(const SoPhuc& z1, const SoPhuc& z2) {
	return SoPhuc((z1.t * z2.t + z1.a * z2.a) / (z2.a * z2.a + z2.t * z2.t), (z1.a * z2.t - z1.t * z2.a) / (z2.a * z2.a + z2.t * z2.t));
 }

ostream& operator<<(ostream& os, const SoPhuc& z) {
	PS temp(0, 1);
	if (z.t == temp) {
		if (z.a == temp)
			cout << 0 << endl;
		else
			cout << "(" << z.a << ")i\n";
	}
	else if (z.a == temp)
		cout << z.t << endl;
	else
		cout << "(" << z.t << ") + (" << z.a << ")i\n";
	return os;
 }
istream& operator>>(istream& is, SoPhuc& z) {
	z.Nhap();
	return is;
 }


bool operator!=(const SoPhuc& z1, const SoPhuc& z2) {
	return (z1.t != z2.t) || (z2.a != z1.a);
 }
bool operator<=(const SoPhuc& z1, const SoPhuc& z2) {
	if (z1.t < z2.t)
		return true;
	else
		if (z1.t == z2.t)
			if (z1.a <= z2.a)
				return true; 
		return false;
}
bool operator<(const SoPhuc& z1, const SoPhuc& z2) {
	if (z1.t < z2.t)
		return true;
	else
		if (z1.t == z2.t)
			if (z1.a < z2.a)
				return true;
	return false;
}
 bool operator==(const SoPhuc& z1, const SoPhuc& z2) {
	 return (z1.t == z2.t) && (z2.a == z1.a);
 }
 bool operator>=(const SoPhuc& z1, const SoPhuc& z2) {
	 if (z1.t > z2.t)
		 return true;
	 else
		 if (z1.t == z2.t)
			 if (z1.a >= z2.a)
				 return true;
	 return false;
 }
 bool operator>(const SoPhuc& z1, const SoPhuc& z2) {
	 if (z1.t > z2.t)
		 return true;
	 else
		 if (z1.t == z2.t)
			 if (z1.a > z2.a)
				 return true;
	 return false;
 }

 SoPhuc SP::operator++() {
	 t++;
	 return *this;
}
 SoPhuc SP::operator++(int) {
	 SP zz(t, a);
	 t++;
	 return zz;
}
 SoPhuc SP::operator--() {
	 t--;
	 return *this;
}
 SoPhuc SP::operator--(int) {
	 SP zz(t, a);
	 t--;
	 return zz;
}


//double SP::TinhModun() const
//{
//	return sqrt(t * t + a * a);
//}
//
//void SP::TimSoPhucLienHop() const
//{
//	SP sp_lh;
//	sp_lh.t = t;
//	sp_lh.a = -a;
//
//	sp_lh.Xuat();
//}