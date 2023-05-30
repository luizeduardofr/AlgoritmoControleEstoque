#include <iostream>
#include <conio.h>
#include <locale.h>
#include <cstring>
using namespace std;

//Trabalho Semestral

struct TipoProduto {
	int idTipo;
	char descTipo[30];
};

struct Produto {
	int idProduto;
	char descProd[30];
	int idTipo;
	int codFornecedor;
	int qtdeEstoque;
	int estoqueMin;
	int estoqueMax;
	float valorUnt;
};

struct Estado {
	int codUF;
	char nomeEstado[25];
};

struct Fornecedor {
	int idFornecedor;
	char nomeFornecedor[40];
	char endereco[30];
	char telefone[15];
	char cidade[20];
	int idUF;
	char cnpj[18];
};

void leituraTipo (struct TipoProduto tipo[], int &contadorTP){
	int i = 0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Tipo Produto " << (i+1) << ": ";
		cin >> tipo[i].idTipo;
		if (tipo[i].idTipo > 0){
			cout << "Descrição: ";
			cin.ignore(); 
			gets(tipo[i].descTipo);
		}
		else saida = 0;
	}
	contadorTP = i - 1;
}

void leituraProduto (struct Produto prod[], int &contadorP){
	int i = 0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Produto " << (i+1) << ": ";
		cin >> prod[i].idProduto;
		if (prod[i].idProduto > 0){
			cout << "Descrição: ";
			cin.ignore(); 
			gets(prod[i].descProd);
			cout << "Código Tipo do Produto: ";
			cin >> prod[i].idTipo;
			cout << "Código do Fornecedor: ";
			cin >> prod[i].codFornecedor;
			cout << "Quantidade do Estoque: ";
			cin >> prod[i].qtdeEstoque;
			cout << "Estoque Mínimo: ";
			cin >> prod[i].estoqueMin;
			cout << "Estoque Máximo: ";
			cin >> prod[i].estoqueMax;
			cout << "Valor Unitário: ";
			cin >> prod[i].valorUnt;
		}
		else saida = 0;
	}
	contadorP = i - 1;
}

void leituraEstado (struct Estado est[], int &contadorE){
	int i = 0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Estado " << (i+1) << ": ";
		cin >> est[i].codUF;
		if (est[i].codUF > 0){
			cout << "Nome do Estado: ";
			cin.ignore();
			gets(est[i].nomeEstado);
		}
		else saida = 0;
	}
	contadorE = i - 1;
}

void leituraFornecedor (struct Fornecedor forn[], int &contadorF){
	int i = 0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Fornecedor " << (i+1) << ": ";
		cin >> forn[i].idFornecedor;
		if (forn[i].idFornecedor > 0){
			cout << "Nome: ";
			cin.ignore();
			cin.getline(forn[i].nomeFornecedor, sizeof(forn[i].nomeFornecedor));
			cout << "Endereço: ";
			cin.getline(forn[i].endereco, sizeof(forn[i].endereco));
			cout << "Telefone: ";
			cin.getline(forn[i].telefone, sizeof(forn[i].telefone));
			cout << "Cidade: ";
			cin.getline(forn[i].cidade, sizeof(forn[i].cidade));
			cout << "Código do Estado: ";
			cin >> forn[i].idUF;
			cout << "CNPJ: ";
			cin.ignore();
			cin.getline(forn[i].cnpj, sizeof(forn[i].cnpj));
		}
		else saida = 0;
	}
	contadorF = i - 1;
}

//Inclusão Fornecedor

void buscaEstado(struct Estado est[], int codE);

void novoFornecedor (struct Estado est[], struct Fornecedor forn[], int &contadorF){
	int i =0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Fornecedor " << (i+1) << ": ";
		cin >> forn[i].idFornecedor;
		if (forn[i].idFornecedor > 0){
			cout << "Nome: ";
			cin.ignore();
			cin.getline(forn[i].nomeFornecedor, sizeof(forn[i].nomeFornecedor));
			cout << "Endereço: ";
			cin.getline(forn[i].endereco, sizeof(forn[i].endereco));
			cout << "Telefone: ";
			cin.getline(forn[i].telefone, sizeof(forn[i].telefone));
			cout << "Cidade: ";
			cin.getline(forn[i].cidade, sizeof(forn[i].cidade));
			cout << "Código do Estado: ";
			cin >> forn[i].idUF;
			int codE;
			codE = forn[i].idUF;
			buscaEstado (est, codE);
			cout << "CNPJ: ";
			cin.ignore();
			cin.getline(forn[i].cnpj, sizeof(forn[i].cnpj));
	   }
	   else saida = 0;	
     }
     contadorF = i - 1;
}

