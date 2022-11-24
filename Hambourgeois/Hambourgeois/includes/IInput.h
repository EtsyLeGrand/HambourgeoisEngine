#pragma once
namespace hambourgeois {
	class IInput {
	public:
		virtual ~IInput() = default;
		/// <summary>
		/// Checks if a specific key is currently down
		/// </summary>
		/// <param name="key">: the id of the pressed key</param>
		/// <returns>true if the key is down, false otherwise</returns>
		virtual bool IsKeyDown(int key) = 0;
		/// <summary>
		/// Checks if a specific button is currently down
		/// </summary>
		/// <param name="button">: the id of the pressed button</param>
		/// <returns>true if the button is down, false otherwise</returns>
		virtual bool IsButtonDown(int button) = 0;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="x">: pointer to the position in x</param>
		/// <param name="y">: pointer to the position in y</param>
		virtual void GetMousePosition(int* x, int* y) = 0;

	protected:
		friend class Engine;
		virtual void Update() = 0;
	};
}