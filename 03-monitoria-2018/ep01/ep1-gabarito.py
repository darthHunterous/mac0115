def imprimeEstado(t, vy, xb, yb):
    print('t={:4d}    vy={:4d}    x={:4d}    y={:4d}'.format(t, vy, xb, yb))

def atualizaTempo(t):
    return t + 1

def atualizaXpokebola(xb, vx, dt):
    return xb + vx * dt

def atualizaYpokebola(yb, vy, dt, g):
    return yb + vy * dt - (g // 2 * dt ** 2)

def atualizaVelocidadeYpokebola(vy, g, dt):
    return vy - g * dt

def verificaContinuacao(yb, xb, xp):
    return yb > 0 and xb < xp

def main():
    g = int(input('Digite o valor da gravidade: '))
    xp = int(input('\nDigite a coordenada x (inteiro >= 0) do pokemon: '))
    yp = int(input('Digite a coordenada y (inteiro >= 0) do pokemon: '))

    # Velocidade horizontal constante
    vx = 1
    # Passo de tempo constante
    dt = 1

    for tentativa in range(1, 4):
        print(f'\nTentativa {tentativa}')
        xb = int(input('\nDigite a coordenada x (inteiro >= 0) do treinador: '))
        yb = int(input('Digite a coordenada y (inteiro >= 0) do treinador: '))
        vy = int(input('Digite a componente y da velocidade de lancamento: '))
        t = int(0)
        imprimeEstado(t, vy, xb, yb)
        continuar = True
        while continuar:
            xb = atualizaXpokebola(xb, vx, dt)
            yb = atualizaYpokebola(yb, vy, dt, g)
            vy = atualizaVelocidadeYpokebola(vy, g, dt)
            t = atualizaTempo(t)
            imprimeEstado(t, vy, xb, yb)
            continuar = verificaContinuacao(yb, xb, xp)
        if yb == yp:
            print('\nA pokebola atingiu o pokemon.')
        else:
            print('\nA pokebola nao atingiu o pokemon.')

main()