#include <bits/stdc++.h>
using namespace std;

/*  Not working
template<class T>
class Map{
  vector< vector<T> > data;
  public:
    Map(int rows, int cols, T init = 0): data(rows, vector<T>(cols, init) ){
    }
    vector<T>& operator[](int row){
      if(row < 0 || row > data.size()) throw "Invalid Access";
      return data[row];
    }
    typename vector<T>::iterator begin(){
      return data.begin();
    }
    typename vector<T>::iterator end(){
      return data.end();
    }
};
*/

class Minesweeper{
  vector< vector<bool> > bombs;
  vector< vector<char> > map;
  int rows, cols;
  int unexplored;
  int endStatus;
  bool isValid(int x, int y){
    return x >= 0 && x < rows && y >= 0 && y < cols;
  }
  void exploreAndMark(int x, int y){
    const static vector<vector<int>> directions{{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    if(!isValid(x, y)) return;
    int nearBomb = 0;
    unexplored -= 1;
    for(const auto& direction: directions){
      int X = x + direction[0], Y = y + direction[1];
      if(!isValid(X, Y)) continue;
      if(bombs[X][Y]) nearBomb += 1;
    }
    map[x][y] = '0' + nearBomb;
    if(nearBomb) return;
    for(const auto& direction: directions){
      int X = x + direction[0], Y = y + direction[1];
      if(!isValid(X, Y)) continue;
      if(map[X][Y] == '*' || map[X][Y] == 'X') exploreAndMark(X, Y);
    }
  }
  void ending(){
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        if(bombs[i][j]){
          if(map[i][j] == 'X') map[i][j] = 'Q';
          else map[i][j] = 'B';
        }
      }
    }
  }
  public:
    Minesweeper(int _rows, int _cols, int _bombs):
                rows(_rows), cols(_cols), endStatus(0), unexplored(_rows * _cols),
                bombs(_rows, vector<bool>(_cols, 0)),
                map(_rows, vector<char>(_cols, '*')){
      if(_bombs > rows * cols / 2) throw "No service for too-much bombs OuO";
      srand(time(nullptr));
      while(_bombs--){
        int x, y;
        do{
          x = rand() % rows, y = rand() % cols;
        }while( bombs[x][y] );
        bombs[x][y] = true;
      }
    }
    void showMap(){
      cout << "  ";
      for(int i = 0; i < cols; ++i){
        cout << i << " ";
      }
      cout << endl;
      for(int i = 0; i < rows; ++i){
        cout << i << " ";
        for(int j = 0; j < cols; ++j){
          cout << map[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
    }
    void mark(int x, int y, char marker = 'X'){
      if(endStatus) return;
      if(!isValid(x, y)){
        cout << "Invalid position" << endl;
        return;
      }
      map[x][y] = 'X';
    }
    void cancleMark(int x, int y){
      if(endStatus) return;
      if(!isValid(x, y) || map[x][y] != 'X'){
        cout << "Invalid position" << endl;
        return;
      }
      mark(x, y, '*');
    }
    void explore(int x, int y){
      if(endStatus) return;
      if(!isValid(x, y) || map[x][y] != '*'){
        cout << "Invalid position" << endl;
        return;
      }
      if(bombs[x][y]){
        cout << "A bomb explored!" << endl;
        endStatus = 1;
        ending();
        return;
      }
      exploreAndMark(x, y);
      if( unexplored == 0 ){
        cout << "Success!" << endl;
        endStatus = 2;
        ending();
      }
    }
    int getStatus(){
      return endStatus;
    }
};

int main(void){
  int N, M, bombs;
  cout << "rows, cols: ";
  cin >> N >> M;
  cout << "number of bombs: ";
  cin >> bombs;
  Minesweeper game(N, M, bombs);
  while(game.getStatus() == 0){
    game.showMap();
    cout << "0. cancle mark, 1. mark, 2. explore - ";
    int inst;
    cin >> inst;
    int x, y;
    if(inst == 0){
      cout << "cancle mark at: ";
      cin >> x >> y;
      game.cancleMark(x, y);
    }else if(inst == 1){
      cout << "mark at: ";
      cin >> x >> y;
      game.mark(x, y);
    }else if(inst == 2){
      cout << "explore at: ";
      cin >> x >> y;
      game.explore(x, y);
    }

  };
  game.showMap();
}
