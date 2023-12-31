#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class AlphaBeta{
public:
  static int alpha_beta_value(State *state, int depth, int alpha, int beta, bool maximizingPlayer);
  static Move get_move(State *state, int depth);
};