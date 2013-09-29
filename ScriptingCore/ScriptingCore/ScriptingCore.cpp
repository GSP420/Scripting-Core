// ScriptingCore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>
#include "Script.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Lua Scripting Test Project\n\n";

	Script script;
	
	
	string sName = "script.lua";
	
	printf("Loading Script \"%s\"........\n\n", sName.c_str());

	if(script.loadScript(sName.c_str()) == false)
		return 1;

	string name = script.getGlobalString("PROGRAM_NAME");
	printf("Script Name: %s\n", name.c_str());
	string version = script.getGlobalString("PROGRAM_VERSION");
	printf("Version: %s\n\n", version.c_str());

	//GRAPHICS CORE VARIABLES (width, height, color,fScreen)
	int width = (int)script.getGlobalNumber("SCREENWIDTH");
	int height = (int)script.getGlobalNumber("SCREENHEIGHT");
	int color = (int)script.getGlobalNumber("COLORDEPTH");
	printf("Screen Resolution: %ix%i @ %ibit color\n", width, height, color);
	bool fScreen = script.getGlobalBoolean("FULLSCREEN");
	printf("Full Screen: %s\n\n", (fScreen)?"true":"false");

	//AUDIO CORE VARIABLES (musicVolume, soundVolume)
	int musicVolume = (int)script.getGlobalNumber("MUSIC_VOLUME");
	printf("Music Volume : %i\n\n", musicVolume);
	int soundVolume = (int)script.getGlobalNumber("SOUND_VOLUME");
	printf("Sound Volume : %i\n\n", soundVolume);

	//PHYSICS CORE VARIABLES (gravity, maxVelocity, maxAcceleration)
	int gravity = (int)script.getGlobalNumber("GRAVITY");
	printf("Gravity : %i\n\n", gravity);
	int maxVelocity = (int)script.getGlobalNumber("MAX_VELOCITY");
	printf("Maximum Velocity : %i\n\n", maxVelocity);
	int maxAcceleration = (int)script.getGlobalNumber("MAX_ACCELERATION");
	printf("Maximum Acceleration : %i\n\n", maxAcceleration);


	system("pause");

	return 0;
}

