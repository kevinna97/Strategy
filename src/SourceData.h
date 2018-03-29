#include "Board.h"

Class SourceData{
  int * Data;
  Board * PBoard;
 Public:
  SourceData();
  SourceData(int * Data, Board * pBoard);
  int Getdata(int num);
  void NotifyBoard(Board *PBoard);
}
