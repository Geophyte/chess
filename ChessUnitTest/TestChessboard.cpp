#include "Chessboard.h"
#include "ChessPieces.h"

#include <cmath>
#include <vector>
#include <sstream>
#include <exception>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
inline std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<Move::Type>(const Move::Type& t)
{
	std::wstring result;
	return result;
}

TEST_CLASS(ChessboardUnitTest)
{
	// TEST MOVE
	TEST_METHOD(TestBasicMovePawn)
	{
		Chessboard board("p6k/8/8/8/8/8/8/7K");
		std::vector<char> expected = { 8, 16 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}
	TEST_METHOD(TestBasicMoveRook)
	{
		Chessboard board("r6k/8/8/8/8/8/8/7K");
		std::vector<char> expected = { 1, 2, 3, 4, 5, 6, 8, 16, 24, 32, 40, 48, 56 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}
	TEST_METHOD(TestBasicMoveKnight)
	{
		Chessboard board("n6k/8/8/8/8/8/8/7K");
		std::vector<char> expected = { 10,17 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}
	TEST_METHOD(TestBasicMoveBishop)
	{
		Chessboard board("b6k/8/8/8/8/8/8/6K1");
		std::vector<char> expected = { 9, 18, 27, 36, 45, 54, 63 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}
	TEST_METHOD(TestBasicMoveQueen)
	{
		Chessboard board("q6k/8/8/8/8/8/8/6K1");
		std::vector<char> expected = { 1, 2, 3, 4, 5, 6, 8, 16, 24, 32, 40, 48, 56, 9, 18, 27, 36, 45, 54, 63 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}
	TEST_METHOD(TestBasicMoveKing)
	{
		Chessboard board("k7/8/8/8/8/8/8/7K");
		std::vector<char> expected = { 1, 8, 9 };
		char pos = 0;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Move);
		}
	}

	// TEST CAPTURE

	TEST_METHOD(TestBasicCapturePawn)
	{
		Chessboard board("k7/8/2P1P3/3p4/2pPP3/8/8/K7");
		std::vector<char> expected = { 36 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		for (size_t i = 0; i < moves.size(); i++)
		{
			Assert::AreEqual(moves[i].cStart, pos);
			Assert::AreEqual(moves[i].cDest, expected[i]);
			Assert::AreEqual(moves[i].type, Move::Type::Capture);
		}
	}
	TEST_METHOD(TestBasicCaptureRook)
	{
		Chessboard board("k7/8/3p4/1pPr1p2/8/3P4/8/K7");
		std::vector<char> expected = { 26, 43 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			if (move.type != Move::Type::Capture)
				continue;

			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expected[i]);
			Assert::AreEqual(move.type, Move::Type::Capture);
			i++;
		}
	}
	TEST_METHOD(TestBasicCaptureKnight)
	{
		Chessboard board("k7/2p1P3/1ppppP2/2pnp3/1Ppppp2/2P1p3/8/K7");
		std::vector<char> expected = { 12, 21, 33, 42 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			if (move.type != Move::Type::Capture)
				continue;

			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expected[i]);
			Assert::AreEqual(move.type, Move::Type::Capture);
			i++;
		}
	}
	TEST_METHOD(TestBasicCaptureBishop)
	{
		Chessboard board("k5P1/5p2/2P5/3b4/8/5p2/P5P1/K7");
		std::vector<char> expected = { 18, 48 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			if (move.type != Move::Type::Capture)
				continue;

			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expected[i]);
			Assert::AreEqual(move.type, Move::Type::Capture);
			i++;
		}
	}
	TEST_METHOD(TestBasicCaptureQueen)
	{
		Chessboard board("k7/1p1P1P2/4p3/1Ppq1P2/3p4/1P1P1P2/8/K7");
		std::vector<char> expected = { 11, 29, 41, 45 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			if (move.type != Move::Type::Capture)
				continue;

			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expected[i]);
			Assert::AreEqual(move.type, Move::Type::Capture);
			i++;
		}
	}
	TEST_METHOD(TestBasicCaptureKing)
	{
		Chessboard board("8/8/2PpP3/2pkP3/2pPp3/8/8/K7");
		std::vector<char> expected = { 18, 20, 35 };
		char pos = 27;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			if (move.type != Move::Type::Capture)
				continue;

			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expected[i]);
			Assert::AreEqual(move.type, Move::Type::Capture);
			i++;
		}
	}
	TEST_METHOD(TestLongCastlingMove)
	{
		Chessboard board("r3kbnr/p3pppp/2n5/qppp1b2/5PP1/P4N1B/1PPPP2P/RNBQK2R");
		char pos = 4;
		std::vector<Move> moves;
		std::vector<Move> castlings;
		board.getMoves(pos, moves);
		for (const auto& move : moves) {
			if (move.type == Move::Type::Castling)
				castlings.push_back(move);
		}
		Assert::AreEqual(int(castlings.size()), 1);
		Assert::AreEqual(castlings[0].cStart, char(4));
		Assert::AreEqual(castlings[0].cDest, char(2));
		Assert::AreEqual(castlings[0].oStart, char(0));
		Assert::AreEqual(castlings[0].oDest, char(3));
	}
	TEST_METHOD(TestShortCastlingMove)
	{
		Chessboard board("r3kbnr/p3pppp/2n5/qppp1b2/5PP1/P4N1B/1PPPP2P/RNBQK2R");
		char pos = 60;
		std::vector<Move> moves;
		std::vector<Move> castlings;
		board.getMoves(pos, moves);
		for (const auto& move : moves) {
			if (move.type == Move::Type::Castling)
				castlings.push_back(move);
		}
		Assert::AreEqual(int(castlings.size()), 1);
		Assert::AreEqual(castlings[0].cStart, char(60));
		Assert::AreEqual(castlings[0].cDest, char(62));
		Assert::AreEqual(castlings[0].oStart, char(63));
		Assert::AreEqual(castlings[0].oDest, char(61));
	}
	TEST_METHOD(TestCastlingAfterMove)
	{
		Chessboard board("r3kbnr/p3pppp/2n5/qppp1b2/5PP1/P4N1B/1PPPP2P/RNBQK2R");
		std::string startFen = board.getFenString();
		// move rook somewhere and then return it to the start position
		Move move1 = { 0, 1, 0, 1, Move::Type::Move };
		Move moveBack = { 1, 0, 1, 0, Move::Type::Move };
		board.makeMove(move1);
		board.makeMove(moveBack);
		Assert::AreEqual(startFen, board.getFenString());
		// check if castling move is still possible
		std::vector<Move> moves;
		std::vector<Move> castlings;
		board.getMoves(4, moves);
		for (const auto& move : moves) {
			if (move.type == Move::Type::Castling)
				castlings.push_back(move);
		}
		Assert::IsTrue(castlings.empty());
	}
	TEST_METHOD(TestEnPassantSuccessful)
	{
		Chessboard board;
		board.makeMove({ 53, 37, 53, 37, Move::Type::Move });
		board.makeMove({ 37, 29, 37, 29, Move::Type::Move });
		board.makeMove({ 14, 30, 14, 30, Move::Type::Move });
		board.getPiece(29)->onNextTurn();
		std::string expected = "rnbqkbnr/pppppp1p/8/5Pp1/8/8/PPPPP1PP/RNBQKBNR";
		Assert::AreEqual(board.getFenString(), expected);
		std::vector<Move> moves;
		std::vector<Move> enPassant;
		board.getMoves(29, moves);
		for (const auto& move : moves) {
			if (move.type == Move::Type::EnPassant)
				enPassant.push_back(move);
		}
		Assert::AreEqual(int(enPassant.size()), 1);
		Assert::AreEqual(enPassant[0].cStart, char(29));
		Assert::AreEqual(enPassant[0].cDest, char(22));
		Assert::AreEqual(enPassant[0].oStart, char(30));
		Assert::AreEqual(enPassant[0].oDest, char(30));
		board.makeMove(enPassant[0]);
		std::string afterMove = "rnbqkbnr/pppppp1p/6P1/8/8/8/PPPPP1PP/RNBQKBNR";
		Assert::AreEqual(board.getFenString(), afterMove);
	}
	TEST_METHOD(TestEnPassantAfterMove)
	{
		Chessboard board;
		board.makeMove({ 53, 37, 53, 37, Move::Type::Move });
		board.makeMove({ 14, 30, 14, 30, Move::Type::Move });
		board.getPiece(37)->onNextTurn();
		board.makeMove({ 37, 29, 37, 29, Move::Type::Move });
		board.getPiece(30)->onNextTurn();
		std::string expected = "rnbqkbnr/pppppp1p/8/5Pp1/8/8/PPPPP1PP/RNBQKBNR";
		Assert::AreEqual(board.getFenString(), expected);
		std::vector<Move> moves;
		std::vector<Move> enPassant;
		board.getMoves(29, moves);
		for (const auto& move : moves) {
			if (move.type == Move::Type::EnPassant)
				enPassant.push_back(move);
		}
		Assert::IsTrue(enPassant.empty());
	}
	TEST_METHOD(TestPromotionSuccessful)
	{
		Chessboard board("rnbqkb1r/ppppp1Pp/7n/8/6P1/7B/PPPPPp1P/RNBQK1NR");
		board.makeMove({ 14, 6, 14, 6, Move::Type::Move });
		Assert::IsTrue(board.getPiece(6)->canPromote());
		board.makeMove({ 53, 61, 53, 61, Move::Type::Move });
		Assert::IsTrue(board.getPiece(61)->canPromote());
	}
	TEST_METHOD(TestMakePromotionFigureFromList) {
		Chessboard board("rnbqkbPr/ppppp2p/7n/8/6P1/7B/PPPPPp1P/RNBQK1NR");
		Assert::IsTrue(board.getPiece(6)->getType() == Piece::Type::Pawn);
		board.switchPromotion(6, Piece::Type::Queen);
		Assert::IsTrue(board.getPiece(6)->getType() == Piece::Type::Queen);
	}
	TEST_METHOD(TestMakePromotionFigureNotFromList) {
		Chessboard board("rnbqkbPr/ppppp2p/7n/8/6P1/7B/PPPPPp1P/RNBQK1NR");
		Assert::IsTrue(board.getPiece(6)->getType() == Piece::Type::Pawn);
		board.switchPromotion(6, Piece::Type::King);
		Assert::IsTrue(board.getPiece(6)->getType() == Piece::Type::Pawn);
	}
	TEST_METHOD(TestKingImminentDanger)
	{
		Chessboard board("R6Q/8/1k6/NB6/8/8/8/6K1");
		std::vector<char> expectedMoves = { 10, 25, 26 };
		std::vector<Move::Type> expectedTypes = { Move::Type::Move, Move::Type::Capture, Move::Type::Move };
		char pos = 17;

		std::vector<Move> moves;
		board.getPiece(pos)->getMoves(moves);

		int i = 0;
		for (const auto& move : moves)
		{
			Assert::AreEqual(move.cStart, pos);
			Assert::AreEqual(move.cDest, expectedMoves[i]);
			Assert::AreEqual(move.type, expectedTypes[i]);
			i++;
		}
	}
	TEST_METHOD(TestKingInDangerBodyguard)
	{
		Chessboard board("8/8/b1k5/4n3/r5q1/8/8/2R4K");
		char expectedMove = 34;
		Move::Type expectedType = Move::Type::Move;

		std::vector<char> offsets;
		board.getTeamOffsets(Team::Player2, offsets);
		for (const auto& i : offsets)
		{
			if (board.getPiece(i)->getType() == Piece::Type::King)
				continue;

			std::vector<Move> moves;
			board.getMoves(i, moves);
			for (const auto& move : moves)
			{
				Assert::AreEqual(move.cStart, i);
				Assert::AreEqual(move.cDest, expectedMove);
				Assert::AreEqual(move.type, expectedType);
			}
		}
	}
	TEST_METHOD(TestKingInDangerCapture)
	{
		Chessboard board("8/8/8/8/8/b1k5/3p3K/q1R1r3");
		char expectedMove = 58;
		Move::Type expectedType = Move::Type::Capture;

		std::vector<char> offsets;
		board.getTeamOffsets(Team::Player2, offsets);
		for (const auto& i : offsets)
		{
			if (board.getPiece(i)->getType() == Piece::Type::King)
				continue;

			std::vector<Move> moves;
			board.getMoves(i, moves);
			for (const auto& move : moves)
			{
				Assert::AreEqual(move.cStart, i);
				Assert::AreEqual(move.cDest, expectedMove);
				Assert::AreEqual(move.type, expectedType);
			}
		}
	}
	TEST_METHOD(TestKingVsKing)
	{
		Chessboard board("k7/2K5/8/8/8/8/8/8");
		std::vector<char> expected1 = { 2, 3, 11, 17, 18, 19 };
		std::vector<char> expected2 = { 8 };
		char pos1 = 10, pos2 = 0;

		// King player 1
		{
			std::vector<Move> moves;
			board.getPiece(pos1)->getMoves(moves);

			int i = 0;
			for (const auto& move : moves)
			{
				Assert::AreEqual(move.cStart, pos1);
				Assert::AreEqual(move.cDest, expected1[i]);
				Assert::AreEqual(move.type, Move::Type::Move);
				i++;
			}
		}

		// King player 2
		{
			std::vector<Move> moves;
			board.getPiece(pos2)->getMoves(moves);

			int i = 0;
			for (const auto& move : moves)
			{
				Assert::AreEqual(move.cStart, pos2);
				Assert::AreEqual(move.cDest, expected2[i]);
				Assert::AreEqual(move.type, Move::Type::Move);
				i++;
			}
		}
	}
};