void buscaEstado (struct Estado est[], int codE){
	int i = 0, f= 4;
	int m = (i + f) / 2;
	for (; f >= i && codE != est[m].codUF; m = (i + f) / 2){
		if (codE > est[m].codUF)
			i = m + 1;
		else 
			f = m - 1;
    }
    if (codE == est[m].codUF)
    	cout << "Nome do Estado: " << est[m].nomeEstado << endl;
	else 
		cout << "\nEstado não Encontrado" << endl;
}

void incFornecedor (struct Fornecedor S[], int contS, struct Fornecedor T[], int contT, struct Fornecedor A[], int &contA){
    int i = 0, j = 0, k = 0; 
    for (;i < contS && j < contT;k++){
        if (S[i].idFornecedor < T[j].idFornecedor){
            A[k].idFornecedor = S[i].idFornecedor;
            strcpy (A[k].nomeFornecedor,S[i].nomeFornecedor);
            strcpy (A[k].endereco,S[i].endereco);
			strcpy (A[k].telefone,S[i].telefone);
            strcpy (A[k].cidade,S[i].cidade);
            A[k].idUF = S[i].idUF;
			strcpy (A[k].cnpj,S[i].cnpj);
            i++;
            }
        else {
            A[k].idFornecedor = T[j].idFornecedor;
            strcpy (A[k].nomeFornecedor,T[j].nomeFornecedor);
            strcpy (A[k].endereco,T[j].endereco);
			strcpy (A[k].telefone,T[j].telefone);
            strcpy (A[k].cidade,T[j].cidade);
            A[k].idUF = T[j].idUF;
			strcpy (A[k].cnpj,T[j].cnpj);
            j++;
        }
    }
    while (i < contS){
        A[k].idFornecedor = S[i].idFornecedor;
        strcpy (A[k].nomeFornecedor,S[i].nomeFornecedor);
        strcpy (A[k].endereco,S[i].endereco);
		strcpy (A[k].telefone,S[i].telefone);
        strcpy (A[k].cidade,S[i].cidade);
        A[k].idUF = S[i].idUF;
		strcpy (A[k].cnpj,S[i].cnpj);
        i++;
        k++;
    }
    while (j < contT){
        A[k].idFornecedor = T[j].idFornecedor;
        strcpy (A[k].nomeFornecedor,T[j].nomeFornecedor);
        strcpy (A[k].endereco,T[j].endereco);
		strcpy (A[k].telefone,S[i].telefone);
        strcpy (A[k].cidade,T[j].cidade);
		A[k].idUF = S[i].idUF;
		strcpy (A[k].cnpj,S[i].cnpj);
        j++;
        k++;
    }
    contA = k;
}


//Fim da inclusão Fornecedor

//Inicio da inclusão Produto

int buscaProduto (struct Produto prod[], int codP);
void buscaFornecedor (struct Fornecedor forn[], int codF);

void novoProd (struct Fornecedor forn[], struct Produto prod[], struct Produto nProd[], int &contadorP){
	int i =0;
	for (int saida = 1; i < 4 && saida != 0; i++){
		cout << "\n\nCódigo do Produto: ";
		cin >> nProd[i].idProduto;
		int codP;
		codP = nProd[i].idProduto;
		if (codP > 0){
		buscaProduto (prod, codP);
		cout << "Descrição: ";
		cin.ignore(); 
		gets(nProd[i].descProd);
		cout << "Código Tipo do Produto: ";
		cin >> nProd[i].idTipo;
		cout << "Código do Fornecedor: ";
		cin >> nProd[i].codFornecedor;
		int codF;
		codF = nProd[i].codFornecedor;
		buscaFornecedor (forn, codF);
		cout << "Quantidade do Estoque: ";
		cin >> nProd[i].qtdeEstoque;
		cout << "Estoque Mínimo: ";
		cin >> nProd[i].estoqueMin;
		cout << "Estoque Máximo: ";
		cin >> nProd[i].estoqueMax;
		cout << "Valor Unitário: ";
		cin >> nProd[i].valorUnt;
	}
	else 
		saida = 0;
  }
  contadorP = i - 1;
}

