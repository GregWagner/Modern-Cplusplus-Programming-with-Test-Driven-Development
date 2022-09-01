#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex {
  public:
    std::string encode(const std::string &word) const;
    std::string encodedDigit(char letter) const;

  private:
    static size_t const MAX_CODE_LENGTH{4};
    const std::string NOT_A_DIGIT{"*"};

    std::string head(const std::string &word) const;
    std::string tail(const std::string &word) const;

    std::string upperFront(const std::string &word) const;

    char lower(char c) const;

    std::string encodedDigits(const std::string &word) const;
    void encodeHead(std::string &encoding, const std::string &word) const;
    void encodeTail(std::string &encoding, const std::string &word) const;
    void encodeLetter(std::string &encoding, char letter,
                      char lastLetter) const;

    bool isVowel(char letter) const;
    std::string lastDigit(const std::string &encoding) const;
    bool isComplete(const std::string &encoding) const;
    std::string zeroPad(const std::string &word) const;
};

#endif
