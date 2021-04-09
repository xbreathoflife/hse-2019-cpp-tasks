#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "StdioBoardView.h"

StdioBoardView::StdioBoardView(GameType gameType_) : gameType(gameType_) {}

void StdioBoardView::printField(const Field& field, bool is_finished) {
	if (gameType == GameType::DEFAULT || is_finished) {
    	std::cout << "\n";
    	for (int y = 0; y < FIELD_SIZE; y++) {
			for (int x = 0; x < FIELD_SIZE; x++)
	    		if (field.field[x][y] == FieldState::X)
					std::cout << "X";
	    		else if (field.field[x][y] == FieldState::O)
					std::cout << "O";
	    		else
					std::cout << '.';
			std::cout << "\n";
    	}
	}
}

void StdioBoardView::printMoveRequest(Player player) {
    if (player == Player::PLAYER_O) {
		std::cout << "O move: ";
    } else {
		std::cout << "X move: ";
    }
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
	if (*it == '-') 
		it++;
    while (it != s.end() && std::isdigit(*it))
		++it;
    return !s.empty() && it == s.end();
}

ReadResult StdioBoardView::readMove(int &x, int &y, Player player) {
	std::string line;
	printMoveRequest(player);
	std::getline(std::cin, line);
	std::istringstream stream(line);
	std::vector<std::string> tokens;
	std::copy(std::istream_iterator<std::string>(stream),
			  std::istream_iterator<std::string>(),
			  std::back_inserter(tokens));
	if (tokens.size() == 2 && is_number(tokens[0]) && is_number(tokens[1])) {
		y = std::stoi(tokens[0]);
		x = std::stoi(tokens[1]);
		if (x == -1 && y == -1)
			return ReadResult::FINISHED;
		return ReadResult::NOT_FINISHED;
	}
		
	return ReadResult::WRONG_FORMAT;
}

void StdioBoardView::printBadMove() {
	std::cout << "Bad move!\n";
}

void StdioBoardView::printResult(GameState gameState) {
	if (gameState == GameState::DRAW) {
	    std::cout << "Draw.\n";
	} else if (gameState == GameState::O_WINS) {
	   	std::cout << "O wins!\n";
	} else if (gameState == GameState::X_WINS) {
	   	std::cout << "X wins!\n";
	}
}