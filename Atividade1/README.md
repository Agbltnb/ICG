# Atividade 1 

Esta atividade tem como objetivo em verificar se o ambiente OpenGL está devidamente funcional nos computadores dos discentes e também os familiarizar com a ferramenta.

## Desenvolvimento

A partir do repositório passado pelo docente, o utilizaremos para verificar se o sistema que o discente utiliza está previamento configurado. Após obter os códigos, foi necessário efetuar a instalação o OpenGL no SO ubuntu 18.04, com os seguintes comandos abaixo:


> $ sudo apt-get update

> $ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

## Execução

Para que possamos executar o programa deveremos utilizar os seguintes comandos abaixo:


> $ gcc main.c -o moderngl_hello_world -lglut -lGLU -lGL

> $ ./moderngl_hello_world

Mas, nesta fase de execução eu testei em dois computadores que possuo, para o computador 1, obtive o primeiro resultado:

Para o computador dois, eu obtive este segundo resultado.


## Dificuldades

Antes de decidir utilizar o Sistema Operacional Ubuntu 18.04, a primeira tentativa foi em tentar fazer o programa executar no Sistema Operacional Windows, através no Devc++ e instalando o  glut-devc.zip, porém eu não consegui fazer que o programa fosse executado no windows por hora, então para efeito deste primeiro entregável e não perder a entrega por isso que houve a migração de sistema operacional.

## Conclusão

Os objetivos para este primeiro entregável foi alcançado com êxito, embora o discente não ficou muito satisfeito por não ter conseguido, por ora, fazer funcionar no Windows.

## Bibliografia Auxiliar

http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/

https://www.inf.pucrs.br/~manssour/CG/pratica1/

https://www.inf.pucrs.br/~manssour/OpenGL/Devc++.html

