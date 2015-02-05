model_description_path=../../src/modeldescription/

all:
		g++ -std=c++14 -o ExecuteModelDescriptionTest.o *.cc ${model_description_path}v2/*.cc ${model_description_path}*.cc -lboost_unit_test_framework
		./ExecuteModelDescriptionTest
