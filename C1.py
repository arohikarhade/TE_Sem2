class Student:
    def __init__(self, name, roll, math, science, english, socialscience, sanskrit):
        self.name = name
        self.roll = roll
        self.math = math
        self.science = science
        self.english = english
        self.socialscience = socialscience
        self.sanskrit = sanskrit

class StudentPerformance:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)
        print("Student added successfully!")

    # def display_students(self):
    #     if not self.students:
    #         print("No students in the database.")
    #         return
    #     print("Student details:")
    #     for student in self.students:
    #         print("Name:", student.name)
    #         print("Roll:", student.roll)
    #         print("Math:", student.math)
    #         print("Math:", student.science)
    #         print("Math:", student.english)
    #         print("Math:", student.sanskrit)
    #         print("Math:", student.socialscience)
    #         print()

    def performance_eval(self, roll):
        for student in self.students:
            if student.roll == roll:
                p_math = student.math / 80 * 100
                p_science = student.science / 80 * 100
                p_english = student.english / 80 * 100
                p_socialscience = student.socialscience / 80 * 100
                p_sanskrit = student.sanskrit / 80 * 100

                percentage = (student.math + student.science + student.english + student.socialscience + student.sanskrit) / 400 * 100
                
                grade = ""
                if(percentage>0 and percentage<40):
                    grade = 'F'

                elif(percentage>40 and percentage<50):
                    grade = 'E'

                elif(percentage>50 and percentage<60):
                    grade = 'D'

                elif(percentage>60 and percentage<70):
                    grade = 'C'

                elif(percentage>70 and percentage<80):
                    grade = 'B'

                elif(percentage>80 and percentage<90):
                    grade = 'A'

                elif(percentage>90 and percentage<100):
                    grade = 'O'
                
                print("Percentage:")
                print("Math:", p_math)
                print("Science", p_science)
                print("English", p_english)
                print("Social Science", p_socialscience)
                print("Sanskrit", p_sanskrit)

                print("Total percentage: ", percentage, "%")

                if(grade == 'F'):
                    print(student.roll, " has failed. You are required to give a retest.")
                else:
                    print(student.roll, " has gotten a total grade ", grade)
        
        print("\n")

# Sample usage
db = StudentPerformance()

# Add students
student1 = Student("John", 101, 50, 65, 73, 40, 70)
student2 = Student("Alice", 102, 38, 55, 70, 77, 69)
db.add_student(student1)
db.add_student(student2)

#Performance evaluation
db.performance_eval(101)

db.performance_eval(102)
