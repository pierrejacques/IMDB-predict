#include<stdio.h>
#include<math.h>
#include<stdlib.h>

FILE *fileData;
FILE *fileOutput;
char fN[255];
double x[78];
//parameters
int 
    x_toKeep2[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,23,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,55,56,57,58,59,60,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77};
double
    x_toMinus[]={1.18,5,1,0,7,0,0,1100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1920},
    x_toTimes[]={0.134952766531714,1.18360073833014e-06,0.000395335046451868,8.69565217391304e-05,0.00396825396825397,0.0465116279069767,5.73065902578797e-06,1.63726427907091e-10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0.142857142857143,0.00246305418719212,3.125e-06,1.45985401459854e-05,8.69565217391304e-05,3.04539156121998e-06,0.0208333333333333},
    x_toPlus=-1,
    b1[]={-1.4289762041191665,-0.80865002239364747,-0.85978695608276723,-0.30800798494053927,-0.20437179713368941,-0.76684732864587435,-1.0557452005008299,1.1194092466973948,1.7100219565915569},
    B2[]={0.1690182690243317,0.15948141668950899,-0.13610640057378331,0.28858734242418738,-0.0841311040481105,-0.322419356815493,-1.0179902511773191,0.24398915854760916,0.038887332326244993},
    b2= -0.23056279513233499,
    y_toMinus=1.7,
    y_toTimes=0.256410256410256,
    y_toPlus=-1,
    x_toMinus2[]={1.18,5,1,0,34,0,0,1100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1920},
    x_toTimes2[]={0.134952766531714,1.18360073833014e-06,0.000395335046451868,8.69565217391304e-05,0.00666666666666667,0.0465116279069767,5.73065902578797e-06,1.63726427907091e-10,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0.181818181818182,0.00246305418719212,3.125e-06,1.45985401459854e-05,8.69565217391304e-05,3.04539156121998e-06,0.0208333333333333},
    x_toPlus2=-1,
    b12[]={-14187.771413405639,13.430490774309032,364.31824201051143,1575.160883823075},
    B22[]={0.021484033164223714,0.4799192927071767,-0.0069039802193013762,0.0023157916270890909},
    b22=-0.54649785771320702,
    y_toMinus2=162,
    y_toTimes2=2.6298291248145e-09,
    y_toPlus2=-1,
    B12[4][70]={{-324.1699524473272,161.03536066521133,-616.17609837451892,-2768.7074779682162,237.38822823928027,285.89049864434514,455.03436622467854,1.088623686707527,146.28304454344794,522.68530760757915,-7660.3069706609758,-111.8387595129021,14206.535881247037,14193.575923300676,-158.81708112219445,-967.92173790132892,437.31651199276899,264.57324117576388,1191.649625320754,-436.58076584410344,14174.167990840106,774.21568386510114,652.36334529731778,-159.62597313833854,-79.875721766489164,-227.96487976737279,1377.4089121554155,12.101625043076721,-322.87892343652783,1301.3905287290804,-733.91922220750814,-172.93915396639568,-57.463254134783234,-43.768665412913045,44.589185180145769,-441.14602190671138,-122.54398331703165,-518.30512778351772,-899.2867777061748,-866.64846528166674,1056.9134120064487,-346.35967552800031,-1447.956698010729,-130.1516077258631,1561.7685324043439,-276.92758904207744,-558.39204346693521,14206.579144398956,176.61951086726035,-372.95284119994517,-320.65382068834037,-225.45474339585215,-302.19647927383778,-67075.619590027651,845.00137431606299,-836.26924003256818,776.45738094831631,-5031.2512968627043,4975.5540084168306,-932.78027470833774,-185.96442172419887,-252.16876057694043,1608.068398920602,138.88380957216324,1481.3518270163217,386.1710628383812,129.10310440632074,-31.794282233738702,-599.48083467710444,890.73791040271431},{0.0078330996393435777,1.2157911199798566,0.32058032391278135,-0.072766286130289612,0.25441550442487953,-0.17047610745053018,0.096434608282017428,19.931289763356897,0.1645574083735605,20.151408360299609,1.4284480693619963,1.4886281523776332,-24.281683149940736,-45.16149876517067,1.1033398186416776,1.146352383635028,1.5749303272921573,1.6057823145561374,0.84147874165718217,1.4430665763441952,-247.64460310708373,1.2147704388006881,-28.591873821160132,0.054443533272454193,0.08665778028738233,0.051392701757459948,-0.014948983443789936,0.047849800607033782,0.020771531845535998,0.021471214462998517,0.025667206683516196,-0.067238409599902182,0.050519567142913564,0.025552427398221274,0.037774603265939247,0.053536001106989251,-0.030003515617361757,0.027871636906770365,0.0073281500064070748,0.093367787389483023,-0.015986491232807386,0.07924405381755642,-0.043750529850728234,-0.044279274724690509,-0.058667790315676205,0.12139358665367483,-0.0010859750740940287,-24.661787478401607,-0.014692892453879799,-0.00081321735366225798,0.022809960037216748,0.0013993793014477692,-0.040508291696550708,407.08371462670675,0.029016795442830912,-0.070326488691921013,-27.20130998165158,0.076564980673173355,0.060206242308767817,0.031368068214479385,-0.080010281553796525,-0.031390856365430972,0.091756319775305323,0.1020556705256757,0.41295713569378628,-23.398244567604575,-4.661908108238741,-1.0805288094771406,23.325875177280029,-0.67095307273158811},{-3083.8544299019386,7213.5058928453291,1278.9048439178689,-1406.2498428593117,3850.6142627119593,-1328.0679094260518,-10622.199017383733,13010.46131959432,801.90193388802129,-498.74109031426667,-1024.2719891967638,1935.2654513234211,-364.92688094475466,-364.94655891921218,-2949.540552958339,-84.122274562733878,-920.85533186273142,-1360.2329057160882,-364.53825227289855,3491.6689309097214,-364.74348276639961,633.14221072071587,607.5199797094798,-105.28891237658888,1244.5672433332231,-133.14651560500516,-1046.3064542129866,819.15096043071037,-1046.1991190674678,939.46113426556224,2028.4192474206773,-900.33962452865831,600.07704830729517,159.11207833439727,318.33755493606918,294.14382399150207,431.57329555824083,-666.69039975336932,1182.7574613569179,-705.49241232934742,256.82122514878102,-491.24221558195222,-330.82169917395868,615.02888682922423,-306.06533400259195,1331.7656988259571,2787.0205209934984,-364.53630380808681,470.23141504971773,2359.5524206082773,244.24909296777821,-329.55226316818943,1187.4151866808936,-364.58064459368512,-34.089660810487544,-2871.8077066476662,-364.82993593245408,-46.660202950361224,-1954.3506021555081,732.57705277412811,-748.74528027444012,-708.49059500249837,782.56660284091242,1066.7104363849003,3272.9671604027576,-26986.220558273806,-1182.0232675768998,1412.3229540524619,31170.502359279075,-142.39808200577886},{2372.9476443267727,20274.003559849505,-21279.791589781002,-2068.4046680294796,-11043.52480488197,-76.051143896163353,4924.027553002843,10279.862354057217,-3553.8586972663302,415.21262097203174,-1642.6953392789844,1017.3132587810111,-1573.5352956761012,-1578.6533235255572,-2024.3587408622152,-308.0640140084497,-1204.9552982561706,-3841.2428020724742,-1573.479456830458,-2090.2468947036941,-1573.5985511610238,-2097.5432239454931,-7159.305756217108,1389.6207881115149,-4342.4210758532099,-1682.6525325157875,-610.18535908092633,1635.2568320331027,816.86004073420713,-887.29235599949504,2509.0726395519723,2135.681117958783,2834.49922708333,-3151.7724476495096,-1985.7717569984218,-801.98703517685612,-2000.2919678724052,-177.53789818637503,2653.0233147172544,-3567.3934160967033,712.18030039019231,101.81122195866291,-2339.0429009653972,-3394.5627855967118,1612.7239712688011,-1664.4453351521365,377.87892901019524,-1573.4786262502264,946.00450085141347,987.01886409378164,-708.83926700147742,-530.06879331814002,952.37389076517547,-1574.7371060276471,1070.8585324925502,3212.1146580775949,-1573.4872811677239,-1558.8499559527443,1852.452786513076,2478.3408329799818,-3278.3474145571877,3634.0695770823768,-2454.9825563823701,-1385.0462688385358,-4029.0106227679789,5848.0134782942223,7669.6455913050122,-7089.4470450334957,24438.938618830714,4940.9091330455494}},
    B1[9][77]={{0.1024374111436523,0.042311915616419823,0.13925644782505542,0.18135701449281308,0.12556584557720885,0.23984775416286958,0.22430475084546803,-0.26256006486750116,-0.011956670442750828,-0.26679433486583387,0.030755768295604238,-0.20828854368992417,0.060584536381947142,0.051586549050386385,-0.052195112820694098,-0.011283694012284497,0.087919969630251532,0.46654019989229356,-0.23982845295004782,0.34881877203833639,-0.05572431278411772,-0.12316587149623887,0.090183197151946004,-0.12391780628713482,-0.078469782651822001,0.12691169122788365,-0.10759748482000302,0.1011904835450638,-0.19553099859535136,0.15653340569345864,0.096318308079993101,-0.11550595023416718,0.19555904509619348,-0.051667352861360434,-0.1450805464113222,-0.035459590199292089,-0.16130295171909506,-0.29355161638803717,0.18508388821438609,0.30630643705581484,-0.20575586457512712,-0.16189721120000419,0.20042947740020772,0.37663807831911206,0.17298540727368383,0.040150441581719626,0.17017171534535314,-0.046940908476024862,-0.22029747185964127,0.11503081163616838,0.089498031350116011,-0.20309785733255425,-0.10136378505175013,-0.28008047615117221,-0.30581922329171307,-0.28189163117239768,-0.032930000998982314,0.21987839289963929,0.21287924323293533,0.14916848291795104,-0.10001674557559342,-0.12550516176750495,-0.38302629033945734,0.078180104844080778,-0.019979498922752841,-0.34321800769963234,0.12909537289521225,0.44459909355652671,0.056191614921380306,-0.1275959997055619,0.29952701899447981,-0.060272984972148405,-0.14079946040642383,-0.12751265307922902,-0.15280603575949453,0.28730608111374611,-0.18744195287591156},{0.13354864439433342,0.39651967249656694,-0.3718267913747984,-0.22101455208457743,-0.10988718010284139,0.38252194103947218,-0.37179037099879308,-0.057340194642860866,-0.03474958801077116,-0.078472091685111336,-0.14714397983019831,-0.12682258070936997,-0.31028292670202667,0.061682006006145484,-0.12702918081446127,-0.33131422155864132,-0.18323815251341552,0.0081807694818431427,0.2463743494114215,0.079502850742589407,-0.22024411180918682,0.26431994692403471,0.72589058487198943,-0.28243884736917141,0.37627303862148359,-0.10720862770270273,0.13517078061183252,0.3734605656975622,0.059943457658015051,-0.058902807763576308,0.13700073144745431,-0.10664582965929595,-0.17730358664948515,0.022239277215581006,0.15626511490104306,-0.10070457446672848,-0.20683456256524357,0.0055432581089951971,-0.10637119199585396,-0.16714649742750445,-0.2588442166064317,0.24089534740244367,0.32112558304351657,-0.2266901915494321,0.16245814339379652,-0.15621260921622801,-0.064855360034045254,0.04070093378293585,-0.23655976597511966,-0.15297246639245637,0.27434486938707953,-0.094443111587200035,0.21960474181056552,-0.065624079305331595,0.0030359940650069132,-0.033870175037090305,-0.10250952340900521,0.22624039397374118,-0.24116394402503846,0.1718744191870207,-0.1912919042516289,-0.06731696607487403,-0.32369687983742629,-0.033820429518720073,-0.27569516899121882,-0.094861293748204789,-0.06846858215312504,-0.1608203311641031,0.10025395088125941,-0.096588730490093255,0.059737003038215303,0.11354277589640993,0.3747288959105286,-0.059347613167218996,0.37730457626337083,0.35852250006355396,-0.16374373567894585},{-0.046642313018585874,-0.33291147109772157,-0.65846900090828697,-0.1729865347267325,-0.048253676216386848,0.33094782160739872,-0.45445266558076708,0.040241320955573756,0.0078335270406600516,-0.13386962641398684,0.11568464483012462,0.11203569501777093,0.29200513819292029,-0.17644518987060404,0.36022753536015761,-0.23905205186920028,-0.29968504722169809,0.16997495495452744,0.26156281409332294,-0.063725635248563881,-0.35620718605334523,-0.30241813611502955,0.2339287403401247,0.34132784562160068,0.092474548455584685,-0.40355775401497079,0.13138670270296193,-0.33458224347242632,-0.028566817890683043,-0.20924473698064272,0.11743756004504199,-0.16115196990908384,-0.26060974900988332,0.0016759404109597947,0.39904668286929074,0.10083630438691535,0.31000618082797893,-0.04142424822738755,0.083449779400488894,0.2003221017184672,-0.02581168771732615,0.19615279352243753,0.11764958949146943,0.32823116371713046,-0.0012241414062793624,0.084210863465310773,-0.048143912857354823,-0.061356933190037891,-0.14876026348400925,-0.075305088858594313,0.047249536568766029,-0.24673612619252783,0.39604325686124958,0.21544010386572132,-0.15182855606169679,-0.17965282898878945,0.0083691632694794099,-0.1147858168297608,0.057863619878583461,-0.072680069068649863,-0.16679602341476474,0.061498731722543748,-0.024416017883133342,-0.27247032762673401,-0.41411701566169756,0.038106788105601176,-0.027361833770654757,-0.11139499489396539,0.26761606446280684,0.48881763869786854,-0.039659040509936822,-0.0059181403091034535,-0.2203253629015981,-0.038054751331035724,0.0011404928450295705,-0.03782953951726576,0.28151946861640992},{0.19479741853240112,0.062131063882841106,0.026713336587419097,0.41966449328538702,0.18233597372154886,-0.19079180897531978,-0.26637885719487331,-0.2601002597952693,0.29669933431129958,-0.12280916294260039,-0.20822659181937683,0.096492924155111515,-0.11549604763304594,0.21704287577352796,-0.10035000003228567,0.14953293178828789,-0.16536524715460621,-0.014722292820097148,0.065651671129832709,0.029166737306839989,-0.25358021945967635,0.10373584755746841,-0.22060555945407176,0.28407199325204907,0.20727309699155,0.29204650460772735,-0.001276292342479576,0.048672557017861898,-0.42834169532240868,0.097756402990096913,0.30001289533877618,0.12679932659136489,-0.10810335967753179,0.047466280164291025,0.20145776266968485,0.42769609790049934,0.092613841276859302,-0.015366816199129388,-0.25450002122356408,0.031118701114189979,-0.42193383055175043,0.28398155960703847,0.038415010522249167,0.18071266417769577,0.37970022942389026,-0.056247118720138531,-0.041418526581983937,0.38771344577823397,0.18393302738895118,-0.28052109062156982,0.20402266993403262,0.44660277320010455,-0.20894789930568577,-0.26157463996488961,0.012736999308183587,0.24493815703052016,0.038058106229038581,0.15472189171758899,0.11467936821897345,-0.15412088064871554,-0.046234712545679638,0.1921396395101316,0.3091411723258975,0.058921770580299911,-0.13006083434254548,-0.086637929546848125,-0.160320300349927,-0.040640290022377998,0.28487205214710476,0.32174586609635392,0.064982650699937292,-0.0036697600277403597,0.21241338774206356,0.0015122181400279589,0.17304087746866861,0.022133431391498225,0.11298714288685377},{0.19994048706934353,-0.73102012242182679,0.26287009285791529,-0.050657850645176722,-0.34406978029994034,-0.16849402697682619,0.79072244618081466,0.10874483184667101,0.22916167130945447,0.1689492467463441,-0.050093214260989075,0.49765931590574208,-0.34962437235945526,-0.26518802698268729,-0.4799308835062886,0.23630087365009525,-0.40756969482831651,0.11677561991428033,0.11373178536289553,-0.034233816470567724,0.26675992352396583,0.49293017671048495,0.054808681038081897,-0.59638295601068259,-0.094734652223468468,-0.20606514524206546,0.20370734465526244,0.3359092190991062,0.19522272671761343,0.16923341421534563,0.095835613647214796,0.012406674765615161,-0.15397807026393084,-0.29384747914917247,-0.015288494293620856,-0.044443458063103035,-0.32420436258892732,-0.31500023542854838,-0.13875759334381088,-0.061759256443603409,-0.19844617796840108,0.058210942236736091,-0.17339730540710419,-0.21296304904368429,0.094909224009624982,0.31060110451050421,-0.22817630498254313,0.031890130723007296,-0.12018249186761834,0.10540748639090028,0.03200982576678163,0.27972448025605146,-0.022897499893690026,0.29912058775126249,-0.1244999975710453,-0.17867630566234413,0.04356896318346646,-0.11980176459588324,0.042910333522190175,0.045223922840293064,0.026099830202837314,-0.16889383869938124,-0.053684870953577102,-0.0017257365985636729,-0.14827699257289506,-0.46584101307384884,-0.06008569237963704,0.1636568263918442,0.050587622886787489,-0.018297939786169615,-0.18615529334461672,-0.20363578075758351,-0.41294022235688066,-0.085797043546480614,-0.13030362181656241,-0.075152543223402646,-0.076458083301032501},{-0.069974728589443591,-1.7465392955478831,0.12771305450486911,-0.051145330158030744,-0.080196877440547182,0.091391962688239584,-0.35915302443694413,0.19309603156490321,-0.13517524934412017,0.046975973037069935,0.29642758872258984,0.32117379708851862,0.25042910379568972,0.054638325656087353,0.16743253825537818,0.10353085894652224,0.18107301460672076,0.20049958600798248,-0.091876586346801958,0.20390633651920642,-0.035000630966511327,-0.37816292233048965,-0.16982840950025074,-0.37001588199143076,0.17821397217461105,0.23561555077803356,-0.16042102281716653,0.35554486820817799,-0.49548295613442922,0.17939176431468262,-0.10384821237587868,0.055128105566101079,0.0026546150822463789,-0.22199416650030407,0.14490350358863066,0.026750377060361923,-0.088546969753302007,-0.030268612391762012,-0.082373682408174165,0.084321115635455468,-0.24459051195784362,-0.16353272346495895,0.19302090068867678,0.10056867598987926,0.090764910894229819,-0.02801478885034106,0.054079829343129111,0.048672350117521523,-0.39933467522749255,-0.22672469672799461,-0.074689924896298762,0.085363701413692483,-0.023461729150101401,0.58932124456790269,-0.062440625119772566,0.31794225606108129,-0.073514835826111236,0.039731963885103624,-0.074883889432499184,-0.032911687369898392,0.15799847420630583,0.12278112973500693,-0.093640899235095137,-0.077858081918492777,-0.024939839415599949,0.078246327340709243,0.033204083584547961,0.084062102443271267,-0.050393462650803078,-0.059513393146655519,0.33324125271791111,-0.16591300657452404,0.094178806703960033,-0.11282238652278846,0.40427794463491723,0.49295746632221449,0.85874393145085182},{0.069784589149528925,-1.5426711990581978,0.92084595983893547,-0.0053494791226513169,-0.38066675647396864,0.080084153143752446,-0.37962255128107486,0.22129206115498909,0.2364522159531337,0.10565281612744382,0.010976524385951151,-0.0014428352026588862,0.12392800008593768,0.27522368559068233,0.31091402703677828,0.14627267433572591,0.26132436461690378,0.1619235086860987,0.30328029491721697,0.10014112366405621,-0.24663680147906994,0.13798963936382069,-0.20692053764834972,-0.054772837959071202,-0.0304950475311919,0.13273208610541851,0.19817338483968602,0.32290167339075987,0.17283230233144586,-0.20318479356754168,0.036169419682944834,0.038663191734451291,0.062963732837063288,0.15352495354595008,-0.092086333033230577,0.02606410633644176,0.068316736842561232,0.051103924885994106,-0.00053121475565254608,-0.060647542348100852,0.075573114246017772,0.17952390557205394,0.074994156602683992,-0.10341526788888024,-0.12584437215236444,-0.18236878936536227,0.0365316035540518,-0.069625944532853479,-0.24927385237852534,-0.078844640770100033,0.057341793528094355,-0.0044351206348885279,0.047908195979942343,0.22179248207806057,-0.018551779610813078,-0.067502448064644893,0.091485494391922342,0.080427073962762552,0.043182254501893849,0.29003120495802409,0.073468223568128876,-0.085045849572096599,0.066338883670081797,0.079508241485606979,0.03586574578919946,0.042664800045535169,0.013967801460335137,-0.025038802834026964,-0.032637079166743937,-0.020815084392354254,-0.12260568334230697,-0.83038351527283061,-0.42558274867757068,0.068421623531706277,0.11730916518574946,0.046950557036429003,0.34756622230871803},{0.017449842515730268,-0.23416617811830051,-0.086836030888955321,-0.099869407406394869,-0.02234193005021529,-0.10989520899410106,-0.30135207003671372,0.21022715996222965,0.013993505862224365,0.18178601176814566,0.0093380203511342665,-0.2675213188812825,-0.28627882793632892,-0.16852218366501392,0.087987133963487799,0.094192121915270835,0.2257828117660842,0.026787906983334438,-0.19274765334181362,-0.2155050816731868,0.014569880354655538,-0.28913908548615425,0.14342460383822436,0.21230585774727659,-0.15497299957429359,0.10905247208186461,0.10707887331231081,-0.20396823038281892,0.14634327386787802,-0.054898003892932007,0.23116025201148677,-0.26521425345134064,0.22826061538420545,0.06456826743256619,-0.19462993376788063,0.22167777755399912,-0.27019799893342733,0.15695924663223701,0.22541553975613463,0.13344900696935125,0.039005860917836484,-0.17619470677127255,-0.052003849275271789,0.08350030099495695,-0.22445540165239899,-0.00094577511183407481,-0.27622087915654281,-0.024043861806199739,-0.29215325842200085,-0.3210048396599276,-0.079848849774272715,0.1956189229833851,-0.29438561868235824,-0.18007201163977785,-0.19534938448749548,-0.14629735893510504,-0.19396187519638192,0.11764809362541002,-0.084240279264997775,-0.0061337553917206718,-0.25032038827504516,-0.20531378780852474,0.052165760363633837,0.15092303008427535,-0.20096097391538753,0.28525276258052779,-0.11588128290731038,-0.048024687954372501,-0.073249016670934933,-0.15044409854114069,-0.1173225676625432,-0.15653864516585383,0.029764763011512242,-0.28396913911562044,-0.23381884174270609,0.13567769366554319,-0.0015826920156082893},{0.38435229466526732,0.95896287600583829,-0.52958796928064156,-0.0029497751768090691,0.85767920050439928,-0.49241011832323384,-0.094121088038651948,-0.20628968083911883,-0.13483572526515011,-0.12893742120591078,-0.15173941167724231,0.27732858879231703,0.41488999224232692,-0.60288912427101149,-0.13236935833066293,0.21103619558599893,0.3831734562272559,0.1623362158682311,-0.19532011873465058,0.1627767523350426,0.61944589212865464,0.11360208165461566,0.34969616513509921,0.29160646038267546,-0.31379601465260704,0.16890359421806442,-0.085772364214091262,0.22200153027933867,-0.14002279542503468,-0.12693396397029433,-0.24733037777127537,0.12741886826355192,0.25941390622938248,-0.0814956614844803,0.19845089342568481,-0.27207349275371689,0.0058746754791556451,-0.39611203675966294,-0.18656951910525071,0.2666286148927457,0.1400840066229932,0.21975809616632772,0.076153402857278368,-0.046638350154557959,0.055098985678223474,-0.021866676492559137,0.13512605024512309,0.010932528745484026,0.27532175386600399,-0.36820541221916925,-0.10039834158727549,-0.041458000218102031,-0.23504745672849361,-0.38268485178301098,0.044745615778871969,0.042214941289990607,0.017685748333960045,0.067601156274841659,0.042229343734086072,-0.11461563484986084,-0.27837382400235389,-0.022455520190565501,-0.033888823112130526,0.14185234921765172,0.026728013914556845,0.38735040317220359,0.27619930442840324,-0.34384722617762675,0.061174685562908004,0.073395839462904178,0.22727945514412745,0.4389153359466188,0.069657673501778719,-0.1991658942461233,-0.28809022587460387,0.1180198582148563,-0.50381838279234159}};

