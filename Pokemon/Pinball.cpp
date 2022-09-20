//--------------------------UNIVERIDAD NACIONAL AUTÓNOMA DE MÉXICO----------------------------------------- //
//----------------------------------COMPUTACIÓN GRÁFICA---------------------------------------------------//
//---------------------------------  Semestre 2018-1 ----------------------------------------------------//
//------------------------------------PROYECTO----------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------//
// -------------------------ALUMNOS: MARTAKO938-----------------------------------------//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito
CFiguras miFigura;

//NEW// Keyframes
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0;
float giroBrazo = 0;

float CuñaI = 0;
float CuñaD = 0;
float CuñaA = 0;


float var = 0.0;
float bmoangle=0.0;
float bmoangle2=0.0;
float bmoangle3=0.0;
float giro = 0.0;

//variables de las eferas
float posX_esf1 = 0, posY_esf1 = 0, posZ_esf1 =0, rot_esf1 = 0;


#define MAX_FRAMES 90
int i_max_steps = 4;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;

	float giroBrazo;
	float giroBrazoInc;


	//BMO
float bmoangle;
float inc1;
float bmoangle2;
float inc2;
float bmoangle3;
float inc3;
float angleY;
float incangleY;
float transX;
float transY;
float transZ;
float incX;		//Variable para IncrementoX
float incY;		//Variable para IncrementoY
float incZ;

//Incrementos esferas
float transX_esf1;
float transY_esf1;
float transZ_esf1;
float incX_esf1;		//Variable para IncrementoX
float incY_esf1;		//Variable para IncrementoY
float incZ_esf1;

	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=5;			//introducir datos
bool play=false;
int playIndex=0;

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 10.0f,25.0f, 1.0f };	// Light Position
GLfloat Position3[]= { 7.0f, 8.0f, 0.0f, 1.0f };	// Light Position   ESQUINA DERECHA ARRIBA  VERDE
GLfloat Position4[]= { -1.0f, 8.0f, 18.0f, 1.0f };	// Light Position   ESQUINA IZQ ABAJO    AZUL

GLfloat FocoDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat FocoSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat FocoPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat Foco2Diffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat Foco2Specular[] = { 0.8, 0.8, 0.8, 0.8 };				// Specular Light Values
GLfloat Foco2Shininess[] = { 50.0 };

GLfloat Foco3Diffuse[]= {  0.0,1.0,0.4, 1.0f };					// Diffuse Light Values
GLfloat Foco3Specular[] = { 1.0, 0.5, 0.0, 1.0 };				// Specular Light Values
GLfloat Foco3Shininess[] = { 50.0 };


//Texturas

CTexture text5;	//Pasto01


//BMO
CTexture cuerpoBMO;
CTexture letrasBMO;
CTexture atrasBMO;

//ICE
CTexture nieve;
CTexture nievep;
CTexture nievem;
CTexture lluvian;

//cielos
CTexture icesky;
CTexture skypasto;
CTexture dulcesky;
CTexture otrosky;

//Dulce reino
CTexture ventana_1;
CTexture pared_1;
CTexture helado_1;
CTexture piso_d;


//Campo
CTexture piso_v;
CTexture tree;

//Figuras
CFiguras cubo;
CFiguras sky;

CFiguras fig3;
CFiguras fig4;	//Pasto01

CFiguras base_mesa;
CFiguras pata_mesa;
CFiguras ventilador;

//hora de aventura
CFiguras bmo; //cuerpo BMO
CFiguras montana;
CFiguras arbolm;
CFiguras tronco;

//Figuras de 3D Studio
//modelos 3ds

CModel candy;
CModel chocolate;

CModel fig1;
CModel fig2;


bool g_fanimacion = false;

//ANIMACIÓN BMO
float transZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float angleY = 0.0f;
float angleX = 0.0f;

//ANIMACION ESFERAS
float transZ_esf1  = 0.0f;
float transX_esf1  = 0.0f;
float transY_esf1  = 0.0f;


int timer = 0;

//funciones objetos

