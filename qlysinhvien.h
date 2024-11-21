#pragma once

void tk_tt_ten(vector<sinhvien> d) {
	system("cls");
	ShowCur(true);
	string t;
	cout << "\n\t DANH SACH TIM DUOC ";
	khung_ds(2, 3);
	gotoXY(4, 4); cout << "Stt";
	gotoXY(8, 4); cout << "Ma lop";
	gotoXY(17, 4); cout << "Ma sv";
	gotoXY(30, 4); cout << "Ho va ten";
	gotoXY(49, 4); cout << "Ngay sinh";
	gotoXY(60, 4); cout << "DTBTL";
	gotoXY(80, 2); cout << "Tim kiem theo Ho ten";
	fflush(stdin);
	gotoXY(80, 3); cout << "Nhap vao ho ten can tim: ";
	ve_khung(80, 4);
	gotoXY(81, 5); getline(cin, t);
	int j = 0, n = d.size();
	for (int i = 0; i < n - 1; i++) {
		if (t == d[i].hoten || t == ten_c(d[i].hoten) || t == dem_c(d[i].hoten) || t == ho_c(d[i].hoten) || t == ten(d[i].hoten) || t == dem(d[i].hoten) || t == ho(d[i].hoten)) {
			khung_ds(2, 6 + 3 * j);
			gotoXY(5, 7 + 3 * j); cout << j + 1;
			gotoXY(9, 7 + 3 * j); cout << d[i].malop;
			gotoXY(16, 7 + 3 * j); cout << d[i].masv;
			gotoXY(25, 7 + 3 * j); cout << d[i].hoten;
			gotoXY(48, 7 + 3 * j); cout << d[i].ngaythang;
			gotoXY(62, 7 + 3 * j); cout << d[i].diemtb;
			j++;
		}
	}
	quay_lai(d);
}
