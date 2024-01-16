#include "HinhTron.h"


int main()
{
	HinhTron htr;
	int chon;

	do {
		cout << "-----------CHUONG TRINH XU LY HINH TRON----------\n";
		cout << "1.Nhap diem\n";
		cout << "2.Xuat diem\n";
		cout << "3.Tinh chu vi Hinh tron\n";
		cout << "4.Tinh dien tich Hinh tron\n";
		cout << "0.Thoat chuong trinh\n";
		cout << "---------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
		do {
			switch (chon)
			{
			case 0:
				cout << "Dang thoat chuong trinh...\n\n";
				break;

			case 1:
				cout << " Nhap Hinh tron: \n"; cin >> htr;
				break;
			case 2:
				cout << htr << endl;
				break;
			case 3:
				cout << "Chu vi hinh tron la : " << htr.TinhChuVi() << endl;
				break;
			case 4:
				cout << "Dien tich hinh tron la : " << htr.TinhDienTich() << endl;
				break;
			default:
				cout << "Ban chon khong hop le!\n";
			}
			if (chon != 0)
			{
				cout << "-----------------------------------------------------\n";
				cout << "Ban chon theo menu de tiep tuc thao tac.\n Ban chon:";
				cin >> chon;
			}
		} while (chon != 0);


		system("pause");
		system("cls");
	} while (chon == 0);

	return 0;

}
