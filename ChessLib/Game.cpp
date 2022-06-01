#include "Game.h"
#include "Players/HumanPlayer.h"
#include "Players/RandomPlayer.h"

#include <algorithm>
#include <memory>
#include <thread>
#include <chrono>

Game::Game(Player::Type first, Player::Type second) {
	initPlayer(Team::Player1, first, currPlayer);
	initPlayer(Team::Player2, second, secondPlayer);
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


void Game::play(unsigned delay) {
	printer.printTeam(currPlayer->getTeam(), board);
	while (status != GameStatus::End && status != GameStatus::Stalemate) {
		Move move = currPlayer->getMove(board, printer);
		board.makeMove(move);
		if (move.type == Move::Type::Promotion)
			board.switchPromotion(move.cDest, move.newFigure);
		currPlayer.swap(secondPlayer);
		std::vector<char> figures;
		board.getTeamOffsets(currPlayer->getTeam(), figures);
		for (auto i : figures)
			board.getPiece(i)->onNextTurn();

		std::chrono::milliseconds duration(delay);
		std::this_thread::sleep_for(duration);

		printer.clear();
		printer.printTeam(currPlayer->getTeam(), board);
		if (isInCheck(currPlayer.get())) {
			if (!hasMoves(currPlayer.get()))
				status = GameStatus::End;
			else {
				status = GameStatus::InCheck;
				std::cout << "In check!\n";
			}
		}
		else if (!hasMoves(currPlayer.get()))
			status = GameStatus::Stalemate;
	}
	printer.clear();
	printer.print(board.getFenString());
	endGame();
}

void Game::initPlayer(Team team, Player::Type type, std::unique_ptr<Player>& player) const
{
	switch (type)
	{
	case Player::Type::HumanPlayer:
		player = std::make_unique<HumanPlayer>(team);
		break;
	case Player::Type::RandomPlayer:
		player = std::make_unique<RandomPlayer>(team);
		break;
	}
}

void Game::endGame() const{
	if (status == GameStatus::End) {
		if (currPlayer->getTeam() == Team::Player1)
			std::cout << "Red win!"; //"Black win!";
		else
			std::cout << "Blue win!"; //"White win!";
	}
	else
		std::cout << "Stalemate!";
}