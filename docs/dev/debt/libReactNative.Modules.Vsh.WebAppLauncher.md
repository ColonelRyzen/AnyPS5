# libReactNative.Modules.Vsh.WebAppLauncher technical debt

### Unknown function info

- [libSce catalog exports](../../../core/libs/prx/libReactNative.Modules.Vsh.WebAppLauncher/Export.cpp) - 78 named callable exports complete the set the [PS5 13.60 function stub library catalog](https://github.com/xdCloudy/PS5-13.60-Function-Stub-Library/blob/bfec40deb4c47a17d7603ee2bc79aa6862c0c56b/data/firmware-13.60/libreactnative-modules-vsh-webapplauncher-46dbce980c.jsonl) gives as `defined_function_export` with `verified_nid_binding` and a confirmed 13.60 export, and were absent from the repository. Names and NIDs come from that catalog; prototypes and behaviour are unverified, the declarations use the no-parameter unknown-signature convention and throw through `NotImplemented_nid_no_patch`. Console behaviour is not measured.
