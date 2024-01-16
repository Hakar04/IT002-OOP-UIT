#include "TestCandidate.h"

int main()
{
    TestCandidate Kiemtra;
    int chon;

    do {
		cout << "---------------CHUONG TRINH XU LY DIEM--------------\n";
		cout << "\t1.Nhap Thong tin thi sinh\n";
		cout << "\t2.In danh sach thi sinh co tong diem lon hon 15\n";
		cout << "\t0.Thoat chuong trinh\n";
		cout << "---------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> chon;
        cout << "------------\n";
        switch (chon)
        {
        case 1:
            Kiemtra.NhapDanhSachThiSinh();
            break;
        case 2:
            Kiemtra.IndsThiSinhTongDiemLonHon15();
            break;
        default:
            cout << "Su lua chon cua ban khong hop le!!\n";
            break;
        }
        system("pause");
        system("cls");
    } while (chon != 0);
    return 0;
}