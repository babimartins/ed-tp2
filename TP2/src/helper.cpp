#include "../include/helper.h"

void removePunctuation(std::string* word) {
    char chars[] = ".,!?:;_";
    int indexes[(*word).size()], count = 0;
    for (int i = 0; i < (*word).size(); ++i) {
        for (int j = 0; j < 7; ++j) {
            if ((*word)[i] == chars[j]) {
                char a = (*word)[i];
                indexes[count] = i;
                count++;
                break;
            }
        }
    }
    for (int i = count - 1; i >= 0; --i) {
        (*word).erase(indexes[i], 1);
    }
}

void toLowerCaseChar(char *letter) {
    if (*letter <= 'Z' && *letter >= 'A') {
        *letter = *letter - ('Z' - 'z');
    }
}

void toLowerCaseString(std::string *word) {
    for (char & c : *word) {
        if (c <= 'Z' && c >= 'A') {
            c = c - ('Z' - 'z');
        }
    }
}