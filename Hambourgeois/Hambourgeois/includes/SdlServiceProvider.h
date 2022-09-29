#pragma once

#include <Engine.h>

class SdlServiceProvider : public hambourgeois::IServiceProvider {
public:
	SdlServiceProvider();
	virtual ~SdlServiceProvider();

	virtual bool Initialize() override;
	virtual bool Quit() override;
};