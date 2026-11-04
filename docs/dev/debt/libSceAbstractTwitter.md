# libSceAbstractTwitter technical debt

### Known export names; ABI prototypes unverified

- 68 pending exports in [Export.cpp](../../../core/libs/prx/libSceAbstractTwitter/Export.cpp) are present in the [PS5-3.20_Libs](https://github.com/DNNDHH/PS5-3.20_Libs) inventory. Their prototypes and behavior are unverified. They use the no-parameter import-resolution convention and throw through `NotImplemented_nid_no_patch`; these declarations make no ABI or behavior claim.

### Additional catalog exports (PS5 13.60 stub-library catalog)

- [libSce catalog exports](../../../core/libs/prx/libSceAbstractTwitter/Export.cpp) - 44 named callable exports complete the set the [PS5 13.60 function stub library catalog](https://github.com/xdCloudy/PS5-13.60-Function-Stub-Library/blob/bfec40deb4c47a17d7603ee2bc79aa6862c0c56b/data/firmware-13.60/libsceabstracttwitter-9cd9b3c8b1.jsonl) gives as `defined_function_export` with `source_evidence: [firmware_export_table, verified_nid_name_map]`, and were absent from the repository. Names and NIDs come from that catalog; the catalog publishes no prototypes and no signature information, so the declarations use the no-parameter unknown-signature convention and the bodies throw through `NotImplemented_nid_no_patch`. Console behaviour is not measured.