int buscaProduto (struct Produto prod[], int &codP){
	int i = 0, f = 4;
	int m = (i+f) / 2;
	for (; f >= i && codP != prod[m].idProduto; m = (i+f)/2){
		if (codP > prod[m].idProduto)
			i = m + 1;
		else 
			f = m - 1;
	}
	if (codP == prod[m].idProduto){
		cout << "Código do Produto já existe. Por favor digite outro código!\n\n";
		getch();
	} 
	else 
		return -1;
}

void buscaFornecedor (struct Fornecedor forn[], int codF){
	int i = 0, f= 4;
	int m = (i + f) / 2;
	for (; f >= i && codF != forn[m].idFornecedor; m = (i + f) / 2){
		if (codF > forn[m].idFornecedor)
			i = m + 1;
		else 
			f = m - 1;
    }
    if (codF == forn[m].idFornecedor)
    	cout << "Nome do Fornecedor: " << forn[m].nomeFornecedor << endl;
	else 
		cout << "\nFornecedor não Encontrado" << endl;
}

void incProduto (struct Produto S[], int contS, struct Produto T[], int contT, struct Produto A[], int &contA){
    int i = 0, j = 0, k = 0; 
    for (;i < contS && j < contT;k++){
        if (S[i].idProduto < T[j].idProduto){
            A[k].idProduto = S[i].idProduto;
            strcpy (A[k].descProd,S[i].descProd);
            A[k].idTipo = S[i].idTipo;
            A[k].codFornecedor = S[i].codFornecedor;
            A[k].qtdeEstoque = S[i].qtdeEstoque;
            A[k].estoqueMin = S[i].estoqueMin;
            A[k].estoqueMax = S[i].estoqueMax;
            A[k].valorUnt = S[i].valorUnt;
            i++;
            }
        else {
            A[k].idProduto = T[j].idProduto;
            strcpy (A[k].descProd,T[j].descProd);
            A[k].idTipo = T[j].idTipo;
            A[k].codFornecedor = T[j].codFornecedor;
            A[k].qtdeEstoque = T[j].qtdeEstoque;
            A[k].estoqueMin = T[j].estoqueMin;
            A[k].estoqueMax = T[j].estoqueMax;
            A[k].valorUnt = T[j].valorUnt;
            j++;
        }
    }
    while (i < contS){
            A[k].idProduto = S[i].idProduto;
            strcpy (A[k].descProd,S[i].descProd);
            A[k].idTipo = S[i].idTipo;
            A[k].codFornecedor = S[i].codFornecedor;
            A[k].qtdeEstoque = S[i].qtdeEstoque;
            A[k].estoqueMin = S[i].estoqueMin;
            A[k].estoqueMax = S[i].estoqueMax;
            A[k].valorUnt = S[i].valorUnt;
        i++;
        k++;
    }
    while (j < contT){
            A[k].idProduto = T[j].idProduto;
            strcpy (A[k].descProd,T[j].descProd);
            A[k].idTipo = T[j].idTipo;
            A[k].codFornecedor = T[j].codFornecedor;
            A[k].qtdeEstoque = T[j].qtdeEstoque;
            A[k].estoqueMin = T[j].estoqueMin;
            A[k].estoqueMax = T[j].estoqueMax;
            A[k].valorUnt = T[j].valorUnt;
        j++;
        k++;
    }
    contA = k;
}

void mostrarIncProd (struct Produto A[], int &contA){
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].idProduto;
        cout << "Descrição: " << A[i].descProd;
        cout << "Id Tipo: " << A[i].idTipo;
        cout << "Id Fornecedor: " << A[i].codFornecedor;
        cout << "Quantidade Estoque: " << A[i].qtdeEstoque;
        cout << "Estoque Minimo: " << A[i].estoqueMin;
        cout << "Estoque Máximo: " << A[i].estoqueMax;
        cout << "Valor Unitário: " << A[i].valorUnt;
    }
    getch();
}

//Fim da inclusão Produto

//Inicio Venda

