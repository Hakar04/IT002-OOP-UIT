#include <iostream>
using namespace std;

typedef class INTEGER
{
private:
	int n;
public:
	~INTEGER();
	INTEGER(int = 0);
	INTEGER(const INTEGER&);

	int GetN()const;
	void SetN(int);

	friend INTEGER operator+(const INTEGER&, const INTEGER&);
	friend INTEGER operator-(const INTEGER&, const INTEGER&);
	friend INTEGER operator*(const INTEGER&, const INTEGER&);
	friend INTEGER operator/(const INTEGER&, const INTEGER&);

	friend ostream& operator<<(ostream&, const INTEGER&);
	friend istream& operator>>(istream&, INTEGER&);

	operator double()const;
	operator float()const;
	operator long()const;
	operator long double()const;

	friend bool operator!=(const INTEGER&, const INTEGER&);
	friend bool operator<=(const INTEGER&, const INTEGER&);
	friend bool operator<(const INTEGER&, const INTEGER&);
	friend bool operator==(const INTEGER&, const INTEGER&);
	friend bool operator>=(const INTEGER&, const INTEGER&);
	friend bool operator>(const INTEGER&, const INTEGER&);

	INTEGER operator++();
	INTEGER operator++(int);
	INTEGER operator--();
	INTEGER operator--(int);
}Int;


Int::~INTEGER() {
	this->n = 0;
}
Int::INTEGER(int n) :n(n) {}
Int::INTEGER(const INTEGER& m) :n(m.n) {}

int Int::GetN()const { return n; }
void Int::SetN(int n) { this->n = n; }

INTEGER operator+(const INTEGER& n1, const INTEGER& n2) {
	return INTEGER(n1.n + n2.n);
}
INTEGER operator-(const INTEGER& n1, const INTEGER& n2) {
	return INTEGER(n1.n - n2.n);
}
INTEGER operator*(const INTEGER& n1, const INTEGER& n2) {
	return INTEGER(n1.n * n2.n);
}
INTEGER operator/(const INTEGER& n1, const INTEGER& n2) {
	return INTEGER(n1.n / n2.n);
}

ostream& operator<<(ostream& os, const INTEGER& n) {
	os << n.n;
	return os;
}
istream& operator>>(istream& is, INTEGER& n) {
	is >> n.n;
	cout << endl;
	return is;
}

Int::operator double()const {
	return (double)n;
}
Int::operator float()const {
	return (float)n;
}
Int::operator long()const {
	return (long)n;
}
Int::operator long double()const {
	return (long double)n;
}

bool operator!=(const INTEGER& n1, const INTEGER& n2) {
	return n1.n != n2.n;
}
bool operator<=(const INTEGER& n1, const INTEGER& n2) {
	return n1.n <= n2.n;
}
bool operator<(const INTEGER& n1, const INTEGER& n2) {
	return n1.n < n2.n;
}
bool operator==(const INTEGER& n1, const INTEGER& n2) {
	return n1.n == n2.n;
}
bool operator>=(const INTEGER& n1, const INTEGER& n2) {
	return n1.n >= n2.n;
}
bool operator>(const INTEGER& n1, const INTEGER& n2) {
	return n1.n > n2.n;
}

INTEGER Int::operator++() {
	/*n++;
	return *this;*/
	return ++n;
}
INTEGER Int::operator++(int) {
	/*Int temp = n;
	n++;*/
	return n++;
}
INTEGER Int::operator--() {
	/*n--;
	return *this;*/
	return --n;
}
INTEGER Int::operator--(int) {
	/*Int temp = n;
	n--;*/
	return n--;
}

int main() {
	Int a, b, c;
	int chon;
	long double n;
	do {
		cout << "-------------CHUONG TRINH XU LY so nguyen-------------\n";
		cout << "1. Nhap so nguyen\n";
		cout << "2. Xuat so nguyen\n";
		cout << "3. So sanh\n";
		cout << "4. Cong 2 so nguyen\n";
		cout << "5. Tru 2 so nguyen\n";
		cout << "6. Nhan 2 so nguyen\n";
		cout << "7. Chia 2 so nguyen\n";
		cout << "8. so nguyen ++\n";
		cout << "9. ++ so nguyen\n";
		cout << "10. --so nguyen\n";
		cout << "11. so nguyen --\n";
		cout << "12. Cong so nguyen va 1 so(ep kieu)\n";
		cout << "13. Reset du lieu.\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "-------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon) {
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;
		case 1:
			cout << "So nguyen I: ";
			cin >> a;
			cout << "So nguyen II: ";
			cin >> b;
			break;
		case 2:
			cout << "So nguyen I: " << a << endl;
			cout << "So nguyen II: " << b << endl;
			break;
		case 3:
			if (a != b)
				cout << "Hai so nguyen khac nhau.\n";
			if (a > b)
				cout << "so nguyen 1 lon hon so nguyen 2: (" << a << ") > (" << b << ").\n";
			if (a < b)
				cout << "so nguyen 1 nho hon so nguyen 2: (" << a << ") < (" << b << ").\n";
			if (a == b)
				cout << "Hai so nguyen bang nhau.\n";
			if (a >= b)
				cout << "so nguyen 1 lon hon hoac bang so nguyen 2: (" << a << ") >= (" << b << ").\n";
			if (a <= b)
				cout << "so nguyen 1 nho hon hoac bang so nguyen 2: (" << a << ") <= (" << b << ").\n";
			break;
		case 4:
			c = a + b;
			cout << "Tong = " << c << endl;
			break;
		case 5:
			c = a - b;
			cout << "Hieu = " << c << endl;
			break;
		case 6:
			c = a * b;
			cout << "Tich = " << c << endl;
			break;
		case 7:
			c = a / b;
			cout << "Tich = " << c << endl;
			break;
		case 8:
			cout << "a = " << a << endl;
			cout << "a++ = " << a++ << endl;
			cout << "a = " << a << endl;
			cout << "\nb = " << b << endl;
			cout << "b++ = " << b++ << endl;
			cout << "b = " << b << endl;
			break;
		case 9:
			cout << "a = " << a << endl;
			cout << "++a = " << ++a << endl;
			cout << "a = " << a << endl;
			cout << "\nb = " << b << endl;
			cout << "++b = " << ++b << endl;
			cout << "b = " << b << endl;
			break;
		case 10:
			cout << "a = " << a << endl;
			cout << "a-- = " << a-- << endl;
			cout << "a = " << a << endl;
			cout << "\nb = " << b << endl;
			cout << "b-- = " << b-- << endl;
			cout << "b = " << b << endl;
			break;
		case 11:
			cout << "a = " << a << endl;
			cout << "--a = " << --a << endl;
			cout << "a = " << a << endl;
			cout << "\nb = " << b << endl;
			cout << "--b = " << --b << endl;
			cout << "b = " << b << endl;
			break;
		case 12:
			cout << "Ep kieu so nguyen\n";
			cout << "Nhap nhap so thuc: ";
			cin >> n;
			cout << "a + b + " << n << " = " << a + b + (Int)n << endl;
			cout << "\nEp kieu double\n";
			cout << "Nhap so thuc kieu double: ";
			cin >> n;
			cout << "a + b + " << (double)n << " = " << (double)a + (double)b + n << endl;
			break;
		case 13:
			a.~INTEGER();
			b.~INTEGER();
			cout << "Da reset gia tri.\n";
			break;
		default:
			cout << "Lua chon khong hop le!!!\n";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	} while (chon != 0);
	return 0;
}