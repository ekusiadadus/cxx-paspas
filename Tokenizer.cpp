//
// Created by ekusiadadus on 2022/09/07.
//

#include "Tokenizer.hpp"

namespace simpleparser {
  using namespace std;
  vector<Token> Tokenizer::parse(const string &inProgram) {
    vector<Token> tokens;
    Token currentToken;

    for (char currentChar : inProgram) {
      switch(currentChar) {
        case '@':
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
          if (currentToken.mType == WHITESPACE){
            currentToken.mType = INTEGER_LITERAL;
            currentToken.mText.append(1, currentChar);
          }else {
            currentToken.mText.append(1, currentChar);
          }
          break;
        case '{':
        case '}':
        case '(':
        case ')':
        case'=':
        case'-':
        case'+':
        case';':
        case',':
          if (currentToken.mType != STRING_LITERAL){
            endToken(currentToken);
            currentToken.mType = OPERATOR;
            currentToken.mText.append(1, currentChar);
            endToken(currentToken);
          } else {
            currentToken.mText.append(1, currentChar);
          }
          break;
      }
    }
    return tokens;
  }

  void Tokenizer::endToken(Token &token, vector<Token> &tokens) {
    if (token.mType != WHITESPACE){
      tokens.push_back(token);
    }
    token.mType = WHITESPACE;
    token.mText.clear();
  }
}