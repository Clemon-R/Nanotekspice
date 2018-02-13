/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "LogicBinary.hpp"

nts::Tristate   LogicBinary::binaryAnd(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}

nts::Tristate   LogicBinary::binaryNand(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate   state = LogicBinary::binaryAnd(a, b);

    if (state == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if (state == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}

nts::Tristate   LogicBinary::binaryOr(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}

nts::Tristate   LogicBinary::binaryNor(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate   state = LogicBinary::binaryOr(a, b);

    if (state == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if (state == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    return (nts::Tristate::TRUE);
}

nts::Tristate   LogicBinary::binaryXor(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if ((a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) || 
    (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}