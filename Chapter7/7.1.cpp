#include <bits/stdc++.h>
using namespace std;

/*
card - 
- with four types <- clubs, diamonds, hearts, spades
- value

deck of cards - maintain the cards
- initial with all 52 cards
* shuffle
* add
* give out one
* check if complete

blackjack - a game with two types of participants - host and players
- start with a deck of cards
- each round give out two cards to players and then host
- in certain order, ask each player whether they want to add, and return a status whether their sum is over 21
- get their sum and then declare who wins the round. => money or grades will plus one
- collect abandoned cards into another deck of cards
* reinitial the game
* have the list of players

participant - 
- types: host/player - 
- array of cards <= could be as a deck of cards
- sum
* get a card
* decide if adding or not
* return sum
*/

enum CardType{
  clubs, diamonds, hearts, spades
};

enum ParticipantType{
  host, player
};

class Card{
  int value;
  CardType type;
public:
  Card(int _value, CardType _type): value(_value), type(_type){
  }
  int getValue(){
    return value;
  }
  CardType getType(){
    return type;
  }
};

class Deck{
  vector<shared_ptr<Card>> cards;
  void addAPack(){
    for(const auto type: CardType::All){
      for(int val = 1; val <= 13; ++val){
        addCard( make_shared<Card>(val, type) );
      }
    }
  }
public:
  Deck(bool ANewPack){
    if(ANewPack){
      addAPack();
    }
  }
  void addCard( shared_ptr<Card> card ){
    cards.push_back(card);
  }
  void shuffle(){
    random_shuffle(cards.begin(), cards.end());
  }
  shared_ptr<Card> pop(){
    if(card.size() == 0) throw "Empty Deck!";
    shared_ptr<Card> popCard = cards.back();
    cards.pop_back();
    return popCard;
  }
  void moveTo(Deck& deck){
    while(card.size() > 0){
      deck.addCard( this.pop() );
    }
  }
};

class Participant{
protected:
  Deck deck;
  int sum;
public:
  static shared_ptr<Participant> create(ParticipantType type){
    switch(type){
      case host:
        return make_shared<Host>();
      case player:
        return new make_shared<Player>();
      default:
        return nullptr;
    }
  }
  void getACard(shared_ptr<Card> card){
    sum += card -> getValue();
    deck.addCard(card);
    if(sum > 21){
      sum = -1;
    }
  }
  int getSum(){
    return sum;
  }
  void returnBack(Deck& disposal){
    deck.moveTo(disposal);
    sum = 0;
  }
  bool askMore(){
    if(sum < 0) return false;
    int sumMax = random() % 22;
    if(sum < sumMax) return true;
    return false;
  }
}

class Host: public Participant {
public:
  Host(): sum(0){
  }

}

class Player: public Participant {
public:
  Player(): sum(0){
  }
  bool operator>(const Player& p1, const Player& p2){
    return p1.getSum() > p2.getSum();
  }
}

bool operator>(const Host& host, const Player& player){
  return host.getSum() >= player.getSum();
}

bool operator<(const Host& host, const Player& player){
  return host.getSum() < player.getSum();
}

class Blackjack{
  vector<shared_ptr<Participant>> participants;
  vector<shared_ptr<Participant>> newParticipants;
  Deck pool, disposal;
  int maxPar;
  shared_ptr<Participant> getWinner(){
    shared_ptr<Participant> winner = participants.front();
    for(auto participant: participants){
      if((*participant) > (*winner) ) winner = participant;
    }
    return winner;
  }
public:
  Blackjack(int _maxPart = 7): pool(true), disposal(false), maxPar(_maxPart){
    participants.push_back( Participant::create(ParticipantType::host) );
  }
  void startNewRound(){
    while( newParticipants.size() && participants.size() < maxPar ){
      participants.push_back( newParticipants.pop_back() );
    }
    if(participants.size() < 2) throw "No enough people to start the game.";
    disposal.moveTo(pool);
    for(auto& participant: participants){
      participant.addCard( pool.pop() );
      participant.addCard( pool.pop() );
    }
    for(auto& participant: participants){
      while( participant.askMore() ){
        participant.addCard( pool.pop() );
      }
    }
    auto winner = getWinner();
    winner.reward(1);
    for(auto& participant: participants){
      participant.returnBack(disposal);
    }
  }
  void addParticipant( shared_ptr<Participant> player ){
    auto ite = participants.find(player);
    if(ite != participants.end()) throw "Someone facked the ID!!";
    newParticipants.push_back( player );
  }
  void removeParticipant( shared_ptr<Participant> player){
    auto ite = participants.find(player);
    if(ite != participants.end()){
      (*ite) -> returnBack(disposal);
      participants.erase(ite);
      return;
    }
    auto ite = newParticipants.find(player);
    if(ite != newParticipants.end()){
      newParticipants.erase(ite);
    }
  }
}
