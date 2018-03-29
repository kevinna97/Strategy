#include "Player.h"
#include "Resources.h"
#include <string>
#include "Edge.h"
#include "Vertex.h"

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
  bool enoughResources = true;
   if (this->resources[3] < 1 or this->resources[4] < 1){
    enoughResources = false;
  }
  else{
    this->resources[3] -= 1;
    this->resources[4] -= 1;
  }
  if (canBuild and enoughResources){
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
  bool enoughResources = true;
  if (this->resources[0] < 1 or this->resources[1] < 1 or this->resources[2] < 1 or this->resources[4] < 1){
    enoughResources = false;
  }
  else{
    this->resources[0] -= 1;
    this->resources[1] -= 1;
    this->resources[2] -= 1;
    this->resources[4] -= 1;
  }
  if (canBuild and enoughResources){
    vertices.setOwner(this->idNum);
    return true;
  }
  return false;
}

bool Player::improve(const int VertexNum){
  Vertex * vertices = this->pBoard.getEdge(VertexNum);
  enoughResources = true;
  if (vertices.getOwner() == this->idNum and enoughResources){
    int levels = vertices.getLevel();
    if (levels = 0){
      build-res(vertices.getSideline());
    }
    else if (levels = 1){
      if (this->resources[2] < 2 or this->resources[3] < 3){
        return false;
      }
      else{
        vertices.levelup();
        this->resources[2] -= 2;
        this->resources[3] -= 3;
        return true;
      }
    }
    else if (levels = 2){
      if (this->resources[0] < 3 or this->resources[1] < 2 or this->resources[2] < 2 or this->resources[3] < 1 or this->resources[4] < 2){
        return false;
      }
      else{
        vertices.levelup();
        this->resources[0] -= 3;     
        this->resources[1] -= 2;
        this->resources[2] -= 2;
        this->resources[3] -= 1;
        this->resources[4] -= 2;
        return true;
      }
    }
  }
  return false;
}

bool Player::trade(const char Playernum, const int ResourceFrom, const int ResourceTo){
  Player * players = this->pBoard.getPlayer(Playernum);
  if (this->resources[ResourceTo] > 0 and players->resources[ResourceFrom] > 0){
    this.getResources(ResourceFrom, 1);
    this.getResources(ResourceTo, -1);
    players.getResources(ResourceTo, 1);
    players.getResources(ResourceFrom, -1);
    return true;
  }
  return false;
}

bool Player::getResources(const int Resource, const int number){
  this->resources[number] += number;
}
