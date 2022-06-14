//
// Created by retretor on 11.06.2022.
//

#ifndef POKER_GAME_H
#define POKER_GAME_H
#include "Card.h"
#include "GameManager.h"

class Game {
public:

    Game();
    ~Game();
    enum GameState {
        GameState_Start = 1,
        GameState_CreateDeck = 2,
        GameState_CreatePlayers = 3,
        GameState_CreateTable = 4,
        GameState_CreateHands = 5,

        GameState_Bet = 6,
        GameState_OpenCardsPlayers = 7,
        GameState_OpenCardsTable = 8,

        GameState_End = 0
    };

    void Play();
private:
    GameState gameState;

    GameManager manager;
    Deck deck;


    int countOfSteps = 0;

    void Start();
    void Print() const;
    void CreatePlayers();
    void CreateDeck();
    void CreateTable();
    void CreateHands();
    void Bet();
    void OpenCardsPlayers();
    void OpenCardsTable();

};


#endif //POKER_GAME_H
