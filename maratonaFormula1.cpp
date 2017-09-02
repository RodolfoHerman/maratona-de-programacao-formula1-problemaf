/* --------------------------------------------------------------- */
/*                                                                 */
/*                            _       _                            */
/*                           |_| | | |                             */
/*                           |   |_| |_                            */
/*                      ====================                       */
/*                                                                 */
/*                                                                 */
/* --------------------------------------------------------------- */
/*        PUC-MG, Unidade COREL. Disciplina de Grafos	           */
/*               Graduação em Ciência da Computação                */
/*         2013 Coração Eucarístico, Belo Horizonte - MG           */
/*                     http://www.pucminas.br/                     */
/*                                                                 */
/*        Author: Rodolfo Herman;                                  */
/*                                                                 */
/*                                                                 */
/* --------------------------------------------------------------- */

/* --------------------------------------------------------------- */
/*	ALGORITMO: Maratona de Programacao da SBC – ACM ICPC – 2010    */
/* --------------------------------------------------------------- */	
	
	 
	 
	//=====================================================================
	// BIBLIOTECAS
	//=====================================================================
	#include <iostream>
	#include <fstream>
	#include <stdio.h>
	 
	 
	using namespace std;
	 
	
	class Piloto {
		private:
		int *numGrandesPremios;
		int posicao;
		int posicaoAnalise;
		int pts;
	
		public:
		
		Piloto ( int quantidade ) {
			numGrandesPremios = new int [quantidade];
			posicao = 0;
			pts = 0;
			posicaoAnalise = 0;
		}
		
		void ordemChegadas ( int chegada ) {
			numGrandesPremios[posicao] = chegada;
			posicao++;
		}
		
		void verificarChegada ( int ordem, int pontosGanhos ) {
			if ( numGrandesPremios[posicaoAnalise] == ordem ) {
				pts = pts + pontosGanhos;
			}
		}
		
		void atualizarDados () {
			posicaoAnalise = 0;
			pts = 0;
		}
		
		void atualizaPosicao() {
			posicaoAnalise++;
		}
		
		int getPontuacao () {
			return (pts);
		}
		
	};
	
	class Pontuacao {
		private:
			int *pontuacao;
			int posicao;
			int tam;
		public:
		
		Pontuacao (int tamanho) {
			pontuacao = new int [tamanho];
			posicao = 0;
			tam = tamanho;
		}
	
	
		void inserir ( int pts ) {
			pontuacao[posicao] = pts;
			posicao++;
		}
		
		int retirar ( int pos) {
			return (pontuacao[pos]);
		}
		
		int getNumAnalise() {
			return ( tam );
		}
	};

	
	class Maratona {
		private:
		int numPilotos;
		   
		public:
		  //--------------------------------------------------------------------
		  // Construtor
		  //--------------------------------------------------------------------
		Maratona(){
		}//-------------------------------------------------------------------
	 
	 
		  //--------------------------------------------------------------------
		  // Destrutor
		  //--------------------------------------------------------------------
		~Maratona(){
		}//-------------------------------------------------------------------
	 
		bool entrada(){
			bool resp = true;
			int qtGrandePremios;	
			int temp;
			int sistemPts;
			int analise;
			int pts;
			int a;
			//cout << "GRAND PREMIOS : ";
			cin >> qtGrandePremios;
			//cout << "\nNUM PILOTOS : ";
			cin >> numPilotos;
			if ( (qtGrandePremios <= 0 || qtGrandePremios > 100) || (numPilotos <= 0) ) {
				resp = false;
			} else {
				Piloto** pilotos = new Piloto*[numPilotos];
				for ( int x = 0; x < numPilotos; x++ ) {
					pilotos[x] = new Piloto(qtGrandePremios);
				}
				for ( int m = 0; m < qtGrandePremios; m ++ ) { 
					for ( int x = 0; x < numPilotos; x++ ) {
						//cout << "\nPOSICAO : ";
						cin >> temp;
						pilotos[x]->ordemChegadas(temp);
					}
				}	
				//cout << "\nQTD DE SISTEMAS : ";
				cin >> sistemPts;
			
				Pontuacao** pontos = new Pontuacao*[sistemPts];			
				for ( int x = 0; x < sistemPts; x++ ) {
					//cout << "\nQTD DE PILOTOS ANALISES : ";
					cin >> analise;
					pontos[x] = new Pontuacao( analise);
					for ( int a = 0; a < analise; a++ ) {
						//cout << "\nPTS GANHOS DO PILOTO NUMERO : " << a << " : ";
						cin >> pts;
						pontos[x]->inserir(pts);
					}
				}
			
				for ( int k = 0; k < sistemPts; k++ ) {
					for ( int a = 0; a < qtGrandePremios; a ++ ) {
						for ( int y = 0; y < pontos[k]->getNumAnalise(); y ++ ) {
							int num = pontos[k]->retirar(y);
							for ( int h = 0; h < numPilotos; h ++ ) {
								pilotos[h]->verificarChegada ( y+1, num);
							}	
						}
						if ( a != (qtGrandePremios -1) ) {
							for ( int t = 0; t < numPilotos; t++ ) {
								pilotos[t]->atualizaPosicao();
							}							
						}
					}
					int maior = pilotos[0]->getPontuacao();
					for ( int x = 0; x < numPilotos; x++ ) {
					//cout << "\nPILOTO : " << x << " PTS : " << pilotos[x]->getPontuacao();
						if ( pilotos[x]->getPontuacao() > maior) {
							maior = pilotos[x]->getPontuacao();
						}
					}
				
					for ( int x = 0; x < numPilotos; x++ ) {
						if ( pilotos[x]->getPontuacao() == maior ) {
							cout << (x+1) << " ";
						}	
					}					
					cout << endl;
					for ( int x = 0; x < numPilotos; x ++ ) {
						pilotos[x]->atualizarDados();
					}				
				}
				delete pilotos;
				delete pontos;
			}			 
			return resp;
		}//-------------------------------------------------------------------
	};
	 
	 
	//=====================================================================
	// FUNCAO PRINCIPAL
	//=====================================================================
	int main(int argc, char **argv){
	   int cont = 0;
	   Maratona *g = new Maratona;

	   while ( g->entrada() == true){
		  delete g;
		  g = new Maratona;
	   }
	 
	   delete g;
	   return 0;
	}//--------------------------------------------------------------------
