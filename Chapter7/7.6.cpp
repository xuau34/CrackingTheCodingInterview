/*
Jigsaw
simple => test one by one, edge by edge
combination will form a bigger piece => more edges
//complicate way => using certain method to tell matching rate of two images

PieceOfJigsaw
* vector<Edge>
// * image
*/

class PieceOfJigsaw{
  vector<Edge> edges;
public:
  friend bool combine( PeiceOfJigswa& A, PeiceOfJigsaw& B){
    for(const Edge& x: A.edges){
      for(const Edge& y: B.edges){
        if( fitsWith(x,y) ){
          auto ite = edges.find(x);
          edges.erase(ite);
          for(const Edge& k: B.edges){
            if(k != y) edges.push_back(k);
          }
          return true;
        }
      }
    }
    return false;
  }
};

class Jigsaw{
  vector<PieceOfJigsaw> pieces;
public:
  Jigsaw( vector<PieceOfJigsaw> _pieces): pieces(_pieces){
  }
  PieceOfJigsaw solve(){
    while(pieces.size() > 1){
      PieceOfJigsaw X = pieces.pop_back();
      for(auto& piece: pieces){
        if( combine(piece, X) ) break;
      }
      throw "No valid solution";
    }
  }
};
