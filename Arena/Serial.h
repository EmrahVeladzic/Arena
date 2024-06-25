#ifndef SERIAL
#define SERIAL

#include <windows.h>
#include <stdint.h>

HANDLE Open() {
    HANDLE h_Serial;
    h_Serial = CreateFile(L"COM4\0", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL, 0);
    if (h_Serial == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            
        }
       
    }

    DCB dcbSerial;

    DCB dcbSerialParam = { 0 };
    dcbSerial.DCBlength = sizeof(dcbSerialParam);

    if (!GetCommState(h_Serial, &dcbSerialParam)) {
       
    }

    dcbSerialParam.BaudRate = CBR_300;
    dcbSerialParam.ByteSize = 8;
    dcbSerialParam.StopBits = ONESTOPBIT;
    dcbSerialParam.Parity = NOPARITY;

    if (!SetCommState(h_Serial, &dcbSerialParam)) {
       
    }

    COMMTIMEOUTS timeout = { 0 };
    timeout.ReadIntervalTimeout = 60;
    timeout.ReadTotalTimeoutConstant = 60;
    timeout.ReadTotalTimeoutMultiplier = 15;
    timeout.WriteTotalTimeoutConstant = 60;
    timeout.WriteTotalTimeoutMultiplier = 8;
    if (!SetCommTimeouts(h_Serial, &timeout)) {
        
    }


    return h_Serial;
}


uint8_t ReadSingleByte(HANDLE h_Serial) {

    uint8_t out[2];
    
    DWORD dwRead = 0;
    if (!ReadFile(h_Serial, out, 1, &dwRead, NULL)) {
      
    }

    return out[0];
}






#endif // !SERIAL
