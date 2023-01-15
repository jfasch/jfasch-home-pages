#include <gtest/gtest.h>

#include <sensor-random.h>
#include <sensor-const.h>
#include <sensor-repo.h>

TEST(stl_exercises_suite, sensor_repository_insert_duplicate)
{
    SensorRepository repo;
    repo.add_sensor("Ofen", new RandomSensor(2.3, 666.1));
    repo.add_sensor("Weltraum", new ConstantSensor(-273.15));

    bool inserted;

    inserted = repo.add_sensor("Ofen", new ConstantSensor(0));
    ASSERT_FALSE(inserted);
    ASSERT_EQ(repo.size(), 2);

    inserted = repo.add_sensor("Mond", new ConstantSensor(-100));
    ASSERT_TRUE(inserted);
    ASSERT_EQ(repo.size(), 3);
}
