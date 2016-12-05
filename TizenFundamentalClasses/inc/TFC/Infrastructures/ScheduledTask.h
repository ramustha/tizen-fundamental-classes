/*
 * Scheduler.h
 *
 *  Created on: Sep 13, 2016
 *      Contributor:
 *        Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "TFC/Core.h"
#include <Ecore.h>
#include <chrono>

namespace TFC {
namespace Infrastructures {

class LIBAPI ScheduledTask
{
private:
	Ecore_Timer* timer;
	bool TimerCallback();
	std::chrono::microseconds interval;
	bool firstStarted;
protected:
	virtual void Run() = 0;
public:
	friend Eina_Bool ScheduledTaskDispatcherCallback(void* data);

	ScheduledTask();
	virtual ~ScheduledTask();
	void ScheduleOnce(std::chrono::system_clock::time_point t);
	void SchedulePeriodic(std::chrono::system_clock::time_point startAt, std::chrono::microseconds interval);
	void Cancel();
	bool IsScheduled() { return timer != nullptr; }
};

}
}



#endif /* SCHEDULER_H_ */
