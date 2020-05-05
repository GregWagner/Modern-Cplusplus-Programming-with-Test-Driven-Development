#include "gmock/gmock.h"

class Soundex {

};

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;
}
