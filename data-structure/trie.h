#include<string>
#include<vector>

using namespace std;

class trie{
public:
  vector<trie*> v;
	bool doesEnd;
	string alphabet;
	//Constructor
	trie(string alphabet){
		this->alphabet = alphabet;
		this->doesEnd = false;
		int alphSize = (int) alphabet.size();
		v.resize(alphSize);
		for( int i=0; i<alphSize; i++){
			v[i] = NULL;
		}
	}

	/* Method to add a word to the trie*/
	void addWord(const string s){
		if(s.length() == 0){
			this->doesEnd = true;
			return;
		}		
		int c = s[0];
		if(this->v[c-alphabet[0]] == NULL) { 
			this->v[c-alphabet[0]] = new trie(this->alphabet);
		}
		this->v[c-alphabet[0]]->addWord(s.substr(1));
	}

	/* Method to find if the sting is present in the trie or not*/
	bool isPresent(const string s){
		if( s.length() == 0) //base case
			return this->doesEnd;

		char c = s[0];
		if( this->v[c- alphabet[0]] == NULL)
			return false;
		else{
			return this->v[c-alphabet[0]]->isPresent(s.substr(1));
		}
	}

};
