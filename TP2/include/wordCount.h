#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include "vector.h"

class WordCount {
protected:
    std::string _word;
    int _count;

public:
    WordCount();
    WordCount(std::string word, int count);

    std::string getPlayerName() const { return _word; }
    int getTotalAmount() const { return _count; }
    void setPlayerName(std::string word) { _word = std::move(word); }
    void setTotalAmount(int count) { _count = count; }

    void print();
};

#endif //WORDCOUNT_H
