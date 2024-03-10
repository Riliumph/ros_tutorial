#!/bin/bash

mkdir -p $HOME/.bin
cp .devcontainer/diff-highlight $HOME/.bin
echo 'export PATH=$HOME/.bin:$PATH' >> $HOME/.bashrc


