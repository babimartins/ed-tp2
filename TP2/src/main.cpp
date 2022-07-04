#include <iostream>
#include <getopt.h>
#include "../include/msgassert.h"
#include "../include/files.h"
#include "../include/sort.h"
#include "../include/helper.h"

int m = 0, s = 0;
std::string inputFile, outputFile;
Vector<char> Word::_alphabet = Vector<char>();

void parse_args(int argc, char** argv) {
    int c;
    extern char* optarg;

    m = 0;
    s = 0;
    inputFile = "";
    outputFile = "";

    while ((c = getopt(argc, argv, "i:I:O:o:M:m:s:S:")) != EOF) {
        switch (c) {
            case 'i':
            case 'I':
                inputFile = optarg;
                break;
            case 'o':
            case 'O':
                outputFile = optarg;
                break;
            case 'm':
            case 'M':
                m = std::stoi(optarg);
                break;
            case 's':
            case 'S':
                s = std::stoi(optarg);
                break;
            default:
                exit(1);
        }
    }

    erroAssert(inputFile.length() > 0, "main - É necessário fornecer o nome do arquivo de entrada");
    erroAssert(outputFile.length() > 0, "main - É necessário fornecer o nome do arquivo de saída");
}

int main(int argc, char** argv) {
    parse_args(argc, argv);

    Vector<Word> words;
    Vector<char> newAlphabet;
    readFile(inputFile, &newAlphabet, &words);

    Word::setAlphabet(newAlphabet);
    Sort<Word> sorter;
    sorter.quickSort(words, 0, words.length() - 1, m, s);
    Vector<Word> newWords = uniteRepeatedWords(words);

    writeFile(outputFile, newWords);

    return 0;
}
