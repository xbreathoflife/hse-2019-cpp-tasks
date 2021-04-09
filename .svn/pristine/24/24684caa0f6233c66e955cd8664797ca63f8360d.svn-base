#ifndef BOARDVIEW_H_
#define BOARDVIEW_H_

#include "Board.h"

enum class ReadResult {NOT_FINISHED, FINISHED, WRONG_FORMAT};

class BoardView {
public:
    BoardView() = default;
    virtual void printField(const Field& field, bool is_finished) = 0;
    virtual ReadResult readMove(int &x, int &y, Player player) = 0;
    virtual void printBadMove() = 0;
    virtual void printResult(GameState gameState) = 0;
};

#endif /* BOARDVIEW_H_ */