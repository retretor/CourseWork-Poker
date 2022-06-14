#include <iostream>
#include "./Classes/Game.h"

int main() {
//create players, deck & table
    Game game;
    game.Play();


    /*try
    {
        //---------------------------------------------------------------------
        //create deck
        Deck deck;
        deck.Shuffle();
        deck.Print();

        //create game
        GameManager game;

        //create players
        game.CreatePlayers(game.GetCountOfPlayers(), &deck);
        std::cout << std::endl;

        game.PrintPlayers();
        std::cout << std::endl;

        //create table
        game.CreateTable(&deck);
        game.PrintTable();


        game.CreateHand();
        game.PrintHand();
        //---------------------------------------------------------------------
        //game
        game.SetABet();
        std::cout << std::endl;


        game.PlayerHasCombo();
        game.Result();
        std::cout << std::endl;


        game.PrintPlayers();
        game.PrintTable();


        deck.Print();
    }
    catch(std::exception& ex)
    {
        std::cerr << "Error: ";
        std::cerr << ex.what();
    }*/
    return 0;
}
