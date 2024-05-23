#include "Myframwork.hpp"

int frame_main(std::wstring const& params)
{
	MyFramework::_ms_wcex.hbrBackground = reinterpret_cast<HBRUSH>(::GetStockObject(LTGRAY_BRUSH));
	MyFramework myframe{ L"MyApp" };
	myframe.show_window();
	myframe.run();
	return 0;
}