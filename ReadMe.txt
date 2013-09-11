Contributor: Renchen Sun (Ray)


Compilation
-------------------
make

An executable file named guess-steps-game would be generated

Run
------------------
./guess-steps-game


Instruction:
------------------
This program is an implementaion of a game. Two players are involved in this game, and two integers n and k are provided. Those two inegers are strictly larger than 0 while k <= n. A global counter in this game is initialized to n. Two players take turns to make their moves in order to win. Once the global counter is deducted to 0 or lower, the one who makes the move wins the game. 

The integer k stands for max deduction number. Any move that is larger than this number will be rounded to k, otherwise there is no difference. 
The integer n stands for the global counter. 


Commands
-----------------
game n k sa sb
	-Start a new game with total counter n and max deduction k. Parameters sa and sb indicates which type of input for those two players will be taken, respectively. stdin indicates that the source input of player is from cin, otherwise that player's move is from a file. 

quit
	-Ends the program


Example
----------------

test11A1.txt:
------------
3
7
9
12

Input:
------------
game 40 7 stdin stdin
3
10
7
8
9
10
12
game 40 7 stdin test11A1.txt
10
8
10
game 40 7 test11A1.txt stdin
10
8
10
quit

Output:
------------
Total is 40, max deduction is 7
Player A's move
Total is 37
Player B's move
Total is 30
Player A's move
Total is 23
Player B's move
Total is 16
Player A's move
Total is 9
Player B's move
Total is 2
Player A's move
Total is -5
Player A wins
Score is
A 1
B 0
Total is 40, max deduction is 7
Player B's move
Total is 37
Player A's move
Total is 30
Player B's move
Total is 23
Player A's move
Total is 16
Player B's move
Total is 9
Player A's move
Total is 2
Player B's move
Total is -5
Player B wins
Score is
A 1
B 1
Total is 40, max deduction is 7
Player A's move
Total is 37
Player B's move
Total is 30
Player A's move
Total is 23
Player B's move
Total is 16
Player A's move
Total is 9
Player B's move
Total is 2
Player A's move
Total is -5
Player A wins
Score is
A 2
B 1
