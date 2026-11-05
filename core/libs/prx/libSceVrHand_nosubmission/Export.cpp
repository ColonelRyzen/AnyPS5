#include "prx/libSceVrHand_nosubmission/include/Api.hpp"
#include "SceTypes.hpp"
#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceVrHandDebugGetConfig(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("lpc6JxtBTSA", sceVrHandDebugGetConfig);

int APS5_VABI sceVrHandDebugGetInternalResult(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("ncbuKBJhNys", sceVrHandDebugGetInternalResult);

int APS5_VABI sceVrHandDebugSetConfig(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("M8L5ikOAIxw", sceVrHandDebugSetConfig);

int APS5_VABI sceVrHandSetDebugInterface(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("ef93YhKfJB0", sceVrHandSetDebugInterface);

}
