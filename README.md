
# Operating Systems Theory Notes By Urooj Islam

## 1. Introduction to Operating Systems

### Definition
An Operating System (OS) is system software that manages computer hardware and software resources and provides common services for computer programs. It acts as an intermediary between users and the computer hardware.

### Functions of an OS
1. **Process Management**: Handles process creation, scheduling, execution, and termination. Manages the CPU's time and resources among various processes.
2. **Memory Management**: Manages the system's memory, including RAM and cache. It handles memory allocation, deallocation, and virtual memory management.
3. **File System Management**: Manages files on storage devices, including file creation, deletion, reading, writing, and organization. Provides a hierarchical directory structure.
4. **Device Management**: Manages input/output devices through device drivers, enabling communication between hardware and software.
5. **Security and Access Control**: Ensures system security by managing user permissions, authentication, and protection against unauthorized access.

### Examples
- **Windows**: Developed by Microsoft, used in personal computers and workstations.
- **macOS**: Developed by Apple for Macintosh computers, known for its user-friendly interface and integration with Apple's ecosystem.
- **Linux**: An open-source OS used in servers, desktops, and embedded systems, known for its flexibility and security.
- **Android**: Developed by Google for mobile devices, offering a wide range of applications and customization options.

## 2. OS Architecture

### Layered Architecture
1. **Hardware**: The physical components of the computer, such as the CPU, RAM, and storage devices.
2. **Kernel**: The core part of the OS that manages hardware resources and system operations. It handles process scheduling, memory management, and device control.
3. **System Libraries**: Provide functions and services that applications use to interact with the OS, such as file manipulation and input/output operations.
4. **User Interface**: The interface through which users interact with the OS, including graphical user interfaces (GUIs) and command-line interfaces (CLIs).

### Kernel Modes
- **User Mode**: The mode in which user applications run. It has restricted access to hardware and system resources to prevent accidental or malicious interference.
- **Kernel Mode**: The mode in which the OS kernel operates, with full access to hardware and system resources. It handles critical tasks and manages system operations.

## 3. Processes and Threads

### Processes
A process is an instance of a program in execution. It includes the program code, its current activity, and its allocated resources.

- **Process States**:
  - **New**: The process is being created.
  - **Ready**: The process is waiting to be assigned to the CPU.
  - **Running**: The process is currently being executed by the CPU.
  - **Blocked**: The process is waiting for an event or resource, such as I/O completion.
  - **Terminated**: The process has completed execution and is being removed from memory.

### Threads
Threads are the smallest unit of execution within a process. A process can have multiple threads, which share the same memory space but execute independently.

- **Multithreading**: Enables concurrent execution of multiple threads within a single process, improving performance and resource utilization. Threads within the same process can communicate more easily and share resources.

## 4. Memory Management

### Concepts
- **Physical Memory**: Refers to the actual RAM installed in the computer, used to store data and instructions for active processes.
- **Virtual Memory**: An abstraction that provides each process with the illusion of a large and contiguous memory space. It allows the system to use disk space to extend physical memory.

### Techniques
- **Paging**: Divides memory into fixed-size pages. This helps manage memory more efficiently and reduces fragmentation by allowing non-contiguous allocation.
- **Segmentation**: Divides memory into variable-sized segments based on logical divisions, such as code, data, and stack segments. Segments can grow or shrink independently.

### Allocation Strategies
- **Contiguous Allocation**: Allocates a single contiguous block of memory to a process. This can lead to fragmentation and inefficient use of memory.
- **Paging**: Allocates memory in non-contiguous pages, reducing fragmentation and allowing more efficient memory use.
- **Segmentation**: Allocates memory in segments, which can be of varying sizes and provide logical divisions for processes.

## 5. File Systems

### Purpose
File systems manage how data is stored, organized, and accessed on storage devices. They provide an abstraction for users and applications to interact with data.

### Components
- **File**: A collection of data stored on disk. It has attributes such as name, size, type, and permissions.
- **Directory**: A container that holds files and other directories, creating a hierarchical structure for organizing data.

### File Operations
- **Creation**: Making a new file in the file system.
- **Deletion**: Removing an existing file from the file system.
- **Reading**: Accessing and retrieving data from a file.
- **Writing**: Modifying or adding data to a file.

