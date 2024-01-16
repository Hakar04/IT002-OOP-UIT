#include "Candidate.h"

Candidate::~Candidate(){}

Candidate::Candidate(string Ma, string Ten, int d, int m, int y, float Diem_Toan, float Diem_Van, float Diem_Anh)
{
    while (this->Ma!="")
        this->Ma = Ma;
    while (this->Ten!="")
        this->Ten = Ten;
    while (this->d >= 1 && this->d <= 31)
        this->d = d;
    while (this->m >= 1 && this->m <= 12)
        this->m = m;
    while (this->y > 0)
        this->y = y;
    while (this->Diem_Toan >= 0 && this->Diem_Toan <= 10)
        this->Diem_Toan = Diem_Toan;
    while (this->Diem_Van >= 0 && this->Diem_Van <= 10)
        this->Diem_Van = Diem_Van;
    while (this->Diem_Anh >= 0 && this->Diem_Anh <= 10)
        this->Diem_Anh = Diem_Anh;
}
string Candidate::GetMa() { return Ma;}
string Candidate::GetTen() { return Ten; }
int Candidate::SetD() { return d; }
int Candidate::SetM() { return m; }
int Candidate::SetY() { return y; }
float Candidate::GetDT() { return Diem_Toan; }
float Candidate::GetDV() { return Diem_Van; }
float Candidate::GetDA() { return Diem_Anh; }

void Candidate::SetMa(string Ma) { 
    while (this->Ma != "")
        this->Ma = Ma;
}
void Candidate::SetTen(string Ten){ 
    while (this->Ten != "")
        this->Ten = Ten;
}
void Candidate::GetD(int d)
{
    while (this->d >= 1 && this->d <= 31)
        this->d = d;
}
void Candidate::GetM(int m)
{
    while (this->m >= 1 && this->m <= 12)
        this->m = m;
}
void Candidate::GetY(int y)
{
    while (this->y > 0)
        this->y = y;
}
void Candidate::SetDT(float Diem_Toan){ 
    while (this->Diem_Toan >= 0 && this->Diem_Toan <= 10)
        this->Diem_Toan = Diem_Toan;
}
void Candidate::SetDV(float Diem_Van){ 
    while (this->Diem_Van >= 0 && this->Diem_Van <= 10)
        this->Diem_Van = Diem_Van;
}
void Candidate::SetDA(float Diem_Anh){ 
    while (this->Diem_Anh >= 0 && this->Diem_Anh <= 10)
        this->Diem_Anh = Diem_Anh;
}

void Candidate::SetCandidate(string Ma, string Ten, int d, int m, int y, float Diem_Toan, float Diem_Van, float Diem_Anh)
{
    while (this->Ma != "")
        this->Ma = Ma;
    while (this->Ten != "")
        this->Ten = Ten;
    while (this->d >= 1 && this->d <= 31)
        this->d = d;
    while (this->m >= 1 && this->m <= 12)
        this->m = m;
    while (this->y > 0)
        this->y = y;
    while (this->Diem_Toan >= 0 && this->Diem_Toan <= 10)
        this->Diem_Toan = Diem_Toan;
    while (this->Diem_Van >= 0 && this->Diem_Van <= 10)
        this->Diem_Van = Diem_Van;
    while (this->Diem_Anh >= 0 && this->Diem_Anh <= 10)
        this->Diem_Anh = Diem_Anh;
}

void Candidate::Nhap()
{
    cout << "Nhap MS Thi Sinh: ";
    getline(cin, Ma);
    do {
        cout << "Nhap Ten: ";
        getline(cin, Ten);
        if (Ten == "") cout << "Ten khong hop le!";
    } while (Ten == "");

    do {
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> d >> m >> y;
        if (this->KiemTraNgayThangHopLe() != 1)
            cout << "Ngay thang khong hop le! Moi nhap lai!!" << endl << endl;
    } while (this->KiemTraNgayThangHopLe() != 1);
    do
    {
        cout << "Nhap diem thi Toan: ";
        cin >> Diem_Toan;
        cout << "Nhap diem thi Van: ";
        cin >> Diem_Van;
        cout << "Nhap diem thi Anh: ";
        cin >> Diem_Anh;
    } while (Diem_Toan < 0 || Diem_Van < 0 || Diem_Anh < 0 || Diem_Toan >10 || Diem_Van > 10 || Diem_Anh > 10);
    cin.ignore();
}

float Candidate::TinhDiemTong() const
{
    return Diem_Toan + Diem_Van + Diem_Anh;
}
void Candidate::Xuat() const
{
    cout << "MSSV: " << Ma << "\n"
        << "Ten: " << Ten << "\n";
    cout <<"Ngay sinh: "<< d << "/" << m << "/" << y << endl;

    cout << "Diem Diem_Toan: " << Diem_Toan << "\n"
        << "Diem Diem_Van: " << Diem_Van << "\n"
        << "Diem Diem_Anh: " << Diem_Anh << "\n"
        << "Diem Tong: " << TinhDiemTong() << endl;
    cout << "----------------------------------------------------\n";
}

int Candidate::KiemTraNgayThangHopLe() const
{
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    {
        if (d >= 1 && d <= 31) return 1;
        else return 0;
    }
    case 4: case 6: case 9: case 11:
    {
        if (d >= 1 && d <= 30) return 1;
        else return 0;
    }
    case 2:
    {
        if (y % 4 == 0)
        {
            if (y % 100 == 0)
            {
                if (y % 400 == 0)/* tháng có 29 ngày*/
                {
                    if (d >= 1 && d <= 29) return 1;
                    else return 0;
                }
                else/* tháng có 28 ngày*/
                {
                    if (d >= 1 && d <= 28) return 1;
                    else return 0;
                }
            }
            else/* tháng có 29 ngày */
            {
                if (d >= 1 && d <= 29) return 1;
                else return 0;
            }
        }
        else /*tháng có 28 ngày*/
        {
            if (d >= 1 && d <= 28) return 1;
            else return 0;
        }

    }
    default:
        return 0;
    }
}