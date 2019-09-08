#include <Heckel.h>

class Sandbox : public Heckel::Application
{
public:
	Sandbox()
	{

	}

	virtual ~Sandbox()
	{

	}
};

Heckel::Application* Heckel::CreateApplication()
{
	return new Sandbox();
}

