#pragma once
#include <iostream>
#include <math.h>
const double epsilon = 0.0000000001;


using namespace std;
#ifndef _Diem

class DIEM
{
private:
	double x, y;
	static int dem;
public:
	/*khai báo phương thức hủy (decontructor) (hàm hủy)=>phuong thức này sex được gọi tự động
	khi kết thúc hàm/chương trình. Phải khai báo và định nghĩa phương thức này nếu đối tượng
	có chứa thuộc tính kiểu con trỏ để giải phóng vùng nhớ động đã cấp phát. */
	~DIEM();

	/*khai báo có 3 phương thức khởi tạo tự động (contructor) (còn được gọi là hàm dựng, phương thức thiết lập)
	không có giá trị mặc định, dùng kĩ thuật nạp chồng hàm (function overloading) => sau khi khai báo biến đối tượng
	thuộc lớp DIEM thì các phương thức khởi tạo này tự động được dọi để gán giá trị tọa độ khởi động ban đầu. */
	//DIEM();
	//DIEM(double);
	//DIEM(double, double);

	/*có thể khai báo phương thức khởi tạo tự động (contruction) với giá trị mặc định thay thế cho 3 phương thức khởi tạo tự động trên*/
	DIEM(double = 0, double = 0);

	/*void KhoiTao();
	void KhoiTao(double);
	void KhoiTao(double , double );*/

	/*khai báo các phương thức cấp quyền đọc / ghi (get / set) giá trị cho các thuộc tính tọa độ*/
	double GetX() const;
	double GetY()const;
	static int GetDem() ;
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);

	/*khai báo 2 phương thức hỗ trợ nhập/xuất các thuộc tính tọa độ*/
	void Nhap();
	void Xuat() const;
	void DiChuyen(double, double);
	int KiemTraTrung(const DIEM&) const;//const dùng để bảo toàn dữ liệu
	double TinhKhoangCach(const DIEM&) const;
	DIEM TimDoiXung() const;
	bool KiemTraTamGiacHopLe(const DIEM&, const DIEM&) const;
	double TinhChuViTamGiac(const DIEM&, const DIEM&) const;
	double TinhDienTichTamGiac(const DIEM&, const DIEM&) const;
	string PhanLoaiTamGiac(const DIEM&, const DIEM&) const;
	friend istream& operator>>(istream&, DIEM&);
	friend ostream& operator<<(ostream&, const DIEM&);
};


#endif

