# 🚀 MiniProjetos — Listas Duplamente Encadeadas

Repositório contendo a implementação de dois mini-projetos práticos desenvolvidos para a disciplina de **Estrutura de Dados**, do curso de **Bacharelado em Sistemas de Informação (BSI)** do **Instituto Federal de São Paulo (IFSP)**.

Os projetos têm como objetivo aplicar, de forma prática, os conceitos de **Listas Duplamente Encadeadas** e **Listas Duplamente Encadeadas Circulares**, utilizando cenários inspirados em aplicações do cotidiano.

---

## 📁 Estrutura do Repositório

```text
MiniProjetos/
├── DOCS/                         # Documentação e arquivos de apoio
├── P1-NAVEGADOR/                 # Projeto 1: Histórico de Navegação
│   ├── HistoricoNavegacao.cpp
│   └── HistoricoNavegacao.exe
├── P2-MUSICA/                    # Projeto 2: Player de Música Circular
│   ├── TocaMusicas.cpp
│   └── TocaMusicas.exe
└── README.md                     # Documentação do repositório
```

---

## 🛠️ Tecnologias e Conceitos Aplicados

### Linguagem

* **C++**

### Alocação e gerenciamento de memória

* `malloc`
* `calloc`
* `free`
* Alocação dinâmica de memória
* Liberação de memória e prevenção de *memory leaks*

### Estruturas de Dados

* Lista Duplamente Encadeada Linear
* Lista Duplamente Encadeada Circular

### Ponteiros

* Manipulação de ponteiros
* Ponteiros para ponteiros (`**`)
* Atualização de referências entre nós
* Inserção e remoção dinâmica de elementos

---

# 📌 Projetos Desenvolvidos

## 🌐 P1 — Histórico de Navegação

**Pasta:** `P1-NAVEGADOR`

Simulação do funcionamento do histórico de navegação de um navegador de internet, utilizando uma **Lista Duplamente Encadeada**.

### 💡 Funcionamento

Cada URL visitada é armazenada em um nó da lista.

O sistema mantém um ponteiro indicando a página atual, permitindo navegar entre páginas anteriores e posteriores por meio das operações de **voltar** e **avançar**.

O projeto também implementa uma regra semelhante à encontrada em navegadores reais:

> Caso o usuário volte algumas páginas e, em seguida, visite uma nova página, todo o histórico posterior à página atual é removido.

Os nós removidos são devidamente desalocados da memória.

### ⚙️ Funcionalidades

* **VisitarPagina** — adiciona uma nova página ao histórico e remove o histórico futuro.
* **Voltar** — retorna para a página anterior, quando disponível.
* **Avancar** — avança para a próxima página, quando disponível.
* **ExibirHistorico** — exibe as páginas armazenadas no histórico.
* **DestruirLista** — libera toda a memória utilizada pela lista ao finalizar o programa.

---

## 🎵 P2 — Player de Música Circular

**Pasta:** `P2-MUSICA`

Simulação de um player de música, inspirado no funcionamento de aplicativos como Spotify e YouTube Music, utilizando uma **Lista Duplamente Encadeada Circular**.

### 💡 Funcionamento

Na lista circular, o último nó aponta novamente para o primeiro nó, enquanto o primeiro nó aponta para o último por meio do ponteiro anterior.

Essa estrutura permite que a navegação pela playlist aconteça continuamente, sem atingir um início ou fim definitivo.

Por exemplo:

```text
        ┌──────────────────────────┐
        ↓                          │
[Música 1] ⇄ [Música 2] ⇄ [Música 3]
        ↑                          │
        └──────────────────────────┘
```

### ⚙️ Funcionalidades

* **AdicionarMusica** — adiciona uma nova música ao final da playlist, mantendo a circularidade.
* **RemoverMusica** — localiza uma música pelo título, ajusta os ponteiros dos nós vizinhos e libera a memória do nó removido.
* **Proxima** — avança para a próxima música da playlist.
* **Anterior** — retorna para a música anterior.
* **ExibirPlaylist** — exibe todas as músicas cadastradas e indica qual está sendo reproduzida atualmente.
* **DestruirLista** — encerra a estrutura circular e libera corretamente todos os nós alocados.

---

# 💻 Como Compilar e Executar

## Pré-requisitos

Para executar os projetos, é necessário possuir um compilador C++ instalado, como:

* GCC / G++
* MinGW
* Visual Studio
* Code::Blocks
* Dev-C++
* Outro compilador compatível com C++

---

## 🌐 Executando o Projeto 1 — Navegador

Entre na pasta do projeto:

```bash
cd P1-NAVEGADOR
```

Compile o programa:

```bash
g++ HistoricoNavegacao.cpp -o HistoricoNavegacao
```

Execute:

### Linux / macOS

```bash
./HistoricoNavegacao
```

### Windows

```bash
HistoricoNavegacao.exe
```

---

## 🎵 Executando o Projeto 2 — Player de Música

Entre na pasta do projeto:

```bash
cd P2-MUSICA
```

Compile o programa:

```bash
g++ TocaMusicas.cpp -o TocaMusicas
```

Execute:

### Linux / macOS

```bash
./TocaMusicas
```

### Windows

```bash
TocaMusicas.exe
```

---

# 🎯 Objetivos Acadêmicos

Os projetos foram desenvolvidos com o objetivo de consolidar conhecimentos relacionados a:

* Estruturas de dados encadeadas;
* Listas duplamente encadeadas;
* Listas duplamente encadeadas circulares;
* Alocação dinâmica de memória;
* Manipulação de ponteiros;
* Inserção e remoção de nós;
* Percurso de estruturas encadeadas;
* Gerenciamento e liberação de memória;
* Aplicação prática de estruturas de dados em problemas do cotidiano.

---

## 👨‍💻 Autor

**Sidney Campos Aragão**

**Bacharelado em Sistemas de Informação — IFSP**

Projeto desenvolvido para fins acadêmicos na disciplina de **Estrutura de Dados**.

---

⭐ **Projeto desenvolvido como parte das atividades acadêmicas do IFSP.**
