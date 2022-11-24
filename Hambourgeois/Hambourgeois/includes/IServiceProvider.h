#pragma once

namespace hambourgeois {
	class IServiceProvider {
	public:
		virtual ~IServiceProvider() = default;

		virtual bool Initialize() = 0;
		virtual bool Quit() = 0;
	};
}