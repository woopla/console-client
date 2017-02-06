#include "pclsync_lib_c.h"
#include "pclsync_lib.h"



#ifdef __cplusplus
extern "C" {
#endif
 namespace cc = console_client::clibrary;
 
 psync_syncid_t add_sync_by_path(const char *localpath, const char *remotepath, psync_synctype_t synctype) {
	 return psync_add_sync_by_path(localpath, remotepath, synctype);
 }
 psync_syncid_t add_sync_by_folderid(const char *localpath, psync_folderid_t folderid, psync_synctype_t synctype)
 {
	 return psync_add_sync_by_folderid(localpath, folderid, synctype);
 }
 int  add_sync_by_path_delayed(const char *localpath, const char *remotepath, psync_synctype_t synctype) {
	 return psync_add_sync_by_path_delayed(localpath, remotepath,  synctype);
 }
 int  change_synctype(psync_syncid_t syncid, psync_synctype_t synctype) {
	 return psync_change_synctype( syncid,  synctype);
 }
 int  delete_sync(psync_syncid_t syncid) {
	 return psync_delete_sync(syncid);
 }
 psync_folder_list_t *  get_sync_list() {
	 return psync_get_sync_list();
 }

int init(const char* user, const char* pass, int save) {
  cc::pclsync_lib::get_lib().set_username(user);
  cc::pclsync_lib::get_lib().set_password(pass);
  cc::pclsync_lib::get_lib().set_savepass((bool)save);
  return cc::pclsync_lib::get_lib().init();
}

 int statrt_crypto (const char* pass) {
  return cc::pclsync_lib::statrt_crypto (pass);
}
 int stop_crypto () {
   return cc::pclsync_lib::stop_crypto (NULL);
}
 int finalize () { 
   return cc::pclsync_lib::finalize(NULL);
}
void set_status_callback(status_callback_t c)
{
  return cc::pclsync_lib::get_lib().set_status_callback(c);
}
 #ifdef __cplusplus
}
#endif