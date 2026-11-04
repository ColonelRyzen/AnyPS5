#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

extern "C" {
int APS5_VABI _ZN15AbstractStorage10TwitterAPI11SendContentEPKvl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage10TwitterAPIC1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage10TwitterAPID1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolder4OpenENS_8ItemTypeE_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolder5CloseEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolder6RemoveEb_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolderD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolderD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage13TwitterFolderD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent11SetMetadataEPN23sceMetadataReaderWriter8MetadataE_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3__nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent4OpenEit_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent4ReadEPvlPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent5CloseEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent5FlushEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent5WriteEPKvlPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent6RemoveEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent8SeekByteEliPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContent8SeekTimeElPl_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContentD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContentD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterContentD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterService13SearchStorageEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterService4StopEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterService5StartEv_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterServiceC1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterServiceC2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterServiceD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterServiceD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterServiceD2Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterStorage14GetStorageSizeEPlS1_S1__nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterStorageD0Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterStorageD1Ev_nid_no_patch(void);
int APS5_VABI _ZN15AbstractStorage14TwitterStorageD2Ev_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage13TwitterFolder10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage13TwitterFolder13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage13TwitterFolder7GetStatEPNS_4StatE_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterContent10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterContent13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterContent7GetStatEPNS_4StatE_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterService14GetServiceTypeEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterStorage10GetServiceEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterStorage13GetCapabilityEv_nid_no_patch(void);
int APS5_VABI _ZNK15AbstractStorage14TwitterStorage7GetStatEPNS_4StatE_nid_no_patch(void);
}

