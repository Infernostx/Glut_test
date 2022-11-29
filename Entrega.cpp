//Universidad Nacional de Colombia
//Facultad de Ingeniería
//Departamento de Sistemas e Industrial
//Programación de Computadores

//Primera entrega del proyecto
//Nombre: Miguel Suarez

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <GL/glut.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"  //comentadas para evitar error de compilacion
#define N 100

using namespace std;

// Se tiene pensado integrar archivos para que el usurio pueda editar las respuestas, para eso el arreglo es global
const int Arreglo = 6;
string bolamagica[Arreglo];
char titulo[] = "Bola magica";
int eleccion=0;
string a;
char cstr[N];
float ale =0;
float rotax=0.0;
float rotay=0.0;
float rotaz=0.0; 

//Funciones
void bola8(int a,char** b);
void imprimirBola8(string a, int c);
int imprimirMenuPrincipal();
void init3D(int a,char** b);
void initGL();
void imprime3D();
void modificaVentana(int argh,int argv);
void activaBola(unsigned char key, int xmouse, int ymouse);
void renderizaString(GLfloat x, GLfloat y,GLfloat z,GLfloat s, char* texto);
void inicializoLista();



int main(int argc, char** argv) {
	srand(time(NULL));
	system("CLS");
	inicializoLista();
	int r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	ale=r;
	switch(imprimirMenuPrincipal()){
		case 1:
			eleccion=1;
			bola8(argc,argv); 
			break;
		case 2:
			 eleccion=2;
			 bola8(argc,argv);
			 break;
				
	}
 main(argc,argv);
   return 0;
}

int imprimirMenuPrincipal(){
	int x=0;
	cout<<"\t\t\tBienvenido al Cypher de Miguel\n\n";
	cout<<"Que desea hacer?\n\n";
	cout<<"1.) Bola 8 consola\n";
	cout<<"2.) Bola 8 grafica\n";
	cout<<"3.) Salir\n\n";
	cout<<"Ingrese una opcion:";
	cin>>x;
	cin.ignore();
	system("cls");
	return x;
}
//Funciones de bola 8 consola
void inicializoLista(){
//		bolamagica[0] = "No";
//        bolamagica[1] = "Si";
//        bolamagica[2] = "Puede ser...";
//        bolamagica[3] = "Tal vez";
//        bolamagica[4] = "Lo mas probable es que si";
//        bolamagica[5] = "Lo mas probable es que no";
        
  
  const string archivo = "respuestas.txt";

  ifstream fuente(archivo.c_str());
  
  int leido = 0;
  while (leido < Arreglo && fuente >> bolamagica[leido])
    leido++;

  cout << "Leidas " << leido << " respuestas desde el archivo." << "\n\n";
  for (int i=0;i<Arreglo;i++)
    cout << bolamagica[i] << endl;

  system("pause");
  system("CLS");
        
    }
        
void bola8(int a,char** b){
    //srand ( (0));
    bool Acabar = false;
    string entrada;
    cout << "\t\t\tBienvenid@ a la bola magica!\n\n";
    cout << "Escribe una pregunta de Si o No para responder, o escribe salir para salir del programa.\n";
    while(!Acabar){
        cout << "\nPegunta lo que se te venga a la mente!\n" ;        
        getline(cin, entrada);//Se usa como alternativa a cin y asi evitar la ejecucion al teclear espacio
        if(entrada.compare("salir") == 0)Acabar=true;      
        if(entrada.compare("") != 0 && entrada.compare("salir") != 0 && eleccion==1){
            // cout << bolamagica[rand()%Arreglo] << "\n";
            imprimirBola8(bolamagica[rand()%Arreglo],0);
             entrada = "";
             system("PAUSE");
             system("CLS");
             
        }
		if(entrada.compare("") != 0 && entrada.compare("salir") != 0 && eleccion==2){
			cout << "Controles\nW = Gira arriba\nS = Gira abajo\nA = Gira izquierda\nD = Gira derecha\nI = Mueve hacia adelante\nK = Mueve hacia atras\nR = Cambia el cielo\n" ;
			system("PAUSE");
			init3D(a, b);
			
		}   
    } 
    cout << "Gracias por jugar!\n";   
    system("PAUSE");
    main(a,b);
}

void imprimirBola8(string a,int c){
	float r = 10; 
    float y = 1.0/2.0; //medida
    float x = y*r;     //tamanio
    int mitad=c;
    string msg=a;
    for (int j = -r; j <= r; j++)
    {
    	if(j==0){
    		for (int k = -x*r; k <= r*r; k++){
    			float d = (k/r)*(k/r) + (j/x)*(j/x);
    		if(d>1.1){
    			cout<<" ";
			}            
			if(d<0.9 && d>0.6){	
            	cout<<"@";      	
			}
			if(d==0){
				cout<<"  ";
            	cout<<msg;
            	cout<<"  ";           	
			}           
            if (d > 0.90 && d < 1.1)
            {  
				cout << "*";
            }
			}
				}
		else{				
        for (int k = -x*r; k <= r*r; k++)
        {      	
            float d = (k/r)*(k/r) + (j/x)*(j/x);  
            if(d>1.1){
            	cout<<" ";
			}
			if(d<0.9){	
            	cout<<"@";
			}
            if (d > 0.90 && d < 1.1)
            {
				cout << "*";
            }
        }
    }
        cout << endl;   
    }
}

