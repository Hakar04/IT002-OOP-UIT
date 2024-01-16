#pragma once
#ifndef _thisinh
#include "Candidate.h"

class TestCandidate
{
private:
    Candidate* DanhSachThiSinh;
    int n;

public:

    void NhapDanhSachThiSinh();
    void IndsThiSinhTongDiemLonHon15() const;
};


#endif // !_thisinh
