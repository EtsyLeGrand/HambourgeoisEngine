#pragma once

#include <string>
#include <Color.h>
#include <Rect.h>

#include <IInput.h>
#include <ILogger.h>
#include <IGraphics.h>
#include <IServiceProvider.h>
#include <IAudio.h>
#include <IWorld.h>

namespace hambourgeois {
	class Engine final {
	public:
		static Engine& Get();

		bool Init(const std::string& title, int w, int h);
		void Start();
		static void Exit();

		IInput& Input() const { return *input; }
		ILogger& Logger() const { return *logger; }
		IGraphics& Graphics() const { return *graphics; }
		IServiceProvider& ServiceProvider() const { return *serviceProvider; }
		IAudio& Audio() const { return *audio; }
		IWorld& World() const { return *world; };

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
		

	private:
		bool isInit = false;

		IInput* input = nullptr;
		ILogger* logger = nullptr;
		IGraphics* graphics = nullptr;
		IServiceProvider* serviceProvider = nullptr;
		IAudio* audio = nullptr;
		IWorld* world = nullptr;
	};
}