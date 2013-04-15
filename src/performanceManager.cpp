#include "performanceManager.h"


bool PerformanceManager::running;
volatile bool PerformanceManager::stopThread;
boost::function<void(bool *)> PerformanceManager::f;
boost::thread PerformanceManager::t;


void PerformanceManager::Run()
{
  t=boost::thread(boost::bind(&PerformanceManager::Start));
}


void PerformanceManager::Start() {
    
    stopThread=false;
    while (!stopThread) {
        running=true;
        if (f) { 
	  
	    try{
	      f(&running);
	    }
	    catch(PerformanceManager_exception &ex){
	      ex.what();
	    }
	    
        }
        else {
            sleep(1);
        }
    }
}

void PerformanceManager::Stop()
{
  stopThread=true;
  t.interrupt();
}

void PerformanceManager::StopAnimation(){
  f=NULL;
}


void PerformanceManager::SetPerformance(boost::function<void(bool *)> _f) {
    f=_f;
    running=false;
}


void PerformanceManager::Sleep(float t){ 
  
  try{ 
    boost::this_thread::sleep(boost::posix_time::milliseconds(t)); 
  }
  catch(boost::thread_interrupted const&){
    cout<<"Sleep cancelled."<<endl;
  }
  
  if (!running) 
    throw(PerformanceManager_exception()); 
}





PerformanceManager_exception::PerformanceManager_exception() : exception()
{
  PerformanceManager::StopAnimation();
}


const char* PerformanceManager_exception::what() const throw()
{
    return "Thread not running!";
}

