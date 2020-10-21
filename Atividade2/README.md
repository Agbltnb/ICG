
# Atividade 2 
## Descrição 

Este trabalho consiste em implementar as técnicas básicas da Rasterização apresentadas na disciplina de Introdução à Computação Gráfica. Será realizados os seguintes aspectos: a rasterização de um ponto, de uma linha , de um triângulo cores. O trabalho foi desenvolvido utilizando uma framework, disponibilizada pelo
docente responsável pela disciplina, Christian Azambuja Pagot. A linguagem adotada foi C++.

A estrutura da Framework disponibilizada é: 

- core.h : responsável pela configuração da dimensão da tela.
- frame.buffer : O ponteiro aponta para o primeiro byte color, assim, ele irá apresentar as coordenadas que serão rasterizadas do pixel.
- main.c e main.h:  consistem em funções e variáveis que irão acessar à memória de vdeo durante a simulação.
- mygl.c : Neste arquivo que deveremos implementar funçes relacionadas à rasterização e a interpolação de cores.
- mygl.h : Arquivo de cabeçalho da função principal onde será definida suas respecitivas estruturas.

## Desenvolvimento 

Para o desenvolvimento desta atividade alguns requisitos deverão ser atingidos, são esses:

- Implementar a interpolaço de cores: a partir de dois pontos, a operação de interpolação deverá interpolar a cor da linha com base nas dimenses e cores pré-estabelicidas pelo discente.

- Implementação da função PutPixel : que deverá receber como entrada as coordenadas de um ponto e uma cor em RGBA, para que possamos fazer a rasterização de um determinado ponto na memória de vídeo. 

- Implementar a função DrawLine :  responsavel por rasterizar uma linha, com dois pontos sendo atribuidos como entrada para um respectivo vertice.  A reta resultante será dado a partir da interpolação e sua coloração se tornará um degradê.

- Implementação da função DrawTriangle:  responsável em recebe como parâmetros três vértice e suas respectivas cores, para que desse irá chamar a função DrawLine e un triângulo possa ser plotado.

## PutPixel 

Nesta função a lógica que foi utilizada para a implementação é baseada no cálculo do offset, onde a posição do pixel da tela, e atribuindo a cor desejada para a rasterização do ponto. O offset é cálculado por meio da expressão X4 + Y4*Altura, no qual o X e Y representam as coordenadas x e y do ponto a ser rasterizado, e a Altura está relacionada a dimenssão da tela.

## DrawLine

Para a implementação desta função foi algortimo do ponto médio que o docente solicitou e a partir das aulas dadas pelo menos podemos obter uma estratégia em como poderá ser chegar a uma determinada solução. 

Para os calculos será utilizado variaveis auxiliares para obter o comportamento das taxas de variações.

 - Variação do eixo X negativa, Dx<0 : a reta cresce para o lado negativo, sendo necessário a inversão dos pontos. Então o ponto de origem é modificado para destino e vice-versa.

 - Variação do eixo Y negativa, Dy<0 : Quando a reta é crescente para o lado negativo do Y, calculamos o módulo do valor desta variação e dessa forma, assim o ΔY ficará  positivo. 


## DrawTriangle
Por fim, esta função é responsavel em fazer três chamadas da função DrawLine para que três retas possam ser rasterizadas e formem o desenho de um triângulo, com suas arestas possuindo cores interpoladas.

### Resultados


