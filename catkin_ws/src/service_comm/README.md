# Service通信

引数を二つ渡すとその加算結果を返すサービス

## 実行方法

共通して、各ターミナルでROSを認識させること

```console
$ cd catkin_ws
$ overlay 
/home/ros_dev/workspace/catkin_ws/src/service_comm:/opt/ros/noetic/share
```

### roscore ターミナル

```console
$ roscore
```

### Server ターミナル

```console
$ rosrun service_comm server_node
[ INFO] [1717010232.870429200]: Ready to add two ints.
--- リクエスト到着後
[ INFO] [1717010338.067502748]: request: x=1, y=3
[ INFO] [1717010338.067547453]: sending back response: [4]
```

### Client ターミナル

```console
$ rosrun service_comm client_node 1 3
--- レスポンス到着後
[ INFO] [1717010338.067721407]: Sum: 4
```
