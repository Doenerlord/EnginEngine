#pragma once

//Define macro to import/export in the right scenario
#ifdef ENGIN_PLATFORM_WINDOWS
	#ifdef ENGIN_BUILD_DLL
		#define ENGIN_API __declspec(dllexport)
	#else
		#define	ENGIN_API __declspec(dllimport)
	#endif
#else
	#error Engin only supports Windows!
#endif

#define BIT(x) (1 << x)