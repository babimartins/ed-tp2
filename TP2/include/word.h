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

    bool operator< (const Word &other) const {
        std::string left = _word;
        std::string right = other._word;
        unsigned long long size = left.length() < right.length() ? left.length() : right.length();
        for (int i = 0; i < size; ++i) {
            if (left[i] != right[i]) {
                return left[i] < right[i];
            }
        }
        return true;
    }

    bool operator> (const Word &other) const {
        return other < *this;
    }

    bool operator== (const Word &other) const {
        return _word == other._word;
    }

    bool operator<= (const Word &other) const {
        return (*this < other) || *this == other;
    }

    bool operator>= (const Word &other) const {
        return (*this > other) || *this == other;
    }
};

#endif //WORD_H
