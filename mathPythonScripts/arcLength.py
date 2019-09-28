"""
Author: Peter Watson

script to calculate arc length
uses a summation instead of finding the derivative of f(x) and using the traditional formula


uses a summation approximation where the length of the curve is estimated by the 
length of the hypotenuses of right triangles, where one leg (parallel to x axis) is delta_x 
and one leg (parallel to y axis) is (f(x sub i) - f(x sub i - 1))

currently accurate to 7 significant figures -- note: prints out number rounded to 7 decimal places
"""

import math

def f(x):
    return (x ** 2)

def arcLength(a, b, f):
    n = 10000000               #as n increases, accuracy of estimate increases 
    delta_x = (b - a) / n
    length = 0.0
    #summation of square root of (delta_x^2 + (f(x sub i) - f(x sub i - 1))^2)
    #equivalent statement: summation of square root of (delta_x^2 + delta_y^2)
    for i in range (1, n): 
        length = length + (((delta_x ** 2) + ((f(a+ (delta_x * i)) - f(a + (delta_x * (i - 1)))) ** 2)) ** (1 / 2))
        
    print (length)
    roundedLength = round(length, 7)
    print ("length rounded to 7 decimal places:")
    print (roundedLength)

arcLength(2, 5, f)