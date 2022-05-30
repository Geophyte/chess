#include "Game.h"
#include "Players/HumanPlayer.h"
#include <algorithm>
#include <memory>

Game::Game(Game::Players player1, Game::Players player2) {
	Game::Players p[] = { player1, player2 };
	if (player1 == Game::Players::Human)
		currPlayer = new HumanPlayer(1);
	if (player2 == Game::Players::Human)
		secondPlayer = new HumanPlayer(0);
}


bool Game::isInCheck(Player* player) const {
	auto king = board.getKing(player->getTeam());
	return king->inCheck() != -1;
}

bool Game::hasMoves(Player* player) {
	std::vector<char> figures;
	board.getTeamOffsets(player->getTeam(), figures);
	std::vector<Move> availableMoves;
	for (auto i : figures) {
		board.getMoves(i, availableMoves);
	}
	if (availableMoves.empty())
		return false;
	return true;
}


void Game::play() {
	printer.printTeam(currPlayer->getTeam(), board);
	while (status != GameStatus::End && status != GameStatus::Stalemate) {
		Move move = currPlayer->getMove(board);
		board.makeMove(move);
		if (move.type == Move::Type::Promotion)
			board.switchPromotion(move.cDest, move.newFigure);
		std::swap(currPlayer, secondPlayer);
		std::vector<char> figures;
		board.getTeamOffsets(currPlayer->getTeam(), figures);
		for (auto i : figures)
			board.getPiece(i)->onNextTurn();
		printer.clear();
		printer.printTeam(currPlayer->getTeam(), board);
		if (isInCheck(currPlayer)) {
			if (!hasMoves(currPlayer))
				status = GameStatus::End;
			else {
				status = GameStatus::InCheck;
				std::cout << "In check!\n";
			}
		}
		else if (!hasMoves(currPlayer))
			status = GameStatus::Stalemate;
	}
	printer.clear();
	printer.print(board.getFenString());
	endGame();
}

void Game::endGame() const{
	if (status == GameStatus::End) {
		if (currPlayer->getTeam() == Team::Player1)
			std::cout << "Black win!";
		else
			std::cout << "White win!";
	}
	else
		std::cout << "Stalemate!";
}

Game::~Game() {
	delete currPlayer;
	delete secondPlayer;
}