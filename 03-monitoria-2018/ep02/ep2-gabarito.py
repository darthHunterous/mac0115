GRAVIDADE = 9.81
EPSILON = 0.01
DELTA_T = 0.01
PI = 3.14159265358979323846

# {0:.4f}
def converteGrau(grau):
    return grau * PI / 180

def seno(theta):
    theta = converteGrau(theta)
    serie = theta
    termo = theta
    i = 2

    while (abs(termo) > 1E-10):
        termo *= -1 * theta * theta / (i * (i + 1))
        serie += termo
        i += 2

    return serie

def cosseno(theta):
    theta = converteGrau(theta)
    serie = 1
    termo = 1
    i = 1

    while (abs(termo) > 1E-10):
        termo *= -1 * theta * theta / (i * (i + 1))
        serie += termo
        i += 2

    return serie

def raiz_quadrada(x):
    if (x == 0):
        return 0.0

    r1 = x
    r2 = 1 / 2 * (r1 + x / r1)

    while (abs(r2 - r1) > 1E-10):
        r1 = r2
        r2 = 1 / 2 * (r1 + x / r1)

    return r2

def atualiza_posicao(x, y, vx, vy):
    x += vx * DELTA_T
    y += vy * DELTA_T - GRAVIDADE * DELTA_T ** 2 / 2

    return [x, y]

def atualiza_velocidade(vx, vy):
    vy -= GRAVIDADE * DELTA_T

    return [vx, vy]

def distancia_pontos(x_1, y_1, x_2, y_2):
    return raiz_quadrada((x_2 - x_1) ** 2 + (y_2 - y_1) ** 2)

def ha_colisao(x_pokebola, y_pokebola, x_pokemon, y_pokemon, r):
    if (distancia_pontos(x_pokebola, y_pokebola, x_pokemon, y_pokemon) > r):
        return False
    return True

def simula_lancamento(x_pokebola, y_pokebola, v_lancamento, angulo_lancamento, x_pokemon, y_pokemon, r):
    continuar = True
    vx = v_lancamento * cosseno(angulo_lancamento)
    print(vx)
    vy = v_lancamento * seno(angulo_lancamento)
    print(vy)

    while (continuar):
        print(distancia_pontos(x_pokebola, y_pokebola, x_pokemon, y_pokemon))
        x_pokebola = atualiza_posicao(x_pokebola, y_pokebola, vx, vy)[0]
        y_pokebola = atualiza_posicao(x_pokebola, y_pokebola, vx, vy)[1]
        vx = atualiza_velocidade(vx, vy)[0]
        vy = atualiza_velocidade(vx, vy)[1]

        capturado = ha_colisao(x_pokebola, y_pokebola, x_pokemon, y_pokemon, r)

        if y_pokebola < EPSILON or capturado:
            continuar = False

    return distancia_pontos(x_pokebola, y_pokebola, x_pokemon, y_pokemon) - r
# 0.8948932535929719 deve retornar como raiz 0.945987977509742
def main():
    print(seno(0))
    print(seno(30))
    print(seno(45))
    print(cosseno(0))
    print(cosseno(45))
    print(cosseno(60))
    print(raiz_quadrada(2))
    print(raiz_quadrada(4))
    print(raiz_quadrada(0.8948932535929719))
    x_pokemon = int(input("Digite a coordenada x do pokemon: "))
    y_pokemon = int(input("Digite a coordenada y do pokemon: "))
    r = float(input("Digite o raio do pokemon (> 0) em metros: "))

    capturado = False
    pokebolas = 3
    tentativa = 1

    while (not capturado and pokebolas):
        print()
        print(f"Tentativa {tentativa}")
        x_pokebola = int(input("\tDigite a coordenada x do treinador: "))
        y_pokebola = int(input("\tDigite a coordenada y do treinador: "))
        v_lancamento = int(input("\tDigite a velocidade do lancamento em m/s: "))
        angulo_lancamento = int(input("\tDigite o angulo de lancamento em graus: "))
        print()

        distancia = simula_lancamento(x_pokebola, y_pokebola, v_lancamento, angulo_lancamento, x_pokemon, y_pokemon, r)
        if distancia <= r:
            capturado = True

        if capturado:
            print("A pokebola atingiu o pokemon")
        else:
            print(f"A pokebola nao atingiu o pokemon por {distancia} metros")

        tentativa += 1
        pokebolas -= 1

main()