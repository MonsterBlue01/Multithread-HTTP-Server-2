def fibonacci_generator():
    """Generates all Fibonacci numbers."""
    # YOUR CODE HERE
    a = 0
    b = 1
    while True:
        b = a + b
        yield a
        yield b
        a = a + b

def prime_number_generator():
    """This generator returns all prime numbers."""
    # YOUR CODE HERE
    a = 1
    while True:
        a += 1
        for b in range(2, int(a/2) + 1):
            if a % b == 0:
                break
        else:
            yield a

if __name__ == '__main__':
    r = []
    for n in fibonacci_generator():
        r.append(n)
        if n > 100:
            break
    assert r == [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144]
    print(r)

    initial_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    idx = 0
    for p in prime_number_generator():
        assert p == initial_primes[idx]
        idx += 1
        if idx == len(initial_primes):
            break

    c = 0
    for n in prime_number_generator():
        if n > 900:
            c += 1
        if n in [32, 88, 99, 231, 1000]:
            print("bad:", n)
            raise Exception()
        if n > 1000:
            break
    assert c == 15
