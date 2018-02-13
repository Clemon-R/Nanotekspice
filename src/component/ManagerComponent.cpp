//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <map>
#include "Exception.hpp"
#include "ManagerComponent.hpp"
#include "component/Input.hpp"
#include "component/True.hpp"
#include "component/False.hpp"
#include "component/Clock.hpp"
#include "component/Output.hpp"
#include "component/4001.hpp"
#include "component/4011.hpp"
#include "component/4071.hpp"
#include "component/4030.hpp"

namespace nts
{
	std::unique_ptr<IComponent>	ManagerComponent::createComponent(const std::string &type, const std::string &value)
	{
		std::map<std::string, functionComponent>	listComponent;

		listComponent["input"] = createInput;
		listComponent["true"] = createTrue;
		listComponent["false"] = createFalse;
		listComponent["clock"] = createClock;
		listComponent["output"] = createOutput;
		listComponent["4001"] = create4001;
		//listComponent["4008"] = create4008;
		listComponent["4011"] = create4011;
		//listComponent["4013"] = create4013;
		//listComponent["4017"] = create4017;
		listComponent["4030"] = create4030;
		/*listComponent["4040"] = create4040;
		listComponent["4069"] = create4069;*/
		listComponent["4071"] = create4071;
		/*listComponent["4081"] = create4081;
		listComponent["4094"] = create4094;
		listComponent["4514"] = create4514;
		listComponent["4801"] = create4801;
		listComponent["2716"] = create2716;*/
		if (listComponent.find(type) == listComponent.end())
			throw Exception("Component - " + type + ": unknown");
		return (listComponent[type](value));
	}

	std::unique_ptr<IComponent>	ManagerComponent::create4001(const std::string &value)
	{
		(void)value;
		return (std::make_unique<component4001>());
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4008(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4011(const std::string &value)
	{
		(void)value;
		return (std::make_unique<component4011>());
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4013(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4017(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4030(const std::string &value)
	{
		(void)value;
		return (std::make_unique<component4030>());
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4040(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4069(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4071(const std::string &value)
	{
		(void)value;
		return (std::make_unique<component4071>());
	}
	
	std::unique_ptr<IComponent>     ManagerComponent::create4081(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4094(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4514(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4801(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create2716(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::createInput(const std::string &value)
	{
		nts::Tristate	state = nts::Tristate::UNDEFINED;
		
		if (value == "1")
			state = nts::Tristate::TRUE;
		else if (value == "0")
			state = nts::Tristate::FALSE;
		return (std::make_unique<Input>(state));
	}

	std::unique_ptr<IComponent>     ManagerComponent::createClock(const std::string &value)
	{
		nts::Tristate   state = nts::Tristate::UNDEFINED;

		if (value == "1")
			state = nts::Tristate::TRUE;
		else if (value == "0")
			state = nts::Tristate::FALSE;
		return (std::make_unique<Clock>(state));
	}

	std::unique_ptr<IComponent>     ManagerComponent::createTrue(const std::string &value)
	{
		(void)value;
		return (std::make_unique<True>());
	}
	
	std::unique_ptr<IComponent>     ManagerComponent::createFalse(const std::string &value)
	{
		(void)value;
        return (std::make_unique<False>());
	}

	std::unique_ptr<IComponent>     ManagerComponent::createOutput(const std::string &value)
	{
		(void)value;
		return (std::make_unique<Output>(nts::Tristate::UNDEFINED));		
	}	
}
