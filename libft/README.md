Language / Idioma: [🇧🇷 Português](#-libft---sua-primeira-biblioteca) | [🇺🇸 English](#-libft---your-first-library)

[🇺🇸 English]
# Libft - Your first library.

## Description
The Libft project consists of creating a general-purpose C library that bundles various standard functions to be used in future school projects. The central goal is to understand the inner workings of standard library functions from the libc, implementing them from scratch to develop solid foundations in programming, dynamic allocation, and memory management.

## Instructions

### Compilation
The library is compiled into a file named libft.a at the root of the repository. The included Makefile uses the cc compiler with the mandatory error flags (-Wall -Wextra -Werror):

make          # Compiles all mandatory functions
make bonus    # Compiles the linked list functions (kept for tester compatibility)
make clean    # Removes object files (.o)
make fclean   # Removes object files and the libft.a library
make re       # Performs fclean and recompiles everything

Note: The Makefile avoids unnecessary relinking, and all source files are explicitly named, as required by the Norm.

## Library Content
The functions are organized into three main blocks, subdivided by operational category:

### Bloco 1: Libc Functions (Reimplementations)
In this section, functions strictly mimic the behavior described in their respective man pages.

* Type: Character Verification and Conversion
    * ft_isalpha: Checks for an alphabetic character.
    * ft_isdigit: Checks for a digit.
    * ft_isalnum: Checks for an alphanumeric character.
    * ft_isascii: Checks if a character fits into the ASCII table.
    * ft_isprint: Checks for any printable character.
    * ft_toupper: Converts a character to uppercase.
    * ft_tolower: Converts a character to lowercase.

* Type: Memory Manipulation
    * ft_memset: Fills memory with a constant byte.
    * ft_bzero: Zeroes out a byte string.
    * ft_memcpy: Copies memory area (without memory overlap handling).
    * ft_memmove: Copies memory area (safely handles memory overlap).
    * ft_memchr: Scans memory for a character.
    * ft_memcmp: Compares memory areas.
    * ft_calloc: Allocates and zeroes out memory dynamically.

* Type: String Manipulation
    * ft_strlen: Calculates the length of a string.
    * ft_strlcpy: Size-bounded string copying.
    * ft_strlcat: Size-bounded string concatenation.
    * ft_strchr: Locates the first occurrence of a character in a string.
    * ft_strrchr: Locates the last occurrence of a character in a string.
    * ft_strncmp: Compares two strings up to a specific character limit.
    * ft_strnstr: Locates a substring within another string.
    * ft_strdup: Duplicates a string using dynamic allocation.

* Type: Data Conversion
    * ft_atoi: Converts a string to an integer.

---

### Bloco 2: Additional Functions
Functions that are not part of the standard libc or have specific requirements outlined by the project.

* Type: Advanced String Manipulation
    * ft_substr: Extracts a substring from an original string.
    * ft_strjoin: Concatenates two strings into a new memory allocation.
    * ft_strtrim: Trims specific characters from the beginning and end of a string.
    * ft_split: Splits a string into an array of strings using a delimiter character.
    * ft_strmapi: Applies a function to each character of a string (creates a new string).
    * ft_striteri: Applies a function to each character of a string (modifies the original).

* Type: Data Conversion
    * ft_itoa: Converts an integer to a string.

* Type: Output to File Descriptors (FD)
    * ft_putchar_fd: Writes a character to the specified file descriptor.
    * ft_putstr_fd: Writes a string to the specified file descriptor.
    * ft_putendl_fd: Writes a string followed by a newline to the specified file descriptor.
    * ft_putnbr_fd: Writes an integer to the specified file descriptor.

---

### Bloco 3: Linked List Functions
Functions to manage and manipulate the t_list dynamic data structure (composed of void *content and struct s_list *next). In this updated curriculum, this entire block is a mandatory requirement of the project.

* Type: Node and List Management
    * ft_lstnew: Dynamically allocates and creates a new list node.
    * ft_lstadd_front: Adds a node at the beginning of the list.
    * ft_lstsize: Counts the number of elements in the list.
    * ft_lstlast: Returns the last node of the list.
    * ft_lstadd_back: Adds a node at the end of the list.
    * ft_lstdelone: Deletes a single node and frees its content using a function pointer.
    * ft_lstclear: Deletes and frees an entire list and all its successors.
    * ft_lstiter: Iterates over the list, applying a function to each node's content.
    * ft_lstmap: Creates a new list resulting from applying a function to each node.

---

## Norm Rules
The code strictly complies with the 42 school Norm (v3 / v4) validated by the norminette tool:
* Strict limit of 25 lines per function.
* Maximum of 5 variable declarations per function.
* Forbidden usage of for, do...while, switch, case, goto, and ternary operators.
* Variable declarations must be perfectly aligned using tabs (MISALIGNED_VAR_DECL check).
* All file and function names follow the snake_case naming convention.

## AI Usage Report
In accordance with pedagogical guidelines and academic integrity:
* Purpose: AI (Gemini) was utilized interactively and Socratically to help break down the step-by-step logic of complex algorithms (such as pointer traversal in ft_lstmap, memory leak prevention in ft_lstclear, and handling double pointers like **lst). It also assisted in debugging compilation errors related to implicit declarations (-Wimplicit-function-declaration) and Norm compliance formatting.
* Control: Every single code suggestion was manually reviewed, line-by-line, to ensure a genuine comprehension of the underlying reverse-engineered mechanics and to prevent forbidden code structures from slipping in.
* Resources: No automated code generation tools were used for mass production; the entire process focused strictly on learning according to the peer-to-peer engineering framework.

## References

### Man Pages & Official Documentation
* [Man7.org - Linux Manual Pages](https://man7.org/linux/man-pages/): Official reference for libc function behavior (e.g., man malloc, man memmove, man write).
* [GNU C Library (glibc)](https://www.gnu.org/software/libc/): Technical specifications regarding standard headers and primitive data types.

### 42 Manuals and Tools
* 42 Subject Manual (Libft): Project manual provided on the Intranet platform specifying the required prototypes and expected behaviors.
* 42 Norminette: The official code style validator repository provided by the school to enforce scoping and tab rules.

### Community and Academic Learning
* [GeeksforGeeks - Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/): Conceptual guides utilized to understand insertion, traversal, and safe deletion within dynamic linked structures.
* [Learn-C.org](https://www.learn-c.org/): Quick references regarding pointer arithmetic and passing parameters by value versus by reference.



[🇧🇷 Português]
# Libft - Sua primeira biblioteca.

## Descrição
O projeto Libft consiste na criação de uma biblioteca em C que agrupa diversas funções de uso geral que serão utilizadas em futuros projetos da escola. O objetivo central é compreender o funcionamento interno de funções padrão da biblioteca libc, reimplementando-as do zero para desenvolver fundamentos sólidos em programação, alocação dinâmica e manipulação de memória.

## Instruções

### Compilação
A biblioteca é compilada gerando um arquivo chamado libft.a na raiz do repositório. O Makefile incluído utiliza o compilador cc com as flags de erro obrigatórias (-Wall -Wextra -Werror):

make          # Compila todas as funções obrigatórias
make bonus    # Compila as funções de lista encadeada (mantido para compatibilidade com testadores)
make clean    # Remove os arquivos objeto (.o)
make fclean   # Remove os arquivos objeto e a biblioteca .a
make re       # Realiza o fclean e compila novamente

Nota:** O Makefile não realiza relink desnecessário e todos os arquivos fonte são explicitamente nomeados, conforme exigido pela Norma.

## Conteúdo da Biblioteca
As funções estão organizadas em três blocos principais, subdivididas por categoria de operação:

### Bloco 1: Funções da Libc (Reimplementações)
Nesta parte, as funções seguem rigorosamente o comportamento descrito em suas respectivas man pages.

* Tipo: Verificação e Conversão de Caracteres
    * ft_isalpha: Verifica se o caractere é alfabético.
    * ft_isdigit: Verifica se o caractere é um dígito.
    * ft_isalnum: Verifica se o caractere é alfanumérico.
    * ft_isascii: Verifica se o caractere pertence à tabela ASCII.
    * ft_isprint: Verifica se o caractere é imprimível.
    * ft_toupper: Converte um caractere para maiúsculo.
    * ft_tolower: Converte um caractere para minúsculo.

* Tipo: Manipulação de Memória
    * ft_memset: Preenche a memória com um byte constante.
    * ft_bzero: Zera uma porção de memória.
    * ft_memcpy: Copia uma área de memória (sem sobreposição).
    * ft_memmove: Copia uma área de memória (com segurança para sobreposição).
    * ft_memchr: Localiza um caractere em um bloco de memória.
    * ft_memcmp: Compara dois blocos de memória.
    * ft_calloc: Aloca e zera a memória de forma dinâmica.

* Tipo: Manipulação de Strings
    * ft_strlen: Calcula o comprimento de uma string.
    * ft_strlcpy: Copia strings com limite de tamanho.
    * ft_strlcat: Concatena strings com limite de tamanho.
    * ft_strchr: Localiza a primeira ocorrência de um caractere na string.
    * ft_strrchr: Localiza a última ocorrência de um caractere na string.
    * ft_strncmp: Compara duas strings até um limite de caracteres.
    * ft_strnstr: Localiza uma substring dentro de outra string.
    * ft_strdup: Duplica uma string usando alocação dinâmica.

* Tipo: Conversão de Dados
    * ft_atoi: Converte uma string para um número inteiro.

---

### Bloco 2: Funções Adicionais
Funções que não constam na libc padrão ou possuem assinaturas específicas exigidas pelo projeto.

* Tipo: Manipulação de Strings Avançada
    * ft_substr: Cria uma substring a partir de uma string original.
    * ft_strjoin: Concatena duas strings em uma nova alocação.
    * ft_strtrim: Remove caracteres específicos do início e fim de uma string.
    * ft_split: Divide uma string em um array de strings usando um delimitador.
    * ft_strmapi: Aplica uma função a cada caractere de uma string (gera nova string).
    * ft_striteri: Aplica uma função a cada caractere de uma string (modifica a original).

* Tipo: Conversão de Dados
    * ft_itoa: Converte um número inteiro para uma string.

* Tipo: Saída em File Descriptors (FD)
    * ft_putchar_fd: Escreve um caractere no FD especificado.
    * ft_putstr_fd: Escreve uma string no FD especificado.
    * ft_putendl_fd: Escreve uma string seguida de nova linha no FD.
    * ft_putnbr_fd: Escreve um número inteiro no FD especificado.

---

### Bloco 3: Funções de Listas Encadeadas
Funções para gerenciamento e manipulação da estrutura de dados dinâmica t_list (composta por void *content e struct s_list *next). Nesta matriz curricular, este bloco integra o escopo mandatório do projeto.

* Tipo: Gerenciamento de Nós e Lista
    * ft_lstnew: Cria um novo nó de lista alocado dinamicamente.
    * ft_lstadd_front: Adiciona um nó no início da lista.
    * ft_lstsize: Conta o número de elementos da lista.
    * ft_lstlast: Retorna o último nó da lista.
    * ft_lstadd_back: Adiciona um nó no final da lista.
    * ft_lstdelone: Deleta um único nó e libera seu conteúdo usando uma função ponteiro.
    * ft_lstclear: Deleta uma lista inteira e libera toda a memória alocada.
    * ft_lstiter: Itera sobre a lista aplicando uma função a cada conteúdo.
    * ft_lstmap: Cria uma nova lista resultante da aplicação de uma função em cada nó.

---

## Regras da Norma
O código respeita integralmente a Norma v3 / v4 da 42 através do validador norminette:
* Limite estrito de 25 linhas por função.
* No máximo 5 variáveis por função.
* Proibição do uso de for, do...while, switch, case, goto e operadores ternários.
* Declarações de variáveis perfeitamente alinhadas por tabulação (MISALIGNED_VAR_DECL).
* Nomes de arquivos e funções seguem o padrão snake_case.

## Relatório de Uso de IA
Como parte das exigências pedagógicas e éticas:
* Finalidade: A IA (Gemini) foi utilizada de forma interativa e socrática para auxiliar na quebra da lógica passo a passo de algoritmos complexos (como a caminhada de ponteiros na ft_lstmap, a prevenção de vazamentos de memória na ft_lstclear e o tratamento de ponteiros duplos **lst). Também auxiliou na depuração de erros de compilação relacionados a declarações implícitas (-Wimplicit-function-declaration) e sintaxe da Norma.
* Controle: Todas as sugestões de código foram revisadas linha por linha e validadas manualmente para garantir a compreensão real da engenharia reversa das funções e blindar o código contra padrões proibidos.
* Recursos: Nenhuma automação de geração em massa foi utilizada; o processo focou no aprendizado pautado no modelo de engenharia da escola.

## Referências de Pesquisa

### Man Pages & Documentação Oficial
* [Man7.org - Linux Manual Pages](https://man7.org/linux/man-pages/): Consulta oficial para o comportamento das funções da libc (ex: man malloc, man memmove, man write).
* [GNU C Library (glibc)](https://www.gnu.org/software/libc/): Referência técnica sobre os cabeçalhos padrão e manipulação de tipos de dados primitivos.

### Manuais e Ferramentas da 42
* 42 Subject Oficial (Libft): Manual do projeto fornecido na plataforma Intranet para requisitos de protótipos e comportamento esperado.
* 42 Norminette: Repositório e validador oficial da Norma da escola para checagem de estilo de código (regras de tabulação e restrições de escopo).

### Comunidade e Aprendizado Correlato
* [GeeksforGeeks - Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/): Guia conceitual utilizado para compreender a coreografia de inserção, caminhada e deleção de nós em estruturas dinâmicas encadeadas.
* [Learn-C.org](https://www.learn-c.org/): Consultas rápidas sobre aritmética de ponteiros e passagem de parâmetros por valor vs. referência.
