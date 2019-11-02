
class Machine{
  map<string, set<string>> table;
  size_t maxSize;
  string from, to;
  public:
  Machine(int _maxSize): maxSize(_maxSize), from(""), to(""){
  }
  pair<string, set<string>> addLink(string name, string secondName){
    if(from.length == 0){
      from = to = name;
    };
    auto ite = table.find(name);
    if(ite == table.end() && table.size() == maxSize ){

    
    }
    ite -> second.add(secondName);
  }
  vector<string> getLinks(string name){
    auto ite = table.find(name);
    if(ite == table.end()) return vector<string>();
    return vector<string>(ite -> begin(), ite -> end());
  }
};

class ComputeCenter{
  map< , shared_ptr<Machine> > machines;
  
};
