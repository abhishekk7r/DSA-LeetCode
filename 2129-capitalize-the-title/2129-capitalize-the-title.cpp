class Solution {
public:
    string capitalizeTitle(string s) {
        int n = s.size();
        string str= "";
        string part = "";
        
        
        for(int i=0; i<n; i++)
        {
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=s[i]+32;
            }
        }
        
        int i=0;
        int j=0;
        int k=0;
        
        while(k<s.size()){
            
            if(s[j]==' ' && (j-i)>2){
               part = s.substr(i, (j-i));
               part[0] = part[0] - 32; 
               str += part; 
               str += ' ';
                i= j+1;
                j++;
                part="";
                
            } 
            else if(s[j]==' ' && (j-i)<=2) 
            {
                str += s.substr(i, (j-i));
                str += ' ';
                i= j+1;
                j++;
                part="";
            }
            else{
                j++;
            }
            k++;
        }
        if((j-i) > 2) 
        {
            part = s.substr(i, (j-i));
               part[0] = part[0] - 32; 
               str += part; 
                i= j+1;
                j++;
                part="";
        } else {
            part = s.substr(i, (j-i));
            str += part;

        }
        
        
        return str;
        
    }
};