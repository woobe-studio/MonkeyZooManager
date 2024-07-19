#include "monkey.hpp"
#include <iomanip>

namespace Monkey
{
	tm *TimeDaemon::getNewTimePointerNow()
	{
		time_t now = time(0);
		tm *dt = localtime(&now);
		tm *toRet = new tm;
		memcpy((toRet), dt, sizeof(tm));
		return toRet;
	}

	tm *TimeDaemon::copyTimefromTimePointer(tm *toCopy)
	{
		time_t now = time(0);
		tm *dt = localtime(&now);
		tm *toRet = new tm;
		memcpy(toRet, dt, sizeof(tm));
		return toRet;
	}

	std::string TimeDaemon::getCurrentTimeString()
	{
		time_t now = time(0);
		tm *dt = localtime(&now);
		return getTimeString(dt);
	}

	std::string TimeDaemon::getTimeString(tm *dt)
	{
		std::stringstream output;
		if (dt->tm_hour < 10)
			output << "0";
		output << dt->tm_hour << ":";
		if (dt->tm_min < 10)
			output << "0";
		output << dt->tm_min << ":";
		if (dt->tm_sec < 10)
			output << "0";
		output << dt->tm_sec << " ";
		if (dt->tm_mday < 10)
			output << "0";
		output << dt->tm_mday << "-";
		if (dt->tm_mon < 9)
			output << "0";
		output << dt->tm_mon + 1 << "-" << dt->tm_year + 1900;

		return output.str();
	}
}
