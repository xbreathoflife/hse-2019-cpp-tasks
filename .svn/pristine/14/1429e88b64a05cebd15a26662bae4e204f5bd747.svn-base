#ifndef BOARD_H_
#define BOARD_H_

enum class Player {PLAYER_X, PLAYER_O};
enum class GameState {NOT_FINISHED, DRAW, X_WINS, O_WINS};
enum class FieldState {X, O, EMPTY};

const int FIELD_SIZE = 10;
const int WIN_LEN = 5;

class Field {
public:
    FieldState field[FIELD_SIZE][FIELD_SIZE];
};

class Board {
public:
    Board();
    ~Board() = default;

    bool canMove(int x, int y, Player player);
    void move(int x, int y, Player player);
    Player currentPlayer();
    FieldState checkLine(int x, int y, int shift_x, int shift_y);
    GameState getState();
    const Field& getField() const {
        return field;
    }
private:
    Field field;
    Player current_player;
};

#endif /* BOARD_H_ */
