#pragma once
#include <string>

namespace hambourgeois {
	class ILogger {
	public:
		virtual ~ILogger() = default;
		/// <summary>
		/// Logs a message in a target determined by the logger service, eg. ConsoleLogger, FileLogger
		/// </summary>
		/// <param name="message">: the message to output</param>
		virtual void Log(const std::string& message) = 0;
	};
}