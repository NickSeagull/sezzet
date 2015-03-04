model_description_path=../../src/modeldescription/
normalized_platform=$(shell uname -s | tr [:upper:] [:lower:] \
							| sed \
									-e 's/^mingw32.*$$/mingw32/' \
									-e 's/^cygwin.*$$/cygwin/' \
									-e 's/^darwin.*$$/macosx/')
platform=$(subst cygwin,windows,$(subst mingw32,windows,$(build-platform)))

ifeq ($(platform),windows)
	CC="x86_64-w64-mingw32-g++"
else
	CC="g++"
endif

all:
		$CC -std=c++1y -o run_tests.o -Isrc *.cc ${model_description_path}v2/*.cc ${model_description_path}elementtree/*.cc ${model_description_path}*.cc -lboost_unit_test_framework
