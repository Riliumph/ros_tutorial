function is_ros_mode {
    if [[ ":$ROS_PACKAGE_PATH:" == *":$(pwd):"* ]]; then
        echo "[ROS]"
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
