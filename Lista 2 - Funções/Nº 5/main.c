//IRPF

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcular_irpf(float salario_bruto) {
    float irpf = 0.0;
    if (salario_bruto > 2259.20) {
        float faixa2 = (salario_bruto > 2826.65) ? 2826.65 - 2259.20 : salario_bruto - 2259.20;
        irpf += faixa2 * 0.075;
    }
    if (salario_bruto > 2826.65) {
        float faixa3 = (salario_bruto > 3751.05) ? 3751.05 - 2826.65 : salario_bruto - 2826.65;
        irpf += faixa3 * 0.15;
    }
    if (salario_bruto > 3751.05) {
        float faixa4 = (salario_bruto > 4664.68) ? 4664.68 - 3751.05 : salario_bruto - 3751.05;
        irpf += faixa4 * 0.225;
    }
    if (salario_bruto > 4664.68) {
        float faixa5 = salario_bruto - 4664.68;
        irpf += faixa5 * 0.275;
    }
    return irpf;
}

float calcular_inss(float salario_bruto) {
    float inss = 0.0;
    if (salario_bruto <= 1412.00) {
        inss = salario_bruto * 0.075;
    } else if (salario_bruto <= 2666.68) {
        inss = 1412.00 * 0.075 + (salario_bruto - 1412.00) * 0.09;
    } else if (salario_bruto <= 4000.03) {
        inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (salario_bruto - 2666.68) * 0.12;
    } else if (salario_bruto <= 7786.02) {
        inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (4000.03 - 2666.68) * 0.12 + (salario_bruto - 4000.03) * 0.14;
    } else {
        inss = 1412.00 * 0.075 + (2666.68 - 1412.00) * 0.09 + (4000.03 - 2666.68) * 0.12 + (7786.02 - 4000.03) * 0.14;
    }
    return inss;
}

float calcular_vt(float salario_bruto, float vt) {
    float desconto_vt = salario_bruto * 0.06;
    return (vt < desconto_vt) ? vt : desconto_vt;
}

float calcular_salario_liquido(float salario_bruto, float irpf, float inss, float vt, float va, float salario_extra, float desconto_atrasos, float plano_saude) {
    return salario_bruto - irpf - inss - vt + va + salario_extra - desconto_atrasos - (plano_saude * 0.2);
}

float calcular_gastos_empresa(float salario_bruto, float vt, float va, float plano_saude) {
    float empregador_vt = vt - calcular_vt(salario_bruto, vt);
    return salario_bruto * 0.11 + salario_bruto * 0.0833 + salario_bruto * 0.08 + salario_bruto * 0.04 + salario_bruto * 0.0793 + va + empregador_vt + plano_saude * 0.8;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese_Brazil");

    if (argc < 8) {
        printf("Uso: %s <salario_bruto> <vt> <va> <plano_saude> <hr_semanal> <hr_extra> <hr_atraso>\n", argv[0]);
        return 1;
    }

    float salario_bruto = atof(argv[1]);
    float vt = atof(argv[2]);
    float va = atof(argv[3]);
    float plano_saude = atof(argv[4]);
    float hr_semanal = atof(argv[5]);
    float hr_extra = atof(argv[6]);
    float hr_atraso = atof(argv[7]);

    if (salario_bruto < 1412) {
        printf("O salário mínimo 2024 é R$ 1412. Por favor, insira um valor igual ou maior.\n");
        return 1;
    }

    float irpf = calcular_irpf(salario_bruto);
    float inss = calcular_inss(salario_bruto);
    float desconto_vt = calcular_vt(salario_bruto, vt);

    float salario_hora = salario_bruto / (hr_semanal * 5);
    float salario_extra = (salario_hora * 1.5) * hr_extra;
    float desconto_atrasos = salario_hora * hr_atraso;

    float salario_liquido = calcular_salario_liquido(salario_bruto, irpf, inss, desconto_vt, va, salario_extra, desconto_atrasos, plano_saude);
    float gastos_empresa = calcular_gastos_empresa(salario_bruto, vt, va, plano_saude);

    printf("-------------------------------------------------------\n");
    printf("                 \x1b[1mCALCULADORA DE SALÁRIO\x1b[0m                \n");
    printf("-------------------------------------------------------\n\n");

    printf("Salário Bruto: R$ %.2f\n", salario_bruto);

    printf("\n\x1b[1mDESCONTOS\x1b[0m\n");
    printf("IRPF: R$ %.2f\n", irpf);
    printf("INSS: R$ %.2f\n", inss);
    printf("Vale Transporte: R$ %.2f\n", desconto_vt);
    printf("Plano de Saúde: R$ %.2f\n", plano_saude * 0.2);
    printf("Desconto Atrasos: R$ %.2f\n", desconto_atrasos);

    printf("\n\x1b[1mACRESCIMOS\x1b[0m\n");
    printf("Vale Alimentação: R$ %.2f\n", va);
    printf("Horas Extras: R$ %.2f\n", salario_extra);
    printf("-------------------------------------------------------\n");

    printf("\x1b[1mSalário Líquido: R$ %.2f\n\n\x1b[0m", salario_liquido);
    
    printf("Gastos Totais da Empresa: R$ %.2f\n", gastos_empresa + salario_bruto);
    printf("Custo Total para a Empresa: R$ %.2f\n", gastos_empresa + salario_bruto);
    printf("(%.2f%% maior em relação ao salário bruto)\n", (gastos_empresa + salario_bruto) / salario_bruto * 100);

    return 0;
}
