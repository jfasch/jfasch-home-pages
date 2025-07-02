#include <gtest/gtest.h>
#include <span>

TEST(span_suite, static_extent)
{
    std::array numbers{1,2,3,4,5};                     // <-- 5 at compile time
    std::span span(numbers);
    static_assert(span.size() == 5);
}

TEST(span_suite, dynamic_extent)
{
    std::vector numbers{1,2,3,4,5};                    // <-- 5 at runtime
    std::span span(numbers);
    ASSERT_EQ(span.size(), 5);
}

TEST(span_suite, access)
{
    std::vector numbers{1,2,3,4,5};
    std::span span(numbers);
    ASSERT_EQ(span.size(), 5);
}

TEST(span_suite, undefined_behaviour)
{
    std::vector numbers{1,2,3,4,5};
    std::span span(numbers);
    ASSERT_EQ(true, false);
}

