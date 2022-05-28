#include <iostream>
#include "./Classes/Card.h"
#include "./Classes/Deck.h"
#include "./Classes/Player.h"
#include "./Classes/Table.h"
#include "./Classes/GameManager.h"


int main() {
//create players, deck & table

    try
    {
        Deck deck;
        deck.Shuffle();
        deck.Print();

        GameManager game;
        game.CreatePlayers(game.GetCountOfPlayers(), &deck);
        std::cout << std::endl;

        game.PrintPlayers();
        std::cout << std::endl;


        game.CreateTable(&deck);
        game.PrintTable();


        game.SetABet();
        std::cout << std::endl;


        game.PrintPlayers();
        game.PrintTable();

        deck.Print();
    }
    catch(std::exception& ex)
    {
        std::cerr << "Error: ";
        std::cerr << ex.what();
    }
    return 0;
}