#ifdef __cplusplus
extern "C" {
#endif 



#include <Windows.h>

typedef enum kdb_mode {
    KDB_UNKNOWN = (-1),
    KDB_DISABLED = 0,
    KDB_LOCAL_ENABLED = 1,
    KDB_REMOTE_ENABLED = 3
} t_kdb_mode;

t_kdb_mode is_kernelmode_dbg_enabled();

#ifdef __cplusplus
}
#endif