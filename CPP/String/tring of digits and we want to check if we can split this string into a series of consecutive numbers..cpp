#include<bits/stdc++.h>
#include<string.h>
using namespace std;
bool help(string &s) {
   for(int len =1;len<=s.size()/2;len++){
       long long prev = stoll(s.substr(0,len));
       int start= len;
       bool ans =true;
       while(start<=s.size()){
           long long next=prev-1;
           string nextValue = to_string(next);
           if(s.substr(start,nextValue.size())!=nextValue){
               ans=false;
               break;
           }
           start=start+nextValue.size();
           prev =next;
       }
       if(ans)return true;
   }
   return false;
}
int main() {
    string s = "1009998979695949392919088";
    if (help(s)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}
