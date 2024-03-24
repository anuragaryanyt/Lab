import streamlit as st
import pickle 
import datetime
import os
import random

def acc_no(a):
    return 1

def birth(dob):
    if dob[:4].isdigit() and dob[5:7].isdigit() and dob[8:10].isdigit() and dob[4]=='-' and dob[7]=='-':
        if int(dob[:4]) < 2004:
            if int(dob[5:7]) < 13:
                if dob[5:7] in ['01','03','05','07','08','10','12']:
                    if int(dob[8:10]) < 32 and int(dob[8:10]) > 0:
                        return 1
                    else:
                        st.error("Date is not valid For This Month")
                elif dob[5:7] in ['04','06','09','11']:
                    if int(dob[8:10]) < 31 and int(dob[8:10]) > 0:
                        return 1
                    else:
                        st.error("Date is not valid For This Month")
                else:
                    if int(dob[:4]) % 4 == 0:
                        if int(dob[8:10]) < 30 and int(dob[:4]) > 0:
                            return 1
                        else:
                            st.error("Date is not valid for this month")
                    else:
                        if int(dob[8:10]) < 29 and int(dob[8:10]) > 0:
                            return 1
                        else:
                            st.error("Date is not valid for this month")
            else:
                st.error("Month is not valid")
        else:
            st.error("Year is not valid\n[NOTE= Minimum age should be 18+]")
    else:
        st.error("Invalid format")


def create():
    st.title("Create Account")
    ans = 'y'
    while ans == 'y':
        accno = random.randint(10000000, 99999999)
        name = st.text_input("Enter Account Name", key="account_namekey").capitalize()
        phone = st.text_input("Enter Phone Number", key="phone_numberkey")
        address = st.text_input("Enter Address", key="addresskey")
        city = st.text_input("Enter City", key="citykey").capitalize()
        email = st.text_input("Enter Email", key="emailkey")
        dob = st.date_input("Enter Date Of Birth", key="dobkey", min_value=datetime.date(1900, 1, 1),
                            max_value=datetime.date.today())
        passwd = st.text_input("Enter Password", key="passwordkey", type="password")
        deposit = st.number_input("Deposit Min^m Rs. 500", key="depositkey", min_value=500)

        if st.button("Create Account"):
            if len(phone) != 10 or not phone.isdigit():
                st.error("Invalid Phone Number")
                continue

            if '@' not in email or ('.com' not in email and '.co.in' not in email and '.co' not in email):
                st.error("Invalid Email")
                continue

            rec = [accno, name, phone, address, city, email, dob, passwd, deposit]
            
            with open("bank.dat", "ab") as f:
                pickle.dump(rec, f)

            st.success("Account Successfully Created")
            st.write("Account Details:")
            st.write("Account number:", rec[0])
            st.write("Name:", rec[1])
            st.write("Phone number:", rec[2])
            st.write("Address:", rec[3])
            st.write("City:", rec[4])
            st.write("Email:", rec[5])
            st.write("Date of birth:", rec[6])
            st.write("Balance:", rec[8])

            ans = st.radio("Create More Account", ('y', 'n'))

st.title("Banking Application")

# Authentication (optional, for improved security)
if "logged_in" not in st.session_state:
    st.subheader("Login")
    username = st.text_input("Username")
    password = st.text_input("Password", type="password")
    if st.button("Login"):
        # Check credentials against a database or a secure file
        if username == "admin" and password == "admin":
            st.session_state["logged_in"] = True
        else:
            st.error("Invalid login credentials")

if "logged_in" in st.session_state and st.session_state["logged_in"]:
    # Main Menu with Streamlit Components
    st.sidebar.subheader("Main Menu")
    choice = st.sidebar.selectbox("Select an option", [
        "Create Account", "Account Details", "Check Balance", 
        "Deposit Money", "Withdraw Money", "Banker Tools"
    ])

    if choice == "Create Account":
        create()
    elif choice == "Account Details":
        detail()
    # ... (other choices)

    elif choice == "Banker Tools":
        banker_password = st.sidebar.text_input("Banker Password", type="password")
        if banker_password == "your_banker_password":
            banker_choice = st.sidebar.selectbox("Banker Options", [
                "All Account Details", "Update Account", "Delete Account"
            ])
            if banker_choice == "All Account Details":
                all_details()
            # ... (other banker choices)
        else:
            st.sidebar.error("Invalid banker password")
