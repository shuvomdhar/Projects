import tkinter
import cv2 # pip install opencv-python
import PIL.Image, PIL.ImageTk # pip install pillow
from functools import partial
import threading
import time
import imutils # pip install imutils

stream = cv2.VideoCapture("Python-Projects/DecisionReviewSystem/gallery/images/clip.gif")
flag = True
def play(speed):
    global flag
    print(f"You clicked on play. Speed is {speed}")
    # Play the video in reverse
    frame1 = stream.get(cv2.CAP_PROP_POS_FRAMES)
    stream.set(cv2.CAP_PROP_POS_FRAMES, frame1 + speed)

    grabbed, frame = stream.read()
    if not grabbed:
        exit()
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0, 0, image=frame, ancho=tkinter.NW)
    if flag:
        canvas.create_text(120, 25, fill="white", font="Times 20 italic bold", text="Decision Pending")
    flag = not flag

def pending(decision):
    # 1. Display decision pending image
    frame = cv2.cvtColor(cv2.imread("Python-Projects/DecisionReviewSystem/gallery/images/decision.jpeg"), cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0, 0, image=frame, ancho=tkinter.NW)

    # 2. Wait for 1 second
    time.sleep(1.5)

    # 3. Display sponsor image
    frame = cv2.cvtColor(cv2.imread("Python-Projects/DecisionReviewSystem/gallery/images/sponsor.jpeg"), cv2.COLOR_BGR2RGB)
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0, 0, image=frame, ancho=tkinter.NW)

    # 4. Wait for 1.5 second
    time.sleep(2.5)
    
    # 5. Display out/notout image
    if decision == 'out':
        decisionImg = "Python-Projects/DecisionReviewSystem/gallery/images/out.jpeg"
    else:
        decisionImg = "Python-Projects/DecisionReviewSystem/gallery/images/notout.jpeg"
    frame = cv2.cvtColor(cv2.imread(decisionImg), cv2.COLOR_BGR2RGB) 
    frame = imutils.resize(frame, width=SET_WIDTH, height=SET_HEIGHT)
    frame = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(frame))
    canvas.image = frame
    canvas.create_image(0, 0, image=frame, ancho=tkinter.NW)
    
def out():
    thread = threading.Thread(target=pending, args=("out",))
    thread.daemon = 1
    thread.start()
    print("Player is out")

def not_out():
    thread = threading.Thread(target=pending, args=("not out",))
    thread.daemon = 1
    thread.start()
    print("Player is not out")


# Width and height of our main screen
SET_WIDTH = 600
SET_HEIGHT = 392

# Tkinter gui starts here
window = tkinter.Tk()
window.title("Shuvom Dhar Third Umpire Decision Review Kit")
cv_img = cv2.cvtColor(cv2.imread("Python-Projects/DecisionReviewSystem/gallery/images/welcome.jpeg"), cv2.COLOR_BGR2RGB)
canvas = tkinter.Canvas(window, width=SET_WIDTH, height=SET_HEIGHT)
photo = PIL.ImageTk.PhotoImage(image=PIL.Image.fromarray(cv_img))
image_on_canvas = canvas.create_image(0, 0, ancho=tkinter.NW, image=photo)
canvas.pack()


# Buttons to control playback
btn = tkinter.Button(window, text="<< Previous (fast)", width=50, command=partial(play, -25))
btn.pack()

btn = tkinter.Button(window, text="<< Previous (slow)", width=50, command=partial(play, -2))
btn.pack()

btn = tkinter.Button(window, text="Next (slow) >>", width=50, command=partial(play, 2))
btn.pack()

btn = tkinter.Button(window, text="Next (fast) >>", width=50, command=partial(play, 25))
btn.pack()

btn = tkinter.Button(window, text="Give Out", width=50, command=out)
btn.pack()

btn = tkinter.Button(window, text="Give Not Out", width=50, command=not_out)
btn.pack()
window.mainloop()