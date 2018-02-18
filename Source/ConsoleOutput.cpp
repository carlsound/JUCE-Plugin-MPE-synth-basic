#include "ConsoleOutput.h"

namespace juce
{
	void ConsoleOutput::consoleOutput(std::string &string)
	{
		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::MacOSX)
		{
			std::cout << string << "\n";
		}

		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::Windows)
		{
			OutputDebugStringA(string.c_str());
			OutputDebugStringA("\n");
		}
	}

	void ConsoleOutput::consoleOutput(juce::String &string)
	{
		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::MacOSX)
		{
			std::cout << string << "\n";
		}

		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::Windows)
		{
			OutputDebugStringA(string.toStdString().c_str());
			OutputDebugStringA("\n");
		}
	}

	/*
	ConsoleOutput::ConsoleOutput& operator<<(std::string &string)
	{
		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::MacOSX)
		{
			std::cout << string << "\n";
		}

		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::Windows)
		{
			OutputDebugStringA(string.c_str());
			OutputDebugStringA("\n");

			return this;
		}
	}

	ConsoleOutput::ConsoleOutput& operator<<(juce::String &string)
	{
		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::MacOSX)
		{
			std::cout << string << "\n";
		}

		if (SystemStats::getOperatingSystemType() && SystemStats::OperatingSystemType::Windows)
		{
			OutputDebugStringA(string.toStdString().c_str());
			OutputDebugStringA("\n");
		}

		return this;
	}
	*/
}