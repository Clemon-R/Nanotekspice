/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
# define COMPONENT_HPP_

# include <map>
# include <tuple>
# include <iostream>
# include "IComponent.hpp"

namespace nts{
    enum    PinType
    {
        INPUT,
        OUTPUT,
        USELESS
    };
    class Component : public IComponent {
    public:
        Component();
        virtual ~Component() = default;
        void    setLink(std::size_t pin, nts::IComponent &other,
                    std::size_t otherPin) override;
        void	dump() const override;
        void    setName(const std::string &name);
        const std::string   &getName() const;
        nts::PinType    getType(std::size_t);
        nts::Tristate   computeState(std::size_t pin);
    protected:
        std::string _name;
        nts::Tristate   _state;
        std::map<std::size_t, std::tuple<nts::PinType, nts::IComponent *, std::size_t>> _pins;
    };
}

#endif /* !COMPONENT_HPP_ */
