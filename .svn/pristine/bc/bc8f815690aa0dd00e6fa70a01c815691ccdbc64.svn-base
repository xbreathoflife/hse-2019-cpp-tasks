#include "Board.h"

Board::Board() {
    for (int y = 0; y < FIELD_SIZE; y++)
		for (int x = 0; x < FIELD_SIZE; x++)
	    	field.field[x][y] = FieldState::EMPTY;
    current_player = Player::PLAYER_O;
}

bool Board::canMove(int x, int y, Player player) {
    if (current_player == player && x >=  0 && y >= 0 && x < FIELD_SIZE && y < FIELD_SIZE && field.field[x][y] == FieldState::EMPTY)
		return 1;
    return 0;
}

void Board::move(int x, int y, Player player) {
    if (player == Player::PLAYER_X) {
		field.field[x][y] = FieldState::X;
		current_player = Player::PLAYER_O;
    } else {
		field.field[x][y] = FieldState::O;
		current_player = Player::PLAYER_X;
    }
}

Player Board::currentPlayer() {
    return current_player;
}

FieldState Board::checkLine(int x, int y, int shift_x, int shift_y) {
    if (field.field[x][y] == FieldState::EMPTY)
		return FieldState::EMPTY;
    int next_x = x + shift_x, next_y = y + shift_y, row_len = 0;
    while (row_len++ < WIN_LEN - 1) {
		if (next_x < 10 && next_x >= 0 && next_y < 10 && next_y >= 0 && field.field[next_x][next_y] == field.field[x][y]) {
	    	next_x += shift_x;
	    	next_y += shift_y;
		} else {
	    	return FieldState::EMPTY;
		}
    }
    return field.field[x][y];
}

GameState Board::getState() {
    int flag_winner = 0;
    FieldState res;
    for (int y = 0; y < FIELD_SIZE && !flag_winner; y++)
		for (int x = 0; x < FIELD_SIZE; x++)
	    	if ((res = checkLine(x, y, 0, 1)) != FieldState::EMPTY || (res = checkLine(x, y, 1, 0)) != FieldState::EMPTY ||
				(res = checkLine(x, y, 1, 1)) != FieldState::EMPTY || (res = checkLine(x, y, -1, 1)) != FieldState::EMPTY) {
					if (res == FieldState::O)
						return GameState::O_WINS;
					return GameState::X_WINS;
				}
	for (int y = 0; y < FIELD_SIZE; y++)
		for (int x = 0; x < FIELD_SIZE; x++)
			if (field.field[x][y] == FieldState::EMPTY)
				return GameState::NOT_FINISHED;
	return GameState::DRAW;
}