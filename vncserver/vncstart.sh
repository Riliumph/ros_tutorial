#!/bin/bash

vncserver :1 -PasswordFile $HOME/.vnc/passwd && tail -F $HOME/.vnc/*.log
