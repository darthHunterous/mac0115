import math as mat
dt = 0.25
g = 2

def le_arquivo():
    arquivo = open("entrada.txt", "r")

    lista = arquivo.readlines()
    lista2 = []
    for item in lista:
        lista2.append(item[:-1].split(" "))
    lista2[0][0] = int(lista2[0][0])
    lista2[0][1] = int(lista2[0][1])

    for i in range(1, len(lista2)):
        lista2[i][1] = int(lista2[i][1])
        lista2[i][2] = int(lista2[i][2])
        lista2[i][3] = int(lista2[i][3])

    arquivo.close()
    return lista2

def cria_matriz(m, n):
    matriz = []
    for i in range(m):
        linha = []
        for j in range(n):
            linha.append(" ")
        matriz.append(linha)
    return matriz

def popula_matriz(matriz, pokemons):
    i = 0
    for pokemon in pokemons:
        print(pokemon)
        matriz = preenche_pokemon(matriz, i, pokemon[2], pokemon[3], pokemon[1])
        i += 1
    return matriz

def preenche_pokemon(matriz, id, x, y, raio):
    for i in range(y-raio, y+raio+1):
        for j in range(x-raio, x+raio+1):
            matriz[i][j] = id
    return matriz

def remove_pokemon(matriz, id, pokemons):
    x = pokemons[id][2]
    y = pokemons[id][3]
    raio = pokemons[id][1]

    for i in range(y-raio, y+raio+1):
        for j in range(x-raio, x+raio+1):
            matriz[i][j] = ' '
    return matriz

# imprime a matriz dada
def imprime_matriz(matriz):
    m = len(matriz)
    n = len(matriz[0])
    for i in range(m):
        for j in range(n):
            print(matriz[i][j], end=" ")
        print()
    print()

def atualiza_vy(vy):
    return vy + g * dt

def atualiza_x(x, vx):
    return x + vx * dt

def atualiza_y(y, vy):
    return y + vy * dt + g/2 * dt * dt

def grau_para_radiano(theta):
    return theta * mat.pi / 180

def main():
    lista = le_arquivo()

    m, n = lista[0]    
    pokemons = lista[1:]

    matriz = cria_matriz(m, n)
    matriz = popula_matriz(matriz, pokemons)
    matriz[0][0] = 'a'
    
    pokebolas = int(input("Insira a quantidade de pokébolas disponíveis: "))
    pokemonsLivres = len(pokemons)
    capturado = False
    abscissaCaptura = 0

    while (pokebolas > 0 and pokemonsLivres > 0):
        if not capturado:
            x = int(input("Insira a coordenada x do treinador: "))
            print()
        else:
            x = abscissaCaptura
        y = m-1
        capturado = False

        print(f'{pokebolas} pokébolas disponíveis')
        matriz[y][x] = 'T'
        print("Estado atual do mundo com Pokémons:")
        imprime_matriz(matriz)
        matriz_lancamento = list(map(list, matriz))
        matriz[y][x] = ' '
    
        v = int(input("Insira a velocidade de lançamento: "))
        theta = int(input("Insira o ângulo de lançamento: "))
        theta = grau_para_radiano(theta)

        vx = mat.cos(theta) * v
        vy = -mat.sin(theta) * v
        print()

        while (not capturado and (x >= 0 and x <= n-1) and (y <= m-1)):
            if (round(y) >= 0 and round(x) >= 0):
                if matriz[round(y)][round(x)] != ' ' and matriz[round(y)][round(x)] != 'T':
                    capturado = True
                    pokemonCapturado = matriz[round(y)][round(x)]
                    abscissaCaptura = round(x)
                if matriz_lancamento[round(y)][round(x)] != 'T':
                    matriz_lancamento[round(y)][round(x)] = "."
            x = atualiza_x(x, vx)
            y = atualiza_y(y, vy)
            vy = atualiza_vy(vy)

        pokebolas -= 1
        print("Representação gráfica aproximada do lançamento efetuado:")
        imprime_matriz(matriz_lancamento)
        if capturado:
            matriz = remove_pokemon(matriz, pokemonCapturado, pokemons)
            pokemonsLivres -= 1
            print(f'Um {pokemons[pokemonCapturado][0]} foi capturado!\n')
        else:
            print('O lançamento não capturou Pokémon algum\n')

    if pokemonsLivres == 0:
        print('Parabéns! Todos Pokémons disponíveis foram capturados')
    elif pokebolas == 0:
        print('Infelizmente você ficou sem pokébolas...')

main()