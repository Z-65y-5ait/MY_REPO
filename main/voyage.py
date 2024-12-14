def hotel_frais(n):
    return n*90
def location_voiture_frais(j):
    if j >= 3 and j < 7:
        return ((35*j)-20)
    elif j >= 7:
        return ((35*j)-50)
    else:
        return (35*j)
def vol_frais(v):
    if v == 'Marrakech':
        return 35
    elif v == 'Paris':
        return 200
    elif v == 'Oran':
        return 78
    elif v == 'Carthage':
        return 182
    elif v == 'Dakar':
        return 25
    else:
        return NameError
def voyage_frais(v,j,n):
    N=hotel_frais(n)
    J=location_voiture_frais(j)
    V=vol_frais(v)
    return print(N+J+V) 
