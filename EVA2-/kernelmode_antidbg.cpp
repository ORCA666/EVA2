#include "kernelmode_antidbg.h"
#include <iostream>
#include "connector.h"
#ifdef __cplusplus
extern "C" {
#endif 




#define KUSER_SHARED_VA 0x7FFE0000
#define KUSER_SHARED_SIZE 0x3B8

inline bool is_kuser_shared_mapped()
{
    if (IsBadReadPtr((BYTE*)KUSER_SHARED_VA, KUSER_SHARED_SIZE)) {
        std::cerr << "KDB: Failed to retrieve KUSER_SHARED_DATA\n";
        return false;
    }
    return true;
}

// from Hidden Bee malware:
t_kdb_mode is_kernelmode_dbg_enabled(){
    const ULONGLONG KdDebuggerEnable_offset = 0x2d4;
    if (!is_kuser_shared_mapped()) {
        return KDB_UNKNOWN;
    }
    BYTE* KdDebuggerEnable = (BYTE*)(KUSER_SHARED_VA + KdDebuggerEnable_offset);
    if (*KdDebuggerEnable) {
        /*
        this flag is selected if:
        bcdedit /debug on
        */
        if (*KdDebuggerEnable == 3) {
            std::cout << "KDB: Remote enabled!\n";
            return KDB_REMOTE_ENABLED;
        }
        std::cout << "KDB: Local enabled!\n";
        return KDB_LOCAL_ENABLED;
    }
    std::cout << "KDB: Disabled\n";
    return KDB_DISABLED;
}

#ifdef __cplusplus
}
#endif