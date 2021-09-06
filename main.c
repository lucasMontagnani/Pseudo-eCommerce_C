#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para manipular strings
#include <locale.h> //para caracteres especiais (configura a região)
#include <windows.h> //permite alterações necessária no SO

void menuFuncionario();
void login();
void addCarrinho();
void listarProdutos(int ss);
void menuCliente();
void removerCarrinho();
void finalizarCompra();
void atualizarProduto();


struct Produto{
    int id;
    char nome[20];
    float preco;
    int quantidade;
};

struct Produto products_list[20];
int product_counter = 0;

struct Car{
    int cd;
    int qtd;
};

struct Car carrinho_list[20];
int car_counter = 0;

struct Historic{
    int cd;
    int qtd;
};

struct Historic pedidos[20];
int pedidos_counter = 0;

int compras[10];
int compras_counter = 0;

void inicializa(){

    strcpy(products_list[product_counter].nome,"Caderno");
    products_list[product_counter].preco = 10.90;
    products_list[product_counter].quantidade = 8;
    products_list[product_counter].id = product_counter+1;
    product_counter++;

    strcpy(products_list[product_counter].nome,"Estojo");
    products_list[product_counter].preco = 5.50;
    products_list[product_counter].quantidade = 12;
    products_list[product_counter].id = product_counter+1;
    product_counter++;

    strcpy(products_list[product_counter].nome,"Caneta");
    products_list[product_counter].preco = 2.0;
    products_list[product_counter].quantidade = 20;
    products_list[product_counter].id = product_counter+1;
    product_counter++;
}

void space(){
    /*
    for(int i=0; i<20;i++){
        printf("\n");   //para NetBeans
    }
    */

    system("cls");    //para CodeBlocks
}

void cadastrarProduto(){
    char test[20];
    char op;
    printf("CADASTRAR PRODUTO\n");
    printf("Insira o nome do produto:\n");
    //fflush(stdin);
    //fgets(products_list[product_counter].nome, 20, stdin);
    scanf("%s",&test);
    strcpy(products_list[product_counter].nome,test);
    printf("Insira o preço do produto:\n");
    scanf("%f",&products_list[product_counter].preco);
    printf("Insira a quantidade:\n");
    scanf("%i",&products_list[product_counter].quantidade);

    products_list[product_counter].id = product_counter+1;
    product_counter++;
    //printf("Descrição: %s\n",products_list[product_counter-1].nome);

    printf("O produto foi cadastrado com sucesso! Precione qualquer tecla para continuar...");
    getchar();
    getchar();
    space();

    menuFuncionario();
}

void listarProdutos(int ss){
    if(product_counter>0){
        printf("Produtos:\n\n");
        for(int i=0;i<product_counter;i++){
            printf("Produto %i:\n",products_list[i].id);
            printf("Descrição: %s\n",products_list[i].nome);
            printf("Preço: %.2f\n",products_list[i].preco);
            printf("Em estoque: %i\n",products_list[i].quantidade);
            printf("----------------------------------------------\n");
        }
    }else{
        printf("Ainda não há produtos cadastrados no sistema.");
    }



    if(ss==1){
        addCarrinho();
    }else if(ss==2){
        atualizarProduto();
    }

}

void dadosProduto(){
    int codigo;
    printf("Digite o código do produto que deseja consultar:\n");
    scanf("%i",&codigo);
    while(codigo>product_counter || codigo<=0){
        printf("Código de produto invalido.\n");
        printf("Digite o código do produto que deseja consultar:\n");
        scanf("%i",&codigo);
    }
    codigo--;
    printf("Produto %i: %s\n",products_list[codigo].id,products_list[codigo].nome);
    printf("Preço: %.2f\n",products_list[codigo].preco);
    printf("Em estoque: %i\n",products_list[codigo].quantidade);

    printf("Pressione qualquer tecla para continuar...");
    getchar();
    getchar();
    space();
    menuFuncionario();
}

void atualizarProduto(){
    int t=0, cd;
    char test, nome[20];
    printf("Deseja alterar atualizar algum produto? (S/N)\n");
    scanf(" %c",&test);
    if(test=='s' || test=='S'){ //caracteres usam aspas simples
        printf("Insira o código do produto que deseja atualizar:\n");
        scanf("%i",&cd);
        while(cd>product_counter || cd<=0){
            printf("Código de produto invalido.\n");
            printf("Insira o código do produto que deseja atualizar:\n");
            scanf("%i",&cd);
        }

        printf("Escolha uma das opções para modificar no produto:\n");
        printf("1 - Atualizar a Quantidade no Estoque \n");
        printf("2 - Atualizar o Preço do Produto \n");
        printf("3 - Atualizar o Nome do Produto \n");
        printf("4 - Atualizar tudo \n");
        scanf("%i",&t);

        if(t==1){
            printf("Insira uma nova quantidade para este produto:\n");
            scanf("%i",&products_list[cd-1].quantidade);

        }else if(t==2){
            printf("Insira um novo preço para este produto:\n");
            scanf("%f",&products_list[cd-1].preco);

        }else if(t==3){
            printf("Insira um novo nome para este produto:\n");
            scanf("%s",&nome);
            strcpy(products_list[cd-1].nome,nome);
        }else if(t=4){
            printf("Insira um novo nome para este produto:\n");
            scanf("%s",&nome);
            strcpy(products_list[cd-1].nome,nome);

            printf("Insira um novo preço para este produto:\n");
            scanf("%f",&products_list[cd-1].preco);

            printf("Insira uma nova quantidade para este produto:\n");
            scanf("%i",&products_list[cd-1].quantidade);
        }

        printf("Produto atualizado com sucesso! Precione qualquer tecla para continuar...\n");
        getchar();
        getchar();
        space();
    }
    space();
    menuFuncionario();
}

