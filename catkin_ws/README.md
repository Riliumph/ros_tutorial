# [ROS環境のインストールとセットアップ](http://wiki.ros.org/ja/ROS/Tutorials/InstallingandConfiguringROSEnvironment)

ビルドに向かう前にやるべきこと

- [ ] ワークスペースをOverlayする

## catkin_make

カレントディレクトリに`src`ディレクトリが無いとエラーを発生させる。  
`src`ディレクトリ配下を走査して、必要なビルド環境を構築する。

以下のツリーが構築される

```bash
catkin_ws/
├ src/    # 必須ディレクトリ
├ build/  # 自動生成（git管理外）
└ devel/  # 自動生成（git管理外）
```

## catkinとは

`catkin`とは、ROSで使われるビルドシステムのこと。  
以下の目的で作成される。

- パッケージ管理  
  機能モジュールを格納、管理する。
- 依存関係の解決  
  catkinビルドシステムは、catkin_ws内のパッケージをビルドし、それらの依存関係を解決する。  
  ROSノードやライブラリなどを開発可能にする。
- 環境設定  
  ROSの実行に必要な環境設定を行う。  
  ROSマスターのURIやパスが含まれる。

## [catkin_ws](http://wiki.ros.org/ja/catkin/Tutorials/create_a_workspace)の作成

ROSは`.catkin_workspace`という空ファイルが存在するディレクトリをワークスペースとして認識する。

> 開発初回のみ実行するためメモとして残す。

カレントディレクトリに色々と配置される。  
Dockerのファイルと混合されるの避けるため、慣例通り`catkin_ws`というディレクトリの中で行うこととした。

```console
$ mkdir -p src
$ catkin_make
```

## [Overlay](http://wiki.ros.org/ja/catkin/Tutorials/workspace_overlaying)

ROSシステムに書いたソースコードを認識させるため、ワークスペースごと認識させる。  
これをOverlayと呼ぶ。

```console
$ source devel/setup.bash
$ echo $ROS_PACKAGE_PATH
/home/ros_dev/workspace/catkin_ws/src:/opt/ros/noetic/share
```

環境変数に取り込まれ、認識されたことが確認できる。

## パッケージの作成

`catkin`を使ってパッケージを作成する。  

```console
$ cd catkin_ws/src/
$ catkin_create_pkg pkg_sample
Created file pkg_sample/package.xml
Created file pkg_sample/CMakeLists.txt
Successfully created files in /home/ros_dev/workspace/catkin_ws/src/pkg_sample. Please adjust the values in package.xml.
```

`catkin_create_pkg`は、カレントディレクトリで以下の作業を行うだけである。

- 引数であるパッケージ名のディレクトリを作成する
- 作成したディレクトリ内部に`package.xml`を作成する
- 作成したディレクトリ内部に`CMakeLists.txt`を作成する

> 特に、`$ROS_PACKAGE_PATH`配下である必要もなければ、そういった`catkin`エコシステムに影響する挙動ではない模様。

### catkinとpackage（要調査）

`catkin`が`package`を認識する仕組みは何だろうか？

## パッケージの履歴

一度`catkin_make`や`catkin build`を行った後に、`ROS_PACKAGE_PATH`を実行してみる。  
当然ながら、初期化されていることが分かる。

```console
$ echo $ROS_PACKAGE_PATH
/opt/ros/noetic/share
```

仮に、パッケージソースを削除していても、`build`ディレクトリ内部に残ったキャッシュがある限り、`devel/setup.sh`を実行したらキャッシュがロードされる。

```console
$ source ./devel/setup.bash
$ echo $ROS_PACKAGE_PATH
/home/ros_dev/workspace/catkin_ws/src/cacheed_ros/cached_pkg:/opt/ros/noetic/share
```

> 例えば、次のようなファイルが存在する。  
> `build/cached_pkg/catkin_generated/setup_cached.sh`
