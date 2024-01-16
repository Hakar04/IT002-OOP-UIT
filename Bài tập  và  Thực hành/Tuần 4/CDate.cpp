#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

typedef class CDate {
private:
	int d, y, m;
	time_t now = time(0);
	tm ltm;
	int a = localtime_s(&ltm, &now);
	//tm* ltm = localtime(&now);
public:
	~CDate();
	CDate();
	CDate(int);
	CDate(int, int);
	CDate(int, int, int);
	CDate(const CDate&);
	int GetD()const;
	int GetM()const;
	int GetY()const;
	void SetD(int);
	void SetM(int);
	void SetY(int);
	void QuyDoi();
	int QuyDoiNgay() const;
	bool Kiemtra()const;
	int Khoangcach(const CDate&);
	friend ostream& operator<< (ostream&, const CDate&);
	friend istream& operator>> (istream&, CDate&);
	friend CDate operator+(const CDate&, int);
	friend CDate operator-(const CDate&, int);
	CDate operator++();
	CDate operator--();
}CD;

bool KiemTraNamNhuan(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

CD::~CDate() {}
CD::CDate() {
	d = ltm.tm_mday;
	m = ltm.tm_mon + 1;
	y = ltm.tm_year + 1900;
}
CD::CDate(int d) {
	this->d = d;
	m = ltm.tm_mon + 1;
	y = ltm.tm_year + 1900;
	while (!Kiemtra()) QuyDoi();
}
CD::CDate(int d, int m) {
	this->d = d;
	this->m = m;
	y = ltm.tm_year + 1900;
	while (!Kiemtra()) QuyDoi();
}
CD::CDate(int d, int m, int y) {
	this->d = d;
	this->m = m;
	this->y = y;
	while (!Kiemtra()) QuyDoi();
}
CD::CDate(const CDate& x) :m(x.m), d(x.d), y(x.y) {}

int CD::GetD()const { return d; }
int CD::GetM()const { return m; }
int CD::GetY()const { return y; }
void CD::SetD(int d) {
	this->d = d;
}
void CD::SetM(int m) {
	this->m = m;
}
void CD::SetY(int y) {
	this->y = y;
}
int CD::QuyDoiNgay()const {
	int a[] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	int s = 0;
	if (KiemTraNamNhuan(y)) a[1] = 29;
	for (int i = 0; i < y; i++) {
		if (KiemTraNamNhuan(i)) s += 366;
		else s += 365;
	}
	for (int i = 1; i < m; i++) {
		s += a[i - 1];
	}
	s += d;
	return s;
}

void CD::QuyDoi() {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KiemTraNamNhuan(y)) a[1] = 29;
	if (d > a[m - 1]) {
		d -= a[m - 1];
		m = m % 12 + 1;
		if (m == 1)
			y++;
	}
	else if (d <= 0) {
		d = a[(m + 11) % 12] - abs(d);
		m--;
		if (m == 0) {
			y--; m = 12;
		}
	}
}
bool CD::Kiemtra() const {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (KiemTraNamNhuan(y)) a[1] = 29;
	if (m < 1 || m >12) return 0;
	if (d < 1 || d > a[m - 1]) return 0;
	return 1;
}

ostream& operator<< (ostream& os, const CDate& x) {
	os << "Ngay " << x.d << " Thang " << x.m << " Nam " << x.y << endl;
	return os;
}
istream& operator>> (istream& is, CDate& x) {
	do {
		cout << "Nhap ngay: ";
		is >> x.d;
		cout << "Nhap thang: ";
		is >> x.m;
		cout << "Nhap nam: ";
		is >> x.y;
	} while (!x.Kiemtra());
	return is;
}

CDate operator+(const CDate& day1, int x) {
	return CDate(day1.d + x, day1.m, day1.y);
}
CDate operator-(const CDate& day1, int x) {
	return CDate(day1.d - x, day1.m, day1.y);
}
int CD::Khoangcach(const CDate& day1) {
	return abs(QuyDoiNgay() - day1.QuyDoiNgay());
}

CDate CD::operator++() {
	return CDate(d + 1, m, y);
}
CDate CD::operator--() {
	return CDate(d - 1, m, y);
}
int main() {

	CD day1, day2, day3(3), day4(15, 9), tong, hieu, truoc, sau;
	int chon, x;
	do {
		cout << "----------------------------------CHUONG TRINH XU LY NGAY----------------------------------\n";
		cout << "\t(1). Nhap ngay\n";
		cout << "\t(2). Xuat ngay\n";
		cout << "\t(3). Cong them ngay\n";
		cout << "\t(4). Tru ngay\n";
		cout << "\t(5). Ngay tiep theo\n";
		cout << "\t(6). Ngay hom truoc\n";
		cout << "\t(7). Khoang cach giua hai ngay\n";
		cout << "\t(0). Thoat chuong trinh\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon) {
		case 0:
			cout << "Dang thoat chuong trinh...\n\n";
			break;
		case 1:
			cin >> day1;
			cout << endl;
			break;
		case 2:
			cout << "Cho ngay la 3: " << day3 << endl;
			cout << "Cho ngay la 15 thang 9: " << day4 << endl;
			cout << "Neu co in thoi gian duoc nhap vao (neu khong in thoi gian he thong):\n " << day1 << endl;
			break;
		case 3:
			cout << "Nhap so ngay muon cong (>=0): ";
			cin >> x;
			tong = day1 + x;
			cout << "Sau khi cong: " << tong << endl;
			break;
		case 4:
			cout << "Nhap so ngay muon tru (>=0): ";
			cin >> x;
			hieu = day1 - x;
			cout << "Sau khi tru: " << hieu << endl;
			break;
		case 5:
			truoc = ++day1;
			cout << "Ngay tiep theo: " << truoc << endl;
			break;
		case 6:
			sau = --day1;
			cout << "Ngay hom qua: " << sau << endl;
			break;
		case 7:
			cout << "Nhap ngay so 2: \n";
			cin >> day2;
			cout << "Ngay 1: " << day1;
			cout << "Ngay 2: " << day2 << endl;
			cout << "Khoang cach giua hai ngay: " << day1.Khoangcach(day2) << " ngay" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le!!!\n";
		}
		system("pause");
		system("cls");
	} while (chon != 0);

	return 0;
}