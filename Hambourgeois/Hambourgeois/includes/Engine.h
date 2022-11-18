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
		/// <summary>
		/// Re-checks for inputs
		/// </summary>
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
<<<<<<< Updated upstream

=======
		/// <summary>
		/// Initializes the Graphics service, as well as the window to use as a render target.
		/// </summary>
		/// <param name="title">: the window title</param>
		/// <param name="w">: the window width</param>
		/// <param name="h">: the window height</param>
		/// <returns>true if the service was initialized correctly, false otherwise</returns>
>>>>>>> Stashed changes
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
		/// <summary>
		/// Draws the texture to the rendering target.
		/// </summary>
		/// <param name="id">: the id of the cached texture</param>
		/// <param name="dst">: the drawn destination of the source on the rendering target</param>
		/// <param name="color">: the color filter applied to the texture</param>
		virtual void DrawTexture(size_t id, const hambourgeois::RectF& dst, const hambourgeois::Color& color) = 0;
		/// <summary>
		/// Draws the texture to the rendering target.
		/// </summary>
		/// <param name="id">: the id of the cached texture</param>
		/// <param name="color">: the color filter applied to the texture</param>
		virtual void DrawTexture(size_t id, const hambourgeois::Color& color) = 0;

		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
		/// <summary>
		/// Loads a font and stores it in the font cache.
		/// </summary>
		/// <param name="filename">: the name of the font file</param>
		/// <param name="fontSize">: the size of the font in px</param>
		/// <returns></returns>
		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		/// <summary>
		/// Draws text to the screen
		/// </summary>
		/// <param name="text">: the text to draw</param>
		/// <param name="fontId">: the id of the cached font</param>
		/// <param name="x">: the x position of the string</param>
		/// <param name="y">: the y position of the string</param>
		/// <param name="color">: the drawn string's color</param>
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const hambourgeois::Color& color) = 0;
		
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
	
		virtual void GetWindowSize(int* w, int* h) = 0;
	};

	class IAudio {
	public:
		virtual ~IAudio() = default;
		/// <summary>
		/// Initializes the audio service
		/// </summary>
		/// <returns>true if the service was initialized correctly, false otherwise</returns>
		virtual bool Initialize() = 0;
		/// <summary>
		/// Loads a music file and puts it in the music cache
		/// </summary>
		/// <param name="filename">: the name of the music file</param>
		/// <returns>the index to play the music from the cache</returns>
		virtual size_t LoadMusic(const std::string& filename) = 0;
		/// <summary>
		/// Loads an sfx file and puts it in the sfx cache
		/// </summary>
		/// <param name="filename">: the name of the sfx file</param>
		/// <returns>the index to play the sfx from the cache</returns>
		virtual size_t LoadSound(const std::string& filename) = 0;
		/// <summary>
		/// Plays a music file
		/// </summary>
		/// <param name="id">: the id from the music cache</param>
		virtual void PlayMusic(size_t id) = 0;
		/// <summary>
		/// Plays a music file
		/// </summary>
		/// <param name="id">: the id from the music cache</param>
		/// <param name="loop">: the number of times the music should loop</param>
		virtual void PlayMusic(size_t id, int loop) = 0;
		/// <summary>
		/// Plays an sfx file
		/// </summary>
		/// <param name="id">: the id from the sfx cache</param>
		virtual void PlaySFX(size_t id) = 0;
		/// <summary>
		/// Plays an sfx file
		/// </summary>
		/// <param name="id">: the id from the sfx cache</param>
		/// <param name="loop">: the number of times the sfx should loop</param>
		virtual void PlaySFX(size_t id, int loop) = 0;
		/// <summary>
		/// Pauses the currently playing music
		/// </summary>
		virtual void PauseMusic() = 0;
		/// <summary>
		/// Stops the currently playing music
		/// </summary>
		virtual void StopMusic() = 0;
		/// <summary>
		/// Resumes the currently paused music
		/// </summary>
		virtual void ResumeMusic() = 0;
		/// <summary>
		/// Sets the volume of the music
		/// </summary>
		/// <param name="volume">: the new volume</param>
		virtual void SetVolume(int volume) = 0; 
		/// <summary>
		/// Sets the volume of an sfx
		/// </summary>
		/// <param name="soundId">: the id from the sfx cache</param>
		/// <param name="volume">: the new volume</param>
		virtual void SetVolume(size_t soundId, int volume) = 0;
	};

	class IServiceProvider {
	public:
		virtual ~IServiceProvider() = default;
		/// <summary>
		/// Initializes the service provider service
		/// </summary>
		/// <returns>true if the service was initialized correctly, false otherwise</returns>
		virtual bool Initialize() = 0;
		/// <summary>
		/// Quits the service provider service
		/// </summary>
		/// <returns>true if the service was stopped correctly, false otherwise</returns>
		virtual bool Quit() = 0;
	};

	class IWorld {
	public:
		virtual ~IWorld() = default;
<<<<<<< Updated upstream

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void Update(float dt) = 0;
		virtual bool Add() = 0;
		virtual bool Remove() = 0;
		virtual bool Find() = 0;
=======
		
		/// <summary>
		/// Updates the world and its entities
		/// </summary>
		/// <param name="dt">: the delta time value</param>
		virtual void Update(float dt) = 0;
		/// <summary>
		/// Draws the world and its entities
		/// </summary>
		virtual void Draw() = 0;
		/// <summary>
		/// Adds an entity to the world
		/// </summary>
		/// <param name="entity">: the entity to add</param>
		virtual void Add(Entity * entity) = 0;
		/// <summary>
		/// Removes an entity from the world
		/// </summary>
		/// <param name="entity">: the entity to remove</param>
		virtual void Remove(Entity * entity) = 0;
		/// <summary>
		/// Finds an entity in the world
		/// </summary>
		/// <param name="name">: the entity's name</param>
		/// <returns>the found entity, or nullptr</returns>
		virtual Entity* Find(const std::string & name) = 0;
		/// <summary>
		/// Creates an entity
		/// </summary>
		/// <param name="name">: the entity's name</param>
		/// <returns>The created entity</returns>
		virtual Entity* Create(const std::string & name) = 0;
		/// <summary>
		/// Loads a scene from the registered list
		/// </summary>
		/// <param name="scene">: the name of the scene</param>
		virtual void Load(const std::string & scene) = 0;
		/// <summary>
		/// Registers a scene in the world
		/// </summary>
		/// <param name="name">: the name of the scene</param>
		/// <param name="scene">: the scene to register</param>
		virtual void Register(const std::string & name, Scene* scene) = 0;
		/// <summary>
		/// Unloads the entire world
		/// </summary>
		virtual void Unload() = 0;
	};

	class IScene {
	public:
		virtual ~IScene() = default;
		/// <summary>
		/// Starts up a scene
		/// </summary>
		virtual void Load() = 0;
>>>>>>> Stashed changes
	};
	class Engine final {
	public:
<<<<<<< Updated upstream
=======
		/// <returns>the engine's reference</returns>
		static Engine& Get();
		/// <summary>
		/// Initializes the engine as well as the render window
		/// </summary>
		/// <param name="title">: the window's title</param>
		/// <param name="w">: the window's width</param>
		/// <param name="h">: the window's height</param>
		/// <returns>true if the engine was initialized correctly, false otherwise</returns>
>>>>>>> Stashed changes
		bool Init(const std::string& title, int w, int h);
		/// <summary>
		/// Fires up the engine. Have fun!
		/// </summary>
		void Start();
		/// <summary>
		/// Exits the engine
		/// </summary>
		static void Exit();
		
		/// <returns>a reference to the input service</returns>
		IInput& Input() const { return *input; }
		/// <returns>a reference to the logger service</returns>
		ILogger& Logger() const { return *logger; }
		/// <returns>a reference to the graphics service</returns>
		IGraphics& Graphics() const { return *graphics; }
		/// <returns>a reference to the service provider service</returns>
		IServiceProvider& ServiceProvider() const { return *serviceProvider; }
		/// <returns>a reference to the audio service</returns>
		IAudio& Audio() const { return *audio; }
<<<<<<< Updated upstream
=======
		/// <returns>a reference to the world service</returns>
		IWorld& World() const { return *world; };
>>>>>>> Stashed changes

	private:
		/// <summary>
		/// Processes the inputs of the current frame
		/// </summary>
		void ProcessInput();
		/// <summary>
		/// Updates every part of the engine
		/// </summary>
		/// <param name="dt">the time since the engine was last updated</param>
		void Update(float dt);
		/// <summary>
		/// Renders the displayable elements of the engine
		/// </summary>
		void Render();
		/// <summary>
		/// Shuts down the engine
		/// </summary>
		void Shutdown();
		

	private:
		/// <summary>
		/// Whether or not the engine is initialized
		/// </summary>
		bool isInit = false;

		IInput* input = nullptr;
		ILogger* logger = nullptr;
		IGraphics* graphics = nullptr;
		IServiceProvider* serviceProvider = nullptr;
		IAudio* audio = nullptr;
		
	};
}