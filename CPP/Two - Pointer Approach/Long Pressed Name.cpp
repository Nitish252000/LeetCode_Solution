bool isLongPressedName(string name, string typed) {
        // unordered_map<char,int>mp1,mp2;
        // for(auto i:name){
        //     mp1[i]++;
        // }
        // for(auto i:typed){
        //     mp2[i]++;
        // }
        // for(auto i:mp1){
        //     if(mp2[i.first]<i.second)return false;
        // }
        // return true;
        int n = name.size();
        int i = 0;int j = 0;
        while (j < typed.size()) {
            if (i < n && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j > 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }
        return i == n;
    }
