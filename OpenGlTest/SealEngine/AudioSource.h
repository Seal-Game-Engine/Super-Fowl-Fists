#pragma once

#include "MonoBehaviour.h"
#include "SealPackages.h"
#include "KeyCode.h"
#include <string>
#include <memory>

using namespace irrklang;

//containing within the namespace
namespace SealEngine {
    class AudioSource : public MonoBehaviour
    {
    public:

        void Play();
        void Pause();
        void UnPause();
        void Stop();

        std::string clip;
        AudioSource(const std::string& clip, bool loop = false); //constructor
        AudioSource() = default; //constructor
        bool loop = false;
        //bool playOnAwake = true;
                
        void Awake() override;
        void OnDestroy() override;

    private:
        ISoundEngine* engine = nullptr;

        AudioSource* _Clone() const override { return new AudioSource(*this);}
    };

}

