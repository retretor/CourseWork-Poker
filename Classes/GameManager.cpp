//
// Created by retretor on 26.05.2022.
//

#include "GameManager.h"

GameManager::GameManager() : countOfPlayers(3) {

}
GameManager::~GameManager() {
    for(Player* player : players)
    {
        delete player;
    }
    players.clear();
}
void GameManager::CreatePlayers(int countOfPlayers, Deck* deck) {
    for(int i = 0; i < countOfPlayers; i++)
    {
        players.push_front(new Player);
    }
    for(Player* player : players) {
        for(int i = 0; i < 2; i++)
        {
            player->SetCard(deck->TopCard());
            deck->PopCard();
        }
    }
}

void GameManager::PrintPlayers() {
    for(Player* player : players) {
        player->Print();
        std::cout << std::endl;
    }
}
