import numpy as np
import cv2

def translate(image,x,y):
	M = np.float32([[1,0,x],[0,1,y]])
	shifted = cv2.warpAffine(image,M,(image.shape[1],image.shape[0]))
	return shifted

def rotate(image,angle,center = None,scale=1.0):
	(h,w) = image.shape[:2]
	if center is None:
		center = (w/2,h/2)
	M = cv2.getRotationMatrix2D(center,angle,scale)
	rotated = cv2.warpAffine(image,M,(w,h))
	return rotated

def resizeByWidth(image,w):
	r = w/image.shape[1]
	dim = (int(w),int(image.shape[0]*r))
	resized = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
	return resized

def resizeByHeight(image,h):
	r = h/image.shape[0]
	dim = (int(image.shape[1]*r),int(h))
	resized = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
	return resized

