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
	char tipoProduto[20];
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
			cin.ignore();
			gets(prod[i].tipoProduto);
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
    if (codE == est[m].codUF){
    	cout << "Nome do Estado: " << est[m].nomeEstado << endl;
	}
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

void mostrarInclusao (struct Fornecedor A[], int contA){
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
}

//Fim da inclusão Fornecedor

int main() {
	setlocale(LC_ALL,"");
	int al = 0;
	
	struct TipoProduto arqTipo[4];
	struct Produto arqProd[4];
	struct Estado arqEstado[4];
	struct Fornecedor arqForn[4], arqS[4], arqT[4], arqA[8];
	
	int contTipo, contProd, contEst, contForn, contS, contT, contA;


	while (al != 5){
	system("cls");
		cout << "\t\t\t---Menu de Opções---\n\n\n";
		
		cout << "\t\t1 - Cadastrar\n" << endl;
		cout << "\t\t2 - Inserir\n" << endl;
		cout << "\t\t3 - Venda\n" << endl;
		cout << "\t\t4 - Mostrar\n" << endl;
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
						cout << "Voltando.\n\n\n";
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
			   				system("cls");
			   				cout << "\tFornecedor\n\n" << endl;
			   				
			   				cout << "\nLeitura Arquivo S";
			   				novoFornecedor (arqEstado, arqS, contS);
			   				system("cls");
			   				
			   				cout << "\nLeitura Arquivo T";
			   				novoFornecedor (arqEstado, arqT, contT);
			   				system("cls");
			   			
			   				incFornecedor (arqS, contS, arqT, contT, arqA, contA);
			   				mostrarInclusao (arqA, contA);
			   				break;
			   				
			   			case 2:
			   				system("cls");
			   				cout << "\tProduto\n\n";
			   				
			   				break;
			   				
			   			case 3:
			   				system("cls");
			   				cout << "Voltando.\n\n\n";
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
			  
			  break; 
			
			
			case 4:  
			   system("cls"); 
			   cout << "\t\tMostrar os Registros\n\n";
			   
			   break; 
			
			
			case 5:  
			   system("cls");
			   cout << "Saindo.\n\n";
			   break; 
						
			
			default:
				system("cls");
			    cout << "\nOpçãoo inválida. Informe um número entre 1 e 6\n\n\n";
				break;
		  }
	   }
}