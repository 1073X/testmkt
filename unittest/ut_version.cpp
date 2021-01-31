#include <gtest/gtest.h>

#include <iostream>
#include <meta/info.hpp>

#include "project/version.hpp"

TEST(ut_version, version) {
    std::cout << miu::project::version() << std::endl;
    std::cout << miu::project::build_info() << std::endl;

    std::cout << miu::meta::info() << std::endl;
}
