// SerialBridge.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "SerialBridge.h"
#include "SerialPlugin.h"  // Your internal serial code declarations

extern "C" {

    SERIALBRIDGE_API bool OpenSerialPort(const char* portName, int baudRate) {
        return InternalOpenSerialPort(portName, baudRate);
    }

    SERIALBRIDGE_API void CloseSerialPort() {
        InternalCloseSerialPort();
    }

    SERIALBRIDGE_API bool WriteToSerial(const char* message) {
        return InternalWriteToSerial(message);
    }

}