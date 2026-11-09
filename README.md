# PSE em Ação

Programa acadêmico em C para cadastrar e acompanhar ações coletivas do Programa Saúde na Escola. Esta versão usa somente `stdio.h` e `stdlib.h`, com funções, condições, repetições, vetores e uma `struct` simples. Não utiliza matrizes.

## Integrantes

- João Pedro Peres Portela Garcia — RA 26006727-2
- Kalid Katimi Abdallah — RA 26013520-2
- Kauã Marcelino Soares — RA 26006082-2

UNICESUMAR — AEP, segundo semestre de 2026.

## Por onde começar

Abra `src/main.c` no Dev-C++ para estudar e compilar o código. Leia `docs/GUIA_DO_CODIGO.md` para entender a struct e as funções. O arquivo `pse.exe` executa o programa no Windows.

Há somente um programa em C. Os dois algoritmos em Portugol foram reunidos em um arquivo, com as operações separadas em funções. A versão atual tem 370 linhas, incluindo comentários e espaços, com a opção de voltar ao menu.

## Compilar e executar

No Dev-C++, abra `src/main.c` e escolha a opção de compilar e executar. Mantenha a extensão `.c`.

Também é possível compilar pelo terminal, a partir da pasta do projeto:

```sh
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror src/main.c -o pse.exe
```

No PowerShell, execute:

```powershell
.\pse.exe
```

Caso o GCC não esteja disponível pelo nome, este é o caminho verificado no computador usado para os testes:

```powershell
& 'C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\gcc.exe' -std=c99 -Wall -Wextra -Wpedantic -Werror src/main.c -o pse.exe
.\pse.exe
```

A compilação foi verificada no Windows com GCC TDM64 4.9.2 do Dev-C++. O ambiente específico exigido pelo professor ainda deve ser confirmado. O programa não precisa de outras bibliotecas ou instalações para executar no ambiente testado.

## Login e menu

Ao abrir o programa, a tela **Criar usuário** solicita um nome de usuário e uma senha. Em seguida, a tela de login pede esses mesmos dados para liberar o menu. Não existe uma conta padrão: você escolhe os dados em cada execução.

É possível criar uma conta por execução. Usuário e senha são obrigatórios e aceitam até 39 posições de texto cada. A comparação diferencia maiúsculas e minúsculas. Espaços e tabulações no início e no fim são retirados tanto no cadastro quanto no login.

Ao fechar o programa, a conta é descartada junto com as ações. Na próxima execução, será necessário criar uma nova conta. Para a demonstração, use um usuário fictício, como `equipe`, e uma senha de exemplo, como `saude2026`.

| Opção | Operação |
|---|---|
| 1 | Cadastrar ação |
| 2 | Listar todas as ações |
| 3 | Pesquisar por código, escola ou tema |
| 4 | Atualizar situação e participantes efetivos |
| 5 | Gerar resumo geral |
| 6 | Sair |

A sexta funcionalidade exigida pelo enunciado é a validação das entradas, aplicada nas operações. Ela não precisa aparecer como uma opção do menu.

A tela é limpa ao entrar no login, no menu e em cada operação. Depois de criar o usuário, de uma tentativa de login e de cada operação, pressione **Enter** para continuar. Os resultados e avisos permanecem visíveis até essa confirmação. A limpeza usa o comando `cls` do Windows.

**0 para voltar:** no cadastro, digite 0 quando o código da ação for solicitado, inclusive depois de um código duplicado. Na pesquisa, use 0 na escolha do critério ou no código/termo pesquisado. Na atualização, use 0 no código ou na escolha da situação. Nessas telas, o retorno ao menu é imediato e preserva os registros. Após os resultados de uma operação, digite 0 e pressione Enter, ou apenas pressione Enter, para voltar.

A indicação **(0) para voltar** aparece em uma linha separada, com espaço em relação às outras opções ou ao campo de entrada. O zero é um comando de retorno somente onde essa opção é indicada. Na quantidade efetiva, 0 continua significando nenhum participante; na confirmação de alteração, 0 continua significando não confirmar. No menu principal, a opção 6 encerra o programa.

