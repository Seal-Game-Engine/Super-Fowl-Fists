#include "AnimationClip.h"
#include <numeric>
using namespace SealEngine;

float AnimationClip::length() const { return _length; }

AnimationClip::AnimationClip(std::vector<AnimationFrame> frames, bool loopTime)
    :Object("AnimationClip"), frames(frames), loopTime(loopTime),
    _length(std::accumulate(frames.begin(), frames.end(), 0.0f, [](float sum, const AnimationFrame& _currentFrame) { return sum + _currentFrame.duration; })) {}
