class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> elements = getFormulaCounts(formula);        
        return buildResultFormula(elements);
    }
    
    map<string,int> getFormulaCounts(const string & formula) {
        map<string, int> elements;
        
        string curr = "";
        string count = "";
        for (int i = 0; i < formula.length(); i++) {
            
            // new element
            if (isupper(formula[i])) {
                
                // already had something
                if (curr.length() != 0) 
                    elements[curr] += (count.length() != 0 ? stoi(count) : 1);
                
                curr = formula[i];
                count = "";
            }
            // part of element
            else if (islower(formula[i])) {
                curr += formula[i];
            }
            
            // digit
            else if (isdigit(formula[i])) {
                count += formula[i];
            }
            
            // parentheses
            else if (formula[i] == '(') {
                
                // slice formula inside parentheses
                size_t closing = formula.find_last_of(')');
                string subformula = formula.substr(i+1, closing - i - 1);
                
                // recursively call this function
                map<string,int> recursive_res = getFormulaCounts(subformula);
                
                // check count after subformula
                string sub_count = "";
                int j = closing+1;
                for (; j < formula.length(); j++) {
                    if (!isdigit(formula[j])) break;
                    sub_count += formula[j];
                }
                
                // add results
                for (auto & ele : recursive_res) {
                    elements[ele.first] += ele.second * (sub_count.length() != 0 ? stoi(sub_count) : 1);
                }
                
                // increment counter
                i = j;
            }
        }
        
        // remaining element
        if (curr.length() != 0)
            elements[curr] += (count.length() != 0 ? stoi(count) : 1);
        
        return elements;
    }
    
    string buildResultFormula(map<string, int> & elements) {
        string res;
        
        for (auto & ele : elements) {
            res += ele.first;
            if (ele.second != 1)
                res += to_string(ele.second);
        }
        
        return res;
    }
};