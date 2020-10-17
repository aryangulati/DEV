import csv

filename = "FairDealCustomerData.csv"
csvout = "FairDealCustomerDataout.csv"
with open(filename,'r',newline='') as read_file:
    readCSV = csv.reader(read_file, delimiter=',')
    with open(csvout,"w",newline='') as write_file:
        writer = csv.writer(write_file)
        for row in readCSV:
            writer.writerow([row[0], row[1].split('.')[1].strip() + ' ', row[2],
            row[1].split('.')[0].strip()])
write_file.close()