/*
  ==============================================================================

    DeviceManager.cpp
    Created: 10 Feb 2018 7:49:53am
    Author:  johncarlson

  ==============================================================================
*/

#include "DeviceManager.h"

//==============================================================================
DeviceManager::DeviceManager()
{
	device_manager_ = std::make_shared<AudioDeviceManager>();
	audio_device_io_callback_ = std::make_shared<AudioIODeviceCallback *>();
	midi_in_callback_ = std::make_shared<MidiInputCallback*>();
	//
	device_manager_->initialiseWithDefaultDevices(2, 2);
    //
    StringArray midi_devices_array_ = MidiInput::getDevices();
    std::for_each(midi_devices_array_.begin(), midi_devices_array_.end(), [=](String midi_device_name_){
        device_manager_->setMidiInputEnabled(midi_device_name_, true);
    });
}

DeviceManager::~DeviceManager()
{
	device_manager_->removeAudioCallback(*audio_device_io_callback_);
	device_manager_->removeMidiInputCallback(midi_device_name_blank_, *midi_in_callback_);
	//
	audio_device_io_callback_ = nullptr;
	midi_in_callback_ = nullptr;
	device_manager_ = nullptr;
}

//==============================================================================
AudioIODeviceCallback * DeviceManager::getAudioIODeviceCallback()
{
	return *audio_device_io_callback_;
}

MidiInputCallback * DeviceManager::getMidiInputCallback()
{
	return *midi_in_callback_;
}

//==============================================================================
void DeviceManager::setAudioIODeviceCallback(AudioIODeviceCallback * audioCallback)
{
	device_manager_->removeAudioCallback(*audio_device_io_callback_);
	*audio_device_io_callback_ = audioCallback;
	device_manager_->addAudioCallback(*audio_device_io_callback_);
}

void DeviceManager::setMidiInputCallback(MidiInputCallback * midiCallback)
{
	device_manager_->removeMidiInputCallback(midi_device_name_blank_, *midi_in_callback_);
	*midi_in_callback_ = midiCallback;
    //
    
    
    //
	device_manager_->addMidiInputCallback(midi_device_name_blank_, *midi_in_callback_);
}
