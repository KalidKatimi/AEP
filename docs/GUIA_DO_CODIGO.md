# Guia de estudo do programa

O programa mantém o raciocínio do Portugol: entrar no sistema, mostrar o menu, executar uma operação e voltar ao menu até a escolha de sair. Nesta versão, antes do login, o usuário cria uma conta temporária. Para estudar, comece pela função main, no final do arquivo. Depois leia cadastrarUsuario, realizarLogin, cadastrarAcao, listarAcoes, pesquisarAcao, atualizarSituacao e gerarResumo. Por último, confira as funções auxiliares de entrada e validação.

## As duas bibliotecas

stdio.h fornece printf, usado para mostrar mensagens, e getchar, usado para ler um caractere do teclado. Também define EOF, que representa o fim da entrada. A função fflush(stdout) garante que a mensagem da pausa seja exibida antes de esperar pelo Enter.

stdlib.h fornece atoi, que converte um texto numérico em inteiro, e exit, usado para encerrar quando a entrada termina. A conversão com atoi acontece somente depois da verificação dos algarismos e do tamanho do número. math.h não é necessária: multiplicação e divisão já fazem parte da linguagem C.

## Struct como ficha de cadastro

Uma struct reúne dados diferentes que pertencem à mesma coisa. Neste projeto, uma ação tem código, escola, tema, data e outros campos. Em vez de guardar essas informações em vetores separados, a struct descreve o formato de uma ficha.

Este exemplo reduzido mostra a ideia; o arquivo main.c contém os demais campos:

```c
struct Acao {
    int codigo;
    char escola[101];
    int quantidadePrevista;
};
```

A definição acima descreve quais campos uma ficha terá. A declaração seguinte reserva um vetor com 100 fichas:

```c
struct Acao acoes[100];
```

Os índices começam em zero. Portanto, a primeira ficha é acoes[0], e a última posição disponível é acoes[99]. O ponto seleciona um campo dessa ficha:

```c
acoes[0].codigo = 101;
acoes[0].quantidadePrevista = 40;
```

Leia a primeira linha como “na primeira ação, guarde 101 no campo código”. A segunda guarda 40 no campo de participantes previstos. Para acessar outra ficha, muda-se o índice entre colchetes.

Isso é um vetor de registros. O programa não declara uma matriz com linhas e colunas. Os campos escola, tema e outros textos são vetores de caracteres dentro de cada registro.

## Como o texto é guardado

Em Portugol existe o tipo cadeia. Nesta versão em C, usamos um vetor de char para guardar as letras. Por exemplo, char escola[101] reserva 101 posições: até 100 posições para o texto e uma para '\0', que marca seu fim. Letras acentuadas podem ocupar mais de uma posição dependendo da codificação.

Não confunda '\0' com o algarismo '0'. O primeiro marca o final do texto, enquanto o segundo é um caractere que pode aparecer em um número digitado. '\n' representa uma quebra de linha, e '\t' representa uma tabulação.

A função tamanhoTexto percorre esse vetor até encontrar '\0'. A função textosIguais compara duas sequências de caracteres, uma posição por vez. Ela é usada no login, porque em C não se comparam os conteúdos de dois vetores de texto usando apenas ==.

## Contador e cadastro

totalCadastrado começa em zero. Ele indica quantas ações foram concluídas no cadastro e qual é a próxima posição livre. Se houver três ações, os índices ocupados serão 0, 1 e 2; o próximo cadastro usará o índice 3.

```c
i = totalCadastrado;
acoes[i].codigo = codigo;
/* Os outros campos sao preenchidos e validados. */
totalCadastrado++;
```

O operador ++ acrescenta um. O contador só aumenta depois do preenchimento válido de todos os campos. A função verifica o limite de 100 antes de escrever na próxima posição.

O vetor e o contador foram declarados fora das funções, como no Portugol recebido. São variáveis globais, acessíveis pelas funções do programa.

## Criação de usuário e login

Na função main, os vetores usuarioCadastrado e senhaCadastrada têm 40 posições cada: até 39 para o texto e uma para '\0'. A função cadastrarUsuario recebe esses vetores e usa lerTexto para preenchê-los. Assim, usuário e senha vazios ou longos demais são rejeitados pelas mesmas regras de leitura já utilizadas no programa.

Depois, realizarLogin recebe os dois vetores cadastrados. Dentro dela, usuario e senha guardam uma tentativa de acesso. A função textosIguais compara a tentativa com os dados escolhidos no cadastro:

```c
if (textosIguais(usuario, usuarioCadastrado) && textosIguais(senha, senhaCadastrada)) {
    loginValido = 1;
}
```

O operador && exige que as duas comparações sejam verdadeiras. Se uma estiver incorreta, o programa informa o erro e repete o login. Não há usuário ou senha fixos no código. Os vetores existem somente durante a execução; quando o programa fecha, seus conteúdos são descartados. Ao abrir novamente, a função main começa criando outra conta.

## Situação da ação

A situação usa um inteiro: 1 significa Planejada, 2 significa Realizada e 3 significa Cancelada. A função exibirAcao transforma esses valores nas palavras mostradas na tela.

Uma ação nova começa como Planejada e com zero participantes efetivos. Na atualização, a quantidade efetiva só é solicitada quando a nova situação é Realizada. Nas outras situações, o valor fica zero. A alteração só é aplicada quando o usuário confirma.

## Funções e retornos

