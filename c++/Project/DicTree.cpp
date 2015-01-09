#include "DicTree.h"
#include <string>




     
     DicTree::DicTree(){}
     
     DicTree::DicTree(char _letter): letter (_letter){}
     
     void DicTree::insert(std::string word, int pos){
           if(word.length()>0)
            nodes[word[0]].insert(word.substr(1),pos);
           else
              wordPosition.push_back(pos);
     }
     
     void DicTree::iterate(){
       std::cout << "(" ;
         for (std::map<char,DicTree>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
           //End of a word
            if(it->second.wordPosition.size()>0){
              std::cout << it->first << " => "  ;
              // word poss
              for (std::vector<int>::iterator inte=it->second.wordPosition.begin(); inte!=it->second.wordPosition.end(); ++inte){
	 std::cout << *inte<<",";
              }
               std::cout<<std::endl ;
            }else{
              std::cout << it->first<<std::endl ;
            }
              it->second.iterate();
         }
          std::cout << ")" ;
     }   
     
     
