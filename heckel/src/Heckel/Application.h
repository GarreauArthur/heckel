#pragma once
#include "Core.h"

namespace Heckel
{

	class HECKEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
