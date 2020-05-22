#### 穷人炼丹

跟别人一起共享GPU服务器炼丹感觉很不爽吗？这个project就是为了解决这些问题而生的。

再也不会有莫名其妙被别人kill掉训练进程了。

不会被丹霸一个人把所有GPU都占满了。

#### 安装
首先打开CMakeLists.txt，设置你机器上的cuda lib的路径，然后cmake。

第一次使用，先make backup_libs

生成钩子库

make cuda; make cudart

安装钩子库

make install_hook

Have fun!

限制能使用的显存量在cudadev100_stub.cpp：gmem_visible指出。

目前本库处于beta版本，能对基于libcuda开发的程序做显存限制功能。已在CUDA 10.0 Tensorflow 1.14版本上，使用全链接网络和lenet5测试成功。欢迎加入测试，提issue，贡献代码。

搭配docker+nvidia docker，在docker容器内置本库，可得合伙炼丹，和谐分用效果。