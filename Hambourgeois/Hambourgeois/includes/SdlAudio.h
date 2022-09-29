#pragma once

#include <Engine.h>
#include <unordered_map>

struct Mix_Chunk;
struct _Mix_Music;

class SdlAudio : public hambourgeois::IAudio {
public:
	SdlAudio();
	virtual ~SdlAudio();

	virtual bool Initialize() override;

	virtual size_t LoadMusic(const std::string & filename) override;
	virtual size_t LoadSound(const std::string & filename) override;

	virtual void PlayMusic(size_t id) override;
	virtual void PlayMusic(size_t id, int loop) override;

	virtual void PlaySFX(size_t id) override;
	virtual void PlaySFX(size_t id, int loop) override;

	virtual void PauseMusic() override; 
	virtual void StopMusic() override;
	virtual void ResumeMusic() override;

	virtual void SetVolume(int volume) override;
	virtual void SetVolume(size_t soundId, int volume) override;
private:

	std::unordered_map<size_t, Mix_Chunk*> soundCache;
	std::unordered_map<size_t, _Mix_Music*> musicCache;
};