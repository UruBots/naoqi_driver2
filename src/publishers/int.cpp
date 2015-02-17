/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/


#include <iostream>

#include <std_msgs/Int32.h>

#include "int.hpp"

namespace alros
{
namespace publisher
{

IntPublisher::IntPublisher( const std::string& name, const std::string& topic, float frequency, qi::SessionPtr& session ):
  BasePublisher( name, topic, frequency, session )
{}

void IntPublisher::publish()
{
  static std_msgs::Int32 m;
  m.data++;
  pub_.publish( m );
}

void IntPublisher::reset( ros::NodeHandle& nh )
{
  pub_ = nh.advertise< std_msgs::Int32>( topic_, 10 );
  is_initialized_ = true;
}

} //publisher
} // alros
