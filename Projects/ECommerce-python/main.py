import csv
import re
from Customer import Customer
from CustomerNotAllowedException import CustomerNotAllowedException

csv_clist = []
if __name__ == '__main__':
    filename = "FairDealCustomerData.csv"
    csvout = "CustomerDataout.csv"
    with open(filename, 'r', newline='') as read_file:
        readCSV = csv.reader(read_file, delimiter=',')
        with open(csvout, "w", newline='') as write_file:
            writer = csv.writer(write_file)
            for row in readCSV:
                writer.writerow([row[0],row[1].split('.')[0].strip(), row[1].split('.')[1].strip() + ' ', row[2]])
    write_file.close()

    file = open("CustomerDataout.csv", "r")
    csv_data = csv.reader(file)

    fullname_data = list([data for data in csv_data if re.match(r"([a-zA-Z].+)\s(\w+)\s(\w+)", data[2].strip(), re.IGNORECASE)])

    print("Storing and Printing all customer data from CSV")
    #storing and printing customers from dataset
    customerList = []
    ob = Customer()
    for data in fullname_data:
        ob.setTitle(data[1])
        ob.setFname(data[2])
        ob.setLname(data[0])
        ob.setIsblacklisted(data[3])

        # print(ob.getFname())
        # print(ob.getLname())
        # print(ob.getTitle())
        # print(ob.isblacklisted)
        print(ob.__str__())

    # non-blacklisted customer
    print("----------------------------------------------------------------------------------------")
    print("New customers")
    new_cust = Customer()
    new_cust.setTitle("Mr.")
    new_cust.setFname('John')
    new_cust.setLname('wick')
    new_cust.setIsblacklisted(False)

    final_order = new_cust.createOrder()
    print(final_order.__str__())

    # blacklisted customer
    print("----------------------------------------------------------------------------------------")
    print("Blacklisted customer")
    new_cust1 = Customer()
    new_cust1.setTitle("Mrs.")
    new_cust1.setFname('Perkins')
    new_cust1.setLname('winston')
    new_cust1.setIsblacklisted(True)
    final_order1 = new_cust1.createOrder()
    print(final_order1.__str__())
