//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// 
//

#ifndef MANAGERCOMPONENT_HPP_
# define MANAGERCOMPONENT_HPP_

# include <memory>
# include <functional>
# include "IComponent.hpp"

using	functionComponent = std::function<std::unique_ptr<nts::IComponent> (const std::string &)>;

namespace nts
{
	class ManagerComponent
	{
	public:
		static std::unique_ptr<IComponent>	createComponent(const std::string &, const std::string &);
	private:
		static std::unique_ptr<IComponent>	createInput(const std::string &);
		static std::unique_ptr<IComponent>	createTrue(const std::string &);
		static std::unique_ptr<IComponent>	createFalse(const std::string &);
		static std::unique_ptr<IComponent>	createClock(const std::string &);
		static std::unique_ptr<IComponent>	createOutput(const std::string &);
		static std::unique_ptr<IComponent>	create4001(const std::string &);
		static std::unique_ptr<IComponent>      create4008(const std::string &);
		static std::unique_ptr<IComponent>      create4011(const std::string &);
		static std::unique_ptr<IComponent>      create4013(const std::string &);
		static std::unique_ptr<IComponent>      create4017(const std::string &);
		static std::unique_ptr<IComponent>      create4030(const std::string &);
		static std::unique_ptr<IComponent>      create4040(const std::string &);
		static std::unique_ptr<IComponent>      create4069(const std::string &);
		static std::unique_ptr<IComponent>      create4071(const std::string &);
		static std::unique_ptr<IComponent>      create4081(const std::string &);
		static std::unique_ptr<IComponent>      create4094(const std::string &);
		static std::unique_ptr<IComponent>      create4514(const std::string &);
		static std::unique_ptr<IComponent>      create4801(const std::string &);
		static std::unique_ptr<IComponent>      create2716(const std::string &);
	};
}
#endif
