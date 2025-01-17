## FaceOSC Receiver Templates

2012-2017 by [Dan Wilcox](http://danomatika.com), et al.

This repository contains templates for receiving face tracking OSC ([Open Sound Control](http://opensoundcontrol.org/introduction-osc)) messages from Kyle McDonald's [FaceOSC](https://github.com/kylemcdonald/ofxFaceTracker/downloads) wrapper around Jason Saragih’s [FaceTracker](http://web.mac.com/jsaragih/FaceTracker/FaceTracker.html). Templates are provided for a number of popular arts-engineering toolkits, including Processing, openFrameworks, Max/MSP, Pure Data (pd), and SuperCollider. 

Created for Prof. Golan Levin's [Spring 2012 IACD class](http://golancourses.net/2012spring/) at the [CMU School of Art](http://www.cmu.edu/art/).

--

### Instructions

Download [FaceOSC](https://github.com/kylemcdonald/ofxFaceTracker/releases) and get started with a template project for one of the following creative coding environments:  

* [Processing](http://processing.org/)
	* Requires the [OscP5 library](http://www.sojamo.de/libraries/oscP5/)
	* Known to be compatible with Processing 3.0.
* [OpenFrameworks](http://www.openframeworks.cc/)
	* Currently requires OF version 007+
	* Make sure to copy the FaceOSCReceiver folder into the openframeworks/apps/myApps folder (it must be 3 levels deep)
* [Max/MSP](http://cycling74.com/)
	* requires the [CNMAT Everything for Max package](http://cnmat.berkeley.edu/downloads) for the (OSC-route) object
* [Pure Data Extended](http://puredata.info/)
	* requires *Pd-Extended* for the [OSCroute] and [udpreceive] objects (part of the *mrpeach* external included in Pd-Extended)
* [SuperCollider](http://supercollider.github.io/)


**Further info:**

* FaceOSC uses port 8338 by default for OSC communication.
* The FaceOSC window size is 640 x 480 pixels.

-- 

### OpenFrameworks

#### Generating Project Files

The OpenFrameworks template does not come with the project files pre-generated. You will need to use the OF ProjectGenerator to create them (you should only need to do this once).

To (re)generate project files for an existing project:

* click the "Import" button in the ProjectGenerator
* navigate the to base folder for the OF project ie. "FaceOSCReceiver"
* click the "Update" button

If everything went OK, you should now be able to open the generated project and build/run.
