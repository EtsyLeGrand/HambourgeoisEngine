#pragma once
#include <Sprite.h>
#include <map>
#include <string>
#include <IUpdatable.h>
#include <Rect.h>

namespace hambourgeois
{
    class Entity;

    struct AnimationClip
    {
        int start;
        int count;
        float delay;
    };

    class Animation final : public Sprite, public IUpdatable
    {
    public:
        virtual ~Animation() = default;
        Animation();
        Animation(Entity* parent);

        void Update(float dt) override;

        void Init(int frameInRows, int frameWidth, int frameHeight);
        void AddClip(const std::string& name, int start, int count, float delay);
        void Stop();
        void Play(const std::string& name, bool loop);

    private:
        void UpdateFrame();

        std::map<std::string, AnimationClip> clips;

        int frameInRow = 0;
        int frameWidth = 0;
        int frameHeight = 0;
        int firstFrame = 0;
        int lastFrame = 0;
        float delay = 0.0f;
        float elapsed = 0.0f;
        bool playing = false;
        bool loop = false;
        int currentFrame = 0;
        std::string currentClip;
    };
}