## Exemplo de uso

Crie um usuário e uma senha, faça login com os mesmos dados e selecione a opção 1. Cadastre código `101`, escola `Escola Aurora`, tema `Saude bucal`, data `10/11/2026`, público `Turmas do fundamental`, responsável `Equipe Alfa` e previsão `40`. A ação começa como Planejada, com zero participantes efetivos.

Na opção 2, confira a listagem. Na opção 3, escolha pesquisa por escola e digite `Aurora`. A pesquisa por escola e tema aceita trechos, mas diferencia letras maiúsculas e minúsculas: `AURORA` não encontra `Aurora`.

Na opção 4, informe o código `101`, selecione `2. Realizada`, digite `30` participantes e confirme com `1`. A opção 5 mostrará uma ação realizada e participação de 75%, caso esse seja o único cadastro.

A atualização oferece `1. Planejada`, `2. Realizada` e `3. Cancelada`. Informe `0` na confirmação para desistir sem modificar o registro. Retornar para Planejada ou Cancelada zera a quantidade efetiva. Atualizar novamente para Realizada substitui a quantidade, sem somá-la à anterior.

## Regras

- Até 100 ações por execução.
- Código único, de 1 a 999999.
- Previsão de participantes de 1 a 999999.
- Quantidade efetiva de 0 a 999999, podendo superar a previsão.
- Números digitados com até seis algarismos, sem sinal ou casas decimais.
- Campos de texto obrigatórios, com até 100 posições de armazenamento; em UTF-8, uma letra acentuada pode ocupar mais de uma posição.
- Data existente em DD/MM/AAAA, com verificação de anos bissextos. Datas passadas são permitidas.
- Opções inválidas, registros inexistentes e limite de capacidade produzem mensagens claras.

O limite de seis algarismos é uma decisão desta versão para permitir conversão e soma com inteiros comuns no ambiente de 32 bits ou mais testado. A soma máxima de 100 previsões é 99.999.900.

## Resumo geral

O percentual é calculado assim:

`percentual = 100.0 * participantesEfetivos / participantesPrevistos;`

A previsão inclui todas as ações, inclusive planejadas e canceladas. A quantidade efetiva inclui somente ações realizadas. Se houver três ações previstas para 40, 20 e 40 participantes, com apenas 30 participações efetivas, o resultado será 30%.

Sem previsão cadastrada, o programa informa que o percentual não se aplica. As somas representam participações, e não pessoas únicas, pois o sistema não identifica estudantes individualmente.

## Limitações e cuidados de uso

O usuário, a senha e as ações ficam em memória e são perdidos quando o programa fecha. O login é apenas didático: a senha aparece durante a digitação e é mantida em texto na memória durante a execução. Ele não oferece proteção adequada a um sistema real.

Use somente dados fictícios e coletivos. Os campos de texto não detectam automaticamente informações pessoais. Não cadastre nomes de estudantes, diagnósticos ou prontuários.

As mensagens do terminal não usam acentos para reduzir problemas de exibição em consoles antigos. Não há banco de dados, arquivos de persistência ou interface gráfica.

## Arquivos

```text
src/main.c                Programa único em C
pse.exe                   Executável para Windows
README.md                 Instruções de uso
docs/GUIA_DO_CODIGO.md     Explicação da struct e das funções
docs/IMPLEMENTACAO.md      Relação com os requisitos
docs/TESTES.md             Resultados e roteiro de testes manuais
docs/demonstracao.txt      Saída real de uma execução de teste
.gitignore                Exclusão de arquivos compilados do Git
```

O cálculo do percentual usa double para preservar a precisão em valores elevados. A versão com a opção 0 para voltar compilou sem erros ou avisos e passou por 32 cenários descritos em docs/TESTES.md. O programa e as instruções foram preparados localmente; ainda não foram publicados no GitHub. A documentação acadêmica completa, os casos de uso e o vídeo continuam como próximas etapas.
