# Trabalho Final AED / UPGRADE

Este projeto é um upgrade de um trabalho em c/c++, que tinha como foco uso de Classes em c++ no final do semestre, neste UPGRADE foi implementado uma biblioteca gráfica [OlcGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine/) Cross-Plataforma.
### Abordado no projeto
    - Classes 
    - Objetos 
    - Propriedades
    - Encapsulamento
    - Herança
    - Abstração
    - Sobrecarga
    - Métodos de Acesso (public, private )
    - Organizar Classes e Headers separadamente

### Walls
É uma Classe que recebe herança da Classe Agente, e adiciona a função de andar nos limites(paredes) para o Agente.
### Presa x Predador
São duas Classes Predador e a Presa que recebem herança da Classe Agente, e adiciona novas funções ao Agente, andar aleatoriamente até que a presa entre no campo de visao do pedrador, dando inicio a um perseguição. 

## Dependencias
### Linux
    - GCC 9.2
    - OpenGL
### Windows
    - Visual Studio 
### Compilaçao no Linux
    g++ exec.cpp ./Headers/*.h ./Classes/*.cpp -o exec -lX11 -lGL -lpthread -lpng -w
    
    Bibliotecas obrigatorias
        -lX11 
        -lGL 
        -lpthread 
        -lpng 
    -w desativa mensagens de Warnings

### Compilação no Windows
    Deve ser instalado o Visual Studio para e modulos c/c++,
    e criar um projeto em branco e armazenar os arquivos dentro do projeto,
    alterar os includes e colocar os resources dentro do

## Demonstração

### Projeto Novo
<img src="https://i.imgur.com/ezSSh3l.gif">

### Projeto Antigo
<img src="https://i.imgur.com/uBjIkEb.png">


## Autor

* **Fernando Luiz** - [Feeluiz](https://github.com/feeluiz)
* **Ton Braganca** - [Ton](https://github.com/gleydiston)
## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
