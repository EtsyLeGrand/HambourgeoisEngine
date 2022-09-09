#pragma once

#include <Engine.h>
#include <iostream>
#include <fstream>

class FileLogger : public hambourgeois::ILogger {
public:
	virtual ~FileLogger() override;
	FileLogger();
	
	virtual void Log(const std::string& message) override;

private:
	std::fstream logFile;
};