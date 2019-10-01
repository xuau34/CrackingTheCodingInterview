/*
File system - Directories => Files

//access right: user = ? in what group
//current directory
// * ls
// * mv
// * rm
// * cp
// * cd


Directories
data => file list
parent directory
directories as data //!!!!
created date        //!!!!
modified date       ..
accessed date       ..
//permission
* printList
* addFile
* addDirectory
* sortBy

File
data
created date
modified date
accessed date
//permission
* access
* modify
 */

class Entry{
  class Data;
  Date created;
  Date modified;
  Date accessed;
  string name;
  public:
    Entry(string _name, Date currentDate):
      name(_name), created(currentDate), modified(currentDate), accessed(currentDate){
    }
    Data access(Date currentDate){
      accessed = currentDate;
      return Data;
    }
    void modify(Date currentDate, Data modifiedData){
      modified = currentDate;
      Data = modifiedData;
    }
    string getName(){
      return name;
    }
    Date getCreated(){
      return created;
    }
    Date getModified(){
      return modified;
    }
    Date getAccessed(){
      return accessed;
    }
    void output(){
      cout << name << "\t" << created << "\t" << accessed << "\t" << modified << endl;
    }
    bool operator<(const Entry& other) const{
      return name < other.name;
    }
};

class File: public Entry{
  class Data{
    shared_ptr<vector<char>> text;
    public:
      Data(shared_ptr< vector<char> > _text): text(_text){
      }
  } data;
  public:
    File(string name, Date currentDate, shared_ptr< vector<char> > text):
      Entry(name, currentDate), data(text);
};

class Directory: public Entry{
  class Data{
    vector<shared_ptr<File>> files;
    vector<shared_ptr<Directory>> directories;
    public:
      Data(){
      }
      void add(shared_ptr<File> file){
        files.push_back(file);
      }
      void add(shared_ptr<Directory> directory){
        directories.push_back(directory);
      }
      void list(){
        sort(files.begin(), files.end());
        sort(directories.begin(), directories.end());
        cout << "name\tcreated\taccessed\tmodified\n";
        for(const auto& dir: directories){
          dir.output();
        }
        for(const auto& file: files){
          file.output();
        }
      }
  } data;  
  public:
    Directory(string name, Date currentDate): Entry(name, currentDate){
    }
    void addFile( shared_ptr<File> file ){
      Date currentDate();
      modified = currentDate;
      data.add(file);
    }
    void addDirectory( shared_ptr<Directory> directory){
      Date currentDate();
      modified = currentDate;
      data.add( directory);
    }
    void list(){
      Date currentDate();
      accessed = currentDate;
      data.list();
    }
};
