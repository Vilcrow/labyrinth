/*******************************************************************************
** vim:ts=4:sw=4:expandtab
**
** This file is part of the labyrinth project, a text adventure game
**
** Copyright (C) 2022 S.V.I 'Vilcrow', <vilcrow.net>
**
** LICENCE:
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
** You should have received a copy of the GNU General Public License
** along with this program. If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************/

#ifndef GAME_H_SENTRY
#define GAME_H_SENTRY

#include "backpack.h"
#include "battery.h"
#include "cassette.h"
#include "commands.h"
#include "door.h"
#include "inscription.h"
#include "player.h"
#include "room.h"
#include "safe.h"
#include "sheet.h"
#include "shelf.h"
#include "table.h"
#include "watch.h"

class Game {
public:
    Game();
    ~Game();
    void run();
private:
    enum { roomCount = 81 };
    enum { finishRoom = 82 };
    int roomNumber;
    Lbr::WallType curWallType;
    LbrContainer *curContainer;
    Backpack *backpack;
    std::map<int, Room*> gameMap; //all rooms
    bool saved;

    Game(Game&) = delete;
    Game& operator=(Game&) = delete;
    void generateMap();
    void room_1();
    void room_2();
    void room_3();
    void room_4();
    void room_5();
    void room_6();
    void room_7();
    void room_8();
    void room_9();
    void room_10();
    void room_11();
    void room_12();
    void room_13();
    void room_14();
    void room_15();
    void room_16();
    void room_17();
    void room_18();
    void room_19();
    void room_20();
    void room_21();
    void room_22();
    void room_23();
    void room_24();
    void room_25();
    void room_26();
    void room_27();
    void room_28();
    void room_29();
    void room_30();
    void room_31();
    void room_32();
    void room_33();
    void room_34();
    void room_35();
    void room_36();
    void room_37();
    void room_38();
    void room_39();
    void room_40();
    void room_41();
    void room_42();
    void room_43();
    void room_44();
    void room_45();
    void room_46();
    void room_47();
    void room_48();
    void room_49();
    void room_50();
    void room_51();
    void room_52();
    void room_53();
    void room_54();
    void room_55();
    void room_56();
    void room_57();
    void room_58();
    void room_59();
    void room_60();
    void room_61();
    void room_62();
    void room_63();
    void room_64();
    void room_65();
    void room_66();
    void room_67();
    void room_68();
    void room_69();
    void room_70();
    void room_71();
    void room_72();
    void room_73();
    void room_74();
    void room_75();
    void room_76();
    void room_77();
    void room_78();
    void room_79();
    void room_80();
    void room_81();
    std::string ActionInGame(Action action);
    std::string handleActionWithObject(Action act, LbrObject *obj);
    std::string handleActionWithContainer(Action act);
    std::string getContext() const;
    std::string ActionWithBackpack(Lbr::ActType aType);
    std::string ActionWithBattery(Lbr::ActType aType, Battery *battery);
    std::string ActionWithCassette(Lbr::ActType aType, Cassette *cassette);
    std::string ActionWithDoor(const Action act);
    std::string ActionWithInscription(Lbr::ActType aType, Inscription *key);
    std::string ActionWithKey(Lbr::ActType aType, Key *key);
    std::string ActionWithLock(Lbr::ActType aType, LbrLock *lock);
    std::string ActionWithPlayer(Lbr::ActType aType);
    std::string ActionWithRoom(Lbr::ActType aType, Room *room);
    std::string ActionWithSafe(const Action act);
    std::string ActionWithSheet(Lbr::ActType aType, Sheet *sheet);
    std::string ActionWithShelf(Lbr::ActType aType);
    std::string ActionWithTable(Lbr::ActType aType);
    std::string ActionWithWall(Lbr::ActType aType);
    std::string ActionWithWatch(Lbr::ActType aType, Watch *watch);
    std::string OpenLock(const Action act, LbrLock *lock);
    std::string ActionTakeObject(LbrObject *obj);
    std::string ActionThrowObject(LbrObject *obj);
    std::string save();
    std::string load();
    std::string quit(bool& q);
    void setStartOptions();
    void clearGameOptions();
    std::string checkDoors() const;
};

#endif
