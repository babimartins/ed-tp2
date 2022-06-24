#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "vector.h"

class Word {
protected:
    std::string _word;
    int _count;

public:
    Word();
    Word(std::string word, int count);

    std::string getPlayerName() const { return _word; }
    int getTotalAmount() const { return _count; }
    void setPlayerName(std::string word) { _word = std::move(word); }
    void setTotalAmount(int count) { _count = count; }

    void print();

    bool operator< (const Word &other) {
//        return lhs[0] < rhs[0];
    }
};

#endif //WORD_H
