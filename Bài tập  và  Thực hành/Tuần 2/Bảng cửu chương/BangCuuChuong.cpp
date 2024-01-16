#include "BangCuuChuong.h"

int main()
{
    BCC bcc;
    int chon;
    do
    {
        cout << "-----------CHUONG TRINH IN BANG CUU CHUONG----------\n";
        cout << "\t1.Nhap Bang Cuu Chuong\n";
        cout << "\t2.Xuat Bang Cuu Chuong\n";
        cout << "\t3.In Bang Cuu Chuong thu m\n";
        cout << "\t4.In Bang Cuu Chuong tu m den n\n";
        cout << "\t5.Inn Bang Cuu Chuong tong hop\n";
        cout << "\t6.Thiet lap lai gia tri m, n\n";
        cout << "\t0.Thoat chuong trinh\n";
        cout << "-----------------------------------------------------\n";
        cout << "Ban chon: ";
        cin >> chon;
        do {
            switch (chon)
            {
            case 0: cout << "Dang thoat chuong trinh......\n"; break;
            case 1: bcc.Nhap(); break;
            case 2: bcc.Xuat(); break;
            case 3: bcc.In_BCC_m(); break;
            case 4: bcc.In_BCC_mn(); break;
            case 5: bcc.In_BCC_TongHop(); break;
            case 6: bcc.SetMN(2, 9); cout << "m moi: " << bcc.GetM() << ", n moi: " << bcc.GetN() << endl; break;
            default:
                cout << "Khong hop le! vui long nhap lai!" << endl;
                break;
            }
            if (chon != 0)
            {

                cout << "-----------------------------------------------------\n";
                cout << "Ban chon theo menu de tiep tuc thao tac.\n\n";
                cout << "\t1.Nhap Bang Cuu Chuong\n";
                cout << "\t2.Xuat Bang Cuu Chuong\n";
                cout << "\t3.In Bang Cuu Chuong thu m\n";
                cout << "\t4.In Bang Cuu Chuong tu m den n\n";
                cout << "\t5.Inn Bang Cuu Chuong tong hop\n";
                cout << "\t6.Thiet lap lai gia tri m, n\n";
                cout << "\t0.Thoat chuong trinh\n";
                cout << "------------------------------------------------\n";
                cout << "Ban chon: ";
                cin >> chon;


            }
        } while (chon != 0);

        cout << "Dang thoat chuong trinh...\n\n";
        system("pause");
        system("cls");
    } while (chon == 0);
    return 0;
}  