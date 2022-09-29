#pragma once

#include <Engine.h>

class ConsoleLogger : public hambourgeois::ILogger {
public:
	virtual ~ConsoleLogger();
	ConsoleLogger();
	

	virtual void Log(const std::string& message) override;
};