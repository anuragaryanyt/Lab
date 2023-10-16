import sqlite3
import datetime
import random

def create_table():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()
    
    cursor.execute('''
    CREATE TABLE IF NOT EXISTS accounts (
        accno INTEGER PRIMARY KEY,
        name TEXT,
        phone INTEGER,
        address TEXT,
        city TEXT,
        email TEXT,
        dob TEXT,
        passwd TEXT,
        balance INTEGER
    )
    ''')
    
    conn.commit()
    conn.close()

def create():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()
    
    ans = 'y'
    while ans == 'y':
        accno = random.randint(10000000, 99999999)
        name = input("Enter Account Name=").capitalize()
        # Rest of the account creation logic...
        
        cursor.execute('''
        INSERT INTO accounts (accno, name, phone, address, city, email, dob, passwd, balance)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
        ''', (accno, name, phone, address, city, email, d, passwd, deposit))
        
        conn.commit()
        
        # Display account details...
        
        ans = input("Create More Account\nPRESS(y/n)=")
    
    conn.close()

# Define and rewrite other functions similarly...

if __name__ == '__main__':
    create_table()
    
#     while True:
#         # Main menu logic...



def acc_no(a):
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()
    
    cursor.execute('SELECT * FROM accounts WHERE accno = ?', (a,))
    result = cursor.fetchone()
    
    conn.close()
    
    if result is None:
        return 1
    else:
        return 0



def birth(dob):
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    cursor.execute("SELECT strftime('%Y', 'now') - strftime('%Y', ?) AS age", (dob,))
    result = cursor.fetchone()

    conn.close()

    age = result[0]
    
    if age >= 18:
        return 1
    else:
        print("Year is not valid\n[NOTE= Minimum age should be 18+]")




def all_details():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    cursor.execute('SELECT * FROM accounts')
    all_accounts = cursor.fetchall()

    conn.close()

    print('=' * 120)
    print("ALL ACCOUNT DETAILS")

    for acc in all_accounts:
        print(acc)

if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...




