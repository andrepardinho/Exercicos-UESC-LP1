// ANDRÉ PARDINHO - 202410507

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    float salario_bruto = 0, irpf = 0, inss = 0, salario_liquido = 0;
    float VT = 0, descontoVT = 0, VA = 0, plano_saude = 0;
    float hr_semanal = 0, hr_atraso = 0, hr_extra = 0;
    float salario_hora = 0, salario_extra = 0, desconto_atrasos = 0;

    printf("-------------------------------------------------------\n");
    printf("                 \x1b[1mCALCULADORA DE SALÁRIO\x1b[0m                \n");
    printf("-------------------------------------------------------\n\n");

    do {
        printf("\x1b[1mDigite o valor do seu salário bruto normal: \x1b[0m");
        scanf("%f", &salario_bruto);
        if (salario_bruto < 1412) {
            printf("\nO salário mínimo 2024 é R$ 1412. Por favor, insira um valor igual ou maior.\n");
        }
    } while (salario_bruto < 1412);

    printf("\n\nBase de cálculo do imposto de renda - fev de 2024\n");
    printf("--------------------------------------------------\n");
    printf("  \x1b[1m\x1b[34mFAIXA SALARIAL              TAXA     DESCONTO\x1b[0m\x1b[37m\n");
    printf("--------------------------------------------------\n");



  int faixa_salarial = 0;
  if (salario_bruto <= 2259.20) faixa_salarial = 1;
  else if (salario_bruto <= 2826.65) faixa_salarial = 2;
  else if (salario_bruto <= 3751.05) faixa_salarial = 3;
  else if (salario_bruto <= 4664.68) faixa_salarial = 4;
  else faixa_salarial = 5;

  switch (faixa_salarial) {
      case 5:
          irpf += (salario_bruto - 4664.68) * 0.275;
          printf("  Acima de R$4664,68         | 27,5%% | R$ %.2f\n", (salario_bruto - 4664.68) * 0.275);
      case 4:
          irpf += ((salario_bruto > 4664.68 ? 4664.68 : salario_bruto) - 3751.05) * 0.225;
          printf("--------------------------------------------------\n  De R$3751,06 até R$4664,68 | 22,5%% | R$ %.2f\n", ((salario_bruto > 4664.68 ? 4664.68 : salario_bruto) - 3751.05) * 0.225);
      case 3:
          irpf += ((salario_bruto > 3751.05 ? 3751.05 : salario_bruto) - 2826.65) * 0.15;
          printf("--------------------------------------------------\n  De R$2826,66 até R$3751,05 |  15%%  | R$ %.2f\n", ((salario_bruto > 3751.05 ? 3751.05 : salario_bruto) - 2826.65) * 0.15);
      case 2:
          irpf += ((salario_bruto > 2826.65 ? 2826.65 : salario_bruto) - 2259.20) * 0.075;
          printf("--------------------------------------------------\n  De R$2259,21 até R$2826,65 |  7,5%% | R$ %.2f\n", ((salario_bruto > 2826.65 ? 2826.65 : salario_bruto) - 2259.20) * 0.075);
      case 1:
          printf("--------------------------------------------------\n  Até R$2259,20              |  0,0%% | Isento\n");
          break;
  }
  
    printf("--------------------------------------------------\n");
    printf("\x1b[34m\x1b[1m  TOTAL DE IRPF A SER PAGO\x1b[37m\x1b[0m   | \x1b[34m\x1b[1mR$ %.2f\x1b[37m\x1b[0m\n", irpf);
    printf("--------------------------------------------------\n");

    // Calcula o salário líquido menos irpf
    salario_liquido = salario_bruto - irpf;

    // Exibe o resultado
    printf("\x1b[36m* Salário com o IRPF descontado: R$ %.2f\n\x1b[37m", salario_liquido);

  //PARTE 2
  //CALCULO DE OUTROS DESCONTOS
  printf("\n\n\n\x1b[1mVamos calcular outros descontos ou acréscimos sobre seu salário:\n\n\n\x1b[0m");

    // CÁLCULO DO INSS
    int faixa_inss;
    if (salario_bruto <= 1412.00) {
        faixa_inss = 1;
    } else if (salario_bruto <= 2666.68) {
        faixa_inss = 2;
    } else if (salario_bruto <= 4000.03) {
        faixa_inss = 3;
    } else if (salario_bruto <= 7786.02) {
        faixa_inss = 4;
    } else {
        faixa_inss = 5;
    }

    switch (faixa_inss) {
        case 1:
            inss = salario_bruto * 0.075;
            break;
        case 2:
            inss = 1412.00 * 0.075 + (salario_bruto - 1412.00) * 0.09;
            break;
        case 3:
            inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (salario_bruto - 2666.68) * 0.12;
            break;
        case 4:
            inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (4000.03 - 2666.68) * 0.12 + (salario_bruto - 4000.03) * 0.14;
            break;
        case 5:
            inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (4000.03 - 2666.68) * 0.12 + (7786.02 - 4000.03) * 0.14;
            break;
    }

    
    // CÁLCULO DO VALE TRANSPORTE
    printf("Digite o valor do seu vale transporte: ");
    scanf("%f", &VT);

    descontoVT = salario_bruto * 0.06;
    if (VT < descontoVT) {
        descontoVT = VT;
    } else {
        descontoVT = salario_bruto * 0.06;
    }

    // VALE ALIMENTAÇÃO
    printf("Digite o valor do seu vale alimentação: ");
    scanf("%f", &VA);

    // PLANO DE SAÚDE
    printf("Digite o valor do seu plano de saúde: ");
    scanf("%f", &plano_saude);

    // RESULTADOS
    printf("\n--------------------------------------------------\n");
    printf(" \x1b[1m\x1b[34mDESCRIÇÃO                       DESCONTO\x1b[0m\x1b[37m\n");
    printf("--------------------------------------------------\n");
    printf(" Vale transporte               | R$ %.2f\n", descontoVT);
    printf("--------------------------------------------------\n");
    printf(" Vale alimentação              | R$ 0,00\n");
    printf("--------------------------------------------------\n");
    printf(" Plano de saúde                | R$ %.2f\n", plano_saude * 0.2);
    printf("--------------------------------------------------\n");
    printf(" INSS a ser pago               | R$ %.2f\n", inss);
    printf("--------------------------------------------------\n");

    printf("\n\x1b[36m* O desconto do vale transporte é de até 6%% do seu salário (R$ %.2f)\n", salario_bruto * 0.06);
    printf("* O desconto do plano de saúde é de 20%% do valor do plano\x1b[37m\n");

    // CÁLCULO HORA EXTRA E ATRASOS
    printf("\n\nDigite quantas horas semanais você trabalha: ");
    scanf("%f", &hr_semanal);

    printf("Digite quantas horas extras você trabalhou no mês: ");
    scanf("%f", &hr_extra);

    printf("Digite quantas horas de atraso você teve no mês: ");
    scanf("%f", &hr_atraso);

    salario_hora = salario_bruto / (hr_semanal * 5);
    salario_extra = (salario_hora * 1.5) * hr_extra;
    desconto_atrasos = salario_hora * hr_atraso;

    printf("\n--------------------------------------------------\n");
    printf(" \x1b[1mGanhos com horas extras\x1b[0m            | R$ %.2f", salario_extra);
    printf("\n--------------------------------------------------\n");
    printf(" \x1b[1mDescontos de atraso\x1b[0m                | R$ %.2f\n", desconto_atrasos);
    printf("--------------------------------------------------\n");
    printf("\x1b[36m* Seu salário-hora é de R$%.2f e a sua hora extra vale R$%.2f\x1b[37m\n", salario_hora, salario_hora * 1.5);

    // Calcula o salário líquido
    salario_liquido = salario_bruto - irpf - inss - descontoVT + VA + salario_extra - desconto_atrasos - (plano_saude * 0.2);

    printf("\n\nApós os descontos e acréscimos:\n\x1b[1m\x1b[34mSEU SÁLARIO LIQUIDO É R$ %.2f\x1b[0m\x1b[37m\n", salario_liquido);

    // PARTE 3

    printf("\n\n\n\x1b[1mVamos dar uma olhada em outros gastos que sua empresa tem com você além do seu salário bruto e qual o custo de um funcionário por mês.\x1b[0m\n");

    // Pausa para continuar
    printf("\nPressione Enter para continuar...");
    getchar(); // Espera o Enter ser pressionado
    getchar(); // Limpa o buffer de entrada

    // Cálculo parcela vale transporte empregador
    float empregadorVT = VT - descontoVT;
    // Cálculo gastos extras da empresa
    float GASTOS_EMPRESA = salario_bruto * 0.11 + salario_bruto * 0.0833 + salario_bruto * 0.08 + salario_bruto * 0.04 + salario_bruto * 0.0793 + VA + empregadorVT + plano_saude * 0.8;

    printf("\n--------------------------------------------------\n");
    printf("\x1b[1m\x1b[34m  DESCRIÇÃO                           GASTOS\x1b[0m\x1b[37m\n");
    printf("--------------------------------------------------\n");
    printf(" Fração de férias (11%%)              | R$ %.2f\n", salario_bruto * 0.11);
    printf("--------------------------------------------------\n");
    printf(" Fração de 13º salário (8.33%%)       | R$ %.2f\n", salario_bruto * 0.0833);
    printf("--------------------------------------------------\n");
    printf(" FGTS (8%%)                           | R$ %.2f\n", salario_bruto * 0.08);
    printf("--------------------------------------------------\n");
    printf(" Provisão de multa p/rescisão (4%%)   | R$ %.2f\n", salario_bruto * 0.04);
    printf("--------------------------------------------------\n");
    printf(" Previdenciário (7.93%%)              | R$ %.2f\n", salario_bruto * 0.0793);
    printf("--------------------------------------------------\n");
    printf(" Vale transporte                     | R$ %.2f\n", empregadorVT);
    printf("--------------------------------------------------\n");
    printf(" Vale alimentação                    | R$ %.2f\n", VA);
    printf("--------------------------------------------------\n");
    printf(" Plano de saúde                      | R$ %.2f\n", plano_saude * 0.8);
    printf("--------------------------------------------------\n");
    printf("\x1b[1m\x1b[34m  TOTAL DE GASTOS EXTRAS\x1b[0m\x1b[37m             | \x1b[1m\x1b[34mR$ %.2f\x1b[0m\x1b[37m\n", GASTOS_EMPRESA);
    printf("--------------------------------------------------\n");

    printf("\x1b[36m* As porcentagens de gastos extras acima especificadas são baseadas no seu salário bruto\x1b[37m\n");
    printf("\x1b[36m* Os valores e tarifas considerados são os das empresas optantes pelo sistema 'Simples Nacional'\x1b[37m\n");

    printf("\n\nCom esses gastos:\n\x1b[1m\x1b[34mSEU CUSTO PARA A EMPRESA É DE R$ %.2f\x1b[0m\x1b[37m\n", GASTOS_EMPRESA + salario_bruto);

    printf("(Isso representa um valor %.2f%% maior em relação ao salário bruto).", (GASTOS_EMPRESA + salario_bruto) / salario_bruto * 100);

    return 0;
}
