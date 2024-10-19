class Cell():
    CHARACTERS='0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúñüÁÉÍÓÚÑÜ'
    def __init__(self, base):
        self.BASE: int = base
        self.ALLOWED: int = range(1,base**2+1)
        self.possibleValues:set[int] = set(self.ALLOWED)
        self.value:int = None
        self.isLocked:bool = False
    
    def get_value(self) -> int | None:
        return self.value
    
    def get_possible(self) -> set[int]:
        return self.possibleValues
    
    def set_value(self, value:int|None) -> int:
        '''
        return codes: \n
        0: success
        1: cell is locked
        2: input not in range
        '''
        if self.isLocked:
            return 1
        if value in self.ALLOWED or value is None:
            self.value = value
            return 0
        return 2

    def reset_value(self):
        return self.set_value(None)
    
    def add_possible(self, possible:int):
        '''
        return codes: \nvalue
        0: success
        1: cell is locked
        2: input not in range
        '''
        if self.isLocked:
            return 1
        if possible in self.ALLOWED:
            self.possibleValues.add(possible)
            return 0
        return 2
    
    def remove_possible(self, possible:int):
        self.possibleValues.remove(possible)
        return 0
    
    def lock(self):
        self.isLocked = True
        return 0
        
    def unlock(self):
        self.isLocked = False
        return 0 
        
    def __str__(self):
        output=''
        for col in range(self.BASE):
            for row in range(self.BASE):
                if len(self.possibleValues)>0:
                    cell = col*self.BASE+row+1
                    if cell in self.possibleValues:
                        output=output + f'{self.CHARACTERS[cell]}'
                    else:
                        output=output+' '
                elif self.value is not None:
                    output = output + f'{self.CHARACTERS[self.value]}'
                else:
                    output = output + ' '
            output = output + '\n'
        return output
        
class CellBase3(Cell):
    def __init__(self):
        super(CellBase3, self).__init__(3)
