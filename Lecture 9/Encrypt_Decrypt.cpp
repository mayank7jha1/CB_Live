class Encrypter {
public:
	map<char, string>m;
	vector<string>d;
	Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
		for (int i = 0; i < keys.size(); i++) {
			m[keys[i]] = values[i];
			/*
				a=ei
				b=zf
				c=ei
				d=am

			*/
		}
		d = dictionary;
	}

	string encrypt(string word1) {
		string ans = "";
		for (int i = 0; i < word1.size(); i++) {
			if (m.find(word1[i]) == m.end()) {
				return "";
			}
			ans += m[word1[i]];
		}
		return ans;
	}

	int decrypt(string word2) {

		/*word2 ko decrypt karke jo string ke options bane hume vo
		vaali string leni hain jo dictionary me hain:

		iska matlab ye bhi hosakta hain:
		ki hum directly dictionary vaali strings ko one by onr
		check karle and ye dekh le ki vo word2 ke equal hai kya?*/

		int ans = 0;
		for (int i = 0; i < d.size(); i++) {
			string s = encrypt(d[i]);
			if (s == word2) {
				ans++;
			}
		}
		return ans;
	}
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */



/*eizfeiam

ei----->a/c?
*/
