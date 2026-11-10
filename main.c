#include <stdio.h>
#include <stdlib.h>

/* Uma struct funciona como uma ficha com os dados de uma acao. */
struct Acao {
    int codigo;
    char escola[101];
    char tema[101];
    char dataPrevista[11];
    char publicoAlvo[101];
    char responsavel[101];
    int quantidadePrevista;
    int quantidadeEfetiva;
    int situacao; /* 1 = Planejada, 2 = Realizada, 3 = Cancelada. */
};

/* Vetor de 100 fichas. O contador indica quantas estao preenchidas. */
struct Acao acoes[100];
int totalCadastrado = 0;

void limparTela(void) {
    system("cls"); /* Limpa o terminal do Windows. */
}

void aguardarEnter(void) {
    int tecla;
    printf("\nPressione Enter para continuar...");
    fflush(stdout);
    tecla = getchar();
    while (tecla != '\n' && tecla != EOF) {
        tecla = getchar();
    }
}

int tamanhoTexto(char texto[]) {
    int tamanho = 0;
    while (texto[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

void lerTexto(char mensagem[], char texto[], int capacidade) {
    int caractere, tamanho, excedeu, inicio, fim, i;
    while (1) {
        printf("%s", mensagem);
        tamanho = 0;
        excedeu = 0;
        caractere = getchar();
        /* Le a linha inteira, mesmo quando ela ultrapassa o limite. */
        while (caractere != '\n' && caractere != EOF) {
            if (tamanho < capacidade - 1) {
                texto[tamanho] = caractere;
                tamanho++;
            } else {
                excedeu = 1;
            }
            caractere = getchar();
        }
        if (caractere == EOF && tamanho == 0) {
            printf("\nEntrada encerrada. Dados em memoria descartados.\n");
            exit(0);
        }
        texto[tamanho] = '\0';
        inicio = 0;
        fim = tamanho;
        /* Retira espacos nas bordas antes de verificar o preenchimento. */
        while (inicio < fim && (texto[inicio] == ' ' || texto[inicio] == '\t')) inicio++;
        while (fim > inicio && (texto[fim - 1] == ' ' ||
               texto[fim - 1] == '\t' || texto[fim - 1] == '\r')) fim--;
        if (excedeu) printf("[ERRO] Texto muito longo. Limite: %d.\n", capacidade - 1);
        else if (inicio == fim) printf("[ERRO] Campo obrigatorio vazio.\n");
        else {
            for (i = inicio; i < fim; i++) texto[i - inicio] = texto[i];
            texto[fim - inicio] = '\0';
            return;
        }
    }
}

int lerInteiro(char mensagem[], int minimo, int maximo) {
    char texto[30];
    int i, valido, numero;
    while (1) {
        lerTexto(mensagem, texto, 30);
        /* Seis algarismos evitam estouro na conversao e nas somas. */
        valido = tamanhoTexto(texto) <= 6;
        for (i = 0; texto[i] != '\0'; i++) {
            if (texto[i] < '0' || texto[i] > '9') valido = 0;
        }
        if (valido == 1) {
            numero = atoi(texto);
            if (numero >= minimo && numero <= maximo) return numero;
        }
        printf("[ERRO] Informe um inteiro entre %d e %d, com ate 6 algarismos.\n", minimo, maximo);
    }
}

int textosIguais(char primeiro[], char segundo[]) {
    int i = 0;
    while (primeiro[i] != '\0' && segundo[i] != '\0') {
        if (primeiro[i] != segundo[i]) {
            return 0;
        }
        i++;
    }
    return primeiro[i] == segundo[i];
}

int dataValida(char data[]) {
    int i, dia, mes, ano;
    int diasDoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (tamanhoTexto(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && (data[i] < '0' || data[i] > '9')) {
            return 0;
        }
    }
    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');
    ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 +
          (data[8] - '0') * 10 + (data[9] - '0');
    if (ano < 1 || mes < 1 || mes > 12) {
        return 0;
    }
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) diasDoMes[1] = 29;
    return dia >= 1 && dia <= diasDoMes[mes - 1];
}

void cadastrarUsuario(char usuarioCadastrado[], char senhaCadastrada[]) {
    printf("\n=== CRIAR USUARIO ===\n");
    printf("Crie um usuario e uma senha para esta execucao.\n");
    lerTexto("Novo usuario: ", usuarioCadastrado, 40);
    lerTexto("Nova senha: ", senhaCadastrada, 40);
    printf("[SUCESSO] Usuario criado. Entre com os dados cadastrados.\n");
}

void realizarLogin(char usuarioCadastrado[], char senhaCadastrada[]) {
    char usuario[40], senha[40];
    int loginValido = 0;
    while (loginValido == 0) {
        limparTela();
        printf("\n=== TELA DE LOGIN ===\n");
        lerTexto("Usuario: ", usuario, 40);
        lerTexto("Senha: ", senha, 40);
        if (textosIguais(usuario, usuarioCadastrado) && textosIguais(senha, senhaCadastrada)) {
            loginValido = 1;
            printf("[SUCESSO] Login realizado.\n");
        } else {
            printf("[ERRO] Usuario ou senha incorretos.\n");
        }
        aguardarEnter();
    }
}

int buscarIndice(int codigo) {
    int i;
    for (i = 0; i < totalCadastrado; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void exibirAcao(int i) {
    printf("----------------------------------------\n");
    printf("Codigo: %d\nEscola: %s\n", acoes[i].codigo, acoes[i].escola);
    printf("Tema: %s\nData prevista: %s\n", acoes[i].tema, acoes[i].dataPrevista);
    printf("Publico-alvo: %s\nResponsavel: %s\n", acoes[i].publicoAlvo, acoes[i].responsavel);
    printf("Participantes previstos: %d\n", acoes[i].quantidadePrevista);
    printf("Participantes efetivos: %d\n", acoes[i].quantidadeEfetiva);
    if (acoes[i].situacao == 1) {
        printf("Situacao: Planejada\n");
    } else if (acoes[i].situacao == 2) {
        printf("Situacao: Realizada\n");
    } else {
        printf("Situacao: Cancelada\n");
    }
}

int cadastrarAcao(void) {
    int codigo, i;
    if (totalCadastrado == 100) {
        printf("[ERRO] Limite de 100 acoes atingido.\n");
        return 1;
    }
    printf("\n=== CADASTRAR ACAO ===\n");
    codigo = lerInteiro("\n(0) para voltar\n\nCodigo (1 a 999999): ", 0, 999999);
    while (buscarIndice(codigo) != -1) {
        printf("[ERRO] Codigo ja cadastrado. Informe outro codigo.\n");
        codigo = lerInteiro("\n(0) para voltar\n\nCodigo (1 a 999999): ", 0, 999999);
    }
    if (codigo == 0) return 0;
    i = totalCadastrado;
    acoes[i].codigo = codigo;
    lerTexto("Escola: ", acoes[i].escola, 101);
    lerTexto("Tema: ", acoes[i].tema, 101);
    lerTexto("Data prevista (DD/MM/AAAA): ", acoes[i].dataPrevista, 11);
    while (dataValida(acoes[i].dataPrevista) == 0) {
        printf("[ERRO] Data invalida.\n");
        lerTexto("Data prevista (DD/MM/AAAA): ", acoes[i].dataPrevista, 11);
    }
    lerTexto("Publico-alvo coletivo: ", acoes[i].publicoAlvo, 101);
    lerTexto("Responsavel ficticio: ", acoes[i].responsavel, 101);
    acoes[i].quantidadePrevista = lerInteiro("Participantes previstos (1 a 999999): ", 1, 999999);
    acoes[i].quantidadeEfetiva = 0;
    acoes[i].situacao = 1;
    totalCadastrado++;
    printf("[SUCESSO] Acao cadastrada.\n");
    exibirAcao(i);
    return 1;
}

void listarAcoes(void) {
    int i;
    printf("\n=== LISTAR ACOES ===\n");
    if (totalCadastrado == 0) {
        printf("[AVISO] Nenhuma acao cadastrada.\n");
    }
    for (i = 0; i < totalCadastrado; i++) {
        exibirAcao(i);
    }
    printf("Total listado: %d\n", totalCadastrado);
}

int contemTexto(char texto[], char termo[]) {
    int i, j;
    for (i = 0; texto[i] != '\0'; i++) {
        j = 0;
        while (termo[j] != '\0' && texto[i + j] == termo[j]) {
            j++;
        }
        if (termo[j] == '\0') {
            return 1;
        }
    }
    return 0;
}

int pesquisarAcao(void) {
    int criterio, codigo = 0, i, encontrados = 0;
    char termo[101] = "";
    printf("\n=== PESQUISAR ACAO ===\n");
    if (totalCadastrado == 0) {
        printf("[AVISO] Nenhuma acao cadastrada.\n");
        return 1;
    }
    printf("1. Codigo\n2. Escola\n3. Tema\n\n(0) para voltar\n\n");
    criterio = lerInteiro("Criterio: ", 0, 3);
    if (criterio == 0) return 0;
    if (criterio == 1) {
        codigo = lerInteiro("\n(0) para voltar\n\nCodigo: ", 0, 999999);
        if (codigo == 0) return 0;
    } else {
        lerTexto("\n(0) para voltar\n\nNome ou trecho (mesmas maiusculas/minusculas): ", termo, 101);
        if (textosIguais(termo, "0")) return 0;
    }
    for (i = 0; i < totalCadastrado; i++) {
        if ((criterio == 1 && acoes[i].codigo == codigo) ||
            (criterio == 2 && contemTexto(acoes[i].escola, termo)) ||
            (criterio == 3 && contemTexto(acoes[i].tema, termo))) {
            exibirAcao(i);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("[AVISO] Nenhuma acao encontrada.\n");
    }
    printf("Resultados: %d\n", encontrados);
    return 1;
}

int atualizarSituacao(void) {
    int codigo, indice, situacao, efetivos = 0, confirmar;
    printf("\n=== ATUALIZAR SITUACAO ===\n");
    if (totalCadastrado == 0) {
        printf("[AVISO] Nenhuma acao cadastrada.\n");
        return 1;
    }
    codigo = lerInteiro("\n(0) para voltar\n\nCodigo: ", 0, 999999);
    if (codigo == 0) return 0;
    indice = buscarIndice(codigo);
    if (indice == -1) {
        printf("[ERRO] Codigo nao encontrado.\n");
        return 1;
    }
    exibirAcao(indice);
    printf("1. Planejada\n2. Realizada\n3. Cancelada\n\n(0) para voltar\n\n");
    situacao = lerInteiro("Nova situacao: ", 0, 3);
    if (situacao == 0) return 0;
    if (situacao == 2) {
        efetivos = lerInteiro("Participantes efetivos (0 a 999999): ", 0, 999999);
    }
    confirmar = lerInteiro("Confirmar alteracao? (1 = sim, 0 = nao): ", 0, 1);
    if (confirmar == 0) {
        printf("[AVISO] Alteracao descartada. Registro preservado.\n");
        return 1;
    }
    acoes[indice].situacao = situacao;
    acoes[indice].quantidadeEfetiva = efetivos;
    printf("[SUCESSO] Situacao atualizada.\n");
    exibirAcao(indice);
    return 1;
}

void gerarResumo(void) {
    int i, planejadas = 0, realizadas = 0, canceladas = 0;
    int previstos = 0, efetivos = 0;
    double percentual;
    for (i = 0; i < totalCadastrado; i++) {
        previstos = previstos + acoes[i].quantidadePrevista;
        if (acoes[i].situacao == 1) {
            planejadas++;
        } else if (acoes[i].situacao == 2) {
            realizadas++;
            efetivos = efetivos + acoes[i].quantidadeEfetiva;
        } else {
            canceladas++;
        }
    }
    printf("\n=== RESUMO GERAL ===\n");
    printf("Total de acoes: %d\n", totalCadastrado);
    printf("Planejadas: %d\nRealizadas: %d\nCanceladas: %d\n", planejadas, realizadas, canceladas);
    printf("Participantes previstos (todas as acoes): %d\n", previstos);
    printf("Participantes efetivos (acoes realizadas): %d\n", efetivos);
    if (previstos > 0) {
        percentual = 100.0 * efetivos / previstos;
        printf("Participacao em relacao ao total previsto: %.2f%%\n", percentual);
    } else {
        printf("Participacao em relacao ao total previsto: nao se aplica (sem previsao).\n");
    }
    printf("Os totais representam participacoes, nao pessoas unicas.\n");
}

int main(void) {
    int opcao, mostrarPausa;
    char usuarioCadastrado[40], senhaCadastrada[40];
    limparTela();
    printf("PSE EM ACAO - Projeto academico\n");
    printf("Use somente dados ficticios e coletivos. Nao informe dados de estudantes.\n");
    printf("Ao encerrar, o usuario, a senha e os registros serao perdidos.\n");
    cadastrarUsuario(usuarioCadastrado, senhaCadastrada);
    aguardarEnter();
    realizarLogin(usuarioCadastrado, senhaCadastrada);
    do {
        limparTela();
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cadastrar acao\n2. Listar acoes\n3. Pesquisar acao\n");
        printf("4. Atualizar situacao\n5. Gerar resumo geral\n6. Sair\n");
        opcao = lerInteiro("Escolha uma opcao: ", 1, 6);
        limparTela();
        mostrarPausa = 1;
        switch (opcao) {
            case 1: mostrarPausa = cadastrarAcao(); break;
            case 2: listarAcoes(); break;
            case 3: mostrarPausa = pesquisarAcao(); break;
            case 4: mostrarPausa = atualizarSituacao(); break;
            case 5: gerarResumo(); break;
            case 6: printf("Sistema encerrado. Dados em memoria descartados.\n"); break;
        }
        if (opcao != 6 && mostrarPausa == 1) {
            printf("\n(0) para voltar\n");
            aguardarEnter();
        }
    } while (opcao != 6);
    return 0;
}
