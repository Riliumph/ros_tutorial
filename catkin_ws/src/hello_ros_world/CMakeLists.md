# [CMakeLists](http://wiki.ros.org/ja/catkin/CMakeLists.txt)の解説

有効にしたところだけ

## project

```cmake
project (your-project-name)
```

変数`${PROJECT_NAME}`を定義するマクロ。

## find_package

```cmake
find_package(catkin REQUIRED
    COMPONENTS
    roscpp
    # etc...
)
```

ビルドに使用するパッケージを指定する。  
このマクロが実行されたとき、以下の変数が定義される。

- `catkin_INCLUDE_DIRS`
- `catkin_LIBRARIES`
- `catkin_DEFINITIONS`

> COMPONENTである理由は、「いっぱい同じことタイピングするのが面倒だから」らしい。  
> おそらく、このマクロによって`catkin_xxx`マクロが使えるようになることを示したいのだと思う。  
> e.g. `catkin_INCLUDE_DIRS`など  
> 参照：6.2 なぜCatkinパッケージはコンポーネントとして指定されるのか？

## catkin_package

```cmake
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hello_library
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)
```

catkin謹製のCMakeマクロ。

### INCLUDE_DIRS

他パッケージに公開するインクルードパス。  

> ヘッダとソースは隣り合っているのが好みなので、includeをsrcに変更済み

### LIBRARIES

このパッケージでビルドされるライブラリで、他パッケージに公開するライブラリを指定する。  
他パッケージがリンクできるようになる。

### CATKIN_DEPENDS

このパッケージが依存するcatkinパッケージを指定する。  
ここに記載すると、`package.xml`にも追記が必要。

```xml
<?xml version="1.0"?>
<package format="2">
（省略）
  <build_depend>roscpp</build_depend>
  <exec_depend>roscpp</exec_depend>
</package>
```

### DEPENDS

このパッケージが依存するシステムライブラリを指定する。

## include_directories

```cmake
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
```

このパッケージをビルドする際にインクルードパスを追加するマクロ。  
Makefileにおける`INCLUDE`変数（`-I`で作る配列）そのもの。  

ここに必須値が無いと、`#include <ros/ros.h>`ができない。

## add_executable

```cmake
add_executable(<bin name>
  <bin's source code>
)
```

実行ファイルを定義するマクロ。

## add_library

```cmake
add_library(<lib name>
  <lib's source code>
)
```

ライブラリを定義するマクロ。

## target_link_libraries

```cmake
target_link_libraries(<linked bin name>
  ${catkin_LIBRARIES}
  <lib name>
)
```

実行バイナリを指定し、それにリンクするライブラリのパスを追加するマクロ。  
これが無いと`#include <ros/ros.h>`はできるのでAPIまでは到達するが、内部の実装が読めないのでエラーとなる。

## install

```cmake
install(
  TARGETS ${PROJECT_NAME}_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
```

`install`マクロは実行バイナリ、ライブラリ、ヘッダ用にそれぞれ引数がある。  
それぞれを見比べること。

これを有効化しないと、インストールされないので`rosrun`が実行ファイルを見つけられない。  
`${CATKIN_PACKAGE_BIN_DESTINATION}`は`devel/lib`配下を指す。  
詳しくはREADME.mdを参照。
