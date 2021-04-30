// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the OPENCVPHYSICALCAMERA_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// OPENCVPHYSICALCAMERA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <wtypes.h>
#ifdef OPENCVPHYSICALCAMERA_EXPORTS
#define OPENCVPHYSICALCAMERA_API __declspec(dllexport)
#else
#define OPENCVPHYSICALCAMERA_API __declspec(dllimport)
#endif


typedef struct
{
	int id;
	char devicePath[1024];
	char deviceName[256];

} DEVICE;


// This class is exported from the dll
class OPENCVPHYSICALCAMERA_API COpenCvPhysicalCamera {
public:
	COpenCvPhysicalCamera(void);
	// TODO: add your methods here.
};

extern OPENCVPHYSICALCAMERA_API int nOpenCvPhysicalCamera;

/// <summary>
/// Use from C#
/// [DllImport("OpenCvPhysicalCamera.dll", CallingConvention = CallingConvention.Cdecl)]      
/// private static extern int fnOpenCvPhysicalCamera(StringBuilder buf);
/// StringBuilder s = new StringBuilder(100);
/// fnOpenCvPhysicalCamera(s);
/// </summary>
/// <param name="str"></param>
/// <returns></returns>

/*
 [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
        public struct DEVICE
        {
            public int id;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public string devicePath;
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
            public string deviceName;
        }

        [DllImport("OpenCvPhysicalCamera.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int fnOpenCvPhysicalCamera(int index, ref DEVICE dvices);
*/
extern "C" OPENCVPHYSICALCAMERA_API int fnOpenCvPhysicalCamera(int index, DEVICE * devices);

extern "C" OPENCVPHYSICALCAMERA_API int fnOpenCvLoadPhysicalCamera();
