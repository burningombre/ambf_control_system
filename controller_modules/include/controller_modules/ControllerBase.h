#ifndef CONTROLLERBASE_H
#define CONTROLLERBASE_H
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <Eigen/Core>
#include <ros/ros.h>

/**
 * @brief Base class for controllers to be build
 * 
 */
class ControllerBase
{
   public:
    ControllerBase(){}
    ~ControllerBase(){}

   //overide function to calculate the controller output
    virtual void update(const trajectory_msgs::JointTrajectoryPoint&, const trajectory_msgs::JointTrajectoryPoint&, std::vector<double>&)=0;
    virtual std::vector<double> get_error(){return error;}
    virtual std::vector<double> get_tau(){return tau;}  


   protected:

      std::vector<double> error;
      std::vector<double> tau;
     
      //helper function to convert between the std vectors and Eigen vectors
      template<typename T, typename A>
      Eigen::VectorXd VectToEigen(std::vector<T,A> const& msg )   
      {
         std::vector<double> vec(msg.begin(), msg.end());
         Eigen::VectorXd Q =  Eigen::Map<Eigen::VectorXd, Eigen::Unaligned>(vec.data(), vec.size());
         return Q;
      }

};


#endif // CONTROLLERBASE_H
