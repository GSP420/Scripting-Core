// *******************************
// Interface Class - ScriptedInput
// *******************************

#include <iostream>
#include <string>
using namespace std;

class ScriptedInput
{
	public:
		virtual bool loadScript(std::string scriptfile)=0;
		virtual std::string getGlobalString(std::string name)=0;
		virtual double getGlobalNumber(std::string name)=0;
		virtual bool getGlobalBoolean(std::string name)=0;
	
};

