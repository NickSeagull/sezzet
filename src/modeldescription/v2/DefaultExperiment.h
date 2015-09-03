#ifndef MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_
#define MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_

class DefaultExperiment{
private:
	double tolerance_;
	double start_time_;
	double stop_time_;
	double step_size_;
public:
	void step_size(double new_step_size);
	double step_size();
	void stop_time(double new_stop_time);
	double stop_time();
	void start_time(double new_start_time);
	double start_time();
	void tolerance(double new_tolerance);
	double tolerance();
    DefaultExperiment();
};


#endif
