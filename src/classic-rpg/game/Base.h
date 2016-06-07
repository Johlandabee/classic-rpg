#pragma once
#include "GameTime.h"
#include "Console.h"
#include "Input.h"

namespace Engine
{
	class Base {
	public:
		Base();
		virtual ~Base();
		void run();

	protected:
		bool isFixedFrameRate = true;

		Console* console = nullptr;
		Input* input = nullptr;

		double desiredFrameRate = 60.0;

		virtual void initialize();
		
	private:
		GameTime* gameTime = nullptr;

		bool isRunning = false;
		bool isInitialized = false;

		virtual void update(const GameTime* gameTime) abstract;
		virtual void draw(const GameTime* gameTime) abstract;
	};
}
