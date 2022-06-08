#include "CppUnitTest.h"
#include "Chessboard.h"
#include "GameStatus.h"
#include "MoveWriterUtilites.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace moveWriterUtilities;


TEST_CLASS(MoveWriterTest)
{
	TEST_METHOD(TestFormateMoveLongCastling) {
		Move move = { 4, 2, 0, 3, Move::Type::Castling };
		Chessboard board("r3kbnr/p3pppp/2n5/qppp1b2/5PP1/P4N1B/1PPPP2P/RNBQK2R");
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "0-0-0  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateMoveShortCastling) {
		Move move = { 60, 62, 63, 61, Move::Type::Castling };
		Chessboard board("r3kbnr/p3pppp/2n5/qppp1b2/5PP1/P4N1B/1PPPP2P/RNBQK2R");
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "0-0  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateMovePawnMoved) {
		Chessboard board;
		Move move = { 8, 24, 8, 24, Move::Type::Move };
		Assert::IsTrue(board.getPiece(8)->getType() == Piece::Type::Pawn);
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "a7-a5  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateMoveNotPawnMoved) {
		Chessboard board;
		Move move = { 1, 16, 1, 16, Move::Type::Move };
		Assert::IsTrue(board.getPiece(1)->getType() != Piece::Type::Pawn);
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "Nb8-a6  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateCaptureMove) {
		Chessboard board("rnbqkbnr/p1pppppp/P7/1p6/8/8/1PPPPPPP/RNBQKBNR");
		Move move = { 2, 16, 16, 16, Move::Type::Capture };
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "Bc8xa6  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateEnPassant) {
		Chessboard board;
		board.makeMove({ 53, 37, 53, 37, Move::Type::Move });
		board.makeMove({ 37, 29, 37, 29, Move::Type::Move });
		board.makeMove({ 14, 30, 14, 30, Move::Type::Move });
		board.getPiece(29)->onNextTurn();
		std::string expectedFen = "rnbqkbnr/pppppp1p/8/5Pp1/8/8/PPPPP1PP/RNBQKBNR";
		Assert::AreEqual(board.getFenString(), expectedFen);
		Move move = { 29, 22, 30, 30, Move::Type::EnPassant };
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "f5xg6 e.p.  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateMovePromotion) {
		Chessboard board("rnbqkbPr/ppppp2p/7n/8/6P1/7B/PPPPPp1P/RNBQK1NR");
		Assert::IsTrue(board.getPiece(6)->getType() == Piece::Type::Pawn);
		Move move = { 14, 6, 14, 6, Move::Type::Move, Piece::Type::Queen };
		board.switchPromotion(6, move.promoteFigure);
		std::string got = formateMove(move, board, GameStatus::None);
		std::string expected = "g7-g8=Q  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateInCheck) {
		Chessboard board;
		Move move = { 8, 24, 8, 24, Move::Type::Move };
		Assert::IsTrue(board.getPiece(8)->getType() == Piece::Type::Pawn);
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::InCheck);
		std::string expected = "a7-a5+  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateEndGame) {
		Chessboard board;
		Move move = { 8, 24, 8, 24, Move::Type::Move };
		Assert::IsTrue(board.getPiece(8)->getType() == Piece::Type::Pawn);
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::End);
		std::string expected = "a7-a5#  ";
		Assert::AreEqual(expected, got);
	}
	TEST_METHOD(TestFormateStalemate) {
		Chessboard board;
		Move move = { 8, 24, 8, 24, Move::Type::Move };
		Assert::IsTrue(board.getPiece(8)->getType() == Piece::Type::Pawn);
		board.makeMove(move);
		std::string got = formateMove(move, board, GameStatus::Stalemate);
		std::string expected = "a7-a5\n0.5:0.5  ";
		Assert::AreEqual(expected, got);
	}
};