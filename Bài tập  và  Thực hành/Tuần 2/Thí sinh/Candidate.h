#pragma once
#ifndef _thisinh

#include <iostream>
#include <string>
using namespace std;
#define MAX 40000
class Candidate
{
private:
    string Ma, Ten;
    int d, m, y;
    float Diem_Toan, Diem_Van, Diem_Anh;

public:

    ~Candidate();
    Candidate(string = "", string = " ", int =1, int =1, int =2000, float = 0, float = 0, float = 0);
    string GetMa();
    string GetTen();
    int SetD();
    int SetM();
    int SetY();
    float GetDT();
    float GetDV();
    float GetDA();
    void SetMa(string);
    void SetTen(string);
    void GetD(int);
    void GetM(int);
    void GetY(int);
    void SetDT(float);
    void SetDV(float);
    void SetDA(float);
    void SetCandidate(string, string, int, int, int, float, float, float);

    void Nhap();
    void Xuat() const;
    float TinhDiemTong() const;
    int KiemTraNgayThangHopLe() const;

    
};
#endif // !_thisinh
