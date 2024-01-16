#include <iostream>
#include <math.h>
using namespace std;

typedef class POLYNOMIAL {
private:
	double* arr;
	int n;
public:
	~POLYNOMIAL();
	POLYNOMIAL(int = 0, int = 0);
	int GetN()const;
	double* GetArr()const;
	void SetN(int);
	//void* SetArr(int);
	POLYNOMIAL(const POLYNOMIAL&);
	POLYNOMIAL& operator= (const POLYNOMIAL&);
	friend ostream& operator<<(ostream&, const POLYNOMIAL&);
	friend istream& operator>>(istream&, POLYNOMIAL&);
	friend POLYNOMIAL operator+(const POLYNOMIAL&, const POLYNOMIAL&);
	friend POLYNOMIAL operator-(const POLYNOMIAL&, const POLYNOMIAL&);
	friend POLYNOMIAL operator*(const POLYNOMIAL&, const POLYNOMIAL&);
	friend bool operator==(const POLYNOMIAL&, const POLYNOMIAL&);
}Pol;

Pol::~POLYNOMIAL() {
	n = 0;
	delete[]arr;
	arr = NULL;
}
Pol::POLYNOMIAL(int n, int m) {
	if (n == 0) {
		this->n = 0;
		arr = NULL;
	}
	else {
		while (n <= 0)
		{
			cout << "Nhap lai n (n>0): ";
			cin >> n;
		}
		this->n = n;
		arr = new double[n + 1];
		for (int i = n; i >= 0; i--)
			*(arr + i) = m;
	}
}
int Pol::GetN() const { return n; }
double* Pol::GetArr() const { return arr; }
void Pol::SetN(int) {
	if (n == 0) {
		this->n = 0;
	}
	else {
		while (n <= 0) {
			cout << "Nhap lai n (n>0): ";
			cin >> n;
		}
		this->n = n;
	}
}
//void* Pol::SetArr(int m) {
//	if (n == 0) arr = NULL;
//	else {
//		arr = new double[n+1];
//		for (int i = n; i >=0; i--)
//			*(arr + i) = m;
//	}
//}

Pol& Pol::operator=(const Pol& m) {
	n = m.n;
	arr = new double[n + 1];
	for (int i = n; i >= 0; i--)
		arr[i] = *(m.arr + i);
	return *this;
}
Pol::POLYNOMIAL(const Pol& m) {
	this->n = m.n;
	delete[] this->arr;
	this->arr = new double[n + 1];
	for (int i = this->n; i >= 0; i--)
		this->arr[i] = m.arr[i];
}

ostream& operator<<(ostream& os, const Pol& m) {
	int x = -1;
	int dem = 0;
	for (int a = m.n; a >= 0; a--)
		if (*(m.arr + a) != 0) {
			if (*(m.arr + a) > 0)
				x = a;
			break;
		}
	for (int b = m.n; b >= 0; b--) {
		if (*(m.arr + b) == 0)
			dem++;
	}
	if (dem == m.n + 1)
		os << 0;
	else {
		for (int i = m.n; i >= 0; i--) {
			if (*(m.arr + i) != 0) {
				if (*(m.arr + i) < 0) {
					os << " - ";
					if (*(m.arr + i) != -1)
						os << abs(*(m.arr + i));
				}
				else {
					if (i != x)
						os << " + ";
					if (*(m.arr + i) != 1)
						os << *(m.arr + i);
				}
				if (i == 1)
					os << "X";
				else if (i == 0) {
					if (*(m.arr + i) == -1 || *(m.arr + i) == 1)
						os << 1;
					else
						os << "";
				}
				else
					os << "(X^" << i << ")";
			}
		}
		
	}
	return os;
}
istream& operator>>(istream& is, Pol& m) {
	delete[]m.arr;
	do {
		cout << "Nhap Bac cua da thuc (>=0): ";
		is >> m.n;
		cout << endl;
	} while (m.n < 0);
	cout << "Nhap cac he so cua da thuc: \n";
	m.arr = new double[m.n + 1];
	for (int i = m.n; i >= 0; i--) {
		cout << "X^" << i << ": ";
		is >> *(m.arr + i);
	}
	return is;
}

