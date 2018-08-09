# Introduction

I installed Tensorflow GPU version on my laptop Gigabyte Aero 14 (7700HQ, GTX 1060), this instruction might be helpful if you want to use tensorflow on a laptop with both Nvidia GPU and Inter integrated GPU, the issue here is that you cannot simply connect your HDMI cable to your nvidia graph card like a desktop, you need to do some extra to solve the conflict.

The os version is: Ubuntu 16.04.4 LTS amd64

## Nvidia driver install

#### 1. Login with non-gui

After installation of the os, you will normally not be able to see the gui desktop because of graphic cards conflict, you can use the following command to access terminal.

```Ctrl + Alt + F1```

Reboot your laptop with ```reboot```

#### 2. Disable nvidia graphics in BIOS
You can login gui version os by disable nvidia graphics in BIOS first, press F12 at start up, choose disable 3D acceleration, then save change and restart, you will be able to login and confugure your network.


#### 3. Follow the instruction
install nvidia graphics driver follow the instraction, I choose to download nvidia-390 here.
https://gist.github.com/wangruohui/df039f0dc434d6486f5d4d098aa52d07

After verify with ```nvidia-smi```, if everything is okay, you can reboot now


#### 4. Enable nvidia graphics in BIOS
For some reason, after enable nvidia GPU, the gui desktop still won't show up, I use tty and install the same driver with apt-get, then it works after reboot

```sudo add-apt-repository ppa:graphics-drivers```
```sudo apt-get update```
```sudo apt-get install nvidia-390 nvidia-settings```

You will now be able to see GeForce GTX 1060/PCIe/SSE2 in All Settings/Details, 

#### 5. Some commands might be useful
As you might need to try several times, here are some useful commands

* switch to nvidia card
```sudo prime-select nvidia```

* check current card in use
```prime-select query```

* disable or enable lightdm
```sudo service lightdm stop```
```sudo service lightdm start```

* uninstall nvidia driver
```sudo apt-get purge nvidia*```


## Install CUDA 9.0
After you successfully installed nvidia driver, the next step is CUDA, for the current(r1.8) version of tensorflow, you should to use CUDA 9.0 with cudnn 7.1.3. however I installed 9.1 at first, tensorflow will not run and thrown a missing file error, the problem was solved after I installed the 9.0 version.

```sudo sh cuda_9.1.85_387.26_linux.run```

In the options
* As you already have a newer driver, you do not need to install driver again. 
* After installation, you should export path and lib path as instructed

In .bashrc
```export PATH=$PATH:/usr/local/cuda-9.0/bin```
```export LD_LIBRARY_PATH=$LD_LIBRARY:/usr/local/cuda-9.0/lib64```

edit ```cuda.conf``` use following command
```sudo bash -c "echo /usr/local/cuda-9.0/lib64/ > /etc/ld.so.conf.d/cuda.conf"```
```sudo ldconfig```

edit ```/etc/environment``` add the following line
```:/usr/local/cuda-9.0/bin```


you can check installation use 

```nvcc --version```

Note: you can compile CUDA C++ program use nvcc just like gcc.

## Install cudnn
follow instruction: 
https://docs.nvidia.com/deeplearning/sdk/cudnn-install/

download all 4 files

install .deb using sudo dpkg -i *.deb

# Install tensorflow

sudo apt-get install python3-pip

pip3 install tensorflow-gpu