void menuFuncionario(){
    int option;
    printf("MENU DE OPÇÕES:\n");
    printf("1 - Cadastrar Produto \n");
    printf("2 - Listar Produtos \n");
    printf("3 - Dados do Produto (por ID) \n");
    printf("4 - Encerrar Sessão (Logout)\n");
    printf("5 - Sair do sistema\n");
    printf("Escolha uma das opções a cima:\n");
    scanf("%i",&option);

    space();
    if(option == 1){
        cadastrarProduto();
    }else if(option == 2){
        listarProdutos(2);
    }else if(option == 3){
        dadosProduto();
    }else if(option == 4){
        login();
    }else if(option == 5){
        //nada :)
    }

}

void addCarrinho(){
    char test,test2;
    int cd,qtd=0,ok=1;
    printf("Deseja adicionar algum produto ao carrinho? (S/N)\n");
    scanf(" %c",&test);
    if(test=='s' || test=='S'){ //caracteres usam aspas simples
        printf("Insira o código do produto que deseja comprar:\n");
        scanf("%i",&cd);
        while(cd>product_counter || cd<=0){
            printf("Código de produto invalido.\n");
            printf("Insira o código do produto que deseja comprar:\n");
            scanf("%i",&cd);
        }
        //verificar se o cofigo do produto existe entre os produtos da loja (validação)

        for(int i=0;i<car_counter;i++){
            if(carrinho_list[i].cd==cd){
                int safe=0;
                ok=0;// veridicar se já há o produto selecionado no carrinho
                printf("Este produto já está no carrinho, deseja aumentar a quantidade? (S/N)\n");
                scanf(" %c",&test);
                if(test=='s' || test=='S'){
                    printf("Insira a quantidade que deseja incrementar:\n");
                    scanf("%i",&qtd);
                    safe = carrinho_list[i].qtd;
                    safe= safe + qtd;

                    while(safe>products_list[i].quantidade){
                        safe = carrinho_list[i].qtd;
                        printf("Não há no estoque a quantidade selecionada, insira um igual ou menor a presente no estoque:");
                        scanf("%i",&qtd);
                        safe= safe + qtd;
                    }
                    carrinho_list[i].qtd = safe;
                }
            }
        }
        if(ok==1){
            carrinho_list[car_counter].cd=cd;
            printf("Quantas unidades deste produto deseja comprar?\n");
            scanf("%i",&qtd);
            carrinho_list[car_counter].qtd=qtd;


            while(qtd>products_list[cd-1].quantidade){
                printf("Não há no estoque a quantidade selecionada, insira um igual ou menor a presente no estoque:");
                scanf("%i",&qtd);
                carrinho_list[car_counter].qtd=qtd;
            }

            car_counter++;

            printf("Produto adicionado no carrinho com sucesso!  Precione qualquer tecla para continuar...\n");
            getchar();
            getchar();
            space();
        }

    }
    //printf("%i",products_list[cd-1].quantidade);
    space();
    menuCliente();
}

void mostrarCarrinho(){
    if(car_counter>0){
        printf("Carrinho:\n\n");
        for(int i=0;i<car_counter;i++){
            for(int j=0; j<product_counter;j++){
                if(j==(carrinho_list[i].cd-1)){
                    printf("Item %i:\n",i+1);
                    printf("Código do Produto %i:\n",products_list[j].id);
                    printf("Descrição: %s\n",products_list[j].nome);
                    printf("Preço: %.2f\n",products_list[j].preco);
                    printf("Quantidade no carrinho: %i\n",carrinho_list[i].qtd);
                    printf("Sub-total: %.2f\n",products_list[j].preco*carrinho_list[i].qtd);//PREÇO DO PRODUTO X QTD DO CARRINHO
                    printf("----------------------------------------------\n");
                }
            }
        }
        //eixibir total
        int op=0;
        printf("Opções:\n");
        printf("1 - Remover algum item do carrinho\n");
        printf("2 - Finalizar compra\n");
        printf("3 - Voltar ao menu e continuar comprando\n");
        printf("Selecione uma das opções acima:\n");
        scanf("%i",&op);
        if(op==1){
            removerCarrinho();
        }else if(op==2){
            finalizarCompra();
        }else{
            space();
            menuCliente();
        }
    }else{
        printf("Ainda não há produtos no carrinho. Precione qualquer tecla para continuar...\n");
        getchar();
        getchar();
        space();
        menuCliente();
    }

}