char wordBuff[255];

void initX(){
    int i;
    for (i=0;i<77;i++){
        x[i] = 0;
    }
    x[0]=2.35;
    x[4]=90;
    x[7]=20000000;
    x[74] = 1000;
    x[76] = 2009;
}

int isLetter(char ch){
      int code;
      code = (int)ch;
      if ((code>=65 && code<=90) || (code>=97 && code<=122) || (code>=48 && code<=57)){
            return 1;
      }
      else{
            return 0;
      }
}

int countWord(char *str){
      int i,n,h=0,t=0,inBlank=0,count=0,bar=0;
      n=strlen(str);
      if (!isLetter(str[0])) {h=1;}
      if (!isLetter(str[n-1])) {t=1;}
      for (i=0;i<strlen(str);i++){
             if (!inBlank && !isLetter(str[i])){
                     inBlank = 1;
                     count ++;
                    if (str[i]=='-'){
                        bar ++;
                    }
             }
             if (isLetter(str[i])){inBlank=0;}
      }
      return count+1-t-h-bar;
}

void readWord(){
    char ch,str[2];
    int code;
    ch = fgetc(fileData);
    code = (int) ch;
    memset(wordBuff, 0, sizeof(wordBuff));
    while(code!=9 && ch!='\n' && ch!=EOF){
        str[0] = ch;
        str[1] = '\0';
        strcat(wordBuff,str);
        ch = fgetc(fileData);
        code = (int) ch;
    }
}

