#include "CWindow.h"


int CWindow::width;
int CWindow::height;
std::wstring CWindow::title;
HWND CWindow::hwnd;
HINSTANCE CWindow::hInstance;

LRESULT CALLBACK WindowProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;

	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE)
		{
			if (MessageBox(
				NULL,
				TEXT("�����Ͻðڽ��ϱ�?"),
				TEXT("����"),
				MB_YESNO | MB_ICONQUESTION) == IDYES)
			{
				// â ����.
				DestroyWindow(hwnd);
			}
		}
	}
	return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool CWindow::InitializeWindow()
{
	return InitializeWindow(hInstance, width, height, title);
}

bool CWindow::InitializeWindow(
	HINSTANCE hInstance,
	int width,
	int height,
	std::wstring title)
{
	CWindow::hInstance = hInstance;
	CWindow::width = width;
	CWindow::height = height;
	CWindow::title = title;

	// ������ Ŭ���� ����.
	WNDCLASS wc;

	// ��� 0���� �ʱ�ȭ.
	ZeroMemory(&wc, sizeof(wc));

	// �ʿ��� ���� ����.
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("GraphicsEngine");
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;

	// ������ Ŭ���� ���.
	if (RegisterClass(&wc) == false)
	{
		exit(-1);
	}

	// �簢�� ����
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	CWindow::width = rect.right - rect.left;
	CWindow::height = rect.bottom - rect.top;

	// â ���� (�����).
	// â�� ���� ���� �����Ǹ� �ڵ� �� ��ȯ.
	hwnd = CreateWindow(
		wc.lpszClassName,
		title.c_str(),
		WS_OVERLAPPEDWINDOW,
		0, 0,
		CWindow::width, CWindow::height,
		NULL, NULL,
		hInstance,
		NULL
	);

	// ���� �˻�.
	if (hwnd == NULL)
	{
		exit(-1);
	}

	// â ���̱�.
	ShowWindow(hwnd, SW_SHOW); // â ����
	UpdateWindow(hwnd); // ������Ʈ�ؾ� ����. �� ������ ���ٰ� ���� ��.

	return true;
}

void CWindow::SetInstance(HINSTANCE hInstance)
{
	CWindow::hInstance = hInstance;
}

void CWindow::SetWidth(int width)
{
	CWindow::width = width;
}

void CWindow::SetHeight(int height)
{
	CWindow::height = height;
}

void CWindow::SetTitle(std::wstring title)
{
	CWindow::title = title;
}