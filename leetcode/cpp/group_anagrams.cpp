/*
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

/*
 * class Solution {
 *     int powerWithMod(int base, int t, int mod){
 *         if(base == 1){
 *             return 1;
 *         }
 *         if(mod <= 1){
 *             return 0;
 *         }
 *         long res = 1;
 *         long bb = base;
 *         int i = 0;
 *         while((1<<i)<=t && i < 31){
 *             if(t & (1<<i)){
 *                 res = (res*bb)%mod;
 *             }
 *             bb *= bb;
 *             i++;
 *         }
 *         return res;
 *     }
 *     //according to fermat little theorem (a^(p-1)%p) === 1
 *     // (N/d)%mod = (N*d^(p-2))%mod
 *     int devideWithMod(long init, int d, int mod){
 *         return (init * powerWithMod(d,mod-2,mod))%mod;
 *     }
 *     void productFirstNprime(int cnt, vector<int>&prime){
 *         bool vv[1000] = {false};
 *         for(int i = 2; i < 1000; i++){
 *             if(vv[i] == false){
 *                 prime.push_back(i);
 *                 //cout<<i<<endl;
 *                 int j = i+i;
 *                 while(j<1000){
 *                     vv[j] = true;
 *                     j += i;
 *                 }
 *                 if(prime.size()==cnt){
 *                     break;
 *                 }
 *             }
 *         }
 *         return ;
 *     }
 *     int getKey(const string&s, const vector<int>&pri, const int mod){
 *         long res=1;
 *         for(char c:s){
 *             res = (res * pri[c-'a'])%mod;
 *         }
 *         return res;
 *     }
 * public:
 *     vector<vector<string>> groupAnagrams(vector<string>& strs) {
 *         vector<int> pri;
 *         productFirstNprime(26, pri);
 *         unordered_map<int,int>ump;
 *         vector<vector<string>>res;
 *         const int mod = 1e9+7;
 *         for(string&s:strs){
 *             int key = getKey(s,pri,mod);
 *             if(ump.count(key)){
 *                 res[ump[key]].push_back(s);
 *             }else{
 *                 ump[key] = res.size();
 *                 res.push_back({s});
 *             }
 *         }
 *         return res;
 *     }
 * };
 */

/*
 * class Solution {
 * //     string getSignature(string str) {
 * //         int alphabet[26] = {0};
 * //         for (auto c : str)
 * //             alphabet[c-97]++;
 *
 * //         string result;
 * //         for (auto i : alphabet)
 * //             result += (char)(i+48);
 *
 * //         return result;
 * //     }
 * public:
 *     vector<vector<string>> groupAnagrams(vector<string>& strs) {
 *         unordered_map<string, int > anagramMap;
 *         vector<vector<string>> result;
 *         int count = -1;
 *         for (auto str : strs) {
 *             // string sig = getSignature(str);
 *             string sig = str;
 *             sort(sig.begin(), sig.end());
 *             if (anagramMap.count(sig)) {
 *                 result[anagramMap[sig]].push_back(str);
 *             } else {
 *                 result.push_back({str});
 *                 anagramMap[sig] = ++count;
 *             }
 *         }
 *
 *         return result;
 *     }
 * };
 *
 * auto speedup=[](){
 *     std::ios::sync_with_stdio(false);
 *     cin.tie(nullptr);
 *     cout.tie(nullptr);
 *     return nullptr;
 * }();
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams1(vector<string> &strs) {
    vector<vector<string>> ret;
    unordered_map<int, vector<string>> map_;
    int i = 0;
    for (auto s : strs) {
        sort(s.begin(), s.end());
        hash<string> h;
        int str_hash = h(s);
        map_[str_hash].push_back(strs[i]);

        ++i;
    }

    for (auto &it : map_) {
        ret.push_back(it.second);
    }

    return ret;
}

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ret;
    unordered_map<string, int> map_;
    int i     = 0;
    int count = -1;
    for (auto s : strs) {
        sort(s.begin(), s.end());
        if (map_.count(s)) {
            ret[map_[s]].push_back(strs[i]);
        } else {
            ret.push_back({strs[i]});
            map_[s] = ++count;
        }
        ++i;
    }
    return ret;
}

int main() {
    struct test {
        vector<string> arr;
        vector<vector<string>> expected;
    };

    vector<test> tests = {
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {
                {"ate", "eat", "tea"},
                {"nat", "tan"},
                {"bat"},
            },
        },
    };

    for (auto t : tests) {
        vector<vector<string>> ret = groupAnagrams(t.arr);
    }
}
