lista = []

for i in range(10):
  lista.append(int(input(f'Insira o {i + 1}º número: ')))

soma = sum(lista)
media = soma/len(lista)
qtd_acima_media = 0
qtd_abaixo_media = 0

for numero in lista:
  if numero > media:
    qtd_acima_media += 1
  elif numero < media:
    qtd_abaixo_media += 1

print(f'Média: {media}')
print(f'Acima da média: {qtd_acima_media}')
print(f'Abaixo da média: {qtd_abaixo_media}')
