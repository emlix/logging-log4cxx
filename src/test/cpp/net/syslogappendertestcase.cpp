/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <log4cxx/helpers/datagramsocket.h>
#include <log4cxx/net/syslogappender.h>
#include "../appenderskeletontestcase.h"

using namespace log4cxx;
using namespace log4cxx::helpers;
using namespace log4cxx::net;

/**
   Unit tests of log4cxx::SyslogAppender
 */
class SyslogAppenderTestCase : public AppenderSkeletonTestCase
{
		LOGUNIT_TEST_SUITE(SyslogAppenderTestCase);
		//
		//    tests inherited from AppenderSkeletonTestCase
		//
		LOGUNIT_TEST(testDefaultThreshold);
		LOGUNIT_TEST(testSetOptionThreshold);
		LOGUNIT_TEST(testLargeMessage);
		LOGUNIT_TEST_SUITE_END();


	public:

		AppenderSkeleton* createAppenderSkeleton() const
		{
			return new log4cxx::net::SyslogAppender();
		}

		void testLargeMessage() {
			SyslogAppenderPtr syslogAppender =
					SyslogAppenderPtr(new SyslogAppender());

			syslogAppender->setMaxMessageLength(20);

			Logger::getRootLogger()->addAppender(syslogAppender);

			Logger::getRootLogger()->error( LOG4CXX_STR( "This is a message over 20 characters in length so we can test stuff" ) );
		}
};

LOGUNIT_TEST_SUITE_REGISTRATION(SyslogAppenderTestCase);
