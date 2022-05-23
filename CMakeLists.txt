cmake_minimum_required(VERSION 3.17.0)
project(Chess VERSION 1.0)

#==========================================
#   ChessLib
#==========================================

file(GLOB_RECURSE ChessLib_SRC "ChessLib/*.h" "ChessLib/*.cpp" "ChessLib/ChessPieces/*.h" "ChessLib/ChessPieces/*.cpp" "ChessLib/Players/*.h" "ChessLib/Players/*.cpp")

add_library(ChessLib ${ChessLib_SRC})

set_property(TARGET ChessLib PROPERTY CXX_STANDARD 17)

#==========================================
#   ChessApp
#==========================================

file(GLOB_RECURSE ChessApp_SRC "ChessApp/*.h" "ChessApp/*.cpp")

add_executable(ChessApp ${ChessApp_SRC})

target_link_libraries(ChessApp ChessLib)

target_include_directories(ChessApp PRIVATE "ChessLib/")

set_property(TARGET ChessApp PROPERTY CXX_STANDARD 17)

#==========================================
#   ChessUnitTest
#==========================================

file(GLOB_RECURSE ChessUnitTest_SRC "ChessUnitTest/*.h" "ChessUnitTest/*.cpp")

add_library(ChessUnitTest SHARED ${ChessUnitTest_SRC})

target_link_libraries(ChessUnitTest ChessLib)

target_include_directories(ChessUnitTest PRIVATE "ChessLib/")

set_property(TARGET ChessUnitTest PROPERTY CXX_STANDARD 17)