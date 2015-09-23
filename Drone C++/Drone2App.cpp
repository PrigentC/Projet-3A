/*
* Copyright (c) 2011 Jean-Marc Perronne
* Ensisa, 12 rue des Freres Lumieres, F-68093 Mulhouse cedex
* All rights reserved.
*
* The copyright of this software is owned by Werner Randelshofer.
* You may not use, copy or modify this software, except in
* accordance with the license agreement you entered into with
* Jean-Marc Perronne. For details see accompanying license terms.
*/

#ifndef DRONE2APP_H
#define DRONE2APP_H

class Drone2App
{
	static Drone2APP::MouseHandler setupMouse3d()
	{
		final  boolean IS_OVERLAPPED = true;

		std:cout << "mouse3D setup...";

		// 3dconnexion devices discovering
		DeviceManager dvm = DeviceManager.instance();
		dvm.discoverDevices(IS_OVERLAPPED);

		System.out.println("hid devices number: " + dvm.devicesNbr());

		int devicesIds[] = dvm.devicesIDS();
		System.out.print("hid devices ids:");

		for (int id : devicesIds)
			System.out.print(" " + Integer.toHexString(id));

		if (devicesIds.length != 0)
		{
			MouseHandler mh = new TakeOffLandHandler(0, devicesIds[0], new BasicMouseAdapter());
			mh.initialize();
			if (mh.failed()) System.err.println("Mouse3D setup failed!");
			else return mh;
		}
		return null;
	}

	static void main(String[] args)
	{

		try
		{
			/*final MouseHandler mh = setupMouse3d();
			if (mh==null) return;*/

			final KeyboardHandler kh = new KeyboardHandler();

			DroneHandler drone = new DroneHandler(kh);
			//drone.sendOnlyMode();
			//drone.sendDumpOnlyMode(System.out);
			drone.sendAndDumpMode(System.err);

			final Cockpit cockpit = new Cockpit(drone);

			EventQueue.invokeAndWait(new Runnable()
			{
				public void run()
			{
				cockpit.setup();
			}
			});

			//NavdataDemoDumper dumper = new NavdataDemoDumper();
			NavdataDemoRecorder navdataDemoRecorder = new NavdataDemoRecorder(new NavdataDemoRawWriter(DroneConstants.NAVDATA_DEMO_SEPARATOR), DroneConstants.NAVDATA_DEMO_RECORDS_DIR, DroneConstants.NAVDATA_DEMO_EXT);
			PictureRecorder pictureRecorder = new PictureRecorder(new PictureWriter(DroneConstants.PICTURE_WRITER_FORMAT), DroneConstants.PICTURES_RECORDS_DIR);
			VideoRecorder videoRecorder = new VideoRecorder(new AviWriter(AVIOutputStream.VideoFormat.JPG), DroneConstants.VIDEO_RECORDS_DIR);

			//drone.registerOptionVisitor(dumper);
			drone.registerOptionVisitor(DroneConstants.NAVDATA_DEMO_RECORDER_KEY, navdataDemoRecorder);
			drone.registerOptionVisitor(DroneConstants.COCKPIT_KEY, cockpit.updater());

			drone.registerImageConsumer(DroneConstants.PICTURE_RECORDER_KEY, pictureRecorder);
			drone.registerImageConsumer(DroneConstants.VIDEO_RECORDER_KEY, videoRecorder);
			drone.registerImageConsumer(DroneConstants.COCKPIT_KEY, cockpit.updater());

			drone.start();
			drone.run();

			if (navdataDemoRecorder.recording()) navdataDemoRecorder.stop();
			if (videoRecorder.recording()) videoRecorder.stop();

			/*
			Runtime.getRuntime().addShutdownHook(new Thread() {
			public void run() { if (mh != null) mh.closeMouse(); }
			});
			*/
		}
		catch (SocketException e)
		{
			e.printStackTrace();
		}
		catch (UnknownHostException e)
		{
			e.printStackTrace();
		}
		catch (BadInterfaceException e)
		{
			e.printStackTrace();
		}
		catch (InterruptedException e)
		{
			e.printStackTrace();
		}
		catch (InvocationTargetException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		finally
		{
			System.exit(0);
		}
	}
}

#endif
