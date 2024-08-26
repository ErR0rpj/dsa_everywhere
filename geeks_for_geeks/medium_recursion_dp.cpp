//https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1
//Recursion, DP
//TLE
//Medium
//time: O(n*m)
//space: O(o*m)

#include<bits/stdc++.h>
using namespace std;


map<pair<int,int>,bool>mp;

  bool pattern_matching(string pattern, string str, int patpos, int strpos){
    int patlen = pattern.length();
    int strleng = str.length();
    
    if(mp.count({patpos,strpos})) return mp[{patpos,strpos}];

    if(patpos == patlen && strpos == strleng){
        return mp[{patpos,strpos}] = true;
    } else if((patpos >= patlen || strpos >= strleng) && pattern[patpos] == '*'){
        return mp[{patpos,strpos}] = pattern_matching(pattern, str, patpos+1, strpos);
    } else if(patpos >= patlen || strpos >= strleng){
        return  mp[{patpos,strpos}] = false;
    }

    if(pattern[patpos] == str[strpos]){
        return mp[{patpos,strpos}]  = pattern_matching(pattern, str, patpos+1, strpos+1);
    } else if(pattern[patpos] == '?'){
        return mp[{patpos,strpos}]  = pattern_matching(pattern, str, patpos+1, strpos+1);
    } else if(pattern[patpos] == '*'){
        for(int i=strpos; i<=strleng; i++){
            if(pattern_matching(pattern, str, patpos+1, i)){
                return mp[{patpos,strpos}] = true;
            }
        }
    } 
        return mp[{patpos,strpos}] = false;

}

/*You are required to complete this method*/
int wildCard(string pattern, string str) {
        mp.clear();
        bool isMatched = pattern_matching(pattern, str, 0, 0);
        if(isMatched){
            return 1;
        } else{
            return 0;
        }
}

int main(){
    string pattern;
    string str;
    cin>>pattern>>str;


    int output = wildCard(pattern, str);
    cout<<output<<"\n";

    return 0;
}
