#include "PHANSO.h"

int main()
{
	PS ps1, ps2;
	int chon, n;

	do
	{
		cout << "-------------CHUONG TRINH XU LY PHAN SO-------------\n";
		cout << "1. Nhap phan so\n";
		cout << "2. Xuat phan so\n";
		cout << "3. Rut gon phan so\n";
		cout << "4. So sanh phan so\n";
		cout << "5. Cong 2 phan so\n";
		cout << "6. Tru 2 phan so\n";
		cout << "7. Nhan 2 phan so\n";
		cout << "8. Chia 2 phan so\n";
		cout << "9. Phan so ++\n";
		cout << "10. ++ phan so\n";
		cout << "11. --phan so\n";
		cout << "12. Phan so --\n";
		cout << "13. Cong phan so va 1 so(ep kieu)\n";
		cout << "14. Reset du lieu.\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "-------------------------------------------------------\n";
			cout << "Ban chon: ";
			cin >> chon;
			if (chon== 0)
				cout << "Dang thoat Chuong trinh...\n\n";
			else if (chon == 1) {
				cout << "Nhap phan so 1: " << endl;
				cin >> ps1;
				cout << "Nhap phan so 2: " << endl;
				cin >> ps2;
			}
			else if (chon == 2) {
				cout << "Phan so thu 1: ";
				cout << ps1 << endl;
				cout << "Phan so thu 2: ";
				cout << ps2 << endl;
			}
			else if (chon == 3) {
				cout << "Rut gon phan so: \n";
				cout << "Phan so thu nhat: "; ps1.RutGon();  cout <<ps1<< endl;
				cout << "Phan so thu hai: "; ps2.RutGon();  cout << ps2<<endl;
			}
			else if (chon == 4) {
				if (ps1 != ps2)
					cout << "Hai phan so khac nhau.\n";
				if (ps1 > ps2)
					cout << "Phan so 1 lon hon phan so 2: (" << ps1 << ") > (" << ps2 << ").\n";
				if (ps1 < ps2)
					cout << "Phan so 1 nho hon phan so 2: (" << ps1 << ") < (" << ps2 << ").\n";
				if (ps1 == ps2)
					cout << "Hai phan so bang nhau.\n";
				if (ps1 >= ps2)
					cout << "Phan so 1 lon hon hoac bang phan so 2: (" << ps1 << ") >= (" << ps2 << ").\n";
				if (ps1 <= ps2)
					cout << "Phan so 1 nho hon hoac bang phan so 2: (" << ps1 << ") <= (" << ps2 << ").\n";
			}
			else if (chon == 5) {
				cout << "Tong 2 ps = ";
				PS cong = ps1 + ps2;
				cong.RutGon();
				cout << cong << endl;
			}
			else if (chon == 6) {
				cout << "Hieu 2 ps = ";
				PS tru = ps1 - ps2;
				tru.RutGon();
				cout << tru << endl;
			}
			else if (chon == 7) {
				cout << "Tich 2 ps = ";
				PS nhan = ps1 * ps2;
				nhan.RutGon();
				cout << nhan << endl;
			}
			else if (chon == 8) {
				cout << "Thuong 2 ps = ";
				PS chia = ps1 / ps2;
				chia.RutGon();
				cout << chia << endl;
			}
			else if (chon == 9) {
				cout << "ps1 = " << ps1 << endl;
				cout << "ps1++ = " << ps1++ << endl;
				cout << "ps1 = " << ps1 << endl;
				cout << "ps2 = " << ps2 << endl;
				cout << "ps2++ = " << ps2++ << endl;
				cout << "ps2 = " << ps2 << endl;
			}
			else if (chon == 10) {
				cout << "ps1 = " << ps1 << endl;
				cout << "++ps1 = " << ++ps1 << endl;
				cout << "ps1 = " << ps1 << endl;
				cout << "ps2 = " << ps2 << endl;
				cout << "++ps2 = " << ++ps2 << endl;
				cout << "ps2 = " << ps2 << endl;
			}
			else if (chon == 11) {
				cout << "ps1 = " << ps1 << endl;
				cout << "--ps1 = " << --ps1 << endl;
				cout << "ps1 = " << ps1 << endl;
				cout << "ps2 = " << ps2 << endl;
				cout << "--ps2 = " << --ps2 << endl;
				cout << "ps2 = " << ps2 << endl;
			}
			else if (chon == 12) {
				cout << "ps1 = " << ps1 << endl;
				cout << "ps1-- = " << ps1-- << endl;
				cout << "ps1 = " << ps1 << endl;
				cout << "ps2 = " << ps2 << endl;
				cout << "ps2-- = " << ps2-- << endl;
				cout << "ps2 = " << ps2 << endl;
			}
			else if (chon == 13) {
				cout << "Ep kieu phan so\n";
				cout << "Nhap so nguyen: ";
				cin >> n;
				cout << "ps1 + ps2 + " << n << " = " << ps1 + ps2 + (PHANSO)n << endl;
				cout << "\nEp kieu double\n";
				cout << "Nhap so thuc kieu double: ";
				cin >> n;
				cout << "ps1 + ps2 + " << (double)n << " = " << (double)ps1 + (double)ps2 + n << endl;
			}
			else if (chon == 14) {
				ps1.~PHANSO();
				ps2.~PHANSO();
				cout << "Phan so da reset.\n";
			}
			else
				cout << "Ban chon sai moi chon lai!\n\n";
		system("pause");
		system("cls");
	} while (chon != 0);

	return 0;
}