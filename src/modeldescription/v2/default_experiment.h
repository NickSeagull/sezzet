#ifndef MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_
#define MODELDESCRIPTION_V2_DEFAULTEXPERIMENT_H_

class DefaultExperiment{
private:
	double tolerance_;
	double start_time_;
	double stop_time_;
	double step_size_;
public:
	inline void step_size(double new_step_size);
	inline double step_size();
	inline void stop_time(double new_stop_time);
	inline double stop_time();
	inline void start_time(double new_start_time);
	inline double start_time();
	inline void tolerance(double new_tolerance);
	inline double tolerance();
    DefaultExperiment();
};


#endif
