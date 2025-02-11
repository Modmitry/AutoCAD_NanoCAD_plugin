//#if defined(_DEBUG) && !defined(AC_FULL_DEBUG) && !defined(NC_FULL_DEBUG)
//#error _DEBUG should not be defined except in internal debug builds (ACAD or NCAD)
//#endif

#if !defined(HOST_NO_MFC)
#define _AFXDLL
// you can add MFC path if it is necessary for the project
#include <afxwin.h>
#include <unknwn.h>
#else
#include <windows.h>
#endif

#include <arxHeaders.h>

void printHello()
{
    acutPrintf(L"\nHello CAD!");
}

void createCircle()
{
    // get center point from user
    AcGePoint3d center;
    if (acedGetPoint(nullptr, L"\nEnter the center point: ", asDblArray(center)) != RTNORM)
    {
        return;
    }

    // create the circle with default radius 
    constexpr double DEFAULT_RADIUS = 5;
    auto circle = std::make_unique<AcDbCircle>(center,AcGeVector3d::kZAxis, DEFAULT_RADIUS);
    
    // add circle to the drawing
    AcDbBlockTableRecordPointer pCurSpace(acdbCurDwg()->currentSpaceId(), AcDb::kForWrite);
    if (pCurSpace.openStatus() == Acad::eOk)
    {
        pCurSpace->appendAcDbEntity(circle.get());
        circle.release()->close();
    }
}

// The function is called when the application loads
void initApp()  
{
    // Commands  
    // 1st argument - name of the command group
    // 2nd argument - global name of the command
    // 3rd argument - local name for the same command
    // 4th argument - defines whether the command is transparent – can be invoked when another command is active
    // 5th argument - pointer to the function being called

    acedRegCmds->addCommand(L"TEST_COMMANDS_2025", L"TEST_HELLO_CMD", L"TEST_HELLO", ACRX_CMD_MODAL, printHello);
    acedRegCmds->addCommand(L"TEST_COMMANDS_2025", L"TEST_CIRCLE_CMD", L"TEST_CIRCLE", ACRX_CMD_MODAL, createCircle);
}

// The function is called when the application unloads
void unloadApp()
{
    acedRegCmds->removeGroup(L"TEST_COMMANDS_2025");
}

// main() C++
// msg - message sent from the ObjectARX core to the application  
// The second parameter controls various data access functions

extern "C" __declspec(dllexport) AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId) 
{
    switch (msg) 
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(appId);
        acrxDynamicLinker->registerAppMDIAware(appId);
        initApp();
        break;
    case AcRx::kUnloadAppMsg:
        unloadApp();
    }
    return AcRx::kRetOK;
}
