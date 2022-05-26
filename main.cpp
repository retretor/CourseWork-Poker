#include <iostream>
#include "./Classes/Card.h"
#include "./Classes/Deck.h"
#include "./Classes/Player.h"



int main() {
    Deck deck;

    deck.Shuffle();

    deck.Print();
    std::cout << std::endl;




    Player player;

    player.SetCard(deck.TopCard());
    deck.PopCard();

    player.SetCard(deck.TopCard());
    deck.PopCard();

    player.Print();
    std::cout << std::endl;

    deck.Print();
    std::cout << std::endl;


    return 0;
}