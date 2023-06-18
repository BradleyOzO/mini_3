#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  static int minimax_value(State *state, int depth, bool maximizingPlayer);
  static Move get_move(State *state, int depth);
};