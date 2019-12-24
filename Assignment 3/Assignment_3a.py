import cv2
import numpy as np
import serial

incser = serial.Serial('', 9600)

images = ["opencv1.jpeg", "opencv2.png"]
colors= ( ([0,0,83],[80,130,255]) , ([0,168,0],[150,255,190]) , ([135,0,0],[255,200,134]) ) #rgb
serwrt = ('r', 'g', 'b')
outputName = ("red", "green", "blue")

i=0
while i in range(2):
    frame = cv2.imread(images[i])
    for j in range(3):
        lowerRange = np.array(colors[j][0])
        upperRange = np.array(colors[j][1])
        mask = cv2.inRange(frame, lowerRange, upperRange)
        result = cv2.bitwise_and(frame, frame, mask= mask)
        result[np.where((result == [0,0,0]).all(axis = 2))] = [255,255,255]
        cv2.imwrite(outputName[j] + "{}.jpg".format(i+1), result)
        incser.write(serwrt[j])
        incser.close()
    i+=1
