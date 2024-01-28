# Analisador-Lexico
Analisador léxico para Pascal desenvolvido em C para a disciplina de Compiladores do curso de Ciência da Computação da UNESP - Bauru. Cada linha de código será analisada e os identificadores da linguagem Pascal serão identificados na saída do programa.

## Exemplo de funcionamento
Dado o programa em Pascal a seguir:

```pascal
1 program teste;
2 uses crt;
3 var a: Integer;
4 begin
5     a := 1;
6     writeln("Hello World");
7 end.
```

A seguinte saída será escrita no terminal:

1       PALAVRA_RESERVADA_PROGRAM IDENTIFICADOR_TESTE OPERADOR_;  
2       IDENTIFICADOR_USES IDENTIFICADOR_CRT OPERADOR_;  
3       PALAVRA_RESERVADA_VAR IDENTIFICADOR_A OPERADOR_: IDENTIFICADOR_INTEGER OPERADOR_;  
4       PALAVRA_RESERVADA_BEGIN  
5       IDENTIFICADOR_A OPERADOR_:= NUMERO_1 OPERADOR_;  
6       IDENTIFICADOR_WRITELN OPERADOR_( IDENTIFICADOR_HELLO IDENTIFICADOR_WORLD OPERADOR_) OPERADOR_;  
7       PALAVRA_RESERVADA_END OPERADOR_.  
