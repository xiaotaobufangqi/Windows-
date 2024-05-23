//-----------------------------------------------------------
//    WinFramwork.cpp.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------
#include "WinFramwork.h"
#include <Windowsx.h> //windows¸¨Öú¿â

extern int frame_main(std::wstring const& params);

//-----------------------------------------------------------
//initialize static variable
//-----------------------------------------------------------
winframe::WinFramework* winframe::WinFramework::_ms_frame{nullptr};

HINSTANCE winframe::WinFramework::_ms_hinstance{nullptr};

WNDCLASSEX winframe::WinFramework::_ms_wcex{
	sizeof(_ms_wcex),
		CS_HREDRAW | CS_VREDRAW,
		& WndProcdure,
		0,
		0,
		_ms_hinstance,
		::LoadIcon(NULL, IDI_APPLICATION),
		::LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(GetStockObject(WHITE_BRUSH)),
		NULL,
		L"",
		_ms_wcex.hIcon};
//-----------------------------------------------------------
winframe::WinFramework::WinFramework(std::wstring name)
{
	_ms_frame = this;

	//define a window class.
	/*WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = &WndProcdure;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _ms_hinstance;
	wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = name.c_str();
	wcex.hIconSm = wcex.hIcon;*/
	_ms_wcex.lpszClassName = name.c_str();

	//create an instance of class
	if (!RegisterClassEx(&_ms_wcex))
		return;

	//kernel object.
	_hWnd = ::CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		name.c_str(),
		L"AppX",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		NULL, NULL, _ms_hinstance, NULL);
}

//-----------------------------------------------------------
bool winframe::WinFramework::show_window(void)
{
	if (!_hWnd)
		return false;

	if (!ShowWindow(_hWnd, SW_NORMAL))
		return false;
	return UpdateWindow(_hWnd);
}

//----------------------------------------------------------

void winframe::WinFramework::run(void)
{
	//Message Looping.
	MSG msg;
	while (::GetMessage(&msg, NULL, NULL, NULL))
	{
		//process messages.
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

//-----------------------------------------------------------
LRESULT winframe::WinFramework::WndProcdure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	bool result{ false };

	switch (uMsg)
	{
	case WM_CREATE:
	{
		result = _ms_frame->on_create(reinterpret_cast<CREATESTRUCT*>(lParam));
		if (result)
			return 1;
	}
	break;
	case WM_CLOSE:
	{
		::PostMessage(hWnd, WM_QUIT, wParam, lParam);
		return 1;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC = ::BeginPaint(hWnd, &ps);
		/*::Rectangle(hDC, 100, 100, 200, 200);*/
		result = _ms_frame->on_paint(hDC, ps);
		::EndPaint(hWnd, &ps);

		if (result)
			return 1;
	}
	break;

	case WM_LBUTTONDOWN:
	{
		POINT pt{ GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam) };
		result = _ms_frame->on_lbutton_down(pt);

		if (result)
			return 1;
	}
	break;

	case WM_RBUTTONDOWN:
	{
		POINT pt{ GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam) };
		result = _ms_frame->on_rbutton_down(pt);

		if (result)
			return 1;
	}
	break;

	case WM_LBUTTONUP:
	{
		POINT pt{ GET_X_LPARAM(lParam),GET_Y_LPARAM(lParam) };
		result = _ms_frame->on_lbutton_up(pt);

		if (result)
			return 1;
	}
	break;

	default:
		break;
	}
	return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//----------------------------------------------------------

bool winframe::WinFramework::on_paint(
	HDC& hDC, 
	PAINTSTRUCT& ps)
{
	return false;
}

//---------------------------------------------------------

bool winframe::WinFramework::on_lbutton_down(POINT& pt)
{
	return false;
}

//-----------------------------------------------------------

bool winframe::WinFramework::on_lbutton_up(POINT& pt)
{
	return false;
}

//----------------------------------------------------------
bool winframe::WinFramework::on_rbutton_down(POINT& pt)
{
	return false;
}

//-----------------------------------------------------------

bool winframe::WinFramework::on_create(CREATESTRUCT* crst)
{
	return false;
}



//-----------------------------------------------------------
int __stdcall wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	wchar_t* lpCmdLine, //long pointer string
	int nShowCmd)
{
	winframe::WinFramework::_ms_hinstance = hInstance;
	return frame_main(lpCmdLine);
}

//------------------------------------------------------------



