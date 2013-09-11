//
//  main.cpp
//  A3Q4
//
//  Created by Sun Renchen on 2013-06-20.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include "scoreboard.h"
#include "player.h"
using namespace std;
int main(int argc, const char * argv[])
{
    ScoreBoard* SB = ScoreBoard::getInstance();
    Player* A = Player::getInstance(1);
    Player* B = Player::getInstance(2);
    SB->Player_in(*A, *B);
    A->Set_ScoreBoard(SB);
    B->Set_ScoreBoard(SB);
    char command;
    string which;
    bool flag = false;
    while (!flag)
    {
        cin >> command;
        switch (command) {
            case 'g':
                cin >> which;
                if (which == "ame")
                    SB->startGame();
                break;
            case 'q':
                cin >> which;
                if (which == "uit")
                    flag = true;
                break;
            default:
                break;
        }
    }
    return 0;
}

