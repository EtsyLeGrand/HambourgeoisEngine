#include <Animation.h>
#include <Engine.h>

hambourgeois::Animation::Animation() : Animation(nullptr)
{
}

hambourgeois::Animation::Animation(Entity* parent) : Sprite(parent)
{
}

void hambourgeois::Animation::Update(float dt)
{
    if (playing)
    {
        elapsed += dt;
        if (elapsed >= delay)
        {
            elapsed = 0.0f;
            currentFrame++;

            if (currentFrame > lastFrame)
            {
                currentFrame = firstFrame;
                if (!loop)
                {
                    playing = false;
                }
            }

            UpdateFrame();
        }
    }
}

void hambourgeois::Animation::Init(int _frameInRows, int _frameWidth, int _frameHeight)
{
    frameInRow = _frameInRows;
    frameWidth = _frameWidth;
    frameHeight = _frameHeight;

    source.x = 0;
    source.y = 0;
    source.w = frameWidth;
    source.h = frameHeight;

    currentClip.clear();
}

void hambourgeois::Animation::AddClip(const std::string& name, int start, int count, float delay)
{
    clips.emplace(name, AnimationClip{ start, count, delay });
}

void hambourgeois::Animation::Stop()
{
    playing = false;
    currentFrame = 0;
    firstFrame = 0;
    lastFrame = 0;
    delay = 0.0f;
    loop = false;
    currentClip.clear();
}

void hambourgeois::Animation::Play(const std::string& name, bool isLoop)
{
    if (name != currentClip)
    {
        const AnimationClip _clip = clips[name];
        currentFrame = _clip.start;
        firstFrame = _clip.start;
        lastFrame = _clip.start + _clip.count - 1;
        delay = _clip.delay;
        loop = isLoop;

        UpdateFrame();
        playing = true;
        currentClip = name;
    }
}

void hambourgeois::Animation::UpdateFrame()
{
    const int _row = currentFrame / frameInRow;
    const int _col = currentFrame - frameInRow * _row;
    const int _x = frameWidth * _col;
    const int _y = frameHeight * _row;

    source.x = _x;
    source.y = _y;
    source.w = frameWidth;
    source.h = frameHeight;
}