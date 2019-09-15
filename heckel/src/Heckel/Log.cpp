#include "hzpch.h"
#include "Log.h"

namespace Heckel
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// define message pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// create the logger
		s_CoreLogger = spdlog::stdout_color_mt("HECKEL");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}