#include "Player.h"
#include "Resources.h"
#include <string

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
               ss << BuildPoints;
               string str = ss.str();
               return str;
               }

string Player::playerResidence(){
               string residences = "Player Has Residences At Vertices: "
               for (int i = 0; i < 50; i++){
                  if (!pResidences[i]){
                    break;
                  }
                  else{
                    stringstream ss;
                    ss << pResidences[i].getSideline();
                    residences.append(ss);
                    residences.append("(Level ");
                    ss << pResidences[i].getLevel();
                    residences.append(ss);
                    residences.append("), ");
                  }
               }
               return residences; 
}
