#include "enginpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engin {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	//initializing the loggers
	void Log::Init() {
		//sets the pattern in which the logger writes the messages
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//creates a color multithreaded logger with name "ENGIN"
		s_CoreLogger = spdlog::stdout_color_mt("ENGIN");
		//sets the severity level on which the message is written. Message color depends on level.
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}