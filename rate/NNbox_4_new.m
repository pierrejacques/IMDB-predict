function [Y,Xf,Af] = NNbox_4_new(X,~,~)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 29-Apr-2017 17:28:34.
%
% [Y] = myNeuralNetworkFunction(X,~,~) takes these arguments:
%
%   X = 1xTS cell, 1 inputs over TS timesteps
%   Each X{1,ts} = Qx77 matrix, input #1 at timestep ts.
%
% and returns:
%   Y = 1xTS cell of 1 outputs over TS timesteps.
%   Each Y{1,ts} = Qx1 matrix, output #1 at timestep ts.
%
% where Q is number of samples (or series) and TS is the number of timesteps.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1_remove = [21 22 24 25 26 54 61];
x1_step1_keep = [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 23 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 55 56 57 58 59 60 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77];
x1_step2_xoffset = [1.18;5;1;0;34;0;0;1100;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;1;1;0;0;0;0;1920];
x1_step2_gain = [0.134952766531714;1.18360073833014e-06;0.000395335046451868;8.69565217391304e-05;0.00666666666666667;0.0465116279069767;5.73065902578797e-06;1.63726427907091e-10;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;0.181818181818182;0.00246305418719212;3.125e-06;1.45985401459854e-05;8.69565217391304e-05;3.04539156121998e-06;0.0208333333333333];
x1_step2_ymin = -1;

% Layer 1
b1 = [-14187.771413405639;13.430490774309032;364.31824201051143;1575.160883823075];
IW1_1 = [-324.1699524473272 161.03536066521133 -616.17609837451892 -2768.7074779682162 237.38822823928027 285.89049864434514 455.03436622467854 1.088623686707527 146.28304454344794 522.68530760757915 -7660.3069706609758 -111.8387595129021 14206.535881247037 14193.575923300676 -158.81708112219445 -967.92173790132892 437.31651199276899 264.57324117576388 1191.649625320754 -436.58076584410344 14174.167990840106 774.21568386510114 652.36334529731778 -159.62597313833854 -79.875721766489164 -227.96487976737279 1377.4089121554155 12.101625043076721 -322.87892343652783 1301.3905287290804 -733.91922220750814 -172.93915396639568 -57.463254134783234 -43.768665412913045 44.589185180145769 -441.14602190671138 -122.54398331703165 -518.30512778351772 -899.2867777061748 -866.64846528166674 1056.9134120064487 -346.35967552800031 -1447.956698010729 -130.1516077258631 1561.7685324043439 -276.92758904207744 -558.39204346693521 14206.579144398956 176.61951086726035 -372.95284119994517 -320.65382068834037 -225.45474339585215 -302.19647927383778 -67075.619590027651 845.00137431606299 -836.26924003256818 776.45738094831631 -5031.2512968627043 4975.5540084168306 -932.78027470833774 -185.96442172419887 -252.16876057694043 1608.068398920602 138.88380957216324 1481.3518270163217 386.1710628383812 129.10310440632074 -31.794282233738702 -599.48083467710444 890.73791040271431;0.0078330996393435777 1.2157911199798566 0.32058032391278135 -0.072766286130289612 0.25441550442487953 -0.17047610745053018 0.096434608282017428 19.931289763356897 0.1645574083735605 20.151408360299609 1.4284480693619963 1.4886281523776332 -24.281683149940736 -45.16149876517067 1.1033398186416776 1.146352383635028 1.5749303272921573 1.6057823145561374 0.84147874165718217 1.4430665763441952 -247.64460310708373 1.2147704388006881 -28.591873821160132 0.054443533272454193 0.08665778028738233 0.051392701757459948 -0.014948983443789936 0.047849800607033782 0.020771531845535998 0.021471214462998517 0.025667206683516196 -0.067238409599902182 0.050519567142913564 0.025552427398221274 0.037774603265939247 0.053536001106989251 -0.030003515617361757 0.027871636906770365 0.0073281500064070748 0.093367787389483023 -0.015986491232807386 0.07924405381755642 -0.043750529850728234 -0.044279274724690509 -0.058667790315676205 0.12139358665367483 -0.0010859750740940287 -24.661787478401607 -0.014692892453879799 -0.00081321735366225798 0.022809960037216748 0.0013993793014477692 -0.040508291696550708 407.08371462670675 0.029016795442830912 -0.070326488691921013 -27.20130998165158 0.076564980673173355 0.060206242308767817 0.031368068214479385 -0.080010281553796525 -0.031390856365430972 0.091756319775305323 0.1020556705256757 0.41295713569378628 -23.398244567604575 -4.661908108238741 -1.0805288094771406 23.325875177280029 -0.67095307273158811;-3083.8544299019386 7213.5058928453291 1278.9048439178689 -1406.2498428593117 3850.6142627119593 -1328.0679094260518 -10622.199017383733 13010.46131959432 801.90193388802129 -498.74109031426667 -1024.2719891967638 1935.2654513234211 -364.92688094475466 -364.94655891921218 -2949.540552958339 -84.122274562733878 -920.85533186273142 -1360.2329057160882 -364.53825227289855 3491.6689309097214 -364.74348276639961 633.14221072071587 607.5199797094798 -105.28891237658888 1244.5672433332231 -133.14651560500516 -1046.3064542129866 819.15096043071037 -1046.1991190674678 939.46113426556224 2028.4192474206773 -900.33962452865831 600.07704830729517 159.11207833439727 318.33755493606918 294.14382399150207 431.57329555824083 -666.69039975336932 1182.7574613569179 -705.49241232934742 256.82122514878102 -491.24221558195222 -330.82169917395868 615.02888682922423 -306.06533400259195 1331.7656988259571 2787.0205209934984 -364.53630380808681 470.23141504971773 2359.5524206082773 244.24909296777821 -329.55226316818943 1187.4151866808936 -364.58064459368512 -34.089660810487544 -2871.8077066476662 -364.82993593245408 -46.660202950361224 -1954.3506021555081 732.57705277412811 -748.74528027444012 -708.49059500249837 782.56660284091242 1066.7104363849003 3272.9671604027576 -26986.220558273806 -1182.0232675768998 1412.3229540524619 31170.502359279075 -142.39808200577886;2372.9476443267727 20274.003559849505 -21279.791589781002 -2068.4046680294796 -11043.52480488197 -76.051143896163353 4924.027553002843 10279.862354057217 -3553.8586972663302 415.21262097203174 -1642.6953392789844 1017.3132587810111 -1573.5352956761012 -1578.6533235255572 -2024.3587408622152 -308.0640140084497 -1204.9552982561706 -3841.2428020724742 -1573.479456830458 -2090.2468947036941 -1573.5985511610238 -2097.5432239454931 -7159.305756217108 1389.6207881115149 -4342.4210758532099 -1682.6525325157875 -610.18535908092633 1635.2568320331027 816.86004073420713 -887.29235599949504 2509.0726395519723 2135.681117958783 2834.49922708333 -3151.7724476495096 -1985.7717569984218 -801.98703517685612 -2000.2919678724052 -177.53789818637503 2653.0233147172544 -3567.3934160967033 712.18030039019231 101.81122195866291 -2339.0429009653972 -3394.5627855967118 1612.7239712688011 -1664.4453351521365 377.87892901019524 -1573.4786262502264 946.00450085141347 987.01886409378164 -708.83926700147742 -530.06879331814002 952.37389076517547 -1574.7371060276471 1070.8585324925502 3212.1146580775949 -1573.4872811677239 -1558.8499559527443 1852.452786513076 2478.3408329799818 -3278.3474145571877 3634.0695770823768 -2454.9825563823701 -1385.0462688385358 -4029.0106227679789 5848.0134782942223 7669.6455913050122 -7089.4470450334957 24438.938618830714 4940.9091330455494];

