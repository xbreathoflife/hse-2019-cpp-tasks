#include "BoardTest.h"

void BoardTest::testMove1() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    DO_CHECK(!b.canMove(0, 0, Player::PLAYER_O));
}
    
void BoardTest::testMove2() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    DO_CHECK(b.canMove(1, 1, Player::PLAYER_O));
}

void BoardTest::testMove3() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    DO_CHECK(!b.canMove(0, 1, Player::PLAYER_X));
}

void BoardTest::testMove4() {
    Board b;
    DO_CHECK(!b.canMove(10, 10, Player::PLAYER_X));
}

void BoardTest::testMove5() {
    Board b;
    DO_CHECK(!b.canMove(-5, 5, Player::PLAYER_X));
}


void BoardTest::testCurrentPlayer1() {
    Board b;
    DO_CHECK(b.currentPlayer() == Player::PLAYER_O);
}

void BoardTest::testCurrentPlayer2() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    DO_CHECK(b.currentPlayer() == Player::PLAYER_O);
}

void BoardTest::testCurrentPlayer3() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 0, Player::PLAYER_O);
    DO_CHECK(b.currentPlayer() == Player::PLAYER_X);
}

void BoardTest::testCheckLine1() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkLine(0, 0, 1, 1) == FieldState::X);
}

void BoardTest::testCheckLine2() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkLine(0, 0, 0, 1) != FieldState::X);
}

void BoardTest::testCheckLine3() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkLine(0, 0, 1, 0) != FieldState::X);
}

void BoardTest::testCheckLine4() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkLine(0, 0, 1, 1) != FieldState::X);
}


/*
void BoardTest::testCheckDown1() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkDown(0, 0) != FieldState::X);
}

void BoardTest::testCheckDown2() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(0, 1, Player::PLAYER_X);
    b.move(0, 2, Player::PLAYER_X);
    b.move(0, 3, Player::PLAYER_X);
    b.move(0, 4, Player::PLAYER_X);
    DO_CHECK(b.checkDown(0, 0) == FieldState::X);
}

void BoardTest::testCheckDown3() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(0, 1, Player::PLAYER_X);
    b.move(0, 2, Player::PLAYER_O);
    b.move(0, 3, Player::PLAYER_X);
    b.move(0, 4, Player::PLAYER_X);
    DO_CHECK(b.checkDown(0, 0) != FieldState::X);
}

void BoardTest::testCheckRight1() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkRight(0, 0) != FieldState::X);
}

void BoardTest::testCheckRight2() {
    Board b;
    b.move(0, 5, Player::PLAYER_X);
    b.move(1, 5, Player::PLAYER_X);
    b.move(2, 5, Player::PLAYER_X);
    b.move(3, 5, Player::PLAYER_X);
    b.move(4, 5, Player::PLAYER_X);
    DO_CHECK(b.checkRight(0, 5) == FieldState::X);
}

void BoardTest::testCheckRight3() {
    Board b;
    b.move(0, 5, Player::PLAYER_X);
    b.move(1, 5, Player::PLAYER_X);
    b.move(3, 5, Player::PLAYER_X);
    b.move(4, 5, Player::PLAYER_X);
    DO_CHECK(b.checkRight(0, 5) != FieldState::X);
}

void BoardTest::testCheckDownRight1() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkDownRight(0, 0) == FieldState::X);
}

void BoardTest::testCheckDownRight2() {
    Board b;
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_X);
    b.move(4, 4, Player::PLAYER_X);
    b.move(5, 5, Player::PLAYER_X);
    DO_CHECK(b.checkDownRight(0, 0) == FieldState::EMPTY);
}

void BoardTest::testCheckDownRight3() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 1, Player::PLAYER_X);
    b.move(2, 2, Player::PLAYER_X);
    b.move(3, 3, Player::PLAYER_O);
    b.move(4, 4, Player::PLAYER_X);
    DO_CHECK(b.checkDownRight(0, 0) == FieldState::EMPTY);
}

void BoardTest::testCheckDownLeft1() {
    Board b;
    b.move(1, 9, Player::PLAYER_X);
    b.move(2, 8, Player::PLAYER_X);
    b.move(3, 7, Player::PLAYER_X);
    b.move(4, 6, Player::PLAYER_X);
    b.move(5, 5, Player::PLAYER_X);
    DO_CHECK(b.checkDownLeft(5, 5) == FieldState::X);
}

void BoardTest::testCheckDownLeft2() {
    Board b;
    b.move(1, 9, Player::PLAYER_O);
    b.move(2, 8, Player::PLAYER_O);
    b.move(3, 7, Player::PLAYER_O);
    b.move(4, 6, Player::PLAYER_X);
    b.move(5, 5, Player::PLAYER_O);
    DO_CHECK(b.checkDownLeft(5, 5) == FieldState::EMPTY);
}

void BoardTest::testCheckDownLeft3() {
    Board b;
    b.move(3, 7, Player::PLAYER_O);
    b.move(4, 6, Player::PLAYER_O);
    b.move(5, 5, Player::PLAYER_O);
    b.move(6, 4, Player::PLAYER_O);
    DO_CHECK(b.checkDownLeft(4, 6) == FieldState::EMPTY);
}
*/
void BoardTest::testGetState1() {
    Board b;
    b.move(0, 0, Player::PLAYER_O);
    b.move(0, 1, Player::PLAYER_O);
    b.move(0, 2, Player::PLAYER_O);
    b.move(0, 3, Player::PLAYER_X);
    b.move(0, 4, Player::PLAYER_X);
    DO_CHECK(b.getState() == GameState::NOT_FINISHED);
}