void barda_a(){

glPushMatrix(); // inicio barda
				
				glPushMatrix(); //plano a
					glTranslatef(0, -0.5, 20);
					glRotatef(11,0.0,1.0, 0.0);   //gira 11 grados el primer plano que está a la derecha 
					//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
					glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
					glEnd();
					glPushMatrix(); //plano b
						glTranslatef(7.8, 0, 0);
						glRotatef(23,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
						glEnd();
						glPushMatrix(); //plano c
							glTranslatef(7.8, 0, 0);
							glRotatef(22,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
							//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
							glBegin(GL_QUADS);
								glColor3f(1.0, 1.0, 1.0);
								glNormal3f(0.0, 0.0, 1.0);
								glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
								glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
								glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
								glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
							glEnd();
								glPushMatrix(); //plano d
								glTranslatef(7.8, 0, 0);
								glRotatef(22.5,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
								//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
								glBegin(GL_QUADS);
									glColor3f(1.0, 1.0, 1.0);
									glNormal3f(0.0, 0.0, 1.0);
									glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
									glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
									glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
									glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
								glEnd();
							glPopMatrix();//fin plano d
						glPopMatrix();//fin plano c
					glPopMatrix(); //fin plano b
				glPopMatrix();// fin plano a

			glPopMatrix();//fin barda


}
void barda_completa(){
			glPushMatrix();
				barda_a();
				glPushMatrix();
					glRotatef(90,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					barda_a();
				glPopMatrix();
				glPushMatrix();
					glRotatef(180,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					barda_a();
				glPopMatrix();
				glPushMatrix();
					glRotatef(270,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					barda_a();
				glPopMatrix();
			glPopMatrix();
}

void castillo(){

glPushMatrix(); //GRAN PUSH

		glPushMatrix(); //Inicio castillo
			glTranslatef(25.0, -0.5, 0.0);
			//glScalef(1.0, 4.0, 1.0);
			//glRotatef(180,0.0,1.0, 0.0);
			glColor3f(1, 1, 1);
			miFigura.cilindro(2.0,24.0,20,ventana_1.GLindex);  //cilindro principal

			//Secciones de la barda
			barda_completa();

			glPushMatrix();   //base 1
				glColor3f(1.0,1.0,1.0);
				miFigura.cilindro(6,16.0,20,pared_1.GLindex);
			glPopMatrix();
			glPushMatrix();   //base2
				glColor3f(1.0,1.0,1.0);
				miFigura.cilindro(10,8.0,20,pared_1.GLindex);
				glPushMatrix();   //columna1
					glTranslatef(0.0, 0.0, 15.0);
					glColor3f(1.0,1.0,1.0);
					miFigura.cilindro(1,8.0,20,pared_1.GLindex);
					glPushMatrix();			//esfera1
						glTranslatef(0.0, 8.0, 0.0);
						miFigura.esfera(1.0,20,20,pared_1.GLindex);
					glPopMatrix();
					glRotatef(90,0.0,1.0, 0.0);
					glPushMatrix();   //columnahor
						glTranslatef(4.0, 8.0, 0.0);
						glRotatef(90,0.0,0.0, 1.0);
						miFigura.cilindro(1,4.0,20,pared_1.GLindex);
						glPushMatrix();  //esfera2
							miFigura.esfera(1.0,20,20,pared_1.GLindex);
							glRotatef(-90,0.0,0.0, 1.0);
							miFigura.cilindro(1,4.0,20,pared_1.GLindex);
							glTranslatef(0.0, 4.0, 0.0);
							miFigura.cono(3.0,1.5,10,helado_1.GLindex);  //cono superior
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();   //columna2
					glTranslatef(0.0, 0.0, -15.0);
					glColor3f(1.0,1.0,1.0);
					miFigura.cilindro(1,8.0,20,pared_1.GLindex);
					glPushMatrix();			//esfera1
						glTranslatef(0.0, 8.0, 0.0);
						miFigura.esfera(1.0,20,20,pared_1.GLindex);
					glPopMatrix();
					glRotatef(-90,0.0,1.0, 0.0);
					glPushMatrix();   //columnahor
						glTranslatef(4.0, 8.0, 0.0);
						glRotatef(90,0.0,0.0, 1.0);
						
						miFigura.cilindro(1,4.0,20,pared_1.GLindex);
						glPushMatrix();  //esfera2
							miFigura.esfera(1.0,20,20,pared_1.GLindex);
							glRotatef(-90,0.0,0.0, 1.0);
							
							miFigura.cilindro(1,4.0,20,pared_1.GLindex);
							glTranslatef(0.0, 4.0, 0.0);
							miFigura.cono(3.0,1.5,10,helado_1.GLindex);  //cono superior
						glPopMatrix();
					glPopMatrix();

				glPopMatrix();
				glPushMatrix();   //columna3
					glTranslatef(-15.0, 0.0, 0.0);
					glColor3f(1.0,1.0,1.0);
					miFigura.cilindro(1,8.0,20,pared_1.GLindex);
					glPushMatrix();			//esfera1
						glTranslatef(0.0, 8.0, 0.0);
						miFigura.esfera(1.0,20,20,pared_1.GLindex);
					glPopMatrix();
					glPushMatrix();   //columnahor
						glTranslatef(4.0, 8.0, 0.0);
						glRotatef(90,0.0,0.0, 1.0);
						
						miFigura.cilindro(1,4.0,20,pared_1.GLindex);
						glPushMatrix();  //esfera2
							miFigura.esfera(1.0,20,20,pared_1.GLindex);
							glRotatef(-90,0.0,0.0, 1.0);
							
							miFigura.cilindro(1,4.0,20,pared_1.GLindex);
							glTranslatef(0.0, 4.0, 0.0);
							miFigura.cono(3.0,1.5,10,helado_1.GLindex);  //cono superior
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
				glPushMatrix();   //columna4
					glTranslatef(15.0, 0.0, 0.0);
					glColor3f(1.0,1.0,1.0);
					miFigura.cilindro(1,8.0,20,pared_1.GLindex);
					glPushMatrix();			//esfera1
						glTranslatef(0.0, 8.0, 0.0);
						miFigura.esfera(1.0,20,20,pared_1.GLindex);
					glPopMatrix();
					glRotatef(180,0.0,1.0, 0.0);
					glPushMatrix();   //columnahor
						glTranslatef(4.0, 8.0, 0.0);
						glRotatef(90,0.0,0.0, 1.0);
						
						miFigura.cilindro(1,4.0,20,pared_1.GLindex);
						glPushMatrix();  //esfera2
							miFigura.esfera(1.0,20,20,pared_1.GLindex);
							glRotatef(-90,0.0,0.0, 1.0);
							
							miFigura.cilindro(1,4.0,20,pared_1.GLindex);
							glTranslatef(0.0, 4.0, 0.0);
							miFigura.cono(3.0,1.5,10,helado_1.GLindex);  //cono superior
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();		

			//dona
			/*glPushMatrix();
				glTranslated(0,0,0);
				glColor3f(1.0,1.0,0.0);
				miFigura.torus(20,19,16, 16);
			glPopMatrix();
			*/

			
		glPopMatrix();

glPopMatrix(); //FIN CASTILLO

}
void seccion_hoja(){
	glPushMatrix();
				glPushMatrix(); //plano a
					glTranslatef(0, -0.5, 20);
					glRotatef(11,0.0,1.0, 0.0);   //gira 11 grados el primer plano que está a la derecha 
					//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
					glBegin(GL_QUADS);
						glColor3f(1, 0, 0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
					glEnd();
					glPushMatrix(); //plano b
						glTranslatef(7.8, 0, 0);
						glRotatef(23,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
							glColor3f(1, 0, 0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
						glEnd();
						glPushMatrix(); //plano c
							glTranslatef(7.8, 0, 0);
							glRotatef(22,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
							//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
							glBegin(GL_QUADS);
								glColor3f(1, 0, 0);
								glNormal3f(0.0, 0.0, 1.0);
								glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
								glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
								glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
								glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
							glEnd();
								glPushMatrix(); //plano d
								glTranslatef(7.8, 0, 0);
								glRotatef(22.5,0.0,1.0, 0.0);   //gira 11 grados el primer plano 
								//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
								glBegin(GL_QUADS);
									glColor3f(1, 0, 0);
									glNormal3f(0.0, 0.0, 1.0);
									glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
									glTexCoord2f(1.0, 0.0); glVertex3f(7.8, 0, 0.0);
									glTexCoord2f(1.0, 1.0); glVertex3f(7.8, 4, 0.0);
									glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 4, 0.0);
								glEnd();
							glPopMatrix();//fin plano d
						glPopMatrix();//fin plano c
					glPopMatrix(); //fin plano b
				glPopMatrix();// fin plano a

			glPopMatrix();//fin barda

}
void hojas_comp(){
			glPushMatrix();
				seccion_hoja();
				glPushMatrix();
					glRotatef(90,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					seccion_hoja();
				glPopMatrix();
				glPushMatrix();
					glRotatef(180,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					seccion_hoja();
				glPopMatrix();
				glPushMatrix();
					glRotatef(270,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					seccion_hoja();
				glPopMatrix();
			glPopMatrix();

}
void copa(){
glPushMatrix();   //copa esfera
		glTranslatef(0.0, 24.0, 0.0);
		glColor3f(1, 0, 0);
		miFigura.esfera(8.0,20,20,0);
		//hojas
		glPushMatrix();
			glTranslatef(0.0, -8.0, 0.0);
			glScalef(0.405,2.0,0.405);
			//glColor3f(0.0,1.0,0.0);
			hojas_comp();
		glPopMatrix();
glPopMatrix();
}
void arbol_c(){
	glPushMatrix();
		glTranslatef(7.0, 0.0, 0.0); 
		glColor3f(0.274, 0.184, 0.113);
		miFigura.cilindro(2.0,10.0,20,0);   
		glTranslatef(0.0, 1.5, 0.0); 
		glScalef(0.5,0.5,0.5);
		copa();
	glPopMatrix();
}


void BMO(){

 glPushMatrix();
  
  glColor3f(1.0, 1.0, 1.0);
		glTranslatef(transX, transY+0.7, transZ+35);
		//glRotatef(180, 0, 1.0, 0.0);
		glRotatef(angleY, 0.0, 1.0, 0.0);
		glRotatef(angleX, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.2);

	glPushMatrix();
		//glScalef(5.0, 8.0, 1.0);
		glColor3f(0.4, 0.7450, 0.6509);
		bmo.prismaBMO(6.0, 5.0, 4.0, cuerpoBMO.GLindex,letrasBMO.GLindex,atrasBMO.GLindex,letrasBMO.GLindex);// Cuerpo texturizado
	glPopMatrix();
	

		//Brazo D
	glPushMatrix();
			glTranslatef(3.25, -1.0, 0.0);
				glPushMatrix();
					glTranslatef(0.75, 0.0, 0.0);
					glRotatef(bmoangle, 0.0, 0.0, 1.0);
					glTranslatef(0.75, 0.0, 0.0);
					glPushMatrix();
						glTranslatef(0.75, 0.0, 0.0);
						glRotatef(bmoangle2, 0.0, 1.0, 0.0);
						glTranslatef(0.5, 0.0, 0.0);
						glColor3f(0.3882, 0.6745, 0.7019);
						bmo.prisma(1.0, 1.0,0.75,0);
					glPopMatrix();
					glColor3f(0.3882, 0.6745, 0.7019);
					bmo.prisma(0.75, 1.5, 0.75, 0); 
				glPopMatrix();
			glColor3f(0.3882, 0.6745, 0.7019);
			bmo.prisma(0.75, 1.5, 0.75, 0); //brazo D	
	glPopMatrix();

		//Brazo I
		glPushMatrix();
			glTranslatef(-4.0, -1.0, 0.0);
			//glScalef(3.0, 1.0, 1.0);
			//glRotatef(180,0.0,1.0, 0.0);
			glColor3f(0.3882, 0.6745, 0.7019);
			bmo.prisma(0.75, 3.0, 0.75, 0); //brazo I
		glPopMatrix();

		//Pie I
		glPushMatrix();
			glTranslatef(-2.0, -4.5, 0.0);
			//glScalef(1.0, 4.0, 1.0);
			//glRotatef(180,0.0,1.0, 0.0);
			glColor3f(0.3882, 0.6745, 0.7019);
			bmo.prisma(3.0, 0.7, 0.75, 0); //pie I
			
			glPushMatrix();
				glTranslatef(0.0, -1.5, 0.0);
				glRotatef(bmoangle3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.375, 0.75);;
				bmo.prisma(0.75, 0.75, 2.0, 0);//piecito
			glPopMatrix();
		glPopMatrix();

		//Pie D
		glPushMatrix();
			glTranslatef(2.0, -4.5, 0.0);
			//glScalef(1.0, 4.0, 1.0);
			//glRotatef(180,0.0,1.0, 0.0);
			glColor3f(0.3882, 0.6745, 0.7019);
			bmo.prisma(3.0, 0.75, 0.75, 0); //pie D
			glPushMatrix();
				glTranslatef(0.0, -1.5, 0.0);
				glRotatef(bmoangle3, 1.0, 0.0, 0.0);
				glTranslatef(0.0, -0.375, 0.75);;
				bmo.prisma(0.75, 0.75, 2.0, 0);//piecito
			glPopMatrix();
		glPopMatrix();

glPopMatrix(); //FIN BMO

}

// PinBall
void pisos ()
{
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0, 1.0, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glPushMatrix(); //Pasto
			glTranslatef(0.0,-1.0,50.0);
			glScalef(150,0.1,50);
			glDisable(GL_LIGHTING);
			//fig4.prisma2(piso_v.GLindex, 0);
			glEnable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();

		glPushMatrix(); //Pasto rosa
		glColor3f(1.0, 1.0, 1.0);
		//glColor3f(1.0, 0.5098, 0.6705); color rosa
			glTranslatef(0.0,-1.0,0.0);
			glScalef(90,0.1,50);
			glDisable(GL_LIGHTING);
			fig4.prisma2(piso_d.GLindex, 0);
			glEnable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();

		glPushMatrix(); //Pasto nieve
			glTranslatef(0.0,-1.0,-50.0);
			glScalef(150,0.1,50);
			glDisable(GL_LIGHTING);
			//fig4.prisma2(nievep.GLindex, 0);
			glEnable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
		glPopMatrix();

		glColor3f(1.0, 1.0, 1.0);
		glDisable(GL_COLOR_MATERIAL);
}

void muros(){
		glPushMatrix(); //planos exteriores
					glTranslatef(0, 0.5,0); // para alinearlo con la superficie de la mesa
					glPushMatrix(); //plano inf 
						glTranslatef(-10,0,19);// para moverlo a la orilla
						glRotatef(0,0.0,1.0, 0.0);   //gira x grados
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(20, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(20, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();
					glPushMatrix(); //plano sup
						glTranslatef(-10,0,-19);// para moverlo a la orilla
						glRotatef(0,0.0,1.0, 0.0);   //gira x grados
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(20, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(20, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();
					glPushMatrix(); //plano izq
						glRotatef(90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(-19,0,-10);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(38, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(38, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();
					glPushMatrix(); //plano der
						glRotatef(90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(-19,0,10);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(38, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(38, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();

					glPushMatrix(); //canal de saque
						glRotatef(90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(-19,0,8);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(38, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(38, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();

					glPushMatrix(); //canal de salida der 
						glRotatef(90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(-17.5,0,6);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(10, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(10, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();

					glPushMatrix(); //canal de salida dizq 
						glRotatef(90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(-17.5,0,-8);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
						glTexCoord2f(1.0, 0.0); glVertex3f(10, 0, 0.0);
						glTexCoord2f(1.0, 1.0); glVertex3f(10, 2, 0.0);
						glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();

		glPopMatrix();// fin plano a
}

void mesa(){
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);

		glPushMatrix();// Base mesa
			glTranslatef(0,6,5);
			glColor3f(0.1647, 0.4509, 0.2823);
			base_mesa.prisma(1.0, 20.0, 38.0, 0);
		
			glPushMatrix();// Elementos de adentro 
				muros();
				glTranslatef(-1,0,-3);// para centrar los rebotadores
				glScalef(0.2,0.2,0.2);
				arbol_c();
				glTranslatef(-10.0, 0.0, 0.0);
				arbol_c();
				glTranslatef(5.0, 0.0, -10.0);
				arbol_c();

			glPopMatrix();

			glPushMatrix();  //Rebotador izq
				glTranslatef(0, 0.5,0); // para alinearlo con la superficie de la mesa
					glPushMatrix();
						glRotatef(-90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(12.5,0,6);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(4, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(4, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
						glRotatef(20,0.0,1.0, 0.0);   //gira x grados
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(4.6, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(4.6, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
						glTranslatef(4.6,0,0);// para moverlo a la orilla
						glRotatef(238,0.0,1.0, 0.0);   //gira x grados
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(1.6, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(1.6, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-6, 2.0,12.5);  // 2 en y para que se eleve , -6 para alinearlo de izq a derecha
						glBegin(GL_POLYGON); //tapa
						glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 4);
							glTexCoord2f(1.0, 1.0); glVertex3f(0, 0, 0);
							glTexCoord2f(0.0, 0.0); glVertex3f(2.0, 0.0, 5);

						glEnd();
				glPopMatrix(); // fin TAPA
			glPopMatrix(); // fin reb

			glPushMatrix();  //Rebotador der
				glTranslatef(0, 0.5,0); // para alinearlo con la superficie de la mesa
					glPushMatrix();
						glRotatef(-90,0.0,1.0, 0.0);   //gira x grados
						glTranslatef(12.5,0,-4);// para moverlo a la orilla
						//glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(4, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(4, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
						glRotatef(-20,0.0,1.0, 0.0);   //gira x grados
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(4.6, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(4.6, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
						glTranslatef(4.6,0,0);// para moverlo a la orilla
						glRotatef(-238,0.0,1.0, 0.0);   //gira x grados
						glBegin(GL_QUADS);
							glColor3f(1.0, 1.0, 1.0);
							glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(1.6, 0, 0.0);
							glTexCoord2f(1.0, 1.0); glVertex3f(1.6, 2, 0.0);
							glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 2, 0.0);
						glEnd();
					glPopMatrix();
				glPushMatrix();
						glTranslatef(2, 2.0,12.5);  // 2 en y para que se eleve , -6 para alinearlo de izq a derecha
						glBegin(GL_POLYGON); //tapa
						glNormal3f(0.0, 0.0, 1.0);
							glTexCoord2f(1.0, 0.0); glVertex3f(0, 0, 5);
							glTexCoord2f(1.0, 1.0); glVertex3f(2, 0, 4);
							glTexCoord2f(0.0, 0.0); glVertex3f(2.0, 0.0, 0);

						glEnd();
				glPopMatrix(); // fin TAPA

			glPopMatrix();//fin reb

			glPushMatrix(); // ventilador rojo
				glTranslatef(-0.7,1.5,4); //-.5 para que quede centrado
				glColor3f(1, 0.09, 0.023);
				base_mesa.prisma(2.0, 5.0, 5.0, 0);
			glPopMatrix();

			glPushMatrix(); // ventilador azul
				glTranslatef(5.5,1.5,-11);
				glColor3f(0.002, 0.09, 1);
				base_mesa.prisma(2.0, 5.0, 5.0, 0);
			glPopMatrix();

		glPopMatrix();

		
		glPushMatrix(); //Patas
			glTranslatef(0,2.75,0);//para subirlo desde el centro 
			glPushMatrix();
				glTranslatef(-9,0,-18+5); //mas cinco porque la mesa está recorrida tambien 5
				glColor3f(0.274, 0.184, 0.113);
				pata_mesa.prisma(5.5, 2, 2, 0); // pata sup izq
				glTranslatef(0,0,36);
				pata_mesa.prisma(5.5, 2, 2, 0); // pata inf izq
			glPopMatrix();

			glPushMatrix();
				glTranslatef(9,0,-18+5); //mas cinco porque la mesa está recorrida tambien 5
				glColor3f(0.274, 0.184, 0.113);
				pata_mesa.prisma(5.5, 2, 2, 0); // pata sup der
				glTranslatef(0,0,36);
				pata_mesa.prisma(5.5, 2, 2, 0); // pata inf der
			glPopMatrix();

		glPopMatrix(); //Fin de las Patas

	glPopMatrix();

}

void cuña(GLuint textura1a) //funcon cuña 
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V4
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V5
	};

	glBindTexture(GL_TEXTURE_2D, textura1a);   // choose the texture to use.
	glBegin(GL_POLYGON);	
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	
							//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();

}



GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	// call the function that contains 
	// the rendering commands
		pisos();

	// endList
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	//glLightfv(GL_LIGHT1, GL_POSITION, FocoPosition);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, Foco2Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Foco2Specular);

	glLightfv(GL_LIGHT2, GL_DIFFUSE, Foco3Diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Foco3Specular);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	glEnable ( GL_COLOR_MATERIAL );

	//Para las luces


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    

	//BMO


	cuerpoBMO.LoadTGA("cuerpBMO.tga");
	cuerpoBMO.BuildGLTexture();
	cuerpoBMO.ReleaseImage();

	letrasBMO.LoadTGA("letrasBMO.tga");
	letrasBMO.BuildGLTexture();
	letrasBMO.ReleaseImage();

	atrasBMO.LoadTGA("atrasBMO.tga");
	atrasBMO.BuildGLTexture();
	atrasBMO.ReleaseImage();

	//ice
	nieve.LoadTGA("nieve.tga");
	nieve.BuildGLTexture();
	nieve.ReleaseImage();

	nievep.LoadTGA("nievep.tga");
	nievep.BuildGLTexture();
	nievep.ReleaseImage();

	nievem.LoadTGA("montana.tga");
	nievem.BuildGLTexture();
	nievem.ReleaseImage();

	lluvian.LoadTGA("lluvia.tga");
	lluvian.BuildGLTexture();
	lluvian.ReleaseImage();

	icesky.LoadTGA("icesky.tga");
	icesky.BuildGLTexture();
	icesky.ReleaseImage();

	skypasto.LoadTGA("skypasto.tga");
	skypasto.BuildGLTexture();
	skypasto.ReleaseImage();

	dulcesky.LoadTGA("candysky.tga");
	dulcesky.BuildGLTexture();
	dulcesky.ReleaseImage();

	otrosky.LoadTGA("otrosky.tga");
	otrosky.BuildGLTexture();
	otrosky.ReleaseImage();

	ventana_1.LoadTGA("ventana1.tga");
	ventana_1.BuildGLTexture();
	ventana_1.ReleaseImage();

	pared_1.LoadTGA("pared1.tga");
	pared_1.BuildGLTexture();
	pared_1.ReleaseImage();

	helado_1.LoadTGA("helado1.tga");
	helado_1.BuildGLTexture();
	helado_1.ReleaseImage();

	piso_d.LoadTGA("text/piso2.tga"); //piso amarillo
	piso_d.BuildGLTexture();
	piso_d.ReleaseImage();

	piso_v.LoadTGA("pisov.tga");
	piso_v.BuildGLTexture();
	piso_v.ReleaseImage();



	//modelos 3ds
	candy._3dsLoad("candy/DL3D_Christmas-Cane.3ds");
	chocolate._3dsLoad("chocolate/chocolate-bar.3ds");

	fig1._3dsLoad("fig1/Model.3ds");
	fig2._3dsLoad("fig2/toy.3ds");


	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,35, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[0].transX =0;
		KeyFrame[0].transY =0;
		KeyFrame[0].transZ =0;
		KeyFrame[0].bmoangle =0;
		KeyFrame[0].bmoangle2 =0;
		KeyFrame[0].bmoangle3 =0;
		KeyFrame[0].angleY =20;

		KeyFrame[0].transX_esf1 =0;
		KeyFrame[0].transY_esf1 =0;
		KeyFrame[0].transZ_esf1 =0;


		KeyFrame[1].transX =-6.0;
		KeyFrame[1].transY =0;
		KeyFrame[1].transZ =0;
		KeyFrame[1].bmoangle =0;
		KeyFrame[1].bmoangle2 =0;
		KeyFrame[1].bmoangle3 =0;
		KeyFrame[1].angleY = -96,0;

		KeyFrame[1].transX_esf1 =0;
		KeyFrame[1].transY_esf1 =0;
		KeyFrame[1].transZ_esf1 =-3;

		KeyFrame[2].transX =-9.0;
		KeyFrame[2].transY =0;
		KeyFrame[2].transZ =6;
		KeyFrame[2].bmoangle =0;
		KeyFrame[2].bmoangle2 =0;
		KeyFrame[2].bmoangle3 =0;
		KeyFrame[2].angleY =-96.0;

		KeyFrame[2].transX_esf1 =0;
		KeyFrame[2].transY_esf1 =0;
		KeyFrame[2].transZ_esf1 =-7;

		KeyFrame[3].transX =-6.0;
		KeyFrame[3].transY =0;
		KeyFrame[3].transZ =6.0;
		KeyFrame[3].bmoangle =72;
		KeyFrame[3].bmoangle2 =0;
		KeyFrame[3].bmoangle3 =0;
		KeyFrame[3].angleY =-96;

		KeyFrame[3].transX_esf1 =0;
		KeyFrame[3].transY_esf1 =0;
		KeyFrame[3].transZ_esf1 =-9;

		KeyFrame[4].transX =-5-0;
		KeyFrame[4].transY =0;
		KeyFrame[4].transZ =6.0;
		KeyFrame[4].bmoangle =72.0;
		KeyFrame[4].bmoangle2 =-54;
		KeyFrame[4].bmoangle3 =149;
		KeyFrame[4].angleY =-96;

		KeyFrame[4].transX_esf1 =0;
		KeyFrame[4].transY_esf1 =0;
		KeyFrame[4].transZ_esf1 =-12;

		KeyFrame[5].transX =-4.0;
		KeyFrame[5].transY =0;
		KeyFrame[5].transZ =6.0;
		KeyFrame[5].bmoangle =39;
		KeyFrame[5].bmoangle2 =62;
		KeyFrame[5].bmoangle3 =149;
		KeyFrame[5].angleY =2;

		KeyFrame[5].transX_esf1 =0;
		KeyFrame[5].transY_esf1 =0;
		KeyFrame[5].transZ_esf1 =-17;


	}
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	

	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		//camara con elevacion en y de 10 para  ver mas arriba
		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y + 25,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

			glPushMatrix();
				glDisable(GL_LIGHTING); //desactiva
					glColor3f( 0.0,0.0,1.0 );	//AZUL
					glMaterialfv(GL_FRONT,GL_DIFFUSE,Foco2Diffuse);
					glLightfv(GL_LIGHT1,GL_POSITION,Position4);
					glTranslatef(-1.0f, 8.0f, 18.0f);					
					glutSolidSphere(0.15,40,40);  //foco (radio,H,V);
				glEnable(GL_LIGHTING);//activa		
			glPopMatrix();

			glPushMatrix();
			
				glDisable(GL_LIGHTING); //desactiva
					glColor3f( 0.0,1.0,0.0 );	//VERDE
					glMaterialfv(GL_FRONT,GL_DIFFUSE,Foco3Diffuse);
					glLightfv(GL_LIGHT1,GL_POSITION,Position3);
					glTranslatef(7.0f, 8.0f, 0.0f);					
					glutSolidSphere(0.15,40,40);  //foco(radio,H,V);
				glEnable(GL_LIGHTING);//activa

			glPopMatrix();


			glPushMatrix();
				glEnable ( GL_COLOR_MATERIAL );
					glColor3f(1, 1, 1);
					glCallList(ciudad_display_list);
				glDisable ( GL_COLOR_MATERIAL );
			glPopMatrix();

	glPushMatrix();		//CAMPO
		glEnable(GL_COLOR_MATERIAL); //BMO
		glTranslatef( 0,0,-10);  
		//BMO();
	glPopMatrix();		

	glPushMatrix();		//mesa
		glEnable(GL_COLOR_MATERIAL);
		glTranslatef(0,0,0);  
		mesa();
	
		glPushMatrix();   //esfera1
			glTranslatef(7.0, 7.2, 6.0);  //Posicion inicial de la esfera1
			glTranslatef(transX_esf1, transY_esf1, transZ_esf1);
			glColor3f(1, 1, 0);
			miFigura.esfera(0.7,20,20,0);
		glPopMatrix();

		glPushMatrix();   //esfera2
			glTranslatef(-7.0, 7.2, -6.0);  //Posicion inicial de la esfera2
			glColor3f(1, 0, 0);
			miFigura.esfera(0.7,20,20,0);
		glPopMatrix();

		glPushMatrix();   //esfera3
			glTranslatef(-9, 7.2, 12.0);  //Posicion inicial de la esfera3
			glColor3f(0, 1, 0);
			miFigura.esfera(0.7,20,20,0);
		glPopMatrix();

		glPushMatrix();   
			glTranslatef(-3.5, 7.2, 21.5);  
			glRotatef(CuñaI,0.0,1.0, 0.0);//Giro //Cuña izquierda
			glTranslatef(0.5, 0, -0.5);  
			glRotatef(-90,1.0,0.0, 0.0);
			glScalef(2.7,1.0,1.0);//Para alargar
			glColor3f(1, 1, 1);
			cuña(ventana_1.GLindex);

		glPopMatrix();

		glPushMatrix();   
			glTranslatef(1, 7.2, 21);  
			glRotatef(-90,1.0,0.0, 0.0);
			glScalef(2.7,1.0,1.0);//Para alargar
			glColor3f(1, 1, 1);
  
			glRotatef(90,0.0,0.0, 1.0);
			glPushMatrix();   
				glRotatef(CuñaD,0.0,0.0, 1.0);//Giro //Cuña derecha
				//glTranslatef(-0.5, 0, 1);
				cuña(ventana_1.GLindex);
			glPopMatrix();

		glPopMatrix();

			glPushMatrix();   
			glTranslatef(-9.0, 7.2, 11.5);  
			glRotatef(CuñaA,0.0,1.0, 0.0);//Giro //Cuña Arriba
			glTranslatef(0.5, 0, -0.5);  
			glRotatef(-90,1.0,0.0, 0.0);
			glScalef(2.7,1.0,1.0);//Para alargar
			glColor3f(1, 1, 1);
			cuña(ventana_1.GLindex);

		glPopMatrix();


		//Modelos 3ds
		glPushMatrix();
			glTranslatef(5.0, 7.2, 11.5);  //reobtador
			//glColor3f(0.533, 0.262, 0.184);
			glScalef(0.04, 0.02, 0.04);
			fig2.GLrender(NULL,_SHADED, 1);
		glPopMatrix();	

		glPushMatrix();
			glTranslatef(-6.3, 7.2, 14.5);  //reobtador2
			//glColor3f(0.533, 0.262, 0.184);
			glScalef(0.04, 0.02, 0.04);
			fig2.GLrender(NULL,_SHADED, 1);
		glPopMatrix();	

		glPushMatrix();
			glTranslatef(-1.0, 6.6, 15.5);  //camara
			//glColor3f(0.533, 0.262, 0.184); 
			glScalef(0.01, 0.01, 0.01);
			fig1.GLrender(NULL,_SHADED, 1);
		glPopMatrix();	

		glPushMatrix();
			glTranslatef(-5.9, 7.2, 2.5);    //camara2
			//glColor3f(0.533, 0.262, 0.184); 
			glScalef(0.01, 0.01, 0.01);
			fig1.GLrender(NULL,_SHADED, 1);
		glPopMatrix();	

		/*glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 23.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 22.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 21.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 20.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
				glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 19.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 18.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 17.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();
		glPushMatrix();// Bastones  resorte
			glTranslatef(9.8, 6.2, 16.5);  
			glRotatef(180,0,1,0);
			glScalef(0.04, 0.02, 0.04);
			glColor3f(1.0, 0.0, 0.0);
			candy.GLrender(NULL,_SHADED, 1);
		glPopMatrix();*/

				//Barras de chocolate
		/*glPushMatrix();
			glTranslatef(-5.9, 7.2, 2.5);  
			glRotatef(90,0,1,0);
			glScalef(0.08, 0.08, 0.08);
			glColor3f(0.533, 0.262, 0.184);
			chocolate.GLrender(NULL,_SHADED, 1);
		glPopMatrix();	*/


	glPopMatrix();	

glPushMatrix(); // DULCE REINO

	//CASTILLO
	glPushMatrix();
		//castillo();
	glPopMatrix();


	// arboles
	/*glPushMatrix();  //arboles a
		glTranslatef(0.0, -0.5, -5.0); 
		glPushMatrix();			//arbol 1
				glScalef(0.2,0.2,0.2);
				arbol_c();		
		glPopMatrix();
		glPushMatrix();			//arbol 2
				glTranslatef(-10.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 3
				glTranslatef(-20.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 4
				glTranslatef(-30.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 5
				glTranslatef(-40.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();


	glPopMatrix();

		glPushMatrix();  //arboles b
		glTranslatef(0.0, -0.5, 5.0); 
		glPushMatrix();			//arbol 1
				glScalef(0.2,0.2,0.2);
				arbol_c();		
		glPopMatrix();
		glPushMatrix();			//arbol 2
				glTranslatef(-10.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 3
				glTranslatef(-20.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 4
				glTranslatef(-30.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();
		glPushMatrix();			//arbol 5
				glTranslatef(-40.0, 0.0, 0.0); 
				glScalef(0.2,0.2,0.2);
				arbol_c();	
		glPopMatrix();

	glPopMatrix();*/

glPopMatrix();//Fin dulce reino
		
			
glPushMatrix(); //REINO HIELO
	

		glPushMatrix(); // plano nieve cayendo
			glTranslatef(-65, 0, -31);
			glDisable(GL_LIGHTING);
			glEnable(GL_BLEND); ///activa transparecia
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);//transparencia
			glBindTexture(GL_TEXTURE_2D, lluvian.GLindex);
			/*	glBegin(GL_QUADS);				//Coordenadas del plano 
					glColor3f(1.0, 1.0, 1.0);
					glNormal3f(0.0, 0.0, -1.0);
					glTexCoord2f(0.0, 0.0 + var); glVertex3f(0.0, 0.0, 0.0);
					glTexCoord2f(1.0, 0.0 + var); glVertex3f(130.0, 0, 0.0);
					glTexCoord2f(1.0, 1.0 + var); glVertex3f(130.0, 130.0, 0.0);
					glTexCoord2f(0.0, 1.0 + var); glVertex3f(0.0, 130, 0.0);
				glEnd(); */
			glDisable(GL_BLEND); ///desactiva transparecia
			glEnable(GL_LIGHTING);
		glPopMatrix();



glPopMatrix(); //FIN ARENA BATALLA

			glDisable(GL_COLOR_MATERIAL);

			glEnable ( GL_COLOR_MATERIAL );
			glColor3f(1.0,1.0,1.0);

		glPopMatrix(); 

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-0.05,0.23,-0.25,(void *)font,"P O K E M O N ");
			//pintaTexto(-0.25,0.19,-0.25,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.01;
	fig3.text_der-= 0.01;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	var += 0.01;

	//Movimiento del coche
	if(g_fanimacion)
	{
	
	}

	//Movimiento del monito
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation

			KeyFrame[playIndex].incX=(KeyFrame[playIndex+1].transX-KeyFrame[playIndex].transX)/i_max_steps;			//100 frames
			KeyFrame[playIndex].incY=(KeyFrame[playIndex+1].transY-KeyFrame[playIndex].transY)/i_max_steps;			//100 frames
			KeyFrame[playIndex].incZ=(KeyFrame[playIndex+1].transZ-KeyFrame[playIndex].transZ)/i_max_steps;			//100 frames

			KeyFrame[playIndex].inc1=(KeyFrame[playIndex+1].bmoangle-KeyFrame[playIndex].bmoangle)/i_max_steps;		//100 frames
			KeyFrame[playIndex].inc2=(KeyFrame[playIndex+1].bmoangle2-KeyFrame[playIndex].bmoangle2)/i_max_steps;	//100 frames
			KeyFrame[playIndex].inc3=(KeyFrame[playIndex+1].bmoangle3-KeyFrame[playIndex].bmoangle3)/i_max_steps;		//100 frames
			KeyFrame[playIndex].incangleY=(KeyFrame[playIndex+1].angleY-KeyFrame[playIndex].angleY)/i_max_steps;	

			//ANIMACION ESFERA
			KeyFrame[playIndex].incX_esf1=(KeyFrame[playIndex+1].transX_esf1-KeyFrame[playIndex].transX_esf1)/i_max_steps;			//100 frames
			KeyFrame[playIndex].incY_esf1=(KeyFrame[playIndex+1].transY_esf1-KeyFrame[playIndex].transY_esf1)/i_max_steps;			//100 frames
			KeyFrame[playIndex].incZ_esf1=(KeyFrame[playIndex+1].transZ_esf1-KeyFrame[playIndex].transZ_esf1)/i_max_steps;			//100 frames





			}
		}
		else
		{	//Draw information
			transX+=KeyFrame[playIndex].incX;
			transY+=KeyFrame[playIndex].incY;
			transZ+=KeyFrame[playIndex].incZ;
			bmoangle+=KeyFrame[playIndex].inc1;
			bmoangle2+=KeyFrame[playIndex].inc2;
			bmoangle3+=KeyFrame[playIndex].inc3;
			angleY+=KeyFrame[playIndex].incangleY;

			transX_esf1+=KeyFrame[playIndex].incX_esf1;
			transY_esf1+=KeyFrame[playIndex].incY_esf1;
			transZ_esf1+=KeyFrame[playIndex].incZ_esf1;

			i_curr_steps++;
		}

	}

	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	//glOrtho(-70,70,-70,70,0.1,20);
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);


	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

//mouse
/*void mouse( int mov, int x, int y ){
	switch (mov) {
	case MOUSEEVENTF_MOVE:
		objCamera.Move_Camera( CAMERASPEED+0.2 );
	break;
	case MOUSE_EVENT:
		objCamera.Move_Camera( -(CAMERASPEED+0.2) );
	break;
	}
}*/

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {


	case '6':    //Cuña I
			
			CuñaA = 45;

		break;
	case '7':
	
			CuñaA = 0;
			

		break;



	case '1':    //Cuña I
			
			CuñaI = 45;

		break;
	case '2':
	
			CuñaI = 0;
			

		break;

	case '4':    //CuñaD
			
			CuñaD = 45;

		break;
	case '5':
	
			CuñaD = 0;
			

		break;


	case 'u':    //Prende y apaga luz VERDE
			
			glEnable(GL_LIGHT2);
			

		break;
	case 'U':
	
			glDisable(GL_LIGHT2);
			

		break;

	case 'o':    //Prende y apaga luz AZUL
			
			glEnable(GL_LIGHT1);
			

		break;
	case 'O':
	
			glDisable(GL_LIGHT1);
			

		break;

		case 'p':    //Prende y apaga luz 0 adentro del tablero
			
			glEnable(GL_LIGHT0);
			//glEnable(GL_LIGHT1);
		
			break;
		case 'P':
	
			glDisable(GL_LIGHT0);
			//glDisable(GL_LIGHT1);
	

			break;

		case 't':   //Movimientos de camara
			objCamera.Move_Camera( CAMERASPEED+0.005 );
			break;

		case 'g':
			objCamera.Move_Camera(-(CAMERASPEED+0.005));
			break;

		case 'f':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.005));
			break;

		case 'h':
			objCamera.Strafe_Camera((CAMERASPEED+0.005));
			break;

			 //Movimientos de camara
		case 'i':  
			g_lookupdown -= 0.5f;
			break;

		case 'k':
			g_lookupdown += 0.5f;
			break;

		case 'j':
			objCamera.Rotate_View(-CAMERASPEED*0.5);
			break;

		case 'l':
			objCamera.Rotate_View( CAMERASPEED*0.5);
			break;

		case 'w':   //Movimientos de BMO
		case 'W':
			transZ --;
			printf( "Z: %f \n", transZ);
			break;

		case 'S':
		case 's':
			transZ ++;
			printf( "Z: %f \n", transZ);
			break;

		case 'd':
		case 'D':
			transX ++;
			printf( "x: %f \n", transX);
			break;

		case 'a':
		case 'A':
			transX --;
			printf( "x: %f \n", transX);
			break;

		case 'q':
			bmoangle ++;
			printf( "bmoangle: %f \n", bmoangle);
			
			break;

		case 'Q':
			bmoangle --;
			printf( "bmoangle: %f \n", bmoangle);
			break;

		case 'e':
			bmoangle2 ++;
			printf( "bmoangle2: %f \n", bmoangle2);
			break;
	
		case 'E':
			bmoangle2 --;
			printf( "bmoangle2: %f \n", bmoangle2);
			break;

		case 'z':
			bmoangle3 ++;
			printf( "bmoangle3: %f \n", bmoangle3);
			break;

		case 'Z':
			bmoangle3 --;
			printf( "bmoangle3: %f \n", bmoangle3);
			break;

		//vista fija

		case 'C':
			objCamera.Position_Camera(55,1.0,55,-25,1,-5,0,1,0);
		break;
		case 'c':
			objCamera.Position_Camera(55,55,5,0,20,-5,0,1,0);
		break;

		case 'm':						
		case 'M':
			if(play==false && (FrameIndex>1))
			{
				transX=KeyFrame[0].transX;
				transY=KeyFrame[0].transY;
				transZ=KeyFrame[0].transZ;
				bmoangle=KeyFrame[0].bmoangle;
				bmoangle2=KeyFrame[0].bmoangle2;
				bmoangle3=KeyFrame[0].bmoangle3;
				angleY=KeyFrame[0].angleY;

				transX_esf1=KeyFrame[0].transX_esf1;
				transY_esf1=KeyFrame[0].transY_esf1;
				transZ_esf1=KeyFrame[0].transZ_esf1;

				play=true;
				playIndex=0;
			}
			else
			{
				play=false;
			}
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		//g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		//g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		//objCamera.Rotate_View(-CAMERASPEED);
		angleY += 2.0;
		printf( "angleY: %f \n", angleY);
		break;

	case GLUT_KEY_RIGHT:
		//objCamera.Rotate_View( CAMERASPEED);
		angleY -= 2.0;
		printf( "angleY: %f \n", angleY);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);

				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				KeyFrame[FrameIndex].giroMonito=giroMonito;
			
				FrameIndex++;
			}
			
		
			break;

		case 1:
			if(play==false && FrameIndex >1)
			{
				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				giroMonito=KeyFrame[0].giroMonito;

				play=true;
				playIndex=0;
			}
			else
			{
				play=false;
			}
			break;

	}
}

void menu( int id)
{
	switch (id)
	{
		case 1:
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;


	}
}

int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (800, 800);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("P O K E M O N "); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
  //glutAddMenuEntry	  ("Animacion Carro", 1);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);

  glutMainLoop        ( );          // 

  return 0;
}
