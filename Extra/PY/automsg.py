import pyautogui as pg
import random
import time
i = 0
time.sleep(1)

while i<1000:
    pg.write("hiiiiiii")
    time.sleep(0.3)
    pg.press("enter")
    time.sleep(0.3)
    i+=1