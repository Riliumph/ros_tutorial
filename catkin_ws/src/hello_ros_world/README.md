# hello, ROS world パッケージ

hello, ROS Worldを出力するだけの最低限のパッケージ。

## ビルド方法

```console
$ catkin build
```

## 実行方法

```console
$ rosrun hello_ros_world hello_ros_world_node
hello, ROS world
bye, ROS world
```

## インストールされたものを確認する

調べてみるとこういうディレクトリツリーになっている。

```bash
catkin_ws
├ src/
| └ hello_ros_world/
|   ├ src/
|   | ├ main.cpp
|   | ├ newbie.cpp
|   | └ newbie.hpp
|   ├ CMAkeLists.txt
|   ├ package.xml
|   └ README.md
|
└ devel/
  ├ .private/                      # ビルド結果を格納するディレクトリ
  | └ hello_ros_world/
  |   ├ lib/
  |   | ├ hello_ros_world/
  |   | | └ hello_ros_world_node*  # 実行ファイル（本体）
  |   | ├ libnewbie_lib.so         # DLL（本体）
  |   | └ pkgconfig/               # コンパイラの設定など
  |   └ share/
  |
  └ lib/                           # インストール先（rosrunが認識するディレクトリ）
    ├ hello_ros_world/
    | └ hello_ros_world_node -> .private/hello_ros_world/lib/hello_ros_world/hello_ros_world_node*
    └ libnewbie_lib.so -> .private/hello_ros_world/lib/libnewbie_lib.so* # シンボリックリンク
```
