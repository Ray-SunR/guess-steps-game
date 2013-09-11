CXX = g++
CXXFLAGS = -Wall -MMD
OBJECTS = scoreboard.o player.o guess-steps-game.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = guess-steps-game

EXEC: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
