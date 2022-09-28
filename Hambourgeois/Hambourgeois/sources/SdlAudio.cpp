#include <SdlAudio.h>
#include <SDL_mixer.h>

SdlAudio::SdlAudio() : hambourgeois::IAudio()
{
}

SdlAudio::~SdlAudio()
{
	Mix_CloseAudio();
}

bool SdlAudio::Initialize()
{
	return Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == 0;
}

size_t SdlAudio::LoadMusic(const std::string& filename)
{
	const size_t musId = std::hash<std::string>()(filename);
	if (musicCache.find(musId) == musicCache.end()) // Doesn't exist in cache
	{
		musicCache[musId] = Mix_LoadMUS(filename.c_str());
	}

	return musId;
}

size_t SdlAudio::LoadSound(const std::string& filename)
{
	const size_t soundId = std::hash<std::string>()(filename);
	if (soundCache.find(soundId) == soundCache.end()) // Doesn't exist in cache
	{
		soundCache[soundId] = Mix_LoadWAV(filename.c_str());
	}

	return soundId;
}

void SdlAudio::PlayMusic(size_t id)
{
	Mix_PlayMusic(musicCache[id], 0);
}

void SdlAudio::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(musicCache[id], loop);
}

void SdlAudio::PlaySFX(size_t id)
{
	Mix_PlayChannel(-1, soundCache[id], 0);
}

void SdlAudio::PlaySFX(size_t id, int loop)
{
	Mix_PlayChannel(-1, soundCache[id], loop);
}

void SdlAudio::PauseMusic()
{
	Mix_PauseMusic();
}

void SdlAudio::StopMusic()
{
	Mix_HaltMusic();
}

void SdlAudio::ResumeMusic()
{
	Mix_ResumeMusic();
}

void SdlAudio::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void SdlAudio::SetVolume(size_t soundId, int volume)
{
	Mix_VolumeChunk(soundCache[soundId], volume);
}