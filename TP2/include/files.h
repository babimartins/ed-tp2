#ifndef FILES_H
#define FILES_H

#include "wordCount.h"

void readFile(const std::string& filename, VectorCustom<std::string>* words);
void writeFile(const std::string &filename, VectorCustom<WordCount> wordsCount);

#endif //FILES_H
