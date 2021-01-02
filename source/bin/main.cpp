
#include <cstdint>
#include <iostream>

#include "project/lib.hpp"

namespace miu::project {
extern std::string_view version();
extern std::string_view build_info();
}    // namespace miu::project

int32_t
main(int32_t, char*[]) {
    std::cout << "version: " << miu::project::version() << std::endl;
    std::cout << "build_info: " << miu::project::build_info() << std::endl;
    miu::project::lib_func();
    return 0;
}
