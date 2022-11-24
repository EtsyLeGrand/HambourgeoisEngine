#pragma once
#include <string>
#include <Color.h>
#include <Rect.h>

namespace hambourgeois {
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
}
