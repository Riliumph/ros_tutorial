# [CMakeLists](http://wiki.ros.org/ja/catkin/CMakeLists.txt)の解説

Action通信に特化したところだけ

## find_package

```cmake
find_package(catkin REQUIRED
  genmsg
  actionlib_msgs
)
```

アクション通信を行うので、アクション通信で使われるライブラリを指定している。

- `genmsg`  
  .actionや.srvファイルから、C++やPythonのクラス定義を自動生成するツール。  
- `actionlib_msgs`  
  ROSのアクション通信機能を提供するパッケージ。

## add_action_files

```cmake
add_action_files(
  DIRECTORY <directory name>
  FILES
  <action filename>
)
```

### DIRECTORY

アクションファイルを格納してあり、追跡するディレクトリ名。  
パッケージルートから追跡する。

基本的には以下のようなディレクトリツリー

```bash
your-package
├ src/
├ action/
| └ DoDishes.action
├ CMakeLists.txt
└ package.xml
```
