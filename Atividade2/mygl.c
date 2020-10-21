#include "mygl.h"

#include <math.h>
//#include <vector>
//#include <algorithm>




unsigned char* fb_ptr = NULL;

void InitMyGl(void) {
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));	

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i) {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }    
}

unsigned char* GetFBMemPtr(void) {
	return fb_ptr;
}

void CloseMyGl(void) {
    if (!fb_ptr)
        free(fb_ptr);
}

//
// >>> Caro aluno: defina aqui as funções que você implementar <<<
//

void PutPixel(struct Pontos p, struct Cor c)   //Função responsavee para colorir o pixel
{
	//Efetua o calulo no offset do ponteira para a cor do buffer	
	int end = p.x * 4 + p.y * 4 * IMAGE_WIDTH;


	//Adiciona a informação de cor do pixel para cada banda, r,g,b,a
	fb_ptr[end] 	   = c.r;
	fb_ptr[end + 1] = c.g;
	fb_ptr[end + 2] = c.b;
	fb_ptr[end + 3] = c.a;
}



void DrawLine(struct Pontos pA, struct Cor cA, struct Pontos pB, struct Cor cB) // função responsavel no preenchimento da lista
{
	int x = pA.x;
	int y = pA.y;
	int xf = pB.x;
	int yf = pB.y;
	
//preemcher cada pixel da linha
	struct Cor c = cA;
	
	
	
	int aux = 1;
	int auy = 1;
	//os valores a seguir serão calculados a partir do auxiliares
	int dx = xf - x;
	
	if (dx < 0) {
	dx *= -1; 
	aux = -1;} // se o delta x for negativo o aux tbm será
	int dy = yf - y;
	
	if (dy < 0) { //se o delta y for negativo o aux tbm será
	dy *= -1; 
	auy = -1;}
	
	PutPixel(pA, cA);
	//daqui para baixo é a simulação de um rebatimento de qualquer linha para o primeiro octante
	if (dy <= dx){
		int D = 2 * dy - dx;
		int inc_E = 2 * dy;
		int inc_NE = 2 * (dy - dx);
		
//Cálculo para cada banda utilizados a interpolação
		float dr = (cB.r - cA.r)/dx;
		float dg = (cB.g - cA.g)/dx;
		float db = (cB.b - cA.b)/dx;
		
		while(x * aux < xf){
			if (D <= 0){
				D += inc_E;
				x = x + 1 * aux;
			} else{
				D += inc_NE;
				x = x + 1 * aux;
				y = y + 1 * auy;
			}
			
			c.r += dr;
			c.g += dg;
			c.b += db;
			
			struct Pontos p = {x, y};

			PutPixel(p, c);
	 	}
	} else{
		int D = 2 * dx - dy;
		int inc_E = 2 * dx;
		int inc_NE = 2 * (dx - dy);
		
		float dr = (cB.r - cA.r)/dy;
		float dg = (cB.g - cA.g)/dy;
		float db = (cB.b - cA.b)/dy;
		
		while(y * auy < yf){
			if (D <= 0){
				D += inc_E;
				y = y + 1 * auy;
			} else{
				D += inc_NE;
				x = x + 1 * aux;
				y = y + 1 * auy;
			}
			
			c.r += dr;
			c.g += dg;
			c.b += db;
			
			struct Pontos p = {x, y};
			
			PutPixel(p, c);
		}
	}
}


//O triângulo é criado interligando de 3 linhas  utilizando a função DrawLine
void DrawTriangle(struct Pontos pA, struct Cor cA, struct Pontos pB, struct Cor cB, struct Pontos pC, struct Cor cC) 
{
	DrawLine(pA, cA, pB, cB);
	DrawLine(pB, cB, pC, cC);
	DrawLine(pC, cC, pA, cA);

	
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void) {
    //
    // >>> Caro aluno: chame aqui as funções que você implementou <<<
    //
    
    //Inicialização das paletas de cores que 
    struct Cor amarelo = {255, 255, 0, 255};
    struct Cor azul = {0, 0, 255, 255};
    struct Cor branco = {255, 255, 255, 255};
    struct Cor ciano = {0, 255, 255, 255};
    struct Cor laranja = {252, 132, 3, 255};
    struct Cor magenta = {255, 0, 255, 255};
    struct Cor verde = {0, 255, 0, 255};	
    struct Cor vermelho = {255, 0, 0, 255};
    struct Cor roxo = {166, 0, 255, 255};    
    
	
	//{

	//}

	
	//Teste  Desenha uma linha branca do canto inferior esquerdo da tela ao canto superior direito da tela
	/*{
		struct Pontos pA = {0, 0};
		//struct Pontos pB = {IMAGE_WIDTH - 1, IMAGE_HEIGHT - 1};
		struct Pontos pB = {200, 300};
		DrawLine(pA, amarelo, pB, amarelo);
	}*/
	

	
	//Teste-> Desenhando um triângulo na tela
	/*{
		struct Pontos pAA = {0, 0};
		struct Pontos pBB = {200,300};
		struct Pontos pCC = {300,200};
	
		DrawTriangle(pA, roxo, pB, azul, pC, vermelho);
	}*/
	/*{// quadrado
		struct Pontos pAA = {0, 0};
		//struct Pontos pB = {IMAGE_WIDTH - 1, IMAGE_HEIGHT - 1};
		struct Pontos pBB = {100, 0};
		struct Pontos pCC = {100,100};
		struct Pontos pDD = {0,100};
	


		DrawLine(pAA, amarelo,pBB,  azul);
		DrawLine(pBB, branco,  pCC,  ciano);
		DrawLine(pCC, ciano, pDD,  laranja);
		DrawLine(pDD,   branco, pAA, roxo);


	}*/

	{ int xC = IMAGE_WIDTH/2;
	int yC = IMAGE_HEIGHT/2;

	int pAA = IMAGE_WIDTH -1;
	int pBB = xC / 2;
	int pA1 = IMAGE_HEIGHT -1;
	int pB2 = yC / 2;

	struct Pontos central = {xC,yC};
	struct Pontos linha1 = {pAA,pA1};
	struct Pontos linha2 = {0,pA1};
	struct Pontos linha3 = {pBB,0};
	struct Pontos linha4 = {0,pB2};
	 

		DrawLine(central, amarelo,linha1,  azul);
		DrawLine(central, branco,  linha2,  ciano);
		DrawLine(central, ciano, linha3,  laranja);
		DrawLine(central,   branco, linha4, roxo);


	}


}


/*void DrawCircleArc(Point piu , float radius, Cor cA, float angle, float var_an){
//struct Pontos pA, struct Cor cA, struct Pontos pB, struct Cor cB, struct Pontos pC, struct Cor cC
//chama a função putpixel

	PutPixel(piu, cA);
	float aux_ang = 0.0f;
	
	while(aux_ang <= angle){
		float teta = toRadians(aux_ang);

	//calculos do x e y
	int x = piu.x + round(radius * cos((teta+aux_ang)));
	int y = piu.y + round(radius * sin((teta+aux_ang)));

	PutPixel(Point(x,y),cA);
	aux_ang +=0.5f;     }


}

float toRadians(float degrees){ return (degrees * 3.1415926535)/180.f;}*/
