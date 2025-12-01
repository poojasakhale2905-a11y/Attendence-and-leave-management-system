
##📘 ABSTRACT##

# Attendance & Leave Management System (C Program)

This project is a console-based Attendance and Leave Management System written in C.  
It allows administrators to manage employee information, record attendance, and process leave requests.

---

## ✨ Features
- Add new employees  
- Mark employees as **Present** or **Absent**  
- Apply leave days  
- Display all employee records  
- Uses binary file (`employees.dat`) for storage  
- Simple, portable, and works on any C compiler  

---

## 📁 Data Storage
All records are stored in:



employees.dat


This binary file contains:
- Employee ID  
- Name  
- Present days  
- Absent days  
- Leave days  

---

## 🛠 Technical Requirements
- GCC compiler or any ANSI C compatible compiler  
- Works on Windows, Linux, macOS  
- Terminal/Command prompt  

---

## 📌 Functional Requirements
- System must allow adding employees  
- System must allow updating daily attendance  
- System must allow employee leave entries  
- System must display all stored employee data  
- Data must persist after program exit using file storage  

---

## ▶️ How to Run the Program

### **On Windows**


gcc attendance.c -o attendance
attendance


### **On Linux / Mac**


gcc attendance.c -o attendance
./attendance


---

## 📸 Screenshots (Text-Based)

### 1️⃣ Program Menu Screen

==============================
ATTENDANCE & LEAVE MANAGEMENT

Add Employee

Mark Attendance

Apply Leave

Display Employee Records

Exit
Enter your choice:


---

### 2️⃣ Add Employee Screen


Enter Employee ID: 101
Enter Name: John
Employee Added Successfully!


---

### 3️⃣ Mark Attendance Output


Enter Employee ID to mark attendance: 101

Present

Absent
Enter attendance: 1
Attendance Updated.


---

### 4️⃣ Display Employee Records Output

==========================================
EMPLOYEE RECORDS

ID Name Present Absent Leave
101 John 10 2 1
102 Sarah 8 4 0


---


<img width="435" height="371" alt="2" src="https://github.com/user-attachments/assets/b2ea2d9c-bafd-4261-9c03-666299933183" />
<img width="397" height="301" alt="1" src="https://github.com/user-attachments/assets/1e3b8291-bf81-4d5c-b8c9-08b068bf8ddb" />

