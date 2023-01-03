#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <string>

BOOL WINAPI testThread(HMODULE hModule) noexcept{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    SetConsoleTitle("example dll entry | github.com/ch4daev");

    printf("injected!\ngithub.com/ch4daev");


    //Uncomment this so that the console closes
    /*
    fclose(fp);
    FreeConsole();
    */
    return true;
}
BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0,(LPTHREAD_START_ROUTINE)testThread, 0, 0,0);
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

