//
//  Player.h
//  A3Q4
//
//  Created by Sun Renchen on 2013-06-20.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __A3Q4__Player__
#define __A3Q4__Player__

#include <iostream>
#include "scoreboard.h"
#include <string>
#include <fstream>
class ScoreBoard;
class Player
{
public:
    static Player* getInstance(int num);//num is used to indicate which instance client wants to get, beacuse there are only two player objects that can be constructed. 
    void makeMove(); // fetch the next move, and call ScoreBoard::makeMove() to register move.
    std::string const Get_name();
    void Set_istream(std::istream& instream);
    void Set_ScoreBoard(ScoreBoard* instance);
    void Set_Option(const std::string& a);
    void Close_file();
private:
    Player();
    static Player* instance1;
    static Player* instance2;
    static void cleanup();
    static int count;
    std::string option; // used to indicate the input source, stdin or file.
    ScoreBoard* sb;
    std::ifstream in;
    //std::string base;
};

#endif /* defined(__A3Q4__Player__) */
