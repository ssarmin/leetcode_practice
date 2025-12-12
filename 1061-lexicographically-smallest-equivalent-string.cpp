//https://leetcode.com/problems/lexicographically-smallest-equivalent-string
class Solution {
public:
    unordered_map<char, char> parent;
    char find(char ch){
        char p = parent[ch];
        while(p != ch){
            ch = p;
            p = parent[ch];
        }
        return p;
    }
    void unit(char ch1, char ch2){
        char p1 = find(ch1);
        char p2 = find(ch2);

        if(p1 < p2){
            parent[p2] = p1;
        }else{
            parent[p1] = p2;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(char ch = 'a'; ch <= 'z'; ch++){
            parent[ch] = ch;
        }
        for(int i=0; i<s1.size(); i++){
            unit(s1[i], s2[i]);
        }
        string res = "";
        for(auto ch: baseStr){
            char p = find(ch);
            res += p;
        }
        return res;
    }
};
/*
"dccaccbdafgeabeeghbigbhicggfbhiccfgbechdicbhdcgahi"
"igfcigeciahdafgegfbeddhgbacaeehcdiehiifgbhhehhccde"
"sanfbzzwblekirguignnfkpzgqjmjmfokrdfuqbgyflpsfpzbo"
"abc"
"bcd"
"d"
"napytcplhv"
"hqbpvxyeyy"
"abcdefghijklmnopqrstuvwxyz"
"azyxwvutsrqponmlkjihgfedcb"
"zyxwvutsrqponmlkjihgfedcba"
"abcdefghijklmnopqrstuvwxyz"
"yrrvttsvqxqtutsxwrvqswwvuwwtwtyxwyxuywtswsyytssswsuqxwqxtvxxxytqqyrsttxtuyywwrvruxtvtwtvtsrxtquyyuuv"
"bghdjklbgiabhdiafjgbjheelkiglikaeicdhegfbijjkaahjlaidglkihhgeibebeblfjcbhelbidbahjdgdhfeaadkhedafldb"
"abcdefghijklmnopqrstuvwxyz"
"dgikzjbhpgrkcuvdfhyvmqqolfgpxewcfbbruiljrvxjjbhldcvjnimxbmshrrzxjipzejnjqgusblghrodhxuerpouuntkodqkjzctlxcnouwclrpmtwktxuzwbvvnpwheqehimnzpulhhipwkitudskypgsuqjexqonthflxusuxttfjolmeculbziyxdpxksvjnbusdeokmxpcuneewwgbhoqctedgtvzzklwmldyqgmszjtjmfogtxtvunmcdhmygdnurkxmqklwuvjhukiupuvznjuxsvzxebpgqftrmmkpdcobpcttekfehufnicokzphkccbzwpqtkvumfegtilcpdyubmcgblhrplgntibfmivvwgzqmhldpjpxubyiudxphmkbjmtdsknlfnzpyxeqdyfqhtpvnlzrdpmvsddocrkykifmiciovhgjtwicmwpqjgjtxotzthuvmstogmkwdycbwgdzzbcflmxbrrrrlpwma"
"kdjhhunwztqusxpsnlqoktnlydeuzfbgrcewgcyugiqmgjvmmcmdetnjrolctnqtxvblomibdjbfhsijnznroidlsskcgrkgjsnbcwxuetmgdbmghjeoiuvosmgwigmuxgtzonzlxhowhopjoglhyyiskifhyrkodcqoxyvscegshbdyjgjodmourodntxtrmymlzggicsopikizbzmjtnetvogsjzevgwbqcrztyrhvqzfuqjpuxsujuxenuggliwemlhfrsfvtrthshbxcvlfuoozukegwvuyhohvgilpheipktdfxewkyilvdypewbxvqttzpqnhxrpcicmxbigisbfurfctwsvrgldozmkoukubqdpqmtoqvrpyuyctqvorfecmntucgopxngrbkxfblvtfsblygletbtfkfbnudjsicuvducomhmvptmshjcoxxxsbnkqpwdpjkfdzcbjfqbrqycppowuizfdxcqvmvqehwgxdv"
"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
*/
