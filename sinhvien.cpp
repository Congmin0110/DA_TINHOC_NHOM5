#include"sinhvien.h"
#include<iostream>
#include <vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<iomanip>

vector<SinhVien>danhsachsinhvien;
using namespace std;

bool isValidDate(int day, int month, int year) {
	if (year < 1900 || year > 2100) return false;
	if (month < 1 || month > 12) return false;

	vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		daysInMonth[1] = 29;
	}

	return day >= 1 && day <= daysInMonth[month - 1];
}

string chuanHoaNgaySinh() {
	string ngaysinh;
	while (true) {
		cout << "Nhap ngay thang nam sinh (DD/MM/YYYY): ";
		getline(cin, ngaysinh);

		istringstream iss(ngaysinh);
		string dayStr, monthStr, yearStr;

		if (getline(iss, dayStr, '/') && getline(iss, monthStr, '/') && getline(iss, yearStr)) {
			try {
				int day = stoi(dayStr);
				int month = stoi(monthStr);
				int year = stoi(yearStr);
				if (isValidDate(day, month, year)) {
				
					ostringstream oss;
					oss << setw(2) << setfill('0') << day << "/"
						<< setw(2) << setfill('0') << month << "/"
						<< year;
					return oss.str();
				}
				else {
					cout << "Ngay thang nam sinh khong hop le. Vui long nhap lai.\n";
				}
			}
			catch (...) {
				cout << "Dinh dang ngay thang nam khong hop le. Vui long nhap lai.\n";
			}
		}
		else {
			cout << "Dinh dang ngay thang nam khong hop le. Vui long nhap lai.\n";
		}
	}
}
string inhoa(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), toupper);
	return result;
}

