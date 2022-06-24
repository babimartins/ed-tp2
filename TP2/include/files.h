#ifndef FILES_H
#define FILES_H

#include "word.h"

void readFile(const std::string& filename, VectorCustom<std::string>* words);
void writeFile(const std::string &filename, VectorCustom<Word> wordsCount);

#endif //FILES_H
