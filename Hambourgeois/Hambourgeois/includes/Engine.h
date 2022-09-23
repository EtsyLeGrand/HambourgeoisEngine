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

	class IGraphics {
	public:
		/*
		virtual ~IGraphics() = default;

		virtual bool Initialize(const std::string& title, int w, int h) = 0;
		virtual void Shutdown() = 0;

		virtual void SetColor(const Color& color) = 0;

		virtual void Clear() = 0;

		virtual void Present() = 0;

		virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void DrawRect(const RectF& rect, const Color& color) = 0;

		virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void FillRect(const RectF& rect, const Color& color) = 0;

		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
		virtual size_t LoadTexture(const std::string& filename) = 0;

		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0;

		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const Color& color) = 0;

		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;

		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0;

		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
	*/
	};

	class IServiceProvider {
	public:
		virtual ~IServiceProvider() = default;
		 // SDL Service provider
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