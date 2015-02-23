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
	void offset(double new_offset);
	double offset();
	void factor(double new_factor);
	double factor();
	void rad(int new_rad);
	int rad();
	void cd(int new_cd);
	int cd();
	void mol(int new_mol);
	int mol();
	void k(int new_k);
	int k();
	void a(int new_a);
	int a();
	void s(int new_s);
	int s();
	void m(int new_m);
	int m();
	void kg(int new_kg);
	int kg();

};

#endif
