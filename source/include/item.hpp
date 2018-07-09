#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "slotType.hpp"
#include "itemRarity.hpp"


class Item
{
public:

private:
    string m_Name;
    SlotType m_Slot;
    ItemRarity m_Rarity;
};


#endif //ITEM_HPP
