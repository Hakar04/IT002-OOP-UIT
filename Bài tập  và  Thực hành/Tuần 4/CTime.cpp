#include <iostream>
#include <math.h>
using namespace std;
class CTime
{
private:
    int h; 
    int m; 
    int s; 
    void QuyDoi();
    bool Kiemtra()const;
public:
    ~CTime();
    CTime(int =0, int=0, int=0);
    //CTime(const CTime&);
    void SetH(int);
    void SetM(int);
    void SetS(int);
    void Sett(int, int, int);
    int GetH();
    int GetM();
    int GetS();

    

    friend CTime operator + (const CTime&, int);
    friend CTime operator - (const CTime&, int);

    friend CTime operator - (const CTime&, const CTime&);

    CTime operator ++ ();
    CTime operator -- ();
    //friend bool operator<=(const CTime&, const CTime&);

    friend istream& operator >> (istream&, CTime&);
    friend ostream& operator << (ostream&, const CTime&);
};
CTime::CTime(int s, int m, int h) {
    this->h = h;
    this->m = m;
    this->s = s;
    while (!Kiemtra())
        QuyDoi();
}
//CTime::CTime(const CTime& t):s(t.s), m(t.m), h(t.h){}
CTime::~CTime() {
    this->h = 0;
    this->m = 0;
    this->s = 0;
}
void CTime::SetH(int h) {
    this->h = h;
}
void CTime::SetM(int m) {
    this->h = m;
}
void CTime::SetS(int s) {
    this->s = s;
}
void CTime::Sett(int s, int m, int h) {
    this->h = h;
    this->m = m;
    this->s = s;
}
int CTime::GetH() {
    return h;
}
int CTime::GetM() {
    return m;
}
int CTime::GetS() {
    return s;
}
bool CTime::Kiemtra() const {
    if (s < 0 || s >= 60)
        return 0;
    if (m < 0 || m >= 60)
        return 0;
    if (s < 0)
        return 0;
    return 1;
}

void CTime::QuyDoi() {
    if (s < 0) {
        s = 60 + s;
        m = m - 1;
    }
    else if (s >= 60) {
        m += (s / 60);
        s %= 60;
    }
    if (m < 0) {
        m = 60 + m;
        h = h - 1;
    }
    else if (m >= 60) {
        h += (m / 60);
        m %= 60;
    }
}
istream& operator >> (istream& is, CTime& t)
{
    do {
        cout << "Gio: ";
        is >> t.h;
        cout << "Phut: ";
        is >> t.m;
        cout << "Giay: ";
        is >> t.s;
    } while (!t.Kiemtra());
    return is;
}
ostream& operator << (ostream& os, const CTime& t)
{
    os << t.h << " gio " << t.m << " phut " << t.s << " giay ";
    return os;
}
CTime operator + (const CTime& t, int r)
{
    CTime t1;
    t1.s = t.h * 3600 + t.m * 60 + t.s + r;
    while (!t1.Kiemtra())
        t1.QuyDoi();
    return t1;
}
CTime operator - (const CTime& t, int r)
{
    CTime t1;
    t1.s = t.h * 3600 + t.m * 60 + t.s - r;
    while (!t1.Kiemtra())
        t1.QuyDoi();
    return t1;
}

CTime CTime::operator++() {
    return CTime(s + 1, m, h);
}
CTime CTime::operator--() {
    return CTime(s - 1, m, h);
}

CTime operator - (const CTime& t1, const CTime& t2){
    CTime t;
    t.s = abs((t1.h * 3600 + t1.m * 60 + t1.s) - (t2.h * 3600 + t2.m * 60 + t2.s));
    while (!t.Kiemtra())
        t.QuyDoi();
    return t;
}
//bool operator<= (const CTime& t1, const CTime& t2) {
//    if (t1.h > t2.h) return false;
//    if (t1.m > t2.m) return false;
//    if (t1.s > t2.s) return false;
//    return false;
//}
int main() {
    CTime t, t1, t3;
    int choice;
    int x;
    do {
        cout << "----------------CTime----------------" << endl;
        cout << "1. Nhap thoi gian " << endl;
        cout << "2. Xuat thoi gian" << endl;
        cout << "3. Cong 1 so nguyen giay " << endl;
        cout << "4. Tru 1 so nguyen giay " << endl;
        cout << "5. Tru 2 CTime " << endl;
        cout << "6. Sau 1 giay" << endl;
        cout << "7. Truoc 1 giay" << endl;
        cout << "0. Thoat." << endl;
        cout << "--------------------------------------" << endl;
        cout << "Ban chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap thoi gian: \n";
            cin >> t;
            break;
        case 2:
            cout << t;
            break;
        case 3:
            cout << t << endl << endl;
            cout << "Nhap so giay muon tang them: ";
            cin >> x;
            t3 = t + x;
            cout << "Sau khi tang: " << t3 << endl;
            break;
        case 4:
            cout << t << endl << endl;
            cout << "Nhap so giay muon giam bot: ";
            cin >> x;
            t3 = t - x;
            cout << "Sau khi giam: " << t3 << endl;
            break;
        case 5:
            cout << "Nhap thoi gian thu 2: \n";
            cin >> t1;
            cout << "\n\nThoi gian thu 1: " << t << endl;
            cout << "Thoi gian thu 2: " << t1 << endl;
            t3 = t1 - t;
            cout << "\nThoi gian I cach thoi gian II: " << t3 << endl;
            break;
        case 6:
            t3 = ++t;
            cout << t3;
            break;
        case 7:
            t3 = --t;
            cout << t3;
            break;
        case 0:
            cout << "Dang thoat chuong trinh...\n";
            break;
        default:
            cout << "Ban chon sai!!!\n";
            break;
        }
        cout << endl;
        system("pause");
        system("cls");
    } while (choice != 0);
    return 0;
}
