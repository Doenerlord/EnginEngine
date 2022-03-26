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

#ifdef ENGIN_ENABLE_ASSERTS
	#define ENGIN_ASSERT(x, ...) { if(!(x)) { ENGIN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define ENGIN_CORE_ASSERT(x, ...) { if(!(x)) { ENGIN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define ENGIN_ASSSERT(x, ...)
	#define ENGIN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)