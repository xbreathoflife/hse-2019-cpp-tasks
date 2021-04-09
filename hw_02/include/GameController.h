#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include "BoardView.h"
#include "Board.h"

class GameController {
public:
    explicit GameController(Board &board_, BoardView &view_);
    void runGame();

private:
    Board &board;
    BoardView &view;
};

#endif /* GAMECONTROLLER_H_ */