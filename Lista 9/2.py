def sum_weights_in_warehouses(M, warehouses, queries):
    # Tworzenie listy przechowującej wagi towarów w poszczególnych magazynach
    warehouse_weights = [sum(warehouse) for warehouse in warehouses]

    result = []
    for query in queries:
        if query[0] == 'K':  # Zapytanie kontrola
            result.append(' '.join(map(str, warehouse_weights)))
        elif query[0] == 'R':  # Zapytanie relokacja
            mz, md, tp, tk = map(int, query[1:])
            mz -= 1  # Indeksy od 1 do M, a listy w Pythonie indeksowane są od 0
            md -= 1

            # Pobranie towarów z magazynu źródłowego
            items_to_move = warehouses[mz][tp - 1:tk]

            # Usunięcie przenoszonych towarów z magazynu źródłowego
            warehouses[mz] = warehouses[mz][:tp - 1] + warehouses[mz][tk:]

            # Dodanie przenoszonych towarów do magazynu docelowego
            warehouses[md] += items_to_move

            # Aktualizacja wagi magazynów
            warehouse_weights[mz] = sum(warehouses[mz])
            warehouse_weights[md] = sum(warehouses[md])

    return result


# Wczytanie danych wejściowych
M, Q = map(int, input().split())
warehouses = []
for _ in range(M):
    warehouse = list(map(int, input().split()))
    warehouses.append(warehouse[1:])

queries = []
for _ in range(Q):
    query = input().split()
    queries.append(query)

# Obliczenie i wyświetlenie wyniku
result = sum_weights_in_warehouses(M, warehouses, queries)
for res in result:
    print(res)
