# Nvidia driver install

1. non-gui

Ctrl + Alt + F2

2. Disable nvidia in BIOS
disable 3D acceleration, so that you can login gui
confugure network

3. add driver ppa

sudo add-apt-repository ppa:graphics-drivers

sudo apt-get update


sudo apt-get install nvidia-390 nvidia-settings




* PASSWORD: M1919C5*6$lax

* switch to nvidia card
sudo prime-select nvidia

* check current card in use
prime-select query

4. Enable nvidia in BIOS





* disable or enable intel 
sudo service lightdm stop
sudo service lightdm start


* install cuda
sudo sh cuda_9.1.85_387.26_linux.run



sudo apt-get purge nvidia*


* Follow instruction, able to install, unable to show gui
https://gist.github.com/wangruohui/df039f0dc434d6486f5d4d098aa52d07

* execute:
sudo apt-get install nvidia-390

problem solved

## Install CUDA 9.0

sudo sh *.run

Install without driver
export path and lib path as instructed

In .bashrc
export PATH=$PATH:/usr/local/cuda-9.0/bin
export LD_LIBRARY_PATH=$LD_LIBRARY:/usr/local/cuda-9.0/lib64

sudo bash -c "echo /usr/local/cuda-9.0/lib64/ > /etc/ld.so.conf.d/cuda.conf"
sudo ldconfig

edit /etc/environment add line
:/usr/local/cuda-9.0/bin

# Install cudnn
follow instruction: 
https://docs.nvidia.com/deeplearning/sdk/cudnn-install/

download all 4 files

install .deb using sudo dpkg -i *.deb

# Install tensorflow

sudo apt-get install python3-pip

pip3 install tensorflow-gpu
