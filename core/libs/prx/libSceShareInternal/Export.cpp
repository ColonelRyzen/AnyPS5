#include "prx/libSceShareInternal/include/Api.hpp"
#include "SceTypes.hpp"
#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceShareSetCommonCurrentStatus(void) {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}
APS5_EXPORT("U48aJ8+mCRk", sceShareSetCommonCurrentStatus);

}
