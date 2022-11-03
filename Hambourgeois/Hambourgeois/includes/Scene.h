#pragma once

namespace hambourgeois {

	class IScene {
	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
	};

}