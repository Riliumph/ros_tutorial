function is_ros_mode {
    IFS=':' read -ra paths <<< "$ROS_PACKAGE_PATH"
    current_dir=$(pwd)
    # 現在のディレクトリがROS_PACKAGE_PATHのどれかのパスの配下にあるかを判定
    found=false
    for path in "${paths[@]}"; do
        if [[ "$current_dir" == "$path"* ]]; then
            found=true
            break
        fi
    done
    if [ "$found" ];then
        echo "(ROS)"
    fi
}

function overlay {
    if ! source ./devel/setup.bash; then
        return 1
    fi
    echo ${ROS_PACKAGE_PATH}
    local ros_mode_func='$(is_ros_mode)'
    if [[ "${PS1}" != *"${ros_mode_func}"* ]]; then
        export PS1="${ros_mode_func}${PS1}"
    fi
}
