# ライブラリビルドするときのCMakeLists.txt

## find_package

依存するパッケージの設定を行う。

```cmake
find_package(catkin REQUIRED
    COMPONENTS
    roscpp
    std_msgs
    service_comm
)
```

このモジュールが依存しているパッケージを解説する。

### [`roscpp`](http://wiki.ros.org/roscpp)

あたかもROS全般のライブラリに思えるが、C++でTopic通信、Service通信、Parametersを実行するためのクライアントライブラリ。  
Action通信は含まれないので使えない。  
また、`ros::init`はデフォルト機能なので、このパッケージが無くても機能する。

> 正直、命名センスが無いとしか思えない

### `service_comm`

このリポジトリに存在するパッケージ。  
`service_comm`が生成するメッセージファイルを使用しているため`find_package`で指定する必要がある。

#### 注意点：find_packageが定義されていない場合

`catkin build`で以下のエラーが発生する。

```bash
Errors     << service_cli_lib:make /home/ros_dev/workspace/catkin_ws/logs/service_cli_lib/build.make.000.log
/home/ros_dev/workspace/catkin_ws/src/service_cli_lib/src/client.cpp:5:10: fatal error: service_comm/AddTwoInts.h: No such file or directory
    5 | #include "service_comm/AddTwoInts.h"
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
make[2]: *** [CMakeFiles/service_cli_lib.dir/build.make:63: CMakeFiles/service_cli_lib.dir/src/client.cpp.o] Error 1
make[1]: *** [CMakeFiles/Makefile2:169: CMakeFiles/service_cli_lib.dir/all] Error 2
make: *** [Makefile:141: all] Error 2
cd /home/ros_dev/workspace/catkin_ws/build/service_cli_lib; catkin build --get-env service_cli_lib | catkin env -si  /usr/bin/make --jobserver-auth=3,4; cd -
```

`find_package`の仕様である`<package-name>_INCLUDE_DIRS`が定義されないため、インクルードパスが見えなくなっている。  
解決するには`find_package`を設定する。

#### 注意点：find_packageのみ設定した場合

`catkin build`で以下のエラーが発生する。

```cmake
Errors     << service_cli_lib:cmake /home/ros_dev/workspace/catkin_ws/logs/service_cli_lib/build.cmake.000.log
CMake Error at /opt/ros/noetic/share/catkin/cmake/catkinConfig.cmake:83 (find_package):
  Could not find a package configuration file provided by "service_comm" with
  any of the following names:

    service_commConfig.cmake
    service_comm-config.cmake

  Add the installation prefix of "service_comm" to CMAKE_PREFIX_PATH or set
  "service_comm_DIR" to a directory containing one of the above files.  If
  "service_comm" provides a separate development package or SDK, be sure it
  has been installed.
Call Stack (most recent call first):
  CMakeLists.txt:10 (find_package)


cd /home/ros_dev/workspace/catkin_ws/build/service_cli_lib; catkin build --get-env service_cli_lib | catkin env -si  /usr/bin/cmake /home/ros_dev/workspace/catkin_ws/src/service_cli_lib --no-warn-unused-cli -DCATKIN_DEVEL_PREFIX=/home/ros_dev/workspace/catkin_ws/devel/.private/service_cli_lib -DCMAKE_INSTALL_PREFIX=/home/ros_dev/workspace/catkin_ws/install; cd -
```

`find_package`が設定されていることで`service_comm_INCLUDE_DIRS`が定義されたためインクルードされAPIへの到達は成功する。  
しかし、内部の実装ファイルが見えないため`cmake`のコンフィグファイルを定義しろというエラーを発生させている。
解決するには`catkin_package`を作るか。自分で作るか。

#### 注意点：find_package + catkin_packageを設定した場合

`catkin build`で以下のエラーが発生する。

```cmake
Errors     << service_cli_lib:cmake /home/ros_dev/workspace/catkin_ws/logs/service_cli_lib/build.cmake.001.log
CMake Error at /opt/ros/noetic/share/catkin/cmake/catkin_package.cmake:196 (message):
  catkin_package() the catkin package 'roscpp' has been find_package()-ed but
  is not listed as a build dependency in the package.xml
Call Stack (most recent call first):
  /opt/ros/noetic/share/catkin/cmake/catkin_package.cmake:102 (_catkin_package)
  CMakeLists.txt:105 (catkin_package)


cd /home/ros_dev/workspace/catkin_ws/build/service_cli_lib; catkin build --get-env service_cli_lib | catkin env -si  /usr/bin/cmake /home/ros_dev/workspace/catkin_ws/src/service_cli_lib --no-warn-unused-cli -DCATKIN_DEVEL_PREFIX=/home/ros_dev/workspace/catkin_ws/devel/.private/service_cli_lib -DCMAKE_INSTALL_PREFIX=/home/ros_dev/workspace/catkin_ws/install; cd -
```

`catkin_package`マクロで依存関係等をエクスポートした場合、`package.xml`にも同様の記述を書く必要がある。

#### 完成形：find_package + catkin_package + package.xml

これが完成形。  
もう、ライブラリビルドして外部に知られるわけじゃないし、`catkin_package`書かなくてもいいか～～～  
じゃなくて、`find_package`書いたら`catkin_package`も書くし、`package.xml`も書け。

それが一番いい。
