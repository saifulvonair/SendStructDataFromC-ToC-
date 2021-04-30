// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the OPENCVPHYSICALCAMERA_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// OPENCVPHYSICALCAMERA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef OPENCVPHYSICALCAMERA_EXPORTS
#define OPENCVPHYSICALCAMERA_API __declspec(dllexport)
#else
#define OPENCVPHYSICALCAMERA_API __declspec(dllimport)
#endif


#pragma once

#include <Windows.h>
#include <dshow.h>

#pragma comment(lib, "strmiids")

#include <map>
#include <string>

extern "C" OPENCVPHYSICALCAMERA_API struct Device {
	int id; // This can be used to open the device in OpenCV
	std::string devicePath;
	std::string deviceName; // This can be used to show the devices to the user
};

class DeviceEnumerator {

public:

	DeviceEnumerator() = default;
	std::map<int, Device> getDevicesMap(const GUID deviceClass);
	std::map<int, Device> getVideoDevicesMap();
	std::map<int, Device> getAudioDevicesMap();

private:

	std::string ConvertBSTRToMBS(BSTR bstr);
	std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);

};
