import time
#LCS Brute force
def lcs(X, Y, m, n):
    L = [[0 for x in range(n+1)] for x in range(m+1)]

    # Construye L[m+1][n+1]
    # Este L[i][j] contiene el tamaño de la LCS de X[0..i-1] y Y[0..j-1]
    for i in range(m+1):
        for j in range(n+1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i-1] == Y[j-1]:
                L[i][j] = L[i-1][j-1] + 1
            else:
                L[i][j] = max(L[i-1][j], L[i][j-1])

    index = L[m][n]
    lcs = [""] * (index+1)
    lcs[index] = ""

    # Empezando desde la derecha hasta abajo llendo hacia la esquina uno por uno
    # de los caracteres guardados en lcs
    i = m
    j = n
    while i > 0 and j > 0:
        # Si el caracter en x y en y es el mismo, quiere decir que está en la LCS
        if X[i-1] == Y[j-1]:
            lcs[index-1] = X[i-1]
            i-=1
            j-=1
            index-=1
        # Si no es el mismo, entonces encuentra el mas largo de dos
        # y va en la direccion del valor mas grande
        elif L[i-1][j] > L[i][j-1]:
            i-=1
        else:
            j-=1

    print ("La subsecuencia mas larga comun de " + X + " y de " + Y + " es " + "".join(lcs))

# Main
X = "TTCGCATCGGGTTG" #Primera secuencia
Y = "TGACCGTGTGTCACG" #Segunda secuencia
m = len(X)
n = len(Y)
start = time.time()  # Empieza a contar el tiempo
print("---Dynamic Programming---")
lcs(X, Y, m, n) #Encuentra la subsecuencia mas larga comun de entre las dos secuencias
print("\nTerminado en " + str(time.time() - start) + " segundos!\n\n")
