#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string>
#include <stdbool.h>
#include "PhoneticFinder.hpp"

/*
* @author Eli, Ron and Tal
*/

namespace phonetic {
    using namespace std;
    using namespace boost::algorithm;
	std::string find(string text, string word ){
		if (!check(text, word)) throw std::invalid_argument( "error" );// בדיקות
		vector<string> result ;
        split(result, text, is_space());
		for (int i=0; i<result.size(); ++i){
			if(result[i].length() == word.length()){
				if(checkWord(result[i], word))
					return result[i];
			}
		}
		throw std::invalid_argument( "error" );
	}
	
	bool check(string text, string word){
		if (text.length() == 0 || word.length() == 0)
			return false;
		vector<string> result = text.split(' ');
		if (result.size() > 1) return false;
		return true;
	}
	
	bool checkWord(string resultI, string word){
		int arr[26]=[0,1,2,3,4,1,2,7,8,9,2,11,12,13,14,1,16,17,18,3,14,21,21,23,8,18];
		transform(resultI.begin(), resultI.end(), resultI.begin(), ::tolower);
		
		for (int i=0; i<resultI.size(); ++i){
			int x = resultI[i] - 'a';
			int y = word[i] - 'a'; 
			if(arr[x]!=arr[y])
				return false;
		}
		return true;
	}
}
