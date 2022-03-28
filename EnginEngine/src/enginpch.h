#pragma once

//precompiled headers are used so that includes are in one file and we don't need a lot of includes in other files as well
//and to speed up the build process

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Engin/Log.h"

#ifdef ENGIN_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

