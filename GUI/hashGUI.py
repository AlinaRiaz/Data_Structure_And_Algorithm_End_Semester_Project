import os
import tkinter as tk
from tkinter import simpledialog, scrolledtext
from ctypes import CDLL, create_string_buffer

# ---- Load DLL ----
script_dir = os.path.dirname(os.path.abspath(__file__))
dll_path = os.path.join(script_dir, "hashLibrary.dll")
lib = CDLL(dll_path)
lib.initLibrary()

BUFFER_SIZE = 4096
buffer = create_string_buffer(BUFFER_SIZE)

# ---- GUI ----
root = tk.Tk()
root.title("Library Management System")
root.geometry("700x450")

output_box = scrolledtext.ScrolledText(root)
output_box.pack(fill="both", expand=True)

def clear_output():
    output_box.delete(1.0, tk.END)

# ---- Student Functions ----
def create_student():
    clear_output()
    roll = simpledialog.askinteger("Create Student", "Enter roll number")
    name = simpledialog.askstring("Create Student", "Enter name")
    if roll and name:
        lib.createStudent(roll, name.encode(), 100)
        output_box.insert(tk.END, "Student added\n")

def view_student():
    clear_output()
    roll = simpledialog.askinteger("View Student", "Enter roll number")
    if roll:
        lib.viewStudent(roll, buffer, BUFFER_SIZE)
        output_box.insert(tk.END, buffer.value.decode() + "\n")

def deposit_amount():
    clear_output()
    roll = simpledialog.askinteger("Deposit", "Enter roll number")
    amount = simpledialog.askfloat("Deposit", "Enter amount")
    if roll and amount:
        lib.depositAmount(roll, amount)
        output_box.insert(tk.END, "Deposit done\n")

# ---- Book Functions ----
def add_book():
    clear_output()
    isbn = simpledialog.askinteger("Add Book", "Enter ISBN")
    title = simpledialog.askstring("Add Book", "Enter title")
    author = simpledialog.askstring("Add Book", "Enter author")
    if isbn and title and author:
        lib.addBook(isbn, title.encode(), author.encode())
        output_box.insert(tk.END, "Book added\n")

def view_books():
    clear_output()
    lib.viewBooks(buffer, BUFFER_SIZE)
    output_box.insert(tk.END, buffer.value.decode() + "\n")

def issue_book():
    clear_output()
    roll = simpledialog.askinteger("Issue Book", "Enter student roll")
    isbn = simpledialog.askinteger("Issue Book", "Enter ISBN")
    if roll and isbn:
        lib.issueBook(roll, isbn)
        output_box.insert(tk.END, "Book issued\n")

def return_book():
    clear_output()
    roll = simpledialog.askinteger("Return Book", "Enter student roll")
    isbn = simpledialog.askinteger("Return Book", "Enter ISBN")
    if roll and isbn:
        lib.returnBook(roll, isbn)
        output_box.insert(tk.END, "Book returned\n")

# ---- Buttons ----
buttons = [
    ("Create Student", create_student),
    ("View Student", view_student),
    ("Deposit Amount", deposit_amount),
    ("Add Book", add_book),
    ("View Books", view_books),
    ("Issue Book", issue_book),
    ("Return Book", return_book),
    ("Exit", root.quit)
]

for text, func in buttons:
    tk.Button(root, text=text, command=func, height=2).pack(fill="x", padx=5, pady=5)

root.mainloop()