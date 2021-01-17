#학과:중어중문학과/학번:202010122/이름:나예담
#이 프로그램은 tkinter를 이용하여 만든 학점계산기입니다. 과목명, 등급, 이수학점을 입력하여 결과보기 버튼을 누르면 결과창에 평균학점이 출력됩니다.
#사용방법은 과목명에 과목이름을 적고, 등급란에 A+, A0, B+, B0, C+, C0, D+, D0, F를 입력하고,
#이수학점에 이수한 학점(숫자)을 적은 후 결과버튼을 누르면 결과가 출력됩니다.
#주의해야 할 사항은 등급란에 A0가 아닌 A라 적을 시 오류창이 발생하기에, 이 점을 주의해야합니다.


from tkinter import* #tkinter 프로그램을 불러오기 위해 작성한다.
from tkinter.ttk import Combobox
import tkinter.messagebox

window = Tk()

display_text = Text(window, width=15,height=1) #결과창의 크기, 위치를 설정한다.
display_text.grid(row=16, column=0)

window.title('학점계산기') #프로그램 이름
window.geometry('600x300') #프로그램 크기
num_1=Label(window, text='번호') #label 이름 정하기
num_2=Label(window, text='1')
num_3=Label(window, text='2')
num_4=Label(window, text='3')
num_5=Label(window, text='4')
num_6=Label(window, text='5')
num_7=Label(window, text='6')
num_8=Label(window, text='7')
num_9=Label(window, text='8')
num_10=Label(window, text='9')
num_11=Label(window, text='10')
name=Label(window, text='과목명')
grade=Label(window, text='등급')
credit=Label(window, text='이수학점')
result=Label(window, text='결과')

name_1=Entry(window) #과목명은 빈칸이어야하기에, entry를 입력한다.
name_2=Entry(window)
name_3=Entry(window)
name_4=Entry(window)
name_5=Entry(window)
name_6=Entry(window)
name_7=Entry(window)
name_8=Entry(window)
name_9=Entry(window)
name_10=Entry(window)

grade_1=Entry(window) #등급도 과목명과 같이 작성한다.
grade_2=Entry(window)
grade_3=Entry(window)
grade_4=Entry(window)
grade_5=Entry(window)
grade_6=Entry(window)
grade_7=Entry(window)
grade_8=Entry(window)
grade_9=Entry(window)
grade_10=Entry(window)

credit_1=Entry(window) #이수학점도 똑같이 작성한다.
credit_2=Entry(window)
credit_3=Entry(window)
credit_4=Entry(window)
credit_5=Entry(window)
credit_6=Entry(window)
credit_7=Entry(window)
credit_8=Entry(window)
credit_9=Entry(window)
credit_10=Entry(window)

#위치를 설정한다.

num_1.grid(row=0, column=0)
num_2.grid(row=1, column=0)
num_3.grid(row=2, column=0)
num_4.grid(row=3, column=0)
num_5.grid(row=4, column=0)
num_6.grid(row=5, column=0)
num_7.grid(row=6, column=0)
num_8.grid(row=7, column=0)
num_9.grid(row=8, column=0)
num_10.grid(row=9, column=0)
num_11.grid(row=10, column=0)
name.grid(row=0, column=1)
grade.grid(row=0, column=2)
credit.grid(row=0, column=3)
result.grid(row=15, column=0)

name_1.grid(row=1, column=1)
name_2.grid(row=2, column=1)
name_3.grid(row=3, column=1)
name_4.grid(row=4, column=1)
name_5.grid(row=5, column=1)
name_6.grid(row=6, column=1)
name_7.grid(row=7, column=1)
name_8.grid(row=8, column=1)
name_9.grid(row=9, column=1)
name_10.grid(row=10, column=1)

grade_1.grid(row=1, column=2)
grade_2.grid(row=2, column=2)
grade_3.grid(row=3, column=2)
grade_4.grid(row=4, column=2)
grade_5.grid(row=5, column=2)
grade_6.grid(row=6, column=2)
grade_7.grid(row=7, column=2)
grade_8.grid(row=8, column=2)
grade_9.grid(row=9, column=2)
grade_10.grid(row=10, column=2)

credit_1.grid(row=1, column=3)
credit_2.grid(row=2, column=3)
credit_3.grid(row=3, column=3)
credit_4.grid(row=4, column=3)
credit_5.grid(row=5, column=3)
credit_6.grid(row=6, column=3)
credit_7.grid(row=7, column=3)
credit_8.grid(row=8, column=3)
credit_9.grid(row=9, column=3)
credit_10.grid(row=10, column=3)

#등급을 숫자로 반환하고, 성적 산출할 수 있는 코드를 작성한다.

grade_score = {"A+":4.5, "A0":4.0, "B+":3.5, "B0":3.0, "C+":2.5, "C0":2.0, "D+":1.5, "D0":1.0, "F":0}
def display(): 
    res = 0.0 
    all_score = 0.0
    try: 
        for i in range(1,11): #for 반복문과 if문을 이용해서 평균 학점을 계산하는 코드 생성한다.
            grade = globals()['grade_{}'.format(i)].get() 
            score = globals()['credit_{}'.format(i)].get() 
            if grade == '' or score == '': #빈칸일 시 집계 하지 않도록 설정한다.
                break
            res += grade_score[grade]*float(score) 
            all_score += float(score) 
        res /= all_score 
        display_text.delete(1.0,"end")
        display_text.insert(1.0, res)
    except Exception as e : #예외 발생(grade_score에 지정되어있지 않은 문자열 입력)시 에러창을 띄워준다.
        tkinter.messagebox.showerror("Error", "Getting Error : {0}".format(e))

b1 = Button(window, text="결과보기", command=display) #"결과보기" 버튼을 누르면 display로 결과가 출력되도록 한다.

b1.grid(row=12, column=2) #버튼의 위치

window.mainloop()
