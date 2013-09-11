//
//  ScoreBoard.h
//  A3Q4
//
//  Created by Sun Renchen on 2013-06-20.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __A3Q4__ScoreBoard__
#define __A3Q4__ScoreBoard__

#include <iostream>
#include "player.h"
class Player;
class ScoreBoard
{
public:
    static ScoreBoard* getInstance();
    void makeMove(int num);
    void startGame(); // used to read in the counter and max_deduction
    void const Print_Score(); //used to print the score;
    void Player_in(Player& p1, Player& p2);//Set two players;
private:
    static ScoreBoard* instance;
    ScoreBoard():score_a(0), score_b(0), counter(0), max_deduction(0),turn(1), p1(NULL),p2(NULL){}
    int score_a, score_b;
    static void cleanup();
    int counter, max_deduction;
    int turn;
    Player* p1;
    Player* p2;
};

#endif /* defined(__A3Q4__ScoreBoard__) */
