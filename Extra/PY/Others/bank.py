import pickle                                                           # importing modules
import datetime
import os
import random
def create():                                                           # function for creating account
    f=open("bank.dat","wb")
    ans='y'
    while ans=='y':
        while True:
            accno=random.randint(10000000,99999999)                  # using random module generating accoun no.
            r=acc_no(accno)
            if r==1:
                break                                                
        name=input("Enter Account Name=")
        name=name.capitalize()
        while True:                                                     # condition for phone no.
            phone=int(input("Enter Phone Number="))
            l=len(str(phone))
            if l==10:
                break
            print("No. Is Not Valid=")
        address=input("Enter Address=")
        city=input("Enter City=")
        city=city.capitalize()
        while True:                                                     # condition for email
            email=input("Enter Email=")
            if '@'in email:
                if '.com' in email or '.co.in' in email or '.co' in email:
                    break
            print("Email is not valid....")    
        while True:                                                     # condition for dob using function birth
              d=input("Enter Date Of Birth(yyyy-mm-dd)=")
              r=birth(d)
              if r==1:
                    break
        while True:                                                     # condition for password
            passwd=input("Enter Password\n(including alphabets and digit)=")
            alpha=False
            digit=False
            for i in passwd:
                if i.isalpha():
                    alpha=True
                elif i.isdigit():
                    digit=True
            if alpha==True and digit==True:
                break
            print("Invalid password")
        deposit=int(input("Deposit Min^m rs500="))                      # condition for deposit money
        while deposit<500:
            print("Balanced Should Be rs500.\nYou Deposited Only",deposit)
            print("Add more",500-deposit,"Money")
            deposit+=int(input())
        rec=[accno,name,phone,address,city,email,d,passwd,deposit]      # detais of account assigning in a list
        pickle.dump(rec,f)                                              # dumping the data in file
        print("....ACCOUNT SUCCESSFULLY CREATED...(",datetime.datetime.now(),")")
        print('='*70)
        print("\t\tACCOUNT DETAILS...")                                 # showing detais of account
        print("Account number=",rec[0])
        print("Name=",rec[1])
        print("Phone number.=",rec[2])
        print("Address=",rec[3])
        print("City=",rec[4])
        print("Email=",rec[5])
        print("Date of birth=",rec[6])
        print("Account password=",rec[7])
        print("Balance=",rec[8])
        print('='*70)        
        ans=input("Create More Account\nPRESS(y/n)=")
    f.close()
def acc_no(a):
    f=open("bank.dat","rb")
    found=False
    try:
        while True:
            rec=pickle.load(f)
            if rec[0]==a:
                found=True
    except:
        if found==False:
            return 1
        f.close()
def birth(dob):                                                         # funtion for cheking  condition of dob
    if dob[:4].isdigit() and dob[5:7].isdigit() and dob[8:10].isdigit() and dob[4]=='-' and dob[7]=='-':        
        if int(dob[:4])<2004:
            if int(dob[5:7])<13:
                if dob[5:7] in ['01','03','05','07','08','10','12']:
                    if int(dob[8:10])<32 and int(dob[8:10])>0:
                        return 1                
                    else:
                        print("Date is not valid For This Month")
                elif dob[5:7] in ['04','06','09','11']:
                    if int(dob[8:10])<31 and int(dob[8:10])>0:
                        return 1
                    else:
                        print("Date is not valid For This Month")
                else:
                    if int(dob[:4])%4==0:
                        if int(dob[8:10])<30 and int(dob[:4])>0:
                            return 1  
                        else:
                            print("Date is not valid for this month")
                    else:
                        if int(dob[8:10])<29 and int(dob[8:10])>0:
                            return 1  
                        else:
                            print("Date is not valid for this month")
            else:
                print("Month is not valid")
        else:
            print("Year is not valid\n[NOTE= Minimum age should be 18+]")
    else:
        print("Invalid format")        
def all_details():                                                          # function for all account details
    f=open("bank.dat","rb")
    try:
        print('='*120)
        print("ALL ACCOUNT DETAILS")
        while True:
            rec=pickle.load(f)
            print(rec)
    except:
        print('='*120)
        f.close    
