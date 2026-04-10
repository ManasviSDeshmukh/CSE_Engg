<h1 align="center">Network File System (NFS)</h1>
<h3 align="center">DCC LCA-2</h3>

<p align="center">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=500&size=22&pause=1000&center=true&vCenter=true&width=800&lines=Configure+NFS+Server+and+Client;Mount+Shared+Directory+and+Verify+Access" alt="Typing SVG" />
</p>

---

- **Name:** Manasvi Deshmukh  
- **PRN:** 1032222834  
- **Subject:** DCC (Distributed Computing Concepts)  

---

## Task Description

### Network File System (NFS)
- Configure NFS server and client  
- Mount shared directory and verify access  

---

## Overview

The **Network File System (NFS)** is a distributed file system protocol that allows a client to access files over a network as if they were stored locally.

In this task, an NFS server and client are configured on the same system using WSL (Ubuntu), and file sharing is demonstrated between them.

---

## System Architecture

```mermaid
flowchart LR
    A[NFS Server Directory] --> B[NFS Protocol]
    B --> C[Mounted Client Directory]
    C --> D[File Access & Sharing]
```
---
## Environment Used

- Operating System: Windows (WSL - Ubuntu)
- Server: NFS Kernel Server
- Client: NFS Common
- Terminal: Ubuntu (WSL)

---
## WSL & Ubuntu Installation in Windows

### Step 1: Open PowerShell (IMPORTANT)
- Press Windows Key
- Search: PowerShell
- Right-click → Run as Administrator

### Step 2: Install WSL
```bash
wsl --install
```
- This installs:
  - WSL
  - Ubuntu

<img src="screenshots/installation-wls-ubuntu.png" width="500">

### Step 3: Restart the system 

### Step 4: Open Ubuntu
- Search: Ubuntu
- Open it
- First launch:
  - Set username
  - Set password

---
## Implementation Steps

### Step 1: Install NFS Server and Client
- In Ubuntu Terminal:
```bash
sudo apt update
sudo apt install nfs-kernel-server -y
sudo apt install nfs-common -y
```
<img src="screenshots/nfs-server-install.png" width="500">
<img src="screenshots/nfs-client-install.png" width="500">

### Step 2: Create Shared Directory (Server)
```bash
mkdir ~/nfs_shared
chmod 777 ~/nfs_shared
echo "Hello from Server" > ~/nfs_shared/test.txt
```
<img src="screenshots/server-created-shared-directory.png" width="500">

### Step 3: Configure NFS Exports
- Open exports file:
```bash
sudo nano /etc/exports
```
- Add:
```bash
/home/your-username/nfs_shared *(rw,sync,no_subtree_check,no_root_squash)
```
- Apply configuration:
```bash
sudo exportfs -a
sudo systemctl restart nfs-kernel-server
```
<img src="screenshots/nfs-server-config.png" width="500">

### Step 4: Create Client Mount Directory
```bash
mkdir ~/nfs_client
```

### Step 5: Mount Shared Directory (Client)
```bash
sudo mount -t nfs localhost:/home/your-username/nfs_shared ~/nfs_client
```

### Step 6: Verify Access
- List files:
```bash
ls ~/nfs_client
```
<img src="screenshots/client-setup.png" width="500">

### Step 7: Test File Sharing
- Create file from client:
```bash
echo "Hello from Client" > ~/nfs_client/client.txt
```
<img src="screenshots/test-file-sharing.png" width="500">

- Verify on server:
```bash
ls ~/nfs_shared
```
<img src="screenshots/files-seen-on-server.png" width="500">

---

## Conclusion

The NFS server and client were successfully configured using Ubuntu (WSL). The shared directory was mounted on the client, and file operations were verified, demonstrating seamless file sharing over a network.

---

## Learning Outcomes

- Understanding distributed file systems
- Configuring NFS server and client
- Mounting remote directories
- Verifying real-time file sharing
