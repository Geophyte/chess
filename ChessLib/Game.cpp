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
	//std::string fenString = board.getFenString();
	//char king = player->getTeam() == Team::Player1 ? 'K' : 'k';
	//char kingOffset = 0;
	//for (auto i : fenString) {
	//	if (i == king)
	//		break;
	//	if (isdigit(i))
	//		kingOffset += (i - '0');
	//	else if (isalpha(i))
	//		kingOffset += 1;
	//}
	//std::vector<char> moves;
	//std::vector<char> captures;
	//char currOffset = 0;
	//for (auto i : fenString) {
	//	if (isalpha(i)) {
	//		if (islower(king) != islower(i)) {
	//			board[currOffset]->getMoves(board, currOffset, moves, captures);
	//		}
	//		currOffset += 1;
	//	}
	//	else if (isdigit(i))
	//		currOffset += (i - '0');
	//}
	//if (std::find(captures.begin(), captures.end(), kingOffset) != captures.end())
	//	return true;
	return false;
}


bool Game::isGameOver(Player* player) {
	//std::vector<char> moves;
	//std::vector<char> captures;
	//char currOffset = 0;
	//char king = player->getTeam() == Team::Player1 ? 'K' : 'k';
	//std::string fenString = board.getFenString();
	//for (auto i : fenString) {
	//	if (isalpha(i)) {
	//		if (islower(king) == islower(i)) {
	//			moves.clear();
	//			captures.clear();
	//			board[currOffset]->getMoves(board, currOffset, moves, captures);
	//			for (auto j : moves) {
	//				board.makeMove(currOffset, j);
	//				bool cond = !isInCheck(player);
	//				board.undoMove(j, currOffset);
	//				if (cond)
	//					return false;
	//			}
	//			for (auto j : captures) {
	//				board.makeMove(currOffset, j);
	//				bool cond = !isInCheck(player);
	//				board.undoMove(j, currOffset);
	//				if (cond)
	//					return false;
	//			}
	//		}
	//		currOffset += 1;
	//	}
	//	else if (isdigit(i))
	//		currOffset += (i - '0');
	//}
	return true;
}


void Game::play() {
	//printer.print(board.getFenString());
	//while (status != GameStatus::End) {
	//	while(true) {
	//		std::pair<char, char> move = currPlayer->getMove(board);
	//		board.makeMove(move.first, move.second);
	//		if (!isInCheck(currPlayer)) {
	//			break;
	//		}
	//		board.undoMove(move.second, move.first);
	//	}
	//	std::swap(currPlayer, secondPlayer);
	//	printer.refreshScreen(board.getFenString());
	//	if (isInCheck(currPlayer)) {
	//		if (isGameOver(currPlayer))
	//			status = GameStatus::End;
	//		else {
	//			status = GameStatus::InCheck;
	//			std::cout << "In check!";
	//		}
	//	}
	//}
	endGame();
}


void Game::endGame() const{
	if (currPlayer->getTeam() == Team::Player1)
		std::cout << "Black win!";
	else
		std::cout << "White win!";
}

Game::~Game() {
	delete currPlayer;
	delete secondPlayer;
}