set TOP=%~dp0
cd %TOP%toolset
conan create . -pr:b %TOP%profiles\vs2019-x86_64 -pr:h %TOP%profiles\vs2019-x86 -o toolset:shared=True
conan create . -pr:b %TOP%profiles\vs2019-x86_64 -pr:h %TOP%profiles\vs2019-x86_64 -o toolset:shared=True

cd %TOP%consumer
conan create . -pr:b %TOP%profiles\vs2019-x86 -pr:h %TOP%profiles\vs2019-x86_64 -o toolset:shared=True


