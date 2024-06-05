# ROS Service コマンド

## サービスの起動

overlayしていないと次のエラーになるため注意

```console
$ rosservice info /add_two_ints
ERROR: Unable to load type [service_comm/AddTwoInts].
Have you typed 'make' in [service_comm]?
```

### roscoreを起動する

```console
$ roscore
```

### サービスを起動する

別ターミナルでサービスを起動する。

```console
$ rosrun service_comm server_node
[ INFO] [1717608987.950395867]: Ready to add two ints.
```

## サービスの確認

```console
$ rosservice list
/add_two_ints
/add_two_ints_server/get_loggers
/add_two_ints_server/set_logger_level
/rosout/get_loggers
/rosout/set_logger_level
```

## サービスのメッセージ型を取得

```console
$ rosservice type /add_two_ints
service_comm/AddTwoInts
```

## メッセージ型でサービスを検索

```console
$ rosservice find service_comm/AddTwoInts
/add_two_ints
```

## サービスノードの確認

```console
$ rosservice node /add_two_ints
/add_two_ints_server
```

## URIの確認

```console
$ rosservice uri /add_two_ints
rosrpc://vncserver:37365
```

## サービスの引数を確認する

```console
$ rosservice args /add_two_ints
a b
```

## サービスを実行する

```console
$ rosservice call /add_two_ints "a: 2
> b: 5"
sum: 7
```

> 複数の引数は改行する必要がある