def detail():                                                               # functoin for specific account details                                                                      
    f=open("bank.dat","rb")
    accno=int(input("Enter account number"))
    passwd=input("Enter password")
    try:
        while True:
            found=False
            rec=pickle.load(f)
            if rec[0]==accno and rec[7]==passwd:
                print('='*30)
                print("ACCOUNT DETAILS...")
                for i in rec:
                    if rec[0]==i:
                        print("Account number=",i)
                    elif rec[1]==i:
                        print("Name=",i)
                    elif rec[2]==i:
                        print("Phone number.=",i)
                    elif rec[3]==i:
                        print("Address=",i)
                    elif rec[4]==i:
                        print("City=",i)
                    elif rec[5]==i:
                        print("Email=",i)
                    elif rec[6]==i:
                        print("Date of birth=",i)
                    elif rec[8]==i:
                        print("Balance=",i)
                found=True
                print('='*30)
                break
    except:
        if found==False:
            print("Account Not Found.....\n(May password or account name incorrect)")
        f.close()  
def delete():                                                                           # function for deleting account
    temp=open("temp.dat","wb")
    f=open("bank.dat","rb")
    print("NOTE - Account balanced should be zero(0)\n(Otherwise your amount will go to school charity##VVM..)")
    accno=int(input("Enter account number"))
    passwd=input("Enter account password")
    found=False
    try:
        print('='*100)
        while True:
            rec=pickle.load(f)
            if rec[0]==accno and rec[7]==passwd:
                found=True
                continue
            pickle.dump(rec,temp)    
    except:
        if found==False:
            print("Account not found...\n(May Account no. or password is incorrect)")
        else:
            print("Account successfully deleted!!!!!!")
        print('='*100)    
        f.close()
        temp.close()
        os.remove("bank.dat")
        os.rename("temp.dat","bank.dat")
def update():                                                                           # function for updating account deatails
    accno=int(input("enter account no."))
    passwd=input("enter account password")
    found=False
    f=open("bank.dat","rb+")
    try:
        while True:
            pos=f.tell()
            rec=pickle.load(f)
            #print(rec,'seeing record line by line')
            if rec[0]==accno and rec[7]==passwd:
                   while True:
                       print("what u want to update\n1-name\n2-phone no.\n3-address\n4-city\n5-email\n6-dob\n0=nothing to update")
                       z=int(input("enter for update"))
                       if z==1:
                           rec[1]=input("enter new name")
                           #rec[1].capitalize()
                       elif z==2:
                           rec[2]=int(input("enter new phone number"))
                       elif z==3:
                           rec[3]=input("enter new address")
                       elif z==4:
                           rec[4]=input("enter new city")
                           #rec[4].capitalize()
                       elif z==5:
                           rec[5]=input("enter new email")
                       elif z==6:
                           rec[6]=input("enter dob")
                           #while True:
                            #   rec[6]=input("Enter new dob")
                             #  r=birth(rec[6])
                              # if r==1:
                               #    break
                       elif z==0:
                           print("exit")
                           break
                       else:
                           print("wrong choice")
                   otp=random.randint(1000,9999)
                   print("\t\t\t\tOTP:",otp)
                   op=int(input("enter otp"))
                   if op==otp:
                      f.seek(pos)
                      pickle.dump(rec,f)
                      found=True
    except:
        if found==False:
            print("account not found")
        else:
            print("account updated")
        f.close()    
def deposit():                                                      # function for deposit money
    f=open("bank.dat","rb+")
    accno=int(input("Enter account number"))
    passwd=input("Enter account passsword")
    found=False
    try:
        print('='*100)
        while True:
            pos=f.tell()
            rec=pickle.load(f)
            if rec[0]==accno and rec[7]==passwd:
                d=int(input("Enter amount to be deposit"))
                rec[8]=rec[8]+d
                b=rec[8]
                f.seek(pos)
                pickle.dump(rec,f)
                found=True
    except:
        if found==False:
            print("Account not found...\n(May password or account name incorrect)")
        else:
            print("Money successfully deposited !!!!!!DATE(",datetime.datetime.now(),")")
            print("Current balance=",b)    
        print('='*100)    
        f.close()
