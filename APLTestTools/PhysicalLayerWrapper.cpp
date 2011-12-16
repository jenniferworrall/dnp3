//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#include "PhysicalLayerWrapper.h"

namespace apl
{


PhysicalLayerWrapper::PhysicalLayerWrapper(Logger* apLogger, IPhysicalLayerAsync* apProxy) :
	Loggable(apLogger),
	IHandlerAsync(apLogger),
	mpProxy(apProxy),
	mpHandler(NULL)

{
	mpProxy->SetHandler(this);
}

void PhysicalLayerWrapper::SetHandler(IHandlerAsync* apHandler)
{
	assert(apHandler != NULL);
	mpHandler = apHandler;
}

void PhysicalLayerWrapper::_OnLowerLayerUp() 
{ 
	if(mpHandler) mpHandler->OnLowerLayerUp(); 
}

void PhysicalLayerWrapper::_OnLowerLayerDown()
{
	if(mpHandler) mpHandler->OnLowerLayerDown();
}

void PhysicalLayerWrapper::_OnReceive(const uint8_t* apData, size_t aSize)
{
	if(mpHandler) mpHandler->OnReceive(apData, aSize);
}

void PhysicalLayerWrapper::_OnSendSuccess()
{
	if(mpHandler) mpHandler->OnSendSuccess();
}

void PhysicalLayerWrapper::_OnSendFailure()
{
	if(mpHandler) mpHandler->OnSendFailure();
}

void PhysicalLayerWrapper::_OnOpenFailure()
{
	if(mpHandler) mpHandler->OnOpenFailure();
}

}
