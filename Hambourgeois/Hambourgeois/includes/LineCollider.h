#pragma once
#include <Collider.h>
#include <string>

namespace hambourgeois
{
	class LineCollider final : public Collider
	{
	public:
		virtual ~LineCollider() = default;
		LineCollider();
		LineCollider(Entity* parent);

		virtual void Start() override;
		virtual void Draw() override;

		void LineFromRect(bool isInverted);

		float GetP1x() { return p1x; };
		float GetP2x() { return p2x; };
		float GetP1y() { return p1y; };
		float GetP2y() { return p2y; };

		float GetSlope() { return ((p2y - p1y) / (p2x - p1x)); }

	private:
		float p1x;
		float p1y;
		float p2x;
		float p2y;

		std::string layerName;
	};
}