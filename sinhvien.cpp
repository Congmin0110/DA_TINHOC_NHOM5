﻿#include"sinhvien.h"
#include<iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<iomanip>
vector<SinhVien>danhsachsinhvien;
bool ktra_trung(const string& mssv)
{
	for (const auto& sv : danhsachsinhvien)
	{
		if (sv.thongtincanhan.masv == mssv)
		{

			return true;
		}
	}
	return false;
}
void themsinhvien()
{
	SinhVien sv;
	
	cout << "\n Nhap ma sinh vien.";
	getline(cin, sv.thongtincanhan.masv);
	cout << "\n Nhap ho ten. ";
	getline(cin, sv.thongtincanhan.hoten);
	cout << "Nhap gioi tinh. ";
	getline(cin, sv.thongtincanhan.gioitinh);
	cout << "Nhap ngay thang nam sinh (DD/MM/YYYY) ";
	getline(cin, sv.thongtincanhan.ngaysinh);
	cout << "Nhap dia chi. ";
	getline(cin, sv.thongtincanhan.diachi);
	cout << "Nhap ma lop. ";
	getline(cin, sv.thongtinhoctap.malop);
	cout << "Nhap khoa. ";
	getline(cin, sv.thongtinhoctap.khoa);
	cout << "Nhap chuyen nganh. ";
	getline(cin, sv.thongtinhoctap.chuyennganh);
	cout << "Nhap diem GPA. ";
	cin >> sv.thongtinhoctap.diemGPA;
	cin.ignore();
	cout << "Nhap trang thai hoc tap. ";
	getline(cin, sv.thongtinhoctap.trangthai);
	cout << "Nhap so tin chi da hoan thanh. ";
	cin >> sv.thongtinhoctap.soTinChiHoanThanh;
	cin.ignore();
	cout << "Nhap gmail. ";
	getline(cin, sv.thongtinlienhe.gmail);
	cout << "Nhap so dien thoai. ";
	getline(cin, sv.thongtinlienhe.sodienthoai);
	cout << "Nhap hoc bong (neu co). ";
	getline(cin, sv.thongtinbosung.hocbong);
	cout << "Nhap hoat dong ngoai khoa(neu co). ";
	getline(cin, sv.thongtinbosung.hoatdong);
	danhsachsinhvien.push_back(sv);
	cout << "Them sinh vien thanh cong!!!";
}
void capnhatds()
{
	string masv;
	cout << "\n Nhap ma so sinh vien can cap nhat:";
	getline(cin, masv);
	for (auto& sv : danhsachsinhvien)
	{
		if (sv.thongtincanhan.masv == masv)
		{
			cout << "Cap nhat thong tin moi sinh vien" << masv << ":\n";
			cout << "Nhap ho ten (cu: " << sv.thongtincanhan.hoten << "):";
			getline(cin, sv.thongtincanhan.hoten);
			cout << "Nhap gioi tinh(cu: " << sv.thongtincanhan.gioitinh << "):";
			getline(cin, sv.thongtincanhan.gioitinh);
			cout << "Nhap ngay tinh(cu " << sv.thongtincanhan.ngaysinh << "):";
			getline(cin, sv.thongtincanhan.ngaysinh);
			cout << "Nhap dia chi (cu " << sv.thongtincanhan.diachi << "):";
			getline(cin, sv.thongtincanhan.diachi);
			cout << "Nhap diem (cu " << sv.thongtinhoctap.diemGPA << "):";
			cin >> sv.thongtinhoctap.diemGPA;
			cin.ignore();
			cout << "Cap nhat thanh cong!\n ";
			return;
		}
	}
}
void xoasinhvien()
{
	string masv;
	cout << " Nhap ma sinh vien can xoa: ";
	getline(cin, masv);
	auto it = remove_if(danhsachsinhvien.begin(), danhsachsinhvien.end(), [&](const SinhVien& sv)
		{
			return sv.thongtincanhan.masv == masv;
		});
	if (it != danhsachsinhvien.end())
	{
		danhsachsinhvien.erase(it, danhsachsinhvien.end());
		cout << "Xoa sinh vien thanh cong!\n";
	}
	else
	{
		cout << "Khong tim thay ma sinh vien.";
	}
}

