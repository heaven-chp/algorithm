import sys

if __name__ == "__main__":
    N, M = map(int, sys.stdin.readline().split())

    pokemonEncyclopediaInt = {}
    pokemonEncyclopediaString = {}

    count = 0
    for i in range(N):
        count += 1
        name = sys.stdin.readline().strip()
        pokemonEncyclopediaInt[str(count)] = name
        pokemonEncyclopediaString[name] = count

    for i in range(M):
        question = sys.stdin.readline().strip()
        if question.isdecimal():
            print(pokemonEncyclopediaInt[question])
        else:
            print(pokemonEncyclopediaString[question])
