#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Heckel
{ 
	/**
	Define 2 consoles to log messages, one for the client, one for the engine
	*/
	class HECKEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macro
#define HZ_CORE_FATAL(...) ::Heckel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Heckel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)  ::Heckel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)  ::Heckel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...) ::Heckel::Log::GetCoreLogger()->trace(__VA_ARGS__)

// client log macro
#define HZ_FATAL(...) ::Heckel::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define HZ_ERROR(...) ::Heckel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)  ::Heckel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)  ::Heckel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_TRACE(...) ::Heckel::Log::GetClientLogger()->trace(__VA_ARGS__)

