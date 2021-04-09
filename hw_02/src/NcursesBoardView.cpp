#include <ncurses.h>
#include "NcursesBoardView.h"

NcursesBoardView::NcursesBoardView() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);
}

NcursesBoardView::~NcursesBoardView() {
    endwin();
}

void NcursesBoardView::printBadMove() {

}

void NcursesBoardView::printGrid() {
    for (int x = 0; x <= FIELD_SIZE * 8; x+=8)
        for(int y = 0; y <= FIELD_SIZE * 4; y++) {
            move(y, x);
            printw("|");
        }

    for (int y = 0; y <= FIELD_SIZE * 4; y+=4)
        for (int x = 0; x <= FIELD_SIZE * 8; x++) { 
            move(y, x);
            printw("-");
        }
    
    for (int y = 0; y <= FIELD_SIZE * 4; y+=4)
        for (int x = 0; x <= FIELD_SIZE * 8; x+=8) {
            move(y, x);
            printw("+");
        }
    
    refresh();
}

void NcursesBoardView::printX(int x, int y) {
    move(y, x);
    printw("X");
    move(y - 1, x - 1);
    printw("X");
    move(y + 1, x + 1);
    printw("X");
    move(y - 1, x + 1);
    printw("X");
    move(y + 1, x - 1);
    printw("X");    
    refresh();
}

void NcursesBoardView::printO(int x, int y) {
    move(y - 1, x - 1);
    printw("O");
    move(y - 1, x);
    printw("O");
    move(y - 1, x + 1);
    printw("O");
    move(y, x - 1);
    printw("O");
    move(y, x + 1);
    printw("O");    
    move(y + 1, x - 1);
    printw("O");
    move(y + 1, x);
    printw("O");
    move(y + 1, x + 1);
    printw("O");
    refresh();
}

void NcursesBoardView::printField(const Field& field, bool is_finished) {
    printGrid();

    for (int y = 0, field_y = 2; y < FIELD_SIZE; y++, field_y +=4)
        for (int x = 0, field_x = 4; x < FIELD_SIZE; x++, field_x+=8)
            if (field.field[x][y] == FieldState::X)
				printX(field_x, field_y);
	    	else if (field.field[x][y] == FieldState::O)
				printO(field_x, field_y);
                
    refresh();
}

ReadResult NcursesBoardView::readMove(int &x, int &y, Player player) {
    static int x_ = 0, y_ = 0, field_x = 4, field_y = 2;
    move(field_y, field_x);
    int enteredChar = getch();
    switch(enteredChar) {
        case 'x':
            return ReadResult::FINISHED;
            break;
        case KEY_UP:
            if (y_ > 0) {
                y_--;
                move(field_y-=4, field_x);
            }
            break;
        case KEY_DOWN:
            if (y_ < FIELD_SIZE - 1) {
                y_++;
                move(field_y+=4, field_x);
            }
            break;
        case KEY_LEFT:
            if (x_ > 0) {
                x_--;
                move(field_y, field_x-=8);
            }
            break;
        case KEY_RIGHT:
            if (x_ < FIELD_SIZE - 1) {
                x_++;
                move(field_y, field_x+=8);
            }
            break;
        case ' ':
            y = y_;
            x = x_;
            break;
    }
    return ReadResult::NOT_FINISHED;
}

void NcursesBoardView::printResult(GameState gameState) {
    move(FIELD_SIZE * 4 + 2, FIELD_SIZE * 4);
    if (gameState == GameState::DRAW) {
        printw("Draw.");
	} else if (gameState == GameState::O_WINS) {
	    printw("O wins!");
	} else if (gameState == GameState::X_WINS) {
		printw("X wins!");
	}
    refresh();
    getch();
 }