#include "Tokenizer.h"
#include <string>

// test
//#include <iostream>

Tokenizer::Tokenizer (std::istream &_stream) : stream (_stream) {
}

static bool is_whitespace (char c) {
	return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void Tokenizer::tokenize () {
	
	std::string current;
	
	char c;
	while (stream.get (c)) {
		if (is_whitespace (c)) {
			tokens.push_back (current);
			current = "";
			tokens.push_back (std::string (1, c));
		} else {
			current += c;
		}
	}
	if (current.length() > 0) tokens.push_back(current);
	
}