POLYNOMIAL operator+(const POLYNOMIAL& f1, const POLYNOMIAL& f2) {
	Pol f((f1.n > f2.n) ? f1.n : f2.n);
	for (int i = f.n; i >= 0; i--)
		*(f.arr + i) = *(f1.arr + i) + *(f2.arr + i);
	return f;
}
POLYNOMIAL operator-(const POLYNOMIAL& f1, const POLYNOMIAL& f2) {
	Pol f((f1.n > f2.n) ? f1.n : f2.n);
	for (int i = f.n; i >= 0; i--)
		*(f.arr + i) = *(f1.arr + i) - *(f2.arr + i);
	return f;
}
POLYNOMIAL operator*(const POLYNOMIAL& f1, const POLYNOMIAL& f2) {
	Pol f(f1.n + f2.n);
	for (int i = f.n; i >= 0; i--)
		*(f.arr + i) = 0;
	for (int j = f1.n; j >= 0; j--)
		for (int k = f2.n; k >= 0; k--)
			*(f.arr + j + k) += (*(f1.arr + j) * *(f2.arr + k));
	return f;
}
//bool operator==(const Pol& f1, const Pol& f2) {
//	for (int i = 0; i <= ((f1.n < f2.n) ? f2.n : f1.n); i++)
//		if (*(f1.arr + i) != *(f2.arr + i))
//			return false;
//		return true;
//}

int main()
{
	Pol f1, f2, f;
	int chon = 0;
	do {
		cout << "------------------------CHUONG TRINH XU LY DA THUC------------------------\n";
		cout << "                       ----------------------------                       \n";
		cout << "\t\t\t(1). Nhap da thuc\n";
		cout << "\t\t\t(2). Xuat da thuc\n";
		cout << "\t\t\t(3). Cong hai da thuc\n";
		cout << "\t\t\t(4). Tru hai da thuc\n";
		cout << "\t\t\t(5). Nhan hai da thuc\n";
		cout << "\t\t\t(0). Thoat chuong trinh\n";
		cout << "--------------------------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
		cout << "-------------\n\n";
		switch (chon) {
		case 0:
			cout << "Dang thoat chuong trinh...\n\n";
			break;
		case 1:
			cout << "Nhap da thuc thu I: \n";
			cin >> f1;
			cout << endl;
			cout << "Nhap da thuc thu II: \n";
			cin >> f2;
			cout << endl;
			break;
		case 2:
			cout << "f1(X) = ";
			cout << f1 << endl;
			cout << endl << "f2(X) = " << f2 << endl;
			break;
		case 3:
			cout << "\nf1(X) = ";
			cout << f1 << endl;
			cout << "f2(X) = ";
			cout << f2 << endl << endl;
			f = f1 + f2;
			cout << "f(X) = f1(X) + f2(X) = " << f << endl;
			break;
		case 4:
			cout << "\nf1(X) = ";
			cout << f1 << endl;
			cout << "f2(X) = ";
			cout << f2 << endl;
			f = f1 - f2;
			cout << "\nf(X) = f1(X) - f2(X) = "; 
			//if (f1 == f2)
				cout << f << endl;
			/*else
				cout << " 0 " << endl;*/
			break;
		case 5:
			cout << "\nf1(X) = ";
			cout << f1 << endl;
			cout << "f2(X) = ";
			cout << f2 << endl;
			f = f1 * f2;
			cout << "\nf(X) = f1(X) * f2(X) = " << f << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le!!!\n";
		}
		cout << endl;
		system("pause");
		system("cls");
	} while (chon != 0);

	return 0;
}


