#pragma once
#include "WinFramwork.h"
#include "LineManager.h"

class MyFramework :public winframe::WinFramework
{
public:
	MyFramework(std::wstring const& name) :WinFramework{ name }
	{

	}

	~MyFramework()
	{
		LineManager::destroy_instance();
	}

	bool on_paint(HDC& hDC, PAINTSTRUCT& ps) override
	{
		//::Ellipse(hDC, 100, 100, 200, 200);
		LineManager::instance()->render(hDC);

		return true;
	}

	bool on_lbutton_down(POINT& pt) override
	{
		_start_pt = pt;
		return true;
	}

	bool on_lbutton_up(POINT& pt) override
	{

		//create a new line instence.
		std::shared_ptr<Line> line(new Line{ _start_pt,pt });
		LineManager::instance()->add_line(line);

		::InvalidateRect(_hWnd, nullptr, true);

		return true;

	}

	bool on_rbutton_down(POINT& pt) override
	{

		LineManager::instance()->clear_all_lines();
		::InvalidateRect(_hWnd, nullptr, true);
		return true;

	}

private:
	/*LineManager*  _line_mgr;*/
	POINT  _start_pt;
};