//int buscaVendaProd (struct Produto prod[], int &codVp){
//	int i = 0, f = 4;
//	int m = (i + f) / 2;
//	for (; f >= i && codVp != prod[m].idProduto; m = (i + f) / 2){
//		if(codVp > prod[m].idProduto)
//			i = m + 1;
//		else 
//			m = i - 1;
//	}
//	
//	if (codVp == prod[m].idProduto){
//		cout << "Descrição do Produto: " << prod[m].descProd << endl;
//		cout << "Quantidade em Estoque: " << prod[m].qtdeEstoque << endl;
//		cout << "Valor Unitário: " << prod[m].valorUnt << endl;
//	}
//	else
//		return -1;
//}
//
//int buscaVendaTipo (struct TipoProduto tipo[], int &codTp){
//	int i = 0, f = 4;
//	int m = (i + f) / 2;
//	for (; f >= i && codTp != tipo[m].idTipo; m = (i + f) / 2){
//		if(codTp > tipo[m].idTipo)
//			i = m + 1;
//		else 
//			m = i - 1;
//	}
//	
//	if (codTp == tipo[m].idTipo)
//		cout << "Descrição Tipo do Produto: " << tipo[m].descTipo;
//	else
//		return -1;
//}



//Fim Venda

//Inicio Mostrar

void mostrarIncForn (struct Fornecedor A[], int &contA){
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].idFornecedor;
        cout << "\tNome: " << A[i].nomeFornecedor;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tTelefone: " << A[i].telefone;
        cout << "\tCidade: " << A[i].cidade;
        cout << "\tUF: " << A[i].idUF;
        cout << "\tCNPJ: " << A[i].cnpj;
    }
    getch();
}
//Fim Mostrar

