#include <iostream>
#include <string>
using namespace std;

typedef class CString {
private:
	string str;
	const string sp = " ";
public:
	CString();
	~CString();

	friend ostream& operator<<(ostream& os, const CString&);
	friend istream& operator>>(istream& is, CString&);

	friend CString operator+(const CString&, const CString&);

	CString& operator=(const CString&);
	friend bool operator<(const CString&, const CString&);
	friend bool operator<=(const CString&, const CString&);
	friend bool operator>(const CString&, const CString&);
	friend bool operator>=(const CString&, const CString&);
	friend bool operator==(const CString&, const CString&);
	friend bool operator!=(const CString&, const CString&);

}CS;

CS::CString() {
}

CS::~CString() {
}

ostream& operator<<(ostream& os, const CS& s)
{
	os << s.str;
	return os;
}
istream& operator>>(istream& is, CS& s)
{
	getline(is, s.str);
	return is;
}
CS operator+(const CS& s1, const CS& s2)
{
	CS s;
	s.str = s1.str + s1.sp + s2.str;
	return s;
}
CString& CS::operator=(const CS& s)
{
	str = s.str;
	return *this;
}
bool operator<(const CS& s1, const CS& s2)
{
	return (s1.str < s2.str);
}
bool operator<=(const CS& s1, const CS& s2)
{
	return (s1.str <= s2.str);
}
bool operator>(const CS& s1, const CS& s2)
{
	return (s1.str > s2.str);
}
bool operator>=(const CS& s1, const CS& s2)
{
	return (s1.str >= s2.str);
}
bool operator!=(const CS& s1, const CS& s2)
{
	return (s1.str != s2.str);
}
bool operator==(const CS& s1, const CS& s2)
{
	return (s1.str == s2.str);
}

int main() {
	CS str1, str2, str3;
	int choice;
	do {
		cout << "-------------CHUONG TRINH XU LY CHUOI-------------\n";
		cout << "\t1. Nhap chuoi\n";
		cout << "\t2. Xuat chuoi\n";
		cout << "\t3. So sanh 2 chuoi\n";
		cout << "\t4. Gan chuoi\n";
		cout << "\t5. Cong 2 chuoi\n";
		cout << "\t0. Thoat chuong trinh\n";
		cout << "-------------------------------------------------------\n";
		cout << "Ban chon: ";
		cin >> choice;
		switch (choice) {
		case 0: 
			cout << "Dang thoat chuong trinh...\n";
			break;
		case 1: 
			cin.ignore();
			cout << "Nhap chuoi 1: ";
			cin >> str1;
			cout << "Nhap chuoi 2: ";
			cin >> str2;
			break;
		case 2: 
			cout << "Chuoi thu 1: ";
			cout << str1 << endl;
			cout << "Chuoi thu 2: ";
			cout << str2 << endl;
			break;
		case 3: 
			if (str1 != str2)
				cout << "Hai chuoi khac nhau.\n";
			if (str1 > str2)
				cout << "Chuoi 1 lon hon chuoi 2.\n";
			if (str1 < str2)
				cout << "Chuoi 1 nho hon chuoi 2.\n";
			if (str1 == str2)
				cout << "Hai chuoi bang nhau.\n";
			if (str1 >= str2)
				cout << "Chuoi 1 lon hon bang chuoi 2.\n";
			if (str1 <= str2)
				cout << "Chuoi 1 nho hon bang chuoi 2.\n";
			break;
		case 4: 
			cout << "Gan chuoi 1 cho chuoi 2: \n";
			str3 = str2;
			str2 = str1;
			cout << "Chuoi 1: " << str1 << endl;
			cout << "Chuoi 2: " << str2;
			str2 = str3;
			str3.~CString();
			break;
		case 5: 
			str3 = str1 + str2;
			cout << "Chuoi 1: " << str1 << endl;
			cout << "Chuoi 2: " << str2 << endl;
			cout << "2 chuoi sau khi cong la: ";
			cout << str3 << endl;
			break;
		default:
			cout << "Lua chon khong hop le!\n";
			break;
		}		
		cout << endl;
		system("pause");
		system("cls");
	} while (choice != 0);
	return 0;
}
