//
// Created by retretor on 11.06.2022.
//

#include "Game.h"

Game::Game() {
    gameState = GameState_Start;
}

Game::~Game() {

}

void Game::Print() const {

}



void Game::Play() {
    bool IsPlay = true;
    while(IsPlay) {
        switch (gameState) {
            case GameState_Start:
                Start();
                break;
            case GameState_CreateDeck:
                CreateDeck();
                break;
            case GameState_CreatePlayers:
                CreatePlayers();
                break;
            case GameState_CreateTable:
                CreateTable();
                break;
            case GameState_CreateHands:
                CreateHands();
                break;

            case GameState_Bet:
                Bet();
                break;


            case GameState_OpenCardsTable:
                OpenCardsTable();
                break;


            case GameState_OpenCardsPlayers:
                OpenCardsPlayers();
                break;
            case GameState_End:
                IsPlay = false;
                break;
        }
    }
    std::cout << "Game is over" << std::endl;
}

void Game::Start() {
    gameState = GameState_CreateDeck;
    std::cout << "Game started, Hello players!" << std::endl;
}

void Game::CreateDeck() {
    gameState = GameState_CreatePlayers;
    deck.Shuffle();
}

void Game::CreatePlayers() {
    gameState = GameState_CreateTable;
    manager.CreatePlayers(&deck);
}

void Game::CreateTable() {
    gameState = GameState_CreateHands;
    manager.CreateTable(&deck);
}
void Game::CreateHands() {
    gameState = GameState_Bet;
    manager.CreateHand();
}


void Game::Bet() {
    manager.SetABet();

    if(countOfSteps == 4)
    {
        gameState = GameState_OpenCardsPlayers;
        countOfSteps = 0;
    }
    else
    {
        gameState = GameState_OpenCardsTable;
        countOfSteps++;
    }
}


void Game::OpenCardsTable() {
    gameState = GameState_Bet;
    manager.PrintTable(countOfSteps);
}

void Game::OpenCardsPlayers() {
    manager.PlayerHasCombo();
    manager.Result();
    manager.PrintPlayers();
    gameState = GameState_End;
}
