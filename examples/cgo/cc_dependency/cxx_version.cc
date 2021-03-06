#include <iostream>

#include "examples/cgo/cc_dependency/version.h"

// TODO(yugui) Support Darwin too once Bazel allows it.
//
// Bazel passes two or more -Wl,-rpath to $(CC) when it links a binary with
// shared libraries prebuilt outside of Bazel (i.e. when "srcs" attribute of
// the dependency cc_library contains ".so" files).
// Unfortunately tools/cpp/osx_cc_wrapper.sh, which is $(CC) on Darwin, expects
// only one -Wl,-rpath. So the binary fails to resolve the shared libraries
// at runtime.
#ifndef __APPLE_CC__
# include "examples/cgo/cc_dependency/c_version.h"
#endif

extern "C" void PrintCXXVersion() {
#ifndef __APPLE_CC__
    PrintCVersion();
#endif
    std::cout << "C++ version: " << __cplusplus << std::endl;
}
