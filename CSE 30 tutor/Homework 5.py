import math

class Complex(object):

    def __init__(self, r, i):
        self.r = r # Real part
        self.i = i # Imaginary part

    def __add__(self, other):
        return Complex(self.r + other.r, self.i + other.i)

    def __sub__(self, other):
        return Complex(self.r - other.r, self.i - other.i)

    def __mul__(self, other):
        return Complex((self.r * other.r - self.i * other.i), 
                       (self.r * other.i + self.i * other.r))
    
    @property
    def modulus_square(self):
        return self.r * self.r + self.i * self.i
    
    @property
    def modulus(self):
        return math.sqrt(self.modulus_square)

    def inverse(self):
        m = self.modulus_square # to cache it
        return Complex(self.r / m, - self.i / m)
    
    def __truediv__(self, other):
        return self * other.inverse()

    def __repr__(self):
        """This defines how to print a complex number."""
        if self.i < 0:
            return "{}-{}i".format(self.r, -self.i)
        return "{}+{}i".format(self.r, self.i)

    def __eq__(self, other):
        """We even define equality"""
        return self.r == other.r and self.i == other.i

class Int(Fraction):

    # YOUR CODE HERE
    def __init__(self, number):
        self.numerator = number
        self.denominator = 1
