#pragma once

#include<vector>
#include<string>

namespace simpleparser {
  using namespace std;
  enum TokenType {
    WHITESPACE,
    IDENTIFIER,
    INTEGER_LITERAL,
    STRING_LITERAL,
    OPERATOR,
  };

  class Token{
  public:
    enum TokenType mType{WHITESPACE};
    string mText;
    size_t mStartOffset{0};
    size_t mEndOffset{0};
    size_t mLineNumber{0};
  };
  class Tokenizer{
  public:
    vector<Token> parse(const string &inProgram);
  private:
    void endToken(Token &token, vector<Token> &tokens);
  };
};

