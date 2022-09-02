#pragma once

#include <string>

namespace hambourgeois {
	class Engine final {
	public:
		bool Init(const std::string &title, int w, int h);
		void Start();
		
	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
		void Exit();

	private:
		bool isRunning = false;
		bool isInit = false;
	};
}