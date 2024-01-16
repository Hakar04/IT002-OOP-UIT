#include "TRIANGLE.h"


int main()
{
	TRIANGLE tg;
	int chon;
	do {
		cout << "-----------------------Triangle processing program----------------------\n";
		cout << "-----------------------CHUONG TRINH XU LY TAM GIAC----------------------\n";
		cout << "\t1.Nhap thong tin tam giac - Entering information of triangle. \n";
		cout << "\t2.Xuat Thong tin tam giac - Accessing information of triangle. \n";
		cout << "\t3.Kiem tra tam giac hop le - Checking Triangle valid.\n";
		cout << "\t4.Di chuyen Tam giac - Move triangle\n";
		cout << "\t5.Tinh chu vi Tam giac - Calculating perimeter of triangle.\n";
		cout << "\t6.Tinh dien tich Tam giac - Calculating area of triangle.\n";
		cout << "\t0.Thoat chuong trinh - Exiting the program.\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
		cout << "------------------------------------------------------------------------\n";


		switch (chon)
		{
		case 0:
			cout << "Exiting...\n\n";
			break;

		case 1:
			cout << " Nhap Thong tin cua tam giac (Entering information of triangle): \n\n"; cin >> tg;
			if (!tg.Check_Valid()) {
				cout << "-------------------------------------------------------------------------\n";
				cout << "3 diem khong tao thanh 1 tam giac!!\nThree points do not form a triangle!!\n";
			}

			break;
		case 2:
			if (tg.Check_Valid())
				cout << tg << endl;
			else
				cout << "Tam giac khong hop le - Triangle invalid.\n\n";
			break;
		case 3:
			if (tg.Check_Valid())
				cout << "Tam giac hop le - Triangle valid.\n";
			else
				cout << "Tam giac khong hop le - Triangle invalid.\n";
			break;
		case 4:
			tg.Move();
			break;
		case 5:
			cout << "Chu vi Tam giac (perimeter of triangle) : " << tg.Calculate_Perimeter() << endl;
			break;
		case 6:
			cout << "Dien tich Tam giac (area of triangle): " << tg.Calculate_Area() << endl;
			break;
		default:
			cout << "Ban chon khong hop le!\n";
			break;
		}


		cout << "\n-------------------------------------------------------------------------\n";

		system("pause");
		system("cls");
	} while (chon != 0);

	return 0;

}
