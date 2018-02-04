//Substring with Concatenation of All Words

class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words){
		vector<int> ans;
		if (s.empty()||words.empty())
			return ans;
		unordered_map<string,int> Mwords,Cwords;
		int n = words.size(), l = s.length(), len = words[0].length();
		int left,count;
		for (string word:words)
			Mwords[word]++;
		for (int i=0; i<len; i++){
			left = i;
			count = 0;
			for (int j=i; j<=l-len; j+=len){
				string t = s.substr(j,len);
				if (Mwords[t]){
					Cwords[t]++;
					if (Cwords[t]<=Mwords[t])
						count++;
					else{
						while (Cwords[t]>Mwords[t]){
							string tt = s.substr(left,len);
							if (Cwords[tt]){
								if (Cwords[tt]<=Mwords[tt])
									count--;
								Cwords[tt]--;
							}
							left +=len;
						}
					}
					if (count == n){
						ans.push_back(left);
						t = s.substr(left,len);
						Cwords[t]--;
						count--;
						left +=len;
					}
				}
				else{
					Cwords.clear();
					count = 0;
					left = j+len;
				}
			}
			Cwords.clear();
		}
		return ans;
	}
};
/*time limited
class Solution{
public:
	vector<int> findSubstring(string s, vector<string>& words){
		vector<int> ans;
		if (s.empty()||words.empty())
			return ans;
		unordered_map<string,int> Mwords,Cwords;
		int n = words.size(), l = s.length(), len = words[0].length();
		int left,count;
		for (string word:words)
			Mwords[word]++;
		for (int i=0; i<len; i++){
			left = i;
			count = 0;
			for (int j=i; j<=l-len; j+=len){
				string t = s.substr(j,len);
				if (Mwords[t]){
					Mwords[t]--;
					Cwords[t]++;
					count++;
					if (count == n){
						ans.push_back(left);
						t = s.substr(left,len);
						Cwords[t]--;
						Mwords[t]++;
						count--;
						left +=len;
					}
				}
				else{
					if (Cwords[t]){
						while (Mwords[t]==0){
							string tt = s.substr(left,len);
							Cwords[tt]--;
							Mwords[tt] ++;
							count--;
							left +=len;
						}
						Mwords[t]=0;
						Cwords[t]++;
						count++;
					}
					else {
						for (string word:words){
							Mwords[word] += Cwords[word];
							count -= Cwords[word];
							Cwords[word] = 0;
						}
						left = j+len;
					}
				}
			}
			for (string word:words){
				Mwords[word] += Cwords[word];
				Cwords[word] = 0;
			}
		}
		return ans;
	}
};
*/