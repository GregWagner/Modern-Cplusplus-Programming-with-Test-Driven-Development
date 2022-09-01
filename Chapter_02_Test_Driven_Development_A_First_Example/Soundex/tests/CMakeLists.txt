include(GoogleTest)
add_executable(tests SoundexTests.cpp ../src/Soundex.cpp)
target_link_libraries(tests GTest::GTest)
gtest_discover_tests(tests)