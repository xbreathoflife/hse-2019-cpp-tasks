#ifndef NCURSESBOARDVIEW_H_
#define NCURSESBOARDVIEW_H_

#include "BoardView.h"

class NcursesBoardView : public BoardView {
public:
    NcursesBoardView();
    ~NcursesBoardView();

    void printField(const Field& field, bool is_finished) override;
    ReadResult readMove(int &x, int &y, Player player) override;
    void printBadMove() override;
    void printResult(GameState gameState) override;

private:
    void printO(int x, int y);
    void printX(int x, int y);
    void printGrid();
};

#endif /* NCURSESBOARDVIEW_H_ */