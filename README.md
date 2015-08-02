# rosserial_tivac

rosserial library for the Texas Intruments Tiva C series Launchpad board (EK-TM4C123GXL).

Since this is the very first version, it requires a few manual steps to get started.
Prerequisites:
* Energia IDE ( http://energia.nu ) 

## Setup & first example
```
git clone https://github.com/bmagyar/rosserial_tivac
```

* Locate your Energia sketchbook
```
cd ~/sketchbook
```

* Copy the contents of the `sketchbook` folder in the `rosserial_tivac` package over to your sketchbook. This installs the `ros_lib` in `sketchbook/Libraries`, and 3 example applications.
* Open Energia
* Click `File/Examples/hello_publisher`, which opens a rosserial version of the popular ROS tutorial `chatter`.
* Plug your Tiva to the computer and hit the upload button
* Open a terminal, and start up the rosserial server
```
roslaunch rosserial_server serial.launch
```
* Open another terminal and check what comes through on the topic published by the Tiva
```
rostopic echo /chatter
```


## Advanced: 
It is possible to tweak with the speed of the Serial, but for that you need to change `TivaHardware.h` in `ros_lib` as well as the launch file which opens the serial port on the compute.r
