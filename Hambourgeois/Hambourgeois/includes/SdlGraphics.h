#pragma once

#include <Engine.h>
#include <unordered_map>
#include <map>

struct SDL_Texture;
struct _TTF_Font;

typedef std::vector<std::vector<int>> TLayer;
typedef std::vector<hambourgeois::RectI> TTileset;
typedef std::map<std::string, TLayer> Tilemap;

class SdlGraphics : public hambourgeois::IGraphics {
public:
	virtual ~SdlGraphics();
	SdlGraphics();

	virtual bool Initialize(const std::string &title, int w, int h) override;
	virtual void Shutdown() override;

	virtual void SetColor(const hambourgeois::Color &color) override;

	virtual void Clear() override;

	virtual void Present() override;

	virtual void DrawRect(float x, float y, float w, float h, const hambourgeois::Color &color) override;
	virtual void DrawRect(const hambourgeois::RectF &rect, const hambourgeois::Color &color) override;

	virtual void FillRect(float x, float y, float w, float h, const hambourgeois::Color &color) override;
	virtual void FillRect(const hambourgeois::RectF &rect, const hambourgeois::Color &color) override;

	virtual void DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color &color) override;
	virtual size_t LoadTexture(const std::string &filename) override;

	virtual void DrawTexture(size_t id, const hambourgeois::RectI &src, const hambourgeois::RectF &dst, double angle, const hambourgeois::Flip &flip, const hambourgeois::Color &color) override;

	virtual void DrawTexture(size_t id, const hambourgeois::RectF &dst, const hambourgeois::Color &color) override;
	virtual void DrawTexture(size_t id, const hambourgeois::Color &color) override;

	virtual void GetTextureSize(size_t id, int* w, int* h) override;

	virtual size_t LoadFont(const std::string &filename, int fontSize) override;
	virtual void DrawString(const std::string &text, size_t fontId, float x, float y, const hambourgeois::Color &color) override;

	virtual void GetTextSize(const std::string &text, size_t fontId, int* w, int* h) override;

	virtual void GetWindowSize(int* w, int* h) override;

	void LoadTileset(const std::string& image, int tileW, int tileH, int col, int count);

	void DrawTiles(int tileW, int tileH, size_t tileset);

private:
	std::unordered_map<size_t, SDL_Texture*> textureCache;
	std::unordered_map<size_t, _TTF_Font*> fontCache;

	std::unordered_map<size_t, SDL_Texture*> tilesetCache;
	std::unordered_map<size_t, TTileset> tilesetRectCache;

	TTileset tileset;
	Tilemap tilemap;
	TLayer layer;
};