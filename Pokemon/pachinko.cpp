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
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_madera;
CTexture t_metal01;
CTexture t_pachinko;
CTexture t_maderaT;
CTexture t_bandeja;

CModel clavo;

bool mov = true;

int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


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

	clavo._3dsLoad("Column art recon N260613.3ds");

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

void cilindro(float radio, float altura, int resolucion)
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
		glColor3f(0.752, 0.752, 0.752);
		glVertex3fv(v2);
		glVertex3fv(v3);
		glVertex3fv(v5);
		glVertex3fv(v4);
		glEnd();

	}
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
	
	glPushMatrix(); //inicia la mesa
	//glColor3f(1.0, 1.0, 1.0);


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

	glPushMatrix();//inserccion de os clavos implementando modelos 3ds
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
	glPushMatrix();//inserccion de os clavos implementando modelos 3ds
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
	cilindro(10.0, 3.0, 150);
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
	glPopMatrix();

	cilindro(10.0, 3.0, 150);//termina cilindro
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
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Proyecto de Final");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Pinball");
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