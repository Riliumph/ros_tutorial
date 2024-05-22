# hello world library

`hello, world`を出力するためだけのライブラリ。  
ROSの他パッケージに依存しない独立した機能なので、ROSパッケージにも影響されない。  
しかし、ROSのCMakeLists.txtを使ってビルドするため、CMakeLists.txtの勉強になる。

## ROSパッケージのビルド方法

```console
$ cd $HOME/workspace/catkin_ws
$ catkin build
----------------------------------------------------------------------
Profile:                     default
Extending:          [cached] /opt/ros/noetic
Workspace:                   /home/ros_dev/workspace/catkin_ws
----------------------------------------------------------------------
Build Space:        [exists] /home/ros_dev/workspace/catkin_ws/build
Devel Space:        [exists] /home/ros_dev/workspace/catkin_ws/devel
Install Space:      [unused] /home/ros_dev/workspace/catkin_ws/install
Log Space:          [exists] /home/ros_dev/workspace/catkin_ws/logs
Source Space:       [exists] /home/ros_dev/workspace/catkin_ws/src
DESTDIR:            [unused] None
----------------------------------------------------------------------
Devel Space Layout:          linked
Install Space Layout:        None
----------------------------------------------------------------------
Additional CMake Args:       None
Additional Make Args:        None
Additional catkin Make Args: None
Internal Make Job Server:    True
Cache Job Environments:      False
----------------------------------------------------------------------
Buildlisted Packages:        None
Skiplisted Packages:         None
----------------------------------------------------------------------
Workspace configuration appears valid.
----------------------------------------------------------------------
[build] Found 1 packages in 0.0 seconds.
[build] Package table is up to date.
Starting  >>> hello_world_lib
Finished  <<< hello_world_lib                [ 0.8 seconds ]
[build] Summary: All 1 packages succeeded!
[build]   Ignored:   None.
[build]   Warnings:  None.
[build]   Abandoned: None.
[build]   Failed:    None.
[build] Runtime: 0.8 seconds total.
```

## 実行ファイルのビルド方法

```console
$ make all
```

## 実行ファイルの実行方法

```console
$ ./bin/hello_world
hello, ROS world
bye, ROS world
```

### 注意事項：ライブラリが見つからない

```console
$ ./bin/hello_world
./hello_world: error while loading shared libraries: libhello_world_lib.so: cannot open shared object file: No such file or directory
```

```console
$ ldd ./bin/hello_world
        linux-vdso.so.1 (0x00007ffff63e4000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fdfcabe1000)
        libhello_world_lib.so => not found
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fdfcabc6000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fdfca9d4000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fdfca885000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fdfcadd3000)
```

動的リンカがパスを見れないらしい。  
動的リンカの設定方法を見直した方が良い。

きっと`-rpath`とかの設定を忘れているだけだろう。  
正しい設定が出来ていれば、次のような情報が取れる

```console
$ ldd ./bin/hello_world
        linux-vdso.so.1 (0x00007ffe869f3000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fb601581000)
        libhello_world_lib.so => /home/ros_dev/workspace/catkin_ws/devel/lib/libhello_world_lib.so (0x00007fb60157c000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fb601561000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fb60136f000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fb601220000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fb601773000)
```

> 参考：[ubuntu manuals](https://manpages.ubuntu.com/manpages/focal/ja/man8/ld-linux.so.8.html)
