#include "SoPhuc.h"

int main()
{
	SP z1, z2;
	int chon1;

	do {
		cout << "-----------CHUONG TRINH XU LY SO PHUC----------\n";
		cout << "\t1.Nhap so phuc\n";
		cout << "\t2.Xuat so phuc\n";
		cout << "\t3.Tinh tong\n";
		cout << "\t4.Tinh hieu\n";
		cout << "\t5.Tinh tich\n";
		cout << "\t6.Tinh thuong\n";
		cout << "\t7. Tang giam so phuc\n";
		cout << "\t8. So sanh\n";
		cout << "\t0.Thoat chuong trinh\n";
		cout << "------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon1;
		SP tong, hieu, tich, thuong;
		switch (chon1)
		{
		case 0:
			cout << "Dang thoat chuong trinh...\n";
			break;

		case 1:
			cout << "\tNhap So phuc 1\n "; cin >> z1;
			cout << endl;
			cout << "\tNhap So phuc 2 \n "; cin >> z2;
			break;
		case 2:
			cout << "z1 = " << z1; cout << "\n";
			cout << "z2 = " << z2; cout << "\n";
			break;
		case 3:

			tong = z1 + z2;
			cout << "Tong 2 so phuc: z1 + z2 = " << tong; cout << endl;
			break;
		case 4:
			hieu = z1 - z2;
			cout << "Hieu 2 so phuc: z1 - z2 = " << hieu << endl;
			break;
		case 5:
			tich = z1 * z2;
			cout << "Tich 2 so phuc: z1 . z2 = " << tich; cout << endl;
			break;
		case 6:

			if (z2 == SP(0, 1)) cout << "Khong chia duoc!!";
			else {
				thuong = z1 / z2;
				cout << "Thuong 2 so phuc: z1 / z2 = " << thuong << endl;
			}
			break;
		case 7:
			cout << "z1 = " << z1 << endl;
			cout << "++z1 = " << ++z1 << endl;
			cout << "z1 = " << z1 << endl;
			cout << "z1++ = " << z1++ << endl;
			cout << "z1 = " << z1 << endl;
			cout << "--z1 = " << --z1 << endl;
			cout << "z1 = " << z1 << endl;
			cout << "z1-- = " << z1-- << endl;
			cout << "z1 = " << z1 << endl;
			break;
		case 8:
			if (z1 == z2)
				cout << "Hai so phuc bang nhau\n";
			if (z1 >= z2)
				cout << "So phuc 1 lon hon bang so phuc 2\n";
			if (z1 <= z2)
				cout << "So phuc 1 nho hon bang so phuc 2\n";
			if (z1 != z2)
				cout << "Hai so phuc khac nhau\n";
			if (z1 > z2)
				cout << "So phuc 1 lon hon so phuc 2\n";
			if (z1<z2)
				cout << "So phuc 1 nho hon so phuc 2\n";
			break;
		default: cout << "Khong hop le!\n"; break;
		}

		system("pause");
		system("cls");
	} while (chon1 != 0);
	return 0;
}
