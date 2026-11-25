#pragma once

#include "SceTypes.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceAgcSuspendPointAndCheckStatus_nid_no_patch(void);
std::uint32_t* APS5_VABI sceAgcVshUnknown_Aozdh0bCcO0(CommandBuffer* buffer);

}

extern "C" {
int APS5_VABI sceAgcGetRegisterDefaultsInternal_0090();
int APS5_VABI sceAgcGetRegisterDefaults_0090();
}
