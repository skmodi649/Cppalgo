#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a = 1 ; a <= t ; a++){
        string binary;
        cin >> binary;
        int max = 0;
        for(int i = 0 ; i < binary.length() ; i++){
            int min = 0;
             for (int len = 1; len <= binary.length() - i; len++){
                 string substring = binary.substr(i , len);
                 int zeros = 0;
                 for(int k = 0 ; k < substring.length() ; k++){
                     if(substring[k] == '1'){
                         zeros++;
                     }
                 }
                 int ones = substring.length() - zeros;
                 if (zeros != ones) {
                        min = zeros > ones ? ones : zeros;
                        if (min > max)
                            max = min;
                    }
             }
        }
        cout << max << endl;
    }
    return 0;
}