#include <iostream>
#include <getopt.h>
#include "../include/msgassert.h"

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

    return 0;
}
