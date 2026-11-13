# Implementação da versão simplificada

Os dois algoritmos em Portugol foram integrados em um único programa em C. O menu foi preservado e o login passou a utilizar os dados escolhidos pelo usuário ao iniciar. A implementação acrescenta listagem de ações, pesquisa por escola e tema, retorno à situação Planejada e cálculo do percentual de participação, completando o escopo mínimo do enunciado.

A versão utiliza apenas stdio.h e stdlib.h. Os dados ficam em um vetor de 100 registros do tipo struct Acao. Cada registro reúne os campos de uma ação. Não há matrizes, enum, typedef, alocação dinâmica ou aritmética de ponteiros. As funções recebem números ou vetores quando necessário, com a sintaxe explicada no guia.

O vetor e o contador são globais, seguindo a organização do Portugol recebido. A função principal controla a criação de usuário, o login e o menu. As operações de cadastro, listagem, pesquisa, atualização e resumo continuam separadas em funções.

A função cadastrarUsuario preenche dois vetores de caracteres declarados na função principal. A função realizarLogin compara as entradas com esses valores. Há uma conta temporária por execução, sem credenciais fixas no código e sem armazenamento em arquivo. A criação de usuário é uma funcionalidade adicional e não substitui nenhum dos seis requisitos mínimos. Os casos de uso e o fluxograma inicial devem representar essa etapa antes do login.

| Requisito | Função principal responsável | Comportamento |
|---|---|---|
| RF01 Cadastrar ação | cadastrarAcao | Recebe os campos obrigatórios e define a situação inicial Planejada |
| RF02 Listar ações | listarAcoes | Mostra todos os registros e o total cadastrado |
| RF03 Pesquisar ação | pesquisarAcao | Pesquisa por código ou trecho da escola ou tema |
| RF04 Atualizar situação | atualizarSituacao | Altera para Planejada, Realizada ou Cancelada e registra participantes efetivos |
| RF05 Gerar resumo | gerarResumo | Conta ações por situação, soma participantes e calcula o percentual geral |
| RF06 Validar entradas | lerTexto, lerInteiro, dataValida e buscarIndice | Impede entradas inválidas, campos vazios e duplicidade; o cadastro verifica a capacidade |

A listagem ocupa a opção 2, seguida por pesquisa na opção 3, atualização na opção 4, resumo na opção 5 e saída na opção 6. Os fluxogramas devem usar essa mesma numeração.

O retorno ao menu principal usa 0 nos pontos indicados: código inicial do cadastro, critério e filtro de pesquisa, código e situação na atualização. As operações retornam sem modificar os registros nesses caminhos. Após exibir resultados, o usuário pode digitar 0 e Enter ou apenas Enter para voltar. O valor zero de participantes efetivos permanece permitido. Os fluxogramas e fluxos alternativos dos casos de uso devem representar esses retornos.

Para simplificar a implementação, os códigos e quantidades aceitam até seis algarismos. O código e a previsão devem ser positivos, e a quantidade efetiva pode ser zero. O limite evita ultrapassar a capacidade dos inteiros usados no ambiente testado. A pesquisa textual distingue maiúsculas e minúsculas e preserva a possibilidade de encontrar vários registros por escola ou tema.

Ao retornar uma ação realizada para Planejada ou Cancelada, a quantidade efetiva é zerada. Ao atualizar novamente uma ação realizada, a nova quantidade substitui a anterior. A confirmação permite desistir sem modificar o registro.

O percentual geral divide os participantes efetivos das ações realizadas pela previsão de todas as ações, incluindo planejadas e canceladas. Essa interpretação está descrita no manual, pois o enunciado não detalha o denominador. A versão simplificada apresenta apenas esse indicador.

A compilação e os testes locais verificam o funcionamento nos cenários documentados. Não houve aplicação em escolas reais nem medição de impacto social. Para concluir a segunda entrega, ainda é necessário atualizar os casos de uso e fluxogramas, acrescentar capturas de tela e conclusões ao relatório, publicar no repositório do grupo e gravar o vídeo.
