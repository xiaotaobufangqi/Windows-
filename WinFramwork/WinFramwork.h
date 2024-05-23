//-----------------------------------------------------------
//    WinFramwork.h.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------
#pragma once  //ֻ������һ�α��ļ�


#ifndef _WIN_FRAMEWORK_H__  //���û���궨����ִ��
#define _WIN_FRAMEWORK_H__
//-----------------------------------------------------------
// headers.
// ----------------------------------------------------------
#include <Windows.h>
#include <string>

//-----------------------------------------------------------
namespace winframe
{
	//-------------------------------------------------------
	class WinFramework
	{
		friend int __stdcall ::wWinMain(
			HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			wchar_t* lpCmdLine, //long pointer string
			int nShowCmd);

	public:
		WinFramework(std::wstring name);
		bool show_window(void);
		void run(void);

		static LRESULT CALLBACK
			WndProcdure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	protected:
		virtual bool on_paint(HDC& hDC,PAINTSTRUCT& ps);
		virtual bool on_lbutton_down(POINT& pt);
		virtual bool on_lbutton_up(POINT& pt);
		virtual bool on_rbutton_down(POINT& pt);
		virtual bool on_create(CREATESTRUCT* crst);

	protected:
		HWND  _hWnd{nullptr};
		static WinFramework*  _ms_frame;  //������̬�������ó�Ա����
		static HINSTANCE  _ms_hinstance;

	public:
		static WNDCLASSEX _ms_wcex;
	};
	//-------------------------------------------------------
}
//-----------------------------------------------------------
#endif
 