/*!
 * \file
 * \brief
 * \author Maciej Stefanczyk
 */

#include <memory>
#include <string>

#include "Trigger.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace Trigger {

Trigger::Trigger(const std::string & name) :
		Base::Component(name)  {

}

Trigger::~Trigger() {
}

void Trigger::prepareInterface() {
	// Register data streams, events and event handlers HERE!
	registerStream("out_trigger", &out_trigger);
	h_onTrigger.setup(this, &Trigger::onTrigger);
	registerHandler("onTrigger", &h_onTrigger);
	addDependency("onTrigger", NULL);
}

bool Trigger::onInit() {

	return true;
}

bool Trigger::onFinish() {
	return true;
}

bool Trigger::onStop() {
	return true;
}

bool Trigger::onStart() {
	return true;
}

void Trigger::onTrigger() {
	out_trigger.write(Base::UnitType());
}


} //: namespace Trigger
} //: namespace Processors
