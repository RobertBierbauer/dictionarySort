#ifndef DICTREE_H
#define DICTREE_H
#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <map>


  class DicTree{
      std::map<char,DicTree> nodes;
      std::vector<int> wordPosition;
      char letter;
      
    public:
      DicTree();
      DicTree(char letter);
      void insert(std::string word, int pos);
      void iterate();
      
  };
#endif