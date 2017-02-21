#include <iostream>
#include <string>
#include <Windows.h>
#include <WinUser.h>

void invert();
void tunnel();
const int w = GetSystemMetrics(SM_CXSCREEN),
h = GetSystemMetrics(SM_CYSCREEN);
HDC hdcDesktop;


DWORD dwRasterOperationCode;



int main() {

	FreeConsole();
	while (true) {
		int num = rand() % 1000 + 100;
		invert();
		tunnel();
		Sleep(num);
		tunnel();
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
void tunnel() {
		int num1 = rand() % -100 + 100;
		int num2 = rand() % -100 + 100;
	    hdcDesktop = GetDC(0);
		StretchBlt(
			hdcDesktop, 
			50+num1, 
			50+num2, 
			w+num1, 
			h+num2, 
			hdcDesktop, 
			0, 
			0, 
			w, 
			h, 
			SRCCOPY);
}