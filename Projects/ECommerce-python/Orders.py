# processing orders
class Orders:
    ProductCode = ""
    ProductName = ""
    def __init__(self):
        pass

    def setProductCode(self, ProductCode):
        self.ProductCode = ProductCode

    def getProductCode(self):
        return self.ProductCode

    def setProductName(self, ProductName):
        self.ProductName = ProductName

    def getProductName(self):
        return self.ProductName

    def __str__(self):
        return "Product code:" + self.ProductCode + " product Name:" + self.ProductName

