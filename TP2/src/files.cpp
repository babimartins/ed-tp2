#include <iostream>
#include <fstream>
#include <cstdio>
#include "../include/files.h"
#include "../include/msgassert.h"

void readFile(const std::string& filename, Vector<std::string>* words) {
    std::fstream file;
    file.open(filename, std::fstream::in);

    if (file.is_open()) {
//        int numRounds, initAmount;
//        file >> numRounds;
//        file >> initAmount;
//        match->setNumRounds(numRounds);
//        match->setInitAmount(initAmount);
//        Vector<Round> rounds;
//        int numPlayers, initBet, countRounds = 0;
//
//        while (countRounds < numRounds) {
//            file >> numPlayers;
//            file >> initBet;
//            Round round;
//            round.setNumPlays(numPlayers);
//            round.setInitBet(initBet);
//
//            std::string line, playersData[numPlayers][8];
//            for (int i = 0; i < numPlayers; ++i) {
//                for (auto &str: playersData[i]) {
//                    str = "";
//                }
//            }
//            for (int i = 0; i < numPlayers; ++i) {
//                std::string data;
//                int max = 8;
//                for (int j = 0; j < max; ++j) {
//                    if (playersData[i][j].empty()) {
//                        file >> data;
//                        if (j == 1 && std::isdigit(data[0])) {
//                            max = 7;
//                        }
//                        if (j == 7 && !std::isdigit(data[0])) {
//                            playersData[i + 1][0] = data;
//                            ++j;
//                        } else {
//                            playersData[i][j] = data;
//                        }
//                    }
//                }
//            }
//
//            Vector<Play> plays;
//            for (int j = 0; j < numPlayers; ++j) {
//                Play play;
//                std::string playerName;
//                int bet;
//                Vector<std::string> hand;
//                if (playersData[j][7].empty()) {
//                    playerName = playersData[j][0];
//                    bet = std::stoi(playersData[j][1]);
//                    for (int k = 0; k < 5; ++k) {
//                        hand.push(playersData[j][k + 2]);
//                    }
//                } else {
//                    playerName = playersData[j][0] + " " + playersData[j][1];
//                    bet = std::stoi(playersData[j][2]);
//                    for (int k = 0; k < 5; ++k) {
//                        hand.push(playersData[j][k + 3]);
//                    }
//                }
//                play = Play(playerName, bet, hand);
//                plays.push(play);
//                Word player = Word(playerName, initAmount);
//                match->updatePlayer(player);
//            }
//
//            round.setPlays(plays);
//            rounds.push(round);
//            countRounds++;
//        }
//        match->setRounds(rounds);
    } else {
        erroAssert(false, "FileLib - Erro ao abrir o arquivo, verifique a existencia dele na pasta raiz");
    }

    file.close();
}

void writeFile(const std::string &filename, Vector<Word> wordsCount) {
    std::fstream file;
    FILE *fp = freopen(filename.c_str(), "w", stdout);
//    match.printResults();
    fclose(fp);
}
