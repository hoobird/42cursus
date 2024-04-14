# Born2beRoot - System Administration Exercise

This document outlines the Born2beRoot project, a System Administration exercise focusing on virtualization and server setup.

## Introduction

The project introduces virtualization concepts by setting up a server with specific requirements. It involves creating and configuring a virtual machine in VirtualBox or UTM, installing and securing an operating system, and implementing strict rules for system administration.

## General Guidelines

- VirtualBox or ~~UTM~~ usage is mandatory.
- Turn in a `signature.txt` file containing the signature of your machine’s virtual disk.
- (This repository doesn't contain the a copy of the virtual machine due to its large size)

## Mandatory Part

Set up your first server with specific rules:
- Choose Debian or ~~Rocky~~ as the operating system.
- Install necessary services without a graphical interface.
- Configure security measures such as SSH access (SSHD), firewall settings (UFW), and password policies (login.defs & libpam-pwquality package). 
- Implement user management and sudo configuration.
- Develop a monitoring script to display system information periodically. (CRON)

## ~~Bonus Part~~

~~Complete additional tasks if the mandatory part is perfect:~~
- ~~Set up partitions correctly.~~
- ~~Deploy a functional WordPress website.~~
- ~~Set up a service of choice, excluding NGINX/Apache2.~~
