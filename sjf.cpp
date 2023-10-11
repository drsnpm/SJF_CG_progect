// sjf sheduling.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<glut.h>
#include<string.h>
#include<stdio.h>
#include<windows.h>

void display();
void init();
void keyboard(unsigned char, int, int);
void mainpage();
void println(float, float, float, void *, char[]);
void backgorund();
void help();
void flowchart();
void about();
void *currentfont;
void key1(unsigned char, int, int);
void drawCircle(float , float , float );
void drawArrowd(float , float , float ); 
void drawRectangle(float , float , float , float ) ;
void drawRhombus(float , float , float );
void drawArrowr(float , float , float ); 
void drawArrowl(float , float , float ); 
using namespace std;

void delayf()
{
    for(int i=0;i<32000;i++)
        for(int j=0;j<32000;j++);
}



struct process
{
    int bt,at,st,ct,no;
    char name;
};

struct p{
    int no,bt,at,rbt,st,ct;
};

void disp();
void displayOptions();

//Global decalarations
int front=-1,rear=-1,n,pt=0,total=0,wid,q[30],wt=0,tt=0,tb,one=1,np=1,att,index1,btt,btotal=0,keypa=0,same[50],tq=99,co=0;
struct p process[25];
struct process p[15];
float basic=36.0,col[5][3]={{.94,.90,.55},{.48,.0,.93},{.5,1.0,0.0},{1,.84,.0},{1,.6,.2}};
bool doneInput=false;
char op[] = {"Options:"};
char op1[] = {"1. Shortest Job First (SJF)"};
char op2[] = {"2. Re-enter the data"};
char op3[] = {"3. Exit"};
//End of global declarations

void displayText( float x, float y, int r, int g, int b, const char *string ) {
    int j = strlen (string);
    glColor3f( r, g, b );
    glRasterPos2f( x, y );
    for( int i = 0; i < j; i++ )
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
    glFlush();
}

void displayName(char *lines)
{
  displayText(500, 450, 0, 0, 1,lines);
}
 //========================================================================================================
 //======================================OPTIONS PAGE======================================================
 //=========================================================================================================
void first(void){

}
 //========================================================================================================
 //=============================Prints the characters on screen at x,y=====================================
 //=========================================================================================================
void println(float x, float y, float z, void *font, char str[]) {
  glRasterPos3f(x, y, z);
  for (int i = 0; str[i] != '\0'; i++) {
    glutBitmapCharacter(font, str[i]);
  }
}
 //========================================================================================================
 //==========================================BACKGROUND=====================================================
 //=========================================================================================================
