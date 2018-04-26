#include <stdio.h>
#include <wchar.h>
#include <fcntl.h>
#include <io.h>
#include<string.h>;
#pragma warning(disable:4996)
struct SinhVien
{
	wchar_t MSSV[11];
	wchar_t HoTen[30];
	wchar_t Email[100];
	wchar_t Khoa[31];
	int KhoaHoc;
	wchar_t NgaySinh[11];
	wchar_t Hinh[30];
	wchar_t MoTa[1000];
	wchar_t sothich1[1000];
	wchar_t sothich2[1000];
};
int DemDong(FILE* fp)
{
	int dem = 0;
	wchar_t c[1000];
	for (int i = 1; i > 0; i++)
	{
		if (fwscanf(fp, L"%[^\n]\n", c) != EOF)
		{
			dem++;
		}
		else return dem;
	}
}
void DichConTro(FILE* fp, wchar_t c)
{
	long dem = 0;
	wchar_t ct;
	
	fseek(fp, -1L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	fseek(fp, -2L, SEEK_CUR);
	if (fgetwc(fp) == c)
	{
		fseek(fp, -2L, SEEK_CUR);
		return;
	}
	fseek(fp, 1L, SEEK_CUR);
	for (int i = 0; i >= 0; i++)
	{
		ct = fgetwc(fp);
		if (ct == c)
		{
			fseek(fp, -dem, SEEK_CUR);
			break;
		}
		else
		{
			dem++;
			fseek(fp, -dem, SEEK_CUR);
		}
	}
}
void DocFileCSV(FILE* fp, SinhVien &a, int& sosothich)
{
	wchar_t h[1000];
	wchar_t k[1000];
	wchar_t c;
	int dem1 = 0;
	int dem2 = 0;
	sosothich = 0;
	fgetwc(fp);
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.MSSV);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.MSSV);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.HoTen);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.HoTen);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.Email);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.Email);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.Khoa);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.Khoa);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%d", &a.KhoaHoc);
		fseek(fp, 2L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%d", &a.KhoaHoc);
		fseek(fp, 1L, SEEK_CUR);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.NgaySinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.NgaySinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.Hinh);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^,],", &a.Hinh);
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.MoTa);
		if (fgetwc(fp) == 44)
		{
			sosothich++;
		}
	}
	else
	{
		DichConTro(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			h[i] = fgetwc(fp);
			if (h[i] == 44 || h[i] == 10)
			{
				if (h[i] == 44)
				{
					h[i] = '\0';
					sosothich++;
					break;
				}
				if (h[i] == 10)
				{
					h[i] = '\0';
					break;
				}
			}
			dem1++;
		}
		for (int i = 0; i <= dem1; i++)
		{
			a.MoTa[i] = h[i];
		}
	}

	if (sosothich == 0)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich1);
		if (fgetwc(fp) == 44)
		{
			sosothich++;
		}
	}
	else
	{
		DichConTro(fp, c);
		for (int i = 0; i >= 0; i++)
		{
			k[i] = fgetwc(fp);
			if (k[i] == 44 || k[i] == 10)
			{
				if (k[i] == 44)
				{
					k[i] = '\0';
					sosothich++;
					break;
				}
				if (k[i] == 10)
				{
					k[i] = '\0';
					break;
				}
			}
			dem2++;
		}
		for (int i = 0; i <= dem2; i++)
		{
			a.sothich1[i] = k[i];
		}
	}
	if (sosothich == 1)
	{
		fseek(fp, -1L, SEEK_CUR);
		return;
	}
	c = fgetwc(fp);
	if (c == 34)
	{
		fwscanf(fp, L"%[^\"]\"", &a.sothich2);
		fseek(fp, 1L, SEEK_CUR);
	}
	else
	{
		DichConTro(fp, c);
		fwscanf(fp, L"%[^\n]", &a.sothich2);
	}
}
void XuatFileHTML(SinhVien* a, int i, int* sothich)
{
	wchar_t b[50];
	wchar_t c[] = L".htm";
	wcscpy(b, a[i].MSSV);
	wcscat(b, c);
	FILE* x = _wfopen(b, L"w, ccs= UTF-8");
	if (x != NULL)
	{
		fwprintf(x, L"<!DOCTYPE html PUBLIC \" -//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(x, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(x, L"	<head>\n");
		fwprintf(x, L"		<meta http-equiv=\"Content - Type\" content=\"text/html; charset = utf - 8\" />\n");
		fwprintf(x, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(x, L"		<title>HCMUS - %ls</title>\n", a[i].HoTen);
		fwprintf(x, L"	</head>\n");
		fwprintf(x, L"	<body>\n");
		fwprintf(x, L"		<div class=\"Layout_container\">\n");
		fwprintf(x, L"			<!-- Begin Layout Banner Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_Banner\" >\n");
		fwprintf(x, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(x, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC Khoa HỌC TỰ NHIÊN </div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Banner Region -->\n");
		fwprintf(x, L"			<!-- Begin Layout MainContents Region -->\n");
		fwprintf(x, L"			<div class=\"Layout_MainContents\">\n");
		fwprintf(x, L"				<!-- Begin Below Banner Region -->\n");
		fwprintf(x, L"				<div class=\"Personal_Main_Information\">\n");
		fwprintf(x, L"					<!-- Begin Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_Location\">\n");
		fwprintf(x, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(x, L"						<span class=\"Personal_FullName\">%ls - %s</span>\n", a[i].HoTen, a[i].MSSV);
		fwprintf(x, L"						<div class=\"Personal_Department\">Khoa %ls</div>\n", a[i].Khoa);
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<div class=\"Personal_Phone\">\n");
		fwprintf(x, L"							Email: %ls\n", a[i].Email);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"						<br />\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"					<!-- End Thông tin cá nhân c?a th?y cô ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(x, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(x, L"						<img src=\"%s\" class=\"Personal_Hinhcanhan\" />\n", a[i].Hinh);
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"				<!-- End Below Banner Region -->\n");
		fwprintf(x, L"				<!-- Begin MainContents Region -->\n");
		fwprintf(x, L"				<div class=\"MainContain\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					<!-- Begin Top Region -->\n");
		fwprintf(x, L"					<div class=\"MainContain_Top\">\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							 <ul class=\"TextInList\">\n");
		fwprintf(x, L"								<li>Họ và tên: %ls</li>\n", a[i].HoTen);
		fwprintf(x, L"								<li>MSSV: %ls</li>\n", a[i].MSSV);
		fwprintf(x, L"								<li>Sinh viên Khoa %ls</li>\n", a[i].Khoa);
		fwprintf(x, L"								<li>Ngày sinh: %ls</li>\n", a[i].NgaySinh);
		fwprintf(x, L"								<li>Email: %ls</li>\n", a[i].Email);
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(x, L"						<div>\n");
		fwprintf(x, L"							<ul class=\"TextInList\">\n");
		if (sothich[i] == 0)
		{
			fwprintf(x, L"								<li>Không có.\n</li>\n");
		}
		if (sothich[i] == 1)
		{
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
		}
		else if (sothich[i] == 2)
		{

			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich1);
			fwprintf(x, L"								<li>%ls</li>\n", a[i].sothich2);
		}
		fwprintf(x, L"							</ul>\n");
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
		fwprintf(x, L"						<div class=\"Description\">\n");
		fwprintf(x, L"							%ls.\n", a[i].MoTa);
		fwprintf(x, L"						</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"					</div>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"\n");
		fwprintf(x, L"			<!-- Begin Layout Footer -->\n");
		fwprintf(x, L"			<div class=\"Layout_Footer\">\n");
		fwprintf(x, L"				<div class=\"divCopyright\">\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(x, L"					<br />\n");
		fwprintf(x, L"					@2018</br>\n");
		fwprintf(x, L"					Đồ án giữa kỳ</br>\n");
		fwprintf(x, L"				Kỹ thuật lập trình</br>\n");
		fwprintf(x, L"				TH2018/04</br>\n");
		fwprintf(x, L"				1712903 - Nguyễn Ngọc Viên</br>\n");
		fwprintf(x, L"				</div>\n");
		fwprintf(x, L"			</div>\n");
		fwprintf(x, L"			<!-- End Layout Footer -->\n");
		fwprintf(x, L"		</div>\n");
		fwprintf(x, L"	</body>\n");
		fwprintf(x, L"</html>\n");
		fwprintf(x, L"\n");
		wprintf(L" ->Tạo file %ls (sinh viên thứ %d) thành công.\n", b, i + 1);
	}
	fclose(x);
}

void XuatThongTin(SinhVien* b, int n, int* sothich)
{

	wprintf(L"---------Thông tin sinh viên %d---------\n", n);
	wprintf(L"Mã số sinh viên: %ls\n", b[n - 1].MSSV);
	wprintf(L"Họ và tên: %ls\n", b[n - 1].HoTen);
	wprintf(L"Sinh viên Khoa: %ls\n", b[n - 1].Khoa);
	wprintf(L"Khóa học: %d\n", b[n - 1].KhoaHoc);
	wprintf(L"Ngày sinh: %ls\n", b[n - 1].NgaySinh);
	wprintf(L"Link hình ảnh: %ls\n", b[n - 1].Hinh);
	wprintf(L"Mô tả: %ls\n", b[n - 1].MoTa);
	wprintf(L"Email: %ls\n", b[n - 1].Email);
	if (sothich[n - 1] == 0)
	{
		wprintf(L"Sở thích 1: không có.\n");
		wprintf(L"Sở thích 2: không có.\n");
	}
	if (sothich[n - 1] == 1)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: không có.\n");
	}
	if (sothich[n - 1] == 2)
	{
		wprintf(L"Sở thích 1: %ls\n", b[n - 1].sothich1);
		wprintf(L"Sở thích 2: %ls\n", b[n - 1].sothich2);
	}
	wprintf(L"---------------------------------------\n");
}
void tuychonxuat(SinhVien* a, int sodong, int& n, int* sothich)
{
	wprintf(L"Nhập số thứ tự sinh viên cần xuất profile page, nhập 0 để xuất tất cả, nhập -1 để thoát: ");
	do
	{
		wscanf(L"%d", &n);
		if (n<-1 || n>sodong)
		{
			wprintf(L"Nhập không hợp lệ, vui lòng nhập lại: ");
			continue;
		}
		if (n == 0)
		{
			for (int i = 0; i < sodong; i++)
			{
				XuatFileHTML(a, i, sothich);
			}
			wprintf(L"Vui lòng nhập tiếp tùy chọn: ");
			continue;
		}
		if (n == -1)
		{
			return;
		}
		XuatFileHTML(a, n - 1, sothich);
		wprintf(L"Vui lòng nhập tiếp tùy chọn: ");
	} while (1);
}
void main()
{

	_setmode(_fileno(stdout), _O_U16TEXT);
	SinhVien a;
	SinhVien *t = NULL;
	int* sothich = NULL;
	int sosothich;
	FILE* fp = _wfopen(L"information.csv", L"rt, ccs= UTF-8");
	if (fp == NULL)
	{
		wprintf(L"Không thể mở tệp csv\n");
		return;
	}
	int n = DemDong(fp);
	t = new SinhVien[n];
	sothich = new int[n];
	rewind(fp);
	for (int i = 1; i <= n; i++)
	{
		sosothich = 0;
		DocFileCSV(fp, a, sosothich);
		t[i - 1] = a;
		sothich[i - 1] = sosothich;

	}
	for (int i = 1; i <= n; i++)
	{
		XuatThongTin(t, i, sothich);
	}
	wprintf(L"---------------------------------------\n");
	int p;
	tuychonxuat(t, n, p, sothich);
	delete[]t;
	delete[]sothich;
	fclose(fp);

}