void BoardTest::testGetState2() {
    Board b;
    b.move(0, 0, Player::PLAYER_O);
    b.move(1, 0, Player::PLAYER_X);
    b.move(0, 1, Player::PLAYER_O);
    b.move(2, 0, Player::PLAYER_X);
    b.move(0, 2, Player::PLAYER_O);
    b.move(3, 0, Player::PLAYER_X);
    b.move(0, 3, Player::PLAYER_O);
    b.move(4, 0, Player::PLAYER_X);
    b.move(0, 4, Player::PLAYER_O);
    DO_CHECK(b.getState() == GameState::O_WINS);
}

void BoardTest::testGetState3() {
    Board b;
    Player player1 = Player::PLAYER_X, player2 = Player::PLAYER_O;
    for (int y = 0; y < FIELD_SIZE - 1; y+=2) {
        for (int i = 0; i < 2; i++)
            for (int x = 0; x < FIELD_SIZE - 1; x+=2) {
                b.move(x, y + i, player1);
                b.move(x + 1, y + i, player2);
            }
        std::swap(player1, player2);
    }
    
    DO_CHECK(b.getState() == GameState::DRAW);
}

void BoardTest::testGetState4() {
    Board b;
    b.move(0, 0, Player::PLAYER_X);
    b.move(1, 0, Player::PLAYER_O);
    b.move(0, 1, Player::PLAYER_X);
    b.move(2, 0, Player::PLAYER_O);
    b.move(0, 2, Player::PLAYER_X);
    b.move(3, 0, Player::PLAYER_O);
    b.move(0, 3, Player::PLAYER_X);
    b.move(4, 0, Player::PLAYER_O);
    b.move(0, 4, Player::PLAYER_X);
    DO_CHECK(b.getState() == GameState::X_WINS);
}

void BoardTest::runAllTests() {
    testMove1();
    testMove2();
    testMove3();
    testMove4();
    testMove5();
    testCurrentPlayer1();
    testCurrentPlayer2();
    testCurrentPlayer3();
    testCheckLine1();
    testCheckLine2();
    testCheckLine3();
    testCheckLine4();
    testGetState1();
    testGetState2();
    testGetState3();
    testGetState4();
}