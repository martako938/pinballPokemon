//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Aldana Mendez Kevin Gonzalo			******//
//*************		Lopez Montoya Miguel Angel			******//
//************************************************************//
#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;

float text_der = 1.0;
float text_izq = 0.0;

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 50.0f, 40.0f, 1.0f };				// Light Position   DE LA BARDA DE AFUERA
GLfloat Position2[]= { -20.0f, 40.0f, 45.0f, 1.0f };		//DE LOS ATAUDES

//GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


//GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
//GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
//GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background		//MATERIAL NEGRO 
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest	//BRILLO

																/*CREAMOS MATERIALES DE DIFERENTES COLORES PARA CADA CUBO EJERCICIO 1*/
GLfloat mat_diffuseROJO[] = { 0.9f, 0.1f, 0.0f, 1.0f };						// Object Color main
GLfloat mat_SpecularROJO[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ShininessROJO[] = { 50.0 };

GLfloat mat_diffuseAZUL[] = { 0.2f, 0.2f, 1.0f, 1.0f };						// Object Color main 
GLfloat mat_SpecularAZUL[] = { 0.8, 0.8, 0.8, 0.8 };
GLfloat mat_ShininessAZUL[] = { 50.0 };

GLfloat mat_diffuseBLANCO[] = { 1.0, 1.0, 1.0, 1.0 };				// Object Color main 
GLfloat mat_SpecularBLANCO[] = { 0.8, 0.8, 0.8, 0.8 };
GLfloat mat_ShininessBLANCO[] = { 50.0 };

GLfloat mat_diffuseMORADO[] = { 1.0, 0.0, 1.0, 1.0 };				// Object Color main
GLfloat mat_SpecularMORADO[] = { 0.8, 0.8, 0.8, 0.8 };
GLfloat mat_ShininessMORADO[] = { 50.0 };


GLfloat mat_diffuseVERDE[] = {  0.0,1.0,0.4, 1.0f };	
GLfloat mat_SpecularVERDE[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat mat_ShininessVERDE[] = { 50.0 };


//GLfloat mat_diffuseAMARILLO[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_diffuseAMARILLO[] ={ 1.0,0.85,0.10, 1.0f };	
GLfloat mat_SpecularAMARILLO[] ={ 1.0, 0.5, 0.0, 1.0 };	
GLfloat mat_ShininessAMARILLO[] = { 50.0 };

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 0.8 };
GLfloat EarthShininess[] = { 50.0 };



CTexture t_madera;
CTexture t_metal01;
CTexture t_pachinko;
CTexture t_maderaT;
CTexture t_bandeja;
CTexture t_ataud;
CTexture t_vidrio;

CModel clavo;
CModel rebotador;

bool mov = true;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	
	

	glEnable(GL_TEXTURE_2D);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT1, GL_POSITION, Position2);

	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT1);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);


	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	t_madera.LoadTGA("madera.tga");
	t_madera.BuildGLTexture();
	t_madera.ReleaseImage();

	t_pachinko.LoadTGA("pachinko.tga");
	t_pachinko.BuildGLTexture();
	t_pachinko.ReleaseImage();
	
	t_maderaT.LoadTGA("maderaT.tga");
	t_maderaT.BuildGLTexture();
	t_maderaT.ReleaseImage();

	t_bandeja.LoadTGA("bandeja.tga");
	t_bandeja.BuildGLTexture();
	t_bandeja.ReleaseImage();

	t_ataud.LoadTGA("ataud.tga");
	t_ataud.BuildGLTexture();
	t_ataud.ReleaseImage();

	t_vidrio.LoadTGA("vidrio.tga");
	t_vidrio.BuildGLTexture();
	t_vidrio.ReleaseImage();

	clavo._3dsLoad("Column art recon N260613.3ds");
	rebotador._3dsLoad("toy.3ds");

}


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

