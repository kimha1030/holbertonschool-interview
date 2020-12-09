#!/usr/bin/python3


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.

    Args:
        boxes (list): list of list that contains all the boxes and its keys
    Returns:
        True: If all the boxes can be opened
        False: If all the boxes can not be opened
    """
    list_unlocked = []
    list_numbers = []

    # Por cada elemento de la lista, agrego 0
    for i in boxes:
        list_unlocked.append(0)

    # Cambio el valor de la 1era caja, para indicar que la caja esta abierta
    list_unlocked[0] = 1

    # Recorro la 1er caja y agrego las llaves a la lista
    for j in boxes[0]:
        list_numbers.append(j)

    for num in list_numbers:
        # Si el num es menor que el no# de cajas
        # y el valor es cero en la posicion de num en list_unlocked
        # se cambia a valor 1, indicando que la caja esta abierta
        if (num < len(boxes)) and (list_unlocked[num] == 0):
            list_unlocked[num] = 1

        # Recorro la lista boxes em la posicion de num
        for i in boxes[num]:
            # Si i no esta en list_numbers, lo agrego en esta lista
            if i not in list_numbers:
                list_numbers.append(k)

    # Si encuentro un cero en list_unlocked, es decir,
    # que una caja esta cerrado, retorno False.
    # Si todas las cajas esta abiertas, retorno True
    if 0 in list_unlocked:
        return False
    else:
        return True
