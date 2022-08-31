#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <passe_par_tout.h>
//#include <string>
using namespace std;

const double h=0.01;

double a=0.40;            //0.40
double b=0.005;           //0.005
double c=0.002;           //0.002  
double d=0.17;            //0.17

double *Y= new double[2];
double *Z= new double[2];
double *W= new double[2];

double x_0[2];
double x_new[2];
int t;
double **Q=new double *[3]; 
/*double *T=new double [t* 100];
double *P1=new double [t* 100];
double *P2=new double [t* 100];*/
int r=0;

void bitmap_output(int x, int y, const char *string ,void *font)
{
  int len, i;
//const char *string="prede";
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}


void display (void)
{

//GRAFICO
glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);
                    
glBegin (GL_LINE_STRIP);

for (int i=0; i< t*100 ; i++){

glVertex2d (Q[0][i], Q[1][i]);                                  //glVertex2d (t0, x_new[0]); 

}

glEnd();  
//glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glColor3f (1.0, 0.0, 0.0);
                    
glBegin (GL_LINE_STRIP);

for (int i=0; i< t*100 ; i++){

//glVertex2d (x_new[0], x_new[1]);
glVertex2d (Q[0][i], Q[2][i]);                                  //glVertex2d (t0, x_new[0]); 
//glEnd();
}

glEnd();

//AL MASSIMO CANCELLA

glColor3f(1.0,1.0,1.0);

bitmap_output(450, -10, "tempo",
    GLUT_BITMAP_HELVETICA_18);          //HELVETICA_18
bitmap_output(-5.0, 460.0, "popolazione", GLUT_BITMAP_HELVETICA_18);

bitmap_output(90, -15, "100", GLUT_BITMAP_HELVETICA_18);

bitmap_output(190, -15, "200", GLUT_BITMAP_HELVETICA_18);

bitmap_output(290, -15, "300", GLUT_BITMAP_HELVETICA_18);

bitmap_output(390, -15, "400", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 95, "100", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 195, "200", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 295, "300", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 395, "400", GLUT_BITMAP_HELVETICA_18);


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(400.0,400.0);
glVertex2d(420.0,400.0);
glEnd();
bitmap_output(425, 400, "Prede", GLUT_BITMAP_HELVETICA_18);

glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);
glVertex2d(400.0,380.0);
glVertex2d(420.0,380.0);
glEnd();
bitmap_output(425, 380, "Predatori", GLUT_BITMAP_HELVETICA_18);



glBegin(GL_LINES);
// draw line for x axis
glColor3f(1.0, 1.0, 1.0);
glVertex2d(0.0, 0.0);
glVertex2d(450.0, 0.0);
glEnd();

glBegin(GL_LINES);
// draw line for y axis
glColor3f(1.0, 1.0, 1.0);
glVertex2d(0.0, 0.0);
glVertex2d(0.0, 450.0);
glEnd();


