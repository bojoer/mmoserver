/*
---------------------------------------------------------------------------------------
This source file is part of SWG:ANH (Star Wars Galaxies - A New Hope - Server Emulator)

For more information, visit http://www.swganh.com

Copyright (c) 2006 - 2010 The SWG:ANH Team
---------------------------------------------------------------------------------------
Use of this source code is governed by the GPL v3 license that can be found
in the COPYING file or at http://www.gnu.org/licenses/gpl-3.0.html

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------
*/

#include "ChanceCube.h"
#include "PlayerObject.h"
#include "MessageLib/MessageLib.h"

//=============================================================================

ChanceCube::ChanceCube() : Item()
{
    mRadialMenu = RadialMenuPtr(new RadialMenu());

    mRadialMenu->addItem(1,0,radId_itemUse,radAction_ObjCallback);
    mRadialMenu->addItem(2,0,radId_examine,radAction_Default);
}


//=============================================================================

ChanceCube::~ChanceCube(void)
{
}

//=============================================================================

void ChanceCube::handleObjectMenuSelect(uint8 messageType,Object* srcObject)
{
    if(PlayerObject* playerObject = dynamic_cast<PlayerObject*>(srcObject))
    {
        if(messageType == radId_itemUse)
        {
            gMessageLib->SendSystemMessage(::common::OutOfBand("dice", "red"), playerObject);
        }
    }
}
