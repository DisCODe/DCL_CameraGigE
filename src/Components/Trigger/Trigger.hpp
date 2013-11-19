/*!
 * \file
 * \brief 
 * \author Maciej Stefanczyk
 */

#ifndef TRIGGER_HPP_
#define TRIGGER_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"



namespace Processors {
namespace Trigger {

/*!
 * \class Trigger
 * \brief Trigger processor class.
 *
 * Trigger processor.
 */
class Trigger: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	Trigger(const std::string & name = "Trigger");

	/*!
	 * Destructor
	 */
	virtual ~Trigger();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();

	/// Event handler.
	Base::EventHandler<Trigger> h_onTrigger;

	void onTrigger();

	Base::DataStreamOut<Base::UnitType> out_trigger;
	

};

} //: namespace Trigger
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("Trigger", Processors::Trigger::Trigger)

#endif /* TRIGGER_HPP_ */
