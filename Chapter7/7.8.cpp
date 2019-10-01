/*
Othello:
capture(color, x, y) (called by put) - recursively capture the opponent's color
conclude - calculate each's number of pieces and acclaim the winner
*table
*two players
put(color, x, y)
  call capture if it's valid
  if there's no room for another piece, call conclude, and then return false;
  return ture

play(2 players){
  call put until put return false
}

Player:
* scores
* policy
next move (table)
*/

typedef struct _Position{
  int x, y;
  _Position(int _x, int _y): x(_x), y(_y){
  }
} Position;

class Player{
  int scores;
  function<Position(vector<vector<int>>)> policy;
  public:
    Player( function<Position(const vector<vector<int>>&)> _policy ): scores(0), policy(_policy){
    }
    void gainOne(){
      scores += 1;
    }
    Position nextStep(const vector<vector<int>>& table){
      return policy(table);
    }
};

class Othello{
  vector<vector<int>> table;
  int rowN, colN, emptyCells;
  Player &firstPlayer, &secondPlayer;
  void capture( Position pos, int color ){
    const static vector< vector<int> > directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    if( table[ next.x ][ next.y ] == color ) return;
    table[ pos.x ][ pos.y ] = color;
    for(const auto& direction: directions){
      Position next( pos.x + direction[0], pos.y + direction[1]);
      if(!isValid( next )) continue;
      capture( next );
    }
  }
  void conclude(){
    int firstSum = 0;
    for(const auto& row: table){
      for(const auto& ele: row){
        if(ele == 1) firstSum += 1;
      }
    }
    int secondSum = rowN * colN - firstSum;
    if(firstSum > secondSum) firstPlayer.gainOne();
    else secondPlayer.gainOne();
  }
  public:
    Othello(int _rowN, int _colN):
      rowN(_rowN), colN(_colN),
      table(_rowN, vector<int>(_colN, 0)), emptyCells(_rowN * _colN){
    }
    bool put( Position pos, int color ){
      if(!isValid(pos) || table[pos.x][pos.y] != 0) throw "invalid position";
      capture(pos, color);
      emptyCells -= 1;
      if(emptyCells == 0){
        conclude();
        return false;
      }
      return true;
    }

    void play(Player& _first, Player& _second){
      firstPlayer = _first;
      secondPlayer = _second;
      bool turn = 0;
      do{
        Position pos = (turn)? secondPlayer.nextStep(): firstPlayer.nextStep();
        int color = (turn)? -1: 1;
      }( put(pos, color) );
      fill(table.begin(), table.end(), vector<int>(colN, 0) );
    }

};
