/*
  ==============================================================================

    DeviceManager.h
    Created: 10 Feb 2018 7:49:53am
    Author:  johncarlson

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class DeviceManager
{
public:
	//==============================================================================
	DeviceManager();
	~DeviceManager();
	//==============================================================================
	AudioIODeviceCallback* getAudioIODeviceCallback();
	MidiInputCallback* getMidiInputCallback();
	//==============================================================================
	void setAudioIODeviceCallback(AudioIODeviceCallback* audioCallback);
	void setMidiInputCallback(MidiInputCallback* midiCallback);

protected:
	//==============================================================================
	std::shared_ptr<AudioDeviceManager> device_manager_;
	//
	std::shared_ptr<AudioIODeviceCallback*> audio_device_io_callback_;
	//
	std::shared_ptr<MidiInputCallback*> midi_in_callback_;
	const String midi_device_name_blank_ = "";

private:
	//==============================================================================
};
