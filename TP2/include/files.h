#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <fstream>
#include "word.h"
#include "../include/msgassert.h"

void readFile(const std::string& filename, Vector<char>* alphabet, Vector<Word>* words);
void writeFile(const std::string &filename, Vector<Word> words);

#endif //FILES_H