void readDouble(int idx){
    readWord();
    if (strlen(wordBuff)>0){
        x[idx] = atof(wordBuff);
    }
}

void fileReadln(){
    int i;
    //initialize
    initX();
    //f=film d=direct a=actor N=name F=fame 
    char nation[25],lang[25],type[255],
    key[255],format[255],rank[25];
    //read raw data
    readWord(); strcpy(fN,wordBuff);
    readDouble(76);
    readWord();readWord();strcpy(nation,wordBuff);
    readWord();strcpy(lang,wordBuff);
    readDouble(7);
    readWord();strcpy(type,wordBuff);
    readWord();strcpy(key,wordBuff);
    readDouble(0);
    readDouble(5);
    readDouble(3);
    readDouble(4);
    readWord();strcpy(format,wordBuff);
    readWord();strcpy(rank,wordBuff);
    readWord();readDouble(72);
    readWord();readDouble(73);
    readWord();readDouble(74);
    readDouble(75);
    readDouble(71);
    readDouble(2);
    readDouble(1);
    fscanf(fileData,"%lf\n",&x[6]);
    //pre-process data
    //fN
    for (i=strlen(fN)-1;i>0;i--){
        if (fN[i]!=' '){
            break;
        }
    }
    if (fN[i]=='?'){
        fN[i] = '\0';
    }
    x[70]=countWord(fN);
    //nation
    if (strcmp("UK",nation) == 0) {x[68]=1;}
    if (strcmp("USA",nation) == 0) {x[69]=1;}
    //lang
    if (strcmp("English",lang) == 0) {x[9]=1;}
    //type
    if (strstr(type,"Action")!=NULL) {x[42]=1;}
    if (strstr(type,"Adventure")!=NULL) {x[43]=1;}
    if (strstr(type,"Animation")!=NULL) {x[44]=1;}
    if (strstr(type,"Biography")!=NULL) {x[45]=1;}
    if (strstr(type,"Comedy")!=NULL) {x[46]=1;}
    if (strstr(type,"Crime")!=NULL) {x[47]=1;}
    if (strstr(type,"Documentary")!=NULL) {x[48]=1;}
    if (strstr(type,"Drama")!=NULL) {x[49]=1;}
    if (strstr(type,"Family")!=NULL) {x[50]=1;}
    if (strstr(type,"Fantasy")!=NULL) {x[51]=1;}
    if (strstr(type,"Film-Noir")!=NULL) {x[52]=1;}
    if (strstr(type,"Game-Show")!=NULL) {x[53]=1;}
    if (strstr(type,"History")!=NULL) {x[54]=1;}
    if (strstr(type,"Horror")!=NULL) {x[55]=1;}
    if (strstr(type,"Music")!=NULL) {x[56]=1;}
    if (strstr(type,"Musical")!=NULL) {x[57]=1;}
    if (strstr(type,"Mystery")!=NULL) {x[58]=1;}
    if (strstr(type,"News")!=NULL) {x[59]=1;}
    if (strstr(type,"Reality-TV")!=NULL) {x[60]=1;}
    if (strstr(type,"Romance")!=NULL) {x[61]=1;}
    if (strstr(type,"Sci-Fi")!=NULL) {x[62]=1;}
    if (strstr(type,"Short")!=NULL) {x[63]=1;}
    if (strstr(type,"Sport")!=NULL) {x[64]=1;}
    if (strstr(type,"Thriller")!=NULL) {x[65]=1;}
    if (strstr(type,"War")!=NULL) {x[66]=1;}
    if (strstr(type,"Western")!=NULL) {x[67]=1;}
    //key
    if (strstr(key,"based")!=NULL) {x[28]=1;}
    if (strstr(key,"city")!=NULL) {x[29]=1;}
    if (strstr(key,"death")!=NULL) {x[30]=1;}
    if (strstr(key,"female")!=NULL) {x[31]=1;}
    if (strstr(key,"friend")!=NULL) {x[32]=1;}
    if (strstr(key,"love")!=NULL) {x[33]=1;}
    if (strstr(key,"male")!=NULL) {x[34]=1;}
    if (strstr(key,"murder")!=NULL) {x[35]=1;}
    if (strstr(key,"new york")!=NULL) {x[36]=1;}
    if (strstr(key,"nudity")!=NULL) {x[37]=1;}
    if (strstr(key,"police")!=NULL) {x[38]=1;}
    if (strstr(key,"relationship")!=NULL) {x[39]=1;}
    if (strstr(key,"school")!=NULL) {x[40]=1;}
    if (strstr(key,"sex")!=NULL) {x[41]=1;}
    //format
    x[8] = 1;
    if (strstr(format,"and")!=NULL) {x[8]=0;}
    //rank
    if (strcmp(rank,"Approved")==0) {x[10]=1;}
    if (strcmp(rank,"G")==0) {x[11]=1;}
    if (strcmp(rank,"GP")==0) {x[12]=1;}
    if (strcmp(rank,"M")==0) {x[13]=1;}
    if (strcmp(rank,"NC-17")==0) {x[14]=1;}
    if (strcmp(rank,"Not Rated")==0) {x[15]=1;}
    if (strcmp(rank,"PG")==0) {x[16]=1;}
    if (strcmp(rank,"PG-13")==0) {x[17]=1;}
    if (strcmp(rank,"Passed")==0) {x[18]=1;}
    if (strcmp(rank,"R")==0) {x[19]=1;}
    if (strcmp(rank,"TV-14")==0) {x[20]=1;}
    if (strcmp(rank,"TV-G")==0) {x[21]=1;}
    if (strcmp(rank,"TV-MA")==0) {x[22]=1;}
    if (strcmp(rank,"TV-PG")==0) {x[23]=1;}
    if (strcmp(rank,"TV-Y")==0) {x[24]=1;}
    if (strcmp(rank,"TV-Y7")==0) {x[25]=1;}
    if (strcmp(rank,"Unrated")==0) {x[26]=1;}
    if (strcmp(rank,"X")==0) {x[27]=1;}
}

