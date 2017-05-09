//
//  main.c
//  sample
//
//  Created by Calvin Menezes & Lloyd Fernandes
//  Copyright © 2017. All rights reserved.
//


/*WINDOWS HEADERS*/
#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<windows.h>

/*MAC HEADERS*/
/*#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<OpenGL/glext.h>
#include<GLUT/glut.h>
#include<stdio.h>
*/


GLint x1=255,x2=255,x3=255; //Color Values to be changed for Grass and Clouds as the function is same for both
GLint groundx=231,groundy=95,groundz=19;
GLint brickx=230,bricky=95,brickz=19;
int next=0;
int flag=0;
void (*scenePointer)();

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




void drawCloud()
{
        //Coordinates of the Cloud are stored in Array 'a'
        GLfloat a[500]={18,89,
                23,90,
                27,85,
                27,81,
                31,75,
                32,71,
                40,72,
                44,71,
                50,68,
                54,63,
                60,58,
                60,52,
                60,47,
                64,43,
                69,43,
                74,40,
                80,34,
                87,34,
                93,33,
                98,39,
                102,42,
                102,48,
                108,51,
                110,47,
                115,51,
                121,55,
                122,62,
                122,68,
                127,72,
                131,79,
                135,77,
                140,72,
                144,77,
                145,84,
                149,89,
                154,86,
                159,90,
                160,98,
                154,104,
                149,109,
                154,113,
                159,118,
                156,124,
                150,127,
                145,133,
                139,133,
                134,136,
                130,136,
                125,133,
                120,138,
                116,138,
                111,140,
                104,140,
                98,141,
                90,138,
                84,133,
                79,138,
                74,142,
                66,142,
                59,138,
                53,138,
                51,133,
                50,128,
                43,128,
                36,128,
                30,122,
                31,118,
                27,115,
                23,109,
                17,105,
                12,102,
                13,96};

        GLfloat cld[72][2]; //'cld' stands for Cloud. It's a 2D array that used to organise the vertices in the form of pairs
        GLint i,j;
        GLint k=0;

        for(i=0;i<72;i++)
                for(j=0;j<2;j++)
                {
                        if(k%2==1)  //Odd indices of array 'a' are the Y coordinates which have to be correctly represented in
                                //the graphical system we use
                                a[k]=195-a[k];

                        cld[i][j]=a[k]; //Store as Vertex Pair
                        k++;
                }

        glColor3ub(x1,x2,x3);       //Draw the Cloud with color as white
        glBegin(GL_POLYGON);
        for(i=0;i<72;i++)
                glVertex2fv(cld[i]);

        glEnd();
        /*
         glColor3f(0,0,0);       //Border of the Cloud in Black[Optional, Remove if it looks bad]
         glLineWidth(2);
         glBegin(GL_LINE_STRIP);
         for(i=0;i<72;i++)
         glVertex2fv(cld[i]);

         glEnd();
         */
}




void drawGround()
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




