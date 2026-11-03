#pragma once

#include "SceTypes.hpp"

extern "C" {

int APS5_VABI sceCustomMusicNetInetNtop(int af, const void* src, char* dst, uint32_t size);
int APS5_VABI sceCustomMusicNetShutdown(int s, int how);
int APS5_VABI sceCustomMusicNetSocketAbort(int s, int flags);
int APS5_VABI sceCustomMusicPthreadAttrGet(Pthread thread, PthreadAttr* attr);
int APS5_VABI sceCustomMusicPthreadSelf();
int APS5_VABI sceCustomMusicSelect();

}
