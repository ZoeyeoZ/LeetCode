//Letter Combinations of a Phone Number
class Solution{
public:
	vector<string> letterCombinations(string digits){
		vector<string> tel = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> comb;
		int d;
		for (int i=0; i<digits.length();i++){
			vector<string> tmp;
			d = digits[i]-'0';
			if ((d<0)||(d>9))
				break;
			if (comb.empty())
				comb.push_back("");
			for (int j=0; j<tel[d].length(); j++)
				for (int k=0; k<comb.size(); k++)
					tmp.push_back(comb[k]+tel[d][j]);
			comb = tmp;
		}
		return comb;
	}
};