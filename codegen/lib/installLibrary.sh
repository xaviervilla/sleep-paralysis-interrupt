rm -r MOD-CODEGEN_REALTIME_loadAndTestModel
cp -a REDUCED_CODEGEN_REALTIME_loadAndTestModel MOD-CODEGEN_REALTIME_loadAndTestModel
rm MOD-CODEGEN_REALTIME_loadAndTestModel/buildInfo.mat
rm MOD-CODEGEN_REALTIME_loadAndTestModel/REDUCED_CODEGEN_REALTIME_loadAndTestModel_ref.rsp
rm MOD-CODEGEN_REALTIME_loadAndTestModel/REDUCED_CODEGEN_REALTIME_loadAndTestModel_rtw.mk
rm MOD-CODEGEN_REALTIME_loadAndTestModel/codeInfo.mat
rm MOD-CODEGEN_REALTIME_loadAndTestModel/gcGuiReport.mat
rm MOD-CODEGEN_REALTIME_loadAndTestModel/rtw_proj.tmw
rm -r MOD-CODEGEN_REALTIME_loadAndTestModel/examples
rm -r MOD-CODEGEN_REALTIME_loadAndTestModel/html
rm -r MOD-CODEGEN_REALTIME_loadAndTestModel/interface
for x in MOD-CODEGEN_REALTIME_loadAndTestModel/*.c;do mv $x ${x}pp;done
rm -r /home/xvilla/Arduino/libraries/CODEGEN_REALTIME_loadAndTestModel
cp -a MOD-CODEGEN_REALTIME_loadAndTestModel /home/xvilla/Arduino/libraries/CODEGEN_REALTIME_loadAndTestModel
