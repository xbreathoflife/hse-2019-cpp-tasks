#include <cstring>
#include "GameController.h"
#include "NcursesBoardView.h"
#include "StdioBoardView.h"

int main(int argc, char *argv[]) {
    Board board;

    if (argc == 2 && !strcmp(argv[1], "curses")) {
        NcursesBoardView nview;
        GameController controller(board, nview);
        controller.runGame();
    } else {
        if (argc == 2 && !strcmp(argv[1], "silent")) {
	        StdioBoardView sview(GameType::SILENT);
            GameController controller(board, sview);
            controller.runGame();
        } else {
	        StdioBoardView sview(GameType::DEFAULT);
            GameController controller(board, sview);
            controller.runGame();
        }

    } 
    
    return 0;
}