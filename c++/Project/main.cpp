#include "Tokenizer.h"
#include "DicTree.h"
#include <fstream>
#include <iostream>

int main () {
	
	std::ifstream s ("test.txt");
	Tokenizer t (s);
	
	t.tokenize ();
	DicTree tree;
	for (int i = 0; i < t.get_tokens().size(); i++) {
		std::cout << "(" << t.get_tokens()[i] << ")" << std::endl;
		
		tree.insert(t.get_tokens()[i],i);
	}
	tree.iterate();
	return 0;
}

