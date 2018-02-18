#pragma once

#include <JuceHeader.h>

#if defined (_WIN32) || defined (_WIN64)
#include <Windows.h>
#endif

namespace juce
{
	class ConsoleOutput
	{
	public:
		//------------------------------------
		ConsoleOutput() = default;
		~ConsoleOutput() = default;
		//------------------------------------
		static void consoleOutput(std::string &string);
		static void consoleOutput(juce::String &string);
		//
		//ConsoleOutput& operator<<(std::string &string);
		//ConsoleOutput& operator<<(juce::String &string);

	protected:
		//------------------------------------

	private:
		//------------------------------------
	};
}