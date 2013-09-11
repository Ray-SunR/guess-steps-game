//
//  ScoreBoard.cpp
//  A3Q4
//
//  Created by Sun Renchen on 2013-06-20.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "scoreboard.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
ScoreBoard* ScoreBoard::instance = NULL;
ScoreBoard* ScoreBoard::getInstance()
{
    if (!instance)
    {
        instance = new ScoreBoard;
        atexit(cleanup);
    }
    else
        return instance;
    return instance;
}

void ScoreBoard::cleanup()
{
    //instance->p1 = NULL;
    //instance->p2 = NULL;
    delete instance;
}

void ScoreBoard::Player_in(Player& pl1, Player& pl2)
{
    p1 = &pl1;
    p2 = &pl2;
}

void ScoreBoard::startGame()
{
    string optiona, optionb;
    int order; //1 indicates B first, 0 indicates A first.
    cin >> counter >> max_deduction >> optiona >> optionb;
    p1->Set_Option(optiona);
    p2->Set_Option(optionb);
    cout << "Total is " << counter << "," << " max deduction is " << max_deduction << endl;
    if (turn % 2 == 0)
        order = 1;
    else
        order = 0;
    while (counter > 0)
    {
        if (order % 2 == 0)
        {
            cout << "Player A's move" << endl;
            p1->makeMove();
            order = 1;
        }
        else
        {
            cout << "Player B's move" << endl;
            p2->makeMove();
            order = 0;
        }
        cout << "Total is " << counter << endl;
    }
    p1->Close_file(); // only effective when input source is from file.
    p2->Close_file(); // only effective when input source is from file.
    if (order == 1)
    {
        cout << "Player A wins" << endl;
        score_a++;
    }
    else
    {
        cout << "Player B wins" << endl;
        score_b++;
    }
    cout << "Score is" << endl;
    cout << "A " << score_a << endl;
    cout << "B " << score_b << endl;
    turn++;
}

void ScoreBoard::makeMove(int num)
{
    if (num > max_deduction)
        counter -= max_deduction;
    if (num <= 0)
        counter -= 1;
    if (num > 0 && num <= max_deduction)
        counter -= num;
}

