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

		/// <summary>
		/// Sets the line from it's entity values
		/// </summary>
		/// <param name="isInverted">: whether or not the line is inverted</param>
		void LineFromRect(bool isInverted);

		int GetFloor() { return floor; }
		void SetFloor(int _floor) { floor = _floor; }

		float GetP1x() { return p1x; }
		float GetP2x() { return p2x; }
		float GetP1y() { return p1y; }
		float GetP2y() { return p2y; }

		/// <summary>
		/// The slope of the line. The "a" in ax + b
		/// </summary>
		float GetSlope() { return ((p2y - p1y) / (p2x - p1x)); }

	private:
		float p1x;
		float p1y;
		float p2x;
		float p2y;

		int floor = 0;

		std::string layerName;
	};
}