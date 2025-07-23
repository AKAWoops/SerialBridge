#include "pch.h"
#include "SerialPlugin.h"
#include <windows.h>
#include <string>

HANDLE hSerial = INVALID_HANDLE_VALUE;

bool InternalOpenSerialPort(const char* portName, int baudRate) {
    if (hSerial != INVALID_HANDLE_VALUE) CloseHandle(hSerial);
    
    std::string fullPort = std::string("\\\\.\\COM") + portName;

    hSerial = CreateFileA(fullPort.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE) return false;

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) return false;

    dcbSerialParams.BaudRate = baudRate;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) return false;

    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) return false;

    return true;
}

void InternalCloseSerialPort() {
    if (hSerial != INVALID_HANDLE_VALUE) {
        CloseHandle(hSerial);
        hSerial = INVALID_HANDLE_VALUE;
    }
}

bool InternalWriteToSerial(const char* message) {
    if (hSerial == INVALID_HANDLE_VALUE) return false;

    DWORD bytesWritten;
    return WriteFile(hSerial, message, strlen(message), &bytesWritten, NULL);
}