////Aqui van las funciones relacionadas a opengl, mucha documentacion se ha leido xd
//Se inicializa el visualizador
void init3D(int a,char** b){
	glutInit(&a, b);            // Empieza la libreria GLUT
   			 glutInitDisplayMode(GLUT_DOUBLE); // El modo en el cual se renderizara la ventana
			 glutInitWindowSize(720, 640);   // Ancho y alto de la ventana
			 glutInitWindowPosition(50, 50); // Posicion de la ventana referente a la pantalla
			 glutCreateWindow(titulo);          // Crea la ventana
			 glutDisplayFunc(imprime3D);       // Renderiza la imagen cada segundo
			 glutReshapeFunc(modificaVentana);       // Maneja la modificacion del tama;o de la ventana
			 //glutKeyboardFunc(activaBola);
			 initGL();                       // inicializa OGL
			 glutMainLoop();                 // Loop en main
			 
}
void initGL() {
   glClearColor(0.5, 0, 0.5, 1); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);   
   glOrtho(-250, 250, -250, 250, -250, 250); //Referencia para la camara 
   glDepthFunc(GL_LEQUAL);   
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}
void imprime3D() {
	
	
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glutKeyboardFunc(activaBola);    
 
   
   glLoadIdentity();                 // Empieza la construccion de la bola
   glTranslatef(0.0, 0.0, -7.0);
   gluLookAt(rotax, rotay, rotaz, 0.0,0.0, -1.0f, 0.0f, 1.0f, 0.0f);
   glRotatef(rotax, 1, 0, 0); 
   glColor3f(0,0,0);
   glutSolidSphere(1,80,80);
   glPushMatrix();
   
   glLoadIdentity();                 // Empieza la construccion de las strings
   glTranslatef(-0.5, 0.5, -7.0);
   gluLookAt(rotax, rotay, rotaz, 0.0, 0.0, -1.0f, 0.0f, 1.0f, 0.0f);
   glRotatef(rotax, 1, 0, 0); 
   glColor3f(1,1,1);
   a=bolamagica[rand()%Arreglo];
   cstr[a.size() + 1];
   strcpy(cstr, a.c_str());
   renderizaString(0,1,-1,500+a.length(),cstr);
   glPushMatrix();
   
   glLoadIdentity();                 
   glTranslatef(-0.5, 0.5, -7.0);
   gluLookAt(rotax, rotay, rotaz, 0.0, 0.0, -1.0f, 0.0f, 1.0f, 0.0f);
   glRotatef(rotax, 1, 0, 0); 
   glColor3f(1,1,1);
   renderizaString(0.3,-0.8,1,152.38,"8");
   glPushMatrix();
   
   glLoadIdentity();                 // Empieza la construccion de las strings
   glTranslatef(0.0, -3, -7.0);
   gluLookAt(rotax, rotay, rotaz, 0.0, 0.0, -1.0f, 0.0f, 1.0f, 0.0f);
   glRotatef(rotax, 1, 0, 0); 
   glColor3f(0.5,0.5,0.5);
   glutSolidCube(3);
   
   glPushMatrix();

   

 
   glutSwapBuffers();  // Se encarga de los buffers del renderizado y reescribe la pantalla
}
void modificaVentana(GLsizei width, GLsizei height) {  // Maneja la ventana para el procesado 3D
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();        
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
void renderizaString(GLfloat x, GLfloat y, GLfloat z, GLfloat s, char* texto){ //Muestra las distintas strings
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(1/s, 1/s, 1/s);
    for( char* p = texto; *p; p++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    glPopMatrix();
}


void activaBola (unsigned char key, int xmouse, int ymouse){	// Maneja los eventos relacionados a las entradas
	switch (key){
//		case 'f':
//			renderizaString(0,0.5,0,152.38, "Hola");
//			break;
		case 'r': 
			glClearColor (0.2, 0.2, 1.0, 0.7);
		break;
		case 's': rotay += 1.0f; 
			break;
        case 'w':  rotay -= 1.0f; 
			break;
        case 'd':    rotax -= 1.0f; 
			break;
        case 'a':  rotax += 1.0f;
			 break;
		case 'i':  rotaz -= 1.0f;
			 break;
		case 'k':  rotaz += 1.0f;
			 break;	 	 
		default:
         break;
	}
	glutPostRedisplay();
}
