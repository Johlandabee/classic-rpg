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
		bool isInitialized = false;

        Console console;
        Input input;

		double desiredFrameRate = 60.0;
        virtual void initialize();
		
		

    private:
        GameTime* gameTime;


        bool isRunning;

        virtual void update(GameTime* gameTime) abstract;
        virtual void draw(GameTime* gameTime) abstract;
    };
}
