//#include "Game.h"
//#include "King.h"
//#include <iostream>
//#include <stdexcept>
//#include <typeinfo>
//
//Game::Game(Player* player1, Player* player2) {
//	if (player1->getColour() == Colour::White && player2->getColour() == Colour::Black) {
//		currPlayer = player1;
//	}
//	else if (player1->getColour() == Colour::Black && player2->getColour() == Colour::White) {
//		currPlayer = player2;
//	}
//	else
//		throw std::invalid_argument("Players should have different colours of figures");
//	this->player1 = player1;
//	this->player2 = player2;
//	board = new Board;
//}
//
//bool Game::inCheck(const Player& player) const {
//	Tile* king = board->getKing(player.getColour());
//	for (int i = 0; i < board->SIZE; ++i) {
//		for (int j = 0; j < board->SIZE; ++j) {
//			Piece* currPiece = board->getSquare(j, i)->getPiece();
//			if (currPiece == nullptr)
//				continue;
//			if (currPiece->getColour() != player.getColour())
//				if (currPiece->canMoveTo(*board, *(board->getSquare(j, i)), *king))
//					return true;
//		}
//	}
//	return false;
//}
//
//bool Game::makeMove(const Move& move) {
//	// can't move empty tale
//	if (move.from->getPiece() == nullptr)
//		return false;
//	// can't move not current player's figure
//	if (move.from->getPiece()->getColour() != currPlayer->getColour())
//		return false;
//	// can't move figure that way
//	if (!(move.from->getPiece()->canMoveTo(*board, *(move.from), *(move.to))))
//		return false;
//	// we should eliminate in check status at first
//	if (status == GameStatus::InCheck && inCheck(*currPlayer))
//		return false;
//	// move figure
//	if (move.to->getPiece() != nullptr) {
//		move.to->getPiece()->setKilled(true);
//	}
//	move.to->setPiece(move.from->getPiece());
//	move.to->getPiece()->setFirstMove(false);
//	move.from->setPiece(nullptr);
//	// @TODO if moved piece is king then refresh its coordinate on board (WhiteKingTile and blackKingTile)
//	// check if opponent is in check now
//	if (currPlayer == player1)
//		currPlayer = player2;
//	else
//		currPlayer = player1;
//	if (inCheck(*currPlayer))
//		status = GameStatus::InCheck;
//	// @TODO add check if game is over
//	return true;
//}
//
//void Game::play() {
//	while (status != GameStatus::BlackWin && status != GameStatus::WhiteWin) {
//		bool temp = false;
//		while (!temp) {
//			temp = makeMove(currPlayer->getMove(*board));
//		}
//		if (status == GameStatus::InCheck)
//			std::cout << "In Check!!";
//	}
//	endGame();
//}
//
//void Game::endGame() {
//	if (status == GameStatus::WhiteWin)
//		std::cout << "White won";
//	else if (status == GameStatus::BlackWin)
//		std::cout << "Black won";
//	delete board;
//}

#include "Game.h"
#include "Players/HumanPlayer.h"
#include <algorithm>

Game::Game(Game::Players player1, Game::Players player2) {
	Game::Players p[] = { player1, player2 };
	if (player1 == Game::Players::Human)
		currPlayer = std::make_unique<HumanPlayer>(1);
	if (player2 == Game::Players::Human)
		secondPlayer = std::make_unique<HumanPlayer>(0);
}


bool Game::isInCheck(Player* player) const {
	std::string fenString = board.getFenString();
	char king = player->getTeam() == Team::Player1 ? 'K' : 'k';
	char kingOffset = 0;
	for (auto i : fenString) {
		if (i == king)
			break;
		if (isdigit(i))
			kingOffset += (i - '0');
		else if (isalpha(i))
			kingOffset += 1;
	}
	std::vector<char> moves;
	std::vector<char> captures;
	char currOffset = 0;
	for (auto i : fenString) {
		if (isalpha(i)) {
			if (islower(king) != islower(i)) {
				board[currOffset]->getMoves(board, currOffset, moves, captures);
			}
			currOffset += 1;
		}
		else if (isdigit(i))
			currOffset += (i - '0');
	}
	if (std::find(captures.begin(), captures.end(), kingOffset) != captures.end())
		return true;
	return false;
}


void Game::play() {
	while (status != GameStatus::End) {

	}
}