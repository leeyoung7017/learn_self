#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int i,n,fd;
	int size=0;
	int j = 0;
	int length = 929;
	int review[length];
    char q,choose;
    char *word[]={"ascend","descend","descendant","absent","absent-minded","astonish","access","accessible","assess","evaluate",
	"agent","travel-agency","assign","assignment","appeal","quest","appreciate","price","precious","annual",
	"anniversary","converse","reverse","universe","accuse","accusation","curse","approve","approval","valid",
	"validate","abuse","child abuse","drug abuse","abandon","aboard","abortion","appropriate","proper","property",
	"estate","legacy","heritage","asset","adopt","adapt","adept","award","reward","awkward",
	"coward","embarrass","amuse","entertain","aggressive","ambition","aggressor","progress","congress","digress",
	"digress from the topic","apply","application","applicant","accurate","accuracy","curious","urge","emergency","urgent",
	"permanent","injure","rescue","secure","subtle","rely","depend","rest on","suspend","pendant",
	"pending","reliable","trustworthy","real","realize","reality","liable","resemble","assemble","status",
	"stable","perceive","receive","conceive","deceive","particle","article","partial","impartial","apartment",
	"department","fundmental","total","vital","digital","produce","product","productive","productivity","approximate",
	"intimate","inmate","adhere","attach","accelerate","decelerate","ensure","assure","enable","old flame",
	"flame","bare","barren","barbarian","savage","barbarious","bargain","barrier","obstacle","blunt",
	"sharp","consider","considerate","considerable","casual","contempt","tempt","lure","temptation","circumstance",
	"accommodate","annoy","annoying","compile","pile","a pile of","modest","humble","arrogant","earnest",
	"contact","intact","catalog","count","counter","account","accountant","counter","uncountable","counterpart",
	"encounter","discount","under no circumstances","confine","infinite","refine","define","definite","democratic","combination",
	"password","tend","tendency","trend","contradict","contrary","contrast","on the contrary = by contrast","extend","intend",
	"attend","attendance","pretend","disguise","expose","compose","posture","depose","dispose","disposable",
	"deposit","propose","impose","depart","impart","crime","commit crime","commit suicide","discriminate","criminal",
	"vision","previse","revise","devise","view","viewpoint","opinion","arguement","conspicuous","visualize",
	"supervise","supervisor","preview","review","press","media","immediate","depress","desire","despair",
	"desparate","dim","dilemma","distract","attract","contract","substract","extract","abstract","tractor",
	"expire","perspire","conspire","inspire","inspiration","aspire","exhaust","equal","equivalent","electronic",
	"atom","value","explore","exploit","explode","explosion","population explosion","establish","strain","nasty",
	"stage","strip","era","light","enlighten","blight","delight","alight","slight","esteem",
	"esteemed","prestige","expand","strive","struggle","extraordinary","outstanding","remarkable","expect","spy",
	"unexpectedly","subject","object","inject","eject","reject","project","sufficient","defficient","efficient",
	"profficient","artificial","superficial","defect","detest","effect","affect","effective","affection","potential",
	"fatigued","weary","vigorous","energetic","energy","dynamic","internal","external","diverse","versetile",
	"differ","suffer","refer","reference","prefer","confer","conference","fertile","fertilizer","attribute",
	"contribute","distribute","acient","authority","awe","awful","agenda","schedule","arbitrary","minister",
	"administer","advocate","anticipate","participate","admit","permit","admission","permission","lisence","reformation",
	"commit","transmit","transfer","transport","transplant","transparent","apparent","evident","evidence","obvious",
	"associate","association","national basketball association","arouse","rise","raise","arise","absurd","auction","adore",
	"avail","available","affirm","assert","desert","certain","ascertain","articulate","ally","alliance",
	"aspect","suspect","inspect","prospect","prospective","circumspect","audience","respect","spectator","spectacular",
	"marvelous","fabulous","magnificent","speculate","perspective","outlook","survey","convey","conclude","include",
	"exclude","preclude","concludion","sample","ample","relieve","grave","grieve","grateful","alleviate",
	"transform","Transformers","translate","passport","transmission","transactor","opaque","commitment","mission","innocent",
	"naive","guilty","subscribe","describe","inscribe","ascribe","script","menuscript","prescript","formal",
	"informal","normal","resort","Disnyland resort","incline","decline","proceed","precede","procession","process",
	"procedure","processor","motion","motive","motivate","motivation","emotion","emotional","promote","promotion",
	"remote","irrigate","irritable","wing","swing","sway","vibrate","strap","trap","swell",
	"sweep","swear","scream","stake","virtue","virtual","violent","virose","violate","resign",
	"navigate","navy","replace","displace","substitute","institute","constitute","prostitute","hooker","superstition",
	"superstitious","dismiss","missile","mission","missionary","dismissal","emit","omit","submit","permit",
	"admit","permission","attain","obtain","retain","sustain","maintain","pertain","detain","arrest",
	"approach","reproach","require","acquire","inquire","license","resist","persist","consist","assist",
	"teaching assistant","insure","insurance","insurance company","guard","bodyguard","guarantee","economy","economic","economics",
	"economist","thrift","decorate","ornament","refresh","renew","distinguish","distinct","distinction","swallow",
	"claim","proclaim","reclaim","declaim","acclaim","exclaim","confess","profession","professor","professional",
	"immune","immune system","intellectual","intelligent","intelligence","lecture","select","collect","elect","dialect",
	"yield","facility","manufacture","industry","commerce","infect","infectious","contagious","timid","intimidate",
	"multiply","multimedia","precedent","cease","ceaseless","reproduce","prohibit","ban","forbid","the Forbidden City",
	"rival","opponent","versus","commercial","remark","remarkably","extraordinarily","more than","exceed","exceeding",
	"innovation","evolution","revolution","uniform","display+sth","show+","sth+manifast","court","justice","justices",
	"legal","verdict","dictionary","possess","possession","origin","invest","investigation","initiate","passion",
	"dispassioned","indifferent","have passion for","spoil","fatal","proof","primary school","primary","elementary school","element",
	"prime","adolescence","adolescent","astro","astronaut","principal","principle","discipline","optimistic","pessimistic",
	"negative","optimism","pessimism","neglect","ignore","cheer","cheerful","optimist","pessimist","reluctant",
	"tentative","be tentative to do = try to do = attempt to do","attempt","temple","tempo","temporary","contemporary","in our contemporary = nowadays","Love is temporary,but friendship lasts forever","avenue",
	"revenue","regular","regulate","regulation","relief","indulge(in)","addict","dictate","reform","edict",
	"abdictate","dedicate","indicate","contradictory","homosexual","homogeneous","homocentric","tutor","uncover","genius",
	"evolve","revolve","involve","serve","reserve","preserve","conserve","observe","deserve","suppress",
	"respective","success","succession","successive","crown","royal","loyal","abundant","abound","resource",
	"source","redundant","perpetual","eternal","intrinsic","extrinsic","dump","surplus","quality","quantity",
	"blast","demonstrate","demon","exceedingly","abdicate","be olidged to do","be olidged to sb","notion","common","the elders","climate","surrounding","forecast","weather forecast","castigate","cast","tolerate","tolerant","tolerate one's bad temper","lose one's temper",
	"temperature","govern","government","iron","irony","ironic","sarcastic","fruit fly experiment","mosquito","isolate",
	"resent","contaminate","plunge","entitle","polish","sympathy","mercy","coincide","spot","pollute",
	"nurtrition","nutritious","nurture","nurtrient","purchase","chase","routine","chest","abdomen","cater",
	"hostile","elastic","ashamed","shame","ash","ponderous","provision","furnish","grant","grand",
	"splendid","note","notable","well-noted","well-known","routine","forum","spectrum","shortcoming","weakness",
	"flaw","frontier","conscious","conscience","instinct","span","engine","tire","retire","tuition",
	"occupy","occupation","career","elite","elitist","oppress","notice","noticable","society","fare",
	"chief executive officer(CEO)","president","preside","convention","wonder","wander","fantasy","fantastic","illusion","unify",
	"union","united","unity","interact","interaction","peer","interfere","intervene","offend","defend",
	"react","reaction","reactor","manipulate","offend","defend","hospitality","hospitable","substance","substantial",
	"oblige","be obliged to do","be obliged to sb","carry out","execute","obscure","bloom","loom","boom","gloom",
	"oral","moral","mortal","immortal","pledge","undertake","overtake","catch up with","morality","noble",
	"illuminate","frame","insight","ingredient","fancy","generate","overcome","protest","contest","contestant",
	"foresee","foresight","subodinary","generation","pace","patient","mask","imitate","simulate","stimulate",
	"hollow","shallow","shadow","dense","condense","retort","inflation","flat","humiliate","humanity",
	"humid","moist","obey","obedient","negotiate","enclose","enclosure","disclose","lean","gap",
	"vacant","blank","merge","emerge","submerge","swarm","stride","submarine","faith","faithful",
	"interpret","spontaneous","raw","crude","sponsor","certificate","doctor","postgraduate","bachelor","certify",
	"diploma","genuine","authentic","grace","graceful","disgrace","disgraceful","giant","gigantic","immense",
	"summit","glitter","glare","gaze","glimpse","peep","glance","scorn","dispute","vivid",
	"survive","monopoly","monopolize","venture","adventure","corn","flash","glow","flasher","flare",
	"a flash of ligntning","sparkle","ignite","habitat","inhabit","linger","lag","hesitate","peak","interrupt",
	"corrupt","gamble","bribe","bride","groom","glove","squeeze","steep","steep mountain","fragile",
	"fragment","vulnerable","feeble","spray","sue","extinct","extinguish","interior","exterior","derive",
	"impulse","invent","generous","reveal","imply","comply","immigrant","constitution","other than"};
 
	struct stat st;
	
	while(1)
	{
		printf("clean?  ");
		scanf("%c",&choose);
		if(choose == 'Y'||choose == 'y')
		{
			fd = open("./review.txt",O_RDWR|O_TRUNC|O_CREAT,0666);
			break;
		}	
		if(choose == 'N'||choose == 'n')
		{
			fd = open("./review.txt",O_RDWR|O_APPEND|O_CREAT,0666);
			fstat(fd,&st);
			size = st.st_size;
			read(fd,review,size);
			break;
		}		
	}
	
	
	for(j=size/4;j<length;j++)
    {
		srand(time(NULL));
        lop: i=rand()%length;
		for(n=0;n<sizeof(review)/sizeof(int);n++)
		{
			if(i == review[n])
				goto lop;		
		}
		review[j] = i;
		write(fd,review+j,sizeof(int));
		printf("%d: %s",j+1,word[i]);
        scanf("%c",&q);
        if(q == 'q')
		{
			break;
		}
            
    }
	close(fd);
    return 0;
}