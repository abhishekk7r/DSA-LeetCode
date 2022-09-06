string reverse(string s){
    int start = 0;
    int end = s.size()-1;
    while(start<end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}
class Solution {
public:
    bool isPalindrome(string s) {
        {
   string v = "";
    
    for(int i=0; i<s.size(); i++)
    {
        if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || 
           (s[i] >= '0' && s[i] <= '9') )
        {
            v += s[i];
        }
    }
    
    
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]>='A' && v[i]<='Z')
        {
            v[i] += 32;
        }
    }
    
    
    string reversed_v = reverse(v);
    
    
    if(reversed_v==v)
        return 1;
    
    return 0;
}
    }
};