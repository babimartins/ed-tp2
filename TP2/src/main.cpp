#include <iostream>
#include <getopt.h>
#include "../include/msgassert.h"
#include "../include/word.h"
#include "../include/files.h"

std::string inputFile;
std::string outputFile;

void parse_args(int argc, char** argv) {
    int c;

    while ((c = getopt(argc, argv, ":i:o:")) != EOF) {
        switch (c) {
            case 'i':
                inputFile = optarg;
                break;
            case 'o':
                outputFile = optarg;
                break;
            default:
                exit(1);
        }
    }

    erroAssert(inputFile.length() == 0, "main - É necessário fornecer o nome do arquivo de entrada");
    erroAssert(outputFile.length() == 0, "main - É necessário fornecer o nome do arquivo de saída");
}


int main(int argc, char** argv) {
    parse_args(argc, argv);

    VectorCustom<std::string> words;
    VectorCustom<Word> wordsCount;
    readFile(inputFile, &words);
    writeFile(outputFile, wordsCount);

    return 0;
}
