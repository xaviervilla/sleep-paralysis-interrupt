rm -r mod-loadAndTestModel
mv loadAndTestModel mod-loadAndTestModel
cp -a mod-loadAndTestModel loadAndTestModel
rm loadAndTestModel/buildInfo.mat
rm loadAndTestModel/loadAndTestModel_ref.rsp
rm loadAndTestModel/loadAndTestModel_rtw.mk
rm loadAndTestModel/codeInfo.mat
rm loadAndTestModel/gcGuiReport.mat
rm loadAndTestModel/rtw_proj.tmw
rm -r loadAndTestModel/examples
rm -r loadAndTestModel/html
rm -r loadAndTestModel/interface
for x in loadAndTestModel/*.c;do mv $x ${x}pp;done
rm -r /home/xvilla/Arduino/libraries/loadAndTestModel
cp -a loadAndTestModel /home/xvilla/Arduino/libraries/loadAndTestModel