void background() {
  glBegin(GL_POLYGON);
  glColor3f(0.3,0.1, 0.5);
  glVertex2d(0, 0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex2d(0, 1800);
  glColor3f(0.5, 0.0, 1.0);
  glVertex2d(2000, 1800);
  glColor3f(1.0, 0.0, 1.0);
  glVertex2d(2000, 0);
  glEnd();
}

 //========================================================================================================
 //===============================================FRONT PAGE================================================
 //=========================================================================================================
void displayfirst(void){
  glClearColor(1.0, 1.0,1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  background();
  glLoadIdentity();
  glColor3f(1, 0, 1);
  println(390.0, 470.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"   SDM INSTITUTE OF TECHNOLOGY , UJIRE   ");
  glColor3f(1, 0, 0);
  println(330.0, 440.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
  glColor3f(0.0,1.0, 0.7);
  println(290.0, 405.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT (18CSL67)  ");
  glColor3f(1, 1, 0);
  println(380.0, 370.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "  A MINI PROJECT ON SHORTEST JOB FIRST");
  glColor3f(0.75,0.75,0.75);
  println(25.0, 130.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "SUBMITTED BY:");
  glColor3f(0.9, 0.4, 0.5);
  println(25.0, 100.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Anusha                                       4SU20CS011");          
  glColor3f(0.9, 0.4, 0.5);
  println(25.0, 70.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Bhoomika Avabhratha               4SU20CS017");     
  glColor3f(0.9, 0.4, 0.5);
  println(25.0, 40.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Darshan Parameshwar Moger   4SU20CS024"); 
  glColor3f(0.75,0.75,0.75);
  println(950.0, 130.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24, "GUIDE:");
  glColor3f(0.9, 0.4, 0.5);
  println(950.0, 100.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Dr.Raghavendhra Patil");
  glColor3f(0.9, 0.4, 0.5);
  println(950.0, 70.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Asst. Professor");
  glColor3f(0.7, 0.7, 1.0);
  println(490.0, 300.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"MENU PAGE : Press M");
  glutKeyboardFunc(key1);
  glFlush();
  glutPostRedisplay();
  glutSwapBuffers();
}

//========================================================================================================
 //===============================================MENU PAGE================================================
 //=========================================================================================================
void mainpage() {
  glClearColor(0.5, 0.4,0.6, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(0, 0, 0);
  println(520.0, 385.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"   MENU PAGE  ");
  //glColor3f(0, 0, 0);
 // println(530.0, 350.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"MENU");
  glColor3f(0, 0, 0);
  println(450.0, 330.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"ABOUT                      :         PRESS A");
   glColor3f(0, 0, 0);
  println(450.0, 290.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"FLOW CHART          :         PRESS F");
  glColor3f(0, 0, 0);
  println(450.0, 250.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"HELP                          :         PRESS H");
  glColor3f(0, 0, 0);
  println(450.0, 210.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"QUIT                           :         PRESS Q");
  glColor3f(0, 0, 0);
  println(450.0, 170.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"STARTING PAGE     :        PRESS S");
  glFlush();
  glutPostRedisplay();
  glutSwapBuffers();
} 

 //========================================================================================================
 //===============================================HELP PAGE================================================
 //=========================================================================================================
void help() {
	glClearColor(0.5, 0.5, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	 glColor3f(0.4,0.0,0.4);
	println(490.0, 480.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24," *  HELP PAGE *");
	println(470.0, 450.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Shortest Job First Algorithm");

	 glColor3f(0.29,1.2,0.3);
	println(50.0, 400.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Shortest Job First is a scheduling policy that selects the waiting process with the smallest execution time to execute next");
	println(50.0, 375.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"Shortest Job First has the advantage of having a minimum average waiting time among all scheduling algorithms");
	 glColor3f(0.4,0.1,0.4);
	println(50.0, 325.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"ALGORITHM:");
	glColor3f(0.29,1.2,0.3);
	println(50.0, 300.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"1) Sort all the processes according to the burst time in ascending order.  ");
	println(50.0, 260.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"2) Execute the process with shortest burst time. ");
	println(50.0, 220.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"3) Calculate the Waiting time and Turnaround time for the executed process. ");
	println(50.0, 180.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"4) Repeat the steps 2-3 until all processes are executed. ");
	println(50.0, 140.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24," 5) Calculate the average Waiting Time and Average Turn Around time ");
    glColor3f(0, 0, 0);
    println(25.0, 50.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"BACK            : Press B");
    glutKeyboardFunc(key1);
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
} 
 //========================================================================================================
 //===========================================FLOW CHART PAGE===============================================
 //=========================================================================================================

   void flowchart(void)
{	
	glLineWidth(3);
    glClearColor(0.75, 0.75, 0.75, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	glColor3f(0, 0, 1);
    println(490.0, 480.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"FLOW CHART");
	//start
	glColor3f(0,0,1);
	println(485.0,450.0,0.0,GLUT_BITMAP_9_BY_15 ,"Start");
	delayf();
	glFlush();
	delayf();
	//oval s
	glColor3f(0,0,0);
	drawCircle(500.0,450.0,20.0);//start circle
	delayf();
	glFlush();
	delayf();

	//draw line
	glBegin(GL_LINES);
	glVertex2f(500,430);
	glVertex2f(500,415);
	glEnd();
	//draw arrow down
	glColor3f(0,0,0);
	drawArrowd(500,415,4.0);
	delayf();
	glFlush();
	delayf();
	//draw rectangle1
	glColor3f(0,0,0);
    drawRectangle(450,375,90,40);
	delayf();
	glFlush();
	delayf();

	glColor3f(0,0,1);
	println(457.0,400.0,0.0,GLUT_BITMAP_9_BY_15 ,"process in ");
	println(456.0,385.0,0.0,GLUT_BITMAP_9_BY_15 ,"ready queue?");
	delayf();
	glFlush();
	delayf();

	//draw line
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2f(495,375);
	glVertex2f(495,360);
	glEnd();
	//draw arrow down
	glColor3f(0,0,0);
	drawArrowd(495,360,4.0);
	delayf();
	glFlush();
	delayf();
	//no
	glColor3f(0,0,1);
	println(500.0,365.0,0.0,GLUT_BITMAP_9_BY_15 ,"No");
	delayf();
	glFlush();
	delayf();

	//draw rhombus
	glColor3f(0,0,0);
	drawRhombus(450,316,45);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(460,319,0.0,GLUT_BITMAP_9_BY_15,"initialize ");
	println(475,304,0.0,GLUT_BITMAP_9_BY_15,"ready ");
	println(476,290,0.0,GLUT_BITMAP_9_BY_15,"queue ");
	delayf();
	glFlush();
	delayf();

	//draw line rhombus1
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(535,320);
	glVertex2f(850,320);
	glEnd();
	//draw line rhombus2
	glBegin(GL_LINES);
	glVertex2f(850,320);
	glVertex2f(850,310);
	glEnd();
	//draw arrow down rhombus2
	glColor3f(0,0,0);
	drawArrowd(850,310,4.0);
	delayf();
	glFlush();
	delayf();
	//draw rectangle3
	glColor3f(0,0,0);
    drawRectangle(800,260,100,50);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(805.0,300.0,0.0,GLUT_BITMAP_9_BY_15 ,"select process");
	println(805.0,285.0,0.0,GLUT_BITMAP_9_BY_15 ,"with shortest");
	println(805.0,270.0,0.0,GLUT_BITMAP_9_BY_15 ,"burst time");
	delayf();
	glFlush();
	delayf();
	
	//draw line rectangle3
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(848,260);
	glVertex2f(848,250);
	glEnd();
	//draw arrow down rectangle3
	glColor3f(0,0,0);
	drawArrowd(848,250,4.0);
	delayf();
	glFlush();
	delayf();
	
	//draw rectangle4
	glColor3f(0,0,0);
    drawRectangle(800,200,100,50);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(805.0,240.0,0.0,GLUT_BITMAP_9_BY_15 ,"Execute the");
	println(805.0,225.0,0.0,GLUT_BITMAP_9_BY_15 ,"selected");
	println(805.0,210.0,0.0,GLUT_BITMAP_9_BY_15 ,"process");
	delayf();
	glFlush();
	delayf();

	//draw line rectangle1
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(980,395);
	glVertex2f(980,225);
	glEnd();
	//draw line rectangle1
	glBegin(GL_LINES);
	glVertex2f(980,225);
	glVertex2f(900,225);
	glEnd();
	//draw line rectangle1
	glBegin(GL_LINES);
	glVertex2f(540,395);
	glVertex2f(980,395);
	glEnd();
	//draw arrow left
	glColor3f(0,0,0);
	drawArrowl(540,395,4.0);
	delayf();
	glFlush();
	delayf();

	//draw line rectangle 4
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(800,225);
	glVertex2f(493,225);
	glEnd();
	//draw line rectangle 4
	glBegin(GL_LINES);
	glVertex2f(493,225);
	glVertex2f(493,217);
	glEnd();
	//draw arrow down rectangle2
	glColor3f(0,0,0);
	drawArrowd(493,217,4.0);
	delayf();
	glFlush();
	delayf();

	//draw rectangle2
	glColor3f(0,0,0);
    drawRectangle(450,160,100,57);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(455.0,207.0,0.0,GLUT_BITMAP_9_BY_15 ,"Calculate");
	println(455.0,192.0,0.0,GLUT_BITMAP_9_BY_15 ,"waiting time");
	println(455.0,177.0,0.0,GLUT_BITMAP_9_BY_15 ,"and turn");
    println(455.0,162.0,0.0,GLUT_BITMAP_9_BY_15 ,"around time");
	delayf();
	glFlush();
	delayf();
	//draw line rectangle1
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(450,395);
	glVertex2f(360,395);
	glEnd();
	
	//draw line rectangle1
	glBegin(GL_LINES);
	glVertex2f(360,395);
	glVertex2f(360,190);
	glEnd();
	
	//draw line rectangle1
	glBegin(GL_LINES);
	glVertex2f(360,190);
	glVertex2f(450,190);
	glEnd();

	//draw right arrow
	glColor3f(0,0,0);
	drawArrowr(450,190,4.0);
	delayf();
	glFlush();
	delayf();

	//yes
	glColor3f(0,0,1);
	println(395.0,405.0,0.0,GLUT_BITMAP_9_BY_15 ,"Yes");
	delayf();
	glFlush();
	delayf();
	//draw line rectangle 2
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(493,160);
	glVertex2f(493,140);
	glEnd();
	//draw line rectangle 2
	glBegin(GL_LINES);
	glVertex2f(493,140);
	glVertex2f(801,140);
	glEnd();
	//draw right arrow
	glColor3f(0,0,0);
	drawArrowr(799,140,4.0);
	delayf();
	glFlush();
	delayf();
	//draw rectangle5
	glColor3f(0,0,0);
    drawRectangle(800,110,100,60);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(805.0,160.0,0.0,GLUT_BITMAP_9_BY_15 ,"Update the ");
	println(805.0,145.0,0.0,GLUT_BITMAP_9_BY_15 ,"waiting time");
	println(805.0,130.0,0.0,GLUT_BITMAP_9_BY_15 ," and turn ");
	println(805.0,115.0,0.0,GLUT_BITMAP_9_BY_15 ,"around time");
	delayf();
	glFlush();
	delayf();
	
	//draw line rectangle5
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(848,110);
	glVertex2f(848,100);
	glEnd();
	//draw arrow down rectangle5
	glColor3f(0,0,0);
	drawArrowd(848,100,4.0);
	delayf();
	glFlush();
	delayf();


	//draw rectangle6
	glColor3f(0,0,0);
    drawRectangle(800,60,100,40);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(808.0,85.0,0.0,GLUT_BITMAP_9_BY_15 ,"Remove from");
	println(808.0,70,0.0,GLUT_BITMAP_9_BY_15 ,"ready queue");
	delayf();
	glFlush();
	delayf();

	//draw line rectangle5
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(800,80);
	glVertex2f(495,80);
	glEnd();
	//draw line rectangle5
	glBegin(GL_LINES);
	glVertex2f(495,80);
	glVertex2f(495,70);
	glEnd();
	//draw arrow down rectangle5
	glColor3f(0,0,0);
	drawArrowd(495,70,4.0);
	delayf();
	glFlush();
	delayf();

	//exit circle
	glColor3f(0,0,0);
	drawCircle(495.0,50.0,20.0);
	delayf();
	glFlush();
	delayf();
	glColor3f(0,0,1);
	println(484.0,50.0,0.0,GLUT_BITMAP_9_BY_15 ,"End");
	delayf();
	glFlush();
	delayf();
    //
	glColor3f(0, 0, 0);
    println(25.0, 50.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"BACK            : Press B");
	glutKeyboardFunc(key1);
    glFlush();
    //glutPostRedisplay();
    glutSwapBuffers();	
}
   void drawCircle(float cx, float cy, float radius) {//to draw circle
    int numSegments = 100;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float px = 40 * cos(theta);
        float py = 20 * sin(theta);
        glVertex2f(cx + px, cy + py);
    }
    glEnd();
}
   void drawArrowd(float x, float y, float size) {//to draw arrow down
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x - size, y + size);

    glVertex2f(x, y);
    glVertex2f(x + size, y + size);

    glVertex2f(x - size, y + size);
    glVertex2f(x + size, y + size);
    glEnd();
}

   void drawRectangle(float x, float y, float width, float height) {//to draw rectangle
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}
   //to draw rhombus//
   void drawRhombus(float x, float y, float size) {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + size, y - size);
    glVertex2f(x + 2 * size, y);
    glVertex2f(x + size, y + size);
    glEnd();
}
void drawArrowr(float x, float y, float size) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x - size, y - size);

    glVertex2f(x, y);
    glVertex2f(x - size, y + size);

    glVertex2f(x - size, y - size);
    glVertex2f(x - size, y + size);
    glEnd();
}
void drawArrowl(float x, float y, float size) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size, y - size);

    glVertex2f(x, y);
    glVertex2f(x + size, y + size);

    glVertex2f(x + size, y - size);
    glVertex2f(x + size, y + size);
    glEnd();
}

 //=========================================================================================================
 //=========================================================================================================
 //===============================================ABOUT PAGE================================================
 //=========================================================================================================
void about(void)
{
    glClearColor(0.4, 0.6, 0.6, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.2, 0.0, 0.4);
    println(490.0, 480.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24," * ABOUT PAGE *");
    glColor3f(0, 0, 0);
    println(25.0, 50.0, 0.0, GLUT_BITMAP_TIMES_ROMAN_24,"BACK            : Press B");
	glColor3f(0.0,0.0,1.0);
	println(40,450,0.0, GLUT_BITMAP_TIMES_ROMAN_24," NAME: ANUSHA ");
	println(40,430,0.0, GLUT_BITMAP_TIMES_ROMAN_24," USN:   4SU20CS011 ");
	println(40,410,0.0, GLUT_BITMAP_TIMES_ROMAN_24," ADDRESS:  KUNDAPURA  ");
	println(40,390,0.0, GLUT_BITMAP_TIMES_ROMAN_24," EMAIL:  anushetty2543@gmail.com");
    println(40,370,0.0, GLUT_BITMAP_TIMES_ROMAN_24," CONTACT:  8217721890");
	//glColor3f(0.6,0.3,0.4);
	println(400,300,0.0, GLUT_BITMAP_TIMES_ROMAN_24," NAME: BHOOMIKA AVABHRATHA");
	println(400,280,0.0, GLUT_BITMAP_TIMES_ROMAN_24," USN:  4SU20CS017  ");
	println(400,260,0.0, GLUT_BITMAP_TIMES_ROMAN_24," ADDRESS:  KUNDAPURA ");
	println(400,240,0.0, GLUT_BITMAP_TIMES_ROMAN_24," EMAIL:  avabhrathabhoomi@gmail.com");
    println(400,220,0.0, GLUT_BITMAP_TIMES_ROMAN_24," CONTACT: 7204864998 ");
	//glColor3f(0.6,0.3,0.4);
	println(750,140,0.0, GLUT_BITMAP_TIMES_ROMAN_24," NAME:  DARSHAN PARAMESHWAR MOGER ");
	println(750,120,0.0, GLUT_BITMAP_TIMES_ROMAN_24," USN:   4SU20CS024  ");
	println(750,100,0.0, GLUT_BITMAP_TIMES_ROMAN_24," ADDRESS:  BHATKAL");
	println(750,80,0.0, GLUT_BITMAP_TIMES_ROMAN_24," EMAIL:  darshanmoger54@gmail.com");
    println(750,60,0.0, GLUT_BITMAP_TIMES_ROMAN_24," CONTACT: 6360364431  ");
	glutKeyboardFunc(key1);
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();	
}
void init() {
  glClearColor(1,1,1,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0,1200,0,500);
  glMatrixMode(GL_MODELVIEW);
  for(int i=0;i<=7;i++)
        same[i]=1;
}

void setFont(void *font)
{
	currentfont=font;
}

void restart()
{
    front=-1,rear=-1,pt=0,total=0;
    co=0;tb=0;
    one=1,np=1;btotal=0;keypa=1;
}

void add(int c) //Insert element c into the queue
{
    if(front==-1)
        front=0;
    q[++rear]=c;
}

int rem() //Remove element and return it from the queue
{
    if(rear<front)
    {
        front=rear=-1;
        return -1;
    }
    else
        return q[front++];
}

void insert(int pos,int c) //Insert element c into the queue at a given position
{
    int dr;
    dr=rear;
    int i;
    for(i=dr;i>=pos;i--)
    {
        q[i+1]=q[i];
    }
    q[pos]=c;
    rear++;
}

void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    displayfirst();
}
 //========================================================================================================
 //=========================================Print the queue================================================
 //========================================================================================================
void printq() //
{
    int i;
    if(front!=-1 && front<=rear)
        for(i=front;i<=rear;i++)
        {
            printf("%d \t",q[i] );
        }
    else printf("Queue empty\n");
    printf("\n" );
}
 //========================================================================================================
 //===============================Sort the queue according to their arrival time============================
 //========================================================================================================
void sort1() //
{
    int i,j,temp;
    for(i=0;i<n;i++)
        add(i);
    printf("before sorting\n");
    printq();
    printf("after sorting\n");
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
        {
            if(process[q[j]].at>process[q[j+1]].at)
            {
                temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
    printq();
    pt = total = process[q[front]].at;
}
 //========================================================================================================
 //====================================Display Gantt chart on terminalto===================================
 //========================================================================================================
void display(int pno1)
{	
    wt=wt+total;
    printf("-%d |%d| %d- \n",pt,pno1,total);
    p[co].ct=pt;
    p[co].st=total;
    co++;
}
 //========================================================================================================
 //=================Check if new processes have arrived up until the current total=========================
 //========================================================================================================
void checkForArrivals(int cp)
{
    int ofront=front,orear=rear;
    while(ofront<=orear)
    {
        if(process[q[ofront]].at<=total)
        {
            ofront++;
        }
        else{
            insert(ofront, cp);
            return;
        }
    }
    add(cp);
}

void delay()
{
    for(int i=0;i<35000;i++)
        for(int j=0;j<5000;j++);
}

void delay2()
{
    for(int i=0;i<35000;i++)
        for(int j=0;j<10000;j++);
}

 //========================================================================================================
 //=============================Prints the characters on screen at x,y=====================================
 //=========================================================================================================
void strin(char *p,int n,GLint x,GLint y)
{	
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_9_BY_15 , p[i] );
}
//same as above with different font
void stri(char *p,int n,GLint x,GLint y)
{
    glColor3f(1,0.9,0);
    glRasterPos2f(x,y);
    for(int i=0;i<n;i++)
        glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24 , p[i] );
}
 //========================================================================================================
 //==========================================To show the constraints=======================================
 //========================================================================================================
void constr()
{
	glLoadIdentity();
    int p=15,q=200;
    glColor3f(1,0,0);
    strin("Please note:",12,p,q);
    strin("________",12,p,q-4);
    strin("-> The number of processes is limited to 5.",43,p,q-(30*1));
    strin("-> All processes must arrive before 7sec.",41,p,q-(30*2));
    strin("-> Total burst time of all the processes must not exceed 30.",60,p,q-(30*3));
	glColor3f(0,0,1);
    strin("PRESS R or r TO RESET THE PROGRAM",33,250,300);
    glColor3f(0.0,0.0,0.0);
    strin("Made by Anusha, Bhoomika & Darshan",40,5,25);
   
}
 //========================================================================================================
 //==========================================to ask for number of process===================================
 //========================================================================================================
void backgrnp()
{
	glLoadIdentity();
    stri("Enter the number of processes:",30,15,375);
    constr();
    glFlush();
}
 //========================================================================================================
 //=======================================to get arrival time==============================================
 //=========================================================================================================
void backgrat()
{
	glLoadIdentity();
    stri("Enter the arrival time of processes: ",37,15,375);
    constr();
    glFlush();
}

 //========================================================================================================
 //=========================================to get the burst time==========================================
 //========================================================================================================
void backgrbt()
{
	glLoadIdentity();
    stri("Enter the burst time of processes: ",35,15,375);
    constr();
    glFlush();
}


 //========================================================================================================
 //=========================Prints arrival time and burst time in the table================================
 //=========================================================================================================
void pro()
{	
    int j;
    char a;
    for( j=0;j<n;j++)
    {
        a='0'+p[j].at;
        strin(&a,1,183,378-(25*(j+2)));
        a='0'+p[j].bt;
        strin(&a,1,295,378-(25*(j+2)));
    }
}
 //========================================================================================================
 //===============================//draws rectangle for gantt chart==========================================
 //=========================================================================================================

void drawrec(int pa,int qa,int ra, int sa)
{	
	glLineWidth(3);
    int ya=qa,width=pa-ra,height= sa-qa;
    int count,delay=300;
    for(count=ra;count<=ra+width;count++)
    {
        glBegin(GL_LINES);
        glVertex2i(count,ya);
        glVertex2i(count, ya+height);
        glEnd();
        glFlush();
        //usleep(delay);
        delay=delay+50;
    }
}
 //========================================================================================================
 //=========================draws a black rectangle exterior to the above rectangle========================
 //=========================================================================================================
void drawloop(int p,int q,int r, int s)
{	
	glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(p,q);
    glVertex2f(p,s);
    glVertex2f(r,s);
    glVertex2f(r,q);
    glEnd();
}
 //========================================================================================================
 //==================================To draw the scale======================================================
 //=========================================================================================================
void drawscale()
{
    int i,j;
    char a;
    glLineWidth(4.0);
    glColor3f(1,1,1.0);
    glBegin(GL_LINES);
    glVertex2i(30,140);
    glVertex2i(1131,140);
    for(i=1;i<=30;i++)
    {
        glVertex2f(30+basic*i,145);
        glVertex2f(30+basic*i,141);
    }
    glEnd();
    for(i=0;i<=30;i++)
    {
        if(i<10)
        {
            a='0'+i;
            strin(&a,1,27+basic*i,147);
        }
        else if(i>9 && i<20)
        {
            j=1;
            a='0'+j;
            strin(&a,1,24+basic*i,147);
            a='0'+(i%10);
            strin(&a,1,32+basic*i,147);
        }
        else if(i==30)
        {
            j=3;
            a='0'+j;
            strin(&a,1,27+basic*i,147);
            a='0'+(i%10);
            strin(&a,1,32+basic*i,147);
        }
        else
        {
            j=2;
            a='0'+j;
            strin(&a,1,27+basic*i,147);
            a='0'+(i%10);
            strin(&a,1,32+basic*i,147);
        }
    }
    glFlush();
}
 //========================================================================================================
 //=====================================print arrival time on top============================================
 //=========================================================================================================
void arri(int po)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].at<=p[po].ct)
        {
            glColor3fv(col[i]);
            strin("P",1,30+36*p[i].at-8,173);
            strin(&p[i].name,1,30+36*p[i].at,173);
            glBegin(GL_LINES);
            glVertex2i(30+36*p[i].at,170);
            glVertex2i(30+36*p[i].at,160);
            glVertex2i(30+36*p[i].at+2,163);
            glVertex2i(30+36*p[i].at,160);
            glVertex2i(30+36*p[i].at-2,163);
            glVertex2i(30+36*p[i].at,160);
            glEnd();
        }
    }
    glFlush();
    glColor3f(0.0,0.87,.803);
}
 //========================================================================================================
 //=================================Print the number with decimals===========================================
 //=========================================================================================================
void prinum(int x,int y,float num)
{
    int r=(int)num,q=(((int)(num*10))%10),p=(((int)(num*100))%10);
    char a;
    if(r>9)
    {
        a='0'+(r/10);
        strin(&a,1,x,y);
        a='0'+(r%10);
        stri(&a,1,x+8,y);
        stri(".",1,x+16,y);
        a='0'+q;
        stri(&a,1,x+24,y);
        a='0'+p;
        stri(&a,1,x+32,y);
        stri(" ms",3,x+40,y);
        glFlush();
        return;
    }
    a='0'+r;
    stri(&a,1,x,y);
    stri(".",1,x+8,y);
    a='0'+q;
    stri(&a,1,x+16,y);
    a='0'+p;
    stri(&a,1,x+24,y);
    glFlush();
}
 //========================================================================================================
 //======================================Print average wait time and turn around time=======================
 //=========================================================================================================
void avg()
{
   int turnAroundTime[20],WaitingTime[20],tTurnAroundTime=0,tWaitingTime=0;

   for(int i=0;i<n;i++)
   {
       turnAroundTime[i] = p[i].st-p[i].at;
       WaitingTime[i] = turnAroundTime[i] - p[i].bt;
       tTurnAroundTime = tTurnAroundTime + turnAroundTime[i];
       tWaitingTime = tWaitingTime + WaitingTime[i];
   }
   float tWait = tWaitingTime/(float)n;
   float tTurn = tTurnAroundTime/(float)n;
   printf("awt = %f att = %f\n",tWait,tTurn);
   stri("Average Waiting Time = ",23,30,68);
   stri("Total Turn around Time = ",25,30,40);
   prinum(250,68,tWait);
   prinum(255,40,tTurn);
}
 //========================================================================================================
 //==============================================To make the table===========================================
 //=========================================================================================================
void table()
{	
    int p,q,r,s,i;
    char a;
    keypa=0;
    glColor3f(1,1,1);
    p=30;
    q=375-(25*(1+n));
    s=375;
    r=330;
    glLineWidth(4.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(p,q);
    glVertex2i(p,s);
    glVertex2i(r+30,s);
    glVertex2i(r+30,q);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(130,s);
    glVertex2i(130,q);
    glVertex2i(233+13,s);
    glVertex2i(233+13,q);
    glVertex2i(p,350);
    glVertex2i(r+30,350);
    glEnd();
    strin("Process",7,55,355);
    strin("Arrival time",12,135,355);
    strin("Burst time",10,253,355);
    for( i=1;i<=n;i++)
    {
        strin("P",1,75,378-(25*(i+1)));
        a='0'+i-1;
        strin(&a,1,83,378-(25*(i+1)));
    }
    pro();
    glFlush();
    glLineWidth(1.0);
    glColor3f(0.0,0.87,.803);
}
 //========================================================================================================
 //=======================================reshape func======================================================      ==//      NOT WORKING        //==
 //=========================================================================================================
void winReshapeFcn (GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity( );
    gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
    glClear(GL_COLOR_BUFFER_BIT);
    restart();
    keypa=0;
}

 //========================================================================================================
 //===============================================displays options=========================================
 //=========================================================================================================
void displayOptions()
{	
	
    glClear(GL_COLOR_BUFFER_BIT);
    displayText(600, 200, 0, 0, 1,op3);
    displayText(600, 230, 0, 0, 1,op2);
    displayText(600, 260, 0, 0, 1,op1);
    displayText(600, 350, 1, 0, 0,op);
    table();
    char s=tq+'0';
    displayText(135,395,0,0,0,"set of processes  ");
    displayText(135,390,0,0,0,"____________");
}
 //========================================================================================================
 //==============set start time and completion time accordingly for sjf====================================
 //=========================================================================================================
void setValuesForSJF()
{
    int i,j,qb[10],temp,index=0,cp;
    bool flag=true,visited[10];
    float me;
    char a;
    int iof=0;

    for(i=0;i<10;i++)
    {
        visited[i]=false;
    }

    for(i=0;i<n;i++)
    {
        qb[i]=i;
    }

    total=pt=process[0].at;

    for(i=0;i<n-1;i++)
        if(process[i].at>process[i+1].at)
            total=pt=process[i+1].at;


    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
        {
            if(process[qb[j]].rbt>process[qb[j+1]].rbt)
            {
                temp=qb[j];
                qb[j]=qb[j+1];
                qb[j+1]=temp;
            }
        }

    while(flag)
    {
        for(j=0;j<n;j++)
            for(i=0;i<n;i++)
            {
                cp = qb[i];
                if(process[cp].at<=total && !visited[cp])
                {
                    pt = total;
                    total = total + process[cp].rbt;
                    p[iof].ct=pt;
                    p[iof].st=total;
                    p[iof].no=cp; iof++;
                    printf("-%d |%d| %d- \n",pt,cp,total);
                    visited[cp]=true;
                    process[cp].rbt=0;
                    break;
                }
            }
        for(i=0;i<n;i++)
        {
            flag=false;
            if(!visited[i])
            {
                flag=true;
                break;
            }
        }
    }
    drawscale();
	glColor3f(0,0,0);
    strin("Gantt Chart",11,30,158+40);
    strin("________",11,30,156+40);
    for(i=0;i<n;i++)
    {
        glColor3fv(col[qb[i]]);
        drawrec(30+p[i].st*36,100,30+p[i].ct*36,130);
        glLineWidth(2.0);
        glColor3f(0.0,0,0);
        drawloop(30+p[i].st*36,100,30+p[i].ct*36,130);
        glColor3fv(col[q[i]]);
        me=(30+p[i].st*36+30+p[i].ct*36)/2;
        strin("P",1,me-8,88);
        a='0'+p[i].no;
        strin(&a,1,me,88);
        arri(i);
        glFlush();
        delay2();
    }
    glLineWidth(1.0);
    glColor3f(1,.84,.0);
}
 //========================================================================================================
 //===================================execute Shortest Job First============================================
 //=========================================================================================================
void execSJF()
{
    int i;
    for(i=0;i<n;i++)
    {
        process[i].at=p[i].at;
        process[i].rbt=process[i].bt=p[i].bt;
    }
    for(i=0;i<n;i++)
    {
        p[i].name='0'+char(i);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    table();
    displayName("Shortest Job First");
    setValuesForSJF();
    displayText(700, 300, 1, 1, 0,"Press 'm' to go back to the option page");
    avg();
}
 //========================================================================================================
 //===============================================KEYS FUNCTION=============================================
 //=========================================================================================================
void key1(unsigned char k,int x,int y)
{
    char a=k;
    int numb;
 if (k == 'M' || k == 'm') 
 {
     glutDisplayFunc(mainpage); 
  }
  if (k == 'b' || k == 'B') 
  {
     glutDisplayFunc(mainpage);
	 glutPostRedisplay();
  }
  
  if (k == 'a' || k == 'A') 
  {
         glutDisplayFunc(about);
   }
  if (k == 'f' || k == 'F') 
  {
         glutDisplayFunc(flowchart);
   }
  
    if (k == 'h' || k == 'H') 
  {
         glutDisplayFunc(help);
  }
    
	
	if (k == 'q' || k == 'Q') 
  {
     exit(0);
  }
    if(keypa==0 && !doneInput)
    {
        if ( k == 's' || k == 'S'){
			glClearColor(0.4, 0.6, 0.6, 0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			keypa=1;
			glutDisplayFunc(backgrnp);
			glutKeyboardFunc(key1);
			//glutKeyboardFunc(key1);
			glFlush();
			glutSwapBuffers();	
        }
    }
   
    else if(keypa==1 && !doneInput)
    {
	glClear(GL_COLOR_BUFFER_BIT);
        if(isdigit(a) && one==1)
        {
            one=0;
            numb=a-'0';
            if(np==1)
            {
                if(numb<=5)                      //===================TAKEING A PROCESS NUMBER=====================//
                {
                    stri(&a,1,360,375);
					
					delay();
					Sleep(100);
                    backgrnp();
                    np=0;
                    att=numb-1;
                    index1=0;
                    n=numb;
					
                    glClear(GL_COLOR_BUFFER_BIT);
					Sleep(1500);
                    backgrat();
                    one=1;
                }                  
                else
                {
                    for(int k=0;k<3;k++) {
                        glClear(GL_COLOR_BUFFER_BIT);
                        backgrnp();
                        glFlush();
                        glColor3f(1, 1, 1);
                        strin("ERROR", 5, 15, 95);
                        strin("_", 5, 15, 93);
                        strin("Number of processes greater than 5 not allowed ", 47, 15, 80);
                        glFlush();
                        delay();
                        glClear(GL_COLOR_BUFFER_BIT);
                        glClearColor(0.4, 0.6, 0.6, 0.0);
                        backgrnp();
                        delay();
                    }
                    one=1;
                    glClearColor(0.4, 0.6, 0.6, 0.0);
                }
            }
            else if(att>=0)                      //===================TAKING A ARRIVAL TIME=====================//
            {
                if(numb<=30)
                {
                    same[numb]=0;
                    stri(&a,1,430,375);
                    att--;
                    delay();
                    backgrat();

                    p[index1++].at=numb;
                    one=1;
                    if(att<0)
                    {
                        delay();
                        glClear(GL_COLOR_BUFFER_BIT);
                        btt=n-1;
                        index1=0;
						Sleep(1300);
                        backgrbt();                
                    }
                    glClear(GL_COLOR_BUFFER_BIT);
                }
            }
            else if(btt>=0)                      //===================TAKING A BURST TIME=====================//
            {
                if(numb<=30)
                {
                    stri(&a,1,410,375);
                    delay();
                    btt--;
				
                    backgrbt();                 
                    tb=tb+numb;
                    p[index1++].bt=numb;
                    btotal+=numb;
                    if(tb>=30) {

                        for (int k = 0; k < 3; k++) {
                            glColor3f(1, 1, 1);
                            strin("ERROR", 5, 15, 95);
                            strin("_", 5, 15, 93);
                            strin("Total burst time greater than 30 not allowed. Restarting the program!", 69, 15, 80);
                            glColor3f(0.0, 0.87, .803);
                            backgrbt();           
                            glFlush();
                            delay();
                            glClear(GL_COLOR_BUFFER_BIT);
							//Sleep(1000);
                            backgrbt();             
                            glFlush();
                            delay();
							Sleep(1000);
                        }
                        one=1;
                        restart();
                        disp();
                    }
                    one=1;
                    glClear(GL_COLOR_BUFFER_BIT);
                    if(btt<0)
                    {
						Sleep(1500);
                        delay();
						doneInput=true;
						glClear(GL_COLOR_BUFFER_BIT);
						glFlush();
						displayOptions();
                    }
                }
            }
        }
        else if(k=='R'||k=='r')
        {
            np=1;
            glClear(GL_COLOR_BUFFER_BIT);
            backgrnp();
        }
        else
        {
            glColor3f(1,1,1);
            stri("ERROR",5,15,83);
            stri("___",5,15,80);
            stri("Number not pressed",18,15,50);
            glClearColor(0.4, 0.6, 0.6, 0.0);
            if(np==1)
                backgrnp();
            else if(att==1)
                backgrat();
            else
                backgrbt(); 
            glFlush();
            one=1;
        }
    }
    else if(doneInput)
    {
        switch(a)
        {
            case '1': execSJF();
                      break;
            case '2': glClear(GL_COLOR_BUFFER_BIT);
                      tq=99;
                      restart();
                      doneInput=false;
                      backgrnp();
                      break;
            case '3': glutDestroyWindow(wid);
                      exit(0);
            case 'm':
            case 'M': restart();
                      doneInput=true;
                      displayOptions();
                      break;
        }
        glFlush();
    }
}
 //========================================================================================================
 //===============================================MAIN FUNCTION=============================================
 //=========================================================================================================
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1700, 780);
    wid =  glutCreateWindow("Process Scheduling");
    init();
    glutDisplayFunc(displayfirst);
    glutKeyboardFunc(key1);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
return 0;
}
