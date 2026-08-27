programa
{
	funcao inicio()
	{
		logico loginValido = falso
		inteiro opcao = 0

		// Autenticação (Tela de Login)
		enquanto (nao loginValido)
		{
			cadeia usuario, senha
			escreva("=== TELA DE LOGIN ===\n")
			escreva("Usuário: ") leia(usuario)
			escreva("Senha: ") leia(senha)

			se (usuario == "admin" e senha == "1234")
			{
				loginValido = verdadeiro
			}
			senao
			{
				escreva("\n[ERRO] Usuário ou senha incorretos!\n\n")
			}
		}

		// Loop do Menu Principal (Fluxograma Geral)
		faca
		{
			escreva("\n=== MENU PRINCIPAL ===\n")
			escreva("1. Cadastro de Ações\n")
			escreva("2. Pesquisar Ação\n")
			escreva("3. Atualizar Situação\n")
			escreva("4. Gerar Resumo Geral\n")
			escreva("5. Sair\n")
			escreva("Escolha uma opção: ")
			leia(opcao)

			se (opcao == 1)
			{
				escreva("\nRedirecionando para Operação: Cadastro...\n")
			}
			senao se (opcao == 2)
			{
				escreva("\nRedirecionando para Operação: Pesquisa...\n")
			}
			senao se (opcao == 3)
			{
				escreva("\nRedirecionando para Operação: Atualizar Situação...\n")
			}
			senao se (opcao == 4)
			{
				escreva("\nRedirecionando para Operação: Gerar Resumo...\n")
			}
			senao se (opcao == 5)
			{
				escreva("\nEncerrando o sistema...\n")
			}
			senao
			{
				escreva("\n[ERRO] Opção inválida!\n")
			}

		} enquanto (opcao != 5)
	}
}
