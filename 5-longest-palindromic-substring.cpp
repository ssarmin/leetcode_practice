//https://leetcode.com/problems/longest-palindromic-substring
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MIN));
        vector<vector<bool>> visit(s.size(), vector<bool>(s.size(), false));
        queue<pair<int, int>> q;
        pair<int, int> p = {0, 0};
        int max_val = 1;
        for(int i=0; i<s.size();i++){
            int val = 1;
            bool flag = false;
            for(int j=i+1; j<s.size(); j++){
                flag = true;
                if(s[i] == s[j]){
                    val++;
                    continue;
                }
                dp[i][j-1] = val;
                dp[j-1][i] = val;
                if(val > max_val){
                    max_val = val;
                    p = {i, j-1};
                }
                q.push({i, j-1});
                i = j-1;
                break;
            }
            if(!flag){
                q.push({i, i});
            }else{
                q.push({i, s.size()-1});
                dp[i][s.size()-1] = val;
                dp[s.size()-1][i] = val;
                if(val > max_val){
                    max_val = val;
                    p = {i, s.size()-1};
                }
            }
        }
        while(!q.empty()){
            int start = q.front().first;
            int end = q.front().second;
            q.pop();
            if(visit[start][end])
                continue;
            visit[start][end] = true;
            if(start-1 >= 0 && end+1 < s.size() && s[start-1] == s[end+1]){
                q.push({start-1, end+1});
                dp[start-1][end+1] = dp[start][end] + 2;
                dp[end+1][start-1] = dp[start-1][end+1];
                if(dp[start-1][end+1] > max_val){
                    max_val = dp[start-1][end+1];
                    p = {start-1, end+1};
                }
            }
        }
        string str = s.substr(p.first, p.second-p.first+1);
        return str;
    }
};
/*
"aacabdkacaa"
"bb"
"a"
"tattarrattat"
"cabac"
"abba"
"aaca"
"abcdasdfghjkldcba"
"jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx"
"jaliztdispcppzgzjxnjxwbhhtbjrijyibqwrhwuscmokylygielwssuyretqnoiglvsltmhetvdoliwibrnwmdtauczcswuqxxokaykslfzgxovphdptgtrbbozdkdgawcegemkumgbyqzjrzurkdaibfwwvcxfcstvixisrcfxvnlzizlbnacxssetlsxrvcaqvzmbnzdfmtskmxmjblzgpdsjvhqhrihiajvwxbmjsncjhmilercbdbzyncrnlyrxrefaeuttkscfttqnedzvqisclbremuxmngrpgqjqkijpizkixkrgaarpknivrrirbkeddkulvlfuetbdnugzodbfufqhrpkyufhrhnnnzsenkvqsuhlbaimniusuxsnmavqbilzgsfxjykrxdkkpnneikwlucdghnikojythrpgwyzoqgraycavrivsbfuaonssmryhcykooivrxmeeowllsfeyxrznvkdpobohpzolnpbxjjxbpnlozphobopdkvnzrxyefsllwoeemxrviookychyrmssnoaufbsvirvacyargqozywgprhtyjokinhgdculwkiennpkkdxrkyjxfsgzlibqvamnsxusuinmiablhusqvknesznnnhrhfuykprhqfufbdozgundbteuflvlukddekbrirrvinkpraagrkxikzipjikqjqgprgnmxumerblcsiqvzdenqttfcskttueaferxrylnrcnyzbdbcrelimhjcnsjmbxwvjaihirhqhvjsdpgzlbjmxmkstmfdznbmzvqacvrxsltessxcanblzizlnvxfcrsixivtscfxcvwwfbiadkruzrjzqybgmukmegecwagdkdzobbrtgtpdhpvoxgzflskyakoxxquwsczcuatdmwnrbiwilodvtehmtlsvlgionqteryusswleigylykomcsuwhrwqbiyjirjbthhbwxjnxjzgzppcpsidtzilaj"
"ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
*/
