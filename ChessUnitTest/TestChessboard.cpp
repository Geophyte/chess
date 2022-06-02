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
};