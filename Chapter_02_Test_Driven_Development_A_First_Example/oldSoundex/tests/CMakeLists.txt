include(GoogleTest)
add_executable(tests SoundexTest.cpp ../src/Soundex.cpp)
target_link_libraries(tests GTest::GTest)
gtest_discover_tests(tests)