% Layer 2
b2 = -0.54649785771320702;
LW2_1 = [0.021484033164223714 0.4799192927071767 -0.0069039802193013762 0.0023157916270890909];

% Output 1
y1_step1_ymin = -1;
y1_step1_gain = 2.6298291248145e-09;
y1_step1_xoffset = 162;

% ===== SIMULATION ========

% Format Input Arguments
isCellX = iscell(X);
if ~isCellX, X = {X}; end;

% Dimensions
TS = size(X,2); % timesteps
if ~isempty(X)
    Q = size(X{1},1); % samples/series
else
    Q = 0;
end

% Allocate Outputs
Y = cell(1,TS);

% Time loop
for ts=1:TS
    
    % Input 1
    X{1,ts} = X{1,ts}';
    temp = removeconstantrows_apply(X{1,ts},x1_step1_keep,x1_step1_remove);
    Xp1 = mapminmax_apply(temp,x1_step2_gain,x1_step2_xoffset,x1_step2_ymin);
    
    % Layer 1
    a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*Xp1);
    
    % Layer 2
    a2 = repmat(b2,1,Q) + LW2_1*a1;
    
    % Output 1
    Y{1,ts} = mapminmax_reverse(a2,y1_step1_gain,y1_step1_xoffset,y1_step1_ymin);
    Y{1,ts} = Y{1,ts}';
end

% Final Delay States
Xf = cell(1,0);
Af = cell(2,0);

% Format Output Arguments
if ~isCellX, Y = cell2mat(Y); end
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings_gain,settings_xoffset,settings_ymin)
y = bsxfun(@minus,x,settings_xoffset);
y = bsxfun(@times,y,settings_gain);
y = bsxfun(@plus,y,settings_ymin);
end

% Remove Constants Input Processing Function
function y = removeconstantrows_apply(x,settings_keep,settings_remove)
if isempty(settings_remove)
    y = x;
else
    y = x(settings_keep,:);
end
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n)
a = 2 ./ (1 + exp(-2*n)) - 1;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings_gain,settings_xoffset,settings_ymin)
x = bsxfun(@minus,y,settings_ymin);
x = bsxfun(@rdivide,x,settings_gain);
x = bsxfun(@plus,x,settings_xoffset);
end
