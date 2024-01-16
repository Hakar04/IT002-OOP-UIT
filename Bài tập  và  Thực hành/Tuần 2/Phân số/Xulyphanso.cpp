#include "PHANSO.h"

PS::~PHANSO() {
	ts = 0;
	ms = 0;
}

PS::PHANSO(int ts, int ms):ts(ts), ms(ms) {}
PS::PHANSO(int ts) :ts(ts), ms(1) {}
PS::PHANSO() :ts(0), ms(1) {}

PS::PHANSO(const PS& ps):ts(ps.ts), ms(ps.ms){}

int PS::GetTS() const{ return ts; }
int PS::GetMS()const { return ms; }

void PS::SetTS(int ts) { this->ts = ts; }
void PS::SetMS(int ms) { this->ms = ms; }
void PS::SetTM(int ts, int ms){
	this->ts = ts;
	this->ms = ms;
}

void PS::Nhap(){
	cout << "Nhap tu so: ";
	cin >> ts;

	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> ms;
	} while (ms == 0);
}

void PS::Xuat() const{
	if (ts == 0)
		cout << "0" << endl;
	else if (ms == ts)
		cout << 1;
	else if (-ms == ts)
		cout << -1;
	else if (ms < -1)
		cout << -ts << "/" << -ms << endl;
	else if (ms == -1)
		cout << -ts << endl;
	else if (ms == 0)
		cout << "Khong chia duoc so 0" << endl;
	else if (ms==1)
		cout<<ts<<endl;
	else 
		cout << ts << "/" << ms;
}

int PS::TimUscln(int x, int y) const  {
	int uscln;
	x = abs(x);
	y = abs(y);
		
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
		
	return x;
}

void PS::RutGon(){
	int k = TimUscln(ts, ms);
	ts /= k;
	ms /= k;
}

PS operator+(const PS& ps1, const PS& ps2)
{
	return PHANSO(ps1.ts * ps2.ms + ps2.ts * ps1.ms, ps1.ms * ps2.ms);
}
PS operator-(const PS& ps1, const PS& ps2)
{
	return PHANSO(ps1.ts * ps2.ms - ps2.ts * ps1.ms, ps1.ms * ps2.ms);
}
PS operator*(const PS& ps1, const PS& ps2)
{
	return PHANSO(ps1.ts * ps2.ts, ps1.ms * ps2.ms);
}
PS operator/(const PS& ps1, const PS& ps2)
{
	return PHANSO(ps1.ts * ps2.ms, ps1.ms * ps2.ts);
}

PS::operator double()const { return (double)ts / ms; }

ostream& operator<<(ostream& os, const PS& ps)
{
	ps.Xuat();
	return os;
}
istream& operator>>(istream& is, PS& ps)
{
	ps.Nhap();
	return is;
}

bool operator!=(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) != (ps2.ts) * (ps1.ms);
}
bool operator<=(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) <= (ps2.ts) * (ps1.ms);
}
bool operator<(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) < (ps2.ts) * (ps1.ms);
}
bool operator==(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) == (ps2.ts) * (ps1.ms);
}
bool operator>=(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) >= (ps2.ts) * (ps1.ms);
}
bool operator>(const PS& ps1, const PS& ps2)
{
	return (ps1.ts) * (ps2.ms) > (ps2.ts) * (ps1.ms);
}

PHANSO PS::operator++() {
	ts += ms;
	return *this;
}
PHANSO PS::operator++(int) {
	PS pstam(ts, ms);//luu gia trij truoc khi tang;
	ts += ms;
	return pstam;
}
PHANSO PS::operator--() {
	ts - ms;
	return *this;
}
PHANSO PS::operator--(int) {
	PS pstam(ts, ms);//luu gia trij truoc khi tang;
	ts -= ms;
	return pstam;
}