double sigmoid(double z){
    return 2/(1+exp(-2*z))-1;
}

double rateNN(){
    int i,j;
    double hid[10],xx[78],out=0;
    //x scale
    for (i=0;i<77;i++){
        xx[i] = (x[i] - x_toMinus[i]) * x_toTimes[i] + x_toPlus;
    }
    //layer 1 linear
    for (i=0;i<9;i++){
        hid[i]=0;
        for (j=0;j<77;j++){
            hid[i] += B1[i][j] * xx[j];
        }
        hid[i] += b1[i];
    }
    //layer 1 sigmoid
    for (i=0;i<9;i++){
        hid[i] = sigmoid(hid[i]);
    }
    //layer 2 linear
    for (i=0;i<9;i++){
        out += B2[i]*hid[i];
    }
    out += b2;
    //output scale
    out = (out - y_toPlus) / y_toTimes + y_toMinus;
    //manual correction FOR BOXPREDICTION
    out = fabs(out);
    if (out>10) {out=10;}
    return out;
}



double boxNN(){
    int i,j;
    double hid[4],xx[70],out=0;
    //x scale
    for (i=0;i<70;i++){
        xx[i] = (x[x_toKeep2[i]-1] - x_toMinus2[i]) * x_toTimes2[i] + x_toPlus2;
    }
    //layer 1 linear
    for (i=0;i<4;i++){
        hid[i]=0;
        for (j=0;j<70;j++){
            hid[i] += B12[i][j] * xx[j];
        }
        hid[i] += b12[i];
    }
    //layer 1 sigmoid
    for (i=0;i<4;i++){
        hid[i] = sigmoid(hid[i]);
    }
    //layer 2 linear
    for (i=0;i<4;i++){
        out += B22[i]*hid[i];
    }
    out += b22;
    //output scale
    out = (out - y_toPlus2) / y_toTimes2 + y_toMinus2;
    //manual correction FOR BOXPREDICTION
    out -= 60000;
    out = fabs(out);
    return out;
}

int main(){
    int line=0;
    printf("\nPlease put your data in 'data.txt'\nStrike any key to continue!");
    getch();
    if((fileData=fopen("data.txt","rt"))==NULL){
        printf("\nCannot find file\nPlease put the data into data.txt\nStrike any key to exit!");
        getch();
        exit(1);
    }
    fileOutput = fopen("output.txt","w+");
    fprintf(fileOutput,"number%cfilmName%cratePredict%cboxPredict\n",(char)9,(char)9,(char)9);//
    while(!feof(fileData)){
        fileReadln();
        line++;
        printf("%d, %s\n",line,fN);
        fprintf(fileOutput,"%d%c%s%c%0.2lf%c%0.0lf\n",line,(char)9,fN,(char)9,rateNN(),(char)9,boxNN());//
    }
    printf("\nAll %d films have been analyzed!\nPlease check the results in 'output.txt', You may open it by Excel\n\nStrike any key to exit!",line);
    getch();
    fclose(fileOutput);
    fclose(fileData);
    return 0;
}