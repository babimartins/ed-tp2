#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include "word.h"
#include "sort.h"

void removePunctuation(std::string* word);
void toLowerCaseChar(char* letter);
void toLowerCaseString(std::string* word);
Vector<Word> uniteRepeatedWords(Vector<Word> words);

#endif //HELPER_H
