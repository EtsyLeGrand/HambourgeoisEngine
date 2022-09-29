#pragma once

#include <string>
#include <Color.h>
#include <Rect.h>

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

	class IGraphics {
	public:
		
		virtual ~IGraphics() = default;

		virtual bool Initialize(const std::string& title, int w, int h) = 0;
		virtual void Shutdown() = 0;

		virtual void SetColor(const hambourgeois::Color& color) = 0;

		virtual void Clear() = 0;

		virtual void Present() = 0;

		virtual void DrawRect(float x, float y, float w, float h, const hambourgeois::Color& color) = 0;
		virtual void DrawRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color) = 0;

		virtual void FillRect(float x, float y, float w, float h, const hambourgeois::Color& color) = 0;
		virtual void FillRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color) = 0;

		virtual void DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color& color) = 0;
		virtual size_t LoadTexture(const std::string& filename) = 0;

		virtual void DrawTexture(size_t id, const hambourgeois::RectI& src, const hambourgeois::RectF& dst, double angle, const hambourgeois::Flip& flip, const hambourgeois::Color& color) = 0;

		virtual void DrawTexture(size_t id, const hambourgeois::RectF& dst, const hambourgeois::Color& color) = 0;
		virtual void DrawTexture(size_t id, const hambourgeois::Color& color) = 0;

		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;

		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const hambourgeois::Color& color) = 0;

		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
	
		virtual void GetWindowSize(int* w, int* h) = 0;
	};

	class IAudio {
	public:
		virtual ~IAudio() = default;

		virtual bool Initialize() = 0;

		virtual size_t LoadMusic(const std::string& filename) = 0;
		virtual size_t LoadSound(const std::string& filename) = 0;

		virtual void PlayMusic(size_t id) = 0;
		virtual void PlayMusic(size_t id, int loop) = 0;

		virtual void PlaySFX(size_t id) = 0;
		virtual void PlaySFX(size_t id, int loop) = 0;

		virtual void PauseMusic() = 0; 
		virtual void StopMusic() = 0;
		virtual void ResumeMusic() = 0;

		virtual void SetVolume(int volume) = 0; 
		virtual void SetVolume(size_t soundId, int volume) = 0;
	};

	class IServiceProvider {
	public:
		virtual ~IServiceProvider() = default;

		virtual bool Initialize() = 0;
		virtual bool Quit() = 0;
	};

	class IWorld {
	public:
		virtual ~IWorld() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void Update(float dt) = 0;
		virtual bool Add() = 0;
		virtual bool Remove() = 0;
		virtual bool Find() = 0;
	};
	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();
		static void Exit();

		IInput& Input() const { return *input; }
		ILogger& Logger() const { return *logger; }
		IGraphics& Graphics() const { return *graphics; }
		IServiceProvider& ServiceProvider() const { return *serviceProvider; }
		IAudio& Audio() const { return *audio; }

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
		
	};
}