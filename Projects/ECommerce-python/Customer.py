from Orders import Orders
from CustomerNotAllowedException import CustomerNotAllowedException


class Customer:
    title = ""
    fname = ""
    lname = ""
    isblacklisted = 0;

    def __init__(self):
        self.title = ""

    def __str__(self):
        return "Title:" + self.title + " First Name:" + self.fname + " Last Name:" + self.lname + " Blacklisted:" + self.isblacklisted

    def setIsblacklisted(self, isblacklisted):
        self.isblacklisted = isblacklisted

    def isblacklisted(self):
        return self.isblacklisted

    def setTitle(self, title):
        self.title = title

    def getTitle(self):
        return self.title

    def setFname(self, fname):
        self.fname = fname

    def getFname(self):
        return self.fname

    def setLname(self, lname):
        self.lname = lname

    def getLname(self):
        return self.lname


    def createOrder(self):
        if self.isblacklisted:
            raise CustomerNotAllowedException("Blacklisted customer. Hence not allowed to add order")

        product_code = input("Enter the product code:")
        product_name = input("Enter the product name:")
        order = Orders()
        order.setProductCode(product_code)
        order.setProductName(product_name)

        return order
