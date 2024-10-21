from Cell import Cell
import numpy as np

class Grid():
    def __init__(self, base:int):
        self.BASE:int = base
        self.DOMAIN: int = range(0,base**2)
        self.grid:np.array[Cell]=np.full((base**2,base**2), Cell(base))

    def get_sector(self, sector):
        # get sector position
        sectorRow = sector//self.BASE
        sectorCol = sector%self.BASE
        rowStartCoord = sectorRow*self.BASE
        colStartCoord = sectorCol*self.BASE
        return self.grid[rowStartCoord:rowStartCoord+self.BASE,colStartCoord:colStartCoord+self.BASE]

    
    def get_row(self, row:int):
        return self.grid[row,:]
    
    def get_col(self, col:int):
        return self.grid[:,col]
    
    
    
    
    
    
    
    def __str__(self):
        for i in self.DOMAIN:
            for cell in self.get_row(i):
                pass


# print(Grid(3).get_row(1))
for i in range(16):
    print(Grid(4).get_sector(i))