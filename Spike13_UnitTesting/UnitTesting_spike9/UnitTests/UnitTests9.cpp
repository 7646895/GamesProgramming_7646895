//
// Created by Jessica Vilaysak on 20/10/2016.
//

#include "gtest/gtest.h"
#include "../ZorkishSpike9/GameHandler.h"


/*
 * Returns description of container.
 */
TEST(ZorkishComposite, TestLookInContainer)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    CommandController *cmd = new CommandController();

    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    cmd->run("go left", p);
    cmd->run("take toolbox", p);
    string actual = cmd->run("look at toolbox", p);
    Container* container = (Container*)p->getObject("toolbox");
    string expected = "toolbox: " + container->getDescription()+"\n";

    ASSERT_EQ(actual, expected);
}

/*
 * take hammer from toolbox
 */
TEST(ZorkishComposite, TestTakeFromContainer)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    CommandController *cmd = new CommandController();

    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    cmd->run("go left", p);
    cmd->run("take toolbox", p);
    cmd->run("open toolbox", p);
    GameObject* noPen = p->getObject("hammer");
    cmd->run("take hammer from toolbox", p);
    GameObject* yesPen = p->getObject("hammer");

    bool check = false;
    if(noPen != yesPen)
        check = true;
    ASSERT_TRUE(check);
}

/*
 * put rock in toolbox
 */
TEST(ZorkishComposite, TestPutInContainer)
{
    StateGameplay *game = new StateGameplay();
    Player *p = new Player();
    CommandController *cmd = new CommandController();

    game->setPlayer(p);
    game->setWorld("Cloudy Mountains");
    cmd->run("take rock", p);
    cmd->run("go left", p);
    cmd->run("take toolbox", p);
    cmd->run("open toolbox", p);
    Container* containerObj = (Container*)p->getObject("toolbox");
    GameObject* noRock = containerObj->getObject("rock");
    cmd->run("put rock in toolbox", p);
    GameObject* yesRock = containerObj->getObject("rock");

    bool check = false;
    if(noRock != yesRock)
        check = true;
    ASSERT_TRUE(check);
}



