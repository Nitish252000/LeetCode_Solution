#include<iostream>
#include<string>
using namespace std;
void permutation_of_string (string str, string ans){
  //Base Case
  if(str.size()==0){
    cout<<ans<<" ";
    return;
  }
  // choice in choosen
  for(int i=0;i<str.size();i++){
    char choose=str[i];
    string rem = str.substr(0,i)+str.substr(i+1);
    permutation_of_string(rem,ans+choose);
  }
}

int main(){
  string s ="aab";
  string ans="";
  permutation_of_string(s,ans);
  return 0;  
}

//----------------------------- If only need unique -----------------------------
// #include<iostream>
// #include<string>
// #include<set>
// using namespace std;
// set<string>st;
// void permutation_of_string (string str, string ans){
//   //Base Case
//   if(str.size()==0){
//     // cout<<ans<<" ";
//     st.insert(ans);
//     return;
//   }
//   // c in all choices
//   for(int i=0;i<str.size();i++){
//     char choose=str[i];
//     string rem = str.substr(0,i)+str.substr(i+1);
//     permutation_of_string(rem,ans+choose);
//   }
// }

// int main(){
//   string s ="aab";
//   string ans="";
//   permutation_of_string(s,ans);
//   for(auto s:st)cout<<s<<" ";
//   return 0;  
// }
