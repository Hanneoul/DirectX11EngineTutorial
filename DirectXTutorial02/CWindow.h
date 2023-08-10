//���� ��α� : https://mingyu0403.tistory.com/218
#pragma once

#include <Windows.h>
#include <string> // STL - Standard Template Library.

class CWindow
{
public:
	static bool InitializeWindow();

	static bool InitializeWindow(
		HINSTANCE hInstance,
		int width,
		int height,
		std::wstring title
	);

	// Getter / Setter.
	static HWND WindowHandle() { return hwnd; }

	static HINSTANCE Instance() { return hInstance; }
	static void SetInstance(HINSTANCE hInstance);

	static int Width() { return width; }
	static void SetWidth(int width);

	static int Height() { return height; }
	static void SetHeight(int height);

	static std::wstring Title() { return title; }
	static void SetTitle(std::wstring title);


private:
	static int width;			// ���� ����.
	static int height;			// ���� ����.
	static std::wstring title;	// ������ ����(Ÿ��Ʋ). wide string �ѱ� ó������ ����������.
	static HWND hwnd;			// ������ �ڵ�.
	static HINSTANCE hInstance;	// ������ �ν��Ͻ�.
};