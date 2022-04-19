CI1065 - Algoritmos e Teoria dos Grafos  
Trabalho - Coeficiente de proximidade
GRR20182564 - Viviane da Rosa Sommer

Para rodar o trabalho:\
    - make \
    - ./teste \
    - Então, deve-se digitar o vértice que será realizado o cálculo de proximidade no terminal

Para testar outros arquivos:\
    Alterar no arquivo teste.c, a linha 14 com o pat do arquivo desejado.\
    Por padrão, está sendo utilizado o arquivo peterson.txt

Arquivos:\
    Fila.h : \
        - definição da estrutura Fila, usada para armazenar os vértices do grafo durante a busca em largura \
        - definição das funções específicas de Fila \
    Fila.c : \
        - criar_fila : função que cria uma Fila com tamanho x \
        - esta_vazia : função que testa de Fila está vazia \
        - enfileira : adiciona um vértice na Fila \
        - desenfileira : remove um vértice da Fila \
    Grafo.h : \
        - definição da estrutura Nodo_Lista_Adj, usada para armazenas os vértices que são vizinhos ao vértice \
        - definição da estrutura Lista_Adj, usada para armazenar os vértices \
        - definição da estrutura Grafo, usada para armazenar uma lista de vértices \
        - definição das funções específicas de Grafo, Lista_Adj e Nodo_Lista_Adj \
    Grafo.c : \
        - criar_grafo: função que cria um Grafo com suas estruturas \
        - criar_Nodo_Lista_Adj : função que cria um nodo da lista de adjacencia, com o nome fornecido \
        - adicionar_aresta: função que adiciona uma aresta no Grafo, ao ler os vertices do arquivo \
        - criar_vertice: função que cria um vértice novo no Grafo, com o nome fornecido \
        - procurar_vertice: função que procura de o vértice com o nome fornecido, já existe no grafo \
        - imprimir_grafo: função que imprime extrutura do grafo (função usada apenas para debug) \
        - leitura_arquivo: função que le do arquivo, pares de vértices \
        - leitura_vertice: função que le nome do vértice, direto do terminal \
        - coeficiente_proximidade: função que calcula o coeficiente de proximidade \
        - destroi_grafo: função que realiza free nas estruturas do Grafo \
        - busca_largura: função que faz a busca em largura no Grafo, e devolve a distancia entre dois vertices \
    Teste.c : \
        - função main \