### File System Types
- **FAT (File Allocation Table)**: An older file system used in DOS and early versions of Windows, known for its simplicity and wide compatibility.
- **NTFS (New Technology File System)**: A modern file system used in Windows with features like file permissions, encryption, and large volume support.
- **EXT (Extended File System)**: A family of file systems used in Linux, offering various features and improvements over time.

## 6. Process Scheduling

### Objective
Process scheduling determines the order in which processes are executed by the CPU, ensuring efficient utilization of CPU time and resources.

### Scheduling Algorithms
- **First-Come, First-Served (FCFS)**: Processes are executed in the order they arrive in the ready queue. Simple but can lead to long wait times for shorter processes.
- **Shortest Job Next (SJN)**: Processes with the shortest burst time are scheduled first. It minimizes average waiting time but may lead to starvation of longer processes.
- **Round Robin (RR)**: Each process is assigned a fixed time slice or quantum in a circular order. It ensures fairness but can lead to high turnaround time.
- **Priority Scheduling**: Processes are scheduled based on priority levels. Higher-priority processes are executed before lower-priority ones, which may lead to starvation of lower-priority processes.

### Concepts
- **Context Switching**: The process of saving the state of the currently running process and loading the state of the next process to be executed. It allows multiple processes to share the CPU.

## 7. Inter-Process Communication (IPC)

### Purpose
IPC mechanisms enable processes to communicate and synchronize with each other, allowing them to cooperate and share data.

### Techniques
- **Shared Memory**: Allows multiple processes to access the same memory region for communication. Efficient but requires synchronization to avoid conflicts.
- **Message Passing**: Processes send and receive messages to communicate. It provides a clear interface for communication but can be slower than shared memory.

### Methods
- **Pipes**: Provide a unidirectional communication channel between processes, typically used for simple data exchange.
- **Message Queues**: Allow processes to send and receive messages in a queue, enabling more flexible communication patterns.

## 8. Deadlock

### Definition
Deadlock occurs when two or more processes are unable to proceed because each is waiting for the other to release resources, creating a cycle of dependency.

### Conditions
- **Mutual Exclusion**: Resources cannot be shared and are held by one process at a time.
- **Hold and Wait**: Processes holding resources can request additional resources.
- **No Preemption**: Resources cannot be forcibly taken from a process.
- **Circular Wait**: A circular chain of processes exists, with each process waiting for a resource held by the next process in the chain.

### Prevention
- **Avoidance**: Uses algorithms like Banker's Algorithm to avoid deadlock by ensuring that resource allocation does not lead to a circular wait.
- **Detection and Recovery**: Detects deadlock conditions and takes actions to recover from them, such as terminating processes or preempting resources.

## 9. Device Management

### Purpose
Device management involves controlling and coordinating hardware devices through device drivers, which act as intermediaries between the OS and hardware.

### Components
- **Device Driver**: Software that communicates with hardware devices and translates OS commands into device-specific operations. Each type of hardware has a corresponding driver.
- **Device Manager**: Part of the OS that handles device requests, manages device drivers, and coordinates device operations.

## 10. Security and Protection

### Objectives
Security and protection mechanisms ensure that unauthorized users do not access system resources and that data integrity and confidentiality are maintained.

### Mechanisms
- **Authentication**: Verifies the identity of users through methods such as passwords, biometrics, or multi-factor authentication.
- **Authorization**: Determines access rights and permissions for users based on their identity and role. Controls what actions users can perform on resources.
- **Encryption**: Protects data by encoding it into a secure format that can only be decoded by authorized entities. Ensures confidentiality and integrity of data.

### Types of Security
- **Physical Security**: Protects hardware from physical damage, theft, or unauthorized access.
- **Network Security**: Safeguards data transmitted over networks using measures such as firewalls, encryption, and intrusion detection systems.
- **Application Security**: Ensures that applications are secure from vulnerabilities and attacks, including secure coding practices and regular security updates.

## 11. System Calls

### Definition
System calls provide an interface between user applications and the OS kernel, allowing applications to request services from the OS.

### Examples


- **File Operations**: `open()`, `read()`, `write()`, `close()`
- **Process Management**: `fork()`, `exec()`, `wait()`, `exit()`
- **Memory Management**: `mmap()`, `munmap()`
- **Device Management**: `ioctl()`, `read()`, `write()`

### Purpose
System calls enable applications to perform operations that require access to hardware or system resources, such as file manipulation, process control, and communication.
