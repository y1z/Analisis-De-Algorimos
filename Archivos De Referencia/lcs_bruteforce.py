#LCS Brute force
import time
#Obtiene todas las subsecuencias posibles de cada arreglo de caracteres
def obtenerSubsecuencias(secuencia,numero) :
    # El numero de subsecuencias es (2**n -1)
    n=len(secuencia)
    numerodesubsecuencias = 2**n
    #Creamos un arreglo de arreglos de caracteres para guardar todas las subsecuencias
    subsecuencias = []
    for contador in range( 1, numerodesubsecuencias) :
        #Arreglo para guardar una por una la secuencia
        subsecuencia = []
        for j in range(0, n) :
            if (contador & (1<<j)) :
                #Inserta caracter por caracter en la subsecuencia a insertar
                subsecuencia.append(secuencia[j])
        #Inserta la subsecuencia hecha a toda la lista de las subsecuencias
        subsecuencias.append(subsecuencia)
    #Devuelve todas las subsecuencias posibles
    return subsecuencias
	
def compararSubsecuencias(subsecuencias1,subsecuencias2) :
    lcs = []
    for i in range(0,len(subsecuencias1)):
        for j in range(0,len(subsecuencias2)):
            if subsecuencias1[i] == subsecuencias2[j]:
                if len(lcs) < len(subsecuencias1[i]):
                    lcs = subsecuencias1[i]
    return lcs

#Main
print("Starting")
secuencia1 = "TTCGCATCGGGTTG" #Primera secuencia
secuencia2 = "TGACCGTGTGTCACG" #Segunda secuencia
subsecuencias1 = obtenerSubsecuencias(secuencia1,1) #Obtiene todas las subsecuencias de la secuencia 1
subsecuencias2 = obtenerSubsecuencias(secuencia2,2) #Obtiene todas las subsecuencias de la secuencia 2
start = time.time()  # Empieza a contar el tiempo
lcs = compararSubsecuencias(subsecuencias1, subsecuencias2) #Comparara una por una todas las subsecuencias de la secuencia 1 y 2
print("---BRUTE FORCE---")
print ("La subsecuencia mas larga comun de " + secuencia1 + " y de " + secuencia2 + " es " + "".join(lcs))
print("\nTerminado en " + str(time.time() - start) + " segundos!\n\n")

raw_input()
