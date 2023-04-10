#pragma once
#include "SealPackages.h"

class IMessageHandler {
public:
	virtual bool TryHandleMessage(const UINT, const WPARAM, const LPARAM) = 0;
};