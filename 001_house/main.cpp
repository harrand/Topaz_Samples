#include "core/tz.hpp"

int main()
{
	tz::initialise({.name = "Sample 001 - House"});
	{
		while(!tz::window().is_close_requested())
		{
			tz::window().update();
		}
	}
	tz::terminate();
	return 0;
}
