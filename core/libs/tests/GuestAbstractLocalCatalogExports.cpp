#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

extern "C" {
int APS5_VABI _ZN15AbstractStorage11LocalFolder4OpenENS_8ItemTypeE_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage11LocalFolder5CloseEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage11LocalFolder6RemoveEb_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage11LocalFolderD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage11LocalFolderD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage11LocalFolderD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3__nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent4OpenEit_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent4ReadEPvlPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent5CloseEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent5FlushEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent5WriteEPKvlPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent6RemoveEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent8SeekByteEliPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContent8SeekTimeElPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContentD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContentD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalContentD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalService13SearchStorageEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalService4StopEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalService5StartEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalServiceC1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalServiceC2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalServiceD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalServiceD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalServiceD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalStorage14GetStorageSizeEPlS1_S1__nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalStorageD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalStorageD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage12LocalStorageD2Ev_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage11LocalFolder10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage11LocalFolder13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage11LocalFolder7GetStatEPNS_4StatE_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalContent10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalContent13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalContent7GetStatEPNS_4StatE_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalService14GetServiceTypeEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalStorage10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalStorage13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage12LocalStorage7GetStatEPNS_4StatE_nid_no_patch(void);
}

namespace {

using ThrowingStub = int (*)(void);

const ThrowingStub kStubs[] = {
    _ZN15AbstractStorage11LocalFolder4OpenENS_8ItemTypeE_nid_no_patch,
    _ZN15AbstractStorage11LocalFolder5CloseEv_nid_no_patch,
    _ZN15AbstractStorage11LocalFolder6RemoveEb_nid_no_patch,
    _ZN15AbstractStorage11LocalFolderD0Ev_nid_no_patch,
    _ZN15AbstractStorage11LocalFolderD1Ev_nid_no_patch,
    _ZN15AbstractStorage11LocalFolderD2Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3__nid_no_patch,
    _ZN15AbstractStorage12LocalContent4OpenEit_nid_no_patch,
    _ZN15AbstractStorage12LocalContent4ReadEPvlPl_nid_no_patch,
    _ZN15AbstractStorage12LocalContent5CloseEv_nid_no_patch,
    _ZN15AbstractStorage12LocalContent5FlushEv_nid_no_patch,
    _ZN15AbstractStorage12LocalContent5WriteEPKvlPl_nid_no_patch,
    _ZN15AbstractStorage12LocalContent6RemoveEv_nid_no_patch,
    _ZN15AbstractStorage12LocalContent8SeekByteEliPl_nid_no_patch,
    _ZN15AbstractStorage12LocalContent8SeekTimeElPl_nid_no_patch,
    _ZN15AbstractStorage12LocalContentD0Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalContentD1Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalContentD2Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalService13SearchStorageEv_nid_no_patch,
    _ZN15AbstractStorage12LocalService4StopEv_nid_no_patch,
    _ZN15AbstractStorage12LocalService5StartEv_nid_no_patch,
    _ZN15AbstractStorage12LocalServiceC1Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalServiceC2Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalServiceD0Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalServiceD1Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalServiceD2Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalStorage14GetStorageSizeEPlS1_S1__nid_no_patch,
    _ZN15AbstractStorage12LocalStorageD0Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalStorageD1Ev_nid_no_patch,
    _ZN15AbstractStorage12LocalStorageD2Ev_nid_no_patch,
    _ZNK15AbstractStorage11LocalFolder10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage11LocalFolder13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage11LocalFolder7GetStatEPNS_4StatE_nid_no_patch,
    _ZNK15AbstractStorage12LocalContent10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage12LocalContent13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage12LocalContent7GetStatEPNS_4StatE_nid_no_patch,
    _ZNK15AbstractStorage12LocalService14GetServiceTypeEv_nid_no_patch,
    _ZNK15AbstractStorage12LocalStorage10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage12LocalStorage13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage12LocalStorage7GetStatEPNS_4StatE_nid_no_patch,
};

const char* kStubNames[] = {
    "_ZN15AbstractStorage11LocalFolder4OpenENS_8ItemTypeE",
    "_ZN15AbstractStorage11LocalFolder5CloseEv",
    "_ZN15AbstractStorage11LocalFolder6RemoveEb",
    "_ZN15AbstractStorage11LocalFolderD0Ev",
    "_ZN15AbstractStorage11LocalFolderD1Ev",
    "_ZN15AbstractStorage11LocalFolderD2Ev",
    "_ZN15AbstractStorage12LocalContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3_",
    "_ZN15AbstractStorage12LocalContent4OpenEit",
    "_ZN15AbstractStorage12LocalContent4ReadEPvlPl",
    "_ZN15AbstractStorage12LocalContent5CloseEv",
    "_ZN15AbstractStorage12LocalContent5FlushEv",
    "_ZN15AbstractStorage12LocalContent5WriteEPKvlPl",
    "_ZN15AbstractStorage12LocalContent6RemoveEv",
    "_ZN15AbstractStorage12LocalContent8SeekByteEliPl",
    "_ZN15AbstractStorage12LocalContent8SeekTimeElPl",
    "_ZN15AbstractStorage12LocalContentD0Ev",
    "_ZN15AbstractStorage12LocalContentD1Ev",
    "_ZN15AbstractStorage12LocalContentD2Ev",
    "_ZN15AbstractStorage12LocalService13SearchStorageEv",
    "_ZN15AbstractStorage12LocalService4StopEv",
    "_ZN15AbstractStorage12LocalService5StartEv",
    "_ZN15AbstractStorage12LocalServiceC1Ev",
    "_ZN15AbstractStorage12LocalServiceC2Ev",
    "_ZN15AbstractStorage12LocalServiceD0Ev",
    "_ZN15AbstractStorage12LocalServiceD1Ev",
    "_ZN15AbstractStorage12LocalServiceD2Ev",
    "_ZN15AbstractStorage12LocalStorage14GetStorageSizeEPlS1_S1_",
    "_ZN15AbstractStorage12LocalStorageD0Ev",
    "_ZN15AbstractStorage12LocalStorageD1Ev",
    "_ZN15AbstractStorage12LocalStorageD2Ev",
    "_ZNK15AbstractStorage11LocalFolder10GetServiceEv",
    "_ZNK15AbstractStorage11LocalFolder13GetCapabilityEv",
    "_ZNK15AbstractStorage11LocalFolder7GetStatEPNS_4StatE",
    "_ZNK15AbstractStorage12LocalContent10GetServiceEv",
    "_ZNK15AbstractStorage12LocalContent13GetCapabilityEv",
    "_ZNK15AbstractStorage12LocalContent7GetStatEPNS_4StatE",
    "_ZNK15AbstractStorage12LocalService14GetServiceTypeEv",
    "_ZNK15AbstractStorage12LocalStorage10GetServiceEv",
    "_ZNK15AbstractStorage12LocalStorage13GetCapabilityEv",
    "_ZNK15AbstractStorage12LocalStorage7GetStatEPNS_4StatE"
};

void RequireThrowsStub(ThrowingStub stub, const char* name, unsigned line) {
    try {
        stub();
    } catch (const std::runtime_error&) {
        return;
    }
    std::fprintf(stderr, "libSceAbstractLocal stub did not throw: %s (line %u)\n", name, line);
    std::abort();
}

}

int main() {
    static_assert(sizeof(kStubs) / sizeof(kStubs[0]) == 40, "catalog declaration count changed");
    for (unsigned i = 0; i < sizeof(kStubs) / sizeof(kStubs[0]); ++i) {
        RequireThrowsStub(kStubs[i], kStubNames[i], __LINE__);
    }
    return 0;
}
