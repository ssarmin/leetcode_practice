//https://leetcode.com/problems/removing-stars-from-a-string
// better version
class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for(auto ch: s){
            if(ch == '*'){
                res.pop_back();
            }else{
                res.push_back(ch);
            }
        }

        return res;
    }
};




class Solution {
public:
    string removeStars(string str) {
        stack<char> s;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '*'){
                s.pop();
            }else{
                s.push(str[i]);
            }
        }

        ostringstream result;
        while(!s.empty()){
            result << s.top();
            s.pop();
        }

        string res = result.str();
        reverse(res.begin(), res.end());
        return res;
    }
};


// "abcd***"
// "a*b*c*d*e*f*ghijk*lmnop*qrstuv*wxyz*"
// "dfssssssssssssssssstrrrrrrrrrrrrrrrrerase***dsfsdfdsfdsfdfs*sdfdsfsdfs*************dsfffffffffffffffff***dfsdfsdgfghdsffffffffffffffftyjtyjhndtfbgdsgsdgsdfsdfdsf*"
// "oipoipoiiiiiiiiereeeeeeeeeeeeeeepoiira***************************dskhwgegkhkhusfdjbkjsfdjkjnsddsfsssssssssssssjnjbsdfkjbe***dsfsdfdsfdsfdfs*sdfdsfsdfs****************dfsdfsdgfghtyjtyjhndtfbgdsgsdgsdfsdfdsf*"
// "oipoipoi**dsdsfdsdsfdsfdsffffffffffffffffffffffffffiiiiiiiereeeeeeeeeeeeeeepoiira***************************dskhwgegkhkhusfdjbkjsfdjkjnsddsfsssssssssssssjnjbsdfkjbe***dsfsdfdsfdsfdfs*sdfdsfsdfs****************dfsdfsdgfghtyjtyjhndtfbgdsgsdgsdfsdfdsf*"
// "lewagsegr**dgrtger**tretruyiuoi*uyhgfdsfdsg**bgfhnbfcx**zvcbet**cod*eerertrytyuyiygjfghfdszv**dfbgfhty*jyjukiuuplkjhgf*bddvsfdgfdgrfdszczdvx*cbg**hggfdfsadferegthtfgdsfgd"
// "khfgjkd*fsjjkf*gkjhfsdjhjhfsdjhjhfdjhjhfdjhjgjkujhjjgkfsluuksfdjhj*hfsdjfsdgjdfsjjd*fsjhdfsjdfsjjhdfsjjhjhvj*hjhvjhjfsdjeryyuwreuyufekgjdfsjj*dfsgjkfsdjjfsdjhdfsjjjjjjsfdgjhjfooiiewrioiwerier*wopiipoerwqerqoiiureu*yuyreyuuuuuuuuuuuuuuuuuuuuuuudfhfdhjfdahjhfdhjnxcznbxcvz*bncvxbncvxhjdfshjfsdhhhhhhhh*hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhlewagsegr**dgrtger**tretruyiuoi*uyhgf*dsfdsg**bgfhnbfcx**zvcbet**cod*eerertrytyuyiygjfghfdszv**dfbgfhty*jyjukiuuplkjhgf*bddvsfdgfassdsadsadasdsasdgfdgdfgfdgfdg**hgfhgtfgddgrfdszczdvx*cbg**hggfdfsadferegthtfgdsfgd"
// "df*sssssfjjdfhfhgf*shfhgjhkjkk*jloipoiuytrt*edsfgdhdfdsfb*vvnvcbghfjgjuy*trersdfghfbcvxdfsghnbvfghfgdgbff*fgqweqwerqeredfs**dfdfuierjkdafjhdfajhcbcxbndfsh**jdafuyueryureorpofkjdfjhdnbcxnbdfhjdsfagy**uearyudfag*jdfsghjvbdsf**ajhjhereroidfaopidadafjhdsnbdfahghjgdhjjhfjhf**dzhjhjdfhjjhrtrer**iuuiruuyrhgdfhghgdf**svbdsfhghgewrjgyery**urepdfaoiuihjfsdabdsf**avhgewrhr**euitpodfuyhgdfsavhdafhjhjhgf**qwwqhhgdhjzdhjxchjsfhjjhfjfdfdfsssssssssssstrrrrrrrrrrrrrr*rrerase***dsfsdfdsfdsfdfs*sdfdsfsdfs*************dsfffffffffffffffff***dfsdfsdgfghdsffffffffff*ffffftyjtyjhndtfb*gdsgsdgsdfsdfdsf*"
