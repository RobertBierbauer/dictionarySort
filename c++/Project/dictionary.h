#ifndef DICTREE_H
#define DICTREE_H

#include <istream>
#include <vector>
#include <string>


  class DicTree{
      map<char,DicTree> nodes;
      std::vector<int> wordPosition;
      char Letter;
      
    public:
      DicTree();
      insert(str::string word, int pos);
      
      
    
    
  
  
  }