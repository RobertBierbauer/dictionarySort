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
               //std::cout<<std::endl ;
            }else{
              std::cout << it->first<<std::endl ;
            }
              it->second.iterate();
         }
          std::cout << ")"<<std::endl ;
     }   
     
      
     std::vector<std::string> DicTree::wordIterate(){
       std::vector<std::string> wordList;
       std::string word;
         for (std::map<char,DicTree>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
              std::vector<std::string> tmpList=it->second.secwordIterate();
              for(std::vector<std::string>::iterator tmpit=tmpList.begin(); tmpit!=tmpList.end(); ++tmpit){
	   wordList.push_back(it->first+*tmpit);
	          std::cout<<"'"<<it->first+*tmpit<<"'"<<std::endl;
         }
         }
           for(std::vector<std::string>::iterator w=wordList.begin(); w!=wordList.end(); ++w){
	     std::cout<< *w<<std::endl;
              }
          return wordList;
     }   
     
     
       std::vector<std::string> DicTree::secwordIterate(){
        std::vector<std::string> wordList;
        std::string word;
         for (std::map<char,DicTree>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
           //std::cout<<"'"<<it->first<<"'"<<it->second.nodes.size()<<"->"<<it->second.wordPosition.size()<<std::endl;
            if(it->second.nodes.size()==0){
              std::cout<<"a"<<std::endl;
              std::vector<std::string> tmpList=it->second.wordIterate();
              for(std::vector<std::string>::iterator tmpit=tmpList.begin(); tmpit!=tmpList.end(); ++tmpit){
	   wordList.push_back(it->first+*tmpit);
	          std::cout<<"'"<<it->first+*tmpit<<"'"<<std::endl;
              }
            }else{
               std::cout<<"b"<<std::endl;
              return std::vector<std::string> {it->first};
            }
         }
           /*for(std::vector<std::string>::iterator w=wordList.begin(); w!=wordList.end(); ++w){
	     std::cout<< *w<<std::endl;
              }*/
          return wordList;
     }  
     
     void DicTree::createOutput(std::string *output, bool first, int scope){
    for(std::map<char,DicTree>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
        if(it->first != ' '){
            if(nodes.size()>1&&!first){
                for(int i = 0; i<scope+1; i++){
                    *output += '_';
                }
            }
            *output  +=it->first;
            if(it->second.wordPosition.size() != 0){
                *output += '{';
                for(std::vector<int>::iterator itW=it->second.wordPosition.begin(); itW != it->second.wordPosition.end(); ++itW){
                    *output += std::to_string(*itW) + ",";
                }
                output->at(output->length()-1) = '}';
            }
            it->second.createOutput(output, false, nodes.size()>1&&!first?scope+1:scope);
            if(first){
                *output+=' ';
            }
        }
    }

}

void DicTree::getWords(int tab, std::string s, std::map<std::string, std::vector<int>> *wordMap){
    for (std::map<char,DicTree>::iterator it=nodes.begin(); it!=nodes.end(); ++it){
        if(it->second.wordPosition.size() != 0){
            wordMap->insert(std::pair<std::string,std::vector<int>>(s+it->first, it->second.wordPosition));
        }
        it->second.getWords(tab+1, s+it->first, wordMap);
    }
}
     
     
