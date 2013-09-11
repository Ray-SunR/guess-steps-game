//
//  Player.cpp
//  A3Q4
//
//  Created by Sun Renchen on 2013-06-20.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "player.h"
#include <iostream>
#include <cstdlib>
using namespace std;
int Player::count = 0;
Player* Player::instance1 = NULL;
Player* Player::instance2 = NULL;
Player* Player::getInstance(int num)
{
    if (count < 2)
    {
        if (!instance1)
            instance1 = new Player();
        else
            instance2 = new Player();
        //atexit(cleanup);
        count++;
    }
    else if (num == 1)
        return instance1;
    else
        return instance2;
    return num == 1? instance1: instance2;
}

Player::Player():option(""), sb(NULL){}

void Player::cleanup()
{
    instance1->sb = NULL;
    instance2->sb = NULL;
    delete instance1;
    delete instance2;
}

void Player::Set_ScoreBoard(ScoreBoard* instance)
{
    this->sb = instance;
}

void Player::Set_Option(const string& a)
{
    option = a;
    if (option != "stdin")
    {
	option = "Movefiles/" + option;
        in.open(option.c_str());
    }
}

void Player::makeMove()
{
    int move;
    if (option == "stdin")
        cin >> move;
    else
        in >> move;
    sb->makeMove(move);
}

void Player::Close_file()
{
    if (option != "stdin")
        in.close();
}
