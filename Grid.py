from Cell import Cell

BASE = 3

class Grid():
    def __init__(self, base:int):
        self.BASE:int = base
        self.DOMAIN: int = range(0,base**2)
        self.grid:list[list[int]] = []
        for r in self.DOMAIN:
            row = []
            for c in self.DOMAIN:
                row[c]=Cell(base)
    
    def get_sector(self, sector):
        # get sector position
        sectorRow = sector//self.BASE - 1
        sectorCol = sector%self.BASE - 1

    
    
    
    
    
    
    
    
    
    
    
    
    def __str__(self):
        return ''
