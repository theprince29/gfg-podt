// Problrm Link: https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

// If the characters in str1 can be changed to get str2, then two strings, str1 and str2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.


if(str1.length() != str2.length())
          return false;
        unordered_map<char,char>Hashmap;
        vector <int> Visited(26,0);
        for(int idx = 0; idx < str1.length();idx++){
            if(Hashmap.find(str1[idx]) == Hashmap.end()){
                if(Visited[str2[idx] -'a'] == 0){
                   Hashmap[str1[idx]] = str2[idx]; 
                   Visited[str2[idx] -'a'] = 1;
                }
               else return false;
            }
            else if(Hashmap.find(str1[idx]) != Hashmap.end()){
                if(Hashmap[str1[idx]] != str2[idx])
                 return false;
            }
        }
         return true; 
}
};