def withdraw():                                                     # function for withdraw money
    f=open("bank.dat","rb+")
    accno=int(input("Enter account number"))
    passwd=input("Enter account passsword")
    found=False
    try:
        print('='*100)
        while True:
            pos=f.tell()                                            # Taking position of file pointer.
            rec=pickle.load(f)
            if rec[0]==accno and rec[7]==passwd:
                d=int(input("Enter Money To Be Withdraw"))
                otp=random.randint(1000,9999)                       # using random module generating otp
                print("\t\t\t\t\tOTP=",otp,"\n\t\t\t\t ",'-'*15)
                ou=int(input("Enter OTP"))
                if otp==ou:
                    s=rec[8]
                    if rec[8]>d or rec[8]==d:
                        rec[8]=rec[8]-d
                        f.seek(pos)
                        pickle.dump(rec,f)
                        found=True
                    else:
                        print("Amount Is Not Sufficient")
                        break
    except:
        if found==False:
            print("Account not found....\n(May password or account name incorrect)")
        else:
            print("Money successfully withdraw!!!!!!!! DATE(",datetime.datetime.now(),")")
            print("Remaining balance=",s-d)
        print('='*100)    
        f.close()
def balance():                                                      # function for check balance
    f=open("bank.dat","rb")
    accno=int(input("Enter account number"))
    passwd=input("Enter password")
    found=False
    try:
        print('='*100)
        while True:
            rec=pickle.load(f)
            if rec[0]==accno and rec[7]==passwd:
                print("Balance=",rec[8])
                found=True
    except:
        if found==False:
            print("Account not found\n(")
        print('='*100)    
        f.close()
ch=None                                                             # menu table

while True:
    print('*'*73,"\n*","TODAY'S DATE:",datetime.date.today(),"\tMAIN MENU\t\t\t\t*\n*\t\t\t ",'-'*18,"\t\t\t\t*\n* 1 - Create Account\t\t\t\t\t\t\t*\n* 2 - Account Alredy Created(SUB-Main Menu)\t\t\t\t*\n* 0 - Exit\t\t\t\t\t\t\t\t*\n* 9 - Bankers Use(SUB-Main Menu)\t\t\t\t\t*\n*",'*'*71)
    ch=int(input("Enter Your Choice="))
    if ch==1:
        create()
    elif ch==2:
        while True:
            ch1=None
            print('*'*73,"\n*\t\t\t\t SUB-Main Menu\t\t\t\t*\n*\t\t\t ",'-'*25," \t\t\t*\n* 1 - Details Of Account\t\t\t\t\t\t*\n* 2 - Check balanced\t\t\t\t\t\t\t*\n* 3 - Deposit Money\t\t\t\t\t\t\t*\n* 4 - Withdraw Money\t\t\t\t\t\t\t*\n* 5 - Return Main Menu\t\t\t\t\t\t\t*\n*",'*'*71)
            ch1=int(input("enter your choice="))
            if ch1==1:
                detail()
            elif ch1==2:
                balance()
            elif ch1==3:
                deposit()
            elif ch1==4:
                withdraw()
            elif ch1==5:
                print("Returning Main Menu")
                break    
            else:
                print("Wrong choice")
    elif ch==0:
        print("EXIT....")
        break
    elif ch==9:
        key=12345
        p=int(input("Enter password To See Details"))
        if key==p:
            while True:
                ch2=None
                print('*'*73,"\n*\t\t\t\t BANKER USE\t\t\t\t*\n*\t\t\t ",'-'*25,"\t\t\t*\n* 1 - All Details Of Account\t\t\t\t\t\t*\n* 2 - Update Account\t\t\t\t\t\t\t*\n* 3 - Delete Account\t\t\t\t\t\t\t*\n* 4 - Return Main Menu\t\t\t\t\t\t\t*\n*",'*'*71)
                ch2=int(input("Enter your choice="))
                if ch2==1:
                    all_details()
                elif ch2==2:
                    update()
                elif ch2==3:
                    delete()
                elif ch2==4:
                    print("Returning Main Menu")
                    break
                else:
                    print("Wrong choices")
        else:
            print("Wrong Password")        
    else:
        print("Wrong choice")
