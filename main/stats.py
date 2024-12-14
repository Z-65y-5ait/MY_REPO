from math import sqrt
def somme(a,b,c,d,e):
    return print(a+b+c+d+e)
def moyenne(a,b,c,d,e):
    return print((a+b+c+d+e)/5) 
def variance(a,b,c,d,e):
    return print((pow(a-moyenne,2)+pow(b-moyenne,2)+pow(c-moyenne,2)+pow(d-moyenne,2)+pow(e-moyenne,2))/5)
def ecart_type(a,b,c,d,e):
    return  print(sqrt((pow(a-somme,2)/5)+(pow(b-somme,2)/5)+(pow(c-somme,2)/5)+(pow(d-somme,2)/5)+(pow(e-somme,2)/5)/4))
def coefficient_de_variation():
    return print((ecart_type/moyenne)*100)
