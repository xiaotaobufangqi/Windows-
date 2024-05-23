//-----------------------------------------------------------
//    Line.cpp.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------
#include "Line.h"

Line::Line(POINT start, POINT end):_start(start),_end(end)
{
}

void Line::render(HDC hDC) const
{
	::MoveToEx(hDC, _start.x, _start.y, nullptr);
	::LineTo(hDC, _end.x, _end.y);
}
