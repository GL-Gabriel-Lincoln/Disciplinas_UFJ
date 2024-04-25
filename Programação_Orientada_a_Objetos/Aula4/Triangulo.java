package Programação_Orientada_a_Objetos.Aula4;

public class Triangulo {

    int baseTriangulo;
    int alturaTriangulo;

    Triangulo() {

    }

    public Triangulo(int base, int altura) {
        this.baseTriangulo = base;
        this.alturaTriangulo = altura;
    }

    public int getBaseTriangulo() {
        return baseTriangulo;
    }

    public int getAlturaTriangulo() {
        return alturaTriangulo;
    }

    public void setBaseTriangulo(int baseTriangulo) {
        this.baseTriangulo = baseTriangulo;
    }

    public void setAlturaTriangulo(int alturaTriangulo) {
        this.alturaTriangulo = alturaTriangulo;
    }

    public double calcularArea() {
        return (double) (this.baseTriangulo * this.alturaTriangulo) / 2;
    }
}
