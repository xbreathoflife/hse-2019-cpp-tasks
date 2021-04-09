#ifndef STDIOBOARDVIEW_H_
#define STDIOBOARDVIEW_H_

#include "BoardView.h"

enum class GameType {DEFAULT, SILENT};

class StdioBoardView : public BoardView {
public:
    StdioBoardView(GameType gameType_);

    void printField(const Field& field, bool is_finished) override;
    ReadResult readMove(int &x, int &y, Player player) override;
    void printBadMove() override;
    void printResult(GameState gameState) override;
private:
    const GameType gameType;
    void printMoveRequest(Player player);

};

#endif /* STDIOBOARDVIEW_H_ */