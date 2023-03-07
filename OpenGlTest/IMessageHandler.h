#pragma once
#include <windows.h>

class IMessageHandler {
public:
	virtual bool TryHandleMessage(const UINT, const WPARAM, const LPARAM) = 0;
};