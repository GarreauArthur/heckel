#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// CreateApplication will be implemented somewhere in the client
extern Heckel::Application* Heckel::CreateApplication();

int main(int argc, char** argv)
{
	Heckel::Log::Init();
	HZ_CORE_WARN("Init log!");
	int a = 2;
	HZ_INFO("hello var={0}", a);

	auto* app = Heckel::CreateApplication();
	app->Run();
	return 0;
}

#endif // HZ_PLATFORM_WINDOWS

