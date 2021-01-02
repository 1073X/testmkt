#include <gtest/gtest.h>

#include <iostream>

namespace miu::project {
extern std::string_view version();
extern std::string_view build_info();
}    // namespace miu::project

TEST(ut_version, version) {
    std::cout << miu::project::version() << std::endl;
    std::cout << miu::project::build_info() << std::endl;
}
