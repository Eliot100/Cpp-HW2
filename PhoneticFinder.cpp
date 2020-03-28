#include <bits/stdc++.h> 
#include <boost/algorithm/string.hpp>
#include <string>

/*
* @author Eli, Ron and Tal
*/

namespace phonetic {
    using namespace std;
	std::string find(string text, string word ){
		string reterndWord;
		vector<string> result; 
		boost::split(result, text, boost::is_any_of(" "));
		for (int i=0; i<result.size(); ++i){
			if(result[i].length() == word.length()){
				if(checkWord(result[i], word))
					return result[i];
			}
		}
		throw std::exception;
	}
	
	bool checkWord(string resultI, string word){
		transform(resultI.begin(), resultI.end(), resultI.begin(), ::tolower);
		
		for (int i=0; i<result.size(); ++i){
			int x = resultI.charAt(i)-'a';
			int y = word.charAt(i)-'a'; 
			if(ron[x]==ron[y]) return true;
		}
	}
}