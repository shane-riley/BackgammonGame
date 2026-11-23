#include "backgammon/version.hpp"

#include <gtest/gtest.h>

TEST(VersionTest, ReturnsNonEmptyVersion)
{
    EXPECT_FALSE(backgammon::version().empty());
}