int main() {
	setlocale(LC_ALL,"");
	
	struct TipoProduto arqTipo[4];
	struct Produto arqProd[4], arqnProd[4];
	struct Estado arqEstado[4];
	struct Fornecedor arqForn[4];
	
	int contTipo = 0, contProd = 0, contEst = 0, contForn = 0;
	
	int al = 0;

	while (al != 5){
	system("cls");
		cout << "\t\t\t---Menu de Opções---\n\n\n";
		
		cout << "\t\t1 - Cadastrar\n" << endl;
		cout << "\t\t2 - Inserir\n" << endl;
		cout << "\t\t3 - Vender\n" << endl;
		cout << "\t\t4 - Mostrar\n\n" << endl;
		cout << "\t\t5 - Sair" << endl;
	
		cout << "\n\nEscolha a opção: ";
		cin >> al;
		
		switch (al)
		{			
			case 1: 
				system("cls");

				int al1;
				while(al1 != 5)
				{
					system("cls");
					cout << "\t\t\tCadastros\n\n";
					cout << "\t\t1 - Tipo Produto" << endl;
					cout << "\t\t2 - Produto" << endl;
					cout << "\t\t3 - Estado" << endl;
					cout << "\t\t4 - Fornecedor" << endl;

					cout << "\n\t\t5 - Voltar";

					cout << "\n\n\tEscolha uma opção: ";
					cin >> al1;

					switch (al1)
					{
					case 1:
						system("cls");
						cout << "\tTipo Produto\n\n";
						leituraTipo(arqTipo, contTipo);
						system("pause");
						break;

					case 2:
						system("cls");
						cout << "\tProduto\n\n";
						leituraProduto(arqProd, contProd);
						system("pause");
						break;

					case 3:
						system("cls");
						cout << "\tEstado\n\n";
						leituraEstado(arqEstado, contEst);
						system("pause");
						break;
					
					case 4:
						system("cls");
						cout << "\tFornecedor\n\n";
						leituraFornecedor(arqForn, contForn);
						system("pause");
						break;

					case 5:
						system("cls");
						cout << "Voltando...\n\n\n";
						break;
					
					default:
						system("cls");
						cout << "Opção inválida! Informe um valor entre 1 e 5.\n\n\n";
						system("pause");
						al1 = 0;
						break;
					}
				}
				al1 = 0;
			    break; 
			
			
			case 2:  
			   system("cls");
			   
			   int al2; 
			   while (al2 != 3)
			   {
			   		system("cls");
			   		cout << "\t\tInserir novos Registros\n\n";
			   		cout << "\t\t1 - Fornecedor" << endl;
			   		cout << "\t\t2 - Produto" << endl;
			   		
			   		cout << "\n\t\t3 - Voltar";
			   		
			   		cout << "\n\nEscolha uma opção: ";
			   		cin >> al2;
			   		
			   		switch (al2)
			   		{
			   			case 1:
			   				struct Fornecedor fornS[4], fornT[4], fornA[8];
			   				int contS, contT, contA;
			   				
			   				system("cls");
			   				cout << "\t\t\tInclusão de Fornecedor\n\n" << endl;
			   				
			   				cout << "\nLeitura Arquivo S";
			   				novoFornecedor(arqEstado, fornS, contS);
			   				system("cls");
			   				
			   				cout << "\nLeitura Arquivo T";
			   				novoFornecedor(arqEstado, fornT, contT);
			   				system("cls");
			   			
			   				incFornecedor(fornS, contS, fornT, contT, fornA, contA);
			   				system("pause");
			   				break;
			   				
			   			case 2:
//			   				struct Produto prodS[4], prodT[4], prodA[8];
//			   				int contpS, contpT, contpA;
//			   				
//			   				system("cls");
//			   				cout << "\t\t\tInclusão de Produto\n\n" << endl;
//			   				
//			   				cout << "\nLeitura Arquivo S";
//			   				novoProd (arqForn, arqProd, prodS, contpS);
//			   				system ("cls");
//			   				
//			   				cout << "\nLeitura Arquivo T";
//			   				novoProd (arqForn, arqProd, prodT, contpT);
//			   				system("cls");
//			   				
//			   				incProduto(prodS, contpS, prodT, contpT, prodA, contpA);
//			   				mostrarIncProd (prodA, contpA);
			   				break;
			   				
			   			case 3:
			   				system("cls");
			   				cout << "Voltando...\n\n\n";
			   				break;
			   				
			   			default:
							system("cls");
							cout << "Opção inválida! Informe um valor entre 1 e 3.\n\n\n";
							system("pause");
							al2 = 0;
							break;
					}
					al2 = 0;
					break;
			   }
			
			
			case 3:  
			  system("cls");
			  cout << "\t\tVenda do Produto\n\n";
			  
			  al = 0;
			  break; 
			
			
			case 4:  
			   system("cls");
			   
			   int al4;
			   while (al4 != 4)
			   {
			   		system("cls");
			   		cout << "\t\tConsultar os Registros\n\n";
			   		cout << "\t\t1 - Inclusão Fornecedor" << endl;
			   		cout << "\t\t2 - Inclusão Produtos" << endl;
			   		cout << "\t\t3 - Estoque Abaixo do Mínimo" << endl;
			   		
			   		cout << "\n\t\t4 - Voltar";
			   		
			   		cout << "\n\nEscolha uma opção: ";
			   		cin >> al4;
			   		
			   		switch (al4)
			   		{
			   			case 1:
			   				struct Fornecedor fornS[4], fornT[4], fornA[8];
			   				int contS, contT, contA;
			   				
			   				system("cls");
			   				
			   				cout << "\t\t\tConsulta Inclusão Fornecedor\n\n" << endl;
			   				mostrarIncForn(fornA, contA);
			   				system("pause");
			   				break;
			   				
			   				
			   			case 2:
			   				system("cls");
			   				
			   				cout << "\t\t\tConsulta Inclusão Produto\n\n" << endl;
			   				
			   				system("pause");
			   				break;
			   				
			   				
			   			case 3:
			   				system("cls");
			   				
			   				cout << "\t\t\tConsulta de Estoque Mínimo\n\n" << endl;
			   				
			   				system("pause");
			   				break;
			   				
			   				
			   			case 4:
			   				system("cls");
			   				cout << "Voltando...\n\n\n";
			   				break;
			   				
			   				
			   			default:
			   				system("cls");
			   				cout << "Opção inválida! Informe um valor entre 1 e 4.\n\n\n";
			   				system("pause");
			   				al4 = 0;
			   				break;
					}
			   	
			   }
			   al4 = 0;
			   break; 
			
			
			case 5:  
			   system("cls");
			   cout << "Saindo.\n\n";
			   break; 
						
			
			default:
				system("cls");
			    cout << "\nOpçãoo inválida. Informe um número entre 1 e 5\n\n\n";
			    al = 0;
				break;
		  }
	   }
}