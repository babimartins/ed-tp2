#include <utility>
#include "../include/word.h"

Word::Word() {
    _word = "";
    _count = 0;
}

Word::Word(std::string word, int count) {
    _word = std::move(word);
    _count = count;
}

void Word::print() {
    std::cout << _word << " " << _count << std::endl;
}
