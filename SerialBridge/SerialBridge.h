// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SERIALBRIDGE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SERIALBRIDGE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once

#ifdef SERIALBRIDGE_EXPORTS
#define SERIALBRIDGE_API __declspec(dllexport)
#else
#define SERIALBRIDGE_API __declspec(dllimport)
#endif

extern "C" {

	SERIALBRIDGE_API bool OpenSerialPort(const char* portName, int baudRate);
	SERIALBRIDGE_API void CloseSerialPort();
	SERIALBRIDGE_API bool WriteToSerial(const char* message);

}