//-----------------------------------------------------------
//    Line.h.
//    5/22/2024.             by hutao.
//-----------------------------------------------------------
#pragma once

#ifndef _LINE_H__
#define _LINE_H__

#include <windows.h>

class Line
{
public:
	Line(POINT start, POINT end);
	void render(HDC hDC) const;

private:
	POINT _start, _end;
};

#endif