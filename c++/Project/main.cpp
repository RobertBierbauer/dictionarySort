#include "Tokenizer.h"
#include <fstream>
#include <iostream>

int main () {
	
	std::ifstream s ("test.txt");
	Tokenizer t (s);
	
	t.tokenize ();
	
	for (int i = 0; i < t.get_tokens().size(); i++) {
		std::cout << "(" << t.get_tokens()[i] << ")" << std::endl;
	}
	
	return 0;
}

