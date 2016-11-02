//
// Created by Jessica Vilaysak on 20/10/2016.
//

#include "gtest/gtest.h"
#include "../ZorkishSpike6/Player.h"
#include "../ZorkishSpike6/Item.h"

Player *p;
Item *pen = new Item("pen", "cool pen");
Item *box = new Item("box", "put things here");
Item *ball = new Item("ball", "to play");
Item *bat = new Item("bat", "to hit balls with");
/*
 * inventory access when inv is empty.
 */
TEST(ZorkishFixture_Inventory, TestInvAccessEmpty) {
    p = new Player();
    string invOutput = p->listInventory();
    string expected = "There are no items in your inventory!\n";
    ASSERT_EQ(invOutput, expected);
}

/*
 * inv access when inv is NOT empty.
 * create pen, add pen to inv
 * check output against function 'listInventory()'
 */
TEST(ZorkishFixture_Inventory, TestInvAccessNotEmpty)
{
    p = new Player();
    p->addInventoryItem(pen);
    string invOutput = p->listInventory();
    string expected = "Listing inventory...\n\t"+
                      pen->getDescription()+"\n";
    ASSERT_EQ(invOutput, expected);
}

/*
 * inventory addition
 */
TEST(ZorkishFixture_Inventory, TestInvAddition)
{
    p = new Player();
    p->addInventoryItem(pen);
    int invCapacity = p->getInventoryCount();
    int expected = 1;
    ASSERT_EQ(invCapacity, expected);
}


/*
 * inventory removal
 */
TEST(ZorkishFixture_Inventory, TestInvRemoval)
{
    p = new Player();
    p->addInventoryItem(pen);
    p->addInventoryItem(box);
    p->addInventoryItem(ball);
    p->addInventoryItem(bat);
    int countBefore = p->getInventoryCount();
    p->removeInventoryItem(pen->getName());
    int countAfter = p->getInventoryCount();

    ASSERT_EQ(countBefore-1, countAfter);
}


