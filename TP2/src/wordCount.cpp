#include <utility>
#include "../include/wordCount.h"

WordCount::WordCount() {
    _word = "";
    _count = 0;
}

WordCount::WordCount(std::string word, int count) {
    _word = std::move(word);
    _count = count;
}

void WordCount::print() {
    std::cout << _word << " " << _count << std::endl;
}
