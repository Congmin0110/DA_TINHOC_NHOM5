#define _CRT_SECURE_NO_WARNINGS
#include"thongtinbosung.h"
#include"thongtincanhan.h"
#include"thongtinhoctap.h"
#include"thongtinlienhe.h"
using namespace std;
struct SinhVien {
	ThongTinCaNhan thongtincanhan;
	ThongTinHocTap thongtinhoctap;
	ThongTinLienHe thongtinlienhe;
	ThongTinBoSung thongtinbosung;
};
void hienthiMenu();
void themsinhvien();
void hienthidanhsachsinhvien();
void capnhatds();
void xoasinhvien();
void timKiemSinhVien();
void sapXepSinhVien();
void thongKeSinhVien();
void luuFileCSV(const string& tenFile);
void docFileCSV(const string& tenFile);