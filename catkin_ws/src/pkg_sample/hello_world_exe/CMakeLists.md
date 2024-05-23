# [CMakeLists](http://wiki.ros.org/ja/catkin/CMakeLists.txt)の解説

主要なところだけ。
基本は、hello_world_libとの差分である。

## install

これを有効化しないと、インストールされないので`rosrun`が実行ファイルを見つけられない。

`${CATKIN_PACKAGE_BIN_DESTINATION}`はどこかというと

```bash
catkin_ws/
├ src/
├ build/
├ logs/
└ devel/
  ├ env.sh
  ├ etc...
  └ lib/
    └ hello_world_exe/
      └ hello_world_exe*
```
