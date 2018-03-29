#include "Player.h"
#include "Resources.h"
#include <string>
#include "Edge.h"

using namespace std;

Player::Player(): BuildPoints{0}{
  int resources[5] = {0,0,0,0,0};
}

Player::Player(int idNum, char pColor, Board * pBoard):
        idNum{idNum}, pColor{pColor}, BuildPoints{0}, pBoard{pBoard}{
          int resources[5] = {0,0,0,0,0};
          vertex * pResidences[50];
        }
   
string Player::playerStatuses(){
               stringstream ss;
               ss << this->BuildPoints;
               string str = ss.str();
               return str;
               }

string Player::playerResidence(){
               string residences = "Player Has Residences At Vertices: "
               for (int i = 0; i < 50; i++){
                  if (!this->pResidences[i]){
                    break;
                  }
                  else{
                    stringstream ss;
                    ss << this->pResidences[i].getSideline();
                    residences.append(ss);
                    residences.append("(Level ");
                    ss << this->pResidences[i].getLevel();
                    residences.append(ss);
                    residences.append("), ");
                  }
               }
               return residences; 
}

bool Player::build-road(const int EdgeNum){
  bool canBuild = false;
  Edge * edges = this->pBoard.getEdge(EdgeNum);
  for (int i = 0; i < 2; i++){
    Vertex * vertices = edges.getVertex(i)
    if (vertices.getOwner() == this->idNum){
      canBuild = true;
    }
    for (int j = 0; j < 3; j++){
      Edge * edges1 = vertices.getEdge(j);
      if (edges1.getOwner() == this->idNum){
        canBuild = true;
      }
    }
  }
  if (canBuild){
    edges.setOwner(this->idNum);
    return true;
  }
  return false;
}

bool Player::build-res(const int VertexNum){
  bool canBuild = false;
  Vertex * vertices = this->pBoard.getEdge(VertexNum);
  for (int j = 0; j < 3; j++){
      Edge * edges1 = vertices.getEdge(j);
      if (edges1.getOwner() == this->idNum){
        canBuild = true;
      }
    }
  if (canBuild){
    vertices.setOwner(this->idNum);
    return true;
  }
  return false;
}

bool Player::improve(const int VertexNum){
  Vertex * vertices = this->pBoard.getEdge(VertexNum);
  if (vertices.getOwner() == this->idNum){
    vertices.levelup();
    return true;
  }
  return false;
}

bool Player::trade(const char Playernum, const int ResourceFrom, const int ResourceTo){
  Player * players = this->pBoard.getPlayer(Playernum);
  this.getResources(ResourceFrom, 1);
  this.getResources(ResourceTo, -1);
  players.getResources(ResourceTo, 1);
  players.getResources(ResourceFrom, -1);
  return true;
}

bool Player::getResources(const int Resource, const int number){
  this->resources[number] += number;
}
