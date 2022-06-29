#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "vector.h"

class Word {
protected:
    std::string _word;
    int _count;
    static Vector<char> _alphabet;

public:
    Word();
    explicit Word(std::string word);
    Word(std::string word, int count);

    std::string getPlayerName() const { return _word; }
    int getTotalAmount() const { return _count; }
    Vector<char> getAlphabet() const { return _alphabet; }
    void setPlayerName(std::string word) { _word = std::move(word); }
    void setTotalAmount(int count) { _count = count; }
    static void setAlphabet(Vector<char> alphabet) { _alphabet = alphabet; }

    void print();
};

#endif //WORD_H
