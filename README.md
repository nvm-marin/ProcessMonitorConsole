# Process Monitor
![Badge](https://img.shields.io/badge/Issues-0-green)
![alt text]
<img src="https://github.com/marincolta/ProcessMonitorConsole/blob/main/img.jpeg?raw=true" width="300">

Process Monitor: Maintain focus, minimize distractions. Monitors specified processes, offers gentle reminders, and automatically closes non-work apps. Stay on track and boost productivity during work/study sessions.
## Key Features

- Monitors a customizable list of processes to avoid during work sessions.
- Provides a gentle reminder when a monitored process is detected, promoting productivity and focus.
- Automatically closes non-work-related applications to minimize distractions.
- Lightweight and easy to use.

## Installation

1. Clone this repository or download the latest release.
2. Customize the list of processes to monitor by editing the `proccessestomon` vector in the code.
3. Compile and run the application on your Windows machine.

## Usage

1. Launch Process Monitor on your Windows machine.
2. The application will continuously monitor the specified processes.
3. If a monitored process is detected, Process Monitor will display a reminder message and give you the option to close the application or continue working.
4. Choose the appropriate action based on your intentions and desired level of focus.
5. If there is any problem with Win Security then add the program to exclusions.


## Documentation

https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate  - used to check which key was pressed 

**uintptr_t mem::GetProcId(const char* procName)** which takes as parameter the procname has the function to get the procid of a process:
  1. We create a hSnap (handle) to snapshot all processes
  2. We loop through all processes
  3. We make a storage var to store the process name and convert it to WCHAR
  4. Using the function "_wcsicmp we compare the proccess with the wProcName(given process)
  5. return our procId.

**bool mem::isProcessRunning(const char* procname)** is the same as the function from the above but the difference is this one is a bool function so the return value will be true/false.


## Contributing

Contributions are welcome! If you have any ideas, suggestions, or bug reports, please open an issue or submit a pull request.

