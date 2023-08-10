//����� ��α� : https://mingyu0403.tistory.com/218
//�ܼ�â�� ����ֵ��� ����
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include "CWindow.h"

#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#endif
{
	// Window �и��� �� �θ���
	if (CWindow::InitializeWindow(hInstance, 1600, 900, L"����D3D ����") == false)
	{
		exit(-1);
	}

	// �޽��� ó�� ����
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		// GetMessage(&msg, hwnd, 0, 0);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// �츮�� ��.
			// �׸��� (DirectX 11).
		}
	}
}