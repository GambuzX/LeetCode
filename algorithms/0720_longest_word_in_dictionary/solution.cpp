class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> existing;
        for(string & word : words) existing.insert(word);
        
        int max_len = 0;
        string answer = "";
        for (string & word : words) {
            int gen_size = 1;
            
            while(gen_size <= word.length()) {
                
                string gen = word.substr(0, gen_size);
                
                // slice does not exist
                if (existing.find(gen) == existing.end()) break;
                
                // full word was found
                if (gen == word) {
                    
                    // update answer
                    if (gen_size > max_len) {
                        max_len = gen_size;
                        answer = word;
                    }
                    else if (gen_size == max_len) {
                        answer = answer < word ? answer : word;
                    }
                }
                
                gen_size++;
            }
        }
        
        return answer;
    }
};