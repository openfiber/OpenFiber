#include "test_cell.h"

Test_Cell::Test_Cell()
{
}

void Test_Cell::initConsts(double *CONSTANTS, double *RATES, double *STATES)
{
    STATES[0] = 0;
    STATES[1] = 7.455e-8;
    STATES[2] = 0;
    STATES[3] = 0.436333342969918;
    STATES[4] = 0.436333525334166;
    STATES[5] = 0.088805830771694;
    STATES[6] = 0.00015;
    STATES[7] = -93.658148;
    STATES[8] = 3.988;
    STATES[9] = 139.054;
    STATES[10] = 5.18787513289509;
    STATES[11] = 6.15e-6;
    STATES[12] = 8.88859784542779e-6;
    STATES[13] = 1.53745791069154e-7;
    STATES[14] = 0.001;
    STATES[15] = 0.0015;
    STATES[16] = 0.995;
    STATES[17] = 2.55e-6;
    STATES[18] = 0;
    STATES[19] = 1;
    STATES[20] = 1;
    STATES[21] = 0.997;
    STATES[22] = 0.997044616031121;
    STATES[23] = 1.63117173173398e-8;
    STATES[24] = 0.994579;
    STATES[25] = 0.989665;
    STATES[26] = 0.001914;
    STATES[27] = 0.2854569;
    STATES[28] = 0;
    STATES[29] = 0;
    STATES[30] = -20;

    CONSTANTS[0] = 0;
    CONSTANTS[1] = 14.6;
    CONSTANTS[2] = 0.84;
    CONSTANTS[3] = 14.6;
    CONSTANTS[4] = 0.0018;
    CONSTANTS[5] = 48;
    CONSTANTS[6] = 0.015;
    CONSTANTS[7] = 30;
    CONSTANTS[8] = 3;
    CONSTANTS[9] = 0.6;
    CONSTANTS[10] = 0.705;
    CONSTANTS[11] = 3;
    CONSTANTS[12] = 0.9;
    CONSTANTS[13] = 5.5;
    CONSTANTS[14] = 0.25;
    CONSTANTS[15] = 0.5;
    CONSTANTS[16] = 4;
    CONSTANTS[17] = 2;
    CONSTANTS[18] = 0.525139356105856;
    CONSTANTS[19] = 1;
    CONSTANTS[20] = 1.14;
    CONSTANTS[21] = 17.3;
    CONSTANTS[22] = 259;
    CONSTANTS[23] = 17.3;
    CONSTANTS[24] = 15;
    CONSTANTS[25] = 0.964285;
    CONSTANTS[26] = 1;
    CONSTANTS[27] = 40;   
    CONSTANTS[28] = 10;
    CONSTANTS[29] = 5;
    CONSTANTS[30] = 0.07;
    CONSTANTS[31] = 0.6;
    CONSTANTS[32] = 0.52;
    CONSTANTS[33] = 0.06;
    CONSTANTS[34] = 10000;
    CONSTANTS[35] = 0.0025;
    CONSTANTS[36] = -3;
    CONSTANTS[37] = 16;
    CONSTANTS[38] = 0.0015;
    CONSTANTS[39] = 16;
    CONSTANTS[40] = 0.0015;
    CONSTANTS[41] = 46;
    CONSTANTS[42] = 0;
    CONSTANTS[43] = 39;
    CONSTANTS[44] = 0;
    CONSTANTS[45] = 8314.472;
    CONSTANTS[46] = 310;
    CONSTANTS[47] = 96485.3415;
    CONSTANTS[48] = 9.5e-5;
    CONSTANTS[49] = 0.03;  
    CONSTANTS[50] = 140;   
    CONSTANTS[51] = 2;
    CONSTANTS[52] = 10;
    CONSTANTS[53] = 0.5;
    CONSTANTS[54] = 0.0021;
    CONSTANTS[55] = 0.0013;
    CONSTANTS[56] = 0.0026;
    CONSTANTS[57] = 0;
    CONSTANTS[58] = 20;
    CONSTANTS[59] = 2.5;
    CONSTANTS[60] = 1e-5;
    CONSTANTS[61] = 0.004;
    CONSTANTS[62] = 0.0006;
    CONSTANTS[63] = 0.1;
    CONSTANTS[64] = 0.002;
    CONSTANTS[65] = 0.01;
    CONSTANTS[66] = 100000;
    CONSTANTS[67] = 0.001;
    CONSTANTS[68] = 20;
    CONSTANTS[69] = 1;
    CONSTANTS[70] = 3;
    CONSTANTS[71] = 0.3;
    CONSTANTS[72] = 0.0001;
    CONSTANTS[73] = 0.00025;
    CONSTANTS[74] = 0.006;
    CONSTANTS[75] = 0;
    CONSTANTS[76] = 0.7;
    CONSTANTS[77] = 1;
    CONSTANTS[78] = 24.2;
    CONSTANTS[79] = 0.0005;
    CONSTANTS[80] = 3;
    CONSTANTS[81] = 0;
    CONSTANTS[82] = 0.5;
    CONSTANTS[83] = 0.001;
    CONSTANTS[84] = 0.00015;
    CONSTANTS[85] = 0.4;
    CONSTANTS[86] = 0.5;
    CONSTANTS[87] = 1;
    CONSTANTS[88] = 0.03;
    CONSTANTS[89] = 0;
    CONSTANTS[90] = 4;
    CONSTANTS[91] = 15;
    CONSTANTS[92] = 50000;
    CONSTANTS[93] = 32500;
    CONSTANTS[94] = 40;
    CONSTANTS[95] = 0.05;
    CONSTANTS[96] = 10000;
    CONSTANTS[97] = 0.0005;
    CONSTANTS[98] = 0.01;
    CONSTANTS[99] = 1.5;
    CONSTANTS[100] = 4;
    CONSTANTS[101] = 12;
    CONSTANTS[102] = 74;
    CONSTANTS[103] = 0.49;
    CONSTANTS[104] = 0.1;
    CONSTANTS[105] = 0.003;
    CONSTANTS[106] = 0.4;
    CONSTANTS[107] = 0.03;
    CONSTANTS[108] = 10;
    CONSTANTS[109] = 0.03;
    CONSTANTS[110] = 70000;
    CONSTANTS[111] = 200;
    CONSTANTS[112] = 0.08;
    CONSTANTS[113] = 100000;
    CONSTANTS[114] = 182;    
    CONSTANTS[115] = 0.1;
    CONSTANTS[116] = 1000;
    CONSTANTS[117] = 3;
    CONSTANTS[118] = 2.9e-4;
    CONSTANTS[119] = 2e-4;
    CONSTANTS[120] = 1e-5;
    CONSTANTS[121] = 0;
    CONSTANTS[122] = 0;
    CONSTANTS[123] =  CONSTANTS[25]*CONSTANTS[13];
    CONSTANTS[124] = CONSTANTS[13]/10.0000;
    CONSTANTS[125] =  CONSTANTS[14]*(0.400000+ 0.400000*CONSTANTS[14])/( CONSTANTS[13]*pow( (CONSTANTS[14]+1.00000)*0.400000, 2.00000));
    CONSTANTS[126] = ( 0.400000*CONSTANTS[14]+1.00000)/( CONSTANTS[14]*CONSTANTS[13]);
    CONSTANTS[127] =  3.14159*pow(CONSTANTS[101]/1000.00, 2.00000)*CONSTANTS[102]/1000.00;
    CONSTANTS[128] =  CONSTANTS[84]*CONSTANTS[85]/CONSTANTS[86];
    CONSTANTS[129] = CONSTANTS[93]/CONSTANTS[92];
    CONSTANTS[130] =  CONSTANTS[14]*CONSTANTS[15]*pow(CONSTANTS[124]/CONSTANTS[13], 2.00000)/( 3.00000*CONSTANTS[14]*CONSTANTS[15] -  (CONSTANTS[14]+1.00000)*CONSTANTS[124]/CONSTANTS[13]);
    CONSTANTS[131] =  CONSTANTS[127]*CONSTANTS[103];
    CONSTANTS[132] =  CONSTANTS[127]*CONSTANTS[106];
}

