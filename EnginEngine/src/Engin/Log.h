#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Engin {

	class ENGIN_API Log
	{
	public:
		//initializing the loggers
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		//a logger to log core engine things
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		// a logger to log application things
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//macros which define what logger and severity level to use

//CoreLogger macros
#define ENGIN_CORE_ERROR(...)	::Engin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGIN_CORE_WARN(...)	::Engin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGIN_CORE_INFO(...)	::Engin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGIN_CORE_TRACE(...)	::Engin::Log::GetCoreLogger()->trace(__VA_ARGS__)

//ClientLogger macros
#define ENGIN_ERROR(...)	::Engin::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGIN_WARN(...)		::Engin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGIN_INFO(...)		::Engin::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGIN_TRACE(...)	::Engin::Log::GetClientLogger()->trace(__VA_ARGS__)

