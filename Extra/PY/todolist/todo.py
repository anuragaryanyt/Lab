import csv

class ToDoList:
    def __init__(self, filename):
        self.filename = filename
        self.tasks = self.load_tasks()

    def load_tasks(self):
        try:
            with open(self.filename, 'r', newline='') as file:
                reader = csv.DictReader(file)
                return list(reader)
        except FileNotFoundError:
            return []

    def save_tasks(self):
        with open(self.filename, 'w', newline='') as file:
            fieldnames = ['tasks', 'completed']
            writer = csv.DictWriter(file, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(self.tasks)

    def add_tasks(self, tasks):
        self.tasks.append({"tasks": tasks, "completed": "No"})
        self.save_tasks()

    def delete_tasks(self, index):
        del self.tasks[index]
        self.save_tasks()

    def mark_complete(self, index):
        self.tasks[index]["completed"] = "Yes"
        self.save_tasks()

    def display(self):
        print("-------------------------------------------------------------------")
        print("                          TO DO LIST                               ")
        print("Index   Tasks   \t\tStatus")
        for index, tasks in enumerate(self.tasks, start=1):
            status = "[Completed]" if tasks["completed"] == "Yes" else "[Not Completed]"
            print(f"{index:<7} {tasks['tasks']:<7} \t\t{status}")


def main():
    filename = "tasks.csv"
    todo = ToDoList(filename)

    while True:
        # print("                    ")
        print(
            "\n1. Add tasks \n2. Delete tasks \n3. Mark as completed \n4. Display \n5. Exit")

        choice = input("Enter your choice: ")
        if choice == '1':
            tasks = input("Enter the tasks: ")
            todo.add_tasks(tasks)

        elif choice == '2':
            index = int(input("Enter the index of tasks: ")) - 1
            todo.delete_tasks(index)

        elif choice == '3':
            index = int(
                input("Enter the index of to be mark as completed: ")) - 1
            todo.mark_complete(index)

        elif choice == '4':
            todo.display()

        elif choice == '5':
            print("Exiting...")
            break

        else:
            print("Invalid Choice!!")


if __name__ == '__main__':
    main()
