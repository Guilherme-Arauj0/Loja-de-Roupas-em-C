#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_ALUNOS 5

struct Aluno {
    char nome[50];
    int matricula;
    int idade;
    char sexo;
    float notaA1;
    float notaA2;
    int frequencia;
    float media;
};

int i;

float calcularMedia(float notaA1, float notaA2) {
    return (notaA1 + notaA2) / 2.0;
}

float calcularPercentualReprovados(struct Aluno alunos[], int numAlunos) {
    int contadorReprovados = 0;

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].media < 6.0 || alunos[i].frequencia < 60) {
            contadorReprovados++;
        }
    }

    return (float)contadorReprovados / numAlunos * 100.0;
}



void listarDadosCalculados(struct Aluno alunos[], int numAlunos) {
    float maiorMedia = 0.0;
    float mediaTotal = 0.0;
    float percentualReprovados;

    for (i = 0; i < numAlunos; i++) {
        mediaTotal += alunos[i].media;

        if (alunos[i].media > maiorMedia) {
            maiorMedia = alunos[i].media;
        }
    }

    percentualReprovados = calcularPercentualReprovados(alunos, numAlunos);

    printf("Maior m�dia dos alunos cadastrados: %.2f\n", maiorMedia);
    printf("M�dia de notas dos alunos: %.2f\n", mediaTotal / numAlunos);
    printf("Percentual de alunos reprovados: %.2f%%\n", percentualReprovados);
}

void cadastrarAluno(struct Aluno *aluno) {
    printf("Nome: ");
    scanf(" %[^\n]", aluno->nome);

    printf("Matr�cula: ");
    scanf("%d", &aluno->matricula);

    printf("Idade: ");
    scanf("%d", &aluno->idade);

    printf("Sexo (M/F): ");
    scanf(" %c", &aluno->sexo);

    printf("Nota A1: ");
    scanf("%f", &aluno->notaA1);

    printf("Nota A2: ");
    scanf("%f", &aluno->notaA2);

    printf("Frequ�ncia: ");
    scanf("%d", &aluno->frequencia);

    
    aluno->media = calcularMedia(aluno->notaA1, aluno->notaA2);
}

void consultarAlunoPorMatricula(struct Aluno alunos[], int numAlunos, int matricula) {
    int alunoEncontrado = 0;

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Aluno encontrado:\n\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matr�cula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequ�ncia: %d\n", alunos[i].frequencia);
            printf("M�dia: %.2f\n", alunos[i].media);

            alunoEncontrado = 1;
            break;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com a matr�cula %d.\n", matricula);
    }
}

void consultarAlunoPorNome(struct Aluno alunos[], int numAlunos, const char *nome) {
    int alunoEncontrado = 0;

    for (i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            printf("Aluno encontrado:\n\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matr�cula: %d\n", alunos[i].matricula);
            printf("Idade: %d\n", alunos[i].idade);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Nota A1: %.2f\n", alunos[i].notaA1);
            printf("Nota A2: %.2f\n", alunos[i].notaA2);
            printf("Frequ�ncia: %d\n", alunos[i].frequencia);
            printf("M�dia: %.2f\n", alunos[i].media);

            alunoEncontrado = 1;
        }
    }

    if (!alunoEncontrado) {
        printf("Nenhum aluno encontrado com o nome %s.\n", nome);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    int opcao;
    int matricula;
    char nome[50];

	
    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Consultar dados dos alunos\n");
        printf("3 - Sair\n");
        printf("\nDigite a op��o desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numAlunos >= MAX_ALUNOS) {
                    printf("Limite de alunos cadastrados atingido!\n");
                } else {
                    cadastrarAluno(&alunos[numAlunos]);
                    numAlunos++;

                    char cadastrarOutro;
                    printf("\nDeseja cadastrar outro aluno? (S/N): ");
                    scanf(" %c", &cadastrarOutro);

                    if (cadastrarOutro == 'N' || cadastrarOutro == 'n') {
                        
                        system("cls");
                        
						break;
						
                    }else{
                    	
                    	system("cls");
					}
                }
                break;
            case 2:
                if (numAlunos == 0) {
                    printf("Nenhum aluno cadastrado!\n");
                } else {
                    int consultaOpcao;
                    printf("\nCONSULTAR DADOS DOS ALUNOS\n");
                    printf("1 - Consultar aluno pelo n�mero da matr�cula\n");
                    printf("2 - Consultar aluno pelo nome\n");
                    printf("3 - Retornar ao menu principal\n");
                    printf("Digite a op��o desejada: ");
                    scanf("%d", &consultaOpcao);

                    switch (consultaOpcao) {
                        case 1:
                            printf("N�mero da matr�cula: ");
                            scanf("%d", &matricula);
                            consultarAlunoPorMatricula(alunos, numAlunos, matricula);
                            break;
                        case 2:
                            printf("Nome: ");
                            scanf(" %[^\n]", nome);
                            consultarAlunoPorNome(alunos, numAlunos, nome);
                            break;
                        case 3:
                            break;
                        default:
                            printf("Op��o inv�lida!\n");
                            break;
                    }
                }
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
                break;
        }
    } while (opcao != 3);

    printf("\n"); listarDadosCalculados(alunos, numAlunos);

    return 0;
}
