#pragma once

#include <string>

namespace hambourgeois {
	class IInput {
	public:
		virtual ~IInput() = default;

		virtual bool IsKeyDown(int key) = 0;
		virtual bool IsButtonDown(int button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;

	protected:
		friend class Engine;
		virtual void Update() = 0;
	};

	class ILogger {
	public:
		virtual ~ILogger() = default;

		virtual void Log(const std::string& message) = 0;
	};

	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();
		static void Exit();

		IInput& Input() const { return *input; }
		ILogger& Logger() const { return *logger; }

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
		

	private:
		bool isInit = false;

		IInput* input = nullptr;
		ILogger* logger = nullptr;

	public:
		
	};
}