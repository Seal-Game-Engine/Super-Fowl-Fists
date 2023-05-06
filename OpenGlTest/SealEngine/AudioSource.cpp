//HOW TO MAKE PAUSE CONTINUE THE MUSIC WHERE IT WAS PAUSED AT 

#include "AudioSource.h"

using namespace SealEngine;

AudioSource::AudioSource(const std::string& clip) :clip(clip) {} //ctr

AudioSource::~AudioSource() { engine->drop(); } //dtr

void AudioSource::Awake() { engine = createIrrKlangDevice(); }

void AudioSource::Play()
{
    engine->play2D(clip.data(), loop);
}

void AudioSource::Pause()
{
    engine->setAllSoundsPaused();
}

void AudioSource::Stop()
{
    engine->stopAllSounds();
}