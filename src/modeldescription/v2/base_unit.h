#ifndef MODELDESCRIPTION_V2_BASEUNIT_H_
#define MODELDESCRIPTION_V2_BASEUNIT_H_

struct BaseUnit {
private:
	int kg_;
	int m_;
	int s_;
	int a_;
	int k_;
	int mol_;
	int cd_;
	int rad_;
	double factor_;
	double offset_;
};

#endif
