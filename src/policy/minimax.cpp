#include <cstdlib>
#include <queue>
#include "../state/state.hpp"
#include "./minimax.hpp"


/**
* @brief Randomly get a legal action
* 
* @param state Now state
* @param depth You may need this for other policy
* @return Move 
*/


int Minimax::minimax_value(State *state, int depth, bool maximizingPlayer){
    if(!depth){
        return state->evaluate_base2();
    }

    state->get_legal_actions();
    auto actions = state->legal_actions;
    int size = actions.size();

    if(maximizingPlayer){
        int value = -100000;
        for(int i=0;i<size;i++){
            int vv = minimax_value(state->next_state(actions[i]), depth-1, false);
            if(vv > value){
                value = vv;
            }
        }

        return value;
    }

    else {
        int value = 100000;
        for(int i=0;i<size;i++){
            int vv = minimax_value(state->next_state(actions[i]), depth-1, true);
            if(vv < value){
                value = vv;
            } 
        }
        return value;
    }
}

Move Minimax::get_move(State *state, int depth){
    int value = -1000000;
    Move result;
    state->get_legal_actions();
    auto actions = state->legal_actions;
    int size = state->legal_actions.size();
    int brch;

    for(int i=0;i<size;i++){
        brch = minimax_value(state->next_state(actions[i]), depth, false);
        if(brch > value){
            value = brch;
            result = actions[i];
        }
    }

    return result;
}