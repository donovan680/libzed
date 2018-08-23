#include "pause.h"

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#else
#error "system::pause() : Platform not supported!"
#endif

namespace z
{
	namespace system
	{
		void pause(double ms)
		{
			#ifdef _WIN32
			Sleep(ms);
			#else
			usleep(ms * 1000);
			#endif
		}
	}
}