void removerCarrinho(){
    int del=0,id=0,ok=0;
    printf("Digite o código do produto que deseja remover do carrinho:\n");
    scanf("%i",&del);
    for(int i=0;i<car_counter;i++){
        if(carrinho_list[i].cd==del){
            //printf("%i",carrinho_list[i].qtd);
            id = i;
        }
    }
    //printf("%i",id);
    for(int i=id;i<car_counter;i++){
        if(i+1<car_counter){
            carrinho_list[i].cd=carrinho_list[i+1].cd;
            carrinho_list[i].qtd=carrinho_list[i+1].qtd;
        }

    }
    car_counter--;
    space();
    mostrarCarrinho();
}

void finalizarCompra(){
    compras[compras_counter]= car_counter;

    if(car_counter>0){
        for(int i=0;i<car_counter;i++){
            for(int j=0; j<product_counter;j++){
                if(j==(carrinho_list[i].cd-1)){
                    products_list[j].quantidade = products_list[j].quantidade - carrinho_list[i].qtd;

                }
            }
            //passar do carrinho para o historico
            pedidos[pedidos_counter].cd = carrinho_list[i].cd;
            pedidos[pedidos_counter].qtd = carrinho_list[i].qtd;
            pedidos_counter++;

        }
    }

    compras_counter++;
    car_counter = 0;//limpar do carrinho
    printf("Compra efetuada com sucesso! Obrigado pela preferencia, volte sempre!\n");
    printf("Precione qualquer tecla para continuar...\n");
    getchar();
    getchar();
    space();
    menuCliente();
}

void vizualizarHistorico(){
    /*
    for(int i=0;i<pedidos_counter;i++){
        printf("Código do Produto: %i",pedidos[i].cd);
        printf("Código do Quantidade: %i",pedidos[i].qtd);
    }*/

    if(pedidos_counter>0){
        int counter=0,k=0;
        float total=0;
        printf("Histórico de Pedidos:\n\n");
        printf("========== Compra 1 ==========\n");
        for(int i=0;i<pedidos_counter;i++){
            if(compras[k]==counter){
                k++;
                printf("\n========== Compra %i ==========\n",k+1);
                counter=0;
            }
            for(int j=0; j<product_counter;j++){
                if(j==(pedidos[i].cd-1)){
                    printf("Item %i:\n",i);
                    printf("Código do Produto %i:\n",products_list[j].id);
                    printf("Descrição: %s\n",products_list[j].nome);
                    printf("Preço: %.2f\n",products_list[j].preco);
                    printf("Quantidade no carrinho: %i\n",pedidos[i].qtd);
                    printf("Sub-total: %.2f\n",products_list[j].preco*pedidos[i].qtd);//PREÇO DO PRODUTO X QTD DO HISTORICO
                    total = total + products_list[j].preco*pedidos[i].qtd;
                    printf("----------------------------------------------\n");
                    if(compras[k]==counter+1){
                        printf("Valor Total = %.2f\n",total);
                        total=0;
                    }
                    counter++;
                }
            }
        }
        printf("\nPrecione qualquer tecla para continuar...\n\n");
        getchar();
        getchar();
        space();
    }else{
        printf("Ainda não há pedidos no histórico. Precione qualquer tecla para continuar...\n");
        getchar();
        getchar();
        space();

    }
    menuCliente();
}

void menuCliente(){
    int option;
    printf("MENU DE OPÇÕES:\n");
    printf("1 - Exibir/Comprar Produtos \n");
    printf("2 - Exibir Carrinho\n");
    printf("3 - Historico de Compras\n");
    printf("4 - Encerrar Sessão (Logout)\n");
    printf("5 - Sair do sistema\n");
    printf("Escolha uma das opções a cima:\n");
    scanf("%i",&option);

    space();
    if(option == 1){
        listarProdutos(1);
    }else if(option == 2){
        mostrarCarrinho();
    }else if(option == 3){
        vizualizarHistorico();
    }else if(option == 4){
        login();
    }else if(option == 5){
        //nada :)
    }
}

void login(){
    int passe;
    printf("Selecione um usuário para acessar o sistema:\n");
    printf("1 - Cliente\n");
    printf("2 - Funcionario\n");
    printf("3 - Sair do Sistema \n");
    scanf("%i",&passe);
    space();
    if(passe==1){
        menuCliente();
    }else if(passe==2){
        menuFuncionario();
    }else if(passe==3){
        //nada:)
    }else{
        login();
        //VALIDAÇÃO PASSANDO PARAMETRO
    }

}

int main(){
    system("color 0a");
    setlocale(LC_ALL, "Portuguese"); //configura o idioma da região mas apenas funciona com printf

    inicializa();
    login();
}

