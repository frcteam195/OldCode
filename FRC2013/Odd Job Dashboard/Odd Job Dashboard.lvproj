<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="12008004">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="NI.SortType" Type="Int">3</Property>
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Support" Type="Folder">
			<Item Name="Parse Digital Module.vi" Type="VI" URL="../Parse Digital Module.vi"/>
			<Item Name="Update Battery Indicator.vi" Type="VI" URL="../Update Battery Indicator.vi"/>
			<Item Name="Save DB Images.vi" Type="VI" URL="../Save DB Images.vi"/>
			<Item Name="Receive DS Packet.vi" Type="VI" URL="../Receive DS Packet.vi"/>
			<Item Name="App EXE.ico" Type="Document" URL="../App EXE.ico"/>
			<Item Name="Decode Status Byte.vi" Type="VI" URL="../Decode Status Byte.vi"/>
			<Item Name="Elapsed Time.vi" Type="VI" URL="../Elapsed Time.vi"/>
		</Item>
		<Item Name="TypeDefs" Type="Folder">
			<Item Name="DStoPCPacketTypeDef.ctl" Type="VI" URL="../DStoPCPacketTypeDef.ctl"/>
		</Item>
		<Item Name="Dashboard Main.vi" Type="VI" URL="../Dashboard Main.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="IMAQ Create" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ Create"/>
				<Item Name="IMAQ Image.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/IMAQ Image.ctl"/>
				<Item Name="Image Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Type"/>
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="IMAQ Write File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write File 2"/>
				<Item Name="IMAQ Write BMP File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write BMP File 2"/>
				<Item Name="IMAQ Write Image And Vision Info File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write Image And Vision Info File 2"/>
				<Item Name="IMAQ Write JPEG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG File 2"/>
				<Item Name="IMAQ Write JPEG2000 File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG2000 File 2"/>
				<Item Name="IMAQ Write PNG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write PNG File 2"/>
				<Item Name="IMAQ Write TIFF File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write TIFF File 2"/>
				<Item Name="Dflt Data Dir.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/file.llb/Dflt Data Dir.vi"/>
				<Item Name="WPI_DriverStationDigitalData.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/DriverStation/WPI_DriverStationDigitalData.ctl"/>
				<Item Name="WPI_CameraDecodeJPEGString.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraDecodeJPEGString.vi"/>
				<Item Name="WPI_CameraRead MJPG.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraRead MJPG.vi"/>
				<Item Name="WPI_CameraIssue HTTP Request with Authentication.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraIssue HTTP Request with Authentication.vi"/>
				<Item Name="Trim Whitespace.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Trim Whitespace.vi"/>
				<Item Name="whitespace.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/whitespace.ctl"/>
				<Item Name="WPI_CameraERRAccountProblem.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraERRAccountProblem.vi"/>
				<Item Name="WPI_UtilitiesFRC Build Error.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Utilities/WPI_UtilitiesFRC Build Error.vi"/>
				<Item Name="WPI_CameraERRFailedComm.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraERRFailedComm.vi"/>
				<Item Name="WPI_CameraImageSize.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraImageSize.ctl"/>
				<Item Name="Color to RGB.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/colorconv.llb/Color to RGB.vi"/>
				<Item Name="IMAQ Overlay Line" Type="VI" URL="/&lt;vilib&gt;/vision/Overlay.llb/IMAQ Overlay Line"/>
				<Item Name="WPI_CameraSettings Read MJPG.ctl" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Camera/WPI_CameraSettings Read MJPG.ctl"/>
				<Item Name="imagedata.ctl" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/imagedata.ctl"/>
				<Item Name="DS_Mode_Simulation_Global.vi" Type="VI" URL="/&lt;vilib&gt;/Rock Robotics/WPI/Simulation/DS_Mode_Simulation_Global.vi"/>
				<Item Name="IMAQ ArrayToColorImage" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ ArrayToColorImage"/>
				<Item Name="Color (U64)" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Color (U64)"/>
				<Item Name="Unflatten Pixmap.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pixmap.llb/Unflatten Pixmap.vi"/>
				<Item Name="NI_Vision_Development_Module.lvlib" Type="Library" URL="/&lt;vilib&gt;/vision/NI_Vision_Development_Module.lvlib"/>
				<Item Name="ROI Descriptor" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/ROI Descriptor"/>
				<Item Name="Particle Parameters" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Particle Parameters"/>
				<Item Name="IVA Result Manager Function.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Vision Assistant Utils.llb/IVA Result Manager Function.ctl"/>
				<Item Name="IVA Result Manager.vi" Type="VI" URL="/&lt;vilib&gt;/vision/Vision Assistant Utils.llb/IVA Result Manager.vi"/>
				<Item Name="Vision Info Type2.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Vision Info Type2.ctl"/>
				<Item Name="IVA Append VI Name to GUID.vi" Type="VI" URL="/&lt;vilib&gt;/vision/Vision Assistant Utils.llb/IVA Append VI Name to GUID.vi"/>
				<Item Name="Vision Info Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Vision Info Type"/>
				<Item Name="IVA Store Particles Results.vi" Type="VI" URL="/&lt;vilib&gt;/vision/Vision Assistant Utils.llb/IVA Store Particles Results.vi"/>
				<Item Name="NI_PID_pid.lvlib" Type="Library" URL="/&lt;vilib&gt;/addons/control/pid/NI_PID_pid.lvlib"/>
				<Item Name="NI_PID__prctrl compat.lvlib" Type="Library" URL="/&lt;vilib&gt;/addons/control/pid/NI_PID__prctrl compat.lvlib"/>
				<Item Name="lvpidtkt.dll" Type="Document" URL="/&lt;vilib&gt;/addons/control/pid/lvpidtkt.dll"/>
			</Item>
			<Item Name="nivissvc.dll" Type="Document" URL="nivissvc.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="nivision.dll" Type="Document" URL="nivision.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="Green Vision Process.vi" Type="VI" URL="../Green Vision Process.vi"/>
			<Item Name="Image Process.vi" Type="VI" URL="../../Utilities/Image Process.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="FRC PC Dashboard" Type="EXE">
				<Property Name="App_INI_aliasGUID" Type="Str">{47BAFDCE-3F99-4134-9347-62A4C9A5434C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{76D91052-50F0-4E0B-B76F-616DDC550CED}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{56AA9368-84D4-42E1-9CCF-4FA34A518587}</Property>
				<Property Name="Bld_buildSpecDescription" Type="Str">Build Dashboard Main.vi into an EXE that will respond to the driver station and display robot information on a PC.</Property>
				<Property Name="Bld_buildSpecName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{F12754D6-B5E0-496F-B50C-3EDB6F368199}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard/Dashboard.exe</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/FRC Dashboard Project/FRC PC Dashboard/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/Support/App EXE.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{7049F83E-AFC8-4A61-A2B9-751B83E09B8D}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_fileDescription" Type="Str">FRC PC Dashboard</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">FRC PC Dashboard</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{AEE2EF3D-7087-47D6-AEAE-9F87F896ED5E}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{606C2B41-6C53-472A-B59C-CCE9AFA57384}</Property>
				<Property Name="App_INI_GUID" Type="Str">{516956C5-D689-4067-85EE-3AF021B3CB2C}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{E98974BF-44C2-472A-B492-DB3B6985D75C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{67347C28-6FE3-4AD4-A02C-DC8427930A77}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{AFD44382-4E98-4548-95A6-9DF602838372}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{9FB896C9-8FBD-4AC4-8E49-D079F639AFED}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="OddJobDashboard" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{817BAAD1-8C9B-4EAC-9AE9-8440998F3EB6}</Property>
				<Property Name="App_INI_GUID" Type="Str">{75463D25-48E9-4D6C-A416-3B3CF59F7793}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{1F8B1D86-9B79-4C01-8FD6-89491F6B4AD5}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">OddJobDashboard</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{EFBD09B7-C252-4AC4-8EFB-2C93C887F419}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{78526293-B70D-4170-824B-4E26952D82B8}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">OddJobDashboard</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">OddJobDashboard</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">OddJobDashboard</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C8E6FB65-ED31-4294-B8FD-51EE1FE56681}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{95EC38C6-C409-4DCA-91DB-E3B1A3516F75}</Property>
				<Property Name="App_INI_GUID" Type="Str">{B54D7447-09B5-47D4-B231-1320B87C1C38}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{88355E21-7751-4D57-9EA9-978F4D22B205}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{98B79E05-C183-4DD2-9EF1-7D01347DFA4E}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{7B1794B1-9BB0-4575-ACA8-5DFB54A59DB4}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{53C21A54-1BB6-4933-8DB6-D7647CEF7065}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main12" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7B2F4700-74EC-4020-B25F-52C42852C593}</Property>
				<Property Name="App_INI_GUID" Type="Str">{E7D10888-385A-4E96-ABFC-5AB87B3735CE}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{DDD61032-4902-49B8-89AA-3BB182772040}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main12</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main12</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{3D1DD3A3-2F1F-4EFB-B6AE-61D86EC1833E}</Property>
				<Property Name="Destination[0].destName" Type="Str">Application.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main12/Application.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main12/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{5C45BBEB-21F0-4089-AC39-A0C9049B1639}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main12</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main12</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main12</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{D6B89E2A-FD39-4B5B-B5BD-7C4106B34858}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Application.exe</Property>
			</Item>
			<Item Name="Dashboard Main13" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{1850BF76-DAAF-487C-AA3A-2047ECBCB298}</Property>
				<Property Name="App_INI_GUID" Type="Str">{09BB8CB5-587D-4DF2-9D00-9C87D296E3A3}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{FE6A5760-FCC7-469B-B2AC-279A82FCE02B}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main13</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main13</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{79191934-6C2C-4611-B17A-F8FBCA767266}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main13/Dashboard.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main13/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{5C45BBEB-21F0-4089-AC39-A0C9049B1639}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main13</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main13</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main13</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{5E96D607-E143-4B6A-9E6C-5FEFD9B006E2}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main2" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{45F8A7A9-75FB-4513-A785-9422F9E586B1}</Property>
				<Property Name="App_INI_GUID" Type="Str">{C875D884-CFC6-4999-A7CE-4DA9369C06D8}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{046FE6DA-52E1-4C14-B58F-5DE746719725}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main2</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{67B8ADCF-BCE1-4908-949B-A917CE3F88AE}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{5C45BBEB-21F0-4089-AC39-A0C9049B1639}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main2</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main2</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main2</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{F11CAA29-AA56-4FA3-B702-418672CE54A5}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main3" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{74F00706-045A-426A-8E4C-3F787DF33310}</Property>
				<Property Name="App_INI_GUID" Type="Str">{4F1D8884-9D76-44B4-A971-95240EBD174C}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{9F1FD999-B0B8-41AE-B3C9-4756E115E396}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main3</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{75821D4D-33F0-470B-BB32-C471E9487744}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{F15DA7D8-BB7D-424A-AA91-C401C9EF567A}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main3</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main3</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main3</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{1548A9C1-3872-455A-A4A4-DE8E55735A70}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main4" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{11C6CDFF-540C-4166-8986-134186AEE73A}</Property>
				<Property Name="App_INI_GUID" Type="Str">{BC9BA711-E15C-4E9B-B4BD-42E6E351D8A5}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{57F21FDF-CB3D-4321-B3DF-4633660F7BFC}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main4</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{CF79AAB3-EEF7-4F89-B127-C4135C6DC96E}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{F15DA7D8-BB7D-424A-AA91-C401C9EF567A}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main4</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main4</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main4</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{95099837-FCA3-40AF-AC79-FB3AAEF5A800}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main5" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{583FFC32-5748-411E-8BDB-1141D751E8D5}</Property>
				<Property Name="App_INI_GUID" Type="Str">{FB78464B-8AD0-4613-B145-AFECB9FE294B}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{A28EB425-D542-44DA-963D-7BF52BF26F1A}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main5</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{DA34BD96-B010-4214-9E5E-F463ECB127E1}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashbaord.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashbaord.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{B035F151-EF61-4102-B885-9DF48F540D7D}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main5</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main5</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main5</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{4ADD3D8D-A57F-416F-8BB4-8B5F4DFC2F93}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashbaord.exe</Property>
			</Item>
			<Item Name="Dashboard Main6" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{DD74F603-AD06-484C-BED4-3B36934F6EAA}</Property>
				<Property Name="App_INI_GUID" Type="Str">{FA425B95-1715-4B10-9A8B-DAF8DC2FCF90}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{8DC11B07-E793-486C-BCDB-D79D7E013C93}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main6</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{8B04174C-E238-4686-AA03-7A0B9DFDF665}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{30C15947-D221-414A-B5D0-94003E925A9E}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main6</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main6</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main6</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{DD86F5FD-9B09-4234-A9DF-D107269E94EF}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main7" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{E9B90C76-E883-4D01-8BF7-CE511770E8C3}</Property>
				<Property Name="App_INI_GUID" Type="Str">{69661484-A474-46AD-B83A-6BBFAE5BF8ED}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{4668AB81-C114-44E8-AD5E-42F2CAB182E9}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main7</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{8DE22930-6349-4CA5-9A1A-897E192DF8C2}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{4309A327-F25E-4353-B236-186CED48E92C}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main7</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main7</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main7</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{0D3BC7CC-3FEA-4CF8-B566-4E8EF8D82E50}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main8" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{0636993B-C8E6-48B3-BFA3-4DCBA6957313}</Property>
				<Property Name="App_INI_GUID" Type="Str">{90D99998-B83F-41AD-83CF-6FBA7620D2D6}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{6BFB2C52-9B50-4230-ABDC-5E226FFA7CBD}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main8</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{D4D083FF-370C-4DFE-9240-D6445458E55E}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{AED0DA9B-EB48-4F48-B456-0927FB35274E}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main8</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main8</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main8</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{61FF0356-80B9-4C75-973C-9E6ADC77CE37}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main9" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{954495F2-C7EF-4511-AC57-8B978F9A6504}</Property>
				<Property Name="App_INI_GUID" Type="Str">{52CA9DDC-BBDB-4C23-9CF4-4CA81E6951F1}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{0AA6F761-2144-4AF9-B00D-DF6D0CAFF4AB}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main9</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{5CFE4D20-AD5E-4291-9866-51A2EA6AC7ED}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{D1CE157D-78A8-4A38-B422-79A963960104}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main9</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main9</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main9</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{5692894A-9CC9-4A22-BA97-4E3E2CAF9B1C}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main10" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{923381E7-D57B-4068-B874-86E73CFAE665}</Property>
				<Property Name="App_INI_GUID" Type="Str">{E6DA1614-BFD6-4D1D-9CF8-D04558DC5C95}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{7243841F-621A-48CF-8FA9-19F185FD9E95}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main10</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{5D64415A-183E-4105-9960-600F9ED94B2A}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{1D64D85C-CE20-4FF3-8E23-96DB3F422ADC}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main10</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main10</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main10</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{B1137ADC-96E4-4A6D-97CC-04D7EDC05170}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main11" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7CAA5B96-102F-44CA-A79F-84C863F698CE}</Property>
				<Property Name="App_INI_GUID" Type="Str">{A075E41F-3F3C-451D-8D36-A8EA5B521609}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{B8AEC632-B8FB-4469-B1F0-E6CFE7CA9CF6}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main11</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{C3226CF3-2C3B-4C2C-B651-DF7ED1DA3374}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{8F90FEC6-53E7-4AA6-BEB0-3CB0FEFF4B3E}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main11</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main11</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main11</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{72634BB1-40A4-4109-874E-8A54430E415B}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main14" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{538682CB-A7D1-4760-A2BF-6B5BD4DF175C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{D2401913-633D-4BC5-9B36-CFDB2E6FB708}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{B500EB2A-4E0B-470F-8290-487CB09CE540}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main14</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{0ACD8776-F8B1-47FD-AD0D-847B514DD98F}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{71F6F6F2-B2DE-4761-8ED2-58EEF5FC1409}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main14</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main14</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main14</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{5768133A-E5E0-4495-AE88-24C957F1F46E}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main15" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{6544BE28-BBAF-4908-AE68-7B16D655A1BD}</Property>
				<Property Name="App_INI_GUID" Type="Str">{CBC9CFDF-23A8-4B96-8A6C-5970DE328A49}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{83201403-8E15-4D13-9705-13B7AC553573}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main15</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{9BBF8D4A-3BDF-4D8E-ACD7-C1774627D786}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dasboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dasboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{E0E84614-5E5F-4D01-AF5B-0F02E45C3458}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main15</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main15</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main15</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{41F3973A-1C06-4511-B5C8-91628303D14A}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dasboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main16" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{C1B1DE57-AD47-42E6-AF61-A08F6A35E80D}</Property>
				<Property Name="App_INI_GUID" Type="Str">{DB2753A8-EE28-4592-9CA3-C3B33D099375}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{F8B1E6BE-5C92-4F2B-94E4-FAC0D7B2A73C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main16</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{7C1C4621-BF33-4F23-B9E9-2BA497D5F494}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{03653A65-F858-44C8-9624-2F87D5C213BA}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main16</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main16</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main16</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{1B272C65-88B0-4262-A4C9-1530E1D1C207}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main17" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{02EAE2E6-A1C0-413D-8BFA-70F053336D5D}</Property>
				<Property Name="App_INI_GUID" Type="Str">{13775835-7BB2-44E9-9EB9-065231756E73}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{E3CFB06F-6F5F-4769-9996-DE539BD27435}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main17</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{EEA9CDEC-B65D-478D-A1E2-3C39F5EAD4B2}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{03653A65-F858-44C8-9624-2F87D5C213BA}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main17</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main17</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main17</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{CC7D2B94-6919-44D2-80A3-2AEB800C6FA4}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main18" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{75C30FF4-CFB1-4316-836B-5A096343535C}</Property>
				<Property Name="App_INI_GUID" Type="Str">{C1C140A2-3241-4909-9263-906BCC972E32}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{8EC190EF-5369-4A71-8FAA-1AB86663C974}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main18</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{92199D51-85C2-4BAF-A2F5-04EE7224EE34}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{75551C81-A26D-4AE3-B861-51DF7FCF456D}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main18</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main18</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main18</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{69F2F128-77B5-4B59-B89D-9AF3D7F350FE}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main19" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{C4EB24CF-7241-4EE9-9FA5-C56A8091CE04}</Property>
				<Property Name="App_INI_GUID" Type="Str">{7B57967C-868A-4E4B-BC86-49D8FEB18CFC}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{2B2B58F8-F376-4A37-8A4B-D99EA99A2E9D}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main19</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{2138822D-DB1E-4055-B134-E9E79AEE72C7}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{F9F3B234-E5A2-48C2-A09B-91D8BC9225B6}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main19</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main19</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main19</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{6F8670E4-9CD5-46F0-8CFA-ABB4FEF70126}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main20" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{870E4CF4-4FDE-448A-A57D-787DC7782525}</Property>
				<Property Name="App_INI_GUID" Type="Str">{65E91405-C3BA-46E1-8589-6D38370C057E}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{CB21EA11-1EA1-45FD-99E6-28F9C439FD9E}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main20</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{058FC484-8ECC-40BE-9A46-1E126EC0DC5F}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{CC677704-72D8-48C1-A4CE-28C46ECDA476}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main20</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main20</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main20</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{1C54EA47-8F78-4A3D-A690-06BF063FDAA4}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main21" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{B842112D-9D9C-4DB9-8127-7B1F0DF1E503}</Property>
				<Property Name="App_INI_GUID" Type="Str">{AD9F8487-CD5E-45FF-9C5F-E318CBDF0078}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{3B71919F-29F2-49F8-8E31-82114CA31D42}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main21</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{1116A0FF-FAAF-4FE9-8C65-37F95348E94D}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{A331ED7E-BA16-4015-A6E5-B6408EF362E7}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main21</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main21</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main21</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{960B8740-22AC-402D-958F-5AB9EC42075B}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main22" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{52C7A530-28C2-40F3-9D31-1D4283B51F60}</Property>
				<Property Name="App_INI_GUID" Type="Str">{74ED386F-E0BB-496B-AA6C-32F09BBD4156}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{EC490248-435C-4690-B3A4-366C26B5CE4C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main22</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{824DF8E5-148E-4C64-8A39-278E37312519}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{2350B043-51D7-474B-88DF-5C540EF20742}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main22</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main22</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main22</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{E9AA2F58-3006-47A9-B236-229391B3FCD0}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main23" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{8FF8757B-694E-4DC9-8370-E6CA6A7B9DB7}</Property>
				<Property Name="App_INI_GUID" Type="Str">{58715714-0781-494B-8045-FD37823626B4}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{D4209600-1E18-48C9-8A74-ED609E1A3D58}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main23</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{40636279-AB1D-4909-AA06-92ABFB968B9B}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{38DB1290-F216-4714-9A68-F76262DC1CDC}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main23</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main23</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main23</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{E15CB8E3-F1F4-4F4B-B656-01B6063AA95D}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main24" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{5FA76697-065B-45FB-A59B-D83DC6CB009B}</Property>
				<Property Name="App_INI_GUID" Type="Str">{A1A588D2-90BD-4718-91F7-99131DEEA83C}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{201696AA-766D-4EF0-A6CF-685E1D328E10}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main24</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{9553021F-6822-4F54-B396-5CD2B68F5D3A}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{38DB1290-F216-4714-9A68-F76262DC1CDC}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main24</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main24</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main24</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{A9B941AD-6C1D-4C38-80BF-3979D47DDC21}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main25" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{E7B8E5E0-0788-4C69-8FED-E83D492CF09A}</Property>
				<Property Name="App_INI_GUID" Type="Str">{85A05F57-DE82-4A65-BD49-5EF9E4BF5ED1}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{B0E0FE9B-FB7D-4756-B0B0-F8D5C1DC16CF}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main25</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main25</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{4469D3CD-F4F8-4835-891F-01EFB7DD837B}</Property>
				<Property Name="Destination[0].destName" Type="Str">Application.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main25/Application.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/Dashboard Main25/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{CC51AD0C-FE55-41D8-B682-75693CA39C00}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main25</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main25</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main25</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{C17BB2CD-7EA1-4E64-A69C-3F482B5C86B2}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Application.exe</Property>
			</Item>
			<Item Name="Dashboard Main26" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{9AE4FD06-55E7-49EA-9816-A292EBF83644}</Property>
				<Property Name="App_INI_GUID" Type="Str">{8B1A404E-2700-4FE7-A183-55D6436D6BD8}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{A45FE467-9C00-45CD-9D3E-FBF514CB7A0C}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main26</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{39FB8192-7760-4534-A3BC-38D62282CC06}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{CC51AD0C-FE55-41D8-B682-75693CA39C00}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main26</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main26</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main26</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{FA987704-3CA1-4B1D-8665-45D7412C6583}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main27" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{21F81C7B-0402-4D06-87A8-B5063816A891}</Property>
				<Property Name="App_INI_GUID" Type="Str">{DEC70C10-33A0-4860-8C3A-6D007E955503}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{DBDC4ED0-4F27-4128-B35E-7AA5C7C61A52}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main27</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{680B5BD1-6928-4600-8424-1759AA325CA9}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{CC51AD0C-FE55-41D8-B682-75693CA39C00}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main27</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main27</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main27</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{647401E5-CC37-4876-8677-19AC0AC44372}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main28" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{7F0E5B60-7633-4742-B9F4-7A090E9DFF88}</Property>
				<Property Name="App_INI_GUID" Type="Str">{52CFB1C6-3CC3-4584-9669-C25A20DE1899}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{1EDECF6E-F423-404B-B796-792862193B58}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main28</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{8D5A355D-E71F-460C-B505-3657EFCACC29}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{D120DF12-F8B4-4458-8FC7-C7F86122BC7A}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Team 195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main28</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main28</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 Team 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main28</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{9D8B6F69-522A-459B-BD75-8DD0C632E6FF}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main29" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{D42D817C-5DC3-4F62-9944-AA78ADF90B57}</Property>
				<Property Name="App_INI_GUID" Type="Str">{9B4BA260-D5C0-4F89-B542-E2843C794BB6}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{E5590C68-1D35-4119-919F-35FB08876942}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main29</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{024CB997-ECFC-4016-9F0E-51D7CF1AF8D4}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{548F5751-EDE6-44F8-BB31-B95B26EBEA70}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Team 195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main29</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main29</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 Team 195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main29</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{D4ED20A3-F743-4848-A536-4E8AE5574C72}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
			<Item Name="Dashboard Main30" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{CB27328A-AF59-4CDD-978F-87405E8613F6}</Property>
				<Property Name="App_INI_GUID" Type="Str">{8674BAB2-C99E-486A-8237-5AE2D435642F}</Property>
				<Property Name="App_winsec.description" Type="Str">http://www.Team195.com</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{89D83848-016F-47BF-8ED7-54AEA381E13B}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Dashboard Main30</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">/C/Users/195/Desktop/Dash</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{53FF7EF5-FA1A-49D3-9D8D-E7486D6F03ED}</Property>
				<Property Name="Destination[0].destName" Type="Str">Dashboard.exe</Property>
				<Property Name="Destination[0].path" Type="Path">/C/Users/195/Desktop/Dash/Dashboard.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">/C/Users/195/Desktop/Dash/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">&lt;none&gt;</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{4BA30C0E-DF4B-44EE-A9CC-2BCE0625441B}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/Dashboard Main.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Team195</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Dashboard Main30</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">Dashboard Main30</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 Team195</Property>
				<Property Name="TgtF_productName" Type="Str">Dashboard Main30</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{0C137404-DDA2-41AB-9B7A-DC3BE9B06888}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Dashboard.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
