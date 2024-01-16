#pragma once
#ifndef _Bangcuuchuong
#include <iostream>
using namespace std;

typedef class BangCuuChuong {
private:
	int m, n;
public:
	
	BangCuuChuong(int = 2, int = 9);
	int GetM();
	int GetN();
	void SetM(int);
	void SetN(int);
	void SetMN(int, int);

	void Nhap();
	void Xuat();
	void In_BCC_m();
	void In_BCC_mn();
	void In_BCC_TongHop();
}BCC;


#endif // !_Bangcuuchuong
