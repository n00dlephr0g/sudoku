class Cell():
    def __init__(self):
        self.possibleValues:set[int] = {}
        self.value:int
        self.isLocked:bool = False
    
    def get_value(self) -> int | None:
        return self.value
    
    def get_possible(self) -> set[int]:
        return self.possibleValues
    
    def set_value(self, value:int) -> int:
        '''
        return codes: \n
        0: success
        1: cell is locked
        2: input not in range
        '''
        if self.isLocked:
            return 1
        if value in range(1,10):
            self.value = value
            return 0
        return 2

    def add_possible(self, possible:int):
        '''
        return codes: \n
        0: success
        1: cell is locked
        2: input not in range
        '''
        if self.isLocked:
            return 1
        if possible in range(1,10):
            self.possibleValues.add(possible)
            return 0
        return 2
    
    def lock(self):
        self.isLocked = True
        
    def unlock(self):
        self.isLocked = False