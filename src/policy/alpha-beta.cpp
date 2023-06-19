#include <cstdlib>
#include <bits/stdc++.h>
#include <queue>
#include "../state/state.hpp"
#include "./alpha-beta.hpp"


/**
* @brief Randomly get a legal action
* 
* @param state Now state
* @param depth You may need this for other policy
* @return Move 
*/

using namespace std;

static int cur_player;

int AlphaBeta::alpha_beta_value(State *state, int depth, int alpha, int beta, bool maximizingPlayer){
    if(!depth){
        if(cur_player==0){
            return state->evaluate();
        }
        else{
            return (-1)*state->evaluate();
        }
    }

    state->get_legal_actions();
    auto actions = state->legal_actions;
    int size = actions.size();
    int value;

    if(maximizingPlayer){
        value = -100000;
        for(int i=0;i<size;i++){
            int vv = alpha_beta_value(state->next_state(actions[i]), depth-1, alpha, beta, false);
            if(vv > value){
                value = vv;
            }
            alpha = max(alpha, value);
            if(alpha >= beta){
                break;
            }
        }
        return value;
    }

    else {
        value = 100000;
        
        for(int i=0;i<size;i++){
            int vv = alpha_beta_value(state->next_state(actions[i]), depth-1, alpha, beta, true);
            if(vv < value){
                value = vv;
            }
            beta = min(beta, value);
            if(beta <= alpha){
                break;
            }
        }
        return value;
    }
}

Move AlphaBeta::get_move(State *state, int depth){
    int value = -1000000;
    cur_player = state->player;
    Move result;
    state->get_legal_actions();
    auto actions = state->legal_actions;
    int size = state->legal_actions.size();
    int brch;

    for(int i=0;i<size;i++){
        brch = alpha_beta_value(state->next_state(actions[i]), depth, INT_MIN, INT_MAX, false);
        if(brch > value){
            value = brch;
            result = actions[i];
        }
    }

    return result;
}