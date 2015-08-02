# rosserial_tivac

rosserial library for the Texas Intruments Tiva C series Launchpad board (EK-TM4C123GXL).

### Button publisher
<a href="http://www.youtube.com/watch?feature=player_embedded&v=I4dPV7aJafk
" target="_blank"><img src="http://img.youtube.com/vi/I4dPV7aJafk/0.jpg" 
alt="summary" width="240" height="180" border="10" style="float" /></a>

### LED color subscriber
<a href="http://www.youtube.com/watch?feature=player_embedded&v=--hj8MRKHUM
" target="_blank"><img src="http://img.youtube.com/vi/--hj8MRKHUM/0.jpg" 
alt="summary" width="240" height="180" border="10" style="float "/></a>


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