Uma função separa uma tarefa do restante do programa. Por exemplo, listarAcoes percorre os registros e chama exibirAcao para mostrar cada um.

Em void listarAcoes(void), o primeiro void indica que a função não devolve um valor. O void entre parênteses indica que ela não recebe argumentos. Já int buscarIndice(int codigo) recebe um código e devolve um inteiro: a posição encontrada ou -1 se o código não existir.

Nas verificações como dataValida e textosIguais, 1 significa verdadeiro e 0 significa falso. return entrega o resultado e sai da função. Em uma função void, return sozinho apenas encerra aquela função.

## Leitura e validação

lerTexto recebe a mensagem, o vetor que será preenchido e sua capacidade. A notação char texto[] no parâmetro permite que a função trabalhe com o vetor recebido. O programa usa essa forma sem precisar de operações explícitas com ponteiros.

getchar lê um caractere de cada vez. O laço repete a leitura até a tecla Enter, representada por '\n', ou até EOF. A variável que recebe getchar é int porque precisa representar tanto os caracteres quanto EOF. O programa reserva espaço para '\0', rejeita linhas longas e pede novamente quando o campo está vazio ou contém somente espaços.

lerInteiro primeiro recebe o que foi digitado como texto. Verifica se existem apenas algarismos entre '0' e '9' e se foram digitados no máximo seis. Só então usa atoi para obter o inteiro e conferir o intervalo permitido. Isso evita que uma entrada como “abc” ou “12.5” seja tratada como um número válido.

while (1) mantém a tentativa de leitura em repetição. Quando o valor está correto, return encerra a função e o programa segue para o próximo passo.

## Pesquisa e datas

buscarIndice percorre as ações usando for e compara o código de cada uma. contemTexto procura um trecho dentro de escola ou tema, comparando os caracteres com dois contadores. A comparação exige a mesma grafia, inclusive maiúsculas e minúsculas.

dataValida verifica o formato DD/MM/AAAA, separa dia, mês e ano e confere os limites. A expressão data[0] - '0' transforma um caractere numérico no valor correspondente. Para montar um dia com dois algarismos, o primeiro é multiplicado por dez e somado ao segundo. O vetor simples diasDoMes guarda os 12 limites mensais. O operador % calcula o resto da divisão e permite ajustar fevereiro para 29 dias nos anos bissextos.

Na pesquisa, um único laço percorre as ações. As condições verificam o critério escolhido: código, escola ou tema. Assim, a mesma parte do código exibe e conta os resultados dos três tipos de busca.

## Escolha no menu

O switch (opcao) seleciona a operação. Cada case representa uma opção, chama sua função e usa break para encerrar aquela escolha. Ele substitui a sequência de if e else do menu. O do while continua responsável por repetir o menu até a opção 6.

As funções cadastrarAcao, pesquisarAcao e atualizarSituacao agora devolvem um inteiro. O retorno 0 indica que o usuário escolheu voltar; o retorno 1 indica que há um resultado ou aviso para ler. A variável mostrarPausa recebe esse valor. Assim, o menu volta imediatamente ao escolher 0, mas espera Enter depois de apresentar resultados. Os locais que aceitam 0 para voltar estão indicados nas mensagens. Na quantidade efetiva de participantes, 0 continua sendo um valor válido e não cancela a operação.

## Cálculo do resumo

gerarResumo percorre o vetor, conta cada situação e soma as quantidades. A previsão inclui todas as ações cadastradas. O efetivo inclui somente ações realizadas.

```c
percentual = 100.0 * efetivos / previstos;
```

O uso de 100.0 permite calcular com casas decimais. A variável percentual é double, um tipo decimal com mais precisão que float. Isso evita perder casas decimais quando a quantidade efetiva supera muito a previsão. A impressão com %.2f mostra duas casas decimais, enquanto %% mostra o símbolo de porcentagem. Antes de dividir, o programa verifica se previstos é maior que zero.

## Limpeza de tela e pausa

limparTela chama system("cls"), da biblioteca stdlib.h, para limpar o terminal do Windows. Ela é chamada antes das telas de login, menu e operações. aguardarEnter usa getchar para esperar que o usuário pressione Enter. Essa pausa ocorre antes de apagar resultados e mensagens, dando tempo para ler ou capturar a tela. Os avisos de preenchimento inválido continuam visíveis enquanto o usuário corrige o campo.

## Relação com o Portugol

| Portugol | C usado no projeto |
|---|---|
| escreva | printf |
| inteiro | int |
| cadeia | vetor de char |
| se e senao | if e else |
| enquanto | while |
| faca enquanto | do while |
| para | for |
| verdadeiro e falso | 1 e 0 nas verificações |
| e e ou | && e \|\| |

## Exercício para explicar ao professor

Cadastre uma ação com previsão de 40 participantes. Mostre que ela ocupa uma posição do vetor, começa como Planejada e tem quantidade efetiva zero. Depois atualize para Realizada com 30 participantes e gere o resumo. Explique que 30 dividido por 40, multiplicado por 100, resulta em 75%.

Para estudar a struct, localize no código onde cada campo é preenchido e onde é exibido. Para estudar a repetição, acompanhe o menu voltando após uma operação. Para estudar as condições, provoque um código duplicado e uma entrada negativa e observe qual mensagem aparece. Essas verificações ajudam o grupo a apresentar o funcionamento com suas próprias palavras.
