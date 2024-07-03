#include "monke.hpp"

namespace Monke
{
	tm *TimeDaemon::getNewTimePointerNow()
	{
		std::cout << "GETTING IT NOW" << std::endl;
		time_t now = time(0);
		tm *dt = localtime(&now);
		tm *toRet = new tm;
		memcpy((toRet), dt, sizeof(tm));
		return toRet;
	}
	tm *TimeDaemon::copyTimefromTimePointer(tm *toCopy)
	{
		std::cout << "IT IS EXISTING" << std::endl;
		time_t now = time(0);
		tm *dt = localtime(&now);
		tm *toRet = new tm;
		memcpy(toRet, dt, sizeof(tm));
		return toRet;
	}
}
