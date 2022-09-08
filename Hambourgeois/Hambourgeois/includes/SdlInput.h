#pragma once

#include <Engine.h>

class SdlInput final : public hambourgeois::IInput {
public:
	SdlInput();
	virtual ~SdlInput() = default;

	virtual void Update() override;
	virtual bool IsKeyDown(int key) override;
	virtual bool IsButtonDown(int button) override;
	virtual void GetMousePosition(int* x, int* y) override;

private:
	unsigned char const* keyStates = nullptr;
	int mouseX = 0;
	int mouseY = 0;
	bool mouseStates[3]{ false, false, false };
};