#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>
#include <unordered_map>

enum State {
    Title,
    Game,
    Pause,
    Win,
    Lose
};
class StateMachine {

public:
    StateMachine() : currentState(Title);
    void changeState(State newState);
    void run();


private:
    State currentState;
    std::string stateToString(State state);

};