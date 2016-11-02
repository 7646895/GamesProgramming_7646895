//
// Created by Jessica Vilaysak on 20/10/2016.
//

#include "gtest/gtest.h"
#include "../ZorkishSpike8/GameHandler.h"

/*
 * will test go left from start location.
 * left will take you to fairy clearing.
 */
TEST(ZorkishCommands, TestGoCommand)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    CommandController *cmd = new CommandController();

    cmd->run("left", p);
    string cmdGo = p->getCurrentLocation()->getName();
    ASSERT_EQ(cmdGo, "Fairy Clearing");
}

/*
 * look at inventory
 */
TEST(ZorkishCommands, TestLookCommand_LookAtInventory)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    CommandController *cmd = new CommandController();

    string cmdLook = cmd->run("look at inventory", p);
    ASSERT_EQ(cmdLook, "There are no items in your inventory!\n");
}

/*
 * take rock
 * test is true if inv count is diff.
 */
TEST(ZorkishCommands, TestTakeCommand)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    int initialInvCount = p->getInventoryCount();
    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    CommandController *cmd = new CommandController();

    string cmdTake = cmd->run("take rock", p);
    int afterInvCount = p->getInventoryCount();
    bool check = false;
    if(initialInvCount != afterInvCount)
        check = true;
    ASSERT_EQ(check, true);
}

/*
 * drop item
 * test is true if inv count is diff.
 */
TEST(ZorkishCommands, TestDropCommand)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    CommandController *cmd = new CommandController();
    p->addInventoryItem(new Item("frog", "frog is cool"));
    p->addInventoryItem(new Item("dust", "dust is cool"));
    p->addInventoryItem(new Item("porridge", "i love porridge"));
    p->addInventoryItem(new Item("calculator", "calculators are useful"));

    int initialInvCount = p->getInventoryCount();
    cmd->run("drop calculator", p);
    int afterInvCount = p->getInventoryCount();
    bool check = false;
    if(initialInvCount != afterInvCount)
        check = true;
    ASSERT_EQ(true, check);
}


