class Shape:
    def __init__(self):
        self.color = "black"
        self.p = "Shape >>"
    def get_color(self):
        return self.color

    def print_P(self):
        return self.p

class Square(Shape):
    def __init__(self, side):
        super().__init__()
        self.sq = "Square >>"
        self.side = side
    
    def get_area(self):
        return self.side ** 2

    def print_P(self):
        print(self.sq)
        return super().print_P()

class RightSquare(Square):
    def __init__(self, side):
        super().__init__(side)
        self.rsq = "Right Square >>"
        self.side = side

    def print_P(self):
        print(self.rsq)
        return super().print_P()        
        
class Triangle(Shape):
    def __init__(self, base, height):
        super().__init__()
        self.base = base
        self.height = height
    
    def get_area(self):
        return 0.5 * self.base * self.height
    
rsq = RightSquare(3)
print(rsq.print_P())