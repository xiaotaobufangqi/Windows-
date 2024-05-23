#include "LineManager.h"
//-----------------------------------------------------------
//    LineManager.cpp.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------

std::shared_ptr<LineManager> LineManager::_ms_line_mgr = nullptr;

LineManager::LineManager()
{
}

LineManager::~LineManager()
{
}

void LineManager::deleter(LineManager* line_mgr)
{
	if (line_mgr)
	{
		delete line_mgr;
	}
}

std::shared_ptr<LineManager> LineManager::instance(void)
{
	if (!_ms_line_mgr)
		_ms_line_mgr = std::shared_ptr<LineManager>(new LineManager,deleter);

	return _ms_line_mgr;
}

void LineManager::destroy_instance(void)
{
	if (_ms_line_mgr)
	{
		//delete _ms_line_mgr;
		_ms_line_mgr = nullptr;
	}
}

void LineManager::add_line(std::shared_ptr<Line> line)
{
	if (!line)
		return;

	_line_container.push_back(line);
}

void LineManager::clear_all_lines(void)
{
	_line_container.clear();
}

void LineManager::render(HDC hDC) const
{
	if (!hDC)
		return;

	//render all stuffs...
	for (auto&& item : _line_container)
		if (item)
			item->render(hDC);
}
