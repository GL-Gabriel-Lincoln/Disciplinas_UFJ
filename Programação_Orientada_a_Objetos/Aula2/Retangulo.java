package Programação_Orientada_a_Objetos.Aula2;

public class Retangulo {

    int baseRetangulo;
    int alturaRetangulo;

    Retangulo(){

    }

    Retangulo(int baseRetangulo, int alturaRetangulo) {
        this.alturaRetangulo = alturaRetangulo;
        this.baseRetangulo = baseRetangulo;
    }

    int calculaArea() {

        return baseRetangulo * alturaRetangulo;

    }
}
