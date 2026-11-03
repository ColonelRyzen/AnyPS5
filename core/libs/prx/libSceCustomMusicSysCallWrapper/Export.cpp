#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libSceCustomMusicSysCallWrapper/include/InventoryExports.hpp"
#include "prx/libSceCustomMusicSysCallWrapper/include/Api.hpp"
#include <cstdint>
#include <cstddef>
#include "SceTypes.hpp"
#include "prx/libc/include/General.hpp"

extern "C" {

int APS5_VABI sceCustomMusicNetInetNtop(int af, const void* src, char* dst, uint32_t size) {
    (void)af;
    (void)src;
    (void)dst;
    (void)size;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetShutdown(int s, int how) {
    (void)s;
    (void)how;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetSocketAbort(int s, int flags) {
    (void)s;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadAttrGet(Pthread thread, PthreadAttr* attr) {
    (void)thread;
    (void)attr;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadSelf() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicSelect() {
    NotImplemented_nid_no_patch(__func__);
    return 0;
}

}

extern "C" {

int APS5_VABI sceCustomMusicAudiodecClearContext(int32_t handle) {
    (void)handle;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicAudiodecCpuDecode(const AudiodecCtrl* ctrl, const AudiodecCpuMemory* memory, std::uint32_t type) {
    (void)ctrl;
    (void)memory;
    (void)type;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicAudiodecCreateDecoder(AudiodecCtrl* ctrl, uint32_t codecType) {
    (void)ctrl;
    (void)codecType;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicAudiodecDecode(int32_t handle, AudiodecCtrl* ctrl) {
    (void)handle;
    (void)ctrl;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicAudiodecDeleteDecoder(int32_t handle) {
    (void)handle;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicFileClose(int d) {
    (void)d;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicFileLseek(int d, std::int64_t offset, int whence) {
    (void)d;
    (void)offset;
    (void)whence;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicFileOpenRead(const char* path, int flags, std::uint16_t mode) {
    (void)path;
    (void)flags;
    (void)mode;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicFileRead(int d, void* buf, std::size_t nbytes) {
    (void)d;
    (void)buf;
    (void)nbytes;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicKernelGettimeofday(KernelTimeval* tp) {
    (void)tp;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicKernelNanosleep(const KernelTimespec* rqtp, KernelTimespec* rmtp) {
    (void)rqtp;
    (void)rmtp;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetAccept(int s, void* addr, uint32_t* addrlen) {
    (void)s;
    (void)addr;
    (void)addrlen;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetBind() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetConnect(int s, const void* addr, uint32_t addrlen) {
    (void)s;
    (void)addr;
    (void)addrlen;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetCtlInit() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetCtlTerm() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetEpollAbort(int eid, int flags) {
    (void)eid;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetEpollControl(int eid, int op, int id, const NetEpollEvent* event) {
    (void)eid;
    (void)op;
    (void)id;
    (void)event;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetEpollCreate(const char* name, int flags) {
    (void)name;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetEpollDestroy(int eid) {
    (void)eid;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetEpollWait(int eid, NetEpollEvent* events, int maxevents, int timeout) {
    (void)eid;
    (void)events;
    (void)maxevents;
    (void)timeout;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetErrnoLoc() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetInetPton(int af, const char* src, void* dst) {
    (void)af;
    (void)src;
    (void)dst;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetListen(int s, int backlog) {
    (void)s;
    (void)backlog;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetPoolCreate(const char* name, int size, int flags) {
    (void)name;
    (void)size;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetPoolDestroy(int memid) {
    (void)memid;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetRecv(int s, void* buf, size_t len, int flags) {
    (void)s;
    (void)buf;
    (void)len;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetResolverAbort(int rid, int flags) {
    (void)rid;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetResolverCreate(const char* name, int memid, int flags) {
    (void)name;
    (void)memid;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetResolverDestroy(int rid) {
    (void)rid;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetSend(int s, const void* buf, size_t len, int flags) {
    (void)s;
    (void)buf;
    (void)len;
    (void)flags;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetSetsockopt(int s, int level, int optname, const void* optval, uint32_t optlen) {
    (void)s;
    (void)level;
    (void)optname;
    (void)optval;
    (void)optlen;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetSocketClose(int s) {
    (void)s;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicNetSocket(const char* name, int family, int type, int protocol) {
    (void)name;
    (void)family;
    (void)type;
    (void)protocol;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadAttrDestroy(PthreadAttr* attr) {
    (void)attr;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadAttrInit(PthreadAttr* attr) {
    (void)attr;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadCondDestroy(PthreadCond* cond) {
    (void)cond;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadCondInit(PthreadCond* cond, const PthreadCondattr* attr, const char* name) {
    (void)cond;
    (void)attr;
    (void)name;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadCondWait(PthreadCond* cond, PthreadMutex* mutex) {
    (void)cond;
    (void)mutex;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadCreate(Pthread* thread, const PthreadAttr* attr, PthreadEntry entry, void* arg, const char* name) {
    (void)thread;
    (void)attr;
    (void)entry;
    (void)arg;
    (void)name;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadDetach(Pthread thread) {
    (void)thread;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadExit(void* retval) {
    (void)retval;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadJoin(Pthread thread, void** retval) {
    (void)thread;
    (void)retval;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadMutexDestroy(PthreadMutex* mutex) {
    (void)mutex;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadMutexInit(PthreadMutex* mutex, const PthreadMutexattr* attr, const char* name) {
    (void)mutex;
    (void)attr;
    (void)name;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadMutexLock(PthreadMutex* mutex) {
    (void)mutex;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadSetprio(Pthread thread, int prio) {
    (void)thread;
    (void)prio;
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI sceCustomMusicPthreadYield() {
    NotImplemented_nid_no_patch(__func__);
}

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown__plus_LdekyVYugM_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("+LdekyVYugM", libSceCustomMusicSysCallWrapperUnknown__plus_LdekyVYugM_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown__minus_f8PcMdF8L0_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("-f8PcMdF8L0", libSceCustomMusicSysCallWrapperUnknown__minus_f8PcMdF8L0_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_0WBrHbI33Ec_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("0WBrHbI33Ec", libSceCustomMusicSysCallWrapperUnknown_0WBrHbI33Ec_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_0d4Aw8u3xzE_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("0d4Aw8u3xzE", libSceCustomMusicSysCallWrapperUnknown_0d4Aw8u3xzE_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_1auNQHxva3I_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("1auNQHxva3I", libSceCustomMusicSysCallWrapperUnknown_1auNQHxva3I_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_24ZHuc5b0RA_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("24ZHuc5b0RA", libSceCustomMusicSysCallWrapperUnknown_24ZHuc5b0RA_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_2yE7PehS6iI_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("2yE7PehS6iI", libSceCustomMusicSysCallWrapperUnknown_2yE7PehS6iI_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_3DyCYcJudI4_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("3DyCYcJudI4", libSceCustomMusicSysCallWrapperUnknown_3DyCYcJudI4_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_5I2IqwB0Hes_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("5I2IqwB0Hes", libSceCustomMusicSysCallWrapperUnknown_5I2IqwB0Hes_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_5p7ZpbyUKuo_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("5p7ZpbyUKuo", libSceCustomMusicSysCallWrapperUnknown_5p7ZpbyUKuo_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_6PNhaGAw6Ho_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("6PNhaGAw6Ho", libSceCustomMusicSysCallWrapperUnknown_6PNhaGAw6Ho_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_70NNIr_minus_nfFo_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("70NNIr-nfFo", libSceCustomMusicSysCallWrapperUnknown_70NNIr_minus_nfFo_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_7uOVo0lL97g_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("7uOVo0lL97g", libSceCustomMusicSysCallWrapperUnknown_7uOVo0lL97g_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_8t8UK2XkJ1Y_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("8t8UK2XkJ1Y", libSceCustomMusicSysCallWrapperUnknown_8t8UK2XkJ1Y_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_CQv51NIK3i4_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("CQv51NIK3i4", libSceCustomMusicSysCallWrapperUnknown_CQv51NIK3i4_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_DABJz_plus_GrAWg_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("DABJz+GrAWg", libSceCustomMusicSysCallWrapperUnknown_DABJz_plus_GrAWg_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_EaC0JWOBvy4_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("EaC0JWOBvy4", libSceCustomMusicSysCallWrapperUnknown_EaC0JWOBvy4_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_HNx_minus_bHhat18_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("HNx-bHhat18", libSceCustomMusicSysCallWrapperUnknown_HNx_minus_bHhat18_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_J4_plus_14VzlTHM_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("J4+14VzlTHM", libSceCustomMusicSysCallWrapperUnknown_J4_plus_14VzlTHM_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_JSZXadyt_minus_nk_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("JSZXadyt-nk", libSceCustomMusicSysCallWrapperUnknown_JSZXadyt_minus_nk_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_Kxq7i4lQjGg_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("Kxq7i4lQjGg", libSceCustomMusicSysCallWrapperUnknown_Kxq7i4lQjGg_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_L0MmfM0N_minus_y8_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("L0MmfM0N-y8", libSceCustomMusicSysCallWrapperUnknown_L0MmfM0N_minus_y8_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_Mk6mbbOvaBM_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("Mk6mbbOvaBM", libSceCustomMusicSysCallWrapperUnknown_Mk6mbbOvaBM_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_NbAJfB19zUk_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("NbAJfB19zUk", libSceCustomMusicSysCallWrapperUnknown_NbAJfB19zUk_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_QEVVJH35Fis_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("QEVVJH35Fis", libSceCustomMusicSysCallWrapperUnknown_QEVVJH35Fis_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_ROnMWfJ56t8_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("ROnMWfJ56t8", libSceCustomMusicSysCallWrapperUnknown_ROnMWfJ56t8_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_SneVIJUdrLw_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("SneVIJUdrLw", libSceCustomMusicSysCallWrapperUnknown_SneVIJUdrLw_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_Tr_minus_kghWgcoI_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("Tr-kghWgcoI", libSceCustomMusicSysCallWrapperUnknown_Tr_minus_kghWgcoI_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_VDAd516qud8_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("VDAd516qud8", libSceCustomMusicSysCallWrapperUnknown_VDAd516qud8_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_VTS_plus_zlRk_minus_wo_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("VTS+zlRk-wo", libSceCustomMusicSysCallWrapperUnknown_VTS_plus_zlRk_minus_wo_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_Xkm5tRxA0UQ_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("Xkm5tRxA0UQ", libSceCustomMusicSysCallWrapperUnknown_Xkm5tRxA0UQ_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_Y3l3L6A4OYE_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("Y3l3L6A4OYE", libSceCustomMusicSysCallWrapperUnknown_Y3l3L6A4OYE_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_ZiO9aSV1ZKc_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("ZiO9aSV1ZKc", libSceCustomMusicSysCallWrapperUnknown_ZiO9aSV1ZKc_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_bzddXxOnr30_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("bzddXxOnr30", libSceCustomMusicSysCallWrapperUnknown_bzddXxOnr30_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_eTHTXNt0B2k_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("eTHTXNt0B2k", libSceCustomMusicSysCallWrapperUnknown_eTHTXNt0B2k_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_fsQhNY_plus_RJf8_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("fsQhNY+RJf8", libSceCustomMusicSysCallWrapperUnknown_fsQhNY_plus_RJf8_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_gxew9cxe_plus_xk_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("gxew9cxe+xk", libSceCustomMusicSysCallWrapperUnknown_gxew9cxe_plus_xk_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_hd0MG4ZvfRA_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("hd0MG4ZvfRA", libSceCustomMusicSysCallWrapperUnknown_hd0MG4ZvfRA_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_jETJjJLQtas_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("jETJjJLQtas", libSceCustomMusicSysCallWrapperUnknown_jETJjJLQtas_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_jVD2jFJAQ28_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("jVD2jFJAQ28", libSceCustomMusicSysCallWrapperUnknown_jVD2jFJAQ28_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_kso0cI0kq1U_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("kso0cI0kq1U", libSceCustomMusicSysCallWrapperUnknown_kso0cI0kq1U_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_lgRL6Oblmyg_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("lgRL6Oblmyg", libSceCustomMusicSysCallWrapperUnknown_lgRL6Oblmyg_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_mgSEL99WSwA_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("mgSEL99WSwA", libSceCustomMusicSysCallWrapperUnknown_mgSEL99WSwA_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_n0aVoomYuOM_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("n0aVoomYuOM", libSceCustomMusicSysCallWrapperUnknown_n0aVoomYuOM_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_n4jZ2HjzXUo_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("n4jZ2HjzXUo", libSceCustomMusicSysCallWrapperUnknown_n4jZ2HjzXUo_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_oaaW7CuQLV0_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("oaaW7CuQLV0", libSceCustomMusicSysCallWrapperUnknown_oaaW7CuQLV0_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_qqNVevi1LlY_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("qqNVevi1LlY", libSceCustomMusicSysCallWrapperUnknown_qqNVevi1LlY_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_sWVPeXELNss_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("sWVPeXELNss", libSceCustomMusicSysCallWrapperUnknown_sWVPeXELNss_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_sak_plus_IpFmBkk_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("sak+IpFmBkk", libSceCustomMusicSysCallWrapperUnknown_sak_plus_IpFmBkk_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_y2Fu_plus_vFwEXo_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("y2Fu+vFwEXo", libSceCustomMusicSysCallWrapperUnknown_y2Fu_plus_vFwEXo_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_yM_minus_etuyf_minus_2M_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("yM-etuyf-2M", libSceCustomMusicSysCallWrapperUnknown_yM_minus_etuyf_minus_2M_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_zRDEHOFDvzQ_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("zRDEHOFDvzQ", libSceCustomMusicSysCallWrapperUnknown_zRDEHOFDvzQ_nid_no_patch);

int APS5_VABI libSceCustomMusicSysCallWrapperUnknown_zUgaEYLIysQ_nid_no_patch() {
    NotImplemented_nid_no_patch(__func__);
}
APS5_EXPORT("zUgaEYLIysQ", libSceCustomMusicSysCallWrapperUnknown_zUgaEYLIysQ_nid_no_patch);

}
