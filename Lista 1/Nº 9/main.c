#include <stdio.h>
#include <math.h>

int main() {
   
    float x, y, z;

    printf("Digite o valor de x: ");
    scanf("%f", &x);
    printf("Digite o valor de y: ");
    scanf("%f", &y);

    if (x > 0 && y > 0) {
        printf("O ponto (%.2f, %.2f) está no quadrante superior direito.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("O ponto (%.2f, %.2f) está no quadrante superior esquerdo.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("O ponto (%.2f, %.2f) está no quadrante inferior esquerdo.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("O ponto (%.2f, %.2f) está no quadrante inferior direito.\n", x, y);
    } else {
        printf("O ponto (%.2f, %.2f) está na origem.\n", x, y);
    }

    z = sqrt(x * x + y * y);
    printf("A distância euclidiana do ponto ao centro de coordenadas é: %.2f\n", z);

  
    z = x * y;
    printf("O produto entre x e y em notação científica é: %e\n", z);

    return 0;
}