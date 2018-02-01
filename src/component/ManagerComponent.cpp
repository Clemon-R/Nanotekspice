//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#include <map>
#include "ManagerComponent.hpp"
namespace nts
{
	std::unique_ptr<IComponent>	ManagerComponent::createComponent(const std::string &type, const std::string &value)
	{
		std::map<std::string, functionComponent>	listComponent;

		listComponent["4001"] = create4001;
		listComponent["4008"] = create4008;
		listComponent["4011"] = create4011;
		listComponent["4013"] = create4013;
		listComponent["4017"] = create4017;
		listComponent["4030"] = create4030;
		listComponent["4040"] = create4040;
		listComponent["4069"] = create4069;
		listComponent["4071"] = create4071;
		listComponent["4081"] = create4081;
		listComponent["4094"] = create4094;
		listComponent["4514"] = create4514;
		listComponent["4801"] = create4801;
		listComponent["2716"] = create2716;
			        
		return (listComponent[type] != nullptr ? listComponent[type](value) : nullptr);
	}

	std::unique_ptr<IComponent>	ManagerComponent::create4001(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4008(const std::string &value)
	{
		return (nullptr);
	}

	std::unique_ptr<IComponent>     ManagerComponent::create4011(const std::string &value)
	{
		return (nullptr);
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
		return (nullptr);
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
		return (nullptr);
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
}
