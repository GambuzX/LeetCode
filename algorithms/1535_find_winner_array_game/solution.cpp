class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> wins;
        
        int prev_winner = arr[0];
        int i = 1;
        int winner, loser;
        while(true) {
            int curr = arr.at(i);
            
            if(curr != prev_winner) {
            
                winner = max(prev_winner, curr);
                loser = min(prev_winner, curr);

                wins[winner]++;
                wins[loser] = 0;

                if(wins[winner] >= min((int)arr.size(), k)) return winner;
                prev_winner = winner;                  
            }                   
            
            i = (i+1) % arr.size();
        }
    }
};