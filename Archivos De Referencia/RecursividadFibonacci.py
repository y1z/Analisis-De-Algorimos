#Recursividad de Fibonacci - Efraín Alberto Padilla Zepeda
import time

def FibonacciRecursiva(n):
    if n<=1:
        return n;
    else:
        return FibonacciRecursiva(n-1) + FibonacciRecursiva(n-2);

def FibonacciNoRecursiva(n):
    x=0
    n1=0
    n2=1
    if n<=1:
        return n;
    else:
        for x in range(1,n):
            f=n1+n2;
            n1=n2;
            n2=f;
            x=x+1
        return f;

while(1):
    numero = int(input("Introduce el número en la secuencia de Fibonacci que quieres calcular: "))
    print("El numero en la secuencia de Fibonacci es: " + str(numero));
    start= time.time(); #Empieza a contar el tiempo
    print("\nEl valor correspondiente con algoritmo de Fibonnaci NO Recursivo es: " + str(FibonacciNoRecursiva(numero))+ "\nTerminado en "+str(time.time() - start)+" segundos!\n");
    start= time.time(); #Empieza a contar el tiempo
    print("\nEl valor correspondiente con algoritmo de Fibonnaci Recursivo es: " + str(FibonacciRecursiva(numero)) + "\nTerminado en "+str(time.time() - start)+" segundos!\n");
    print("\n------------------------------------------------------\n")
