#include "MonoBehaviour.h"
#include "Transform.h"
#include "GameObject.h"
#include "Clock.h"
using namespace SealEngine;

void MonoBehaviour::RunCoroutines() {
	for (auto it = _coroutines.begin(); it != _coroutines.end();) {
		if (Time::time() >= it->second) {
			it->first();
			it = _coroutines.erase(it);
		} else
			it++;
	}
}
void MonoBehaviour::Invoke(std::function<void()> action, float delayDuration) { _coroutines.emplace_back(action, Time::time() + delayDuration); }
void MonoBehaviour::InvokeRepeating(std::function<void()> action, float delayDuration, float repeatRate) {
	Invoke([=]() {
		action();
		InvokeRepeating(action, repeatRate, repeatRate);
		}, delayDuration);
}
void MonoBehaviour::CancelInvoke() { _coroutines.clear(); }

bool MonoBehaviour::isActiveAndEnabled() { return enabled && gameObject->activeSelf(); }

Transform* MonoBehaviour::transform() { return gameObject->transform; }
