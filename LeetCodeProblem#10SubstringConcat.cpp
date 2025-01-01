#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
vector<T> delete_element(vector<T> v, T s) {
	vector<T> v1;
	int freq = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == s && freq == 0) {
			freq = 1;
			continue;
		}
		v1.push_back(v[i]);
	}
	return v1;

}

template <typename T>
bool is_exist(vector<T> v, T e) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == e) {
			return 1;
		}
	}
	return 0;
}

template <typename T>
vector<vector<T>> is_exist_and_delete(vector<T> v, T e) {
	vector<vector<T>> a;
	a.push_back({"no"});
	a.push_back({});
	vector<T> f;
	int flag = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == e && flag == 0) {
			flag = 1;
			a[0] = { "yes" };
			continue;
		}
		f.push_back(v[i]);
	}
	a[1] = f;
	return a;
}

int get_alpha_pos(char c) {
	string alphas = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < alphas.length(); i++) {
		if (alphas[i] == c) {
			return i + 1;
		}
	}
}

int get_alpha_poss(string s) {
	int res = 0;
	for (int j = 0; j < s.length(); j++) {
		res = res + (j+1) * get_alpha_pos(s[j]);
	}
	return res;
}

template <typename DT>
void print_vector(vector<DT>  v){
	cout << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


vector<int> solve1(string s, vector<string> words) {
	vector<string> cache;
	vector<vector<string>> return_val;
	vector<int> save;
	const int L = words[0].length();
	int j;
	int k;
	vector<string> comb;
	string temp_str;

	for (int i = 0; i < s.length() - L + 1; i++) {
		temp_str = "";
		for (int j = 0; j < L; j++) {
			temp_str = temp_str + s[i + j];
		}
		comb.push_back(temp_str);
	}
	
	for (int i = 0; i < comb.size(); i++) {
		cache = words;
		j = 0;
		k = 0;

		while (j < words.size() && i + k < comb.size()) {
			return_val = is_exist_and_delete(cache, comb[i + k]);
			if (return_val[0][0] == "yes") {
					cache = return_val[1];
					k = k + L;
					j++;
					continue;
				}break;
			}
		if (j == words.size()) {
			save.push_back(i);
		}

	}

	print_vector(save);
	cout << save.size() << endl;
	return save;
}

int main()
{
	string s = "barfoofoobarthefoobarman";
	vector<string> v = { "bar", "foo", "the" };
	string s1 = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "word" };
	//solve1("lingmindraboofooowingdingbarrwingmonkeypoundcake", { "fooo","barr","wing","ding","wing" });
	solve1(s, v);
	//solve1(s1, words);
	//solve1("wordgoodgoodgoodbestword", { "word", "good", "best", "good" });
	//solve1("aaa", { "a","a" });
	//solve1("a", { "a" });
	//solve1("cccab", { "ca", "cc" });
	//solve1("a", { "a" ,"a" });
	solve1("xjpguhvytyjcknhjqkwelhjqbdgtwxgvgxbdeydxwozidiutuqafxjxaodtkdbfjyiocgtbfhcplmjggbgoarlcgpxssyadyiuapndwxhlitvoayvqzobbuqzpkzpqyzkaqzgmwnyghvvjtszuiawdtxufylvwkhzbhfpfsnmbkjkedlylowqjvkquxmsivrlewakrqysahfgmqhxgfqpbcgxaupkrhvwfviwngrqpwybohaxnsoqvwpxqehkncgvzqtpwkflidoznqwcjksehjdzpkjdmranhtcfejsopgncxjeguymbhpcwbmbpfbcnvhsbqnpftdjsonainoludqtgcwvjyywvhryxepfzuqsjgstthhqmxltbhokfojcvcavgqchmszvyupudykrvvmwedikrroptrmbjojvgkrheibjgnbdknboqjakbpbwgnyrbhmjtfqantjvgmaqcbhulhgowhkeukvxrkhnpznfvwcdldwnedjpkqfjxqnualruvahmcwrxuuafxwubzetmwyvtqkntvhnshwhjsyimujuthoxjuqvqqqmhazayipsqnzbfaktuvpocennadirvadcdeedpvvfixipxujtpajugwhhbsaxsfbvliaadwhmvqbsmmnenxavvhcxbcwwjxtvfuvlqdxlvafhpsnernznxemygiuqfonniiyanxnkzuuoohugvwvsajsirnyydnnnwnplkcwkyqamxvuurrmrafztuauzphmlvdzhfvrflurkpmfidtbgycbuevtufhhakgjrdbwqvqbmciwhbxpcbrwgmscrbjtmsffvgemdupryxphaoxcpobxcvbwwnrkfwscewqjsfcqerzffwjxmmwrhynelgosfiujenvwsxozpogwmrtbeqslqhrbnitsqpevcztxykynaemmvhnbzhnpogqeolyfdccfdxecjcrjidyelnhmvuclduprioylscswaxylbpvkvvqikxuhuytxtkqbapottgrvfphjgetdzjljigrcembzwsczjqsczlygcfpijkmktzvehmgoaknzcqylisnjdlqfshpbsdnndjrkxayykoxogxzqpoascsxubmytsljvuahucisowrccobudsuxuouoqimlaauxwxhqbpkqldsptwjyogviurymclyenueltlcvaollufcnbnmptjzqbycflcjyxnjsynnaealygpljdzzyjyomyrtjvchustnsgctkdgklwwubxvziwouuhpecslxmgmepoxbremcckzdhucqqqmlzcpcwcbilnmabkbtqpxszwvhtzzjslwrnntlsutdjgflsigkyfcxezexydiqrfigudsmalrjtwunfcxdibcmajjbotrfybmtfghftzqpxlcepcjxdmlgvwhjqarqcdlhltoeuettryyhahgfvsnqqucgxtzzykijfwpbcjvujvdjelqadeswawcxpdwpoeyvcqxfzubipetvpjxvpqtqmxpebotpuumxkjelffvwlosczpzrhsjwqycrmvihrugbgkolrjiezcgbtisbadzsbblqytzsqfvyrklitvmvxuyrcqufvvzwyloygnqwsmwjwitrdhobcmugcqnzlnwlykjeaadsmzekhxdlhsojekrjafinseysrjyrjblxbrjkrnvyflhjvasxfbkzhkraustdtfdwymhpzengqwqnxklelvetixvcpphjwkhuzokavxhlwzatjlxxjdqrbnvsccdypltqzdswcbhyaktmxrjgwbzxowqrzvpqgkiipaescoscymovfxebyfbpctgdoxvxidfxdjrfzmkxaavhabiyilpkevpvvksfpzetiwakkkjklgrlhblqnbctyuqtgkawjfrubrenenxpuqcdrptgsyctusmadnyospivhminahewxgzoxvxqtzjntxpymongdvdmknzkudirlhijchbxgkmbjcawsnevkikuvjgspolcyvlacmakymmiqmgibkensqiqbqiqfttdpgfrvfevsqdkelthwzuqpegqvqjakefbmkuhsyfmokwswpbsqwkfatyvjjxvncwzprjhpoteypywhcqxybfaufyfovbbaxcponygdrkeikarmrrmuwnqblvpiwsiuwzkkxqnqctbpusdnlqhhfxkssbapvllskvekmtcqndfhyjujbdtgafauhclenwwaucmiwoyjugqupmfspaarganpcztqxssruebqucbqirkzfsrwsrnardpvclnzfftblusgyvwgnjfudyrvpgwijngnatnfbihmebudwtjlerihrbchjartqzistxyufhikkdpiwauarejjfnsooljglsygpyaxhijrnyalywnsawdfkxtaidgvxgbmhdloougbsipteclezqljnejvjrtgzuvgygvoddrxlgqrjdxititgoeeavxiwrfdroahrdzoqfhhokgygormevsespnpjsscgukzxjopoxyfjedpuxeyswfnoucxmwbvqlwpwmgljestkviesoennjabfeauabpsnljjapwjvochmnngbrvodxribredttvihgthxsssivbwkodniaelyvvzpadkvasejnngfgbqdcmprpczqgmoejptlsdjvxpekdmslniqqufjmhieqwuufjntescbpthbyttjhdbzaiiosssioocvzrqdjugaonbmhxyqczpcixqarkkfaocaftfqnmsbbtqisoyvppxzoqbfclmdzpdgkiyxwqbymtiehjzyyzynrzutnhymwbvimvhkmiiadtekcgjafjpyikrvtqkrthzhcgsqrcquvxhxdsakbrkldbjwttnpcowgvqzotriqorotjqfmhpylthhocxdelcmiulwpdhgtywpkmuwvmugfbqtfpzlcdylxjhnoovkprzzdtvafqjmtbizqhmsmkdlwnykdtusmvrrpnswfbjacrbuaommysxwhyjktdfgzwzqlrmssxtwowqqkfclxchgcqqvwvdxudnhwbarzvnpregclknkowqqniojgtgayvhvyjozebpwhxasjncajuqydghjcplakuxlelkipbgwygrkvvkfqcdvlnenerpplpapcmatogqmnjyiekpwpvrakxpoqgfcxhtcutvicnwrwvbdhtbwovyaupolyunxdizxcvfgiezhbamitnhjkhjfxaqxwfuznuzppgxzkwilxuuskdewkpbhprenwbpkvobmubnfxwqwsmrepvbakejcwqpuregmukaplnuklmjgzamqxpqjualsqdmhjvvefxtskpeybngcpstmilweljwdoimyfhcmgxermlrpyxuqrnebycfmmbpamcyrlceszkllvedwbxmumqwktbyhdojrskidmoxmbizymeupbimnbiawlydoomfgyqmlgjzhuygifcagnmwowykhypyndfvcvhpetolpotztybclpyblwlvuctjhyflwoaajonydhawfbysrytewgztiucrvhdrydthsgixpkvwlwoeujlrpmkzhorcywvwzoftwnsoxoklkbrekcxcrjdyywcwszsupxnlngbmwmxgprmbvkdmthmrdqnyphsehhsuptilhiryzeauqdhjmtdsmqqbakihtcdjxluhtofsufpklwvxryrdrjhrtpyntdyqouxkideeitotrmtlkkqbuxsposchvaamxxyfccknyairmbczovaiuvzjneslguzdsxjwbvjzxsrmvvljqntlitwyxqldlkjfjsbkpnmohfaecnqtblgleelduwjhismtmqgdfurozusbhkwkweyckjihitosldozvuccovqppksxvrjtxhvitdrbwfvjkjkhdmjtkbizodyluietpzbifslbahnmqxuwmfpwjaxzdwkzeqstrweworaqypfrmznagewreuqjqaiwsdrkzvgpnignxnemotmuylmcheozhyvzbmjaksqzcyoclvozocvmnjrwofvvdswhhghtazucziekdulsxjgkszjieefkxcrekaxkatozbtmhnzbmihzdhinnmtzlxsrjtqtvjjwleksukvgucfzlnpbcianhthqoxllhuhuzsotejbanhazwpcyzcoixvanulydhgxganbeydgmminizphatxitsigmvfqdnplnfptdszrgieohvxirwskodqdyxvdkmpzresxyuoeevunsuxjqqthvkmthhxuvotnsoksiayovsboobzfttoofahmhggcucroqdgaeeqbzrppupunkkbpkldtrkymopcgvjgzpwaopsekjaxtlzixkltdxrrliurddzesxfjnzpzipwbcxlcjwvpwmghwabafcgyanjnmymupkxukiwvhtkdhrmdrnfxsmxszihogtixfirpsplzixcrorvigcfyqeqqmxeusoraylprccsnaveqobyueftullmxjstdjndhavacztpzqusevqybwtwhfihodctmpxvpswurpjthfllddlezfcjknsaquvcmsxdmvzemjztqkgtpsarzcalpunhqiledlipgjttsuolgvewpenohnbyjogzyrebeorlxmgshudnpjjgowwxlxxunfwmzapdqgonvuhcrkriubpkzljnlghymdmlfcqvkflfbsjsfbdbculdfwqscatqffdljuiubvbcqlxvmcwqwjvbhmwjmpcrufegbpackdhaoexcgvucgqfncbzqsbjniotkfvmpytspzprflmjrerhgugynhhapxvzcsosqhmhjbzqonaittpznvzaegctezvgrjaksorbsssghuqanhbaeadihfenfzvykwiekcgcualeubejlglpioyrwceddabnymrioznkbaoxdtgobsejicbeghhjhjyfvrqltfvufksifyxgsdrbhufncnyjywrvphgimddtnxbsxayqdsrkmyxonxantrilaqtouyhjvicvlclouebjeaxsyxftqqeqgaecynmwyqrjuexpiyymbxgzxmsnexgkxmpxabvytmhnsgeahepicxhbjbonywaxjrxlusjnhsazyfchlrpnqyqaahpadryoivzepkrwcuwdbykmrachasjazbbfsbtdwvhnfbkivgnwgxkxzmeahqagrbnlchqacaqjbatyigwoggnfvtfcjikclyoqheslgiuhiohswdickvihrpjaxtflttbaztlgcgpmwxhsapvmnfteueguylfrgiugbfmflduhadcdsxphellypuupfbjojduniiuwlqfothrmggvkthljdfakjjysoshzcevquceokvcqdxbxgoijtkucwuxknglrkghfjlvviznowqnfexqyhkcdfbquibnskvzviwstvfhuwubatraaedglgwfozujlpkgahategcacybcrtftxiziqxpfxjqibcrdlryqzasbaugrplmmvmwljnsgwkrznkcydaqdcjgcfmvuziguweifrcopnhpcrtcuwtzyegdjsadsklogryoibczqjquckwygrygxeliymlswyhfphtxkxzaipwmzvkhoiomobunnifmgorwwmvgjujtmhflcpvraldomzbahjmqzfovrjecgpvuwafzrcqrnvicwlceuqwuxkrqvxsdmpxjrfkihccxzmzvxdbuvxqshhkdhcgttgeklousqyrpkqnitocqoskvbuaiwjeppibcxwupumhfeupakrqylbwovyxujblalncilxaflhmrdbrpuiqhlmwgmvawyowjbzumyutldicilwxggnprblzoicmgqkqrjkfjgywjgbrsxoaderwffvvnxhunsmedwjpcklnqogklwmqaemijidyfnsvfezkclzgvntnbbypymfysugdemcjzuggbgqftqmofhbgjbvhqdhixqmbcomdktjnbzturhkwonfxpagffqpegdfitulgpwtsvoopvylklqjctsjaizfoemyyglexhxpeodtjdhtpzftuxdvfeavimtgvemslmkranljtsfkrkdmjghomjjxvedqislvevmekzndtsnlerznzidorolosqhciszmnoszngdhasuflvundybwommhetlpnlbczucochvczrjlmgyrgbnuncdtvpilamnbippkwnoyeajrijiokyizaosxddifpwiznxlmkbkpdvileqzqqkpqyjodoyifuseippuctgtwbbihthxktmarxqwmpgrjyytonpsgvldymnffwepqssjqigexovjntedjwvrtgwssjzzgepywhjorpsreoctjgwucrmyxksrurqcxhcuoliidbzhrbccjyxoplmovefrxxvvfxpvjzdmcevvfxyrvxfmkrcfxjzugurnsijdiormtmialirihyurryyohxlnucbmlmrvaihvwpyhzrrgqnxhlwysvjhplkdywutzebwaswjsoaygnwnyunqpwahkkkijhcilfgmxdvptwqzlmokicczycgkprtyyxijcoxbtvrmthlevcodetcexlpmckkcjunljlmegfrboeflgwqmpvrmgibiulmdgzqrmcvukmvatbmzxemozfafndpjpdmxdcqrglmsajttkhujniznncucfklunxtsbjkixyczhvuueofsxfhmhbpmnchdccxdmhnlhqkpneluuqotvvgcyxpmzyrdaojo", {"twjyogviurymclyenueltlcvao", "tmilweljwdoimyfhcmgxermlrp", "ikuvjgspolcyvlacmakymmiqmg", "agrbnlchqacaqjbatyigwoggnf", "mbzwsczjqsczlygcfpijkmktzv", "vljqntlitwyxqldlkjfjsbkpnm", "beqslqhrbnitsqpevcztxykyna", "usqyrpkqnitocqoskvbuaiwjep", "ibkensqiqbqiqfttdpgfrvfevs", "wszsupxnlngbmwmxgprmbvkdmt", "fpzetiwakkkjklgrlhblqnbcty", "sxdmvzemjztqkgtpsarzcalpun", "wceddabnymrioznkbaoxdtgobs", "hpecslxmgmepoxbremcckzdhuc", "ztuauzphmlvdzhfvrflurkpmfi", "ptrmbjojvgkrheibjgnbdknboq", "vgjujtmhflcpvraldomzbahjmq", "ygormevsespnpjsscgukzxjopo", "qdkelthwzuqpegqvqjakefbmku", "hsazyfchlrpnqyqaahpadryoiv", "ickvihrpjaxtflttbaztlgcgpm", "hnshwhjsyimujuthoxjuqvqqqm", "ejicbeghhjhjyfvrqltfvufksi", "hustnsgctkdgklwwubxvziwouu", "jrfzmkxaavhabiyilpkevpvvks", "reuqjqaiwsdrkzvgpnignxnemo", "wyloygnqwsmwjwitrdhobcmugc", "fvwlosczpzrhsjwqycrmvihrug", "ehmgoaknzcqylisnjdlqfshpbs", "irvadcdeedpvvfixipxujtpaju", "mcwrxuuafxwubzetmwyvtqkntv", "lcjwvpwmghwabafcgyanjnmymu", "hdloougbsipteclezqljnejvjr", "hmrdqnyphsehhsuptilhiryzea", "wunfcxdibcmajjbotrfybmtfgh", "aeeqbzrppupunkkbpkldtrkymo", "rbnvsccdypltqzdswcbhyaktmx", "jqqthvkmthhxuvotnsoksiayov", "uqtgkawjfrubrenenxpuqcdrpt", "mvmwljnsgwkrznkcydaqdcjgcf", "wcdldwnedjpkqfjxqnualruvah", "bamitnhjkhjfxaqxwfuznuzppg", "moxmbizymeupbimnbiawlydoom", "xyfjedpuxeyswfnoucxmwbvqlw", "aftfqnmsbbtqisoyvppxzoqbfc", "zepkrwcuwdbykmrachasjazbbf", "akjjysoshzcevquceokvcqdxbx", "pcgvjgzpwaopsekjaxtlzixklt", "zucziekdulsxjgkszjieefkxcr", "jrnyalywnsawdfkxtaidgvxgbm", "xpkvwlwoeujlrpmkzhorcywvwz", "qzotriqorotjqfmhpylthhocxd", "wymhpzengqwqnxklelvetixvcp", "ceuqwuxkrqvxsdmpxjrfkihccx", "iwstvfhuwubatraaedglgwfozu", "ohfaecnqtblgleelduwjhismtm", "ekaxkatozbtmhnzbmihzdhinnm", "uvxhxdsakbrkldbjwttnpcowgv", "vafhpsnernznxemygiuqfonnii", "sbtdwvhnfbkivgnwgxkxzmeahq", "gwhhbsaxsfbvliaadwhmvqbsmm", "yueftullmxjstdjndhavacztpz", "qgdfurozusbhkwkweyckjihito", "hsyfmokwswpbsqwkfatyvjjxvn", "gxtzzykijfwpbcjvujvdjelqad", "schvaamxxyfccknyairmbczova", "prpczqgmoejptlsdjvxpekdmsl", "tpzbifslbahnmqxuwmfpwjaxzd", "zmzvxdbuvxqshhkdhcgttgeklo", "bapottgrvfphjgetdzjljigrce", "qchmszvyupudykrvvmwedikrro", "sorbsssghuqanhbaeadihfenfz", "xpfxjqibcrdlryqzasbaugrplm", "ftqqeqgaecynmwyqrjuexpiyym", "qusevqybwtwhfihodctmpxvpsw", "jekrjafinseysrjyrjblxbrjkr", "kriubpkzljnlghymdmlfcqvkfl", "ynelgosfiujenvwsxozpogwmrt", "bwovyaupolyunxdizxcvfgiezh", "dtnxbsxayqdsrkmyxonxantril", "mvuziguweifrcopnhpcrtcuwtz", "emmvhnbzhnpogqeolyfdccfdxe", "drbwfvjkjkhdmjtkbizodyluie", "dnlqhhfxkssbapvllskvekmtcq", "pwhxasjncajuqydghjcplakuxl", "jlpkgahategcacybcrtftxiziq", "tzsqfvyrklitvmvxuyrcqufvvz", "llvedwbxmumqwktbyhdojrskid", "mflduhadcdsxphellypuupfbjo", "eswawcxpdwpoeyvcqxfzubipet", "elkipbgwygrkvvkfqcdvlnener", "uiubvbcqlxvmcwqwjvbhmwjmpc", "bxgzxmsnexgkxmpxabvytmhnsg", "rjgwbzxowqrzvpqgkiipaescos", "clvozocvmnjrwofvvdswhhghta", "oftwnsoxoklkbrekcxcrjdyywc", "ypyndfvcvhpetolpotztybclpy", "qeqqmxeusoraylprccsnaveqob", "ftzqpxlcepcjxdmlgvwhjqarqc", "lknkowqqniojgtgayvhvyjozeb", "puregmukaplnuklmjgzamqxpqj", "banhazwpcyzcoixvanulydhgxg", "ualsqdmhjvvefxtskpeybngcps", "ynnaealygpljdzzyjyomyrtjvc", "cjcrjidyelnhmvuclduprioyls", "ubmytsljvuahucisowrccobuds", "fyxgsdrbhufncnyjywrvphgimd", "aelyvvzpadkvasejnngfgbqdcm", "wnqblvpiwsiuwzkkxqnqctbpus", "sldozvuccovqppksxvrjtxhvit", "blwlvuctjhyflwoaajonydhawf", "yanxnkzuuoohugvwvsajsirnyy", "ihrbchjartqzistxyufhikkdpi", "vobmubnfxwqwsmrepvbakejcwq", "tmuylmcheozhyvzbmjaksqzcyo", "tgzuvgygvoddrxlgqrjdxititg", "pgwijngnatnfbihmebudwtjler", "dxrrliurddzesxfjnzpzipwbcx", "hqiledlipgjttsuolgvewpenoh", "pwmgljestkviesoennjabfeaua", "xzkwilxuuskdewkpbhprenwbpk", "kyfcxezexydiqrfigudsmalrjt", "pplpapcmatogqmnjyiekpwpvra", "phjwkhuzokavxhlwzatjlxxjdq", "gsyctusmadnyospivhminahewx", "lmdzpdgkiyxwqbymtiehjzyyzy", "kfwscewqjsfcqerzffwjxmmwrh", "urpjthfllddlezfcjknsaquvcm", "lnpbcianhthqoxllhuhuzsotej", "qcbhulhgowhkeukvxrkhnpznfv", "nrzutnhymwbvimvhkmiiadtekc", "cymovfxebyfbpctgdoxvxidfxd", "tzlxsrjtqtvjjwleksukvgucfz", "hazayipsqnzbfaktuvpocennad", "bpsnljjapwjvochmnngbrvodxr", "hogtixfirpsplzixcrorvigcfy", "vpjxvpqtqmxpebotpuumxkjelf", "gjafjpyikrvtqkrthzhcgsqrcq", "eahepicxhbjbonywaxjrxlusjn", "gowwxlxxunfwmzapdqgonvuhcr", "bmciwhbxpcbrwgmscrbjtmsffv", "wauarejjfnsooljglsygpyaxhi", "dqdyxvdkmpzresxyuoeevunsux", "rufegbpackdhaoexcgvucgqfnc", "fgyqmlgjzhuygifcagnmwowykh", "nenxavvhcxbcwwjxtvfuvlqdxl", "pkxukiwvhtkdhrmdrnfxsmxszi", "vtfcjikclyoqheslgiuhiohswd", "qnzlnwlykjeaadsmzekhxdlhso", "cswaxylbpvkvvqikxuhuytxtkq", "fqjmtbizqhmsmkdlwnykdtusmv", "dnndjrkxayykoxogxzqpoascsx", "kudirlhijchbxgkmbjcawsnevk", "ibredttvihgthxsssivbwkodni", "ndfhyjujbdtgafauhclenwwauc", "dlhltoeuettryyhahgfvsnqquc", "zfovrjecgpvuwafzrcqrnvicwl", "wvhtzzjslwrnntlsutdjgflsig", "cwzprjhpoteypywhcqxybfaufy", "kxpoqgfcxhtcutvicnwrwvbdht", "yxuqrnebycfmmbpamcyrlceszk", "qtfpzlcdylxjhnoovkprzzdtva", "ofsufpklwvxryrdrjhrtpyntdy", "jakbpbwgnyrbhmjtfqantjvgma", "elcmiulwpdhgtywpkmuwvmugfb", "bgkolrjiezcgbtisbadzsbblqy", "bysrytewgztiucrvhdrydthsgi", "sboobzfttoofahmhggcucroqdg", "goijtkucwuxknglrkghfjlvviz", "fbsjsfbdbculdfwqscatqffdlj", "fovbbaxcponygdrkeikarmrrmu", "llufcnbnmptjzqbycflcjyxnjs", "wygrygxeliymlswyhfphtxkxza", "dnnnwnplkcwkyqamxvuurrmraf", "uxuouoqimlaauxwxhqbpkqldsp", "gzoxvxqtzjntxpymongdvdmknz", "byttjhdbzaiiosssioocvzrqdj", "dtbgycbuevtufhhakgjrdbwqvq", "iuvzjneslguzdsxjwbvjzxsrmv", "sjgstthhqmxltbhokfojcvcavg", "qouxkideeitotrmtlkkqbuxspo", "gemdupryxphaoxcpobxcvbwwnr", "ipwmzvkhoiomobunnifmgorwwm", "pvclnzfftblusgyvwgnjfudyrv", "hgcqqvwvdxudnhwbarzvnpregc", "yegdjsadsklogryoibczqjquck", "qqqmlzcpcwcbilnmabkbtqpxsz", "ugaonbmhxyqczpcixqarkkfaoc", "jduniiuwlqfothrmggvkthljdf", "nowqnfexqyhkcdfbquibnskvzv", "niqqufjmhieqwuufjntescbpth", "xssruebqucbqirkzfsrwsrnard", "vykwiekcgcualeubejlglpioyr", "zqonaittpznvzaegctezvgrjak", "oeeavxiwrfdroahrdzoqfhhokg", "wkzeqstrweworaqypfrmznagew", "miwoyjugqupmfspaarganpcztq", "uqdhjmtdsmqqbakihtcdjxluht", "rerhgugynhhapxvzcsosqhmhjb", "aqtouyhjvicvlclouebjeaxsyx", "bzqsbjniotkfvmpytspzprflmj", "nvyflhjvasxfbkzhkraustdtfd", "rrpnswfbjacrbuaommysxwhyjk", "nbyjogzyrebeorlxmgshudnpjj", "wxhsapvmnfteueguylfrgiugbf", "qdnplnfptdszrgieohvxirwsko", "anbeydgmminizphatxitsigmvf", "tdfgzwzqlrmssxtwowqqkfclxc"});
	
}