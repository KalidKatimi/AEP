# Testes da versão revisada

Revisão em 9 de novembro de 2026, no Windows, com GCC TDM64 4.9.2 do Dev-C++. O arquivo main.c foi compilado com -std=c99 -Wall -Wextra -Wpedantic -Werror, sem erros ou avisos.

Foram executados 32 cenários contra o executável da versão atual, que inclui criação de usuário, limpeza de tela, pausas, a correção de precisão do percentual e a opção 0 para voltar ao menu. Os testes forneceram entradas, verificaram os resultados esperados e o encerramento normal. Estes registros descrevem a verificação local e não presumem testes realizados pelos integrantes.

| Cenário executado | Resultado |
|---|---|
| 01 Login criado e credenciais incorretas | Aprovado |
| 02 Campos da conta obrigatorios e limites | Aprovado |
| 03 Credenciais de 39 caracteres | Aprovado |
| 04 Menu invalido e base vazia | Aprovado |
| 05 Cadastro e listagem completos | Aprovado |
| 06 Duplicidade e textos invalidos | Aprovado |
| 07 Datas invalidas e ano bissexto | Aprovado |
| 08 Pesquisas por tres criterios e multiplos resultados | Aprovado |
| 09 Atualizacao de registro inexistente | Aprovado |
| 10 Situacao e efetivo invalidos com percentual comum | Aprovado |
| 11 Cancelar e retirar participantes efetivos | Aprovado |
| 12 Replanejar e zerar efetivo | Aprovado |
| 13 Recusar confirmacao preserva registro | Aprovado |
| 14 Zero efetivo e substituicao acima da previsao | Aprovado |
| 15 Capacidade e maior soma permitida | Aprovado |
| 16 Codigo e quantidade acima do limite | Aprovado |
| 17 Fim de entrada durante cadastro | Aprovado |
| 18 Fim de entrada durante pausa de cadastro da conta | Aprovado |
| 19 Nova conta e reinicio sem dados | Aprovado |
| 20 Resumo das tres situacoes | Aprovado |
| 21 Busca diferencia maiusculas | Aprovado |
| 22 Texto de 100 caracteres e espacos nas bordas | Aprovado |
| 23 Saida sem quebra de linha final | Aprovado |
| 24 Precisao do percentual em extremo permitido | Aprovado |
| 25 Voltar do cadastro sem criar registro | Aprovado |
| 26 Voltar depois de codigo duplicado | Aprovado |
| 27 Voltar da escolha de pesquisa | Aprovado |
| 28 Voltar dos tres filtros de pesquisa | Aprovado |
| 29 Voltar da atualizacao por codigo | Aprovado |
| 30 Voltar da situacao preserva acao realizada | Aprovado |
| 31 Zero participantes continua valido | Aprovado |
| 32 Voltar dos resultados com zero | Aprovado |

Resultado: 32 de 32 cenários aprovados nesta revisão. Essa contagem corresponde à bateria atual; as contagens mencionadas anteriormente na conversa se referiam a outras versões e conjuntos de testes. Os cenários 25 a 32 verificam os caminhos de retorno ao menu, a preservação dos registros e o uso de zero como quantidade efetiva válida.

O caso de precisão utiliza previsão de 3 e quantidade efetiva de 999998. A versão anterior mostrava 33333266.00%, devido à precisão limitada de float. A versão corrigida usa double e exibe 33333266.67%, conforme o cálculo esperado. Casos comuns, como 30 de 40 participantes, continuam produzindo 75.00%.

O teste de capacidade cadastrou 100 ações, rejeitou o cadastro seguinte e verificou a soma máxima de 99999900 participantes previstos. Também foram conferidos os campos completos da listagem, os três critérios de busca, a ausência de registros, códigos repetidos, todas as situações, desistência da atualização e quantidade efetiva zero ou acima da previsão.

O arquivo demonstracao.txt contém a saída real do cenário de resumo com três situações: uma ação planejada, uma realizada e uma cancelada, com 30 participantes efetivos para 100 previstos, resultando em 30.00%. É uma transcrição automatizada, não uma captura de tela.

Os testes não demonstram ausência absoluta de defeitos. Não foi verificado o ambiente do professor, ainda não informado, nem houve uso em uma escola real. A limpeza de tela usa cls e foi preparada para Windows. O grupo ainda precisa executar a versão atual, conferir visualmente as telas e registrar as capturas para o relatório.

## Roteiro para o grupo testar no Dev-C++



Sempre que aparecer “Pressione Enter para continuar”, leia o resultado e pressione Enter para seguir. Capture as telas antes de pressionar Enter.

1. Compile o arquivo main.c e execute o programa. Crie o usuário fictício equipe e a senha de exemplo saude2026. Na tela de login, digite uma senha incorreta para conferir o erro; depois entre com os dados que acabou de criar.
2. Digite uma opção inexistente e confira a mensagem de erro.
3. Cadastre a ação 101, com escola Escola Aurora, tema Saude bucal, data 10/11/2026, público Turmas do fundamental, responsável Equipe Alfa e previsão 40.
4. Liste as ações e confira todos os campos.
5. Tente cadastrar novamente o código 101. Quando o sistema rejeitar, informe 102 e complete uma segunda ação, com previsão 20.
6. Pesquise o código 101 e depois o trecho Aurora pelo critério Escola.
7. Atualize a ação 101 para Realizada, tente uma quantidade negativa e depois informe 30. Confirme a alteração.
8. Gere o resumo. Com a segunda ação ainda Planejada, haverá 60 previstos e 30 efetivos: o percentual será 50%.
9. Atualize a ação 101 para Cancelada. Confira que o resumo passa a apresentar zero participantes efetivos.
10. Encerre e execute novamente. Crie outro usuário e outra senha. Confira que os dados da conta anterior não liberam o login e que, ao entrar com a nova conta, não há ações cadastradas.

Registrem os resultados observados e capturem as telas dessa execução para o relatório. Os testes locais não substituem a verificação no ambiente do professor, que ainda não foi informado.