void timKiemSinhVien() {
	int luaChon;
	cout << "Tim kiem theo:\n";
	cout << "1. Ma sinh vien\n";
	cout << "2. Ten sinh vien\n";
	cout << "Nhap lua chon: ";
	cin >> luaChon;
	cin.ignore();

	if (luaChon == 1) {
		string maSinhVien;
		cout << "Nhap ma sinh vien: ";
		getline(cin, maSinhVien);

		auto it = find_if(danhsachsinhvien.begin(), danhsachsinhvien.end(),
			[&](const SinhVien& sv) { return sv.thongtincanhan.masv == maSinhVien; });

		if (it != danhsachsinhvien.end()) {
			cout << "Thong tin sinh vien:\n";
			cout << "Ho ten: " << it->thongtincanhan.hoten << "\n";
			cout << "GPA: " << it->thongtinhoctap.diemGPA << "\n";
		}
		else {
			cout << "Khong tim thay sinh vien.\n";
		}
	}
	else if (luaChon == 2) {
		string tenSinhVien;
		cout << "Nhap ten sinh vien: ";
		getline(std::cin, tenSinhVien);

		bool found = false;
		for (const auto& sv : danhsachsinhvien) {
			if (sv.thongtincanhan.hoten.find(tenSinhVien) != std::string::npos) {
				cout << "MSSV: " << sv.thongtincanhan.masv << " - Họ tên: " << sv.thongtincanhan.hoten << "\n";
				found = true;
			}
		}

		if (!found) {
			cout << "Khong tim thay sinh vien.\n";
		}
	}
	else {
	cout << "Lua chon khong hop le.\n";
	}
}
void sapXepSinhVien() {
	int luaChon;
	cout << "\n=== Sap xep sinh vien ===\n";
	cout << "1. Theo ma sinh vien(tang dan)\n";
	cout << "2. Theo ten (A-Z)\n";
	cout << "3. Theo GPA (cao xuong thap)\n";
	cout << "Nhap lua chon: ";
	cin >> luaChon;
	cin.ignore();

	if (luaChon == 1) {
		sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), [](const SinhVien& a, const SinhVien& b) {
			return a.thongtincanhan.masv < b.thongtincanhan.masv;
			});
	}
	else if (luaChon == 2) {
		sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), [](const SinhVien& a, const SinhVien& b) {
			return a.thongtincanhan.hoten < b.thongtincanhan.hoten;
			});
	}
	else if (luaChon == 3) {
		sort(danhsachsinhvien.begin(), danhsachsinhvien.end(), [](const SinhVien& a, const SinhVien& b) {
			return a.thongtinhoctap.diemGPA > b.thongtinhoctap.diemGPA;
			});
	}
	else {
		std::cout << "Lua chon hop le.\n";
		return;
	}

	std::cout << "Sap xep thanh cong.\n";
}
void thongKeSinhVien() {
	int tongSoSinhVien = danhsachsinhvien.size();
	int soNam = 0, soNu = 0;
	double gpaMax = -1.0, gpaMin = 11.0;

	for (const auto& sv : danhsachsinhvien) {
		if (sv.thongtincanhan.gioitinh == "Nam") soNam++;
		else if (sv.thongtincanhan.gioitinh == "Nu") soNu++;

		gpaMax = max(gpaMax, sv.thongtinhoctap.diemGPA);
		gpaMin = min(gpaMin, sv.thongtinhoctap.diemGPA);
	}

	cout << "\n=== Thong ke sinh vien ===\n";
	cout << "Tong so sinh vien: " << tongSoSinhVien << "\n";
	cout << "So luong sinh vien Nam: " << soNam << "\n";
	cout << "So luong sinh vien nu: " << soNu << "\n";
	cout << "GPA cao nhat: " << gpaMax << "\n";
	cout << "GPA thap nhat: " << gpaMin << "\n";
}
void luuFileCSV(const std::string& tenFile) {
	ofstream file(tenFile);
	if (!file) {
		std::cout << "Khong the mo file da ghi.\n";
		return;
	}

	for (const auto& sv : danhsachsinhvien) {
		file << sv.thongtincanhan.masv << ","
			<< sv.thongtincanhan.hoten << ","
			<< sv.thongtincanhan.gioitinh << ","
			<< sv.thongtincanhan.ngaysinh << ","
			<< sv.thongtincanhan.diachi << ","
			<< sv.thongtinhoctap.malop << ","
			<< sv.thongtinhoctap.khoa << ","
			<< sv.thongtinhoctap.chuyennganh << ","
			<< sv.thongtinhoctap.diemGPA << ","
			<< sv.thongtinhoctap.trangthai << ","
			<< sv.thongtinhoctap.soTinChiHoanThanh << ","
			<< sv.thongtinlienhe.gmail << ","
			<< sv.thongtinlienhe.sodienthoai << ","
			<< sv.thongtinbosung.hocbong << ","
			<< sv.thongtinbosung.hoatdong << "\n";
	}

	file.close();
	cout << "Du lieu duoc luu vao file " << tenFile << ".\n";
}
void docFileCSV(const string& tenFile) {
	ifstream file(tenFile);
	if (!file) {
		cout << "Khong the mo file de doc.\n";
		return;
	}

	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		SinhVien sv;

		getline(ss, sv.thongtincanhan.masv, ',');
		getline(ss, sv.thongtincanhan.hoten, ',');
		getline(ss, sv.thongtincanhan.gioitinh, ',');
		getline(ss, sv.thongtincanhan.ngaysinh, ',');
		getline(ss, sv.thongtincanhan.diachi, ',');
		getline(ss, sv.thongtinhoctap.malop, ',');
		getline(ss, sv.thongtinhoctap.khoa, ',');
		getline(ss, sv.thongtinhoctap.chuyennganh, ',');
		ss >> sv.thongtinhoctap.diemGPA;
		ss.ignore();
		getline(ss, sv.thongtinhoctap.trangthai, ',');
		ss >> sv.thongtinhoctap.soTinChiHoanThanh;
		ss.ignore();
		getline(ss, sv.thongtinlienhe.gmail, ',');
		getline(ss, sv.thongtinlienhe.sodienthoai, ',');
		getline(ss, sv.thongtinbosung.hocbong, ',');
		getline(ss, sv.thongtinbosung.hoatdong);

		danhsachsinhvien.push_back(sv);
	}

	file.close();
	std::cout << "Dữ liệu đã được đọc từ file " << tenFile << ".\n";
}
void hienthidanhsachsinhvien()
{
	if (danhsachsinhvien.empty())
	{
		cout << "\n Danh sach sinh vien rong!!";
		return;
	}
	cout << setw(10) << " MSSV: "
		<< setw(20) << " Ho va Ten:"
		<< setw(10) << " Gioi tinh: "
		<< setw(15) << " Ngay sinh: "
		<< setw(10) << " Diem GPA: "
		<< "\n";
	cout << string(70, '-') << "\n";
	for (const auto& sv : danhsachsinhvien)
	{
		cout <<setw(10) << sv.thongtincanhan.masv
			<< setw(20) << sv.thongtincanhan.hoten
			<< setw(10) << sv.thongtincanhan.gioitinh
			<< setw(15) << sv.thongtincanhan.ngaysinh
			<< setw(10) << sv.thongtinhoctap.diemGPA
			<< "\n";
	}
}