void Test_Cell::computeRates(double VOI, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC)
{
    RATES[20] = 1.00000 -  1.00000*(STATES[11]/(CONSTANTS[66]+STATES[11])+STATES[20]);
    RATES[21] =  CONSTANTS[68]*(1.00000 - STATES[17]/(CONSTANTS[67]+STATES[17])+STATES[21]);
    RATES[23] =  333.000*(1.00000/(1.00000+exp(- (STATES[7]+4.00000)/5.00000)) - STATES[23]);
    ALGEBRAIC[3] = STATES[0];
    RATES[3] = ALGEBRAIC[3];
    ALGEBRAIC[4] = 50.0000/(1.00000+exp(- (STATES[7] - 5.00000)/9.00000));
    ALGEBRAIC[16] =  0.0500000*exp(- (STATES[7] - 20.0000)/15.0000);
    RATES[12] =  ALGEBRAIC[4]*(1.00000 - STATES[12]) -  ALGEBRAIC[16]*STATES[12];
    ALGEBRAIC[5] = 50.0000/(1.00000+exp(- (STATES[7] - 5.00000)/9.00000));
    ALGEBRAIC[17] =  0.400000*exp(- pow((STATES[7]+30.0000)/30.0000, 3.00000));
    RATES[13] =  ALGEBRAIC[5]*(1.00000 - STATES[13]) -  ALGEBRAIC[17]*STATES[13];
    ALGEBRAIC[6] = 14.0000/(1.00000+exp(- (STATES[7] - 40.0000)/9.00000));
    ALGEBRAIC[18] =  1.00000*exp(- STATES[7]/45.0000);
    RATES[14] =  ALGEBRAIC[6]*(1.00000 - STATES[14]) -  ALGEBRAIC[18]*STATES[14];
    ALGEBRAIC[8] =  20.0000*exp( - 0.125000*(STATES[7]+75.0000));
    ALGEBRAIC[20] = 2000.00/(1.00000+ 320.000*exp( - 0.100000*(STATES[7]+75.0000)));
    RATES[16] =  ALGEBRAIC[8]*(1.00000 - STATES[16]) -  ALGEBRAIC[20]*STATES[16];
    ALGEBRAIC[11] =  0.0330000*exp(- STATES[7]/17.0000);
    ALGEBRAIC[23] = 33.0000/(1.00000+exp( - 0.125000*(STATES[7]+10.0000)));
    RATES[22] =  ALGEBRAIC[11]*(1.00000 - STATES[22]) -  ALGEBRAIC[23]*STATES[22];
    ALGEBRAIC[14] =  CONSTANTS[119]*(STATES[30]+20.0000)+ CONSTANTS[121]*(STATES[30] - CONSTANTS[122]);
    ALGEBRAIC[25] =  - CONSTANTS[118]*(STATES[7] - STATES[30]);
    RATES[30] = - (ALGEBRAIC[14]+ALGEBRAIC[25])/CONSTANTS[120];
    ALGEBRAIC[7] = STATES[7]+41.0000;
    ALGEBRAIC[19] = (fabs(ALGEBRAIC[7])<CONSTANTS[60] ? 2000.00 :  200.000*ALGEBRAIC[7]/(1.00000 - exp( - 0.100000*ALGEBRAIC[7])));
    ALGEBRAIC[27] =  8000.00*exp( - 0.0560000*(STATES[7]+66.0000));
    RATES[15] =  ALGEBRAIC[19]*(1.00000 - STATES[15]) -  ALGEBRAIC[27]*STATES[15];
    ALGEBRAIC[9] = STATES[7]+24.0000 - 5.00000;
    ALGEBRAIC[21] = (fabs(ALGEBRAIC[9])<0.000100000 ? 120.000 :  30.0000*ALGEBRAIC[9]/(1.00000 - exp(- ALGEBRAIC[9]/4.00000)));
    ALGEBRAIC[28] = (fabs(ALGEBRAIC[9])<0.000100000 ? 120.000 :  12.0000*ALGEBRAIC[9]/(exp(ALGEBRAIC[9]/10.0000) - 1.00000));
    RATES[18] =  CONSTANTS[70]*( ALGEBRAIC[21]*(1.00000 - STATES[18]) -  ALGEBRAIC[28]*STATES[18]);
    ALGEBRAIC[10] = STATES[7]+34.0000;
    ALGEBRAIC[22] = (fabs(ALGEBRAIC[10])<CONSTANTS[72] ? 25.0000 :  6.25000*ALGEBRAIC[10]/(exp(ALGEBRAIC[10]/4.00000) - 1.00000));
    ALGEBRAIC[29] = 12.0000/(1.00000+exp( - 1.00000*(STATES[7]+34.0000)/4.00000));
    RATES[19] =  CONSTANTS[71]*( ALGEBRAIC[22]*(1.00000 - STATES[19]) -  ALGEBRAIC[29]*STATES[19]);
    ALGEBRAIC[13] = STATES[11]/(STATES[11]+CONSTANTS[97]);
    ALGEBRAIC[24] = STATES[17]/(STATES[17]+CONSTANTS[98]);
    ALGEBRAIC[30] = ALGEBRAIC[13]+ (1.00000 - ALGEBRAIC[13])*ALGEBRAIC[24];
    ALGEBRAIC[34] = 60.0000+ 500.000*pow(ALGEBRAIC[30], 2.00000);
    ALGEBRAIC[36] = (STATES[7]<- 50.0000 ? 5.00000 : 1.00000);
    RATES[27] =  STATES[26]*ALGEBRAIC[36]*ALGEBRAIC[34] -  ALGEBRAIC[36]*0.600000*STATES[27];
    ALGEBRAIC[32] =  500.000*pow(ALGEBRAIC[30], 2.00000);
    ALGEBRAIC[38] = 1.00000 - STATES[26] - STATES[27];
    RATES[26] =  ALGEBRAIC[38]*ALGEBRAIC[36]*ALGEBRAIC[32] -  STATES[26]*ALGEBRAIC[36]*ALGEBRAIC[34];
    ALGEBRAIC[51] = (STATES[2]<=STATES[0] ?  CONSTANTS[42]*exp( CONSTANTS[41]*(STATES[4] - STATES[3])) :  CONSTANTS[44]*exp( CONSTANTS[43]*(STATES[4] - STATES[3])));
    ALGEBRAIC[37] = STATES[4]+STATES[5];
    ALGEBRAIC[15] =  CONSTANTS[6]*(exp( CONSTANTS[5]*STATES[5]) - 1.00000);
    ALGEBRAIC[26] = ALGEBRAIC[15];
    ALGEBRAIC[40] = (CONSTANTS[0]==1.00000&&ALGEBRAIC[26]>CONSTANTS[17]&&ALGEBRAIC[37]<= CONSTANTS[18]*(1.00000+0.000100000) ? 1.00000 : 0.00000);
    ALGEBRAIC[47] = (ALGEBRAIC[40]==1.00000 ?  CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*STATES[0]/( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])) :  CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*STATES[0]/( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])+ CONSTANTS[5]*CONSTANTS[6]*exp( CONSTANTS[5]*STATES[5])));
    ALGEBRAIC[54] = (ALGEBRAIC[51]==0.00000 ? ALGEBRAIC[47] : STATES[2]);
    RATES[4] = ALGEBRAIC[54];
    ALGEBRAIC[55] = (ALGEBRAIC[40]==1.00000 ? 0.00000 : ALGEBRAIC[40]==0.00000&&ALGEBRAIC[51]==0.00000 ? - ALGEBRAIC[47] : ALGEBRAIC[40]==0.00000&&ALGEBRAIC[51] != 0.00000 ? - STATES[2] : 0.0/0.0);
    RATES[5] = (VOI>=CONSTANTS[33]&&VOI<=CONSTANTS[34]&&VOI - CONSTANTS[33] -  floor((VOI - CONSTANTS[33])/CONSTANTS[19])*CONSTANTS[19]<=CONSTANTS[35] ? - (STATES[4]+STATES[5] - CONSTANTS[18])/CONSTANTS[35] : ALGEBRAIC[55]);
    ALGEBRAIC[31] =  pow(STATES[6]/CONSTANTS[30], CONSTANTS[8])*(1.00000+pow(CONSTANTS[9], CONSTANTS[8]))/(pow(STATES[6]/CONSTANTS[30], CONSTANTS[8])+pow(CONSTANTS[9], CONSTANTS[8]));
    ALGEBRAIC[33] = ( CONSTANTS[31]*STATES[3]+CONSTANTS[32]<0.00000 ? 0.00000 :  CONSTANTS[31]*STATES[3]+CONSTANTS[32]<1.00000 ?  CONSTANTS[31]*STATES[3]+CONSTANTS[32] : 1.00000);
    ALGEBRAIC[35] = (STATES[3]>0.550000 ? (STATES[3]+CONSTANTS[20])/(0.460000+CONSTANTS[20]) :  (CONSTANTS[20]+0.550000)*1.00000);
    ALGEBRAIC[2] = (STATES[0]<=0.00000 ? CONSTANTS[21] -  CONSTANTS[22]*STATES[0]/CONSTANTS[13] : STATES[0]<=CONSTANTS[123]&&0.00000<STATES[0] ?  (CONSTANTS[24] - CONSTANTS[23])*STATES[0]/CONSTANTS[123]+CONSTANTS[23] : CONSTANTS[24]/pow(1.00000+ CONSTANTS[29]*(STATES[0] - CONSTANTS[123])/CONSTANTS[13], CONSTANTS[28]));
    ALGEBRAIC[53] = (STATES[0]<=0.00000 ?  CONSTANTS[14]*(1.00000+STATES[0]/CONSTANTS[13])/(CONSTANTS[14] - STATES[0]/CONSTANTS[13]) : 1.00000+CONSTANTS[15] -  pow(CONSTANTS[15], 2.00000)*CONSTANTS[14]/(  CONSTANTS[14]*CONSTANTS[15]/CONSTANTS[130]*pow(STATES[0]/CONSTANTS[13], 2.00000)+ (CONSTANTS[14]+1.00000)*STATES[0]/CONSTANTS[13]+ CONSTANTS[14]*CONSTANTS[15]));
    ALGEBRAIC[57] = (- CONSTANTS[13]<=STATES[0]&&STATES[0]<=0.00000 ? 1.00000+ 0.600000*STATES[0]/CONSTANTS[13] : 0.00000<STATES[0]&&STATES[0]<=CONSTANTS[124] ? ALGEBRAIC[53]/( ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13])+1.00000) :  ALGEBRAIC[53]*exp( - CONSTANTS[26]*pow((STATES[0] - CONSTANTS[124])/CONSTANTS[13], CONSTANTS[16]))/( ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13])+1.00000));
    ALGEBRAIC[59] =  CONSTANTS[10]*CONSTANTS[11]*ALGEBRAIC[2]*CONSTANTS[12]*ALGEBRAIC[57];
    ALGEBRAIC[61] =  CONSTANTS[11]*ALGEBRAIC[2]*(1.00000 -  CONSTANTS[10]*CONSTANTS[12]*ALGEBRAIC[57]);
    ALGEBRAIC[63] =  ALGEBRAIC[59]*ALGEBRAIC[31]*ALGEBRAIC[33]*ALGEBRAIC[35]*(1.00000 - STATES[1]) -  ALGEBRAIC[61]*STATES[1];
    RATES[1] = ALGEBRAIC[63];
    ALGEBRAIC[44] = (STATES[0]<=0.00000 ?  CONSTANTS[38]*exp( CONSTANTS[37]*STATES[3]) :  CONSTANTS[40]*exp( CONSTANTS[39]*STATES[3]));
    ALGEBRAIC[69] = ALGEBRAIC[53]/ALGEBRAIC[57];
    ALGEBRAIC[65] =  CONSTANTS[14]*1.00000*(1.00000+ 0.400000*CONSTANTS[14]+ 1.20000*STATES[0]/CONSTANTS[13]+ 0.600000*pow(STATES[0]/CONSTANTS[13], 2.00000))/( CONSTANTS[13]*pow( (CONSTANTS[14] - STATES[0]/CONSTANTS[13])*(1.00000+ 0.600000*STATES[0]/CONSTANTS[13]), 2.00000));
    ALGEBRAIC[67] =  1.00000/CONSTANTS[13]*exp( - CONSTANTS[26]*pow(STATES[0]/CONSTANTS[13] - CONSTANTS[124]/CONSTANTS[13], CONSTANTS[16]))*(( 0.400000*CONSTANTS[14]+1.00000)/CONSTANTS[14]+ CONSTANTS[26]*CONSTANTS[16]*(1.00000+ ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13]))*pow(STATES[0]/CONSTANTS[13] - CONSTANTS[124]/CONSTANTS[13], CONSTANTS[16] - 1.00000));
    ALGEBRAIC[72] = (STATES[0]<=- CONSTANTS[13] ? CONSTANTS[125] : - CONSTANTS[13]<STATES[0]&&STATES[0]<=0.00000 ? ALGEBRAIC[65] : 0.00000<STATES[0]&&STATES[0]<=CONSTANTS[124] ? CONSTANTS[126] : ALGEBRAIC[67]);
    ALGEBRAIC[42] = (STATES[0]<=0.00000 ? CONSTANTS[37] : CONSTANTS[39]);
    ALGEBRAIC[74] = (ALGEBRAIC[40]==1.00000 ? - ( CONSTANTS[7]*ALGEBRAIC[63]*ALGEBRAIC[69]+ ALGEBRAIC[42]*ALGEBRAIC[44]*pow(STATES[0], 2.00000)+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])*STATES[2])/( CONSTANTS[7]*STATES[1]*ALGEBRAIC[72]+ALGEBRAIC[44]) : - ( CONSTANTS[7]*ALGEBRAIC[63]*ALGEBRAIC[69]+ ALGEBRAIC[42]*ALGEBRAIC[44]*pow(STATES[0], 2.00000)+ ( CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])+ CONSTANTS[5]*CONSTANTS[6]*exp( CONSTANTS[5]*STATES[5]))*STATES[2])/( CONSTANTS[7]*STATES[1]*ALGEBRAIC[72]+ALGEBRAIC[44]));
    RATES[0] = (ALGEBRAIC[51]==0.00000 ? ( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*(ALGEBRAIC[47] - STATES[0]) - ( CONSTANTS[7]*ALGEBRAIC[63]*ALGEBRAIC[69]+ ALGEBRAIC[42]*ALGEBRAIC[44]*pow(STATES[0], 2.00000)))/( CONSTANTS[7]*STATES[1]*ALGEBRAIC[72]+ALGEBRAIC[44]) : ALGEBRAIC[74]);
    ALGEBRAIC[49] = (STATES[2]<=STATES[0] ? CONSTANTS[41] : CONSTANTS[43]);
    RATES[2] = (ALGEBRAIC[40]==1.00000&&ALGEBRAIC[51] != 0.00000 ? ( ALGEBRAIC[51]*(ALGEBRAIC[74] -  ALGEBRAIC[49]*pow(STATES[2] - STATES[0], 2.00000)) -  CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*(STATES[2] - STATES[0]) -  CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])*STATES[2])/ALGEBRAIC[51] : ALGEBRAIC[40]==0.00000&&ALGEBRAIC[51] != 0.00000 ? ALGEBRAIC[74] -  ALGEBRAIC[49]*pow(STATES[2] - STATES[0], 2.00000) - ( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*(STATES[2] - STATES[0])+ ( CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])+ CONSTANTS[5]*CONSTANTS[6]*exp( CONSTANTS[5]*STATES[5]))*STATES[2])/ALGEBRAIC[51] : ALGEBRAIC[51]==0.00000 ? 0.00000 : 0.0/0.0);
    ALGEBRAIC[43] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(STATES[8]/STATES[9]);
    ALGEBRAIC[52] =   CONSTANTS[53]*STATES[8]/(STATES[8]+CONSTANTS[52])*(STATES[7] - ALGEBRAIC[43])/(1.00000+exp( (STATES[7] - ALGEBRAIC[43] - 10.0000)*CONSTANTS[47]*1.25000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[79] =  CONSTANTS[74]*(CONSTANTS[75]+ STATES[22]*(1.00000 - CONSTANTS[75]))*STATES[23]*(STATES[7] - ALGEBRAIC[43]);
    ALGEBRAIC[56] =   ( CONSTANTS[54]*STATES[12]+ CONSTANTS[55]*STATES[13])*1.00000/(1.00000+exp((STATES[7]+9.00000)/22.4000))*(STATES[7] - ALGEBRAIC[43]);
    ALGEBRAIC[46] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log((STATES[8]+ CONSTANTS[49]*CONSTANTS[50])/(STATES[9]+ CONSTANTS[49]*STATES[10]));
    ALGEBRAIC[58] =  CONSTANTS[56]*pow(STATES[14], 2.00000)*(STATES[7] - ALGEBRAIC[46]);
    ALGEBRAIC[68] =   (1.00000 - CONSTANTS[69])*CONSTANTS[64]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[9]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  STATES[8]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[75] =   CONSTANTS[69]*CONSTANTS[64]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[9]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  STATES[8]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[80] =   CONSTANTS[76]*STATES[8]/(CONSTANTS[77]+STATES[8])*STATES[10]/(CONSTANTS[78]+STATES[10]);
    RATES[8] =  1.00000*(ALGEBRAIC[56]+ALGEBRAIC[58]+ALGEBRAIC[52]+ALGEBRAIC[79] -  1.00000/(CONSTANTS[99] - 1.00000)*ALGEBRAIC[80]+ALGEBRAIC[68]+ALGEBRAIC[75])/( 1.00000*CONSTANTS[132]*CONSTANTS[47]) -  0.700000*(STATES[8] - CONSTANTS[100]);
    RATES[9] =  - 1.00000/( 1.00000*CONSTANTS[131]*CONSTANTS[47])*(ALGEBRAIC[52]+ALGEBRAIC[56]+ALGEBRAIC[58]+ALGEBRAIC[68]+ALGEBRAIC[75]+ALGEBRAIC[79] -  1.00000/(CONSTANTS[99] - 1.00000)*ALGEBRAIC[80]);
    ALGEBRAIC[50] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log((CONSTANTS[50]+ 0.120000*STATES[8])/(STATES[10]+ 0.120000*STATES[9]));
    ALGEBRAIC[60] =  CONSTANTS[59]*pow(STATES[15], 3.00000)*STATES[16]*(STATES[7] - ALGEBRAIC[50]);
    ALGEBRAIC[41] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(CONSTANTS[50]/STATES[10]);
    ALGEBRAIC[64] =  CONSTANTS[62]*(STATES[7] - ALGEBRAIC[41]);
    ALGEBRAIC[62] =   CONSTANTS[61]*1.00000/(1.00000+exp(- (STATES[7]+52.0000)/8.00000))*(STATES[7] - ALGEBRAIC[41]);
    ALGEBRAIC[70] =   (1.00000 - CONSTANTS[69])*CONSTANTS[65]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[10]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[50]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[76] =   CONSTANTS[69]*CONSTANTS[65]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[10]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[50]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[81] =  (1.00000 - CONSTANTS[83])*CONSTANTS[79]*( exp( CONSTANTS[82]*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(STATES[10], CONSTANTS[80])*CONSTANTS[51] -  exp( (CONSTANTS[82] - 1.00000)*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(CONSTANTS[50], CONSTANTS[80])*STATES[11])/( (1.00000+ CONSTANTS[81]*( STATES[11]*pow(CONSTANTS[50], CONSTANTS[80])+ CONSTANTS[51]*pow(STATES[10], CONSTANTS[80])))*(1.00000+STATES[11]/0.00690000));
    ALGEBRAIC[82] =  CONSTANTS[83]*CONSTANTS[79]*( exp( CONSTANTS[82]*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(STATES[10], CONSTANTS[80])*CONSTANTS[51] -  exp( (CONSTANTS[82] - 1.00000)*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(CONSTANTS[50], CONSTANTS[80])*STATES[17])/( (1.00000+ CONSTANTS[81]*( STATES[17]*pow(CONSTANTS[50], CONSTANTS[80])+ CONSTANTS[51]*pow(STATES[10], CONSTANTS[80])))*(1.00000+STATES[17]/0.00690000));
    ALGEBRAIC[66] =   (1.00000 - CONSTANTS[69])*4.00000*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[11]*exp( 100.000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[51]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[73] =   CONSTANTS[69]*4.00000*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[11]*exp( 100.000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[51]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[48] =   0.500000*CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(CONSTANTS[51]/STATES[11]);
    ALGEBRAIC[78] =  CONSTANTS[73]*(STATES[7] - ALGEBRAIC[48]);
    ALGEBRAIC[39] = (VOI>=CONSTANTS[33]&&VOI<=CONSTANTS[34]&&VOI - CONSTANTS[33] -  floor((VOI - CONSTANTS[33])/CONSTANTS[19])*CONSTANTS[19]<=CONSTANTS[35] ? CONSTANTS[36] : 0.00000);
    RATES[7] =  - 1.00000/CONSTANTS[48]*(ALGEBRAIC[39]+ALGEBRAIC[52]+ALGEBRAIC[79]+ALGEBRAIC[56]+ALGEBRAIC[58]+ALGEBRAIC[80]+ALGEBRAIC[60]+ALGEBRAIC[64]+ALGEBRAIC[62]+ALGEBRAIC[70]+ALGEBRAIC[76]+ALGEBRAIC[81]+ALGEBRAIC[82]+ALGEBRAIC[66]+ALGEBRAIC[73]+ALGEBRAIC[68]+ALGEBRAIC[75]+ALGEBRAIC[78]);
    RATES[17] = ( - 1.00000*ALGEBRAIC[73]+ 2.00000*ALGEBRAIC[82]/(CONSTANTS[80] - 2.00000))/( 2.00000*1.00000*CONSTANTS[104]*CONSTANTS[131]*CONSTANTS[47]) -  STATES[17]*CONSTANTS[108];
    ALGEBRAIC[84] = ALGEBRAIC[81]+ALGEBRAIC[82];
    RATES[10] =  - 1.00000/( 1.00000*CONSTANTS[131]*CONSTANTS[47])*(ALGEBRAIC[60]+ALGEBRAIC[62]+ALGEBRAIC[64]+ALGEBRAIC[70]+ALGEBRAIC[76]+ CONSTANTS[99]/(CONSTANTS[99] - 1.00000)*ALGEBRAIC[80]+ CONSTANTS[80]/(CONSTANTS[80] - 2.00000)*ALGEBRAIC[84]);
    ALGEBRAIC[83] = STATES[11]+ STATES[24]*CONSTANTS[128]+ CONSTANTS[84]*CONSTANTS[85]+CONSTANTS[84];
    ALGEBRAIC[85] = (CONSTANTS[89]==0.00000 ?  STATES[11]/ALGEBRAIC[83]*CONSTANTS[87] -   STATES[24]*CONSTANTS[128]/ALGEBRAIC[83]*CONSTANTS[88] :  STATES[11]/ALGEBRAIC[83]*CONSTANTS[87]/(1.00000+STATES[24]/CONSTANTS[90]) -   STATES[24]*CONSTANTS[128]/ALGEBRAIC[83]*CONSTANTS[88]);
    ALGEBRAIC[86] =  CONSTANTS[91]*(STATES[24] - STATES[25]);
    RATES[24] =  CONSTANTS[103]/CONSTANTS[107]*ALGEBRAIC[85] - ALGEBRAIC[86];
    ALGEBRAIC[87] =  ( pow(STATES[26]/(STATES[26]+0.250000), 2.00000)*CONSTANTS[96]+CONSTANTS[95])*STATES[25];
    RATES[25] = ( CONSTANTS[107]/CONSTANTS[105]*ALGEBRAIC[86] - ALGEBRAIC[87])/(1.00000+ CONSTANTS[129]*CONSTANTS[94]/pow(STATES[25]+CONSTANTS[129], 2.00000));
    ALGEBRAIC[88] =  CONSTANTS[30]*STATES[1]/( ALGEBRAIC[35]*STATES[6]);
    ALGEBRAIC[89] = (ALGEBRAIC[88]<=0.00000 ? CONSTANTS[109] : ALGEBRAIC[88]<=1.00000 ? pow(CONSTANTS[109], ALGEBRAIC[88]) : 1.00000);
    RATES[6] =  CONSTANTS[110]*(CONSTANTS[30] - STATES[6])*STATES[11] -  CONSTANTS[111]*exp( - CONSTANTS[27]*STATES[6])*ALGEBRAIC[89]*STATES[6];
    RATES[28] =  CONSTANTS[113]*(CONSTANTS[112] - STATES[28])*STATES[11] -  CONSTANTS[114]*STATES[28];
    RATES[29] =  CONSTANTS[116]*(CONSTANTS[115] - STATES[29])*STATES[11] -  CONSTANTS[117]*STATES[29];
    RATES[11] =  - 1.00000/( 2.00000*1.00000*CONSTANTS[131]*CONSTANTS[47])*(ALGEBRAIC[66]+ALGEBRAIC[78] -  2.00000/(CONSTANTS[80] - 2.00000)*ALGEBRAIC[81])+ STATES[17]*CONSTANTS[104]*CONSTANTS[108]+ ALGEBRAIC[87]*CONSTANTS[105]/CONSTANTS[103] - RATES[6] - RATES[28] - RATES[29] - ALGEBRAIC[85];
}

void Test_Cell::computeVariables(double VOI, double *CONSTANTS, double *RATES, double *STATES, double *ALGEBRAIC)
{
    ALGEBRAIC[3] = STATES[0];
    ALGEBRAIC[4] = 50.0000/(1.00000+exp(- (STATES[7] - 5.00000)/9.00000));
    ALGEBRAIC[16] =  0.0500000*exp(- (STATES[7] - 20.0000)/15.0000);
    ALGEBRAIC[5] = 50.0000/(1.00000+exp(- (STATES[7] - 5.00000)/9.00000));
    ALGEBRAIC[17] =  0.400000*exp(- pow((STATES[7]+30.0000)/30.0000, 3.00000));
    ALGEBRAIC[6] = 14.0000/(1.00000+exp(- (STATES[7] - 40.0000)/9.00000));
    ALGEBRAIC[18] =  1.00000*exp(- STATES[7]/45.0000);
    ALGEBRAIC[8] =  20.0000*exp( - 0.125000*(STATES[7]+75.0000));
    ALGEBRAIC[20] = 2000.00/(1.00000+ 320.000*exp( - 0.100000*(STATES[7]+75.0000)));
    ALGEBRAIC[11] =  0.0330000*exp(- STATES[7]/17.0000);
    ALGEBRAIC[23] = 33.0000/(1.00000+exp( - 0.125000*(STATES[7]+10.0000)));
    ALGEBRAIC[14] =  CONSTANTS[119]*(STATES[30]+20.0000)+ CONSTANTS[121]*(STATES[30] - CONSTANTS[122]);
    ALGEBRAIC[25] =  - CONSTANTS[118]*(STATES[7] - STATES[30]);
    ALGEBRAIC[7] = STATES[7]+41.0000;
    ALGEBRAIC[19] = (fabs(ALGEBRAIC[7])<CONSTANTS[60] ? 2000.00 :  200.000*ALGEBRAIC[7]/(1.00000 - exp( - 0.100000*ALGEBRAIC[7])));
    ALGEBRAIC[27] =  8000.00*exp( - 0.0560000*(STATES[7]+66.0000));
    ALGEBRAIC[9] = STATES[7]+24.0000 - 5.00000;
    ALGEBRAIC[21] = (fabs(ALGEBRAIC[9])<0.000100000 ? 120.000 :  30.0000*ALGEBRAIC[9]/(1.00000 - exp(- ALGEBRAIC[9]/4.00000)));
    ALGEBRAIC[28] = (fabs(ALGEBRAIC[9])<0.000100000 ? 120.000 :  12.0000*ALGEBRAIC[9]/(exp(ALGEBRAIC[9]/10.0000) - 1.00000));
    ALGEBRAIC[10] = STATES[7]+34.0000;
    ALGEBRAIC[22] = (fabs(ALGEBRAIC[10])<CONSTANTS[72] ? 25.0000 :  6.25000*ALGEBRAIC[10]/(exp(ALGEBRAIC[10]/4.00000) - 1.00000));
    ALGEBRAIC[29] = 12.0000/(1.00000+exp( - 1.00000*(STATES[7]+34.0000)/4.00000));
    ALGEBRAIC[13] = STATES[11]/(STATES[11]+CONSTANTS[97]);
    ALGEBRAIC[24] = STATES[17]/(STATES[17]+CONSTANTS[98]);
    ALGEBRAIC[30] = ALGEBRAIC[13]+ (1.00000 - ALGEBRAIC[13])*ALGEBRAIC[24];
    ALGEBRAIC[34] = 60.0000+ 500.000*pow(ALGEBRAIC[30], 2.00000);
    ALGEBRAIC[36] = (STATES[7]<- 50.0000 ? 5.00000 : 1.00000);
    ALGEBRAIC[32] =  500.000*pow(ALGEBRAIC[30], 2.00000);
    ALGEBRAIC[38] = 1.00000 - STATES[26] - STATES[27];
    ALGEBRAIC[51] = (STATES[2]<=STATES[0] ?  CONSTANTS[42]*exp( CONSTANTS[41]*(STATES[4] - STATES[3])) :  CONSTANTS[44]*exp( CONSTANTS[43]*(STATES[4] - STATES[3])));
    ALGEBRAIC[37] = STATES[4]+STATES[5];
    ALGEBRAIC[15] =  CONSTANTS[6]*(exp( CONSTANTS[5]*STATES[5]) - 1.00000);
    ALGEBRAIC[26] = ALGEBRAIC[15];
    ALGEBRAIC[40] = (CONSTANTS[0]==1.00000&&ALGEBRAIC[26]>CONSTANTS[17]&&ALGEBRAIC[37]<= CONSTANTS[18]*(1.00000+0.000100000) ? 1.00000 : 0.00000);
    ALGEBRAIC[47] = (ALGEBRAIC[40]==1.00000 ?  CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*STATES[0]/( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])) :  CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))*STATES[0]/( CONSTANTS[1]*CONSTANTS[2]*exp( CONSTANTS[1]*(STATES[4] - STATES[3]))+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])+ CONSTANTS[5]*CONSTANTS[6]*exp( CONSTANTS[5]*STATES[5])));
    ALGEBRAIC[54] = (ALGEBRAIC[51]==0.00000 ? ALGEBRAIC[47] : STATES[2]);
    ALGEBRAIC[55] = (ALGEBRAIC[40]==1.00000 ? 0.00000 : ALGEBRAIC[40]==0.00000&&ALGEBRAIC[51]==0.00000 ? - ALGEBRAIC[47] : ALGEBRAIC[40]==0.00000&&ALGEBRAIC[51] != 0.00000 ? - STATES[2] : 0.0/0.0);
    ALGEBRAIC[31] =  pow(STATES[6]/CONSTANTS[30], CONSTANTS[8])*(1.00000+pow(CONSTANTS[9], CONSTANTS[8]))/(pow(STATES[6]/CONSTANTS[30], CONSTANTS[8])+pow(CONSTANTS[9], CONSTANTS[8]));
    ALGEBRAIC[33] = ( CONSTANTS[31]*STATES[3]+CONSTANTS[32]<0.00000 ? 0.00000 :  CONSTANTS[31]*STATES[3]+CONSTANTS[32]<1.00000 ?  CONSTANTS[31]*STATES[3]+CONSTANTS[32] : 1.00000);
    ALGEBRAIC[35] = (STATES[3]>0.550000 ? (STATES[3]+CONSTANTS[20])/(0.460000+CONSTANTS[20]) :  (CONSTANTS[20]+0.550000)*1.00000);
    ALGEBRAIC[2] = (STATES[0]<=0.00000 ? CONSTANTS[21] -  CONSTANTS[22]*STATES[0]/CONSTANTS[13] : STATES[0]<=CONSTANTS[123]&&0.00000<STATES[0] ?  (CONSTANTS[24] - CONSTANTS[23])*STATES[0]/CONSTANTS[123]+CONSTANTS[23] : CONSTANTS[24]/pow(1.00000+ CONSTANTS[29]*(STATES[0] - CONSTANTS[123])/CONSTANTS[13], CONSTANTS[28]));
    ALGEBRAIC[53] = (STATES[0]<=0.00000 ?  CONSTANTS[14]*(1.00000+STATES[0]/CONSTANTS[13])/(CONSTANTS[14] - STATES[0]/CONSTANTS[13]) : 1.00000+CONSTANTS[15] -  pow(CONSTANTS[15], 2.00000)*CONSTANTS[14]/(  CONSTANTS[14]*CONSTANTS[15]/CONSTANTS[130]*pow(STATES[0]/CONSTANTS[13], 2.00000)+ (CONSTANTS[14]+1.00000)*STATES[0]/CONSTANTS[13]+ CONSTANTS[14]*CONSTANTS[15]));
    ALGEBRAIC[57] = (- CONSTANTS[13]<=STATES[0]&&STATES[0]<=0.00000 ? 1.00000+ 0.600000*STATES[0]/CONSTANTS[13] : 0.00000<STATES[0]&&STATES[0]<=CONSTANTS[124] ? ALGEBRAIC[53]/( ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13])+1.00000) :  ALGEBRAIC[53]*exp( - CONSTANTS[26]*pow((STATES[0] - CONSTANTS[124])/CONSTANTS[13], CONSTANTS[16]))/( ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13])+1.00000));
    ALGEBRAIC[59] =  CONSTANTS[10]*CONSTANTS[11]*ALGEBRAIC[2]*CONSTANTS[12]*ALGEBRAIC[57];
    ALGEBRAIC[61] =  CONSTANTS[11]*ALGEBRAIC[2]*(1.00000 -  CONSTANTS[10]*CONSTANTS[12]*ALGEBRAIC[57]);
    ALGEBRAIC[63] =  ALGEBRAIC[59]*ALGEBRAIC[31]*ALGEBRAIC[33]*ALGEBRAIC[35]*(1.00000 - STATES[1]) -  ALGEBRAIC[61]*STATES[1];
    ALGEBRAIC[44] = (STATES[0]<=0.00000 ?  CONSTANTS[38]*exp( CONSTANTS[37]*STATES[3]) :  CONSTANTS[40]*exp( CONSTANTS[39]*STATES[3]));
    ALGEBRAIC[69] = ALGEBRAIC[53]/ALGEBRAIC[57];
    ALGEBRAIC[65] =  CONSTANTS[14]*1.00000*(1.00000+ 0.400000*CONSTANTS[14]+ 1.20000*STATES[0]/CONSTANTS[13]+ 0.600000*pow(STATES[0]/CONSTANTS[13], 2.00000))/( CONSTANTS[13]*pow( (CONSTANTS[14] - STATES[0]/CONSTANTS[13])*(1.00000+ 0.600000*STATES[0]/CONSTANTS[13]), 2.00000));
    ALGEBRAIC[67] =  1.00000/CONSTANTS[13]*exp( - CONSTANTS[26]*pow(STATES[0]/CONSTANTS[13] - CONSTANTS[124]/CONSTANTS[13], CONSTANTS[16]))*(( 0.400000*CONSTANTS[14]+1.00000)/CONSTANTS[14]+ CONSTANTS[26]*CONSTANTS[16]*(1.00000+ ( 0.400000*CONSTANTS[14]+1.00000)*STATES[0]/( CONSTANTS[14]*CONSTANTS[13]))*pow(STATES[0]/CONSTANTS[13] - CONSTANTS[124]/CONSTANTS[13], CONSTANTS[16] - 1.00000));
    ALGEBRAIC[72] = (STATES[0]<=- CONSTANTS[13] ? CONSTANTS[125] : - CONSTANTS[13]<STATES[0]&&STATES[0]<=0.00000 ? ALGEBRAIC[65] : 0.00000<STATES[0]&&STATES[0]<=CONSTANTS[124] ? CONSTANTS[126] : ALGEBRAIC[67]);
    ALGEBRAIC[42] = (STATES[0]<=0.00000 ? CONSTANTS[37] : CONSTANTS[39]);
    ALGEBRAIC[74] = (ALGEBRAIC[40]==1.00000 ? - ( CONSTANTS[7]*ALGEBRAIC[63]*ALGEBRAIC[69]+ ALGEBRAIC[42]*ALGEBRAIC[44]*pow(STATES[0], 2.00000)+ CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])*STATES[2])/( CONSTANTS[7]*STATES[1]*ALGEBRAIC[72]+ALGEBRAIC[44]) : - ( CONSTANTS[7]*ALGEBRAIC[63]*ALGEBRAIC[69]+ ALGEBRAIC[42]*ALGEBRAIC[44]*pow(STATES[0], 2.00000)+ ( CONSTANTS[3]*CONSTANTS[4]*exp( CONSTANTS[3]*STATES[4])+ CONSTANTS[5]*CONSTANTS[6]*exp( CONSTANTS[5]*STATES[5]))*STATES[2])/( CONSTANTS[7]*STATES[1]*ALGEBRAIC[72]+ALGEBRAIC[44]));
    ALGEBRAIC[49] = (STATES[2]<=STATES[0] ? CONSTANTS[41] : CONSTANTS[43]);
    ALGEBRAIC[43] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(STATES[8]/STATES[9]);
    ALGEBRAIC[52] =   CONSTANTS[53]*STATES[8]/(STATES[8]+CONSTANTS[52])*(STATES[7] - ALGEBRAIC[43])/(1.00000+exp( (STATES[7] - ALGEBRAIC[43] - 10.0000)*CONSTANTS[47]*1.25000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[79] =  CONSTANTS[74]*(CONSTANTS[75]+ STATES[22]*(1.00000 - CONSTANTS[75]))*STATES[23]*(STATES[7] - ALGEBRAIC[43]);
    ALGEBRAIC[56] =   ( CONSTANTS[54]*STATES[12]+ CONSTANTS[55]*STATES[13])*1.00000/(1.00000+exp((STATES[7]+9.00000)/22.4000))*(STATES[7] - ALGEBRAIC[43]);
    ALGEBRAIC[46] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log((STATES[8]+ CONSTANTS[49]*CONSTANTS[50])/(STATES[9]+ CONSTANTS[49]*STATES[10]));
    ALGEBRAIC[58] =  CONSTANTS[56]*pow(STATES[14], 2.00000)*(STATES[7] - ALGEBRAIC[46]);
    ALGEBRAIC[68] =   (1.00000 - CONSTANTS[69])*CONSTANTS[64]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[9]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  STATES[8]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[75] =   CONSTANTS[69]*CONSTANTS[64]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[9]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  STATES[8]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[80] =   CONSTANTS[76]*STATES[8]/(CONSTANTS[77]+STATES[8])*STATES[10]/(CONSTANTS[78]+STATES[10]);
    ALGEBRAIC[50] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log((CONSTANTS[50]+ 0.120000*STATES[8])/(STATES[10]+ 0.120000*STATES[9]));
    ALGEBRAIC[60] =  CONSTANTS[59]*pow(STATES[15], 3.00000)*STATES[16]*(STATES[7] - ALGEBRAIC[50]);
    ALGEBRAIC[41] =   CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(CONSTANTS[50]/STATES[10]);
    ALGEBRAIC[64] =  CONSTANTS[62]*(STATES[7] - ALGEBRAIC[41]);
    ALGEBRAIC[62] =   CONSTANTS[61]*1.00000/(1.00000+exp(- (STATES[7]+52.0000)/8.00000))*(STATES[7] - ALGEBRAIC[41]);
    ALGEBRAIC[70] =   (1.00000 - CONSTANTS[69])*CONSTANTS[65]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[10]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[50]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[76] =   CONSTANTS[69]*CONSTANTS[65]*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[10]*exp( 50.0000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[50]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[81] =  (1.00000 - CONSTANTS[83])*CONSTANTS[79]*( exp( CONSTANTS[82]*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(STATES[10], CONSTANTS[80])*CONSTANTS[51] -  exp( (CONSTANTS[82] - 1.00000)*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(CONSTANTS[50], CONSTANTS[80])*STATES[11])/( (1.00000+ CONSTANTS[81]*( STATES[11]*pow(CONSTANTS[50], CONSTANTS[80])+ CONSTANTS[51]*pow(STATES[10], CONSTANTS[80])))*(1.00000+STATES[11]/0.00690000));
    ALGEBRAIC[82] =  CONSTANTS[83]*CONSTANTS[79]*( exp( CONSTANTS[82]*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(STATES[10], CONSTANTS[80])*CONSTANTS[51] -  exp( (CONSTANTS[82] - 1.00000)*(CONSTANTS[80] - 2.00000)*STATES[7]*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46]))*pow(CONSTANTS[50], CONSTANTS[80])*STATES[17])/( (1.00000+ CONSTANTS[81]*( STATES[17]*pow(CONSTANTS[50], CONSTANTS[80])+ CONSTANTS[51]*pow(STATES[10], CONSTANTS[80])))*(1.00000+STATES[17]/0.00690000));
    ALGEBRAIC[66] =   (1.00000 - CONSTANTS[69])*4.00000*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[20]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[11]*exp( 100.000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[51]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[73] =   CONSTANTS[69]*4.00000*CONSTANTS[63]*STATES[18]*STATES[19]*STATES[21]*(STATES[7] - 50.0000)*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])/(1.00000 - exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])))*( STATES[11]*exp( 100.000*CONSTANTS[47]/( CONSTANTS[45]*CONSTANTS[46])) -  CONSTANTS[51]*exp( - (STATES[7] - 50.0000)*CONSTANTS[47]*2.00000/( CONSTANTS[45]*CONSTANTS[46])));
    ALGEBRAIC[48] =   0.500000*CONSTANTS[45]*CONSTANTS[46]/CONSTANTS[47]*log(CONSTANTS[51]/STATES[11]);
    ALGEBRAIC[78] =  CONSTANTS[73]*(STATES[7] - ALGEBRAIC[48]);
    ALGEBRAIC[39] = (VOI>=CONSTANTS[33]&&VOI<=CONSTANTS[34]&&VOI - CONSTANTS[33] -  floor((VOI - CONSTANTS[33])/CONSTANTS[19])*CONSTANTS[19]<=CONSTANTS[35] ? CONSTANTS[36] : 0.00000);
    ALGEBRAIC[84] = ALGEBRAIC[81]+ALGEBRAIC[82];
    ALGEBRAIC[83] = STATES[11]+ STATES[24]*CONSTANTS[128]+ CONSTANTS[84]*CONSTANTS[85]+CONSTANTS[84];
    ALGEBRAIC[85] = (CONSTANTS[89]==0.00000 ?  STATES[11]/ALGEBRAIC[83]*CONSTANTS[87] -   STATES[24]*CONSTANTS[128]/ALGEBRAIC[83]*CONSTANTS[88] :  STATES[11]/ALGEBRAIC[83]*CONSTANTS[87]/(1.00000+STATES[24]/CONSTANTS[90]) -   STATES[24]*CONSTANTS[128]/ALGEBRAIC[83]*CONSTANTS[88]);
    ALGEBRAIC[86] =  CONSTANTS[91]*(STATES[24] - STATES[25]);
    ALGEBRAIC[87] =  ( pow(STATES[26]/(STATES[26]+0.250000), 2.00000)*CONSTANTS[96]+CONSTANTS[95])*STATES[25];
    ALGEBRAIC[88] =  CONSTANTS[30]*STATES[1]/( ALGEBRAIC[35]*STATES[6]);
    ALGEBRAIC[89] = (ALGEBRAIC[88]<=0.00000 ? CONSTANTS[109] : ALGEBRAIC[88]<=1.00000 ? pow(CONSTANTS[109], ALGEBRAIC[88]) : 1.00000);
    ALGEBRAIC[0] =  CONSTANTS[2]*(exp( CONSTANTS[1]*(STATES[4] - STATES[3])) - 1.00000);
    ALGEBRAIC[1] =  CONSTANTS[4]*(exp( CONSTANTS[3]*STATES[4]) - 1.00000);
    ALGEBRAIC[12] = exp( 0.0800000*(STATES[7] - 40.0000));
    ALGEBRAIC[45] =   CONSTANTS[57]*STATES[10]/(STATES[10]+CONSTANTS[58])*(STATES[7] - ALGEBRAIC[43]);
    ALGEBRAIC[71] =  CONSTANTS[7]*ALGEBRAIC[69]*STATES[1];
    ALGEBRAIC[77] = ALGEBRAIC[66]+ALGEBRAIC[68]+ALGEBRAIC[70]+ALGEBRAIC[73]+ALGEBRAIC[75]+ALGEBRAIC[76];
}