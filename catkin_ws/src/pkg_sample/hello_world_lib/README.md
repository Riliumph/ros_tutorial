# hello world library

`hello, world`を出力するためだけのライブラリ。  
ROSの他パッケージに依存しない独立した機能なので、ROSパッケージにも影響されない。  
しかし、ROSのCMakeLists.txtを使ってビルドするため、CMakeLists.txtの勉強になる。

## ビルド方法

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
