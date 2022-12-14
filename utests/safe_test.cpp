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

#include "CppUTest/TestHarness.h"
#include "safe.h"
#include "sheet.h"
#include <iostream>
#include <string>

TEST_GROUP(SafeGroup)
{
    Safe *safe = nullptr;
    Sheet *sheet = nullptr;
    int safe_code = 420342;
    void setup()
    {
        safe = new Safe(safe_code);
        sheet = new Sheet("Safe test.");
    }
    void teardown()
    {
        delete safe;
        delete sheet;
    }
};

TEST(SafeGroup, AddRemoveFindObject)
{
    CHECK(safe->addObject(sheet));
    CHECK_FALSE(safe->addObject(sheet));
    CHECK_EQUAL(sheet, safe->findObject(Action(Lbr::ActNone, Lbr::ObjSheet)));
    CHECK(safe->removeObject(sheet));
    CHECK_FALSE(safe->removeObject(sheet));
}

TEST(SafeGroup, GetName)
{
    CHECK_EQUAL(Lbr::ObjSafe, safe->getName());
}

TEST(SafeGroup, GetNameString)
{
    CHECK_EQUAL("safe", safe->getNameString());
}

TEST(SafeGroup, IsLocked)
{
    CHECK(safe->isLocked());
    CHECK(safe->openSafe(safe_code));
    CHECK_FALSE(safe->isLocked());
}

TEST(SafeGroup, OpenSafe)
{
    CHECK_FALSE(safe->openSafe(safe_code+1));
    CHECK(safe->openSafe(safe_code));
}