void hienthiMenu()
{ 
	int chon;
	do {
		
		cout << "\n=============QUAN LY SINH VIEN===============\n";
		cout << "\n 1. Them sinh vien";
		cout << "\n 2. Hien thi danh sach sinh vien.";
		cout << "\n 3. Cap nhat thong tin sinh vien.";
		cout << "\n 4. Xoa sinh vien.";
		cout << "\n 5. Tim kiem sinh vien.";
		cout << "\n 6. Sap xep danh sach sinh vien.";
		cout << "\n 7. Thong ke du lieu sinh vien.";
		cout << "\n 8. Luu danh sach sinh vien vao file.";
		cout << "\n 0. Thoat!!";
		cout << "\n             Moi ban chon!!";
		cout << "\n================================================\n";
		cin >> chon;
		switch (chon)
		{
		case 1:
			themsinhvien();
			break;
		case 2:
			hienthidanhsachsinhvien();
			break;
		case 3:
			capnhatds();
			break;
		case 4:
			xoasinhvien();
			break;
		case 5:
			timKiemSinhVien();
			break;
		case 6:
			sapXepSinhVien();
			break;
		case 7:
			thongKeSinhVien();
			break;
		case 8:
			luuFileCSV("sinhvien.csv");
			break;
		}
	} while (chon != 0);
}

int main()
{
	hienthiMenu();
	return 0;
}