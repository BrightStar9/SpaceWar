#include <algorithm> // For min/max.
#include <cmath>	 // For cos/sin.
#include "Engine.h"
#include "StateMachine.h";

StateMachine::StateMachine() : currentState(Title) {}

void StateMachine::changeState(State newState) {
    std::cout << "Switching from " << stateToString(currentState)
        << " to " << stateToString(newState) << std::endl;
    currentState = newState;
}

void StateMachine::run() {
    while (true) {
        switch (currentState) {
        case Title:
            // Display title screen and wait for start button click
            if (startButtonClicked) {
                changeState(Game);
            }
            break;

        case Game:
            // Run game logic and check win/lose conditions
            if (winConditionMet) {
                changeState(Win);
            }
            else if (loseConditionMet) {
                changeState(Lose);
            }
            else if (pauseButtonClicked) {
                changeState(Pause);
            }
            break;

        case Pause:
            // Display pause screen and wait for resume or quit button click
            if (resumeButtonClicked) {
                changeState(Game);
            }
            else if (quitButtonClicked) {
                changeState(Title);
            }
            break;

        case Win:
            // Display win screen and wait for restart or quit button click
            if (restartButtonClicked) {
                changeState(Game);
            }
            else if (quitButtonClicked) {
                changeState(Title);
            }
            break;

        case Lose:
            // Display lose screen and wait for restart or quit button click
            if (restartButtonClicked) {
                changeState(Game);
            }
            else if (quitButtonClicked) {
                changeState(Title);
            }
            break;
        }
    }
}
std::string StateMachine::stateToString(State state) {
    switch (state) {
    case Title:
        return "Title";
        break;
    case Game:
        return "Game";
        break;
    case Pause:
        return "Pause";
        break;
    case Win:
        return "Win";
        break;
    case Lose:
        return "Lose";
        break;
    }
}