void draw3Cloud()
{
        //3 Clouds are Merged, hence drawCloud function is written thrice
        glPushMatrix();
        glTranslatef(500,250,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(525,250,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(550,250,0);
        glScalef(.3,.3,0);
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




void drawQuestionbrick()
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




void drawHouse()
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

}




void scene1()
{
        GLint i,j;

        glClearColor(0.329411,0.54505,1,1); //Blue sky
        glClear(GL_COLOR_BUFFER_BIT); //clear the color buffer
        glLoadIdentity();
        gluOrtho2D(0,600,0,400); //The Scale for the Window



        /*glPushMatrix();    //Coin
        glTranslatef(250, 56, 0);
        glScalef(0.015, 0.015, 0);
        drawCoin();
        glPopMatrix();*/



        glPushMatrix();    //Pipe
        glTranslatef(521, 31, 0);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glPopMatrix();



        glPushMatrix();    //Goomba
        glTranslatef(415, 42, 0);
        glScalef(0.035, 0.035, 0);
        drawGoomba();
        glPopMatrix();



        glPushMatrix();    //Mushroom
        glTranslatef(374, 142, 0);
        glScalef(0.035, 0.035, 0);
        drawMushroom();
        glPopMatrix();



        glPushMatrix();//Left cloud
        glTranslatef(125,250,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();//Center cloud
        glTranslatef(350,300,0);
        glScalef(.3,.3,0);
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



        //Grass
        glPushMatrix();
        x1=183;
        x2=248;
        x3=24;
        glTranslatef(-340,-235,0);
        draw3Cloud();

        glTranslatef(791,251,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();



        //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);
        }
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




        //Question Mark
        glPushMatrix();
        glTranslatef(374.5,120,0);
        glScalef(1.406,1.406,0);
        drawQuestionbrick();

        glTranslatef(32,0,0);
        drawQuestionbrick();

        glTranslatef(-108,0,0);
        drawQuestionbrick();

        glTranslatef(92,68,0);
        drawQuestionbrick();
        glPopMatrix();




        //Display Mario at Start position
        glPushMatrix();
        glTranslatef(70,40,0);
        glScalef(.055,.05,0);   //For Bigger Version use (.075,.09,0)
        drawMario();
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




        //Ground Blocks
        glPushMatrix();
        groundx=0;groundy=128;groundz=136;
        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);
        }
        glPopMatrix();



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

        glPushMatrix();    //Pipe1
        glTranslatef(22, 31, 0);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glTranslatef(312/.055,0,0);//Pipe2
        drawPipe();
        glPopMatrix();



        glPushMatrix();    //Goomba1
        glTranslatef(252, 42, 0);
        glScalef(0.035, 0.035, 0);
        drawGoomba();
        glTranslatef(31/.035,0,0);//Goomba2
        drawGoomba();
        glPopMatrix();



        glPushMatrix();//Left cloud
        glTranslatef(31,300,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();

        //Three Clouds(Placed at Center)
        glPushMatrix();
        glTranslatef(-300,25,0);
        draw3Cloud();
        glPopMatrix();

        glPushMatrix();//Right cloud1
        glTranslatef(400,300,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();
        glPushMatrix();//Right cloud2
        glTranslatef(425,300,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();



        //Green Mountain
        glPushMatrix();
        glTranslatef(-60,40,0);
        glScalef(.35,.35,0);
        drawMountain();
        glPopMatrix();



        //Grass
        glPushMatrix();
        x1=183;
        x2=248;
        x3=24;

        glTranslatef(111,15,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();



        //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);
        }
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
        drawQuestionbrick();
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



        glPushMatrix();    //Pipe
        glTranslatef(522, 42, 0);
        glRotatef(90,0,0,1);
        glScalef(0.055, 0.07, 0);
        drawPipe();
        glRotatef(270,0,0,1);
        glTranslatef(-4/.055,0,0);
        glScalef(1,1.6,0);
        drawPipe();
        glPopMatrix();



        glPushMatrix();//Cloud above Pipe
        glTranslatef(450,150,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();

        glPushMatrix();//Right cloud1
        glTranslatef(350,300,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();
        glPushMatrix();//Right cloud2
        glTranslatef(375,300,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();



        //Green Mountain
        glPushMatrix();
        glTranslatef(80,40,0);
        glScalef(.45,.55,0);
        drawMountain();
        glPopMatrix();



        //Grass
        glPushMatrix();
        x1=183;
        x2=248;
        x3=24;

        glTranslatef(345,15,0);
        glScalef(.3,.3,0);
        drawCloud();
        glPopMatrix();



        //Ground Blocks
        glPushMatrix();

        glColor3f(0,0,0);
        glRectf(0,0,600,42);

        glTranslatef(0,21,0);   //Upper layer layer blocks of the ground. Hence control elevated to 21(Y coordinate)
        for(i=0;i<50;i++)
        {
                drawGround();
                glTranslatef(21,0,0);   //Place each brick after 21 units
        }
        glPopMatrix();          //Pop matrix ensures Control is at the origin (0,0)

        glPushMatrix();
        for(i=0;i<50;i++)
        {
                drawGround();
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

        glPushMatrix(); //Base of Flagpole
        glTranslatef(209,42,0);
        glScalef(1.3125,1.3125,0);
            drawStep();
        glPopMatrix();



        glPushMatrix(); //House
        glTranslatef(272,41.5,0);
        glScalef(.28,.28,0);
            drawHouse();
        glPopMatrix();


        //Display Mario on top of the Stairs
        glPushMatrix();
        glTranslatef(21,209,0);
        glScalef(.055,.05,0);
        drawMario();
        glPopMatrix();

        x1=255;x2=255;x3=255;

        glFlush();

        x1=x2=x3=255;


        glFlush();
}




/*void myTimer(int n)
{


}*/



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




void myKey(unsigned char c, int x, int y)
{
        if(c=='n')
            next++;
        else if(c=='b')
            next--;
        else
            return; //Don't proceed


        if(next==0)
            scenePointer = &scene1; //Set Display Function as Scene1

        if(next==1)
            scenePointer = &scene2; //Set Display Function as Scene2

        if(next==2)
            scenePointer = &scene3; //Set Display Function as Scene3

        if(next==3)
            scenePointer = &scene4; //Set Display Function as Scene4

        if(next<0)
            next=0;

        if(next>3)
            next=3;

        glutPostRedisplay();
}




void currentDisplay()
{

        (*scenePointer)();  //POinter function that points to one of the 4 Scenes

}




int main(int argc,char **argv)
{
        glutInit(&argc,argv); //Initialize graphics libraries
        glutInitWindowSize(750,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Mario v1.1");

        if(flag==0)
        {
            scenePointer=&scene1;
            flag=1;
        }

        glutDisplayFunc(currentDisplay);
        //glutReshapeFunc(windowResized);
        //glutTimerFunc(myTimer);
        glutKeyboardFunc(myKey);
        glutMainLoop();
        return 0;
}
