#pragma once

#include <Engine.h>

class ConsoleLogger : public hambourgeois::ILogger {
public:
	virtual ~ConsoleLogger() = default;

	virtual void Log(std::string& message) override;
};