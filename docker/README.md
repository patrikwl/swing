## Guide: Install docker in wsl (not using Docker Desktop)
https://dev.to/bowmanjd/install-docker-on-windows-wsl-without-docker-desktop-34m9

## Build docker image
docker build -f Dockerfile -t avr-ubuntu:0.0.3 .

## Use docker image in vscode with "Dec Container" extension:
in ${PROJECT_ROOT}/.devcontainer.json add/modify the version of the docker image just assembled.
