#ifndef MODELDESCRIPTION_V2_BASEUNIT_H_
#define MODELDESCRIPTION_V2_BASEUNIT_H_

class BaseUnit {
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

	public:
	inline double offset();
	inline double factor();
	inline int rad();
	inline int cd();
	inline int mol();
	inline int k();
	inline int a();
	inline int s();
	inline int m();
	inline int kg();
};

#endif
