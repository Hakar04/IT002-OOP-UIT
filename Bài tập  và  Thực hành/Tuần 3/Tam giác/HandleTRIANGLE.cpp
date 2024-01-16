#include "Triangle.h"

TG::~TRIANGLE() {}
TG::TRIANGLE() :A(0, 0), B(1, 0), C(0, 1) {}
TG::TRIANGLE(const POINT& A, const POINT& B, const POINT& C) :A(A), B(B), C(C)
{
	if (!Check_Valid())
		Input();
}
TG::TRIANGLE(double xA, double yA, double xB, double yB, double xC, double yC)
{
	if (!Check_Valid())
		Input();
}

POINT TG::GetA() const { return A; }
POINT TG::GetB() const { return B; }
POINT TG::GetC() const { return C; }

void  TG::SetA(const POINT& A) {
	this->A = A;
	while (!Check_Valid()) {
		cout << "Enter vertex coordinates A (Nhap toa do dinh A): ";
		this->A.Input();
	}
}
void  TG::SetB(const POINT& B) {
	this->B = B;
	while (!Check_Valid()) {
		cout << "Enter vertex coordinates B (Nhap toa do dinh B): ";
		this->B.Input();
	}
}
void  TG::SetC(const POINT& C) {
	this->C = C;
	while (!Check_Valid()) {
		cout << "Enter vertex coordinates C (Nhap toa do dinh C): ";
		this->C.Input();
	}
}
void TG::SetTG(const POINT& A, const POINT& B, const POINT& C)
{
	SetA(A);
	SetB(B);
	SetC(C);
}
void TG::Input()
{

	cout << "\tEnter vertex three coordinates (Nhap toa do 3 dinh)\n\n ";
	cout << "Enter vertex coordinates A (Nhap toa do dinh A).\n ";
	cin >> A;
	cout << "\nEnter vertex coordinates B (Nhap toa do dinh B) \n";
	cin >> B;
	cout << "\nEnter vertex coordinates C (Nhap toa do dinh C) \n";
	cin >> C;

}

void TG::Output() const
{
	cout << "Triangle ABC with (tam giac ABC voi):\n\t+ Three coordinates  (3 dinh) : " << "A"<<A << ", B" << B << ", C" << C;
	cout << ") \n\t+ Length of three sides (do dai 3 canh) : AB = " << A.Find_Distance(B) << ", BC = " << C.Find_Distance(B) << ", AC = " << A.Find_Distance(C);
}
bool TG::Check_Valid()const
{
	return A.Check_TRIANGLE_Valid(B, C);
}
string TG::Classify() const
{
	return A.Classify_TRIANGLE(B, C);
}
double TG::Calculate_Perimeter() const
{
	return A.Calculate_Perimeter_TRIANGLE(B, C);
}
double TG::Calculate_Area() const
{
	return A.Calculate_Area_TRIANGLE(B, C);
}

istream& operator>>(istream& is, TRIANGLE& TG)
{
	TG.Input();
	return is;
}

ostream& operator<<(ostream& os, const TRIANGLE& TG)
{
	TG.Output();
	return os;
}

void TG::Move()
{
	double dx, dy;
	cout << "Move coordinates A (Di chuyen dinh A):\n";
	cout << " Abscissa (Hoanh do): "; cin >> dx;
	cout << " Ordinate (Tung do): "; cin >> dy;
	A.Move_POINT(dx, dy);
	cout << endl;
	cout << "Move coordinates B (Di chuyen dinh B):\n";
	cout << " Abscissa (Hoanh do): "; cin >> dx;
	cout << " Ordinate (Tung do): "; cin >> dy;
	B.Move_POINT(dx, dy);
	cout << endl;
	cout << "Move coordinates C (Di chuyen dinh C):\n";
	cout << " Abscissa (Hoanh do): "; cin >> dx;
	cout << " Ordinate (Tung do): "; cin >> dy;
	C.Move_POINT(dx, dy);
	cout << endl;
	cout << "Three coordinates after moving  (3 dinh sau khi di chuyen): ";
	cout << "A'" << A << ", B'" << B << ", C'" << C << endl;
}

//void Move1()
//{
//	A.Move(B, C);
//
//}