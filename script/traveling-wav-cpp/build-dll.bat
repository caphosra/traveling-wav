setlocal

@echo off

rem Open This On The VS Development Console

pushd %~dp0

set objOutputFolder="%~dp0/../../bin/native-dll"

mkdir %objOutputFolder%

pushd %objOutputFolder%

cl /nologo /Wall /EHcs /c "%~dp0/cpp/*.cpp"

link /nologo /DLL /def:"%~dp0/traveling_wav.def" /out:traveling_wav.dll *.obj

popd

popd

endlocal
