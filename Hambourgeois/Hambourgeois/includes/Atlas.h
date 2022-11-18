#pragma once

#include <Sprite.h>
#include <map>

class Atlas : public Sprite
{
public:
	Atlas(Entity* entity);
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);

protected:
	std::map<const std::string, hambourgeois::RectI> frameCache;

private:
	hambourgeois::RectI frame;
	virtual void Draw() override;
};