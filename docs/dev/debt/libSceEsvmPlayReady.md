# libSceEsvmPlayReady technical debt

### Additional catalog exports (PS5 13.60 stub-library catalog)

- [libSce catalog exports](../../../core/libs/prx/libSceEsvmPlayReady/Export.cpp) - the one named callable export of this library that the [PS5 13.60 function stub library catalog](https://github.com/xdCloudy/PS5-13.60-Function-Stub-Library/blob/bfec40deb4c47a17d7603ee2bc79aa6862c0c56b/data/firmware-13.60/libsceesvmplayready-5091672932.jsonl) gives as `defined_function_export` with `source_evidence: [firmware_export_table, verified_nid_name_map]` and that no other library declares, in a library the repository does not carry. The catalog publishes no prototypes and no signature information, so the declaration uses the no-parameter unknown-signature convention and the body throws through `NotImplemented_nid_no_patch`. Console behaviour is not measured.
