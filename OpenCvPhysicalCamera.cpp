// OpenCvPhysicalCamera.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "OpenCvPhysicalCamera.h"

#include <oleauto.h>
#include <string>


#include <map>
#include <iostream>

#include "DeviceEnumerator.h"

// This is an example of an exported variable
//OPENCVPHYSICALCAMERA_API int nOpenCvPhysicalCamera=0;

std::map<int, Device> devices;
DeviceEnumerator de;
// This is an example of an exported variable
OPENCVPHYSICALCAMERA_API int nOpenCvPhysicalCamera=0;

OPENCVPHYSICALCAMERA_API int fnOpenCvLoadPhysicalCamera() {
    devices = de.getVideoDevicesMap();
    return devices.size();
}
// This is an example of an exported function.
OPENCVPHYSICALCAMERA_API int fnOpenCvPhysicalCamera(int index, DEVICE* devicesOutput)
{   
    if (devices.size() > 0) {
        //
        std::string devicName = devices[index].deviceName;
        std::copy(devicName.begin(), devicName.end(), devicesOutput->deviceName);
        devicesOutput->deviceName[devicName.size()] = 0;

        //
        std::string devicePath = devices[index].devicePath;
        std::copy(devicePath.begin(), devicePath.end(), devicesOutput->devicePath);
        devicesOutput->deviceName[devicePath.size()] = 0;

        devicesOutput->id = devices[index].id;
        return 0;

    }

    return -1;
}

// This is the constructor of a class that has been exported.
COpenCvPhysicalCamera::COpenCvPhysicalCamera()
{
    return;
}
