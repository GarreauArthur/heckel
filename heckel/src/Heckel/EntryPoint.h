#pragma once

#ifdef HZ_PLATFORM_WINDOWS

// CreateApplication will be implemented somewhere in the client
extern Heckel::Application* Heckel::CreateApplication();

int main(int argc, char** argv)
{
	auto* app = Heckel::CreateApplication();
	app->Run();
	return 0;
}

#endif // HZ_PLATFORM_WINDOWS

