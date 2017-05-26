
//
//  main.c
//  sample
//
//  Created by Lloyd Fernandes and Calvin Menezes
//  Copyright © 2017. All rights reserved.
//


/*WINDOWS HEADERS*/
//#include<stdio.h>
//#include<GL/gl.h>
//#include<GL/glut.h>
//#include<windows.h>
//#include<math.h>

/*MAC HEADERS*/
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<OpenGL/glext.h>
#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>


double tyme=0;
GLfloat goombaX=415;
GLint goombaRight=1;    //goombaRight=1 indicates that he's moving in the Right direction, 0 indicates left

GLfloat goomba1X=252;
GLint goomba1Right=1;    //goombaRight=1 indicates that he's moving in the Right direction, 0 indicates left
GLfloat goomba2X=284;
GLint goomba2Right=1;

float i=180;            //Initial Angle before jumping
GLfloat marioX=70,marioY=40,marioZ=0;
GLint marioUp=0,marioHoriz=1;    //marioUp=0 indicates Mario is moving horizontally

GLfloat mushX=374,mushY=120,mushZ=0;
GLint mushMove=0;

int coinFLAG=0;

GLint x1=255,x2=255,x3=255;
GLint groundx=230,groundy=95,groundz=19;
GLint brickx=230,bricky=95,brickz=19;
int next=0;
void (*scenePointer)();
GLfloat flagMove=274;



void drawCoin()
{
        glColor3ub(0, 0, 0);
        glRectf(264,67,519,8); //BLACK BORDER
        glRectf(137,133,264,67);
        glRectf(519,132,647,69);
        glRectf(73,324,137,133);
        glRectf(328,260,456,196);
        glRectf(646,260,710,132);
        glRectf(455,770,519,260);
        glRectf(710,770,773,260);
        glRectf(647,898,710,770);
        glRectf(456,961,647,898);
        glRectf(328,1025,520,961);
        glRectf(201,961,328,897);
        glRectf(137,897,201,833);
        glRectf(73,833,135,707);
        glRectf(11,706,73,324);

        glColor3ub(255, 255, 255);
        glRectf(262,260,326,769); //WHITE REFLECTION
        glRectf(73,324,137,707);
        glRectf(135,770,201,833);
        glRectf(201,833,264,897);
        glRectf(264,897,264,897);
        glRectf(328,898,456,961);
        glRectf(326,770,457,834);

        glColor3ub(173, 127, 49);
        glRectf(265,133,519,70);  //BROWN SHADE
        glRectf(520,197,647,133);
        glRectf(584,258,646,196);
        glRectf(647,771,710,260);
        glRectf(584,898,647,771);

        glColor3ub(242, 186, 55);
        glRectf(137,769,199,133); //GOLDEN SHADE
        glRectf(137,196,519,133);
        glRectf(519,260,583,196);
        glRectf(583,771,647,261);
        glRectf(520,897,583,771);
        glRectf(265,898,583,835);
        glRectf(201,833,264,771);
        glRectf(329,387,455,261);
        glRectf(392,769,455,324);

        glColor3ub(247, 232, 51);
        glRectf(201,770,265,197); //BRIGHT YELLOW
        glRectf(262,258,328,196);
        glRectf(264,834,328,769);
        glRectf(328,769,392,388);
        glRectf(456,834,520,771);
        glRectf(520,771,583,260);
        glRectf(455,260,520,197);

}




void drawPipe()
{
        glColor3ub(0, 0, 0);
        glRectf(13,821,997,401); //PIPE SHAPE
        glRectf(70,406,941,8);

        glColor3ub(130, 206, 44);
        glRectf(44,793,966,429); //LIGHT GREEN FILL
        glRectf(98,371,911,9);

        glColor3ub(23, 166, 27);
        glRectf(182,9,268,371); //PIPE TEXTURE
        glRectf(380,8,436,370);
        glRectf(464,9,745,371);
        glRectf(771,9,829,371);
        glRectf(855,9,883,371);
        glRectf(42,737,184,766);
        glRectf(126,743,182,431);
        glRectf(350,766,380,429);
        glRectf(436,766,771,431);
        glRectf(799,765,842,429);
        glRectf(872,766,901,431);
}




void drawGoomba()
{
        glColor3ub(0, 0, 0);
        glRectf(96,86,294,8); //SHOES
        glRectf(55,128,295,47);
        glRectf(94,167,254,128);
        glRectf(374,88,574,8);
        glRectf(413,128,613,48);
        glRectf(454,167,574,128);

        glColor3ub(216, 186, 127);
        glRectf(175,247,492,130); //BODY
        glRectf(255,128,413,90);

        glColor3ub(230, 94, 23);
        glRectf(15,247,653,366); //FACE
        glRectf(55,208,214,446);
        glRectf(453,207,613,446);
        glRectf(254,646,413,446);
        glRectf(215,606,255,407);
        glRectf(374,605,453,446);
        glRectf(254,566,176,407);
        glRectf(414,566,493,407);
        glRectf(173,527,134,446);
        glRectf(134,486,94,446);
        glRectf(455,526,533,406);
        glRectf(495,487,573,407);
        glRectf(574,446,613,406);
        glRectf(155,507,526,263);

        glColor3ub(223, 223, 223);
        glRectf(174,287,294,366); //EYES
        glRectf(175,367,240,446);
        glRectf(375,288,493,367);
        glRectf(423,367,493,446);

        glColor3ub(0, 0, 0);
        glRectf(134,487,214,447); //EYEBROWS
        glRectf(214,447,254,327);
        glRectf(533,486,454,446);
        glRectf(454,446,413,327);

}




void drawMushroom()
{
        GLfloat val[56]={183,27,183,65,492,65,493,27,182,66,183,104,143,103,143,66,493,66,532,65,533,104,492,104};
        GLfloat ptmsh[12][2];
        int i,j,k=0;
        for(i=0;i<24;i++)
                for(j=0;j<2;j++)
                {
                        ptmsh[i][j]=val[k];
                        k++;
                }
        glColor3ub(0, 0, 0); //BLACK BORDER
        glBegin(GL_POLYGON);
        for(i=0;i<4;i++)
                glVertex2fv(ptmsh[i]);
        glEnd();

        glBegin(GL_POLYGON);
        for(i=4;i<8;i++)
                glVertex2fv(ptmsh[i]);
        glEnd();

        glBegin(GL_POLYGON);
        for(i=8;i<12;i++)
                glVertex2fv(ptmsh[i]);
        glEnd();

        glRectf(105,186,144,104);
        glRectf(66,222,183,182);
        glRectf(183,258,492,221);
        glRectf(260,233,300,144);
        glRectf(377,236,415,143);
        glRectf(492,221,609,182);
        glRectf(532,194,571,104);
        glRectf(30,453,67,221);
        glRectf(610,453,647,221);
        glRectf(66,531,106,453);
        glRectf(571,530,610,453);
        glRectf(105,569,144,530);
        glRectf(532,569,571,530);
        glRectf(144,607,221,569);
        glRectf(454,606,532,569);
        glRectf(221,645,454,606);

        glColor3ub(226, 32, 44); //RED FILLING
        glRectf(68,258,182,221);
        glRectf(494,258,609,221);
        glRectf(67,453,607,258);
        glRectf(106,530,571,444);
        glRectf(145,569,532,526);
        glRectf(223,607,454,559);

        glColor3ub(255, 255, 255); //WHITE FACE
        glRectf(183,143,493,66);
        glRectf(146,182,222,104);
        glRectf(184,221,261,104);
        glRectf(301,220,377,105);
        glRectf(416,218,492,104);
        glRectf(493,182,531,105);

        glColor3ub(255, 255, 255); //WHITE SPOTS
        glRectf(68,375,106,221);
        glRectf(95,337,144,260);
        glRectf(183,452,415,337);
        glRectf(222,492,376,298);
        glRectf(454,375,607,297);
        glRectf(493,413,571,260);
        glRectf(106,530,144,453);
        glRectf(134,530,182,492);
        glRectf(145,569,222,531);
        glRectf(377,606,454,531);
        glRectf(415,531,492,492);
        glRectf(454,567,532,492);
        glRectf(454,491,570,453);
        glRectf(532,530,571,452);
}




