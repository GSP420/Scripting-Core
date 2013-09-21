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

	int width = (int)script.getGlobalNumber("SCREENWIDTH");
	int height = (int)script.getGlobalNumber("SCREENHEIGHT");
	int color = (int)script.getGlobalNumber("COLORDEPTH");
	printf("Screen Resolution: %ix%i @ %ibit color\n", width, height, color);
	bool fScreen = script.getGlobalBoolean("FULLSCREEN");
	printf("Full Screen: %s\n\n", (fScreen)?"true":"false");

	system("pause");
	return 0;
}