//cose nuove
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(100.0,4.0);
glVertex2d(100.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(200.0,4.0);
glVertex2d(200.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(300.0,4.0);
glVertex2d(300.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(400.0,4.0);
glVertex2d(400.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,0.0);
glVertex2d(-4.0,-0.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,100.0);
glVertex2d(-4.0,100.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,200.0);
glVertex2d(-4.0,200.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,300.0);
glVertex2d(-4.0,300.0);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,400.0);
glVertex2d(-4.0,400.0);
glEnd();

glFlush ();
glutSwapBuffers();

}



void display1 (void)
{

//GRAFICO
glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glColor3f (1.0, 1.0, 1.0);
                    
glBegin (GL_LINE_STRIP);

for (int i=0; i< t*100 ; i++)
glVertex2d (Q[1][i], Q[2][i]);                                  //glVertex2d (t0, x_new[0]); 

glEnd();

glBegin(GL_LINES);
// draw line for x axis
glColor3f(1.0, 1.0, 1.0);
glVertex2d(0.0, 0.0);
glVertex2d(470.0, 0.0);
glEnd();

glBegin(GL_LINES);
// draw line for y axis
glColor3f(1.0, 1.0, 1.0);
glVertex2d(0.0, 0.0);
glVertex2d(0.0, 470.0);
glEnd();

//se non serve cancella
glColor3f(1.0,1.0,1.0);

bitmap_output(450, -15, "formiche",
    GLUT_BITMAP_HELVETICA_18);          //HELVETICA_18
bitmap_output(-8.0, 480.0, "formichieri", GLUT_BITMAP_HELVETICA_18);

bitmap_output(90, -15, "100", GLUT_BITMAP_HELVETICA_18);

bitmap_output(190, -15, "200", GLUT_BITMAP_HELVETICA_18);

bitmap_output(290, -15, "300", GLUT_BITMAP_HELVETICA_18);

bitmap_output(390, -15, "400", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 95, "100", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 195, "200", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 295, "300", GLUT_BITMAP_HELVETICA_18);

bitmap_output(-30, 395, "400", GLUT_BITMAP_HELVETICA_18);

     //cose nuove
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(100.0,4.0);
glVertex2d(100.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(200.0,4.0);
glVertex2d(200.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(300.0,4.0);
glVertex2d(300.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(400.0,4.0);
glVertex2d(400.0,-4.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,0.0);
glVertex2d(-4.0,-0.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,100.0);
glVertex2d(-4.0,100.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,200.0);
glVertex2d(-4.0,200.0);
glEnd();


glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,300.0);
glVertex2d(-4.0,300.0);
glEnd();

glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex2d(4.0,400.0);
glVertex2d(-4.0,400.0);
glEnd();

glFlush ();
glutSwapBuffers();

}


void init (void) 
{
glLineWidth (3.0);
glPointSize (3.0);
/* select clearing color 	*/
   //glClearColor (2.0, 1.0, 0.0, 2.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-38.0, 500.0, -20.0, 500.0, -1.0, 1.0);
}


double massimo1 (double *M )
{
double maximum=0;

for (int i=0; i<t*100; i++)
{if(M[i]>maximum)
maximum=M[i];}
return maximum; }

double massimo2 (double *M)
{
double maximum=0;

for (int i=0; i<t*100; i++)
{if (M[i]>maximum)
maximum=M[i];}
return maximum;} 


double minimo1 (double *N)
{
double minimum=100000;

for (int i=0; i<t*100; i++)
{if (N[i]<minimum)
minimum=N[i];}
return minimum;}

double minimo2 (double *N)
{
double minimum=100000;

for (int i=0; i<t*100; i++)
{if (N[i]<minimum)
minimum=N[i];}
return minimum;}


int main (int argc, char** argv)

{

cout<<"Fornire valori iniziali di popolazione. Si assume un sistema formato da due popolazioni, una di prede come ad esempio delle formiche, e una di predatori, in questo caso dei formichieri. Il valore inziale della popolazione delle formiche e dei predatori deve essere compreso tra 10 e 250 (e l'ordine di grandezza è dei milioni per uno e delle migliaia per l'altro), mentre il tempo di evoluzione del sistema deve essere compreso tra 5 e 500 anni. Il rapporto dei parametri vale 85 e 80, perciò mettendo questi due valori rispettivamente per prede e predatori, si produce la soluzione di equilibrio ed essi rimaranno costanti. "<<endl;

do{
cout<<"\nFormiche: ";
cin>>x_0[0];

if (!cin){
cout<<"non corretto, ridigitare: "<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n');  
continue;} 

else if (x_0[0]<10 || x_0[0]>250) {
cout<<"numero fuori intervallo, ridigitare"<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n'); 
continue;}        
break;}
while (true);                                                                                                //da 10 a 250

do{
cout<<"\nFormichieri: ";                                                                                              //da 10 a 250
cin>>x_0[1];

if (!cin) {
cout<<"non corretto, ridigitare: "<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n');  
continue;}

else if (x_0[1]<10 || x_0[1]>250) {
cout<<"numero fuori intervallo, ridigitare"<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n'); 
continue;}
break;}
while (true);

do {
cout<<"\n\nImmetti il tempo per cui vuoi che il programma studi l'evoluzione del sistema:"<<endl;                    //da 5 tipo a 499
cin>>t; 

if (!cin) 
{
cout<<"non corretto, ridigitare: "<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n');  
continue;}

else if (t<5 || t>500)
{cout<<"numero fuori intervallo, ridigitare"<<endl;
char c;
cin.clear();
do;
while((c=cin.get()) != '\n'); 
continue;}
break;}
while (true);


cout<<setw(10)<<"Le formiche si evolvono: "<<"           "<<"i formichieri si evolvono: "<<endl;

//double *H=new double [t*100];

Q[0]=new double [t* 100];
Q[1]=new double [t* 100];
Q[2]=new double [t* 100];

for (double t0=0; t0 < t; t0 += h)    
    {

double f_x[2] = {(a - b*x_0[1]) * x_0[0], (c*x_0[0] - d) * x_0[1]};
 

  for (int i=0; i<2; ++i)
  Y[i]= x_0[i]+ (h/2.0)*f_x[i];
 
double f_y[2] = {(a - b*Y[1])*Y[0], (c*Y[0]-d)*Y[1]};


  for (int i=0; i<2; ++i)
  Z[i]=x_0[i]+ (h/2.0)* f_y[i];

double f_z[2]={ (a-b*Z[1])*Z[0], (c*Z[0]-d)*Z[1]};

 
  for (int i=0; i<2; ++i)
  W[i]=x_0[i]+ h*f_z[i];
 
double f_w[2]={ (a-b*W[1])*W[0], (c*W[0]-d)*W[1]};


  for (int i=0; i<2;++i)   //ALGORITMO
  x_new[i] = x_0[i] + (h/6.0)*(f_x[i]+2*f_y[i]+2*f_z[i]+f_w[i]);  

    
cout<<setw(10)<<setprecision(8)<<fixed<<x_new[0]<<setw(20)<<setprecision(8)<<fixed<<x_new[1];

double H=d*log(x_new[0])-c*x_new[0]-b*x_new[1]+a*log(x_new[1]);


//if (r>0)
cout<<setw(35)<<H<<"\n\n";

for (int i=0; i<2;++i)      
x_0[i]=x_new[i];

Q[1][r]= x_new[0];
Q[2][r]= x_new[1];

Q[0][r]=t0;
++r;
}

cout<<"\n\nil valore massimo delle formiche è: "<<setprecision(4)<<fixed<< massimo1 (Q[1])<<"\n\n";

cout<<"\n\nil valore minimo delle formiche è: "<<setprecision(4)<<fixed<< minimo1(Q[1])<<"\n\n";

cout<<"\n\nil valore massimo dei formichieri è: "<<setprecision(4)<<fixed<< massimo2 (Q[2])<<"\n\n";

cout<<"\n\nil valore minimo dei formichieri è: "<<setprecision(4)<<fixed<< minimo2 (Q[2])<<"\n\n";

int k;
cout<<"Quale grafico vuoi vedere? Premi 1 se desideri vedere la funzione primitiva o 2 se vuoi vedere l'andamento di preda e predatore:  ";
cin>>k;

if(k==1)
{
glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glEnable(GL_DEPTH_TEST);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("primitiva");
   init ();
 glutDisplayFunc(display1);
glutMainLoop();
}
else if (k==2)
{
glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glEnable(GL_DEPTH_TEST);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("andamento");
   init ();
 glutDisplayFunc(display);
glutMainLoop();
}
else {cout<<"ok,nessun grafico"<<endl;

  }
}






