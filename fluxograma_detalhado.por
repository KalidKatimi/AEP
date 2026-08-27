programa
{
	// Limite máximo de ações
	const inteiro MAX_ACOES = 100

	// Vetores globais (Banco de Dados em Memória)
	inteiro codigos[MAX_ACOES]
	cadeia escolas[MAX_ACOES]
	cadeia temas[MAX_ACOES]
	cadeia datasPrevistas[MAX_ACOES]
	cadeia publicosAlvo[MAX_ACOES]
	cadeia responsaveis[MAX_ACOES]
	inteiro qtdsPrevistas[MAX_ACOES]
	inteiro qtdsEfetivas[MAX_ACOES]
	cadeia situacoes[MAX_ACOES]

	inteiro totalCadastrado = 0

	// ==========================================
	// 1. FLUXOGRAMA GERAL DO SISTEMA (MENU)
	// ==========================================
	funcao inicio()
	{
		logico loginValido = falso
		inteiro opcao = 0

		// Tela de Login / Autenticação
		enquanto (nao loginValido)
		{
			cadeia usuario, senha

			escreva("=== TELA DE LOGIN ===\n")
			escreva("Usuário: ")
			leia(usuario)
			escreva("Senha: ")
			leia(senha)

			se (usuario == "admin" e senha == "1234")
			{
				loginValido = verdadeiro
				escreva("\n[SUCESSO] Login realizado com sucesso!\n")
			}
			senao
			{
				escreva("\n[ERRO] Usuário ou senha incorretos! Tente novamente.\n\n")
			}
		}

		// Menu Principal
		faca
		{
			escreva("\n===============================\n")
			escreva("       MENU PRINCIPAL          \n")
			escreva("===============================\n")
			escreva("1. Cadastro de Ações\n")
			escreva("2. Pesquisar Ação\n")
			escreva("3. Atualizar Situação\n")
			escreva("4. Gerar Resumo Geral\n")
			escreva("5. Sair\n")
			escreva("Escolha uma opção (1-5): ")
			leia(opcao)

			se (opcao == 1)
			{
				cadastrarAcao()
			}
			senao se (opcao == 2)
			{
				pesquisarAcao()
			}
			senao se (opcao == 3)
			{
				atualizarSituacao()
			}
			senao se (opcao == 4)
			{
				gerarResumo()
			}
			senao se (opcao == 5)
			{
				escreva("\nEncerrando o sistema e efetuando logout...\n")
			}
			senao
			{
				escreva("\n[ERRO] Opção inválida! Escolha de 1 a 5.\n")
			}

		} enquanto (opcao != 5)

		escreva("\n=== FIM DO PROGRAMA ===\n")
	}

	// ==========================================
	// 2. OPERAÇÃO 1: CADASTRO DE AÇÕES
	// ==========================================
	funcao cadastrarAcao()
	{
		se (totalCadastrado >= MAX_ACOES)
		{
			escreva("\n[ERRO] Limite máximo de cadastros atingido!\n")
			escreva("Retornando ao Menu Principal...\n")
			retorne
		}

		inteiro tempCodigo = 0
		cadeia tempEscola = ""
		cadeia tempTema = ""
		cadeia tempData = ""
		cadeia tempPublico = ""
		cadeia tempResponsavel = ""
		inteiro tempQtdPrev = 0

		logico dadosValidos = falso

		enquanto (nao dadosValidos)
		{
			escreva("\n--- FORMULÁRIO DE CADASTRO DE AÇÕES ---\n")
			escreva("Código da ação (inteiro maior que 0): ")
			leia(tempCodigo)
			escreva("Escola: ")
			leia(tempEscola)
			escreva("Tema: ")
			leia(tempTema)
			escreva("Data Prevista: ")
			leia(tempData)
			escreva("Público-alvo: ")
			leia(tempPublico)
			escreva("Responsável: ")
			leia(tempResponsavel)
			escreva("Quantidade Prevista: ")
			leia(tempQtdPrev)

			logico duplicado = falso
			se (totalCadastrado > 0)
			{
				para (inteiro i = 0; i < totalCadastrado; i++)
				{
					se (codigos[i] == tempCodigo)
					{
						duplicado = verdadeiro
					}
				}
			}

			se (tempCodigo > 0 e nao duplicado e tempQtdPrev > 0)
			{
				dadosValidos = verdadeiro
			}
			senao
			{
				escreva("\n[ERRO] Código inválido, código repetido ou quantidade menor/igual a zero! Preencha o formulário novamente.\n")
			}
		}

		codigos[totalCadastrado] = tempCodigo
		escolas[totalCadastrado] = tempEscola
		temas[totalCadastrado] = tempTema
		datasPrevistas[totalCadastrado] = tempData
		publicosAlvo[totalCadastrado] = tempPublico
		responsaveis[totalCadastrado] = tempResponsavel
		qtdsPrevistas[totalCadastrado] = tempQtdPrev
		qtdsEfetivas[totalCadastrado] = 0
		situacoes[totalCadastrado] = "Planejada"

		totalCadastrado = totalCadastrado + 1

		escreva("\n[SUCESSO] Ação cadastrada com sucesso!\n")
		escreva("-----------------------------------\n")
		escreva("Código: ", tempCodigo, "\n")
		escreva("Escola: ", tempEscola, "\n")
		escreva("Tema: ", tempTema, "\n")
		escreva("Data Prevista: ", tempData, "\n")
		escreva("Público: ", tempPublico, "\n")
		escreva("Responsável: ", tempResponsavel, "\n")
		escreva("Qtd Prevista: ", tempQtdPrev, "\n")
		escreva("Situação Inicial: Planejada\n")
		escreva("-----------------------------------\n")

		escreva("\nRetornando ao Menu Principal...\n")
	}

	// ==========================================
	// 3. OPERAÇÃO 2: PESQUISAR AÇÃO
	// ==========================================
	funcao pesquisarAcao()
	{
		escreva("\n--- PESQUISA DE AÇÃO ---\n")

		se (totalCadastrado == 0)
		{
			escreva("[AVISO] Nenhuma ação foi cadastrada ainda.\n")
			escreva("Retornando ao Menu Principal...\n")
			retorne
		}

		inteiro codigoBusca = 0
		logico encontrado = falso

		escreva("Digite o código da ação que deseja pesquisar: ")
		leia(codigoBusca)

		para (inteiro i = 0; i < totalCadastrado; i++)
		{
			se (codigos[i] == codigoBusca)
			{
				encontrado = verdadeiro
				escreva("\n[SUCESSO] Ação Encontrada!\n")
				escreva("-----------------------------------\n")
				escreva("Código: ", codigos[i], "\n")
				escreva("Escola: ", escolas[i], "\n")
				escreva("Tema: ", temas[i], "\n")
				escreva("Data Prevista: ", datasPrevistas[i], "\n")
				escreva("Público: ", publicosAlvo[i], "\n")
				escreva("Responsável: ", responsaveis[i], "\n")
				escreva("Qtd Prevista: ", qtdsPrevistas[i], "\n")
				escreva("Qtd Efetiva: ", qtdsEfetivas[i], "\n")
				escreva("Situação: ", situacoes[i], "\n")
				escreva("-----------------------------------\n")
			}
		}

		se (nao encontrado)
		{
			escreva("\n[ERRO] Nenhuma ação encontrada com o código ", codigoBusca, ".\n")
		}

		escreva("\nRetornando ao Menu Principal...\n")
	}

	// ==========================================
	// 4. OPERAÇÃO 3: ATUALIZAR SITUAÇÃO
	// ==========================================
	funcao atualizarSituacao()
	{
		escreva("\n--- ATUALIZAR SITUAÇÃO DA AÇÃO ---\n")

		se (totalCadastrado == 0)
		{
			escreva("[AVISO] Nenhuma ação cadastrada para atualizar.\n")
			escreva("Retornando ao Menu Principal...\n")
			retorne
		}

		inteiro codigoBusca = 0
		logico encontrado = falso

		escreva("Digite o código da ação para atualizar a situação: ")
		leia(codigoBusca)

		para (inteiro i = 0; i < totalCadastrado; i++)
		{
			se (codigos[i] == codigoBusca)
			{
				encontrado = verdadeiro
				inteiro escolhaSit = 0

				escreva("\nAção encontrada: ", escolas[i], " - ", temas[i], "\n")
				escreva("Situação Atual: ", situacoes[i], "\n")
				escreva("Escolha a nova situação:\n")
				escreva("1. Realizada\n")
				escreva("2. Cancelada\n")
				escreva("Opção: ")
				leia(escolhaSit)

				se (escolhaSit == 1)
				{
					situacoes[i] = "Realizada"
					escreva("Informe a quantidade efetiva de público atendido: ")
					leia(qtdsEfetivas[i])
					escreva("\n[SUCESSO] Situação alterada para REALIZADA!\n")
				}
				senao se (escolhaSit == 2)
				{
					situacoes[i] = "Cancelada"
					escreva("\n[SUCESSO] Situação alterada para CANCELADA!\n")
				}
				senao
				{
					escreva("\n[ERRO] Opção inválida. A situação não foi alterada.\n")
				}
			}
		}

		se (nao encontrado)
		{
			escreva("\n[ERRO] Código não encontrado no sistema.\n")
		}

		escreva("\nRetornando ao Menu Principal...\n")
	}

	// ==========================================
	// 5. OPERAÇÃO 4: GERAR RESUMO GERAL
	// ==========================================
	funcao gerarResumo()
	{
		escreva("\n--- RESUMO GERAL DE AÇÕES ---\n")

		se (totalCadastrado == 0)
		{
			escreva("[AVISO] Não há registros no banco de dados para gerar resumo.\n")
			escreva("Retornando ao Menu Principal...\n")
			retorne
		}

		inteiro qtdPlanejadas = 0
		inteiro qtdRealizadas = 0
		inteiro qtdCanceladas = 0
		inteiro totalAtendidos = 0

		para (inteiro i = 0; i < totalCadastrado; i++)
		{
			se (situacoes[i] == "Planejada")
			{
				qtdPlanejadas = qtdPlanejadas + 1
			}
			senao se (situacoes[i] == "Realizada")
			{
				qtdRealizadas = qtdRealizadas + 1
				totalAtendidos = totalAtendidos + qtdsEfetivas[i]
			}
			senao se (situacoes[i] == "Cancelada")
			{
				qtdCanceladas = qtdCanceladas + 1
			}
		}

		escreva("Total de ações registradas: ", totalCadastrado, "\n")
		escreva("Ações Planejadas: ", qtdPlanejadas, "\n")
		escreva("Ações Realizadas: ", qtdRealizadas, "\n")
		escreva("Ações Canceladas: ", qtdCanceladas, "\n")
		escreva("Total de público efetivamente atendido: ", totalAtendidos, "\n")
		escreva("-----------------------------------\n")

		escreva("\nRetornando ao Menu Principal...\n")
	}
}
