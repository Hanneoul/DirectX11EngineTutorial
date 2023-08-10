#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <Windows.h>

// â�� �̺�Ʈ�� ó���ϴ� �Լ�.
// �ݹ�(Callback).
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	// �⺻ ó����. ������ ������ ������ ���� ó���ش޶�� ��.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#endif
{
	// ������ Ŭ���� ����.
	WNDCLASS wc;

	// ��� 0���� �ʱ�ȭ.
	ZeroMemory(&wc, sizeof(wc));

	// �ʿ��� ���� ���� (�ؿ��� �ٽ� ����.)
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("GraphicsEngine");
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;

		// ������ Ŭ���� ���.
		if (RegisterClass(&wc) == false) // ���� ���� ������ ��, �Ǽ����� ���� �����ϱ�.
		{
			exit(-1);
		}

	// â ���� (�����).
	// â�� ���� ���� �����Ǹ� �ڵ� �� ��ȯ.
	HWND hwnd = CreateWindow( // �Լ� �Ķ���͸� �� ���� Ctrl+Shift+Space ������ ����.
		wc.lpszClassName, // ����� Ŭ���� �̸����� ������ ������Ѵ�.
		TEXT("�׷��Ƚ� ����"),
		WS_OVERLAPPEDWINDOW,
		0, 0,
		1280, 800,
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

	

	// �޽��� ó�� ����.
// ���� ����.
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		// �޽��� ó��.
		// GetMessage(&msg, hwnd, 0, 0);
		if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) // PM_REMOVE�� �ڸ��� �� �޼����� ���� ��Ұų�.�� �ǹ��ε� ����ٴ� ����.
		{
			// �޽��� �ؼ�����.
			TranslateMessage(&msg);
			// �޽����� ó���ؾ��� ���� ��������.
			DispatchMessage(&msg);
		}
		else
		{
			// �츮�� ��.
			// �׸��� (DirectX 11).
		}
	}
}