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
