#include "TestCandidate.h"

void TestCandidate::NhapDanhSachThiSinh()
{
    do
    {
        cout << "Nhap so thi sinh: ";
        cin >> n;
    } while (n <= 0);
    cout << endl;
    cin.ignore();
    DanhSachThiSinh = new Candidate[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin nguoi thu " << i + 1 << ":" << endl;
        DanhSachThiSinh[i].Nhap();
        cout << "----------------------------------------------------\n";
    }
}
void TestCandidate::IndsThiSinhTongDiemLonHon15() const
{
    int dem=0;
    cout << "Danh sach thi sinh co diem tong lon hon 15: " << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (DanhSachThiSinh[i].TinhDiemTong() > 15)
        {
            dem++;
            DanhSachThiSinh[i].Xuat();
        }
    }
    if (dem == 0)
        cout << "Khong co thi sinh nao!\n";
    else
        cout << "=> Co Tong " << dem << " thi sinh co Tong diem lon hon 15.\n";
}