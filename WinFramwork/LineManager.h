//-----------------------------------------------------------
//    LineManager.h.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------
#pragma once


#ifndef _LINE_MANAGER_H__
#define _LINE_MANAGER_H__
#include "Line.h"
#include <memory>
#include <list>

class LineManager
{
public:
	//singleton pattern.
	static std::shared_ptr<LineManager> instance(void);
	static void destroy_instance(void);

	void add_line(std::shared_ptr<Line> line);
	void clear_all_lines(void);
	void render(HDC hDC) const;

private:
	//Singleton设计原则
	LineManager();
	LineManager(LineManager const& other) = delete; //不会生成,不用在cpp中实现
	LineManager(LineManager&& other) = delete;
	~LineManager();

	static void deleter(LineManager* line_mgr);

private:
	std::list<std::shared_ptr<Line>>  _line_container;
	static std::shared_ptr<LineManager>  _ms_line_mgr;
};

#endif // !_LINE_MANAGER_H__


