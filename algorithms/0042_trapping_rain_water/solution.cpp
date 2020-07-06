struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        
        unordered_set<pair<int,int>, pair_hash> seen;
        
        // LEFT-RIGHT PASS
        int l = 0, r = 0;        
        while(l < height.size()-1 && height[l] <= height[l+1]) {
            l++;
        }
        r = l+1;
        
        int ltotal = 0;
        while(r < height.size()) {
            // find right limit
            int llimit = height[l];
            while(r < height.size() && height[r] < llimit) {
                r++;
            }
            if(r >= height.size()) break;
            
            // add trapped water
            seen.insert(make_pair(l,r));
            for (int i=l+1; i < r; i++)
                ltotal += llimit-height[i];
            
            l = r;
            while(l < height.size()-1 && height[l] <= height[l+1]) {
                l++;
            }
            r = l+1;
        }
        
        // RIGHT-LEFT PASS
        int rtotal = 0;
        r = height.size()-1;
        
        while(r > 0 && height[r-1] >= height[r]) {
            r--;
        }
        l = r-1;
        
        while(l >= 0) {
            // find l limit
            int rlimit = height[r];
            while(l >= 0 && height[l] < rlimit) {
                l--;
            }
            if(l < 0) break;
            
            // add trapped water
            if(seen.find(make_pair(l,r)) == seen.end()) {
                for (int i=r-1; i > l; i--)
                    rtotal += rlimit-height[i];                
            }
            
            r = l;
            while(r > 0 && height[r-1] >= height[r]) {
                r--;
            }
            l = r-1;
        }
        
        
        return ltotal + rtotal;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}