def detail():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    accno = int(input("Enter account number"))
    passwd = input("Enter password")

    cursor.execute('SELECT * FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    conn.close()

    if result is not None:
        print('=' * 30)
        print("ACCOUNT DETAILS...")
        print("Account number=", result[0])
        print("Name=", result[1])
        print("Phone number.=", result[2])
        print("Address=", result[3])
        print("City=", result[4])
        print("Email=", result[5])
        print("Date of birth=", result[6])
        print("Balance=", result[8])
        print('=' * 30)
    else:
        print("Account Not Found.....\n(May password or account name incorrect)")




def delete():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    temp_conn = sqlite3.connect('temp.db')
    temp_cursor = temp_conn.cursor()

    print("NOTE - Account balanced should be zero(0)\n(Otherwise your amount will go to school charity##VVM..)")
    accno = int(input("Enter account number"))
    passwd = input("Enter account password")

    cursor.execute('SELECT * FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    if result is not None and result[8] == 0:
        print('=' * 100)

        for acc in cursor.execute('SELECT * FROM accounts WHERE accno != ? OR passwd != ?', (accno, passwd)):
            temp_cursor.execute('''
            INSERT INTO accounts (accno, name, phone, address, city, email, dob, passwd, balance)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
            ''', acc)

        temp_conn.commit()
        conn.close()
        temp_conn.close()

        print("Account successfully deleted!!!!!!")
        print('=' * 100)
        
        os.remove('bank.db')
        os.rename('temp.db', 'bank.db')
    else:
        if result is None:
            print("Account not found...\n(May Account no. or password is incorrect)")
        else:
            print("Account balance is not zero.")
        print('=' * 100)
    
if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...





def update():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    accno = int(input("Enter account no."))
    passwd = input("Enter account password")

    cursor.execute('SELECT * FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    if result is not None:
        print('=' * 100)
        print("What do you want to update:")
        print("1 - Name")
        print("2 - Phone no.")
        print("3 - Address")
        print("4 - City")
        print("5 - Email")
        print("6 - DOB")
        print("0 - Nothing to update")
        
        z = int(input("Enter choice:"))
        if 1 <= z <= 6:
            new_value = input("Enter new value:")
            cursor.execute('UPDATE accounts SET {} = ? WHERE accno = ?'.format(columns[z]), (new_value, accno))
            conn.commit()
            
            otp = random.randint(1000, 9999)
            print("\t\t\t\tOTP:", otp)
            op = int(input("Enter OTP"))
            
            if op == otp:
                print("Account updated")
            else:
                print("OTP verification failed")
        elif z == 0:
            print("Exit")
        else:
            print("Invalid choice")
    else:
        print("Account not found")
    print('=' * 100)
    
if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...





def deposit():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    accno = int(input("Enter account number"))
    passwd = input("Enter account password")

    cursor.execute('SELECT * FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    if result is not None:
        print('=' * 100)
        d = int(input("Enter amount to be deposited"))
        new_balance = result[8] + d
        
        cursor.execute('UPDATE accounts SET balance = ? WHERE accno = ?', (new_balance, accno))
        conn.commit()

        print("Money successfully deposited !!!!!! DATE(", datetime.datetime.now(), ")")
        print("Current balance =", new_balance)
    else:
        print("Account not found...\n(May password or account name incorrect)")
    print('=' * 100)
    
if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...





def withdraw():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    accno = int(input("Enter account number"))
    passwd = input("Enter account password")

    cursor.execute('SELECT * FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    if result is not None:
        print('=' * 100)
        d = int(input("Enter amount to be withdrawn"))

        if result[8] >= d:
            otp = random.randint(1000, 9999)
            print("\t\t\t\t\tOTP=", otp, "\n\t\t\t\t", '-' * 15)
            ou = int(input("Enter OTP"))

            if otp == ou:
                new_balance = result[8] - d
                cursor.execute('UPDATE accounts SET balance = ? WHERE accno = ?', (new_balance, accno))
                conn.commit()

                print("Money successfully withdrawn !!!!!! DATE(", datetime.datetime.now(), ")")
                print("Remaining balance =", new_balance)
            else:
                print("OTP verification failed")
        else:
            print("Amount Is Not Sufficient")
    else:
        print("Account not found...\n(May password or account name incorrect)")
    print('=' * 100)
    
if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...




def balance():
    conn = sqlite3.connect('bank.db')
    cursor = conn.cursor()

    accno = int(input("Enter account number"))
    passwd = input("Enter password")

    cursor.execute('SELECT balance FROM accounts WHERE accno = ? AND passwd = ?', (accno, passwd))
    result = cursor.fetchone()

    conn.close()

    if result is not None:
        print('=' * 100)
        print("Balance =", result[0])
    else:
        print("Account not found")
    print('=' * 100)
    
if __name__ == '__main__':
    create_table()

    # while True:
    #     # Main menu logic...





def main_menu():
    while True:
        print('*' * 73)
        print("* TODAY'S DATE:", datetime.date.today(), "\tMAIN MENU\t\t\t\t*")
        print("*\t\t\t", '-' * 18, "\t\t\t\t*")
        print("* 1 - Create Account\t\t\t\t\t\t\t*")
        print("* 2 - Account Already Created(SUB-Main Menu)\t\t\t\t*")
        print("* 0 - Exit\t\t\t\t\t\t\t\t*")
        print("* 9 - Bankers Use(SUB-Main Menu)\t\t\t\t\t*")
        print('*' * 71)

        ch = int(input("Enter Your Choice="))
        
        if ch == 1:
            create()
        elif ch == 2:
            sub_menu_account()
        elif ch == 0:
            print("EXIT....")
            break
        elif ch == 9:
            bank_key = 12345
            entered_key = int(input("Enter password To See Details"))
            if entered_key == bank_key:
                sub_menu_banker()
            else:
                print("Wrong Password")
        else:
            print("Wrong choice")

def sub_menu_account():
    while True:
        print('*' * 73)
        print("*\t\t\t SUB-Main Menu\t\t\t*")
        print("*\t\t\t", '-' * 25, " \t\t*")
        print("* 1 - Details Of Account\t\t\t\t\t\t*")
        print("* 2 - Check balanced\t\t\t\t\t\t\t*")
        print("* 3 - Deposit Money\t\t\t\t\t\t\t*")
        print("* 4 - Withdraw Money\t\t\t\t\t\t\t*")
        print("* 5 - Return Main Menu\t\t\t\t\t\t\t*")
        print('*' * 71)

        ch1 = int(input("Enter your choice="))
        if ch1 == 1:
            detail()
        elif ch1 == 2:
            balance()
        elif ch1 == 3:
            deposit()
        elif ch1 == 4:
            withdraw()
        elif ch1 == 5:
            print("Returning Main Menu")
            break
        else:
            print("Wrong choice")

def sub_menu_banker():
    while True:
        print('*' * 73)
        print("*\t\t\t BANKER USE\t\t\t*")
        print("*\t\t\t", '-' * 25, "\t\t*")
        print("* 1 - All Details Of Account\t\t\t\t\t\t*")
        print("* 2 - Update Account\t\t\t\t\t\t\t*")
        print("* 3 - Delete Account\t\t\t\t\t\t\t*")
        print("* 4 - Return Main Menu\t\t\t\t\t\t\t*")
        print('*' * 71)

        ch2 = int(input("Enter your choice="))
        if ch2 == 1:
            all_details()
        elif ch2 == 2:
            update()
        elif ch2 == 3:
            delete()
        elif ch2 == 4:
            print("Returning Main Menu")
            break
        else:
            print("Wrong choice")

if __name__ == '__main__':
    create_table()
    main_menu()



