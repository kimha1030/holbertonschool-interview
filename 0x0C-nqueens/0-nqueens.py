#!/usr/bin/python3
""" Task 0. N queens"""
import sys


def res_nq(num, val_r, list_sol):
    if (val_r == num):
        print(list_sol)
    else:
        for val_c in range(num):
            pos = [val_r, val_c]
            chk = check_pos(pos, list_sol)
            if chk:
                list_sol.append(pos)
                res_nq(num, val_r + 1, list_sol)
                list_sol.remove(pos)

def check_pos(pos, list_sol):
    for ele in list_sol:
        con1 = ele[1] == pos[1]
        con2 = (ele[0] + ele[1] == pos[0] + pos[1])
        con3 = (ele[0] - ele[1] == pos[0] - pos[1])
        if con1 or con2 or con3:
            return False
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        num = int(sys.argv[1])
    except:
        print("N must be a number\n")
        exit(1)
    if num < 4:
        print("N must be at least 4.\n")
        exit(1)
    list_sol = []
    res_nq(num, 0, list_sol)
