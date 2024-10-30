#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;

        int s_length = s.length() ;  
        int t_length = t.length() ;  

        int firstS = 0 ;  

        int secondT = 0 ;  

        int common = 0 ; 

        while( firstS < s_length  && secondT < t_length ) 
        {
             if( s[firstS] == t[secondT] ) 
             {
                common++ ; 
             }
             else
             {
                break ;  
             }

             firstS = firstS + 1 ;  
             secondT = secondT + 1 ;  
        }

        int firstPart =  s.length() ;  

        int secondPart ; 

        if ( common != 0 ) 
        {
           secondPart  =  t.length() - common + 1  ; 
        }
        else 
        {
           secondPart = t_length ;  
        }

        int ans = firstPart + secondPart ;  

        cout << ans << endl ;  
        
    }
}

