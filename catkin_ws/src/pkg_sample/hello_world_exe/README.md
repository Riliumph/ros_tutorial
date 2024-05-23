# hello_world_exe

hello, worldを出力するだけの実行ファイル。  
`hello_world_lib`はライブラリを生成したが、こちらは実行ファイルを生成する。

`CMakeLists.txt`の違いを学ぶ。

## ビルド方法

```console
$ cd $HOME/workspace/catkin_ws
$ catkin build
```

## 実行方法

```console
 $ rosrun hello_world_exe hello_world_exe
hello, ROS world
bye, ROS world
```

## CMakeLists.txtのdiff

CMakeLists.txtは自動生成なので、完全に参照で一切の重複なく作られているわけではない。  
なので、特にプロジェクト名がべた書きされてしまっていて、余計なdiffとして登場するため、`${PROJECT_NAME}`などで置換して極力diffが出ないように手動で細工を施してある。

以下は、その細工後のファイルを比べたdiffである。  
必要最低限の部分のdiffしか出ない。

```diff
2c2
< project(hello_world_exe)
---
> project(hello_world_lib)
117d116
< src
121,123c120,122
< # add_library(${PROJECT_NAME}
< #   src/${PROJECT_NAME}/${PROJECT_NAME}.cpp
< # )
---
> add_library(${PROJECT_NAME}
>   src/newbie.cpp
> )
133,136c132
< add_executable(${PROJECT_NAME}
<   src/main.cpp
<   src/newbie.cpp
< )
---
> # add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
149,151c145,147
< # target_link_libraries(${PROJECT_NAME}
< #   ${catkin_LIBRARIES}
< # )
---
> target_link_libraries(${PROJECT_NAME}
>   ${catkin_LIBRARIES}
> )
169,171c165,167
< install(TARGETS ${PROJECT_NAME}
<   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
< )
---
> # install(TARGETS ${PROJECT_NAME}_node
> #   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
> # )
```

分かりにくければ、VSCodeのCompareやMeldなどを使ってビジュアライズされたdiffを見ること。

まとめると、

- プロジェクト名は当然違う。
- exe側はadd_executableを使う。
- lib側はadd_libraryを使う。
- exe側はtarget_link_libraryを使わない。
- lib側はtarget_link_libraryを使う。
- exe側はinstallを行う
- lib側はinstallを行わない（他パッケージからの参照の実験で変わるかも）
