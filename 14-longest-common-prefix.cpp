//https://leetcode.com/problems/longest-common-prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int l=0; l<strs[0].size(); l++){
            for(int i=1; i<strs.size(); i++){
                if(strs[i].size() <= l){
                    return res;
                }
                if(strs[i][l] != strs[0][l])
                    return res;
            }
            res += strs[0][l];
        }
        return res;
    }
};

["reflower","flow","flight"]
["flower","flower","flower","flower"]
["",""]
["rowdynas","rowpynas","rowllbynas"]
["a"]
["a", "aca", "accb", "b"]
["iflower","flow","flight"]
["c","acc","ccc"]
["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"]
["abxyz", "acxqr"]
["abqxx", "acqyy", "adqzz"]
["aaaab", "abaab"]
["abxdef", "acxghi"]
["abzxy", "aczpq", "adzrs"]
["apqrs", "aqqrs", "arqrs"]
["aabbc", "aacbc", "aadbc"]
["abxxc", "acxxc", "adxxc"]
["abmno", "acmno", "admno"]
["abxzz", "acxzz", "adxxx"]
["abpqr", "acpqr", "adpqr"]
["abmab", "acmab", "admab"]
["abxxy", "acxxy", "adxxy"]
["abccc", "acccc", "adccc"]
["axxbx", "ayxbx", "azxbx"]
["ababa", "acaba", "adaba"]
["abxyzq", "acxyzr", "adxyzs"]
["abqwe", "acqwe", "adqwe"]
["abzzb", "aczzb", "adzzb"]
["abkak", "ackak", "adkak"]
["abpab", "acpab", "adpab"]
["abxza", "acxza", "adxza"]
["abmabm", "acmabm", "admabm"]
["abxyb", "acxyb", "adxyb"]
["abcccx", "accccx", "adcccx"]
["abxabc", "acxabc", "adxabc"]
["abqaz", "acqaz", "adqaz"]
["abpqp", "acpqp", "adpqp"]
["abxyza", "acxyza", "adxyza"]
["abzaz", "aczaz", "adzaz"]
["abqaq", "acqaq", "adqaq"]
["abcbc", "accbc", "adcbc"]
["abzab", "aczab", "adzab"]
["abdab", "acdab", "addab"]
["abxab", "acxab", "adxab"]
["abnab", "acnab", "adnab"]
["abgab", "acgab", "adgab"]
["abhab", "achab", "adhab"]
["abjab", "acjab", "adjab"]
["abkab", "ackab", "adkab"]
["ablab", "aclab", "adlab"]
["abmab", "acmab", "admab"]
["abnabx", "acnabx", "adnabx"]
["abozb", "acozb", "adozb"]
["abpzb", "acpzb", "adpzb"]
["abqzb", "acqzb", "adqzb"]
["abrzb", "acrzb", "adrzb"]
["abszb", "acszb", "adszb"]
