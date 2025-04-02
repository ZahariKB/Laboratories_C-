#pragma once
#include <iostream>
#include <vector>
#include "tree.cpp"
#include "Lesnoe&plodovoe.h"
using namespace std;
static int index = 0;

class container_of_vector  {
private:
    vector<Tree*> trees;
public:
    static bool compareTrees(Tree* tree1,Tree* tree2) {
        if (tree1->get_of_name() == tree2->get_of_name()) {
            return tree1->get_of_age() > tree2->get_of_age();
        }
        else {
            return tree1->get_of_name() < tree2->get_of_name();
        }
    }

  void push_tree(Tree* tree) {
    trees.push_back(tree);
    index++;
  }

  void print_trees() {
    for (const auto& tree : trees) {
      tree->print();
    }
  }

  int get_of_index_of_listvennoe() {
      int index_of_listovoe = 0;
      for (const auto& tree : trees) {
          if (tree->get_type() == listovoe) {
              index_of_listovoe++;
          }
      }
      return index_of_listovoe;
  }

  int get_of_index_of_hvoinoe() {
      int index_of_hvoinoe = 0;
      for (const auto& tree : trees) {
          if (tree->get_type() == hvoinoe) {
              index_of_hvoinoe++;
          }
      }
      return index_of_hvoinoe;
  }

  void sortTrees() {
      for (size_t i = 0; i < trees.size() - 1; i++) {
          for (size_t j = i + 1; j < trees.size(); j++) {
              if (!compareTrees(trees[i], trees[j])) {
                  swap(trees[i], trees[j]);
              }
          }
      }
  }

  int get_of_index_of_les() {
      int index_les = 0;
      for (const auto& tree : trees) {
          if (dynamic_cast<Lesnoe_tree*>(tree)) {
              index_les++;
          }
      }
      return index_les;
  }

  int get_of_index_of_plod() {
      int index_plod = 0;
      for (const auto& tree : trees) {
          if (dynamic_cast<Plodovoe_tree*>(tree)) {
              index_plod++;
          }
      }
      return index_plod;
  }
};