void barda_incompleta(){
			glPushMatrix();
				glPushMatrix();
					glRotatef(225,0.0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					barda_a();
				glPopMatrix();
				glPushMatrix();
					glRotatef(270, 0,1.0, 0.0);
					glTranslatef(0.0, 0.0, 0.0);
					barda_a();
				glPopMatrix();
			glPopMatrix();
}

void ataud(GLuint textura1)
{
	float b1[] = { -1.5, 3.0, 0.5 };
	float b2[] = { 1.5, 3.0, 0.5 };
	float b3[] = { 3.5, 1.0, 0.5 };
	float b4[] = { 1.5, -3.0, 0.5 };
	float b5[] = { -1.5, -3.0, 0.5 };
	float b6[] = { -3.5, 1.0, 0.5 };
	float b7[] = { -1.5, 3.0, -0.5 };
	float b8[] = { 1.5, 3.0,- 0.5 };
	float b9[] = { 3.5, 1.0, -0.5 };
	float b10[] = { 1.5, -3.0, -0.5 };
	float b11[] = { -1.5, -3.0, -0.5 };
	float b12[] = { -3.5, 1.0, -0.5 };

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(b1);
	glTexCoord2f(0.0f, 5.0f); glVertex3fv(b2);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(b3);
	glTexCoord2f(0.5f, 0.0f); glVertex3fv(b4);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(b5);
	glTexCoord2f(1.0f, 0.5f); glVertex3fv(b6);
	glTexCoord2f(1.0f, 1.0f); glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b7);
	glVertex3fv(b8);
	glVertex3fv(b9);
	glVertex3fv(b10);
	glVertex3fv(b11);
	glVertex3fv(b12);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b1);
	glVertex3fv(b7);
	glVertex3fv(b8);
	glVertex3fv(b2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b2);
	glVertex3fv(b8);
	glVertex3fv(b9);
	glVertex3fv(b3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b3);
	glVertex3fv(b9);
	glVertex3fv(b10);
	glVertex3fv(b4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b5);
	glVertex3fv(b4);
	glVertex3fv(b10);
	glVertex3fv(b11);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b5);
	glVertex3fv(b11);
	glVertex3fv(b12);
	glVertex3fv(b6);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(b6);
	glVertex3fv(b12);
	glVertex3fv(b7);
	glVertex3fv(b1);
	glEnd();
}

void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void cubo(void)	//CUBO
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};
	GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values negro
	GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values blanco
	GLfloat LightDiffuseAZUL[] = { 0.0f, 0.0f, 1.0f, 1.0f };	//COLOR AZUL
	GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values blanco
	GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };


	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0, 0.0, 0.0);
							//glNormal3f(0.0,0.0,1.0);		//PARA VER DE DONDE VIENE LA LUZ Y DONDE ESTA REFLEJANDO
	GLfloat mat_diffuseROJO[] = { 1.0, 0.0, 0.0, 1.0 };
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
							//glColor3f(0.0, 0.0, 1.0);
							//glNormal3f(1.0,0.0,0.0);
	GLfloat mat_diffuseAZUL[] = { 0.0, 0.0, 1.0, 1.0 };
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
							//glColor3f(0.0, 1.0, 0.0);
							//glNormal3f(0.0,0.0,-1.0);
	GLfloat mat_diffuseVERDE[] = { 0.0, 1.0, 0.0, 1.0 };
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
						  //glColor3f(1.0, 1.0, 1.0);
						  //glNormal3f(-1.0,0.0,0.0);
	GLfloat mat_diffuseBLANCO[] = { 1.0, 1.0, 1.0, 1.0 };
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
						  //glColor3f(0.4, 0.2, 0.6);
						  //glNormal3f(0.0,-1.0,0.0);
	GLfloat mat_diffuseMORADO[] = { 1.0, 0.0, 1.0, 1.0 };
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
						  //glColor3f(0.8, 0.2, 0.4);
						  //glNormal3f(0.0,1.0,0.0);
	GLfloat mat_diffuseAMARILLO[] = { 1.0, 1.0, 0.0, 1.0 };
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void piramide(void)
{
	//Inicio pirámide
	glPushMatrix(); // este cubo tiene materiales
	//glTranslatef(transX, transY, transZ);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuseVERDE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	cubo();

	//cubo sin materiales
	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(180, 1, 0, 0);
	cubo();
	glPopMatrix();

	/* CUBOS PARA LA PIRAMIDE */
	glPushMatrix();
	glTranslatef(1.0f, 0.0f, 0.0f);
	glRotatef(180, 1, 0, 0);
	cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0f, 0.0f, 0.0f);
	glRotatef(270, 1.0, 0.0, 0.0);
	cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5f, 1.0f, 0.0f);
	glRotatef(90, 0.0, 1.0, 0.0);
	cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5f, 1.0f, 0.0f);
	glRotatef(270, 0.0, 1.0, 0.0);
	cubo();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 2.0f, 0.0f);
	glRotatef(90, 0.0, 0.0, 1.0);
	cubo();
	glPopMatrix();

	glPopMatrix();
}
void cilindro1(float radio, float altura, int resolucion)
{
	glTranslatef(0.0, -2.5, 0.0);
	float v1[] = { 0.0, 0.0, 0.0 };
	float v2[] = { 0.0, 0.0, 0.0 };
	float v3[] = { 0.0, 0.0, 0.0 };
	float v4[] = { 0.0, 0.0, 0.0 };
	float v5[] = { 0.0, 0.0, 0.0 };

	float angulo = 2 * 3.14 / resolucion;
	float ctext_s = 1.0 / resolucion;
	float ctext_t = 0.0;

	for (int i = 0; i <resolucion; i++)
	{

		v2[0] = radio*cos(angulo*i);
		v2[1] = 0;
		v2[2] = radio*sin(angulo*i);

		v3[0] = radio*cos(angulo*(i + 1));
		v3[1] = 0;
		v3[2] = radio*sin(angulo*(i + 1));

		v4[0] = radio*cos(angulo*i);
		v4[1] = altura;
		v4[2] = radio*sin(angulo*i);

		v5[0] = radio*cos(angulo*(i + 1));
		v5[1] = altura;
		v5[2] = radio*sin(angulo*(i + 1));

		glBegin(GL_POLYGON);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v5);
		glVertex3fv(v4);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, altura, 0.0);
		glVertex3fv(v4);
		glVertex3fv(v5);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v5);
		glVertex3fv(v4);
		glEnd();
	}
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
		glColor3f(0.752, 0.752, 0.752);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
		glColor3f(0.752, 0.752, 0.752);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		glColor3f(0.752, 0.752, 0.752);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
		glColor3f(0.752, 0.752, 0.752);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glEnable(GL_ALPHA_TEST); //TRANSPARENCIA
		glAlphaFunc(GL_GREATER, 0.1);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
	
		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
}

