#include <FileLogger.h>



FileLogger::FileLogger()
{
	logFile.open("HamLog.log", std::fstream::out);
}

FileLogger::~FileLogger()
{
	logFile.close();
}

void FileLogger::Log(const std::string& message)
{
	logFile << message << std::endl;
}
