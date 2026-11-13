# PSE em Ação

Sistema em C para planejar e acompanhar ações coletivas do Programa Saúde na Escola. Projeto AEP — UniCesumar, segundo semestre de 2026.

## Integrantes

- João Pedro Peres Portela Garcia — RA 26006727-2
- Kalid Katimi Abdallah — RA 26013520-2
- Kauã Marcelino Soares — RA 26006082-2

## Funcionalidades

Cadastro e listagem de ações; pesquisa por código, escola ou tema; atualização da situação e dos participantes efetivos; resumo geral e validação das entradas. O sistema trata códigos duplicados, registros inexistentes e o limite de 100 ações.

## Como executar

1. Clique em **Code > Download ZIP** e descompacte o projeto.
2. No Dev-C++, abra `src/main.c`.
3. Use **Compilar e Executar**.
4. Crie um usuário e uma senha e faça login com os mesmos dados.

Se preferir o terminal com GCC, execute na pasta do projeto:

```sh
gcc -std=c99 -Wall -Wextra -Wpedantic src/main.c -o pse.exe
```

No PowerShell, inicie com:

```powershell
.\pse.exe
```

Use o menu para acessar as operações. A indicação `(0) para voltar` aparece nas telas que permitem retorno. A opção 6 encerra o programa.

## Organização

- [src/main.c](src/main.c): código-fonte em C da segunda entrega.
- [docs](docs): guia do código, implementação, testes e demonstração.
- [primeiro_bimestre](primeiro_bimestre): algoritmos originais em Portugol, preservados como histórico da primeira entrega.

## Observações

O programa utiliza `stdio.h`, `stdlib.h`, funções, vetores e uma `struct` simples. Usuário, senha e ações ficam na memória e são perdidos ao fechar. O login é didático, com senha visível durante a digitação. Utilize dados fictícios e coletivos, sem identificar estudantes.

As ações começam como planejadas. O resumo compara os participantes efetivos das ações realizadas com a previsão de todas as ações cadastradas. A pesquisa por escola e tema diferencia maiúsculas e minúsculas.
