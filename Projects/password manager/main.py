import pyrebase
import stdiomask

# paste/replace your own firebase project config details here
firebaseConfig = {
    'apiKey': "AIzaVnaJ8SXxY0dfddffdffg22qr-ntuU4jTVb4",
    'authDomain': "passwdmanager-241db5.firebaseapp.com",
    'databaseURL': "https://passwdmanager-244db5-default-rtdb.firebaseio.com",
    'projectId': "passwdmanager-24db5",
    'storageBucket': "passwdmanager-241db5.appspot.com",
    'messagingSenderId': "685312661793",
    'appId': "1:685312df661793:web:dbfdadfa0b87e5f405c10384660"
  };

# initializing firebase 
firebase = pyrebase.initialize_app(firebaseConfig)

auth= firebase.auth()
db= firebase.database()

# verification
def authO(email,password):
    try:
        auth.sign_in_with_email_and_password(email,password)
        return 1
    except:
        return 0

#database queries handling

def createPasswd():
    site=input("Site: ")
    email=input("Email: ")
    Password=stdiomask.getpass()
    data={'password':Password,'email':email}
    
    users=db.child("data").get()
    db.child("data").child(site).push(data)

    print("\t password saved!!! ")

ccc=0
def searchSite(searchQ):
    sites=db.child("data").get()
    for ss in sites.each():
        if ss.key()==searchQ:
            kk=ss.key()
            dumpData(kk)
            ccc=1
            break
    return ccc

def dumpData(kk):
    sites=db.child("data").child(kk).get()
    print('\n')
    for ss in sites.each():
        print("Email: ", ss.val()['email']," |  Password: ",ss.val()['password'])
        print("-"*60)

# menu

def menu():
    option=""
    while option !='q':
         #print("-"*40)
        print("-"*40)
        print("-"*17,"MENU","-"*17)
        print("1. Create New password")
        print("2. Find a password for a site or app")
        print("q. Exit ")
        option=input(" ")
        if option=='1':
            createPasswd()
        elif option=='2':
            searchQ=input("Enter site or app name: ")
            out=searchSite(searchQ)
            if out < 1:
                print("\nPassword for this website or app doesn't exist in database. ")
                print("If Want to same password for ",searchQ," Enter 1\n ")

        elif option=='q':
            break
        else:
            continue


#input
c=0
while c==0:
    email=input("Email: ")
    password=stdiomask.getpass()
    out=authO(email,password)
    if out!=c:
        menu()
        break
    else:
        print("Invaid user or password.\n ")
        continue
