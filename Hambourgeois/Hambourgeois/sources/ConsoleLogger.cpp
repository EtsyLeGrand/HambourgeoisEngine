#include <ConsoleLogger.h>
#include <Windows.h>
#include <iostream>

ConsoleLogger::~ConsoleLogger()
{
	FreeConsole();
}

ConsoleLogger::ConsoleLogger()
{
	AllocConsole();

	//Override les outputs de stdout vers la console
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}

void ConsoleLogger::Log(const std::string& message)
{
	std::cout << message << std::endl;
}
