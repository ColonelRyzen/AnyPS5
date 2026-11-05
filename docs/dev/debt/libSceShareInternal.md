# libSceShareInternal technical debt

### Additional catalog exports (PS5 13.60 stub-library catalog)

- [libSceShareInternal catalog exports](../../../core/libs/prx/libSceShareInternal/Export.cpp) - the 1 named callable exports of this library that the [PS5 13.60 function stub library catalog](https://github.com/xdCloudy/PS5-13.60-Function-Stub-Library/blob/bfec40deb4c47a17d7603ee2bc79aa6862c0c56b/data/firmware-13.60/libsceshareinternal-ce7bea75f2.jsonl) gives as `defined_function_export` with `source_evidence: [firmware_export_table, verified_nid_name_map]`, in a library the repository does not carry. Every catalog NID equals the value the repository's own NID algorithm derives from the name. The catalog publishes no prototypes, so each declaration keeps the no-parameter convention and each body throws through `NotImplemented_nid_no_patch`. Console behaviour is not measured.

| Name | NID |
| --- | --- |
| `sceShareSetCommonCurrentStatus` | `U48aJ8+mCRk` |
