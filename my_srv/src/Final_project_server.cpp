#include "ros/ros.h"
#include "my_srv/Final_project.h"

double randMToN(double M, double N)
{     return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }


bool myrandom (my_srv::Final_project::Request &req, my_srv::Final_project::Response &res){
     res.target_index = randMToN(req.min, req.max);
     return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "Final_project_server");
  ros::NodeHandle n;
  ros::ServiceServer service= n.advertiseService("/Final_project",myrandom);
  ros::spin();
  return 0;
}
