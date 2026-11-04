# libSceJson technical debt

### Unknown function info

- [libSce catalog exports](../../../core/libs/prx/libSceJson/Export.cpp) - 63 named callable exports complete the set the [PS5 13.60 function stub library catalog](https://github.com/xdCloudy/PS5-13.60-Function-Stub-Library/blob/bfec40deb4c47a17d7603ee2bc79aa6862c0c56b/data/firmware-13.60/libscejson-4373222ebf.jsonl) gives as `defined_function_export` with `verified_nid_binding` and a confirmed 13.60 export, and were absent from the repository. Names and NIDs come from that catalog; prototypes and behaviour are unverified, the declarations use the no-parameter unknown-signature convention and throw through `NotImplemented_nid_no_patch`. Console behaviour is not measured.
