#include <gtest/gtest.h>

#include <iostream>
#include <meta/info.hpp>

#include "testmkt/version.hpp"

TEST(ut_version, version) {
    std::cout << miu::testmkt::version() << std::endl;
    std::cout << miu::testmkt::build_info() << std::endl;

    std::cout << miu::meta::info() << std::endl;
}
