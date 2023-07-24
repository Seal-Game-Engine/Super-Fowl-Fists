#include "AudioSource.h"

using namespace SealEngine;

AudioSource::AudioSource(const std::string& clip, bool loop) :clip(clip), loop(loop) {} //ctr

void AudioSource::Awake() { engine = createIrrKlangDevice(); }
void AudioSource::OnDestroy() { engine->drop(); }

void AudioSource::Play()
{
    engine->play2D(clip.data(), loop);
    
}

void AudioSource::Pause()
{
    engine->setAllSoundsPaused(true);
    /*if (engine->isCurrentlyPlaying(clip.data())) { engine->play2D(clip.data());}
    else
        engine->play2D(clip.data());*/
}
void AudioSource::UnPause() {
    engine->setAllSoundsPaused(false);
}

void AudioSource::Stop()
{
    engine->stopAllSounds();
}