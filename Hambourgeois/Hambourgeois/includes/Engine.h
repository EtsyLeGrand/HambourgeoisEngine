#pragma once

#include <string>
#include <Color.h>
#include <Rect.h>

namespace hambourgeois {
	class IInput {
	public:
		virtual ~IInput() = default;
		/// <summary>
		/// Checks if a specific key is currently down
		/// </summary>
		/// <param name="key">: the id of the pressed key</param>
		/// <returns>true if the key is down, false otherwise</returns>
		virtual bool IsKeyDown(int key) = 0;
		/// <summary>
		/// Checks if a specific button is currently down
		/// </summary>
		/// <param name="button">: the id of the pressed button</param>
		/// <returns>true if the button is down, false otherwise</returns>
		virtual bool IsButtonDown(int button) = 0;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="x">: pointer to the position in x</param>
		/// <param name="y">: pointer to the position in y</param>
		virtual void GetMousePosition(int* x, int* y) = 0;

	protected:
		friend class Engine;
		virtual void Update() = 0;
	};

	class ILogger {
	public:
		virtual ~ILogger() = default;
		/// <summary>
		/// Logs a message in a target determined by the logger service, eg. ConsoleLogger, FileLogger
		/// </summary>
		/// <param name="message">: the message to output</param>
		virtual void Log(const std::string& message) = 0;
	};

	class IGraphics {
	public:
		virtual ~IGraphics() = default;
		/// <summary>
		/// Initializes the Graphics service, as well as the window to use as a rander target.
		/// </summary>
		/// <param name="title">: the window title</param>
		/// <param name="w">: the window width</param>
		/// <param name="h">: the window height</param>
		/// <returns>true if the service was initialized correctly, false otherwise</returns>
		virtual bool Initialize(const std::string& title, int w, int h) = 0;
		/// <summary>
		/// Shuts down the Graphics service.
		/// </summary>
		virtual void Shutdown() = 0;
		/// <summary>
		/// Sets the color of the incoming draw calls.
		/// </summary>
		/// <param name="color">: the new color</param>
		virtual void SetColor(const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Clears the rendering target.
		/// </summary>
		virtual void Clear() = 0;
		/// <summary>
		/// Displays all the draw calls on the rendering target.
		/// </summary>
		virtual void Present() = 0;
		/// <summary>
		/// Draws a rectangle without a fill with a certain position, size, and color.
		/// </summary>
		/// <param name="x">: the x position of the rectangle</param>
		/// <param name="y">: the y position of the rectangle</param>
		/// <param name="w">: the width of the rectangle</param>
		/// <param name="h">: the height of the rectangle</param>
		/// <param name="color">: the color of the rectangle</param>
		virtual void DrawRect(float x, float y, float w, float h, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Draws a rectangle without a fill with a certain position, size, and color.
		/// </summary>
		/// <param name="rect">: the rect (x, y, w, h) of the rectangle</param>
		/// <param name="color">: the color of the rectangle</param>
		virtual void DrawRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Draws a filled rectangle with a certain position, size, and color.
		/// </summary>
		/// <param name="x">: the x position of the rectangle</param>
		/// <param name="y">: the y position of the rectangle</param>
		/// <param name="w">: the width of the rectangle</param>
		/// <param name="h">: the height of the rectangle</param>
		/// <param name="color">: the color of the rectangle</param>
		virtual void FillRect(float x, float y, float w, float h, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Draws a rectangle without a fill with a certain position, size, and color.
		/// </summary>
		/// <param name="rect">: the rect (x, y, w, h) of the rectangle</param>
		/// <param name="color">: the color of the rectangle</param>
		virtual void FillRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Draws a line with x1,y1 as starting point, and x2,y2 as ending point.
		/// </summary>
		/// <param name="x1">: the x coordinate of the starting point</param>
		/// <param name="y1">: the y coordinate of the starting point</param>
		/// <param name="x2">: the x coordinate of the ending point</param>
		/// <param name="y2">: the y coordinate of the ending point</param>
		/// <param name="color">: the color of the line</param>
		virtual void DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Loads a texture in the cache
		/// </summary>
		/// <param name="filename">: the path to the texture</param>
		/// <returns>the cached id of the texture</returns>
		virtual size_t LoadTexture(const std::string& filename) = 0;
		/// <summary>
		/// Draws the texture to the rendering target.
		/// </summary>
		/// <param name="id">: the id of the cached texture</param>
		/// <param name="src">: the rect representing the source area of the image to draw</param>
		/// <param name="dst">: the drawn destination of the source on the rendering target</param>
		/// <param name="angle">: the angle of the texture</param>
		/// <param name="flip">: the flip of the texture</param>
		/// <param name="color">: the color filter applied to the texture</param>
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

	class IScene {
	public:
		virtual ~IScene() = default;


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