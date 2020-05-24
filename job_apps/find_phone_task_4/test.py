#!/usr/bin/env python3

# author: Arun Ponnusamy
# website: https://www.arunponnusamy.com

# object detection example
# usage: python object_detection.py <input_image>

# import necessary packages
import cvlib as cv
# from cvlib.object_detection import draw_bbox
import sys
import cv2

# read input image
image = cv2.imread("sample.jpg")

# apply object detection
# bbox, label, conf = cv.detect_common_objects(image)

# print(bbox, label, conf)

# draw bounding box over detected objects
# out = draw_bbox(image, bbox, label, conf)

# display output
# press any key to close window           
cv2.imshow("object_detection", image)
cv2.waitKey()

# save output
cv2.imwrite("object_detection.jpg", image)

# release resources
cv2.destroyAllWindows()