bool ktratrungmasSV(const string& masv)
{
	for (const auto& sv : danhsachsinhvien) {
		if (sv.thongtincanhan.masv == masv) {
			return true;
		}
	}
	return false;
}
string vietHoaChuCaiDau(string str) {
	bool vietHoa = true;
	for (size_t i = 0; i < str.length(); ++i) {
		if (vietHoa && isalpha(str[i])) {
			str[i] = toupper(str[i]);
			vietHoa = false;
		}
		else {
			str[i] = tolower(str[i]);
		}
		if (str[i] == ' ') {
			vietHoa = true;
		}
	}
	return str;
}
string xepLoai(double gpa) {
	if (gpa >= 9.0) {
		return "Xuat sac";
	}
	else if (gpa >= 8.0) {
		return "Gioi";
	}
	else if (gpa >= 6.5) {
		return "Kha";
	}
	else if (gpa >= 5.0) {
		return "Trung binh";
	}
	else {
		return "Yeu";
	}
}
void themsinhvien()
{
	SinhVien sv;
	cout << "\nNhap thong tin sinh vien:\n";
	cin.ignore();
	while (true) {
		cout << "\n Nhap ma sinh vien:";
		getline(cin, sv.thongtincanhan.masv);
		if (ktratrungmasSV(sv.thongtincanhan.masv)) {
			cout << "\n Ma sinh vien trung vui long nhap lai!!!";
		}else
		{
			break;
		}
	}
	cout << "\n Nhap ho ten: ";
	getline(cin, sv.thongtincanhan.hoten);
	sv.thongtincanhan.hoten = vietHoaChuCaiDau(sv.thongtincanhan.hoten);
	cout << "Nhap gioi tinh(nam/nu): ";
	getline(cin, sv.thongtincanhan.gioitinh);
	sv.thongtincanhan.ngaysinh = chuanHoaNgaySinh();
	cout << "Nhap dia chi: ";
	getline(cin, sv.thongtincanhan.diachi);
	cout << "Nhap ma lop: ";
	getline(cin, sv.thongtinhoctap.malop);
	cout << "Nhap khoa: ";
	getline(cin, sv.thongtinhoctap.khoa);
	cout << "Nhap chuyen nganh: ";
	getline(cin, sv.thongtinhoctap.chuyennganh);
	cout << "Nhap diem GPA: ";
	cin >> sv.thongtinhoctap.diemGPA;
	cin.ignore();
	cout << "Nhap trang thai hoc tap(con/khong): ";
	getline(cin, sv.thongtinhoctap.trangthai);
	cout << "Nhap so tin chi da hoan thanh: ";
	cin >> sv.thongtinhoctap.soTinChiHoanThanh;
	cin.ignore();
	cout << "Nhap gmail: ";
	getline(cin, sv.thongtinlienhe.gmail);
	cout << "Nhap so dien thoai: ";
	getline(cin, sv.thongtinlienhe.sodienthoai);
	cout << "Nhap hoc bong (co/khong): ";
	getline(cin, sv.thongtinbosung.hocbong);
	cout << "Nhap hoat dong ngoai khoa (co/khong): ";
	getline(cin, sv.thongtinbosung.hoatdong);
	danhsachsinhvien.push_back(sv);
	cout << "Them sinh vien thanh cong!!!";
}
void capnhatds()
{
	string masv;
	cout << "\n Nhap ma so sinh vien can cap nhat:";
	cin.ignore();
	getline(cin, masv);
	bool found = false;
	for (auto& sv : danhsachsinhvien)
	{
		if (sv.thongtincanhan.masv == masv)
		{
			found = true;
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
	if (!found)
	{
		cout << "Khong tim thay ma so sinh vien!!!" << masv << ".\n";
	}
}
void xoasinhvien()
{
	string masv;
	cout << " Nhap ma sinh vien can xoa: ";
	cin.ignore();
	getline(cin, masv);
	auto it = remove_if(danhsachsinhvien.begin(), danhsachsinhvien.end(),
		[&](const SinhVien& sv) {
			return sv.thongtincanhan.masv == masv;
		});

	if (it != danhsachsinhvien.end()) {
		danhsachsinhvien.erase(it, danhsachsinhvien.end());
		cout << "Xoa sinh vien thanh cong!\n";
	}
	else {
		cout << "Khong tim thay ma sinh vien.\n";
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
		cout << "Lua chon hop le.\n";
		return;
	}

	cout << "Sap xep thanh cong.\n";
}
void thongKeSinhVien() {
	int tongSoSinhVien = danhsachsinhvien.size();
	int soNam = 0, soNu = 0;
	double gpaMax = -1.0, gpaMin = 11.0;

	for (const auto& sv : danhsachsinhvien) {
		if (sv.thongtincanhan.gioitinh == "nam") soNam++;
		else if (sv.thongtincanhan.gioitinh == "nu") soNu++;

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
void luuFileCSV(const string& tenFile) {
	ofstream file(tenFile);
	if (!file) {
		cout << "Khong the mo file da ghi.\n";
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
cout << "Du lieu da duoc doc tu file " << tenFile << ".\n";
}
void hienthidanhsachsinhvien() {
	if (danhsachsinhvien.empty()) {
		cout << "\nDanh sach sinh vien rong!!\n";
		return;
	}
	const int width_mssv = 15;
	const int width_hoten = 30;
	const int width_gioitinh = 15;
	const int width_ngaysinh = 20;
	const int width_diemgpa = 10;
	const int width_xeploai = 15;

	cout <<"+---------------------------------------------------------------------------------------------------------+\n";
	cout <<"| " << setw(width_mssv - 2) << left << "MSSV"
		<< "| " << setw(width_hoten - 2) << left << "Ho va Ten"
		<< "| " << setw(width_gioitinh - 2) << left << "Gioi tinh"
		<< "| " << setw(width_ngaysinh - 2) << left << "Ngay sinh"
		<< "| " << setw(width_diemgpa - 2) << left << "Diem GPA"
		<< "| " << setw(width_xeploai-2) << left<< "Xep loai"
		<< "|\n";
	cout << "+----------------------------------------------------------------------------------------------------------+\n";

	
	for (const auto& sv : danhsachsinhvien) {
		cout <<"| " << setw(width_mssv - 2) << left <<inhoa( sv.thongtincanhan.masv)
			<< "| " << setw(width_hoten - 2) << left << sv.thongtincanhan.hoten
			<< "| " << setw(width_gioitinh - 2) << left << sv.thongtincanhan.gioitinh
			<< "| " << setw(width_ngaysinh - 2) << left << sv.thongtincanhan.ngaysinh
			<< "| " << setw(width_diemgpa - 2) << fixed << setprecision(2) << sv.thongtinhoctap.diemGPA
			<< "| " << setw(width_xeploai-2) << left <<xepLoai(sv.thongtinhoctap.diemGPA)
			<< "|\n";
		cout << "+------------------------------------------------------------------------------------------------------+\n";
	}
}
void hienthiMenu()
{ 
	int chon;
	do {
		
		cout << "\n=============QUAN LY SINH VIEN==================\n";
		cout << "\n 1. Them sinh vien";
		cout << "\n 2. Hien thi danh sach sinh vien.";
		cout << "\n 3. Cap nhat thong tin sinh vien.";
		cout << "\n 4. Xoa sinh vien.";
		cout << "\n 5. Tim kiem sinh vien.";
		cout << "\n 6. Sap xep danh sach sinh vien.";
		cout << "\n 7. Thong ke du lieu sinh vien.";
		cout << "\n 8. Luu danh sach sinh vien vao file.";
		cout << "\n 9. Doc danh sach sinh vien vao file.";
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
		case 9:
			docFileCSV("sinhvien.csv");
		}
	} while (chon != 0);
}

int main()
{
	hienthiMenu();
	return 0;
}