void drawMario()
{
        //Values used for making the mario, array "PTM" means "Points Mario"
        GLfloat ptm[118][2]={{64,377},{64,401},{88,401},{88,424},{232,424},{232,400},{305,401},{304,377},{65,376},{64,280},{88,280},{88,257},{280,257},{281,279},{304,280},{305,304},{328,305},{329,329},{305,329},{305,352},{257,353},{257,376},{64,377},{64,353},{88,352},{89,304},{136,305},{137,329},{112,330},{112,353},{136,352},{137,377},{40,353},{40,281},{88,280},{89,305},{64,304},{64,352},{208,377},{208,329},{232,329},{233,377},{207,281},{208,305},{232,305},{232,329},{256,330},{257,305},{304,305},{304,280},{64,257},{232,257},{232,232},{280,233},{280,208},{304,209},{305,185},{256,185},{256,161},{65,161},{64,185},{16,185},{16,209},{40,209},{40,233},{64,233},{112,256},{113,184},{88,185},{89,137},{64,137},{65,89},{136,89},{137,113},{184,113},{184,89},{256,89},{257,137},{233,137},{233,185},{208,185},{208,232},{184,233},{184,209},{136,209},{137,257},{112,184},{136,161},{184,185},{208,161},{16,185},{16,113},{64,113},{64,137},{88,137},{88,161},{64,161},{64,185},{233,161},{256,160},{256,185},{304,185},{304,113},{257,112},{256,137},{233,137},{16,41},{113,41},{112,89},{40,89},{40,65},{16,65},{208,41},{208,89},{281,89},{281,65},{305,65},{305,41}};

        glBegin(GL_POLYGON);
        glColor3ub(181,50,32); //THE HAT
        glVertex2fv(ptm[0]);
        glVertex2fv(ptm[1]);
        glVertex2fv(ptm[2]);
        glVertex2fv(ptm[3]);
        glVertex2fv(ptm[4]);
        glVertex2fv(ptm[5]);
        glVertex2fv(ptm[6]);
        glVertex2fv(ptm[7]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(234,159,34); //COMPLEXION FACE
        glVertex2fv(ptm[8]);
        glVertex2fv(ptm[9]);
        glVertex2fv(ptm[10]);
        glVertex2fv(ptm[11]);
        glVertex2fv(ptm[12]);
        glVertex2fv(ptm[13]);
        glVertex2fv(ptm[14]);
        glVertex2fv(ptm[15]);
        glVertex2fv(ptm[16]);
        glVertex2fv(ptm[17]);
        glVertex2fv(ptm[18]);
        glVertex2fv(ptm[19]);
        glVertex2fv(ptm[20]);
        glVertex2fv(ptm[21]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //SIDE BURNS
        glVertex2fv(ptm[22]);
        glVertex2fv(ptm[23]);
        glVertex2fv(ptm[24]);
        glVertex2fv(ptm[25]);
        glVertex2fv(ptm[26]);
        glVertex2fv(ptm[27]);
        glVertex2fv(ptm[28]);
        glVertex2fv(ptm[29]);
        glVertex2fv(ptm[30]);
        glVertex2fv(ptm[31]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //HAIR BEHIND
        glVertex2fv(ptm[32]);
        glVertex2fv(ptm[33]);
        glVertex2fv(ptm[34]);
        glVertex2fv(ptm[35]);
        glVertex2fv(ptm[36]);
        glVertex2fv(ptm[37]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //EYE
        glVertex2fv(ptm[38]);
        glVertex2fv(ptm[39]);
        glVertex2fv(ptm[40]);
        glVertex2fv(ptm[41]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //STACHE
        glVertex2fv(ptm[42]);
        glVertex2fv(ptm[43]);
        glVertex2fv(ptm[44]);
        glVertex2fv(ptm[45]);
        glVertex2fv(ptm[46]);
        glVertex2fv(ptm[47]);
        glVertex2fv(ptm[48]);
        glVertex2fv(ptm[49]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //SHIRT
        glVertex2fv(ptm[50]);
        glVertex2fv(ptm[51]);
        glVertex2fv(ptm[52]);
        glVertex2fv(ptm[53]);
        glVertex2fv(ptm[54]);
        glVertex2fv(ptm[55]);
        glVertex2fv(ptm[56]);
        glVertex2fv(ptm[57]);
        glVertex2fv(ptm[58]);
        glVertex2fv(ptm[59]);
        glVertex2fv(ptm[60]);
        glVertex2fv(ptm[61]);
        glVertex2fv(ptm[62]);
        glVertex2fv(ptm[63]);
        glVertex2fv(ptm[64]);
        glVertex2fv(ptm[65]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(234,159,34); //HAND 1
        glVertex2fv(ptm[90]);
        glVertex2fv(ptm[91]);
        glVertex2fv(ptm[92]);
        glVertex2fv(ptm[93]);
        glVertex2fv(ptm[94]);
        glVertex2fv(ptm[95]);
        glVertex2fv(ptm[96]);
        glVertex2fv(ptm[97]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(234,159,34); //HAND 2
        glVertex2fv(ptm[98]);
        glVertex2fv(ptm[99]);
        glVertex2fv(ptm[100]);
        glVertex2fv(ptm[101]);
        glVertex2fv(ptm[102]);
        glVertex2fv(ptm[103]);
        glVertex2fv(ptm[104]);
        glVertex2fv(ptm[105]);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(181,50,32); //RED STRAPS
        glVertex2fv(ptm[66]);
        glVertex2fv(ptm[67]);
        glVertex2fv(ptm[68]);
        glVertex2fv(ptm[69]);
        glVertex2fv(ptm[70]);
        glVertex2fv(ptm[71]);
        glVertex2fv(ptm[72]);
        glVertex2fv(ptm[73]);
        glVertex2fv(ptm[74]);
        glVertex2fv(ptm[75]);
        glVertex2fv(ptm[76]);
        glVertex2fv(ptm[77]);
        glVertex2fv(ptm[78]);
        glVertex2fv(ptm[79]);
        glVertex2fv(ptm[80]);
        glVertex2fv(ptm[81]);
        glVertex2fv(ptm[82]);
        glVertex2fv(ptm[83]);
        glVertex2fv(ptm[84]);
        glVertex2fv(ptm[85]);
        glEnd();

        glColor3ub(234,159,34); //BUTTONS
        glRectf(112,184,136,161);
        glRectf(184,185,208,161);

        glBegin(GL_POLYGON);
        glColor3ub(107,109,0); //LEFT SHOE
        glVertex2fv(ptm[106]);
        glVertex2fv(ptm[107]);
        glVertex2fv(ptm[108]);
        glVertex2fv(ptm[109]);
        glVertex2fv(ptm[110]);
        glVertex2fv(ptm[111]);
        glEnd();
        glBegin(GL_POLYGON);

        glColor3ub(107,109,0); //RIGHT SHOE
        glVertex2fv(ptm[112]);
        glVertex2fv(ptm[113]);
        glVertex2fv(ptm[114]);
        glVertex2fv(ptm[115]);
        glVertex2fv(ptm[116]);
        glVertex2fv(ptm[117]);
        glEnd();
}




void drawMountain()
{
        GLfloat c[30]={11,95,
                85,21,
                96,21,
                96,17,
                110,16,
                110,12,
                133,10,
                135,16,
                149,16,
                149,20,
                159,21,
                233,94};

        GLfloat mnt[12][2];
        GLint i,j;
        GLint k=0;

        for(i=0;i<12;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)  //Odd indices of array 'c' are the Y coordinates which have to be correctly represented in
                                //the graphical system we use
                                c[k]=96-c[k];

                        mnt[i][j]=c[k]; //Store as Vertex Pair
                        k++;
                }

        glColor3ub(0,171,0);       //Draw the Mountain with color as green
        glBegin(GL_POLYGON);
        for(i=0;i<12;i++)
                glVertex2fv(mnt[i]);

        glEnd();

        glColor3f(0,0,0);
        glRectf(127,35,136,55);
        glRectf(141,50,156,70);

        glLineWidth(1.5);
        glBegin(GL_LINE_STRIP);
        for(i=0;i<12;i++)
                glVertex2fv(mnt[i]);
        glEnd();
}


void drawBush()
{
        
        glColor3ub(183,248,24);
        glRectf(204,645,419,249); //GREEN FILL
        glRectf(419,859,706,214);
        glRectf(706,214,1064,537);
        glRectf(686,788,849,537);
        glRectf(218,322,169,609);
        glRectf(167,360,131,572);
        glRectf(139,389,78,509);
        glRectf(96,428,59,501);
        glRectf(310,259,562,216);
        glRectf(346,214,527,179);
        glRectf(419,184,527,143);
        glRectf(527,216,562,179);
        glRectf(598,232,887,180);
        glRectf(670,186,814,143);
        glRectf(922,216,993,180);
        glRectf(1052,358,1101,251);
        glRectf(1087,322,1137,287);
        glRectf(1066,501,1101,430);
        glRectf(1101,430,1137,537);
        glRectf(849,609,922,537);
        glRectf(916,572,1030,537);
        glRectf(958,560,1028,609);
        glRectf(1028,609,993,643);
        glRectf(706,824,741,777);
        glRectf(779,824,814,773);
        glRectf(527,930,670,843);
        glRectf(491,897,714,855);
        glRectf(383,753,472,631);
        glRectf(417,716,346,633);
        glRectf(360,680,310,625);
        glRectf(834,680,885,590);
        glRectf(1050,430,1101,395);
        
        
        glColor3ub(61, 182, 31);   //Green Shade
        glRectf(202,393,240,358);
        glRectf(240,358,275,322);
        glRectf(275,322,419,287);
        glRectf(346,358,383,287);
        glRectf(383,287,598,251);
        glRectf(454,249,525,216);
        glRectf(527,322,598,277);
        glRectf(598,322,670,287);
        glRectf(598,358,633,322);
        glRectf(633,322,670,249);
        glRectf(670,249,814,285);
        glRectf(777,214,670,255);
        glRectf(812,320,849,287);
        glRectf(633,393,670,358);
        glRectf(456,680,489,716);
        glRectf(489,716,562,753);
        glRectf(633,788,668,753);
        glRectf(668,753,706,718);
        
        glColor3ub(0, 0, 0);
        glRectf(527,969,670,932); //BLACK BORDER
        glRectf(489,932,527,897);
        glRectf(419,895,491,861);
        glRectf(383,859,419,753);
        glRectf(348,753,383,718);
        glRectf(312,718,348,680);
        glRectf(204,680,310,645);
        glRectf(167,645,204,609);
        glRectf(131,609,167,572);
        glRectf(96,574,131,501);
        glRectf(59,537,98,501);
        glRectf(23,501,60,430);
        glRectf(60,430,96,395);
        glRectf(96,395,131,360);
        glRectf(131,360,167,322);
        glRectf(167,322,204,251);
        glRectf(204,251,310,216);
        glRectf(310,216,346,180);
        glRectf(346,180,419,143);
        glRectf(419,143,527,108);
        glRectf(525,179,562,143);
        glRectf(560,214,598,179);
        glRectf(598,179,670,143);
        glRectf(670,143,816,108);
        glRectf(814,179,885,143);
        glRectf(885,214,922,180);
        glRectf(922,180,995,143);
        glRectf(993,216,1066,179);
        glRectf(1066,251,1137,216);
        glRectf(1101,287,1139,249);
        glRectf(1139,320,1174,287);
        glRectf(1139,320,1101,358);
        glRectf(1101,358,1064,393);
        glRectf(1174,395,1101,430);
        glRectf(1176,395,1137,537);
        glRectf(1137,537,1103,572);
        glRectf(1101,501,1066,537);
        glRectf(1066,537,1030,645);
        glRectf(1030,645,995,682);
        glRectf(995,609,958,645);
        glRectf(958,574,922,609);
        glRectf(922,609,887,680);
        glRectf(887,680,851,788);
        glRectf(851,788,814,824);
        glRectf(814,824,779,861);
        glRectf(779,788,741,824);
        glRectf(741,824,708,895);
        glRectf(708,895,670,932);
        
}


void drawCloud()
{

        glColor3ub(252,252,252);
        glRectf(204,645,419,249); //WHITE FILL
        glRectf(419,859,706,214);
        glRectf(706,214,1064,537);
        glRectf(686,788,849,537);
        glRectf(218,322,169,609);
        glRectf(167,360,131,572);
        glRectf(139,389,78,509);
        glRectf(96,428,59,501);
        glRectf(310,259,562,216);
        glRectf(346,214,527,179);
        glRectf(419,184,527,143);
        glRectf(527,216,562,179);
        glRectf(598,232,887,180);
        glRectf(670,186,814,143);
        glRectf(922,216,993,180);
        glRectf(1052,358,1101,251);
        glRectf(1087,322,1137,287);
        glRectf(1066,501,1101,430);
        glRectf(1101,430,1137,537);
        glRectf(849,609,922,537);
        glRectf(916,572,1030,537);
        glRectf(958,560,1028,609);
        glRectf(1028,609,993,643);
        glRectf(706,824,741,777);
        glRectf(779,824,814,773);
        glRectf(527,930,670,843);
        glRectf(491,897,714,855);
        glRectf(383,753,472,631);
        glRectf(417,716,346,633);
        glRectf(360,680,310,625);
        glRectf(834,680,885,590);
        glRectf(1050,430,1101,395);

        
        glColor3ub(68, 189, 249);   //Blue Shade
        glRectf(202,393,240,358);
        glRectf(240,358,275,322);
        glRectf(275,322,419,287);
        glRectf(346,358,383,287);
        glRectf(383,287,598,251);
        glRectf(454,249,525,216);
        glRectf(527,322,598,277);
        glRectf(598,322,670,287);
        glRectf(598,358,633,322);
        glRectf(633,322,670,249);
        glRectf(670,249,814,285);
        glRectf(777,214,670,255);
        glRectf(812,320,849,287);
        glRectf(633,393,670,358);
        glRectf(456,680,489,716);
        glRectf(489,716,562,753);
        glRectf(633,788,668,753);
        glRectf(668,753,706,718);

        glColor3ub(0, 0, 0);
        glRectf(527,969,670,932); //BLACK BORDER
        glRectf(489,932,527,897);
        glRectf(419,895,491,861);
        glRectf(383,859,419,753);
        glRectf(348,753,383,718);
        glRectf(312,718,348,680);
        glRectf(204,680,310,645);
        glRectf(167,645,204,609);
        glRectf(131,609,167,572);
        glRectf(96,574,131,501);
        glRectf(59,537,98,501);
        glRectf(23,501,60,430);
        glRectf(60,430,96,395);
        glRectf(96,395,131,360);
        glRectf(131,360,167,322);
        glRectf(167,322,204,251);
        glRectf(204,251,310,216);
        glRectf(310,216,346,180);
        glRectf(346,180,419,143);
        glRectf(419,143,527,108);
        glRectf(525,179,562,143);
        glRectf(560,214,598,179);
        glRectf(598,179,670,143);
        glRectf(670,143,816,108);
        glRectf(814,179,885,143);
        glRectf(885,214,922,180);
        glRectf(922,180,995,143);
        glRectf(993,216,1066,179);
        glRectf(1066,251,1137,216);
        glRectf(1101,287,1139,249);
        glRectf(1139,320,1174,287);
        glRectf(1139,320,1101,358);
        glRectf(1101,358,1064,393);
        glRectf(1174,395,1101,430);
        glRectf(1176,395,1137,537);
        glRectf(1137,537,1103,572);
        glRectf(1101,501,1066,537);
        glRectf(1066,537,1030,645);
        glRectf(1030,645,995,682);
        glRectf(995,609,958,645);
        glRectf(958,574,922,609);
        glRectf(922,609,887,680);
        glRectf(887,680,851,788);
        glRectf(851,788,814,824);
        glRectf(814,824,779,861);
        glRectf(779,788,741,824);
        glRectf(741,824,708,895);
        glRectf(708,895,670,932);

}




void drawGroundBricks()
{
        //draw and fill Color for the square
        glColor3ub(groundx,groundy,groundz);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(20,0);
        glVertex2f(20,20);
        glVertex2f(0,20);
        glEnd();

        glLineWidth(2.4);
        //Black Shade on Bottom and Right edge
        glColor3f(0,0,0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,0);
        glVertex2f(20,0);
        glVertex2f(20,20);
        glEnd();

        //White Shade  on Top and Left edge
        glColor3ub(251,188,177);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,0);
        glVertex2f(0,20);
        glVertex2f(20,20);
        glEnd();

        //Interior Black Shade lines
        glColor3f(0,0,0);
        GLfloat b[50]={3,277,
                9,277,
                17,277,
                49,276,
                58,278,
                57,297,
                98,297,
                109,298,
                110,322,
                195,321,
                224,321,
                223,271,
                250,271,
                249,34,
                250,146,
                385,146,
                250,146,
                250,0
        };

        GLfloat line[18][2];
        GLint i,j;
        GLint k=0;

        for(i=0;i<18;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)      //Y coordinate Transformation
                                b[k]=420-b[k];
                        line[i][j]=( b[k] * (.0476) );  //Scaled from size 420 to 20. Hence the scaling factor
                        k++;
                }

        glLineWidth(2);
        glBegin(GL_LINE_STRIP); //Draw the lines
        for(i=0;i<18;i++)
                glVertex2fv(line[i]);
        glEnd();



        //Interior white shading Line
        glColor3ub(251,188,177);
        GLfloat b1[50]={34,303,
                47,303,
                47,326,
                98,327,
                97,355,
                223,356,
                223,325,
                253,325,
                252,272,
                274,272,
                274,170,
                381,168,
                273,171,
                272,39,
                272,0
        };
        //Concept is same as the one used in White shading Line
        GLfloat line1[15][2];
        k=0;

        for(i=0;i<15;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)
                                b1[k]=420-b1[k];
                        line1[i][j]=( b1[k] * (.0476) );
                        k++;
                }
        glLineWidth(1.4);
        glBegin(GL_LINE_STRIP);
        for(i=0;i<15;i++)
                glVertex2fv(line1[i]);
        glEnd();
}



void drawGroundBricks2()
{
        //draw and fill Color for the square
        glColor3ub(groundx,groundy,groundz);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(20,0);
        glVertex2f(20,20);
        glVertex2f(0,20);
        glEnd();
        
        glLineWidth(2.4);
        //Black Shade on Bottom and Right edge
        glColor3f(0,0,0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,0);
        glVertex2f(20,0);
        glVertex2f(20,20);
        glEnd();
        
        //White Shade  on Top and Left edge
        glColor3ub(166,246,245);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,0);
        glVertex2f(0,20);
        glVertex2f(20,20);
        glEnd();
        
        //Interior Black Shade lines
        glColor3f(0,0,0);
        GLfloat b[50]={3,277,
                9,277,
                17,277,
                49,276,
                58,278,
                57,297,
                98,297,
                109,298,
                110,322,
                195,321,
                224,321,
                223,271,
                250,271,
                249,34,
                250,146,
                385,146,
                250,146,
                250,0
        };
        
        GLfloat line[18][2];
        GLint i,j;
        GLint k=0;
        
        for(i=0;i<18;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)      //Y coordinate Transformation
                                b[k]=420-b[k];
                        line[i][j]=( b[k] * (.0476) );  //Scaled from size 420 to 20. Hence the scaling factor
                        k++;
                }
        
        glLineWidth(2);
        glBegin(GL_LINE_STRIP); //Draw the lines
        for(i=0;i<18;i++)
                glVertex2fv(line[i]);
        glEnd();
        
        
        
        //Interior white shading Line
        glColor3ub(166,246,245);
        GLfloat b1[50]={34,303,
                47,303,
                47,326,
                98,327,
                97,355,
                223,356,
                223,325,
                253,325,
                252,272,
                274,272,
                274,170,
                381,168,
                273,171,
                272,39,
                272,0
        };
        //Concept is same as the one used in White shading Line
        GLfloat line1[15][2];
        k=0;
        
        for(i=0;i<15;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)
                                b1[k]=420-b1[k];
                        line1[i][j]=( b1[k] * (.0476) );
                        k++;
                }
        glLineWidth(1.4);
        glBegin(GL_LINE_STRIP);
        for(i=0;i<15;i++)
                glVertex2fv(line1[i]);
        glEnd();
}

void draw3Bush()
{
        //3 Bushes are Merged, hence drawBush function is written thrice
        glPushMatrix();
        glTranslatef(500,250,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(525,250,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();
        
        glPushMatrix();
        glTranslatef(550,250,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();
}


void draw3Cloud()
{
        //3 Clouds are Merged, hence drawCloud function is written thrice
        glPushMatrix();
        glTranslatef(500,250,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(525,250,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(550,250,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();
}




void drawBrick()
{
        GLint i;

        //Black Rectangle
        glColor3f(0,0,0);
        glRectf(0,0,75,75);

        //Top Shade
        glColor3ub(238,210,190);
        glLineWidth(2);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,74);
        glVertex2f(75,74);
        glEnd();

        glColor3ub(brickx,bricky,brickz);

        //5 Inner Rectangles(bricks)
        glPushMatrix();
        for(i=0;i<2;i++)
        {
                glRectf(1,4,14,18);
                glRectf(18,4,53,18);
                glRectf(57,4,76,18);
                glRectf(1,22,33,36);
                glRectf(38,22,71,36);

                glTranslatef(0,36,0);
        }
        glPopMatrix();

}




void drawQuestionBrick()
{
        //Black Square
        glColor3f(0,0,0);
        glRectf(0,0,16,16);

        //Left and Top Shade
        glColor3ub(211,98,46);
        glRectf(0,1,1,15);
        glRectf(1,15,15,16);

        //Inner Background Square
        glColor3ub(253,163,70);
        glRectf(1,1,15,15);

        //4 Dots at corners
        glColor3f(0,0,0);
        glRectf(2,2,3,3);
        glRectf(13,2,14,3);
        glRectf(13,13,14,14);
        glRectf(2,13,3,14);

        //Question Mark Shadow
        glRectf(8,2,10,4);
        glRectf(8,5,10,8);
        glRectf(10,7,12,11);
        glRectf(5,8,7,12);
        glRectf(7,11,9,12);

        //Orange Question Mark
        glColor3ub(239,89,30);
        glRectf(7,3,9,5);
        glRectf(7,6,9,8);
        glRectf(8,8,11,9);
        glRectf(9,9,11,12);
        glRectf(5,12,10,13);
        glRectf(4,9,6,12);

}




void drawStep()
{
        glColor3f(0,0,0);   //Black Square
        glRectf(0,0,16,16);

        glColor3ub(252,188,176);    //Peach Triangle
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,16);
        glVertex2f(16,16);
        glEnd();

        glColor3ub(200,76,12);

        glBegin(GL_LINE_LOOP);      //Diagonal
        glVertex2f(0,15.9);
        glVertex2f(15.9,.2);
        glEnd();

        glRectf(4,4,12,12);         //Central Square

}




void drawFlag()
{
        glRotatef(180, 1, 0, 0); //because I forgot to flip image before plotting vertices

        glColor3ub(255, 255, 255);
        glBegin(GL_POLYGON);        //FLAG
        glVertex2f(647,334);
        glVertex2f(647,675);
        glVertex2f(219,334);
        glEnd();

        glColor3ub(26, 146, 22);
        glRectf(436,483,621,377); //FLAG DESIGN - GREEN FILL
        glRectf(488,506,565,357);
        glRectf(462,388,595,357);

        glColor3ub(255, 255, 255);
        glRectf(462,442,488,399); //FLAG DESIGN FACE
        glRectf(488,421,514,378);
        glRectf(540,421,568,377);
        glRectf(568,442,595,398);
        glRectf(516,463,542,442);
}




void drawFlagpole()
{
        glRotatef(180, 1, 0, 0); //because I forgot to flip image before plotting vertices

        glColor3ub(185, 252, 58);
        glRectf(621,314,675,3200);  //POLE (modify last parameter to adjust pole length)

        glColor3ub(0, 0, 0);
        glRectf(595,163,700,144); //POLE CIRCLE BLACK BORDER
        glRectf(703,183,726,165);
        glRectf(729,270,754,185);
        glRectf(703,293,729,270);
        glRectf(596,311,703,293);
        glRectf(570,291,593,272);
        glRectf(540,270,567,186);
        glRectf(567,186,595,163);

        glColor3ub(26, 146, 22);
        glRectf(568,270,726,188); //GREEN FILL TOP
        glRectf(595,186,700,165);
        glRectf(596,293,700,259);

        glColor3ub(138, 214, 41);
        glRectf(595,186,621,165); //LIGHT GREEN SHINE POLE TOP
        glRectf(568,229,595,186);


}


void drawBattlements()
{
        glTranslatef(-256, -34, 0);
        glScalef(0.38, 0.38, 0);
        
        glColor3ub(230, 95, 19);
        glRectf(93,183,135,95);  //BATTLEMENTS 1 FILL
        glRectf(230,181,339,93);
        glRectf(434,183,538,93);
        glRectf(634,181,740,91);
        glRectf(833,183,940,91);
        glRectf(1037,183,1075,97);
        
        glPushMatrix();
        glTranslatef(0, -30, 0); //BATTLEMENTS 2 FILL
        glScalef(1, 1.03, 0);
        glRectf(289,580,333,502);
        glRectf(436,582,537,500);
        glRectf(634,582,736,500);
        glRectf(833,584,888,500);
        glPopMatrix();
        
        glLineWidth(1.5);
        glBegin(GL_LINES);
                glColor3ub(0, 0, 0);
                glVertex2f(89,93);  //EXTRA LINES FOR BETTER DETAIL
                glVertex2f(133,93);
                glVertex2f(232,93);
                glVertex2f(335,93);
                glVertex2f(434,93);
                glVertex2f(531,93);
                glVertex2f(630,93);
                glVertex2f(738,93);
                glVertex2f(835,93);
                glVertex2f(934,93);
                glVertex2f(1033,93);
                glVertex2f(1081,93);

                glColor3ub(244, 189, 176);
                glLineWidth(1.26);
                glVertex2f(95,181);  //BORDER OF BATTLEMENT 1
                glVertex2f(136,181);
                glVertex2f(136,181);
                glVertex2f(136,93);
                glVertex2f(136,93);
                glVertex2f(232,93);
                glVertex2f(232,93);
                glVertex2f(232,181);
                glVertex2f(232,181);
                glVertex2f(333,181);
                glVertex2f(333,181);
                glVertex2f(333,93);
                glVertex2f(333,93);
                glVertex2f(434,93);
                glVertex2f(434,93);
                glVertex2f(434,181);
                glVertex2f(434,181);
                glVertex2f(536,181);
                glVertex2f(536,181);
                glVertex2f(536,93);
                glVertex2f(536,93);
                glVertex2f(633,93);
                glVertex2f(633,93);
                glVertex2f(633,181);
                glVertex2f(633,181);
                glVertex2f(735,181);
                glVertex2f(735,181);
                glVertex2f(735,93);
                glVertex2f(735,93);
                glVertex2f(835,93);
                glVertex2f(835,93);
                glVertex2f(835,181);
                glVertex2f(835,181);
                glVertex2f(934,181);
                glVertex2f(934,181);
                glVertex2f(934,93);
                glVertex2f(934,93);
                glVertex2f(1033,93);
                glVertex2f(1033,93);
                glVertex2f(1033,181);
                glVertex2f(1033,181);
                glVertex2f(1086,181);
        glEnd();
        
        glPushMatrix();
        glTranslatef(0, -14, 0);
        glBegin(GL_LINES);
                glLineWidth(1.5);
                glColor3ub(0, 0, 0);
                glVertex2f(291,496);   //EXTRA LINES FOR BETTER DETAIL
                glVertex2f(333,496);
                glVertex2f(432,496);
                glVertex2f(535,496);
                glVertex2f(632,496);
                glVertex2f(736,496);
                glVertex2f(833,496);
                glVertex2f(890,496);
        glEnd();
        glPopMatrix();
        
        glTranslatef(0, -8, 0);
        glBegin(GL_LINES);
                glLineWidth(1.26);
                glColor3ub(244, 189, 176);
                glVertex2f(291,583);   //BORDER OF BATTLEMENTS 2
                glVertex2f(333,583);
                glVertex2f(333,583);
                glVertex2f(333,495);
                glVertex2f(333,495);
                glVertex2f(436,495);
                glVertex2f(436,495);
                glVertex2f(436,583);
                glVertex2f(436,583);
                glVertex2f(535,583);
                glVertex2f(535,583);
                glVertex2f(535,495);
                glVertex2f(535,495);
                glVertex2f(632,495);
                glVertex2f(632,495);
                glVertex2f(632,583);
                glVertex2f(632,583);
                glVertex2f(735,583);
                glVertex2f(735,583);
                glVertex2f(735,495);
                glVertex2f(735,495);
                glVertex2f(834,495);
                glVertex2f(834,495);
                glVertex2f(834,583);
                glVertex2f(834,583);
                glVertex2f(890,583);
        glEnd();
}

void drawCastle()
{
        
                GLint i,j;
        for(i=0;i<3;i++)        //Ground Floor
        {

            for(j=0;j<5;j++)
            {
                drawBrick();
                glTranslatef(75,0,0);
            }
            glTranslatef(-75*5,73,0);
        }

        glTranslatef(75,0,0);   //First Floor
        for(i=0;i<2;i++)
        {

            for(j=0;j<3;j++)
            {
                drawBrick();
                glTranslatef(75,0,0);
            }
            glTranslatef(-75*3,73,0);
        }

        glColor3f(0,0,0);       //Door
        glTranslatef(75,-5*73,0);
        glRectf(0,0,75,146);

        glTranslatef(-38,73*3,0);
        glRectf(0,0,37.5,73);

        glTranslatef(110,0,0);
        glRectf(0,0,37.5,73);
        
        drawBattlements(); //Battlements
        
}




void marker()
{
        glColor3f(1,1,1);
        glBegin(GL_LINE_STRIP);
        glVertex2f(0,0);
        glVertex2f(21,0);
        glEnd();
}




void scene1()
{
        GLint i,j;

        glClearColor(0.329411,0.54505,1,1); //Blue sky
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
        glLoadIdentity();
        gluOrtho2D(0,600,0,400); //The Scale for the Window



        glPushMatrix();//Left cloud
        glTranslatef(125,250,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();//Center cloud
        glTranslatef(350,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        //Three Clouds
        draw3Cloud();



        //Green Mountain
        glPushMatrix();
        glTranslatef(264,40,0);
        glScalef(.35,.35,0);
        drawMountain();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-125,40,0);
        glScalef(.8,.7,0);
        drawMountain();
        glPopMatrix();



        //Bush
        glPushMatrix();
        glTranslatef(-340,-224,0);
        draw3Bush();

        glTranslatef(791,250,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();




        //Bricks
        glPushMatrix();
        glTranslatef(352,120,0);
        for(j=0;j<3;j++)
        {
                glPushMatrix();
                glScalef(.3,.3,0);
                drawBrick();
                glPopMatrix();

                glTranslatef(45,0,0);
        }
        glPopMatrix();




        glPushMatrix();    //Goomba
        glTranslatef(goombaX, 42, 0);   //Initial x value=415;
        glScalef(0.035, 0.035, 0);
        drawGoomba();
        glPopMatrix();



        glPushMatrix();    //Mushroom
        glTranslatef(mushX, mushY, mushZ);      //Initial Postion (374,142,-1)
        glScalef(0.035, 0.035, 0);
        drawMushroom();
        glPopMatrix();




        //Question Mark
        glPushMatrix();
        glTranslatef(374.5,120,0);
        glScalef(1.406,1.406,0);
        drawQuestionBrick();

        glTranslatef(32,0,0);
        drawQuestionBrick();

        glTranslatef(-108,0,0);
        drawQuestionBrick();

        glTranslatef(92,68,0);
        drawQuestionBrick();
        glPopMatrix();




        //Display Mario at Start position
        glPushMatrix();
        glTranslatef(marioX,marioY,0);  //Initial is (70,40,0)
        glScalef(.055,.055,0);   //For Bigger Version use (.075,.09,0)
        drawMario();
        glPopMatrix();




        glPushMatrix();    //Pipe
        glTranslatef(521, 31, 0);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glPopMatrix();




         //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);
        }
        glPopMatrix();

        x1=255;x2=255;x3=255;

        glFlush();
}




void scene2()
{

        GLint i,j;

        glClearColor(0,0,0,1); //Blue sky
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
        glLoadIdentity();
        gluOrtho2D(0,410,0,273); //The Scale for the Window


        //Left Wall
        glPushMatrix();
        brickx=0;bricky=128;brickz=136;
        glTranslatef(0,41,0);
        for(j=0;j<11;j++)
        {
                glPushMatrix();
                glScalef(.3,.3,0);
                drawBrick();
                glPopMatrix();

                glTranslatef(0,21,0);
        }
        glPopMatrix();



        //Mid Floor Raise
        glPushMatrix();
        glTranslatef(105,41,0);
        for(i=0;i<3;i++)
        {
            for(j=0;j<7;j++)
            {
                glPushMatrix();
                glScalef(.3,.3,0);
                drawBrick();
                glPopMatrix();

                glTranslatef(21,0,0);
            }
            glTranslatef(-147,21,0);
        }
        glPopMatrix();



        //Ceiling Bricks
        glPushMatrix();
        glTranslatef(105,252,0);
        for(j=0;j<7;j++)
        {
                glPushMatrix();
                glScalef(.3,.3,0);
                drawBrick();
                glPopMatrix();

                glTranslatef(21,0,0);
        }
        glPopMatrix();




        //Ground Blocks
        glPushMatrix();
        groundx=0;groundy=128;groundz=136;
        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGroundBricks2();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGroundBricks2();
                glTranslatef(21,0,0);
        }
        glPopMatrix();




        //Coins
        glPushMatrix();
        glTranslatef(108,105,0);
        for(i=0;i<2;i++)    //Bottom and Middle Row
        {
            for(j=0;j<7;j++)
            {
                glPushMatrix();
                glScalef(.02,.02,0);
                drawCoin();
                glPopMatrix();

                glTranslatef(21,0,0);
            }
            glTranslatef(-147,42,0);
        }
        glPopMatrix();

        glPushMatrix();     //Top Row
        glTranslatef(129,189,0);
        for(j=0;j<5;j++)
        {
                glPushMatrix();
                glScalef(.02,.02,0);
                drawCoin();
                glPopMatrix();

                glTranslatef(21,0,0);
        }
        glPopMatrix();




        //Cover coins using black boxes DURING ANIMATION
        if(coinFLAG>0)
        {
            glPushMatrix();
                glColor3f(0,0,0);
                glRectf(106,106,106+21*coinFLAG,126);
            glPopMatrix();
        }




        //Display Mario
        glPushMatrix();
        glTranslatef(marioX,marioY,0);
        glScalef(.055,.055,0);
        drawMario();
        glPopMatrix();




        //To simulate Mario going inside the pipe DURING ANIMATION
        glPushMatrix();
        glColor3f(0,0,0);
        glRectf(344,41,410,100);
        glPopMatrix();




        //Pipe
        glPushMatrix();

        glTranslatef(392, 42, 0);
        glRotatef(90,0,0,1);
        glScalef(0.04, 0.06, 0);
        drawPipe();

        glRotatef(270,0,0,1);
        glTranslatef(-4/.04,-7/.04,0);
        glScalef(.6,20,0);
        drawPipe();

        glPopMatrix();




        x1=255;x2=255;x3=255;
        brickx=231;bricky=95;brickz=19;
        groundx=230;groundy=95;groundz=19;


        glFlush();

}




void scene3()
{
        GLint i,j;

        glClearColor(0.329411,0.54505,1,1); //Blue sky
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
        glLoadIdentity();
        gluOrtho2D(0,600,0,400); //The Scale for the Window




        glPushMatrix();//Left cloud
        glTranslatef(31,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        //Three Clouds(Placed at Center)
        glPushMatrix();
        glTranslatef(-300,25,0);
        draw3Cloud();
        glPopMatrix();

        glPushMatrix();//Right cloud1
        glTranslatef(400,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();
        glPushMatrix();//Right cloud2
        glTranslatef(425,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();



        //Bush
        glPushMatrix();
        glTranslatef(111,27,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();



        glPushMatrix();    //Goomba1
        glTranslatef(goomba1X, 42, 0);
        glScalef(0.035, 0.035, 0);
        drawGoomba();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(goomba2X,42,0);//Goomba2
        glScalef(0.035, 0.035, 0);
        drawGoomba();
        glPopMatrix();




        //Green Mountain
        glPushMatrix();
        glTranslatef(-60,40,0);
        glScalef(.35,.35,0);
        drawMountain();
        glPopMatrix();




        //Bricks
        glPushMatrix();
        glTranslatef(147,120,0);
        for(j=0;j<4;j++)//Draw 4 bricks
        {
                glPushMatrix();
                glScalef(.3,.3,0);
                drawBrick();
                glPopMatrix();

                glTranslatef(21,0,0);
        }
        glPopMatrix();



        //Question Mark
        glPushMatrix();//3rd brick is replaced by question mark
        glTranslatef(189,120,0);
        glScalef(1.406,1.406,0);
        drawQuestionBrick();
        glPopMatrix();



        //Steps
        glPushMatrix();
        glTranslatef(400,42,0);
        //glTranslatef(252,42,0);

        for(i=9;i>0;i--)
        {
            if(i==1)
                break;
            for(j=0;j<i;j++)
            {
                glPushMatrix();
                glScalef(1.3125,1.3125,0);
                drawStep();
                glPopMatrix();

                glTranslatef(21,0,0);   //Place each block after 21 units
            }
            glTranslatef(-(i-1)*21,21,0);
        }
        glPopMatrix();




        //Mario is inside the Pipe initially
        glPushMatrix();
        glTranslatef(marioX,marioY,0);
        glScalef(.055,.055,0);
        drawMario();
        glPopMatrix();




        glPushMatrix();    //Pipe1
        glTranslatef(22, 31, 0);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glTranslatef(312/.055,0,0);//Pipe2
        drawPipe();
        glPopMatrix();



        //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);
        }
        glPopMatrix();



        x1=x2=x3=255;

        glFlush();
}




void scene4()
{
        GLint i,j;

        glClearColor(0.329411,0.54505,1,1); //Blue sky
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
        glLoadIdentity();
        gluOrtho2D(0,600,0,400); //The Scale for the Window



        glPushMatrix();//Cloud above Pipe
        glTranslatef(450,150,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();//Right cloud1
        glTranslatef(350,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();
        glPushMatrix();//Right cloud2
        glTranslatef(375,300,0);
        glScalef(.04,.04,0);
        drawCloud();
        glPopMatrix();



        //Green Mountain
        glPushMatrix();
        glTranslatef(80,40,0);
        glScalef(.45,.55,0);
        drawMountain();
        glPopMatrix();



        //Bush
        glPushMatrix();
        glTranslatef(350,15,0);
        glScalef(.04,.04,0);
        drawBush();
        glPopMatrix();



        //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGroundBricks();
                glTranslatef(21,0,0);
        }
        glPopMatrix();



        //Stairs
        glPushMatrix();
        glTranslatef(-148,42,0);
        //glTranslatef(252,42,0);

        for(i=9;i>0;i--)
        {
            if(i==1)
                break;
            for(j=0;j<i;j++)
            {
                glPushMatrix();
                glScalef(1.3125,1.3125,0);
                drawStep();
                glPopMatrix();

                glTranslatef(21,0,0);   //Place each block after 21 units
            }
            glTranslatef(-(i-1)*21,21,0);
        }
        glPopMatrix();



        glPushMatrix();    //Flagpole
        glTranslatef(181, 274, 0);
        glScalef(0.059, 0.066, 0);
        drawFlagpole();
        glPopMatrix();

        glPushMatrix();    //Flag
        glTranslatef(181, flagMove, 0);
        glScalef(0.059, 0.066, 0);
        drawFlag();
        glPopMatrix();

        glPushMatrix(); //Base of Flagpole
        glTranslatef(209,42,0);
        glScalef(1.3125,1.3125,0);
            drawStep();
        glPopMatrix();



        glPushMatrix(); //House
        glTranslatef(272,41.5,0);
        glScalef(.28,.28,0);
            drawCastle();
        glPopMatrix();


        //Display Mario on top of the Stairs
        glPushMatrix();
        glTranslatef(marioX,marioY,marioZ);
        glScalef(.055,.055,0);
        drawMario();
        glPopMatrix();



        glPushMatrix();    //Pipe
        glTranslatef(522, 41, 0);
        glRotatef(90,0,0,1);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glRotatef(270,0,0,1);
        glTranslatef(-4/.055,0,0);
        glScalef(1,1.6,0);
        drawPipe();
        glPopMatrix();



        x1=255;x2=255;x3=255;

        glFlush();
}




void resetScene1()
{
        tyme=0;
        goombaX=415;
        goombaRight=1;    //goombaRight=1 indicates that he's moving in the Right direction, 0 indicates left

        marioX=70,marioY=40;        //Starting position of Mario
        marioUp=0,marioHoriz=1;    //marioUp=0 to make Mario move horizontally

        mushX=374,mushY=120,mushZ=0;
        mushMove=0;
        i=180;
}




void resetScene2()
{
        tyme=0;

        marioX=21,marioY=274;       //Mario before free fall
        marioUp=0,marioHoriz=0;    //Mario has to move downwards

        i=180;
        coinFLAG=0;
}




void resetScene3()
{
        tyme=0;
        goomba1X=252;
        goomba2X=284;
        goomba1Right=1;    //goombaRight=1 indicates that he's moving in the Right direction, 0 indicates left
        goomba2Right=1;

        marioX=42,marioY=42;      //Mario inside the pipe
        marioUp=1,marioHoriz=0;    //marioUp=1 to make Mario move upwards

        i=180;
}




void resetScene4()
{
        tyme=0;

        marioX=21,marioY=209,marioZ=0;
        marioUp=1,marioHoriz=1;
        flagMove=274;

        i=180;
}




//Animate Scene1

void myTimer1(int n)
{

        tyme+=10;   //Count time in miliseconds

        if(marioUp==0 && marioHoriz==1)
            marioX+=2;      //Mario moves Horizontally

        else if(marioUp==0 && marioHoriz==0)
        {
            marioY-=3;      //Mario moves Vertically downwards
            mushY+=1.07;       //Mushroom pops out of the Question mark
        }

        else if(marioUp==1 && marioHoriz==0)
            marioY+=2;      //Mario moves Vertically upwards

        if(mushMove==1)
            mushX+=1;       //Mushroom starts moving horizontally

        if(tyme==1530)      //Jump Up to hit the question mark
        {
            marioUp=1;
            marioHoriz=0;
        }

        if(tyme==1830)     //Let gravity do the job
        {
            marioUp=0;
            marioHoriz=0;
        }

        if(tyme==2030)      //Continue running
        {
            marioHoriz=1;
            mushMove=1;     //Mushroom moves over the bricks
        }


        if(tyme>=2430 && tyme<=2930)      //Mario Jumps
        {
            marioHoriz=1;   //This is done in order to not match the first 3 if conditions
            marioUp=1;
            if(i>150)       //Mario jumps onto the Pipe
            {   marioX=500+46*(-cos(3.14*i));
                marioY=42+46*(-sin(3.14*i));
                i=i-.01;
            }
        }

        if(tyme>=2930)
        {
            mushMove=0;     //Stop moving mushroom horizontally
            mushY-=1.01;    //Let it fall downwards
        }

        if(tyme>=3930 && tyme<=4280)      //Mushroom is on the ground. Move it horizontally
        {
            mushY+=1.01;   //Inorder to counter the statement 'mushY-=1.01;' . This is done because even 'if(tyme>=2930)' will be executed
            mushMove=1;
            marioX+=.7;     //Mario moves to center of the Pipe
        }

        if(tyme>=4280)
        {
            mushMove=0;     //If set to 1, it'll move to the Right, hence set it to 0
            mushX-=1;       //Move Leftwards
            mushY+=1.01;
            marioY-=1;
        }



        //Goomba Animation
        if(goombaRight==1)
            goombaX+=1.2;     //Move towards the right
        else
            goombaX-=1.2;     //Move towards the left


        if(goombaX>=500)    //When he hits the pipe, set flag to move in the Left direction
            goombaRight=0;

        if(goombaX<=0)      //When he hits the leftmost part of the screen, set flag to move in the Right direction
            goombaRight=1;



        glutPostRedisplay();

        if(scenePointer==scene1)
            glutTimerFunc(10,myTimer1,0);

}




//Animate Scene2

void myTimer2()
{

        tyme+=10;   //Count time in miliseconds

        if(marioUp==0 && marioHoriz==1)
            marioX+=1;      //Mario moves Horizontally

        else if(marioUp==0 && marioHoriz==0)
        {
            marioY-=2;      //Mario moves Vertically downwards
        }

        else if(marioUp==1 && marioHoriz==0)
            marioY+=2;      //Mario moves Vertically upwards



        if(tyme==1170)
        {
            marioUp=1;      //Stop movement
            marioHoriz=1;
        }


        if(tyme>=1530 && tyme<=2030)      //Mario Jumps
        {
            if(i>150)       //Mario jumps onto the elevated floor having coins
            {   marioX=84+63*(-cos(3.14*i));
                marioY=43+63*(-sin(3.14*i));
                i=i-.01;
            }
        }

        if(tyme==1970)      //Coin 1 disappears
        {
            coinFLAG=1;
            marioUp=0;      //Start moving mario horizontally
        }

        if(tyme==2170)      //Coin 2 disappears
            coinFLAG=2;

        if(tyme==2370)      //Coin 3 disappears
            coinFLAG=3;

        if(tyme==2570)      //Coin 4 disappears
            coinFLAG=4;

        if(tyme==2770)      //Coin 5 disappears
            coinFLAG=5;

        if(tyme==2970)      //Coin 6 disappears
            coinFLAG=6;

        if(tyme==3170)      //Coin 7 disappears
            coinFLAG=7;

        if(tyme==3550)
        {
            marioUp=1;
        }

        if(tyme>=3550 && tyme<=3970)      //Mario falls to ground after collecting Coins
        {
            marioX+=.75;
            marioY-=1.5;
        }

        if(tyme==4000)                  //Enable Horizontal movement of Mario
            marioUp=0;



        glutPostRedisplay();

        if(scenePointer==scene2)
            glutTimerFunc(10,myTimer2,0);
}




//Animate Scene3

void myTimer3()
{

        tyme+=10;   //Count time in miliseconds

        if(marioUp==0 && marioHoriz==1)
            marioX+=1;      //Mario moves Horizontally

        else if(marioUp==0 && marioHoriz==0)
        {
            marioY-=2;      //Mario moves Vertically downwards
        }

        else if(marioUp==1 && marioHoriz==0)
            marioY+=.5;      //Mario moves Vertically upwards

        if(tyme==860)       //Mario comes up the Pipe
            marioHoriz=1;

        if(tyme>=1300 && tyme<=2000)      //Mario Jumps onto the bricks
            if(i>150)
            {   marioX=126+84*(-cos(3.14*i));
                marioY=89+84*(-sin(3.14*i));
                i=i-.01;
            }

        if(tyme==2050)                  //Move Mario horizontally on the bricks
        {
            marioUp=0;
            i=180;      //Set angle value for the next jump
        }

        if(tyme>=2300 && tyme<=2900)
            if(i>150)       //Mario is jumping onto the 2nd Pipe
            {   marioX=284+50*(-cos(3.14*i));
                marioY=141+50*(-sin(3.14*i));
                i=i-.015;
            }

        if(tyme==2900)            //Free fall onto the Pipe
        {
            marioUp=0;
            marioHoriz=0;
            i=180;                  //Set angle value for the next jump
        }

        if(tyme==3180)             //Move towards the right
            marioHoriz=1;

        if(tyme==3480)              //Stop
            marioUp=1;

        if(tyme>=3700 && tyme<=4400)
            if(i>179.44)       //Mario jumps onto the Stairs
            {   marioX=441+63*(-cos(3.14*i));
                marioY=89+63*(-sin(3.14*i));
                i=i-.01;
            }

        if(tyme==4450)
            i=180;

        if(tyme>=4500 && tyme<=5200)
            if(i>179.52)       //Mario jumps onto the Top Step
            {   marioX=533+63*(-cos(3.14*i));
                marioY=147+63*(-sin(3.14*i));
                i=i-.01;
            }

        if(tyme==5250)
            marioUp=0;          //Mario moves horizontally

        if(tyme==5470)
            marioUp=1;          //Stop Mario movement




        //Goomba Animation
        if(goomba1Right==1)  //Goomba1
            goomba1X+=.7;     //Move towards the right
        else
            goomba1X-=.7;     //Move towards the left

        if(goomba2Right==1)  //Goomba2
            goomba2X+=.7;     //Move towards the right
        else
            goomba2X-=.7;     //Move towards the left


        if(goomba1X>=315)    //When he hits the pipe, set flag to move in the Left direction
            goomba1Right=0;

        if(goomba1X<=73)      //When he hits the leftmost part of the screen, set flag to move in the Right direction
            goomba1Right=1;

        if(goomba2X>=316)    //When he hits the pipe, set flag to move in the Left direction
            goomba2Right=0;

        if(goomba2X<=73)      //When he hits the leftmost part of the screen, set flag to move in the Right direction
            goomba2Right=1;




        glutPostRedisplay();

        if(scenePointer==scene3)
            glutTimerFunc(10,myTimer3,0);

}


//Animate Scene4

void myTimer4()
{

        tyme+=10;   //Count time in miliseconds

        if(marioUp==0 && marioHoriz==1)
            marioX+=1;      //Mario moves Horizontally

        else if(marioUp==0 && marioHoriz==0)
        {
            marioY-=1.5;      //Mario moves Vertically downwards
        }

        else if(marioUp==1 && marioHoriz==0)
            marioY+=.5;      //Mario moves Vertically upwards

        if(tyme>=500 && tyme<=1270)      //Mario Jumps onto the Flag
            if(i>150)
            {   marioX=115+94*(-cos(3.14*i));
                marioY=209+94*(-sin(3.14*i));
                i=i-.01;
            }

        if(tyme>=1400 && tyme<=2500)    //Mario and Flag slide downwards
        {
            marioHoriz=0;
            marioUp=0;
            flagMove-=1.5;

        }

        if(tyme==2500)          //Stop sliding
        {
            marioHoriz=1;
            marioUp=1;
        }

        if(tyme==3000)          //Mario moves rightwards
        {
            marioUp=0;
        }

        if(tyme==3300)          //Falls onto the ground
        {
            marioHoriz=0;
        }

        if(tyme==3590)          //Pause
        {
            marioY--;           //Alignment with the Ground
            marioHoriz=1;
            marioUp=1;
        }

        if(tyme==3700)          //Go towards the Castle
            marioUp=0;

        if(tyme==4560)          //Go inside the Castle
        {
            marioUp=1;
            marioZ=3;
        }

        if(tyme==8000)          //Walk towards the Pipe
        {
            marioZ=0;
            marioUp=0;
        }

        if(tyme==9500)         //Enter the Pipe
        {
            marioHoriz=1;
            marioUp=1;
        }




        glutPostRedisplay();

        if(scenePointer==scene4)
            glutTimerFunc(10,myTimer4,0);

}




void myKey(unsigned char c, int x, int y)
{
        if(c=='n'||c=='N')
            next++;
        else if(c=='b'||c=='B')
            next--;
        else if(c=='q'||c=='Q')     //Quit
            exit(0);
        else
            return;         //Don't proceed


        if(next==0)
        {
            scenePointer = &scene1; //Set Display Function as Scene1
            resetScene1();          //Load Parameters in their initial state for this scene
            glutTimerFunc(10,myTimer1,0);   //Start Animation
        }

        if(next==1)
        {
            scenePointer = &scene2; //Set Display Function as Scene2
            resetScene2();
            glutTimerFunc(10,myTimer2,0);
        }

        if(next==2)
        {
            scenePointer = &scene3; //Set Display Function as Scene3
            resetScene3();
            glutTimerFunc(10,myTimer3,0);
        }

        if(next==3)
        {
            scenePointer = &scene4; //Set Display Function as Scene3
            resetScene4();
            glutTimerFunc(10,myTimer4,0);
        }

        if(next<0)
            next=0;

        if(next>3)
            next=3;

        glutPostRedisplay();
}




void currentDisplay()
{

        (*scenePointer)();              //Pointer function that points to one of the 4 Scenes

}




//      Windows:Ctrl+Shift+C to comment and Ctrl+Shift+X to uncomment
/*
void windowResized(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if(w<=h)
            gluOrtho2D(0,600,0,400*(GLfloat)(h/w));
        else
            gluOrtho2D(0,600*(GLfloat)(w/h),0,400);
        glMatrixMode(GL_MODELVIEW);

}*/




int main(int argc,char **argv)
{
        glutInit(&argc,argv);            //Initialize graphics libraries
        //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
        glutInitWindowSize(750,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Mario v1.1");

        scenePointer=&scene1;       //scenePointer should initially point to the first scene in order to display it

        glutDisplayFunc(currentDisplay);

        glutTimerFunc(3000,myTimer1,0);
        glutTimerFunc(500,myTimer2,0);
        glutTimerFunc(500,myTimer3,0);
        glutTimerFunc(500,myTimer4,0);

        //glutReshapeFunc(windowResized);
        glutKeyboardFunc(myKey);
        glutMainLoop();             //mainloop handles all the glut events(functions with the prefix "glut"). Display function is only called once, not iteratively.
        return 0;
}
