#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>

#include "core.h"

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);

//
// >>> Caro aluno: declare aqui as funÃ§Ãµes que vocÃª implementar <<<
//

//Definição da estrutura para o ponto
struct Pontos
{
	int x;
	int y;
};

//Definição da estrutura para a cor
struct Cor
{
	float r; 
	float g; 
	float b; 
	int a;
};

//Aqui é a declaração das funções.
void PutPixel(struct Pontos p, struct Cor c);
void DrawLine(struct Pontos p0, struct Cor c0, struct Pontos p1, struct Cor c1);
void DrawTriangle(struct Pontos p0, struct Cor c0, struct Pontos p1, struct Cor c1, struct Pontos p2, struct Cor c2);

#endif  // MYGL_H
