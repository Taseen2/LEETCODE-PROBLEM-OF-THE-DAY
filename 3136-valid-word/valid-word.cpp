class Solution {
public:
    bool isValid(string word) {
        if( word.length() < 3 ) return false;

        bool vowel = false, consonant = false;

        for(char ch : word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e'|| ch == 'i'|| ch == 'o'|| ch == 'u'){
                    vowel = true;
                }else{
                    consonant = true;
                }

            }
            else if(!isdigit(ch)) return false;
        }
        return vowel && consonant;
    }
};