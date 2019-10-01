/*
  employee - respondent, manager, director
    bool onCall
  call center
    give instructions => dispatchCall(), endCall()
 */
#include <bits/stdc++.h>
using namespace std;

enum EmployeeType{
  respondent, manager, director
};

class Employee{
protected:
  EmployeeType type;
  bool onCall;
  Employee(EmployeeType _type): onCall(false), type(_type){
  }
public:
  static shared_ptr<Employee> create( EmployeeType type );
  bool isOnCall(){
    return onCall;
  }
  void getOnCall(){
    onCall = true;
  }
  void endCall(){
    onCall = false;
  }
  EmployeeType getType(){
    return type;
  }
};

class Respondent: public Employee{
public:
  Respondent(): Employee(EmployeeType::respondent){
  }
};
class Manager: public Employee{
public:
  Manager(): Employee(EmployeeType::manager){
  }
};
class Director: public Employee{
public:
  Director(): Employee(EmployeeType::director){
  }
};

shared_ptr<Employee> Employee::create( EmployeeType type ){
  switch( type ){
    case respondent:
      return make_shared<Respondent>();
    case manager:
      return make_shared<Manager>();
    case director:
      return make_shared<Director>();
    default:
      return nullptr;
  }
}
class CallCenter{
  vector< shared_ptr<Employee> > employees;
public:
  CallCenter( int resN, int manN, int dirN ){
    while( resN-- ){
      employees.push_back( Employee::create(EmployeeType::respondent) );
    }
    while( manN-- ){
      employees.push_back( Employee::create(EmployeeType::manager) );
    }
    while( dirN-- ){
      employees.push_back( Employee::create(EmployeeType::director) );
    }
  }
  shared_ptr<Employee> dispatchCall(){
    for( auto employee: employees ){
      if(employee -> isOnCall()) continue;
      employee -> getOnCall();
      return employee;
    } 
    return nullptr;
  }
  void endCall( shared_ptr<Employee> employee ){
    if(!employee -> isOnCall() ) throw "He/She is free right now!";
    employee -> endCall();
  }
};

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  CallCenter center(A, B, C);
  int inst;
  vector< shared_ptr<Employee> > callList;
  while(cin >> inst){
    switch(inst){
      case 0:
        {
          if(callList.size() == 0){
            cout << "No one is on call" << endl;
            break;
          }
          auto ite = callList.begin() + (rand() % callList.size());
          cout << "Ending call of - " << (*ite) -> getType() << endl;
          center.endCall( *ite );
          callList.erase( ite );
        }
        break;
      case 1:
        {
          auto employee = center.dispatchCall();
          cout << "Calling - " << employee -> getType() << endl;
          callList.push_back(employee);
        }
        break;
    }
  }
}
