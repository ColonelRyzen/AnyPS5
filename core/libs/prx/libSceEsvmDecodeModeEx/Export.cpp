#include "prx/libSceEsvmDecodeModeEx/include/Api.hpp"
#include "SceTypes.hpp"
#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceEsvmUseCustomMusicCoreForDecoderMode(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("M8-ylcEPnGo", sceEsvmUseCustomMusicCoreForDecoderMode);

}
