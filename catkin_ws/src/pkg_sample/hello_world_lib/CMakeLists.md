# [CMakeLists](http://wiki.ros.org/ja/catkin/CMakeLists.txt)の解説

主要なところだけ。

## find_package

ビルドに使用するパッケージを指定する。

```cmake
# default
find_package(catkin REQUIRED)
# 修正する場合
find_package(catkin REQUIRED
    COMPONENTS
    roscpp
    # etc...
)
```

> COMPONENTである理由は、「いっぱい同じことタイピングするのが面倒だから」らしい。  
> おそらく、このマクロによって`catkin_xxx`マクロが使えるようになることを示したいのだと思う。  
> e.g. `catkin_INCLUDE_DIRS`など  
> 参照：6.2 なぜCatkinパッケージはコンポーネントとして指定されるのか？

このマクロが実行されたとき、以下の変数が定義される。

- `catkin_INCLUDE_DIRS`
- `catkin_LIBRARIES`
- `catkin_DEFINITIONS`

## catkin_package

catkin謹製のCMakeマクロ。

- INCLUDE_DIRS：src  
  他パッケージに見せるインクルードパス。  
  ヘッダとソースは隣り合っているのが好みなので、includeをsrcに変更済み

## include_directories

> 必須値：`${catkin_INCLUDE_DIRS}`

このパッケージをビルドする際にインクルードパスを追加するマクロ。  
Makefileにおける`INCLUDE`変数（`-I`で作る配列）そのもの。  

ここに必須値が無いと、`#include <ros/ros.h>`ができない。

## add_executable

実行ファイルを作成するマクロ。

## add_library

ライブラリを作成するマクロ。  

## target_link_libraries

引数：`<target> <PRIVATE|PUBLIC|INTERFACE> <library> ...`

リンクするライブラリのパスを追加するマクロ。  
これが無いと`#include <ros/ros.h>`はできるのでAPIまでは到達するが、内部の実装が読めないのでエラーとなる。
