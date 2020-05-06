#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <unordered_map>

class Soundex {
  public:
    std::string encode(const std::string& word) const
    {
      return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
    }

  private:
    static size_t const MAX_CODE_LENGTH {4};
    const std::string NOT_A_DIGIT {"*"};

    std::string head(const std::string& word) const {
      return word.substr(0, 1);
    }

    std::string tail(const std::string& word) const {
      return word.substr(1);
    }

    std::string upperFront(const std::string& word) const {
      return std::string(1,
          std::toupper(static_cast<unsigned char>(word.front())));
    }

  public:
    std::string encodedDigit(char letter) const {
      const std::unordered_map<char, std::string> encodings {
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                    {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"},
        {'l', "4"},
        {'m', "5"}, {'n', "5"},
        {'r', "6"},
      };
      auto it = encodings.find(lower(letter));
      return it == encodings.end() ? NOT_A_DIGIT : it->second;
    }

  private:
    char lower(char c) const {
      return std::tolower(static_cast<unsigned char>(c));
    }

    std::string encodedDigits(const std::string& word) const {
      std::string encoding;
      encodeHead(encoding, word);
      encodeTail(encoding, word);
      return encoding;
    }

    void encodeHead(std::string& encoding, const std::string& word) const {
      encoding += encodedDigit(word.front());
    }

    void encodeTail(std::string& encoding, const std::string& word) const {
      for (auto i = 1u; i < word.length(); ++i) {
        if (!isComplete(encoding)) {
          encodeLetter(encoding, word[i], word[i - 1]);
        }
      }
    }

    void encodeLetter(std::string& encoding, char letter, char lastLetter) const {
      auto digit = encodedDigit(letter);
      if (digit != NOT_A_DIGIT &&
          (digit != lastDigit(encoding) || isVowel(lastLetter))) {
        encoding += digit;
      }
    }

    bool isVowel(char letter) const {
      return std::string("aeiouy").find(lower(letter)) != std::string::npos;
    }

    std::string lastDigit(const std::string& encoding) const {
      if (encoding.empty()) {
        return "";
      }
      return std::string(1, encoding.back());
    }

    bool isComplete(const std::string& encoding) const {
      return encoding.length() == MAX_CODE_LENGTH;
    }

    std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MAX_CODE_LENGTH - word.length();
      return word + std::string(zerosNeeded, '0');
    }
};

#endif
