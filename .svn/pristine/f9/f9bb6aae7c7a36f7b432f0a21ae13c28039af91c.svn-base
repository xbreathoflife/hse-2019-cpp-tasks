#include "GameController.h"

GameController::GameController(Board &board_, BoardView &view_) : board(board_), view(view_) {}

void GameController::runGame() {
    GameState state;
    while (true) {
		Player player = board.currentPlayer();
	    view.printField(board.getField(), false);
		int x, y, flag = 0;
		while (true) {
			ReadResult result = view.readMove(x, y, player); 
			if (result == ReadResult::FINISHED) {
				flag = 1;
				break;
			}
			if ((result == ReadResult::NOT_FINISHED && !board.canMove(x, y, player)) || result == ReadResult::WRONG_FORMAT) {
				view.printBadMove();
			} else {
				board.move(x, y, player);
				break;
	    	}
		}
		if (flag == 1) {
	    	break;
		}
		state = board.getState();
		if (state != GameState::NOT_FINISHED) {
	    	view.printField(board.getField(), true);
	    	view.printResult(state);
	    	break;
		}
    }

}