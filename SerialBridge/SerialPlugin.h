#pragma once

#ifdef SERIALPLUGIN_EXPORTS
#define SERIALPLUGIN_API __declspec(dllexport)
#else
#define SERIALPLUGIN_API __declspec(dllimport)
#endif

extern "C" {
    SERIALPLUGIN_API bool InternalOpenSerialPort(const char* portName, int baudRate);
    SERIALPLUGIN_API void InternalCloseSerialPort();
    SERIALPLUGIN_API bool InternalWriteToSerial(const char* message);
}