void prisma3 (GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(0.0, 0.0, 0.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 0.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 0.0, 0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.

	glBegin(GL_POLYGON);  //Left
	glColor3f(0.0, 0.0, 0.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.0, 0.0, 0.0);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glEnable(GL_ALPHA_TEST); //TRANSPARENCIA
	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top5
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
}
void prisma2(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
							//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
							//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
						  //glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();


	glBegin(GL_POLYGON);  //Bottom
						  //glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
						  //glColor3f(0.8,0.2,0.4);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

}

void mesa(void)
{
	glPushMatrix();
	glPushMatrix(); //inicia la mesa
	//glColor3f(1.0, 1.0, 1.0);


/*	glPushMatrix();
		glDisable(GL_LIGHTING); //desactiva
			glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position);
		
		glEnable(GL_LIGHTING);//activa
	glPopMatrix();*/



	//modelos jerarquicos
	glPushMatrix();
	glTranslatef(0.0, -1.7, 4.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.4, 0.5);
	
	glPushMatrix();
		
		glEnable(GL_LIGHTING); //desactiva
			//glColor3f( 1.0,0.0,1.0 );	//Sol amarillo
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position2);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseAZUL);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularAZUL);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessAZUL);
			ataud(t_ataud.GLindex);
		glDisable(GL_LIGHTING);//activa
		
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.7, 7.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glScalef(0.5, 0.4, 0.5);

	glPushMatrix();
	 glEnable(GL_LIGHTING); //desactiva
			//glColor3f( 1.0,0.0,1.0 );	//Sol amarillo
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position2);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseROJO);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularROJO);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessROJO);
			ataud(t_ataud.GLindex);

		glDisable(GL_LIGHTING);//activa
	glPopMatrix();


	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0, -1.7, 4.7);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 0.5);
		glPushMatrix();
			glEnable(GL_LIGHTING); //desactiva
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseAMARILLO);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularAMARILLO);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessAMARILLO);

			ataud(t_ataud.GLindex);

			glDisable(GL_LIGHTING);//activa
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, -1.7, 4.7);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 0.5);
		glPushMatrix();
			glEnable(GL_LIGHTING); //desactiva
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseAMARILLO);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularAMARILLO);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessAMARILLO);
		
			ataud(t_ataud.GLindex);
	
			glDisable(GL_LIGHTING);//activa
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1.7, 2.2);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glScalef(1.5, 1.5, 1.5);
		glPushMatrix();
		glEnable(GL_LIGHTING); //desactiva
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseVERDE);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularVERDE);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessVERDE);
		
			piramide();
		
			glDisable(GL_LIGHTING);//activa
		glPopMatrix();

	glPopMatrix();


	glPushMatrix();//circunferencia
	//glColor3f(1.0, 1.0, 1.0);

	//Primer nivel
	glPushMatrix();//inserccion de os clavos implementando modelos 3ds
	glTranslatef(5.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1.7, -6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//Segundo nivel
	glPushMatrix();
	glTranslatef(6.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();//inserccion de os clavos implementando modelos 3ds
	glTranslatef(-6.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1.7, -5.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//tercer nivel
	glPushMatrix();
	glTranslatef(-4.5, -1.7, -4.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, -4.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//cuarto nivel
	glPushMatrix();
	glTranslatef(-4.5, -1.7, -3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, -3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//quinto nivel
	glPushMatrix();
	glTranslatef(-3.5, -1.7, -2.5);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, -2.5);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//sexto nivel
	glPushMatrix();
	glTranslatef(-5.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-7.5, -1.7, -1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -1.7, -2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//septimo nivel
	glPushMatrix();
	glTranslatef(-4.5, -1.7, 0.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, 0.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//octavo nivel
	glPushMatrix();
	glTranslatef(-3.5, -1.7, 1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, 1.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//noveno nivel
	glPushMatrix();
	glTranslatef(-4.5, -1.7, 2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, 2.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//decimo nivel
	glPushMatrix();
	glTranslatef(-3.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, -1.7, 3.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//nivel once
	glPushMatrix();
	glTranslatef(-3.5, -1.7, 6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, 6.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//nivel doce
	glPushMatrix();
	glTranslatef(-4.5, -1.7, 6.5);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -1.7, 6.5);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//nivel trece
	glPushMatrix();
	glTranslatef(-3.5, -1.7, 7.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, 7.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//nivel catorce
	glPushMatrix();
	glTranslatef(-3.5, -1.7, 8.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -1.7, 8.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -1.7, 8.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1.7, 8.0);
	glColor3f(1.0, 0.843, 0.0);
	clavo.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();//termina los clavos

	glPushMatrix();
	glTranslatef(0, -2.3, 0);
	glScalef(0.5, 0.5, 0.5); //escala de la mesa

		glPushMatrix();
		glEnable(GL_LIGHTING); //desactiva
			//glColor3f( 1.0,0.0,1.0 );	//Sol amarillo
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT0,GL_POSITION,Position2);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseAMARILLO);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularAMARILLO);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessAMARILLO);
		
				barda_completa();
			
		glDisable(GL_LIGHTING);//activa
		glPopMatrix();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -2.3, 0);
	glScalef(0.45, 0.45, 0.45); //escala de la mesa

	glPushMatrix();
	 glEnable(GL_LIGHTING); //desactiva
			//glColor3f( 1.0,0.0,1.0 );	//Sol amarillo
			glMaterialfv(GL_FRONT,GL_DIFFUSE, Diffuse);
			glLightfv(GL_LIGHT1,GL_POSITION,Position);
			glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuseMORADO);
			glMaterialfv(GL_FRONT,GL_SPECULAR, mat_SpecularMORADO);
			glMaterialfv(GL_FRONT,GL_SHININESS, mat_ShininessMORADO);

			barda_incompleta();

		glDisable(GL_LIGHTING);//activa
	glPopMatrix();

	glPopMatrix();
	//cilindro(10.0, 3.0, 150);//termina cilindro
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(6.5, -1.7, 1.2);
	glColor3f(0.4, 1.0, 0.4);
	glScalef(0.03, 0.03, 0.03);
	rebotador.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(-6.5, -1.7, 1.2);
	glColor3f(0.4, 1.0, 0.4);
	glScalef(0.03, 0.03, 0.03);
	rebotador.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	glPushMatrix();//bndeja de la caja pachinko
	glTranslatef(0.0, 0.0, 12.5);

	glPushMatrix();//boton de funcionamiento
	glTranslatef(8.4, 3.5, 0.3);
	cilindro1(1.0, 2.0, 150);
	glPopMatrix();
	
	glScalef(20, 5.0, 5.0);
	prisma2(t_bandeja.GLindex, t_madera.GLindex);
	glPopMatrix();//termina Bandeja de la caja pchinko

	glScalef(20.0, 5.0, 20.0); //escala de la mesa
	prisma(t_pachinko.GLindex, t_maderaT.GLindex); // aplicacion de texturas
	glPopMatrix();//termina la mesa
	glTranslatef(0.0, 0.0, 2.2);
	glScalef(23, 6.0, 27); //marco
	prisma3(t_vidrio.GLindex);
	glPopMatrix();


	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();

	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);

		mesa();

	
	
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Proyecto de Final Laboratorio");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Pachinko");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	text_izq-= 0.01;
	text_der-= 0.01;
	if(text_izq<-1)
		text_izq=0;
	if(text_der<0)
		text_der=1;

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
			case 'l':    //Prende y apaga luz 0 adentro y fuera del cuarto
			
			glEnable(GL_LIGHT1);

			break;
			case 'L':
	
			glDisable(GL_LIGHT1);

			break;

			case 'k':    //Prende y apaga luz 0 adentro y fuera del cuarto
			
			glEnable(GL_LIGHT0);

			break;
			case 'K':
	
			glDisable(GL_LIGHT0);

			break;

		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
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
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto Final"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}