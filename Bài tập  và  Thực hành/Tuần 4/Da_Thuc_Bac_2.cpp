#include <iostream>
#include <math.h>
using namespace std;

typedef class DaThucBac2 {
private:
	double a, b, c;
public:
	~DaThucBac2();
	DaThucBac2(double = 1, double = 0, double =0);
	double GetA()const;
	double GetB()const;
	double GetC()const;
	void SetA(double);
	void SetB(double);
	void SetC(double);
	friend ostream& operator<<(ostream&, const DaThucBac2&);
	friend istream& operator>>(istream&, DaThucBac2&);
	friend DaThucBac2 operator+(const DaThucBac2&, const DaThucBac2&);
	double Tinh_fxo(double);
	void Tim_Nghiem();
}DT2;

DT2::~DaThucBac2() {};
DT2::DaThucBac2(double a, double b, double c) {
	while (a == 0) {
		cout << "Nhap lai a (a!=0): ";
		cin >> a;
	}
	this->a = a;
	this->b = b;
	this->c = c;
}
double DT2::GetA()const { return a; }
double DT2::GetB()const { return b; }
double DT2::GetC()const { return c; }
void DT2::SetA(double) {
	while (a == 0) {
		cout << "Nhap lai a (a!=0): ";
		cin >> a;
	}
	this->a = a;
}
void DT2::SetB(double) {
	this->b = b;
}
void DT2::SetC(double) {
	this->c = c;
}
ostream& operator<<(ostream& os, const DT2& dt) {
	if (dt.a < 0)
		os << "- ";
	if (abs(dt.a) == 1)
		os << "(x^2) ";
	else
		os << abs(dt.a) << "(x^2) ";

	if (dt.b != 0) {
		if (dt.b < 0)
			os << "- ";
		else
			os << "+ ";
		if (abs(dt.b) == 1)
			os << "x ";
		else
			os << abs(dt.b) << "x ";
	}
	if (dt.c != 0) {
		if (dt.c < 0)
			os << "- ";
		else
			os << "+ ";
		os << abs(dt.c);
	}

	os << endl;
	return os;
}
istream& operator>>(istream& is, DT2& dt) {
	do {
		cout << "Nhap a (a!=0): ";
		is >> dt.a;
	} while (dt.a == 0);
	cout << "Nhap b: ";
	is >> dt.b;
	cout << "Nhap c: ";
	is >> dt.c;
	return is;
}
DaThucBac2 operator+(const DT2& dt1, const DT2& dt2) {
	return DaThucBac2(dt1.a + dt2.a, dt1.b + dt2.b, dt1.c + dt2.c);
}
double DT2::Tinh_fxo(double xo) {
	return a * xo * xo + b * xo + c;
}
void DT2::Tim_Nghiem() {
	double delta = b * b - 4 * a * c;
	double x1, x2;
	if (delta < 0)
		cout << "Phuong trinh F(x)=0 vo nghiem\n";
	else if (delta == 0) {
		cout << "Phuong trinh F(x)=0 co nghiem kep.\n";
		x1 = -b / (2 * a);
		cout << "x1 = x2 = " << x1 << endl;
	}
	else {
		cout << "Phuong trinh F(x)=0 co 2 nghiem phan biet.\n";
		x1 = (-b + (double)sqrt(delta)) / (2 * a);
		x2 = (-b - (double)sqrt(delta)) / (2 * a);
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
}

int main() {
	DT2 dt1, dt2, dt;
	int choice;
	double xo;
	do {
		cout << "------------------------CHUONG TRINH XU LY DA THUC BAC 2------------------------\n";
		cout << "                       ----------------------------------                       \n";
		cout << "\t\t\t(1). Nhap da thuc\n";
		cout << "\t\t\t(2). Xuat da thuc\n";
		cout << "\t\t\t(3). Tinh F(xo)\n";
		cout << "\t\t\t(4). Tim nghiem phuong trinh F(x)=0\n";
		cout << "\t\t\t(5). Cong hai da thuc\n";
		cout << "\t\t\t(0). Thoat chuong trinh\n";
		cout << "--------------------------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> choice;
		cout << "-------------\n\n";
		switch (choice) {
		case 1:
			cout << "Nhap da thuc: \n";
			cin >> dt1;
			break;
		case 2:
			cout << "F(x) = "<<dt1;
			break;
		case 3:
			cout << "F(x) = " << dt1;
			cout << "xo = ";
			cin >> xo;
			cout << "\nF(" << xo << ") = " << dt1.Tinh_fxo(xo) << endl;
			break;
		case 4:
			cout << "F(x) = " << dt1;
			dt1.Tim_Nghiem();
			break;
		case 5:
			cout << "Nhap da thuc 2 voi a2 != -a1:\n";
			cin >> dt2;
			cout << "\nF1(x) = " << dt1;
			cout << "F2(x) = " << dt2;
			dt = dt1 + dt2;
			cout << "F(x) = F1(x) + F2(x) = " << dt;
			break;
		case 0:
			cout << "Dang thoat chuong trinh...\n";
		default :
			cout << "Lua chon cua ban khong hop le!!!\n";
		}
		cout << endl;
		system("pause");
		system("cls");
	} while (choice != 0);
	return 0;
}