#include "BangCuuChuong.h"
#include <iomanip>

BCC::BangCuuChuong(int m, int n)
{
	if (m < 2 || m>9 || n < 2 || n>9)
		Nhap();
	else
	{
		this->m = m;
		this->n = n;
	}
}

int BCC::GetM() { return m; }
int BCC::GetN() { return n; }

void BCC::SetM(int m)
{
	while (m < 2 || m>9)
	{
		cout << "Nhap m tu 2->9: ";
		cin >> m;
	}
	this->m = m;
}
void BCC::SetN(int n)
{
	while (n < 2 || n > 9)
	{
		cout << "Nhap n tu 2->9: ";
		cin >> n;
	}
	this->n = n;
}
void BCC::SetMN(int m, int n)
{
	*this = BCC(m, n);
}

void BCC::Nhap() {
	do {
		cout << "Nhap BCC m, n tu 2->9: ";
		cin >> m >> n;
	} while (m < 2 || m>9 || n < 2 || n>9);
}
void BCC::Xuat()
{
	In_BCC_m();
	In_BCC_mn();
	In_BCC_TongHop();
}

void BCC::In_BCC_m()
{
	cout << "____________IN BCC THU " << m << "____________\n";
	for (int i = 1; i <= 10; i++)
		cout << "            " << m << " x " << setw(2) << i << " = " << setw(2) << m * i << "\n";
}

void BCC::In_BCC_mn()
{
	cout << "___________________________IN BCC TU " << m << " DEN " << n << "__________________________\n";
	int x = max(m, n), y = min(m, n);
	for (int i = 1; i <= 10; i++)
	{
		for (int j=y; j <= x; j++)
			cout << j << " x " << setw(2) << i << " = " << setw(2) << j * i << "\t";
		cout << endl ;
	}
}

void BCC::In_BCC_TongHop()
{
	cout << "______________________________IN BCC TONG HOP______________________________\n";
	for (int i = 1; i <= 10; i++)
	{
		for (int a = 1; a <= 10; a++)
			cout << setw(3) << a * i << "\t";
		cout << endl << endl;
	}
}