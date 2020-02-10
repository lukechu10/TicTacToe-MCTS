#pragma once

#include <random>
#include <vector>

#include "Game.h"

class Node {
public:
  static constexpr double C_PARAM = 1.41; // sqrt(2)

  Node *selectBestChildUCT();
  Node *expand();  // phase 2 - expansion
  char simulate(); // phase 3 - simulation
  void backpropagate(char winner);
  int visitCount() { return visits; }
  double winCount() { return wins; }
  const Game &getState() { return state; }
  std::vector<Node *> getChildren() { return children; }

  bool fullyExpanded();
  bool isLeaf();

  // constructor
  Node(Node *parent, Game state);
  ~Node();

private:
  Node *parent;

  std::vector<Node *> children;
  std::vector<Game::Play> unexpandedNodes;
  Game state;

  double wins = 0;
  int visits = 0;

  std::random_device r;
  std::default_random_engine generator{r()}; // random number generator
};
