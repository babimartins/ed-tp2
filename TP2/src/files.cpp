#include <iostream>
#include <fstream>
#include "../include/files.h"
#include "../include/helper.h"

void readFile(const std::string& filename, Vector<char>* alphabet, Vector<Word>* words) {
    std::fstream file;
    file.open(filename, std::fstream::in);

    if (file.is_open()) {
        std::string line, word;
        char letter;

        std::getline(file, line);

        for (int i = 0; i < 26; ++i) {
            file >> letter;
            toLowerCaseChar(&letter);
            alphabet->push(letter);
        }

        std::getline(file, line);

        while (file >> word) {
            if (!word.empty() && word != "#TEXTO") {
                toLowerCaseString(&word);
                removePunctuation(&word);
                Word newWord = Word(word);
                words->push(newWord);
            }
        }
    } else {
        erroAssert(false, "FileLib - Erro ao abrir o arquivo, verifique a existencia dele na pasta raiz");
    }

    file.close();
}

void writeFile(const std::string &filename, Vector<Word> words) {
    FILE *fp = freopen(filename.c_str(), "w", stdout);
    for (int i = 0; i < words.length(); ++i) {
        words[i].print();
    }
    std::cout << "#FIM";
    fclose(fp);
}
