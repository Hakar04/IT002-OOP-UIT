#include "DIEM.h"
int DIEM::dem = 0;

/*Định nghĩa phương thức hủy (decontructor) (hàm hủy) => Do điểm chỉ có 2 thuộc tính hoành độ x, tung độ y kiểu số thực
  (không có thuộc tinha kiểu con trỏ) nên không gọi hàm delete để giải phóng vùng nhớ động đã cấp phát, mà chỉ hiện
  thông báo "Da huy 1 DIEM" để thấy được CT tự động gọi phương thức này khi kết thúc hàm/chương trình*/
DIEM::~DIEM()
{
	cout << "Dang huy 1 DIEM => Con " << --dem << "diem\n";
}

/* Định nghĩa 3 phương thức khởi tạo tự động (contruction) không có giá tị mặc định, dufng kĩ thuật nạp chồng hàm
   (function overloading) */

//DIEM::DIEM()
   //{
   //	x = y = 0;
   //}
   //
   // DIEM::DIEM(double x)
   //{
   //	this->x = x;
   //	y = 0;
   //}
   //
   // DIEM::DIEM(double x, double y)
   //{
   //	 this->x = x;
   //	 this->y = y;
   //}

 /* Định nghĩa phương thức khởi tạo tự động (contruction) với giá trị mặc định thay thế cho 3 phương thức khởi tạo tự động trên*/
DIEM::DIEM(double x, double y) : x(x), y(y) { dem++; }


//void DIEM::KhoiTao()
//{
//	x = 0;
//	y = 0;
//}

//void DIEM::KhoiTao(double x)
//{
//	this->x = x;
//	y = 0;
//}
//
//void DIEM::KhoiTao(double x, double y)
//{
//	this->x = x;
//	this->y = y;
//}

double DIEM::GetX() const
{
	return x;
}
double DIEM::GetY() const
{
	return y;
}
int DIEM::GetDem() { return dem; }
void DIEM::SetX(double x)
{
	this->x = x;
}
void DIEM::SetY(double y)
{
	this->y = y;
}
void DIEM::SetXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void DIEM::Nhap()
{
	cin >> x >> y;
}

void DIEM::Xuat() const
{
	cout << x << " , " << y;
}

void DIEM::DiChuyen(double dx, double dy)
{
	x += dx;
	y += dy;
}

int  DIEM::KiemTraTrung(const DIEM &d) const
{ 
	if (x == d.x && y != d.y) return 1;
	if (x != d.x && y == d.y) return 2;
	if (x == d.x && y == d.y) return 3;
	return 0;
}

//Công thức chung: d()=sqrt(pow(x-x', 2)+ pow(y-y', 2))
double DIEM::TinhKhoangCach(const DIEM& d) const
{
	return sqrt(pow(x - d.x, 2)+ pow(y-d.y, 2));
}

DIEM DIEM::TimDoiXung() const
{
	return DIEM(-x == 0 ? 0 : -x, -y == 0 ? 0 : -y);
}

bool DIEM::KiemTraTamGiacHopLe(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}

double DIEM::TinhChuViTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	//return KiemTraTamGiacHopLe(d1, d2) ? a + b + c : 0;
	return a + b + c;
}

double DIEM::TinhDienTichTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

string DIEM::PhanLoaiTamGiac(const DIEM& d1, const DIEM& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	string chuoikq = "";
	if (!KiemTraTamGiacHopLe(d1, d2))
		chuoikq = "TG khong hop le";
	else if (a == b || b == c || c == a)
	{
		if ((a * a + b * b - c * c) <= epsilon || (c * c + b * b - a * a) <= epsilon || (a * a + c * c - b * b) <= epsilon)
			chuoikq = "TG vuong can";
		else
			chuoikq = "TG can";
	}
	else if (a * a + b * b - c * c <= epsilon || c * c + b * b - a * a <= epsilon || a * a + c * c - b * b <= epsilon)
		chuoikq = "TG vuong";
	else
		chuoikq = "TG thuong";
	return chuoikq;
}

istream& operator>>(istream& is, DIEM& d)
{
	d.Nhap();
	return is;
}
ostream& operator<<(ostream& os, DIEM& d)
{
	d.Xuat();
	return os;
}
