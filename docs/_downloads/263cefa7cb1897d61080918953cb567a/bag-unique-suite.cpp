#include "bag-unique.h"

#include <gtest/gtest.h>

TEST(bag_unique_suite, find_by_int_ok)
{
    BagUnique bag;
    bag.insert(std::make_unique<BagUnique::Item>("something", 42));
    bag.insert(std::make_unique<BagUnique::Item>("anything", 666));

    auto item = bag.find_by_int(42);
    ASSERT_NE(item, nullptr);
    ASSERT_EQ(item->first, "something");
    ASSERT_EQ(item->second, 42);
}

TEST(bag_unique_suite, find_by_int_nok)
{
    BagUnique bag;
    bag.insert(std::make_unique<BagUnique::Item>("something", 42));
    bag.insert(std::make_unique<BagUnique::Item>("anything", 666));

    auto item = bag.find_by_int(7);
    ASSERT_EQ(item, nullptr);
}


// attention: remove while iterating:
// https://en.cppreference.com/w/cpp/container/vector/erase

TEST(bag_unique_suite, remove_by_int_ok)
{
    BagUnique bag;
    bag.insert(std::make_unique<BagUnique::Item>("something", 42));
    bag.insert(std::make_unique<BagUnique::Item>("anything", 666));

    std::size_t nremoved = bag.remove_by_int(42);
    ASSERT_EQ(nremoved, 1);
}

