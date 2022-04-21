class SockDrawer(object):

    def __init__(self):
        self.drawer = []

    def add_sock(self, color):
        """Adds a sock of the given color to the drawer."""
        self.drawer.append(color)

    def get_pair(self, color):
        """Returns False if there is no pair of the given color, and True
        if there is.  In the latter case, it removes the pair from the drawer."""
        if self.drawer.count(color) >= 2:
            self.drawer.remove(color)
            self.drawer.remove(color)
            return True
        else:
            return False

    @property
    def available_colors(self):
        """Lists the colors for which we have at least two socks available."""
        colors = set()
        for el in self.drawer:
            if self.drawer.count(el) >= 2:
                colors.add(el)
        return colors

#@title Let's define a testing helper.

def check_equal(x, y, msg=None):
    if x != y:
        if msg is None:
            print("Error:")
        else:
            print("Error in", msg, ":")
        print("    Your answer was:", x)
        print("    Correct answer: ", y)
    assert x == y, "%r and %r are different" % (x, y)

def test_drawer(c):
    """Tests a drawer class c."""
    d = c()
    d.add_sock('red')
    d.add_sock('red')
    d.add_sock('red')
    d.add_sock('green')
    check_equal(d.available_colors, {'red'})
    check_equal(d.get_pair('red'), True)
    check_equal(d.get_pair('green'), False)
    check_equal(d.get_pair('red'), False)
    d.add_sock('blue')
    d.add_sock('blue')
    d.add_sock('blue')
    d.add_sock('red')
    check_equal(d.available_colors, {'red', 'blue'})

class SmartDrawer(object):

    def __init__(self):
        self.socks = defaultdict(int)

    def add_sock(self, color):
        self.socks[color] += 1

    def get_pair(self, color):
        if self.socks[color] > 1:
            self.socks[color] -= 2
            return True
        else:
            return False

    @property
    def available_colors(self):
        return {c for c, n in self.socks.items() if n > 1}

class MehAD(dict):

    def __add__(self, other):
        d = MehAD()
        other_keys = set(other.keys()) if isinstance(other, dict) else set()
        for k in set(self.keys()) | other_keys:
            d[k] = self.get(k, 0) + (other.get(k, 0) if isinstance(other, dict) else other)
        return d

class AD(dict):

    def __add__(self, other):
        return AD._binary_op(self, other, lambda x, y: x + y, 0)

    def __sub__(self, other):
        return AD._binary_op(self, other, lambda x, y: x - y, 0)

    @staticmethod
    def _binary_op(left, right, op, neutral):
        r = AD()
        l_keys = set(left.keys()) if isinstance(left, dict) else set()
        r_keys = set(right.keys()) if isinstance(right, dict) else set()
        for k in l_keys | r_keys:
            # If the right (or left) element is a dictionary (or an AD),
            # we get the elements from the dictionary; else we use the right
            # or left value itself.  This implements a sort of dictionary
            # broadcasting.
            l_val = left.get(k, neutral) if isinstance(left, dict) else left
            r_val = right.get(k, neutral) if isinstance(right, dict) else right
            r[k] = op(l_val, r_val)
        return r

### Exercise: Implement the sock drawer class using ADs

class ADSockDrawer(object):

    def __init__(self):
        self.drawer = AD()

    def add_sock(self, color):
        """Adds a sock of the given color to the drawer.
        Do it in one line of code."""
        # YOUR CODE HERE
        self.drawer[color] = self.drawer[color] + 1 if color in self.drawer.keys() else 1

    def get_pair(self, color):
        """Returns False if there is no pair of the given color, and True
        if there is.  In the latter case, it removes the pair from the drawer.
        Do it in 5 lines of code or less."""
        # YOUR CODE HERE
        if self.drawer[color] < 2:
          return False
        else:
          self.drawer[color] -= 2
          return True

    @property
    def available_colors(self):
        """Lists the colors for which we have at least two socks available.
        Do it in 1 line of code."""
        # YOUR CODE HERE
        return (self.drawer >= 2).filter().keys()
