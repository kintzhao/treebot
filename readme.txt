ARToolKitPlus-2.3.1  + qtcreator+ artoolkitplus +opencv 

erro : QTerro:Size mismatch for type ‘QPaintBufferCacheEntry’ [1024]. Previously registered size 0 

参见说明：http://blog.csdn.net/zyh821351004/article/details/46641573
---------------------------------------------------------------------------------------------------------------------------------------------------
QMetaType::registerType: Binary compatibility break — Size mismatch for type ‘QPaintBufferCacheEntry’ [1024]. Previously registered size 0, now regist

        发现这个       QMetaType::registerType: Binary compatibility break — Size mismatch for type ‘QPaintBufferCacheEntry’ [1024]. Previously registered size 0, now regist

        发现这个问题出现与连接时依赖opencv有关， 推测问题主要出在安装的opencv 与qt4 ,qt5间的关系构成的版本问题。。应该是opencv lib编译时依赖了qt4.而我的工程需要依赖qt5..

如：my problem is solved. this is happened because i used opencv libs in my project and compiled it with qt4. i rebuild opencv with qt5 and now everything is ok。

解决：

       1.  将qt5设为默认库：参考：http://blog.csdn.net/zyh821351004/article/details/43273763

         sudo apt-get install qt5-default

        2. 重新编译opencv:   （想快速点，记得将example关闭）

参考sh文件：http://blog.csdn.net/zyh821351004/article/details/43488945           

cd opencv-2.4.9  
mkdir build  
cd build  
#注：CMAKE编译的ＯＮ与ｏff.    第一个用在pcduino。　第二个在ＰＣ可以装。在pcduino上的ｐｙｔｈｏｎ部分的编译出问题。  
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..  
make -j4  
sudo make install  
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'  
sudo ldconfig  
echo "OpenCV 2.4.9 ready to be used"   

注：cmake 与 make 之后的一系列也是需要的 。。

     3. 重新编译原工程。OK。


