#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <istream>
#include <vector>
#include <string>

class Tokenizer {
	
	std::istream &stream;
	std::vector<std::string> tokens;
	
public:
	
	Tokenizer (std::istream &stream);
	const std::vector<std::string> & get_tokens () { return tokens; }
	
	void tokenize ();
	
};

#endif
