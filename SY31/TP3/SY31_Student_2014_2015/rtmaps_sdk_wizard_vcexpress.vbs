' Wizard for the SDK of RTMaps
' To be used with Visual C++ Express 2010
' v1.0 2010/11 OM
' v1.1 2011/03 OM : merged code with wizard for 2008 + upgrade V4
' v1.2 2012/02 OM : support for .user files
'
' This script requires RTMAPS4WIFIBOT_SDKDIR to be defined and point to a folder containing templates.u
'
' (c) 2010-2012 Intempora S.A.. All Rights Reserverd.

''''''''''' Check arguments '''''''''''''''''''''
If WScript.Arguments.Count < 2 Then
    QuitwithMessage "Wrong arguments.",-1
End If

''''''''''' Create required objects '''''''''''''
Set FSO = CreateObject("Scripting.FileSystemObject")

'''''''''''' Common constants ''''''''''''''''''
Const mainTitle = "RTMaps SDK Wizard"

' First argument must be the VC target version
Dim targetVC
targetVC = WScript.Arguments.Item(0)
If targetVC <> "2008" And targetVC <> "2010" Then
    QuitWithMessage "The first argument must be one of 2008 or 2010",-1
End If
Dim projectExtension
If targetVC = "2008" Then
	projectExtension = ".vcproj"
ElseIf targetVC = "2010" Then
	projectExtension = ".vcxproj"
End If
Dim solutionFullPath
solutionFullPath = FSO.GetAbsolutePathName(WScript.Arguments.Item(1))
Dim mySDKRootPath, templatePath
Set WS = CreateObject("WScript.Shell")
Dim wshSysenv, rtmapsSDKPath
Set wshSysenv = WS.Environment("PROCESS")
rtmapsSDKPath = wshSysenv("RTMAPS4WIFIBOT_SDKDIR")
If Not FSO.FolderExists(rtmapsSDKPath) Then
    QuitWithMessage "Check your configuration: RTMAPS4WIFIBOT_SDKDIR is not defined."
End If
templatePath = rtmapsSDKPath & "\templates.u\"
If Not FSO.FolderExists(templatePath) Then
    QuitWithMessage "Check your configuration."
End If

'''''' Check requirements ''''''''''''
'' Interactive mode
If WScript.Interactive = False Then
    QuitWithMessage "Script must be run in interactive mode.",-1
End If
'' Check if solution file is missing
If FSO.FileExists( solutionFullPath ) = false Then
    QuitWithMessage "Solution file ("&solutionFullPath&") is missing. Please check your installation",-1
End If
mySDKRootPath = FSO.GetParentFolderName(solutionFullPath)

' Helper function to request an integer choice to the user in a valid range
Function RequestChoice(prompt, minAns, maxAns)
    Dim l_res, l_choice, l_isOK
    l_isOK = false
    Do While l_isOK = False
        l_res = InputBox(prompt,mainTitle)
        If IsNumeric(l_res) = True Then
            l_choice = Int(l_res)
            If l_choice >= minAns And l_choice <= maxAns Then
                l_isOK = true
            End If
        End If
        If l_isOK = False Then
            WScript.Echo "Wrong answer. Try again."
        End If
    Loop
    RequestChoice = l_choice
End Function

' Helper function to quit with a message and an error code
Sub QuitWithMessage(msg, errCode)
    WScript.Echo msg
    WScript.Quit(errCode)
End sub

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' Create a new package

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Sub CreateNewPackage
    Dim newGUID, newGUID2, packageName, projectFolder, subFolder
    Set TypeLib = CreateObject("Scriptlet.TypeLib")
    newGUID = TypeLib.Guid
    newGUID = Left(newGUID,Len(newGUID)-2)
    newGUID2 = TypeLib.Guid
    newGUID2 = Left(newGUID2,Len(newGUID2)-2)
    Set TypeLib = Nothing
    Set re = New RegExp
    re.Pattern = "^[a-z][a-z_0-9]*$"
    re.IgnoreCase = True
    re.Global = False
    Do While packageName = ""
        packageName = InputBox("Enter a new package name")
        If packageName = "" Then
            WScript.Quit(0)
        End If
        If false = re.Test(packageName) Then
            WScript.Echo "Project name contains invalid characters. Try again."
            packageName = ""
        End If
        projectFolder = FSO.BuildPath(mySDKRootPath, packageName & ".u")
        if FSO.FolderExists(projectFolder) = true Then
            WScript.Echo packageName & " package already exists. Try again."
            packageName = ""
        End If
    Loop
    Dim projectFolderObj
    Set projectFolderObj = FSO.CreateFolder(projectFolder)
    If projectFolderObj = "" Then
        QuitWithMessage "Failed to create package folder: " & projectFolder,-1
    End If
    Dim subFolders, srcFolder
    Set subFolders = projectFolderObj.SubFolders
    subFolders.Add("local_interfaces")
    Set srcFolder = subFolders.Add("src")
    Dim pckInfo, outputPckInfo
    pckInfo = FSO.BuildPath(templatePath,"package_name.pckinfo")
    outputPckInfo = packageName & ".pckinfo"
    FSO.CopyFile pckInfo,projectFolderObj.Path & "\" & outputPckInfo
    ' Create the project
    Dim vcprojFileTemplatePath, vcprojFileTargetPath, userFileTemplatePath, userFileTargetPath, buffer
    userFileTemplatePath = FSO.BuildPath(templatePath,"rtmaps_template_vc"&targetVC&projectExtension&".user")
    userFileTargetPath = FSO.BuildPath(projectFolderObj.Path,"rtmaps_"&packageName&projectExtension&".user")
    FSO.CopyFile userFileTemplatePath, userFileTargetPath
    vcprojFileTemplatePath = FSO.BuildPath(templatePath,"rtmaps_template_vc"&targetVC&projectExtension)
    vcprojFileTargetPath = FSO.BuildPath(projectFolderObj.Path,"rtmaps_"&packageName&projectExtension)
    FSO.CopyFile vcprojFileTemplatePath, vcprojFileTargetPath
    set xmlDoc = CreateObject("Msxml2.DOMDocument.3.0")
    xmlDoc.Async = False
    xmlDoc.Load(vcprojFileTargetPath)
    Set rootNode = xmlDoc.documentElement
    If rootNode Is Nothing Then
        QuitWithMessage "Project template is invalid.",-1
    End If

	If targetVC = "2008" Then
        rootNode.setAttribute "ProjectGUID", newGUID
        rootNode.setAttribute "Name", packageName
        rootNode.setAttribute "RootNamespace", packageName
        Set objNodeList = rootNode.getElementsByTagName("Files")
        If objNodeList.Length <> 1 Then
            QuitWithMessage "Project file is invalid (no Files section)",-1
        End If
        Set filesNode = objNodeList.Item(0) 'IXMLDOMElement
        ' Look for src path
        Dim srcFilterNode, includeFilterNode
        Set srcFilterNode = Nothing
        Set includeFilterNode = Nothing
        Set objNodeList = filesNode.getElementsByTagName("Filter")
        For Each n In objNodeList
            name = n.getAttribute("Name")
            If name = "src" Then
                Set srcFilterNode = n
            ElseIf name = "local_interfaces" Then
                Set includeFilterNode = n
            End If
        Next
        If srcFilterNode Is Nothing Then
            Set srcFilterNode = xmlDoc.createElement("Filter")
            srcFilterNode.setAttribute "Name", "src"
            filesNode.appendChild(srcFilterNode)
        End If
        If includeFilterNode Is Nothing Then
            Set includeFilterNode = xmlDoc.createElement("Filter")
            includeFilterNode.setAttribute "Name", "local_interfaces"
            filesNode.appendChild(includeFilterNode)
        End If

        Set srcElt = xmlDoc.createElement("File")
        srcElt.setAttribute "RelativePath", outputPckInfo
        filesNode.appendChild(srcElt)

	ElseIf targetVC = "2010" Then

        Set propertyGroup = rootNode.getElementsByTagName("PropertyGroup")
        For Each p In propertyGroup
            If p.getAttribute("Label") = "Globals" Then
                Set txtNode = xmlDoc.createTextNode(packageName)
                p.getElementsByTagName("ProjectName").Item(0).replaceChild txtNode, p.getElementsByTagName("ProjectName").Item(0).childNodes.Item(0)
                Set txtNode = xmlDoc.createTextNode(newGUID)
                p.getElementsByTagName("ProjectGuid").Item(0).replaceChild txtNode, p.getElementsByTagName("ProjectGuid").Item(0).childNodes.Item(0)
                Set txtNode = xmlDoc.createTextNode(packageName)
                p.getElementsByTagName("RootNamespace").Item(0).replaceChild txtNode, p.getElementsByTagName("RootNamespace").Item(0).childNodes.Item(0)
                'todo : add pckinfo to the project file
            End If
        Next

    End If

    xmlDoc.save(vcprojFileTargetPath)
    Set xmlDoc = Nothing
    ' Add the project to the solution
    Dim solutionFile, tmpFileName, tmpFile, state
    Set solutionFile = FSO.OpenTextFile(solutionFullPath,1)
    tmpFileName = FSO.GetTempName
    Set tmpFile = FSO.CreateTextFile(tmpFileName,True)
    state = 0
    re.Pattern = "^# Visual Studio"
    re.Global = False
    re.IgnoreCase = False
    Do While solutionFile.AtEndOfStream <> True
        buffer = solutionFile.ReadLine
        Select Case state
        Case 0
            tmpFile.WriteLine(buffer)
            If re.Test(buffer) Then
                tmpFile.WriteLine("Project("""&newGUID2&""") = """&_
                         packageName&""", """&packageName&".u\rtmaps_"&packageName&_
                         projectExtension&""", """&newGUID&"""")
                tmpFile.WriteLine("EndProject")
                state = 1
                re.Pattern = "ProjectConfigurationPlatforms"
            End If
        Case 1
            tmpFile.WriteLine(buffer)
            If re.Test(buffer) Then
                tmpFile.WriteLine(vbTab&vbTab&newGUID&".Debug|Win32.ActiveCfg = Debug|Win32")
                tmpFile.WriteLine(vbTab&vbTab&newGUID&".Debug|Win32.Build.0 = Debug|Win32")
                tmpFile.WriteLine(vbTab&vbTab&newGUID&".Release|Win32.ActiveCfg = Release|Win32")
                tmpFile.WriteLine(vbTab&vbTab&newGUID&".Release|Win32.Build.0 = Release|Win32")
                state = 2
            End If
        Case Else
            tmpFile.WriteLine(buffer)
        End Select
    Loop
    solutionFile.Close
    tmpFile.Close
    FSO.CopyFile tmpFileName, solutionFullPath
    FSO.DeleteFile tmpFileName
    Set re = Nothing
End Sub

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
' Create a new component
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
Sub CreateNewComponent
    ' List the available packages
    Dim rootFolders, f, re
    Set re = new RegExp
    re.Global = False
    re.IgnoreCase = True
    re.Pattern = "\.u$"
    Set rootFolders = FSO.GetFolder(mySDKRootPath).SubFolders
    If rootFolders.Count > 69 Then
        QuitWithMessage "You have exceeded the 64 max packages.", -1
    End If
    Dim myArr(64), idx, idx2
    idx = 0
    For Each f in rootFolders
        If re.Test(f.name) Then
            myArr(idx) = Left(f.name, Len(f.name) - 2)
            idx = idx + 1
        End If
    Next
    If idx = 0 Then
        QuitWithMessage "You must create a package first.", -1
    End If
    ' Select a package
    Dim choice, msg
    msg = "Choose the package to which you want to add a component:" & vbCrLf
    idx2 = 0
    Do While idx2 < idx
        msg = msg & " " & (idx2+1) & " - " & myArr(idx2) & vbCrLf
        idx2 = idx2 + 1
    Loop
    msg = msg & " 0 - Quit"
    choice = RequestChoice(msg,0,idx)
    If choice = 0 Then
        WScript.Quit(0)
    End If
    ' Component name
    Dim moduleName
    re.Pattern = "^[a-z][a-z_0-9]*$"
    re.Global = False
    re.IgnoreCase = True
    Do While moduleName = ""
        moduleName = InputBox("Enter the name of the new component:", mainTitle)
        If moduleName = "" Then
            WScript.Quit(0)
        End If
        If False = re.Test(moduleName) Then
            WScript.Echo "Module name contains invalid characters. Try again."
            moduleName = ""
        End If
    Loop
    Dim projectPath, srcPath, includePath, vcprojFullPath
    projectPath = FSO.BuildPath(mySDKRootPath, myArr(choice-1) & ".u")
    vcprojFullPath = FSO.BuildPath(projectPath,"rtmaps_"&myArr(choice-1)&projectExtension)
    If FSO.FileExists(vcprojFullPath) = False Then
        QuitWithMessage vcprojFullPath & " is missing. Aborting.",-1
    End If
    ' Create the templates files
    srcPath = FSO.BuildPath(projectPath, "src")
    If FSO.FolderExists(srcPath) = False Then
        QuitWithMessage "Package project is invalid.",-1
    End If
    includePath = FSO.BuildPath(projectPath, "local_interfaces")
    If FSO.FolderExists(includePath) = False Then
        QuitWithMessage "Package project is invalid.",-1
    End If
    Dim srcTemplateFullPath, includeTemplateFullPath,srcDestFullPath,includeDestFullPath
    srcTemplateFullPath = FSO.BuildPath(templatePath,"src\maps_ComponentTemplate.cpp")
    includeTemplateFullPath = FSO.BuildPath(templatePath,"local_interfaces\maps_ComponentTemplate.h")
    srcDestFullPath = FSO.BuildPath(srcPath, "maps_"&moduleName&".cpp")
    includeDestFullPath = FSO.BuildPath(includePath, "maps_"&moduleName&".h")
    If FSO.FileExists(srcDestFullPath) Or FSO.FileExists(includeDestFullPath) Then
        QuitWithMessage "This module already exists.", -1
    End If
    Dim srcTemplateFile, includeTemplateFile,srcDestFile,includeDestFile
    Set srcTemplateFile = FSO.OpenTextFile(srcTemplateFullPath,1)
    Set includeTemplateFile = FSO.OpenTextFile(includeTemplateFullPath,1)
    Set srcDestFile = FSO.CreateTextFile(srcDestFullPath)
    Set includeDestFile = FSO.CreateTextFile(includeDestFullPath)
    Dim buffer
    re.Pattern = "ComponentTemplate"
    re.Global = True
    re.IgnoreCase = False
    Do While srcTemplateFile.AtEndOfStream <> True
        buffer = srcTemplateFile.ReadLine
        buffer = re.Replace(buffer,moduleName)
        srcDestFile.WriteLine(buffer)
    Loop
    srcTemplateFile.Close
    srcDestFile.Close
    Do While includeTemplateFile.AtEndOfStream <> True
        buffer = includeTemplateFile.ReadLine
        buffer = re.Replace(buffer,moduleName)
        includeDestFile.WriteLine(buffer)
    Loop
    includeTemplateFile.Close
    includeDestFile.Close
    ' Add the new sources to the vcproj
    set xmlDoc = CreateObject("Msxml2.DOMDocument.6.0")
    xmlDoc.Async = False
    xmlDoc.Load(vcprojFullPath)

	If targetVC = "2008" Then

        Set objNodeList = xmlDoc.getElementsByTagName("Files")
        If objNodeList.Length <> 1 Then
            QuitWithMessage "Project file is invalid (no Files section)",-1
        End If
        Set filesNode = objNodeList.Item(0) 'IXMLDOMElement
        ' Look for src path
        Dim srcFilterNode, includeFilterNode
        Set srcFilterNode = Nothing
        Set includeFilterNode = Nothing
        Set objNodeList = filesNode.getElementsByTagName("Filter")
        For Each n In objNodeList
            name = n.getAttribute("Name")
            If name = "src" Then
                Set srcFilterNode = n
            ElseIf name = "local_interfaces" Then
                Set includeFilterNode = n
            End If
        Next
        If srcFilterNode Is Nothing Then
            Set srcFilterNode = xmlDoc.createElement("Filter")
            srcFilterNode.setAttribute "Name", "src"
            filesNode.appendChild(srcFilterNode)
        End If
        If includeFilterNode Is Nothing Then
            Set includeFilterNode = xmlDoc.createElement("Filter")
            includeFilterNode.setAttribute "Name", "local_interfaces"
            filesNode.appendChild(includeFilterNode)
        End If

        Set srcElt = xmlDoc.createElement("File")
        srcElt.setAttribute "RelativePath", ".\src\maps_"&moduleName&".cpp"
        Set includeElt = xmlDoc.createElement("File")
        includeElt.setAttribute "RelativePath", ".\local_interfaces\maps_"&moduleName&".h"
        srcFilterNode.appendChild(srcElt)
        includeFilterNode.appendChild(includeElt)

	ElseIf targetVC = "2010" Then

        Set rootNode = xmlDoc.documentElement
        If rootNode Is Nothing Then
            QuitWithMessage "Project file is invalid.",-1
        End If
        For Each node In xmlDoc.documentElement.childNodes
            If node.nodeName = "ItemGroup" Then
                If node.getAttribute("Label") = "RTMaps_sources" Then
                    Set cppElt = xmlDoc.createNode(1, "ClCompile", node.namespaceURI)
                    cppElt.setAttribute "Include", "src\maps_"&moduleName&".cpp"
                    node.appendChild(cppElt)
                ElseIf node.getAttribute("Label") = "RTMaps_headers" Then
                    Set hElt = xmlDoc.createNode(1, "ClInclude", node.namespaceURI)
                    hElt.setAttribute "Include", "local_interfaces\maps_"&moduleName&".h"
                    node.appendChild(hElt)
                End If
            End If
        Next

    End If

    xmlDoc.save(vcprojFullPath)
    Set xmlDoc = Nothing
    Set re = Nothing
End Sub


'''''''''''''' Main script ''''''''''''''''''
Dim choice
choice = RequestChoice("What do you want to do:" & vbCrLf & _
               " 1 - Create a new package" & vbCrLf & _
               " 2 - Create a new component" & vbCrLf & _
               " 0 - Quit", 0, 2)
'WScript.Echo choice
Select Case choice
    Case 0    WScript.Quit(0)
    Case 1    CreateNewPackage
    Case 2    CreateNewComponent
    Case Else WScript.Quit(-1)
End Select
' Everything went ok
WScript.Quit(0)
