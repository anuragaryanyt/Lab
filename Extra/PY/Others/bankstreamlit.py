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
    session_state = st.session_state

    if 'accounts' not in session_state:
        session_state['accounts'] = {}

    while True:
        accno = random.randint(10000000, 99999999)
        if accno not in session_state['accounts']:
            session_state['accounts'][accno] = {}

        account_data = session_state['accounts'][accno]
        account_data['name'] = st.text_input("Enter Account Name", key=f"account_name_{accno}", value=account_data.get('name', "")).capitalize()
        account_data['phone'] = st.text_input("Enter Phone Number", key=f"phone_number_{accno}", value=account_data.get('phone', ""))
        account_data['address'] = st.text_input("Enter Address", key=f"address_{accno}", value=account_data.get('address', ""))
        account_data['city'] = st.text_input("Enter City", key=f"city_{accno}", value=account_data.get('city', "")).capitalize()
        account_data['email'] = st.text_input("Enter Email", key=f"email_{accno}", value=account_data.get('email', ""))
        dob_value = session_state.get('dob', None)
        dob = st.date_input("Enter Date Of Birth", key=f"dob_{accno}", min_value=datetime.date(1900, 1, 1), max_value=datetime.date.today(), value=datetime.datetime.strptime(dob_value, "%Y-%m-%d") if dob_value else None)
        session_state['dob'] = dob.strftime("%Y-%m-%d") if dob else None
        account_data['passwd'] = st.text_input("Enter Password", key=f"password_{accno}", type="password", value=account_data.get('passwd', ""))
        account_data['deposit'] = st.number_input("Deposit Min^m Rs. 500", key=f"deposit_{accno}", min_value=500, value=account_data.get('deposit', 500))

        if st.button("Create Account"):
            # Validations
            if len(str(account_data['phone'])) != 10:
                st.error("Invalid Phone Number")
                continue
            if '@' not in account_data['email'] or ('.com' not in account_data['email'] and '.co.in' not in account_data['email'] and '.co' not in account_data['email']):
                st.error("Invalid Email")
                continue
            # Account details
            rec = [accno, account_data['name'], account_data['phone'], account_data['address'], account_data['city'], account_data['email'], account_data['dob'], account_data['passwd'], account_data['deposit']]
            # Saving to file
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
            break  # Exit loop after creating account

# Function to manage application flow
def main():
    st.sidebar.title("Bank Management System")
    menu_option = st.sidebar.radio("Menu", ("Create Account", "Exit"))
    if menu_option == "Create Account":
        create()
    elif menu_option == "Exit":
        st.sidebar.write("Thank you for using the Bank Management System!")

if __name__ == "__main__":
    main()