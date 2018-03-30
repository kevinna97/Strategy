#ifndef _BOARD_H
#define _BOARD_H


#include <memory>
#include <vector>

class Board {
  std::vector<std::shared_ptr<Tile *>> tiles;// double check syntac
  std::vector<std::shared_ptr<Sideline *>> vertices;
  std::vector<std::shared_ptr<Sideline *>> edges;
  int playerTurn;
  std::vector<std::unique_ptr<Dice *>> diceComponent;
  std::unique_ptr<SourceData *> data;
  std::unique_ptr<BoardDisplay *> textBoard;
  std::vector<std::unique_ptr<Player *>> pPlayers;
public:
	void printBoard(Board *);
	int diceRoll();
	void next();

	
}

#endif
