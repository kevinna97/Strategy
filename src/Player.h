#ifndef _PLAYER_H_
#define _PLAYER_H_

enum Class Resources;

Class Player {
  int idNum;
  char pColor;
  int * resources;
  int BuildPoints;
  Board * pBoard;
 Public:
  Player();
  Player(int idNum, char pColor, int * resources, int BuildPoints, Board * pBoard);
  
  string playerStatuses();
  string playerResidence();
  bool build-road(const int EdgeNum);
  bool build-res(const int VertexNum);
  bool improve(const int VertexNum);
  bool trade(const char Player, const int ResourceFrom, const int ResourceTo);

  bool getResources(const int Resource);
  void MutateResource(const int Resource);
