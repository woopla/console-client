#pragma once

#ifdef PBACKUP_EXPORTS
#define PCC_API __declspec(dllexport)
#else
#define PCC_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

  #include "psynclib.h"
  
  PCC_API psync_syncid_t _cdecl add_sync_by_path(const char *localpath, const char *remotepath, psync_synctype_t synctype);
  PCC_API psync_syncid_t _cdecl add_sync_by_folderid(const char *localpath, psync_folderid_t folderid, psync_synctype_t synctype);
  PCC_API int _cdecl add_sync_by_path_delayed(const char *localpath, const char *remotepath, psync_synctype_t synctype);
  PCC_API int _cdecl change_synctype(psync_syncid_t syncid, psync_synctype_t synctype);
  PCC_API int _cdecl delete_sync(psync_syncid_t syncid);
  PCC_API psync_folder_list_t * _cdecl get_sync_list();
  
  typedef void (*status_callback_t)(int status,  const char * stat_string); 
  
  PCC_API int _cdecl  init(const char* user, const char* pass, int save);
  PCC_API int _cdecl statrt_crypto (const char* pass);
  PCC_API int _cdecl stop_crypto ();
  PCC_API int _cdecl finalize ();
  PCC_API void _cdecl set_status_callback(status_callback_t);
 
#ifdef __cplusplus
};
#endif