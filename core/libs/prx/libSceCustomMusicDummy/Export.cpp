#include "prx/libSceCustomMusicDummy/include/Api.hpp"
#include "SceTypes.hpp"
#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceCustomMusicDummyFileCheckReachability(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("NpvAtwSD4EM", sceCustomMusicDummyFileCheckReachability);

int APS5_VABI sceCustomMusicDummyFileOpen(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("lJhv62O8rO0", sceCustomMusicDummyFileOpen);

int APS5_VABI sceCustomMusicDummyKernelMmap(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("YMratqD+-tY", sceCustomMusicDummyKernelMmap);

}