namespace {

using ThrowingStub = int (*)(void);

const ThrowingStub kStubs[] = {
    _ZN15AbstractStorage10TwitterAPI11SendContentEPKvl_nid_no_patch,
    _ZN15AbstractStorage10TwitterAPIC1Ev_nid_no_patch,
    _ZN15AbstractStorage10TwitterAPID1Ev_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolder4OpenENS_8ItemTypeE_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolder5CloseEv_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolder6RemoveEb_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolderD0Ev_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolderD1Ev_nid_no_patch,
    _ZN15AbstractStorage13TwitterFolderD2Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent11SetMetadataEPN23sceMetadataReaderWriter8MetadataE_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3__nid_no_patch,
    _ZN15AbstractStorage14TwitterContent4OpenEit_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent4ReadEPvlPl_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent5CloseEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent5FlushEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent5WriteEPKvlPl_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent6RemoveEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent8SeekByteEliPl_nid_no_patch,
    _ZN15AbstractStorage14TwitterContent8SeekTimeElPl_nid_no_patch,
    _ZN15AbstractStorage14TwitterContentD0Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterContentD1Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterContentD2Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterService13SearchStorageEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterService4StopEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterService5StartEv_nid_no_patch,
    _ZN15AbstractStorage14TwitterServiceC1Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterServiceC2Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterServiceD0Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterServiceD1Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterServiceD2Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterStorage14GetStorageSizeEPlS1_S1__nid_no_patch,
    _ZN15AbstractStorage14TwitterStorageD0Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterStorageD1Ev_nid_no_patch,
    _ZN15AbstractStorage14TwitterStorageD2Ev_nid_no_patch,
    _ZNK15AbstractStorage13TwitterFolder10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage13TwitterFolder13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage13TwitterFolder7GetStatEPNS_4StatE_nid_no_patch,
    _ZNK15AbstractStorage14TwitterContent10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage14TwitterContent13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage14TwitterContent7GetStatEPNS_4StatE_nid_no_patch,
    _ZNK15AbstractStorage14TwitterService14GetServiceTypeEv_nid_no_patch,
    _ZNK15AbstractStorage14TwitterStorage10GetServiceEv_nid_no_patch,
    _ZNK15AbstractStorage14TwitterStorage13GetCapabilityEv_nid_no_patch,
    _ZNK15AbstractStorage14TwitterStorage7GetStatEPNS_4StatE_nid_no_patch,
};

const char* kStubNames[] = {
    "_ZN15AbstractStorage10TwitterAPI11SendContentEPKvl",
    "_ZN15AbstractStorage10TwitterAPIC1Ev",
    "_ZN15AbstractStorage10TwitterAPID1Ev",
    "_ZN15AbstractStorage13TwitterFolder4OpenENS_8ItemTypeE",
    "_ZN15AbstractStorage13TwitterFolder5CloseEv",
    "_ZN15AbstractStorage13TwitterFolder6RemoveEb",
    "_ZN15AbstractStorage13TwitterFolderD0Ev",
    "_ZN15AbstractStorage13TwitterFolderD1Ev",
    "_ZN15AbstractStorage13TwitterFolderD2Ev",
    "_ZN15AbstractStorage14TwitterContent11SetMetadataEPN23sceMetadataReaderWriter8MetadataE",
    "_ZN15AbstractStorage14TwitterContent13ParseMetadataEPN23sceMetadataReaderWriter8MetadataES3_",
    "_ZN15AbstractStorage14TwitterContent4OpenEit",
    "_ZN15AbstractStorage14TwitterContent4ReadEPvlPl",
    "_ZN15AbstractStorage14TwitterContent5CloseEv",
    "_ZN15AbstractStorage14TwitterContent5FlushEv",
    "_ZN15AbstractStorage14TwitterContent5WriteEPKvlPl",
    "_ZN15AbstractStorage14TwitterContent6RemoveEv",
    "_ZN15AbstractStorage14TwitterContent8SeekByteEliPl",
    "_ZN15AbstractStorage14TwitterContent8SeekTimeElPl",
    "_ZN15AbstractStorage14TwitterContentD0Ev",
    "_ZN15AbstractStorage14TwitterContentD1Ev",
    "_ZN15AbstractStorage14TwitterContentD2Ev",
    "_ZN15AbstractStorage14TwitterService13SearchStorageEv",
    "_ZN15AbstractStorage14TwitterService4StopEv",
    "_ZN15AbstractStorage14TwitterService5StartEv",
    "_ZN15AbstractStorage14TwitterServiceC1Ev",
    "_ZN15AbstractStorage14TwitterServiceC2Ev",
    "_ZN15AbstractStorage14TwitterServiceD0Ev",
    "_ZN15AbstractStorage14TwitterServiceD1Ev",
    "_ZN15AbstractStorage14TwitterServiceD2Ev",
    "_ZN15AbstractStorage14TwitterStorage14GetStorageSizeEPlS1_S1_",
    "_ZN15AbstractStorage14TwitterStorageD0Ev",
    "_ZN15AbstractStorage14TwitterStorageD1Ev",
    "_ZN15AbstractStorage14TwitterStorageD2Ev",
    "_ZNK15AbstractStorage13TwitterFolder10GetServiceEv",
    "_ZNK15AbstractStorage13TwitterFolder13GetCapabilityEv",
    "_ZNK15AbstractStorage13TwitterFolder7GetStatEPNS_4StatE",
    "_ZNK15AbstractStorage14TwitterContent10GetServiceEv",
    "_ZNK15AbstractStorage14TwitterContent13GetCapabilityEv",
    "_ZNK15AbstractStorage14TwitterContent7GetStatEPNS_4StatE",
    "_ZNK15AbstractStorage14TwitterService14GetServiceTypeEv",
    "_ZNK15AbstractStorage14TwitterStorage10GetServiceEv",
    "_ZNK15AbstractStorage14TwitterStorage13GetCapabilityEv",
    "_ZNK15AbstractStorage14TwitterStorage7GetStatEPNS_4StatE"
};

void RequireThrowsStub(ThrowingStub stub, const char* name, unsigned line) {
    try {
        stub();
    } catch (const std::runtime_error&) {
        return;
    }
    std::fprintf(stderr, "libSceAbstractTwitter stub did not throw: %s (line %u)\n", name, line);
    std::abort();
}

}

int main() {
    static_assert(sizeof(kStubs) / sizeof(kStubs[0]) == 44, "catalog declaration count changed");
    for (unsigned i = 0; i < sizeof(kStubs) / sizeof(kStubs[0]); ++i) {
        RequireThrowsStub(kStubs[i], kStubNames[i], __LINE__);
    }
    return 0;
}
