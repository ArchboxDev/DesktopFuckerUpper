#include <iostream>
#include <string>
#include <Windows.h>
#include <WinUser.h>

void invert();
void scatter();
const int w = GetSystemMetrics(SM_CXSCREEN),
h = GetSystemMetrics(SM_CYSCREEN);
HDC hdcDesktop;


DWORD dwRasterOperationCode;



int main() {

	FreeConsole();
	while (true) {
		int num = rand() % 500 + 100;
		invert();
		scatter();
		Sleep(num);
		scatter();
		invert();
		Sleep(num);
	}
	return 0;
}

void invert() {
	hdcDesktop = GetDC(0);
	dwRasterOperationCode = NOTSRCCOPY;
	BitBlt(
		hdcDesktop,
		0,
		0,
		w,
		h,
		hdcDesktop,
		0,
		0,
		dwRasterOperationCode
	);
	ReleaseDC(0, hdcDesktop);
}
void scatter() {
		int num1 = rand() % -100 + 100;
		int num2 = rand() % -100 + 100;
		int num3 = rand() % -100 + 100;
		int num4 = rand() % -100 + 100;
	    hdcDesktop = GetDC(0);
		StretchBlt(
			hdcDesktop,
			50 + num1,
			50 + num2,
			w + num3,
			h + num4,
			hdcDesktop, 
			0, 
			0, 
			w, 
			h, 
			SRCCOPY);
}