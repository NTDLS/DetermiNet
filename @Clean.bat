@Echo Off

attrib *.* -h -a -r -s

DelTree Debug /Y /DelRoot
DelTree Release /Y /DelRoot
Del *.ncb
Del *.user
Del *.suo
Del *.sdf

DeleteTree IPCH /y /DelRoot
DeleteTree Debug /y /DelRoot
DeleteTree Release /y /DelRoot
