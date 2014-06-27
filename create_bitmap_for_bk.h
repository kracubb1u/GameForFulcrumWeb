#ifndef _____
#define _____

#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

 
class KDib {

public:
	KDib();
	~KDib();
	 
	static void KDib::DrawBitmap(HDC hdc, int x, int y, HBITMAP &hBitmap);
	BOOL CreateDib24(int w, int h, const char* fileName);
	void StoreDib24();
	BOOL LoadFromFile(const char* fileName);
	void SetPixel(int x, int y, COLORREF color);
	int Draw(HDC hdc, int xDst, int yDst, int wDst, int hDst,
		int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop);
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	const char* GetError() { return error.c_str(); }
	SIZE SizeBitmap(HBITMAP hCaptureBitmapp);
private:	
	int width;
	int height;
	int bytesPerLine;
	BITMAPFILEHEADER fileHead;   // ��������� ���������� �����
	BITMAPINFOHEADER infoHead;   // ��������� ��������������� �����
	BITMAPINFOHEADER* pInfoHead;
	BYTE* aBitmapBits;           // ������ ��������
	int fileHeadSize;
	int infoHeadSize;
	int imageSize;
	string error;

	ifstream inpFile;
	ofstream outFile;
};



#endif