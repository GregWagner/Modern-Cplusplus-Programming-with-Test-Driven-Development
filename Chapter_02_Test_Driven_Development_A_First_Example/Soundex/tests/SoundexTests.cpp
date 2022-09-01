#include "../src/Soundex.hpp"
#include "gmock/gmock.h"

using namespace testing;

class Soundex {
};

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
}