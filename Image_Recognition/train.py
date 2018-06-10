#!/usr/bin/python3
import sys
import os
import random
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
import pickle



def unpickle(file):
	with open(file, 'rb') as fo:
		dict = pickle.load(fo, encoding='bytes')
	return dict

def get_data(file):
	File = os.path.abspath(file)
	dict = unpickle(File)
	for key in dict.keys():
		print(key)
	print("Unpacking {}".format(dict[b'batch_label']))

	
	X = np.asarray(dict[b'data'].T).astype("uint8")
	Yraw = np.asarray(dict[b'labels'])
	Y = np.zeros((10,10000))
	for i in range(10000):
		Y[Yraw[i],i] = 1
	names = np.asarray(dict[b'filenames'])
	return X,Y,names


def visualize_image(X,Y,names,id):
	rgb = X[:,id]
	#print(rgb.shape)
	img = rgb.reshape(3,32,32).transpose([1, 2, 0])
	#print(img.shape)
	plt.imshow(img)
	plt.title(names[id])
	print(Y[id])
	plt.show()
	

if __name__=="__main__":
	X,Y,names = get_data("cifar-10-batches-py/data_batch_1")
	#visualize_image(X,Y,names,20)


	images_placeholder = tf.placeholder(tf.float32, shape=[None, 3072])
	labels_placeholder = tf.placeholder(tf.int64, shape=[None])