//@author - piyush
#include <map>
#include <string>

class trienode{
    public:
        bool isword;
        std::map<char, trienode*> m;
    
    trienode(){
        this->isword = false;
    }
    /*Add a string key*/
    void insert_key(std::string key){
        if ( key.length() == 0){
            this->isword = true;
            return;
        }

        if( this->m.find(key[0]) == this->m.end())
            this->m[key[0]] = new trienode();
            this->m[key[0]]->insert_key(key.substr(1, key.length()-1));
    }
    
    /*Search for a string key*/
    bool search_key(std::string key){
        if(key.length() == 0){
            return this->isword;
        }
        if( this->m.find(key[0]) == this->m.end()){
            return false;
        }else{
            return this->m[key[0]]->search_key(key.substr(1, key.length()-1));
        }
    }

    /*Delete a string key
      Returns - 
      -1 - Key not present, did nothing
       0 - Key deleted, but trie not empty
       1 - Key deleted, trie empty
    */
    
    int delete_key(std::string key){
        if (key.length() == 0){
            if(false == this->isword)
                return -1;
            this->isword = false;
            if( 0 == this->m.size()){
                return 1; //means delete this node
            }
            else
                return 0;
        }

        if( this->m.find(key[0]) == this->m.end()){
            return -1;
        }

        int result = this->m[key[0]]->delete_key(key.substr(1, key.length()-1));
        if(result == 1){
            delete this->m[key[0]];
            this->m.erase(key[0]);
            if(!this->isword && this->m.size() == 0){
                //pass
            }else{
                result = 0;
            }
        }
        return result;
    }

};






