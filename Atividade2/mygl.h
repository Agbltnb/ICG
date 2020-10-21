#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a mem�ria do framebuffer

// Declara��o da fun��o que chamar� as fun��es implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funções que você implementar <<<
//

//Defini��o da estrutura para o ponto
struct Pontos
{
	int x;
	int y;
};

//Defini��o da estrutura para a cor
struct Cor
{
	float r; 
	float g; 
	float b; 
	int a;
};

//Aqui � a declara��o das fun��es.
void PutPixel(struct Pontos p, struct Cor c);
void DrawLine(struct Pontos p0, struct Cor c0, struct Pontos p1, struct Cor c1);
void DrawTriangle(struct Pontos p0, struct Cor c0, struct Pontos p1, struct Cor c1, struct Pontos p2, struct Cor c2);

#endif  // MYGL_H
