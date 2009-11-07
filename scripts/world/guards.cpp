/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Guards
SD%Complete: 100
SDComment: All Guard gossip data, quite some npc_text-id's still missing, adding constantly as new id's are known. CombatAI should be organized better for future.
SDCategory: Guards
EndScriptData */

/* ContentData
guard_contested
guard_darnassus
guard_dunmorogh
guard_durotar
guard_elwynnforest
guard_ironforge
guard_mulgore
guard_orgrimmar
guard_stormwind
guard_teldrassil
guard_tirisfal
guard_undercity
EndContentData */

#include "precompiled.h"
#include "guard_ai.h"

//script spesific action
#define GOSSIP_ACTION_TAVERN                  101
#define GOSSIP_ACTION_GEMMERCHANT             102
#define GOSSIP_ACTION_MANALOOM                103

//script spesific sender
#define GOSSIP_SENDER_SEC_GEMMERCHANT         101
#define GOSSIP_SENDER_SEC_AUCTIONHOUSE        102

//script spesific gossip text
#define GOSSIP_TEXT_TAVERN                    "Worlds End Tavern"
#define GOSSIP_TEXT_BANKSCYERS                "Scyers bank"
#define GOSSIP_TEXT_BANKALDOR                 "Aldor Bank"
#define GOSSIP_TEXT_INNSCYERS                 "Scyers Inn"
#define GOSSIP_TEXT_INNALDOR                  "Aldor Inn"
#define GOSSIP_TEXT_STABLESCYERS              "Scyers Stable"
#define GOSSIP_TEXT_STABLEALDOR               "Aldor Stable"
#define GOSSIP_TEXT_BATTLEMASTERALLIANCE      "Alliance Battlemasters"
#define GOSSIP_TEXT_BATTLEMASTERHORDE         "Horde Battlemasters"
#define GOSSIP_TEXT_BATTLEMASTERARENA         "Arena Battlemasters"
#define GOSSIP_TEXT_MANALOOM                  "Mana Loom"
#define GOSSIP_TEXT_ALCHEMYLAB                "Alchemy Lab"
#define GOSSIP_TEXT_GEMMERCHANT               "Gem Merchant"
#define GOSSIP_TEXT_GEMSCYERS                 "Scyers Gem Merchant"
#define GOSSIP_TEXT_GEMALDOR                  "Aldor Gem Merchant"

#define GOSSIP_TEXT_AH_SILVERMOON_1           "Western Auction House"
#define GOSSIP_TEXT_AH_SILVERMOON_2           "Royal Exchange Auction House"

#define GOSSIP_TEXT_INN_SILVERMOON_1          "Silvermoon City Inn"
#define GOSSIP_TEXT_INN_SILVERMOON_2          "Wayfarer's Rest tavern"


/*******************************************************
 * guard_contested start
 *******************************************************/

CreatureAI* GetAI_guard_contested(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_contested end
 *******************************************************/

/*******************************************************
 * guard_darnassus start
 *******************************************************/

bool GossipHello_guard_darnassus(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_AUCTIONHOUSE   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HIPPOGRYPH     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAILBOX        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WEAPONMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATTLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    pPlayer->SEND_GOSSIP_MENU(3016, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_darnassus(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction house
            pPlayer->SEND_POI(9861.23, 2334.55, 7, 6, 0, "Darnassus Auction House");
            pPlayer->SEND_GOSSIP_MENU(3833, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            pPlayer->SEND_POI(9938.45, 2512.35, 7, 6, 0, "Darnassus Bank");
            pPlayer->SEND_GOSSIP_MENU(3017, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Wind master
            pPlayer->SEND_POI(9945.65, 2618.94, 7, 6, 0, "Rut'theran Village");
            pPlayer->SEND_GOSSIP_MENU(3018, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Guild master
            pPlayer->SEND_POI(10076.40, 2199.59, 7, 6, 0, "Darnassus Guild Master");
            pPlayer->SEND_GOSSIP_MENU(3019, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Inn
            pPlayer->SEND_POI(10133.29, 2222.52, 7, 6, 0, "Darnassus Inn");
            pPlayer->SEND_GOSSIP_MENU(3020, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Mailbox
            pPlayer->SEND_POI(9942.17, 2495.48, 7, 6, 0, "Darnassus Mailbox");
            pPlayer->SEND_GOSSIP_MENU(3021, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Stable master
            pPlayer->SEND_POI(10167.20, 2522.66, 7, 6, 0, "Alassin");
            pPlayer->SEND_GOSSIP_MENU(5980, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Weapon trainer
            pPlayer->SEND_POI(9907.11, 2329.70, 7, 6, 0, "Ilyenia Moonfire");
            pPlayer->SEND_GOSSIP_MENU(4517, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Battlemaster
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7519, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DRUID           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(4264, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->SEND_GOSSIP_MENU(4273, pCreature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_darnassus(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            pPlayer->SEND_POI(9923.61, 2327.43, 7, 6, 0, "Brogun Stoneshield");
            pPlayer->SEND_GOSSIP_MENU(7518, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            pPlayer->SEND_POI(9977.37, 2324.39, 7, 6, 0, "Keras Wolfheart");
            pPlayer->SEND_GOSSIP_MENU(7651,  pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            pPlayer->SEND_POI(9979.84, 2315.79, 7, 6, 0, "Aethalas");
            pPlayer->SEND_GOSSIP_MENU(7482, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_darnassus(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            pPlayer->SEND_POI(10186, 2570.46, 7, 6, 0, "Darnassus Druid Trainer");
            pPlayer->SEND_GOSSIP_MENU(3024, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            pPlayer->SEND_POI(10177.29, 2511.10, 7, 6, 0, "Darnassus Hunter Trainer");
            pPlayer->SEND_GOSSIP_MENU(3023, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            pPlayer->SEND_POI(9659.12, 2524.88, 7, 6, 0, "Temple of the Moon");
            pPlayer->SEND_GOSSIP_MENU(3025, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            pPlayer->SEND_POI(10122, 2599.12, 7, 6, 0, "Darnassus Rogue Trainer");
            pPlayer->SEND_GOSSIP_MENU(3026, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            pPlayer->SEND_POI(9951.91, 2280.38, 7, 6, 0, "Warrior's Terrace");
            pPlayer->SEND_GOSSIP_MENU(3033, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_darnassus(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(10075.90, 2356.76, 7, 6, 0, "Darnassus Alchemy Trainer");
            pPlayer->SEND_GOSSIP_MENU(3035, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Cooking
            pPlayer->SEND_POI(10088.59, 2419.21, 7, 6, 0, "Darnassus Cooking Trainer");
            pPlayer->SEND_GOSSIP_MENU(3036, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Enchanting
            pPlayer->SEND_POI(10146.09, 2313.42, 7, 6, 0, "Darnassus Enchanting Trainer");
            pPlayer->SEND_GOSSIP_MENU(3337, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //First Aid
            pPlayer->SEND_POI(10150.09, 2390.43, 7, 6, 0, "Darnassus First Aid Trainer");
            pPlayer->SEND_GOSSIP_MENU(3037, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Fishing
            pPlayer->SEND_POI(9836.20, 2432.17, 7, 6, 0, "Darnassus Fishing Trainer");
            pPlayer->SEND_GOSSIP_MENU(3038, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Herbalism
            pPlayer->SEND_POI(9757.17, 2430.16, 7, 6, 0, "Darnassus Herbalism Trainer");
            pPlayer->SEND_GOSSIP_MENU(3039, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            pPlayer->SEND_POI(10086.59, 2255.77, 7, 6, 0, "Darnassus Leatherworking Trainer");
            pPlayer->SEND_GOSSIP_MENU(3040, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            pPlayer->SEND_POI(10081.40, 2257.18, 7, 6, 0, "Darnassus Skinning Trainer");
            pPlayer->SEND_GOSSIP_MENU(3042, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Tailoring
            pPlayer->SEND_POI(10079.70, 2268.19, 7, 6, 0, "Darnassus Tailor");
            pPlayer->SEND_GOSSIP_MENU(3044, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_darnassus(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_darnassus(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_darnassus(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_darnassus(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_darnassus(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_darnassus end
 *******************************************************/

CreatureAI* GetAI_guard_darnassus(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_dunmorogh start
 *******************************************************/

bool GossipHello_guard_dunmorogh(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK             , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HIPPOGRYPH       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN              , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->SEND_GOSSIP_MENU(4287, pCreature->GetGUID());

    return true;
}

void SendDefaultMenu_guard_dunmorogh(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4288, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Gryphon master
            pPlayer->SEND_GOSSIP_MENU(4289, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            pPlayer->SEND_GOSSIP_MENU(4290, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(-5582.66, -525.89, 7, 6, 0, "Thunderbrew Distillery");
            pPlayer->SEND_GOSSIP_MENU(4291, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Stable Master
            pPlayer->SEND_POI(-5604, -509.58, 7, 6, 0, "Shelby Stoneflint");
            pPlayer->SEND_GOSSIP_MENU(5985, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PALADIN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(4292, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(4300, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_dunmorogh(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            pPlayer->SEND_POI(-5618.29, -454.25, 7, 6, 0, "Grif Wildheart");
            pPlayer->SEND_GOSSIP_MENU(4293, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            pPlayer->SEND_POI(-5585.6, -539.99, 7, 6, 0, "Magis Sparkmantle");
            pPlayer->SEND_GOSSIP_MENU(4294, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Paladin
            pPlayer->SEND_POI(-5585.6, -539.99, 7, 6, 0, "Azar Stronghammer");
            pPlayer->SEND_GOSSIP_MENU(4295, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Priest
            pPlayer->SEND_POI(-5591.74, -525.61, 7, 6, 0, "Maxan Anvol");
            pPlayer->SEND_GOSSIP_MENU(4296, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            pPlayer->SEND_POI(-5602.75, -542.4, 7, 6, 0, "Hogral Bakkan");
            pPlayer->SEND_GOSSIP_MENU(4297, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            pPlayer->SEND_POI(-5641.97, -523.76, 7, 6, 0, "Gimrizz Shadowcog");
            pPlayer->SEND_GOSSIP_MENU(4298, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            pPlayer->SEND_POI(-5604.79, -529.38, 7, 6, 0, "Granis Swiftaxe");
            pPlayer->SEND_GOSSIP_MENU(4299, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_dunmorogh(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_GOSSIP_MENU(4301, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(-5584.72, -428.41, 7, 6, 0, "Tognus Flintfire");
            pPlayer->SEND_GOSSIP_MENU(4302, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(-5596.85, -541.43, 7, 6, 0, "Gremlock Pilsnor");
            pPlayer->SEND_GOSSIP_MENU(4303, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_GOSSIP_MENU(4304, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(-5531, -666.53, 7, 6, 0, "Bronk Guzzlegear");
            pPlayer->SEND_GOSSIP_MENU(4305, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(-5603.67, -523.57, 7, 6, 0, "Thamner Pol");
            pPlayer->SEND_GOSSIP_MENU(4306, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(-5199.9, 58.58, 7, 6, 0, "Paxton Ganter");
            pPlayer->SEND_GOSSIP_MENU(4307, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_GOSSIP_MENU(4308, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_GOSSIP_MENU(4310, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_POI(-5531, -666.53, 7, 6, 0, "Yarr Hamerstone");
            pPlayer->SEND_GOSSIP_MENU(4311, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_GOSSIP_MENU(4312, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_GOSSIP_MENU(4313, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_dunmorogh(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_dunmorogh(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_dunmorogh(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_dunmorogh(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_dunmorogh end
 *******************************************************/

CreatureAI* GetAI_guard_dunmorogh(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_durotar start
 *******************************************************/

bool GossipHello_guard_durotar(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WINDRIDER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->SEND_GOSSIP_MENU(4037, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_durotar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4032, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Wind rider
            pPlayer->SEND_GOSSIP_MENU(4033, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            pPlayer->SEND_POI(338.7, -4688.87, 7, 6, 0, "Razor Hill Inn");
            pPlayer->SEND_GOSSIP_MENU(4034, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable master
            pPlayer->SEND_POI(330.31, -4710.66, 7, 6, 0, "Shoja'my");
            pPlayer->SEND_GOSSIP_MENU(5973, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(4035, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(4036, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_durotar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            pPlayer->SEND_POI(276, -4706.72, 7, 6, 0, "Thotar");
            pPlayer->SEND_GOSSIP_MENU(4013, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            pPlayer->SEND_POI(-839.33, -4935.6, 7, 6, 0, "Un'Thuwa");
            pPlayer->SEND_GOSSIP_MENU(4014, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            pPlayer->SEND_POI(296.22, -4828.1, 7, 6, 0, "Tai'jin");
            pPlayer->SEND_GOSSIP_MENU(4015, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            pPlayer->SEND_POI(265.76, -4709, 7, 6, 0, "Kaplak");
            pPlayer->SEND_GOSSIP_MENU(4016, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Shaman
            pPlayer->SEND_POI(307.79, -4836.97, 7, 6, 0, "Swart");
            pPlayer->SEND_GOSSIP_MENU(4017, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            pPlayer->SEND_POI(355.88, -4836.45, 7, 6, 0, "Dhugru Gorelust");
            pPlayer->SEND_GOSSIP_MENU(4018, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            pPlayer->SEND_POI(312.3, -4824.66, 7, 6, 0, "Tarshaw Jaggedscar");
            pPlayer->SEND_GOSSIP_MENU(4019, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_durotar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(-800.25, -4894.33, 7, 6, 0, "Miao'zan");
            pPlayer->SEND_GOSSIP_MENU(4020, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(373.24, -4716.45, 7, 6, 0, "Dwukk");
            pPlayer->SEND_GOSSIP_MENU(4021, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_GOSSIP_MENU(4022, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_GOSSIP_MENU(4023, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(368.95, -4723.95, 7, 6, 0, "Mukdrak");
            pPlayer->SEND_GOSSIP_MENU(4024, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(327.17, -4825.62, 7, 6, 0, "Rawrk");
            pPlayer->SEND_GOSSIP_MENU(4025, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(-1065.48, -4777.43, 7, 6, 0, "Lau'Tiki");
            pPlayer->SEND_GOSSIP_MENU(4026, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(-836.25, -4896.89, 7, 6, 0, "Mishiki");
            pPlayer->SEND_GOSSIP_MENU(4027, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_GOSSIP_MENU(4028, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_POI(366.94, -4705, 7, 6, 0, "Krunn");
            pPlayer->SEND_GOSSIP_MENU(4029, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_GOSSIP_MENU(4030, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_GOSSIP_MENU(4031, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_durotar(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_durotar(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_durotar(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_durotar(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_durotar end
 *******************************************************/

CreatureAI* GetAI_guard_durotar(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_elwynnforest start
 *******************************************************/

bool GossipHello_guard_elwynnforest(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GRYPHON       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->SEND_GOSSIP_MENU(933, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_elwynnforest(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4260, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Gryphon master
            pPlayer->SEND_GOSSIP_MENU(4261, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            pPlayer->SEND_GOSSIP_MENU(4262, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(-9459.34, 42.08, 7, 6, 0, "Lion's Pride Inn");
            pPlayer->SEND_GOSSIP_MENU(4263, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Stable Master
            pPlayer->SEND_POI(-9466.62, 45.87, 7, 6, 0, "Erma");
            pPlayer->SEND_GOSSIP_MENU(5983, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(4264, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(4273, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_elwynnforest(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            pPlayer->SEND_GOSSIP_MENU(4265, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            pPlayer->SEND_GOSSIP_MENU(4266, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            pPlayer->SEND_POI(-9471.12, 33.44, 7, 6, 0, "Zaldimar Wefhellt");
            pPlayer->SEND_GOSSIP_MENU(4268, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            pPlayer->SEND_POI(-9469, 108.05, 7, 6, 0, "Brother Wilhelm");
            pPlayer->SEND_GOSSIP_MENU(4269, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            pPlayer->SEND_POI(-9461.07, 32.6, 7, 6, 0, "Priestess Josetta");
            pPlayer->SEND_GOSSIP_MENU(4267, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Rogue
            pPlayer->SEND_POI(-9465.13, 13.29, 7, 6, 0, "Keryn Sylvius");
            pPlayer->SEND_GOSSIP_MENU(4270, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warlock
            pPlayer->SEND_POI(-9473.21, -4.08, 7, 6, 0, "Maximillian Crowe");
            pPlayer->SEND_GOSSIP_MENU(4272, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Warrior
            pPlayer->SEND_POI(-9461.82, 109.50, 7, 6, 0, "Lyria Du Lac");
            pPlayer->SEND_GOSSIP_MENU(4271, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_elwynnforest(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(-9057.04, 153.63, 7, 6, 0, "Alchemist Mallory");
            pPlayer->SEND_GOSSIP_MENU(4274, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(-9456.58, 87.90, 7, 6, 0, "Smith Argus");
            pPlayer->SEND_GOSSIP_MENU(4275, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(-9467.54, -3.16, 7, 6, 0, "Tomas");
            pPlayer->SEND_GOSSIP_MENU(4276, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_GOSSIP_MENU(4277, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_GOSSIP_MENU(4278, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(-9456.82, 30.49, 7, 6, 0, "Michelle Belle");
            pPlayer->SEND_GOSSIP_MENU(4279, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(-9386.54, -118.73, 7, 6, 0, "Lee Brown");
            pPlayer->SEND_GOSSIP_MENU(4280, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(-9060.70, 149.23, 7, 6, 0, "Herbalist Pomeroy");
            pPlayer->SEND_GOSSIP_MENU(4281, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(-9376.12, -75.23, 7, 6, 0, "Adele Fielder");
            pPlayer->SEND_GOSSIP_MENU(4282, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_GOSSIP_MENU(4283, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(-9536.91, -1212.76, 7, 6, 0, "Helene Peltskinner");
            pPlayer->SEND_GOSSIP_MENU(4284, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(-9376.12, -75.23, 7, 6, 0, "Eldrin");
            pPlayer->SEND_GOSSIP_MENU(4285, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_elwynnforest(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_elwynnforest(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_elwynnforest(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_elwynnforest(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_elwynnforest end
 *******************************************************/

CreatureAI* GetAI_guard_elwynnforest(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_ironforge start
 *******************************************************/

bool GossipHello_guard_ironforge(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_AUCTIONHOUSE      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_IRONFORGE_BANK    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DEEPRUNTRAM       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GRYPHON           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN               , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAILBOX           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WEAPONMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATTLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    pPlayer->SEND_GOSSIP_MENU(2760, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_ironforge(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction House
            pPlayer->SEND_POI(-4957.39, -911.6, 7, 6, 0, "Ironforge Auction House");
            pPlayer->SEND_GOSSIP_MENU(3014, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            pPlayer->SEND_POI(-4891.91, -991.47, 7, 6, 0, "The Vault");
            pPlayer->SEND_GOSSIP_MENU(2761, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Tram
            pPlayer->SEND_POI(-4835.27, -1294.69, 7, 6, 0, "Deeprun Tram");
            pPlayer->SEND_GOSSIP_MENU(3814, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Gryphon Master
            pPlayer->SEND_POI(-4821.52, -1152.3, 7, 6, 0, "Ironforge Gryphon Master");
            pPlayer->SEND_GOSSIP_MENU(2762, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Guild Master
            pPlayer->SEND_POI(-5021, -996.45, 7, 6, 0, "Ironforge Visitor's Center");
            pPlayer->SEND_GOSSIP_MENU(2764, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Inn
            pPlayer->SEND_POI(-4850.47, -872.57, 7, 6, 0, "Stonefire Tavern");
            pPlayer->SEND_GOSSIP_MENU(2768, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Mailbox
            pPlayer->SEND_POI(-4845.7, -880.55, 7, 6, 0, "Ironforge Mailbox");
            pPlayer->SEND_GOSSIP_MENU(2769, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Stable Master
            pPlayer->SEND_POI(-5010.2, -1262, 7, 6, 0, "Ulbrek Firehand");
            pPlayer->SEND_GOSSIP_MENU(5986, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Weapons Trainer
            pPlayer->SEND_POI(-5040, -1201.88, 7, 6, 0, "Bixi and Buliwyf");
            pPlayer->SEND_GOSSIP_MENU(4518, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Battlemaster
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7529, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Class Trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE            , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PALADIN         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);           
            pPlayer->SEND_GOSSIP_MENU(2766, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Profession Trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING     , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(2793, pCreature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_ironforge(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            pPlayer->SEND_POI(-5047.87, -1263.77, 7, 6, 0, "Glordrum Steelbeard");
            pPlayer->SEND_GOSSIP_MENU(7483, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            pPlayer->SEND_POI(-5038.37, -1266.39, 7, 6, 0, "Donal Osgood");
            pPlayer->SEND_GOSSIP_MENU(7649, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            pPlayer->SEND_POI(-5037.24, -1274.82, 7, 6, 0, "Lylandris");
            pPlayer->SEND_GOSSIP_MENU(7528, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_ironforge(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            pPlayer->SEND_POI(-5023, -1253.68, 7, 6, 0, "Hall of Arms");
            pPlayer->SEND_GOSSIP_MENU(2770, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            pPlayer->SEND_POI(-4627, -926.45, 7, 6, 0, "Hall of Mysteries");
            pPlayer->SEND_GOSSIP_MENU(2771, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Paladin
            pPlayer->SEND_POI(-4627.02, -926.45, 7, 6, 0, "Hall of Mysteries");
            pPlayer->SEND_GOSSIP_MENU(2773, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Priest
            pPlayer->SEND_POI(-4627, -926.45, 7, 6, 0, "Hall of Mysteries");
            pPlayer->SEND_GOSSIP_MENU(2772, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            pPlayer->SEND_POI(-4647.83, -1124, 7, 6, 0, "Ironforge Rogue Trainer");
            pPlayer->SEND_GOSSIP_MENU(2774, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            pPlayer->SEND_POI(-4605, -1110.45, 7, 6, 0, "Ironforge Warlock Trainer");
            pPlayer->SEND_GOSSIP_MENU(2775, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            pPlayer->SEND_POI(-5023.08, -1253.68, 7, 6, 0, "Hall of Arms");
            pPlayer->SEND_GOSSIP_MENU(2776, pCreature->GetGUID());
            break;
            pPlayer->SEND_GOSSIP_MENU(2766, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_ironforge(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(-4858.5, -1241.83, 7, 6, 0, "Berryfizz's Potions and Mixed Drinks");
            pPlayer->SEND_GOSSIP_MENU(2794, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(-4796.97, -1110.17, 7, 6, 0, "The Great Forge");
            pPlayer->SEND_GOSSIP_MENU(2795, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(-4767.83, -1184.59, 7, 6, 0, "The Bronze Kettle");
            pPlayer->SEND_GOSSIP_MENU(2796, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_POI(-4803.72, -1196.53, 7, 6, 0, "Thistlefuzz Arcanery");
            pPlayer->SEND_GOSSIP_MENU(2797, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(-4799.56, -1250.23, 7, 6, 0, "Springspindle's Gadgets");
            pPlayer->SEND_GOSSIP_MENU(2798, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(-4881.6, -1153.13, 7, 6, 0, "Ironforge Physician");
            pPlayer->SEND_GOSSIP_MENU(2799, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(-4597.91, -1091.93, 7, 6, 0, "Traveling Fisherman");
            pPlayer->SEND_GOSSIP_MENU(2800, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(-4876.9, -1151.92, 7, 6, 0, "Ironforge Physician");
            pPlayer->SEND_GOSSIP_MENU(2801, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(-4745, -1027.57, 7, 6, 0, "Finespindle's Leather Goods");
            pPlayer->SEND_GOSSIP_MENU(2802, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Minning
            pPlayer->SEND_POI(-4705.06, -1116.43, 7, 6, 0, "Deepmountain Mining Guild");
            pPlayer->SEND_GOSSIP_MENU(2804, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(-4745, -1027.57, 7, 6, 0, "Finespindle's Leather Goods");
            pPlayer->SEND_GOSSIP_MENU(2805, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(-4719.60, -1056.96, 7, 6, 0, "Stonebrow's Clothier");
            pPlayer->SEND_GOSSIP_MENU(2807, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_ironforge(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_ironforge(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_ironforge(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_ironforge(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_ironforge(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_ironforge end
 *******************************************************/

CreatureAI* GetAI_guard_ironforge(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_mulgore start
 *******************************************************/

bool GossipHello_guard_mulgore(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WINDRIDER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->SEND_GOSSIP_MENU(3543, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_mulgore(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4051, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Wind rider
            pPlayer->SEND_GOSSIP_MENU(4052, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            pPlayer->SEND_POI(-2361.38, -349.19, 7, 6, 0, "Bloodhoof Village Inn");
            pPlayer->SEND_GOSSIP_MENU(4053, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable master
            pPlayer->SEND_POI(-2338.86, -357.56, 7, 6, 0, "Seikwa");
            pPlayer->SEND_GOSSIP_MENU(5976, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DRUID           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SHAMAN          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(4069, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->SEND_GOSSIP_MENU(4070, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_mulgore(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            pPlayer->SEND_POI(-2312.15, -443.69, 7, 6, 0, "Gennia Runetotem");
            pPlayer->SEND_GOSSIP_MENU(4054, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            pPlayer->SEND_POI(-2178.14, -406.14, 7, 6, 0, "Yaw Sharpmane");
            pPlayer->SEND_GOSSIP_MENU(4055, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Shaman
            pPlayer->SEND_POI(-2301.5, -439.87, 7, 6, 0, "Narm Skychaser");
            pPlayer->SEND_GOSSIP_MENU(4056, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warrior
            pPlayer->SEND_POI(-2345.43, -494.11, 7, 6, 0, "Krang Stonehoof");
            pPlayer->SEND_GOSSIP_MENU(4057, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_mulgore(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_GOSSIP_MENU(4058, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_GOSSIP_MENU(4059, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(-2263.34, -287.91, 7, 6, 0, "Pyall Silentstride");
            pPlayer->SEND_GOSSIP_MENU(4060, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_GOSSIP_MENU(4061, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            pPlayer->SEND_POI(-2353.52, -355.82, 7, 6, 0, "Vira Younghoof");
            pPlayer->SEND_GOSSIP_MENU(4062, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Fishing
            pPlayer->SEND_POI(-2349.21, -241.37, 7, 6, 0, "Uthan Stillwater");
            pPlayer->SEND_GOSSIP_MENU(4063, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Herbalism
            pPlayer->SEND_GOSSIP_MENU(4064, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Leatherworking
            pPlayer->SEND_POI(-2257.12, -288.63, 7, 6, 0, "Chaw Stronghide");
            pPlayer->SEND_GOSSIP_MENU(4065, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mining
            pPlayer->SEND_GOSSIP_MENU(4066, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Skinning
            pPlayer->SEND_POI(-2252.94, -291.32, 7, 6, 0, "Yonn Deepcut");
            pPlayer->SEND_GOSSIP_MENU(4067, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Tailoring
            pPlayer->SEND_GOSSIP_MENU(4068, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_mulgore(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_mulgore(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_mulgore(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_mulgore(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_mulgore end
 *******************************************************/

CreatureAI* GetAI_guard_mulgore(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_orgrimmar start
 *******************************************************/

bool GossipHello_guard_orgrimmar(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WINDRIDER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAILBOX       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_AUCTIONHOUSE  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ZEPPLINMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WEAPONMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_OFFICERS      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATTLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
    pPlayer->SEND_GOSSIP_MENU(2593, pCreature->GetGUID());

    return true;
}

void SendDefaultMenu_guard_orgrimmar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_POI(1631.51, -4375.33, 7, 6, 0, "Bank of Orgrimmar");
            pPlayer->SEND_GOSSIP_MENU(2554, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //wind rider
            pPlayer->SEND_POI(1676.6, -4332.72, 7, 6, 0, "The Sky Tower");
            pPlayer->SEND_GOSSIP_MENU(2555, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //guild master
            pPlayer->SEND_POI(1576.93, -4294.75, 7, 6, 0, "Horde Embassy");
            pPlayer->SEND_GOSSIP_MENU(2556, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(1644.51, -4447.27, 7, 6, 0, "Orgrimmar Inn");
            pPlayer->SEND_GOSSIP_MENU(2557, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //mailbox
            pPlayer->SEND_POI(1622.53, -4388.79, 7, 6, 0, "Orgrimmar Mailbox");
            pPlayer->SEND_GOSSIP_MENU(2558, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //auction house
            pPlayer->SEND_POI(1679.21, -4450.1, 7, 6, 0, "Orgrimmar Auction House");
            pPlayer->SEND_GOSSIP_MENU(3075, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //zeppelin
            pPlayer->SEND_POI(1337.36, -4632.7, 7, 6, 0, "Orgrimmar Zeppelin Tower");
            pPlayer->SEND_GOSSIP_MENU(3173, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //weapon master
            pPlayer->SEND_POI(2092.56, -4823.95, 7, 6, 0, "Sayoc & Hanashi");
            pPlayer->SEND_GOSSIP_MENU(4519, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //stable master
            pPlayer->SEND_POI(2133.12, -4663.93, 7, 6, 0, "Xon'cha");
            pPlayer->SEND_GOSSIP_MENU(5974, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //officers lounge
            pPlayer->SEND_POI(1633.56, -4249.37, 7, 6, 0, "Hall of Legends");
            pPlayer->SEND_GOSSIP_MENU(7046, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //battlemaster
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALTERACVALLEY       , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ARATHIBASIN         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARSONGULCH         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7521, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(2599, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(2594, pCreature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_orgrimmar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            pPlayer->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            pPlayer->SEND_GOSSIP_MENU(7484, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            pPlayer->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            pPlayer->SEND_GOSSIP_MENU(7644, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            pPlayer->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            pPlayer->SEND_GOSSIP_MENU(7520, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_orgrimmar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            pPlayer->SEND_POI(2114.84, -4625.31, 7, 6, 0, "Orgrimmar Hunter's Hall");
            pPlayer->SEND_GOSSIP_MENU(2559, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            pPlayer->SEND_POI(1451.26, -4223.33, 7, 6, 0, "Darkbriar Lodge");
            pPlayer->SEND_GOSSIP_MENU(2560, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            pPlayer->SEND_POI(1442.21, -4183.24, 7, 6, 0, "Spirit Lodge");
            pPlayer->SEND_GOSSIP_MENU(2561, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Shaman
            pPlayer->SEND_POI(1925.34, -4181.89, 7, 6, 0, "Thrall's Fortress");
            pPlayer->SEND_GOSSIP_MENU(2562, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            pPlayer->SEND_POI(1773.39, -4278.97, 7, 6, 0, "Shadowswift Brotherhood");
            pPlayer->SEND_GOSSIP_MENU(2563, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            pPlayer->SEND_POI(1849.57, -4359.68, 7, 6, 0, "Darkfire Enclave");
            pPlayer->SEND_GOSSIP_MENU(2564, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            pPlayer->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            pPlayer->SEND_GOSSIP_MENU(2565, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_orgrimmar(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(1955.17, -4475.79, 7, 6, 0, "Yelmak's Alchemy and Potions");
            pPlayer->SEND_GOSSIP_MENU(2497, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(2054.34, -4831.85, 7, 6, 0, "The Burning Anvil");
            pPlayer->SEND_GOSSIP_MENU(2499, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(1780.96, -4481.31, 7, 6, 0, "Borstan's Firepit");
            pPlayer->SEND_GOSSIP_MENU(2500, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_POI(1917.5, -4434.95, 7, 6, 0, "Godan's Runeworks");
            pPlayer->SEND_GOSSIP_MENU(2501, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(2038.45, -4744.75, 7, 6, 0, "Nogg's Machine Shop");
            pPlayer->SEND_GOSSIP_MENU(2653, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(1485.21, -4160.91, 7, 6, 0, "Survival of the Fittest");
            pPlayer->SEND_GOSSIP_MENU(2502, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(1994.15, -4655.7, 7, 6, 0, "Lumak's Fishing");
            pPlayer->SEND_GOSSIP_MENU(2503, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(1898.61, -4454.93, 7, 6, 0, "Jandi's Arboretum");
            pPlayer->SEND_GOSSIP_MENU(2504, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(1852.82, -4562.31, 7, 6, 0, "Kodohide Leatherworkers");
            pPlayer->SEND_GOSSIP_MENU(2513, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_POI(2029.79, -4704, 7, 6, 0, "Red Canyon Mining");
            pPlayer->SEND_GOSSIP_MENU(2515, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(1852.82, -4562.31, 7, 6, 0, "Kodohide Leatherworkers");
            pPlayer->SEND_GOSSIP_MENU(2516, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(1802.66, -4560.66, 7, 6, 0, "Magar's Cloth Goods");
            pPlayer->SEND_GOSSIP_MENU(2518, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_orgrimmar(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_orgrimmar(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_orgrimmar(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_orgrimmar(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_orgrimmar(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_orgrimmar end
 *******************************************************/

CreatureAI* GetAI_guard_orgrimmar(Creature* pCreature)
{
    return new guardAI_orgrimmar (pCreature);
}

/*******************************************************
 * guard_stormwind start
 *******************************************************/

bool GossipHello_guard_stormwind(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_AUCTIONHOUSE      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STORMWIND_BANK    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DEEPRUNTRAM       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN               , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GRYPHON           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAILBOX           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WEAPONMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_OFFICERS          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATTLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
    pPlayer->SEND_GOSSIP_MENU(933, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_stormwind(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction House
            pPlayer->SEND_POI(-8811.46, 667.46, 7, 6, 0, "Stormwind Auction House");
            pPlayer->SEND_GOSSIP_MENU(3834, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            pPlayer->SEND_POI(-8916.87, 622.87, 7, 6, 0, "Stormwind Bank");
            pPlayer->SEND_GOSSIP_MENU(764, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Deeprun tram
            pPlayer->SEND_POI(-8378.88, 554.23, 7, 6, 0, "The Deeprun Tram");
            pPlayer->SEND_GOSSIP_MENU(3813, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(-8869.0, 675.4, 7, 6, 0, "The Gilded Rose");
            pPlayer->SEND_GOSSIP_MENU(3860, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Gryphon Master
            pPlayer->SEND_POI(-8837.0, 493.5, 7, 6, 0, "Stormwind Gryphon Master");
            pPlayer->SEND_GOSSIP_MENU(879, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Guild Master
            pPlayer->SEND_POI(-8894.0, 611.2, 7, 6, 0, "Stormwind Vistor`s Center");
            pPlayer->SEND_GOSSIP_MENU(882, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Mailbox
            pPlayer->SEND_POI(-8876.48, 649.18, 7, 6, 0, "Stormwind Mailbox");
            pPlayer->SEND_GOSSIP_MENU(3861, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Stable Master
            pPlayer->SEND_POI(-8433.0, 554.7, 7, 6, 0, "Jenova Stoneshield");
            pPlayer->SEND_GOSSIP_MENU(5984, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Weapon Trainer
            pPlayer->SEND_POI(-8797.0, 612.8, 7, 6, 0, "Woo Ping");
            pPlayer->SEND_GOSSIP_MENU(4516, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Officers Lounge
            pPlayer->SEND_POI(-8759.92, 399.69, 7, 6, 0, "Champions` Hall");
            pPlayer->SEND_GOSSIP_MENU(7047, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Battlemasters
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALTERACVALLEY        , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ARATHIBASIN          , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARSONGULCH          , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7499, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Class trainers
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DRUID                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PALADIN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->SEND_GOSSIP_MENU(898, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //Profession trainers
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(918, pCreature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_stormwind(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            pPlayer->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Thelman Slatefist");
            pPlayer->SEND_GOSSIP_MENU(7500, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            pPlayer->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Lady Hoteshem");
            pPlayer->SEND_GOSSIP_MENU(7650, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            pPlayer->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Elfarran");
            pPlayer->SEND_GOSSIP_MENU(7501, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_stormwind(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            pPlayer->SEND_POI(-9012.0, 867.6, 7, 6, 0, "Wizard`s Sanctum");
            pPlayer->SEND_GOSSIP_MENU(899, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Rogue
            pPlayer->SEND_POI(-8753.0, 367.8, 7, 6, 0, "Stormwind - Rogue House");
            pPlayer->SEND_GOSSIP_MENU(900, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Warrior
            pPlayer->SEND_POI(-8624.54, 402.61, 7, 6, 0, "Pig and Whistle Tavern");
            pPlayer->SEND_GOSSIP_MENU(901, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Druid
            pPlayer->SEND_POI(-8751.0, 1124.5, 7, 6, 0, "The Park");
            pPlayer->SEND_GOSSIP_MENU(902, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            pPlayer->SEND_POI(-8512.0, 862.4, 7, 6, 0, "Catedral Of Light");
            pPlayer->SEND_GOSSIP_MENU(903, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Paladin
            pPlayer->SEND_POI(-8577.0, 881.7, 7, 6, 0, "Catedral Of Light");
            pPlayer->SEND_GOSSIP_MENU(904, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Hunter
            pPlayer->SEND_POI(-8413.0, 541.5, 7, 6, 0, "Hunter Lodge");
            pPlayer->SEND_GOSSIP_MENU(905, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Warlock
            pPlayer->SEND_POI(-8948.91, 998.35, 7, 6, 0, "The Slaughtered Lamb");
            pPlayer->SEND_GOSSIP_MENU(906, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_stormwind(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(-8988.0, 759.60, 7, 6, 0, "Alchemy Needs");
            pPlayer->SEND_GOSSIP_MENU(919, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(-8424.0, 616.9, 7, 6, 0, "Therum Deepforge");
            pPlayer->SEND_GOSSIP_MENU(920, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(-8611.0, 364.6, 7, 6, 0, "Pig and Whistle Tavern");
            pPlayer->SEND_GOSSIP_MENU(921, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_POI(-8858.0, 803.7, 7, 6, 0, "Lucan Cordell");
            pPlayer->SEND_GOSSIP_MENU(941, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(-8347.0, 644.1, 7, 6, 0, "Lilliam Sparkspindle");
            pPlayer->SEND_GOSSIP_MENU(922, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(-8513.0, 801.8, 7, 6, 0, "Shaina Fuller");
            pPlayer->SEND_GOSSIP_MENU(923, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(-8803.0, 767.5, 7, 6, 0, "Arnold Leland");
            pPlayer->SEND_GOSSIP_MENU(940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(-8967.0, 779.5, 7, 6, 0, "Alchemy Needs");
            pPlayer->SEND_GOSSIP_MENU(924, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(-8726.0, 477.4, 7, 6, 0, "The Protective Hide");
            pPlayer->SEND_GOSSIP_MENU(925, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_POI(-8434.0, 692.8, 7, 6, 0, "Gelman Stonehand");
            pPlayer->SEND_GOSSIP_MENU(927, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(-8716.0, 469.4, 7, 6, 0, "The Protective Hide");
            pPlayer->SEND_GOSSIP_MENU(928, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(-8938.0, 800.7, 7, 6, 0, "Duncan`s Textiles");
            pPlayer->SEND_GOSSIP_MENU(929, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_stormwind(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_stormwind(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_stormwind(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_stormwind(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_stormwind(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_stormwind end
 *******************************************************/

CreatureAI* GetAI_guard_stormwind(Creature* pCreature)
{
    return new guardAI_stormwind (pCreature);
}

/*******************************************************
 * guard_teldrassil start
 *******************************************************/

bool GossipHello_guard_teldrassil(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FERRY        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->SEND_GOSSIP_MENU(4316, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_teldrassil(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4317, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Rut`theran
            pPlayer->SEND_GOSSIP_MENU(4318, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            pPlayer->SEND_GOSSIP_MENU(4319, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(9821.49, 960.13, 7, 6, 0, "Dolanaar Inn");
            pPlayer->SEND_GOSSIP_MENU(4320, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //stable master
            pPlayer->SEND_POI(9808.37, 931.1, 7, 6, 0, "Seriadne");
            pPlayer->SEND_GOSSIP_MENU(5982, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_DRUID                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(4264, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->SEND_GOSSIP_MENU(4273, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_teldrassil(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            pPlayer->SEND_POI(9741.58, 963.7, 7, 6, 0, "Kal");
            pPlayer->SEND_GOSSIP_MENU(4323, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            pPlayer->SEND_POI(9815.12, 926.28, 7, 6, 0, "Dazalar");
            pPlayer->SEND_GOSSIP_MENU(4324, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            pPlayer->SEND_POI(9906.16, 986.63, 7, 6, 0, "Laurna Morninglight");
            pPlayer->SEND_GOSSIP_MENU(4325, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            pPlayer->SEND_POI(9789, 942.86, 7, 6, 0, "Jannok Breezesong");
            pPlayer->SEND_GOSSIP_MENU(4326, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            pPlayer->SEND_POI(9821.96, 950.61, 7, 6, 0, "Kyra Windblade");
            pPlayer->SEND_GOSSIP_MENU(4327, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_teldrassil(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(9767.59, 878.81, 7, 6, 0, "Cyndra Kindwhisper");
            pPlayer->SEND_GOSSIP_MENU(4329, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Cooking
            pPlayer->SEND_POI(9751.19, 906.13, 7, 6, 0, "Zarrin");
            pPlayer->SEND_GOSSIP_MENU(4330, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Enchanting
            pPlayer->SEND_POI(10677.59, 1946.56, 7, 6, 0, "Alanna Raveneye");
            pPlayer->SEND_GOSSIP_MENU(4331, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //First Aid
            pPlayer->SEND_POI(9903.12, 999, 7, 6, 0, "Byancie");
            pPlayer->SEND_GOSSIP_MENU(4332, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Fishing
            pPlayer->SEND_GOSSIP_MENU(4333, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Herbalism
            pPlayer->SEND_POI(9773.78, 875.88, 7, 6, 0, "Malorne Bladeleaf");
            pPlayer->SEND_GOSSIP_MENU(4334, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            pPlayer->SEND_POI(10152.59, 1681.46, 7, 6, 0, "Nadyia Maneweaver");
            pPlayer->SEND_GOSSIP_MENU(4335, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            pPlayer->SEND_POI(10135.59, 1673.18, 7, 6, 0, "Radnaal Maneweaver");
            pPlayer->SEND_GOSSIP_MENU(4336, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Tailoring
            pPlayer->SEND_GOSSIP_MENU(4337, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_teldrassil(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_teldrassil(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_teldrassil(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_teldrassil(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_teldrassil end
 *******************************************************/

CreatureAI* GetAI_guard_teldrassil(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_tirisfal start
 *******************************************************/

bool GossipHello_guard_tirisfal(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATHANDLER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN             , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->SEND_GOSSIP_MENU(4097, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_tirisfal(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_GOSSIP_MENU(4074, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //bat handler
            pPlayer->SEND_GOSSIP_MENU(4075, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            pPlayer->SEND_POI(2246.68, 241.89, 7, 6, 0, "Gallows` End Tavern");
            pPlayer->SEND_GOSSIP_MENU(4076, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable Master
            pPlayer->SEND_POI(2267.66, 319.32, 7, 6, 0, "Morganus");
            pPlayer->SEND_GOSSIP_MENU(5978, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(4292, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(4096, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_tirisfal(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            pPlayer->SEND_POI(2259.18, 240.93, 7, 6, 0, "Cain Firesong");
            pPlayer->SEND_GOSSIP_MENU(4077, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Priest
            pPlayer->SEND_POI(2259.18, 240.93, 7, 6, 0, "Dark Cleric Beryl");
            pPlayer->SEND_GOSSIP_MENU(4078, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Rogue
            pPlayer->SEND_POI(2259.18, 240.93, 7, 6, 0, "Marion Call");
            pPlayer->SEND_GOSSIP_MENU(4079, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warlock
            pPlayer->SEND_POI(2259.18, 240.93, 7, 6, 0, "Rupert Boch");
            pPlayer->SEND_GOSSIP_MENU(4080, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            pPlayer->SEND_POI(2256.48, 240.32, 7, 6, 0, "Austil de Mon");
            pPlayer->SEND_GOSSIP_MENU(4081, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_tirisfal(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(2263.25, 344.23, 7, 6, 0, "Carolai Anise");
            pPlayer->SEND_GOSSIP_MENU(4082, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_GOSSIP_MENU(4083, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_GOSSIP_MENU(4084, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_POI(2250.35, 249.12, 7, 6, 0, "Vance Undergloom");
            pPlayer->SEND_GOSSIP_MENU(4085, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_GOSSIP_MENU(4086, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(2246.68, 241.89, 7, 6, 0, "Nurse Neela");
            pPlayer->SEND_GOSSIP_MENU(4087, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(2292.37, -10.72, 7, 6, 0, "Clyde Kellen");
            pPlayer->SEND_GOSSIP_MENU(4088, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(2268.21, 331.69, 7, 6, 0, "Faruza");
            pPlayer->SEND_GOSSIP_MENU(4089, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(2027, 78.72, 7, 6, 0, "Shelene Rhobart");
            pPlayer->SEND_GOSSIP_MENU(4090, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_GOSSIP_MENU(4091, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(2027, 78.72, 7, 6, 0, "Rand Rhobart");
            pPlayer->SEND_GOSSIP_MENU(4092, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(2160.45, 659.93, 7, 6, 0, "Bowen Brisboise");
            pPlayer->SEND_GOSSIP_MENU(4093, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_tirisfal(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_tirisfal(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_tirisfal(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_tirisfal(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_tirisfal end
 *******************************************************/

CreatureAI* GetAI_guard_tirisfal(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * guard_undercity start
 *******************************************************/

bool GossipHello_guard_undercity(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATHANDLER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAILBOX       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_AUCTIONHOUSE  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ZEPPLINMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WEAPONMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BATTLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    pPlayer->SEND_GOSSIP_MENU(3543, pCreature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_undercity(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            pPlayer->SEND_POI(1595.64, 232.45, 7, 6, 0, "Undercity Bank");
            pPlayer->SEND_GOSSIP_MENU(3514, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bat handler
            pPlayer->SEND_POI(1565.9, 271.43, 7, 6, 0, "Undercity Bat Handler");
            pPlayer->SEND_GOSSIP_MENU(3515, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            pPlayer->SEND_POI(1594.17, 205.57, 7, 6, 0, "Undercity Guild Master");
            pPlayer->SEND_GOSSIP_MENU(3516, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            pPlayer->SEND_POI(1639.43, 220.99, 7, 6, 0, "Undercity Inn");
            pPlayer->SEND_GOSSIP_MENU(3517, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            pPlayer->SEND_POI(1632.68, 219.4, 7, 6, 0, "Undercity Mailbox");
            pPlayer->SEND_GOSSIP_MENU(3518, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Auction House
            pPlayer->SEND_POI(1647.9, 258.49, 7, 6, 0, "Undercity Auction House");
            pPlayer->SEND_GOSSIP_MENU(3519, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Zeppelin
            pPlayer->SEND_POI(2059, 274.86, 7, 6, 0, "Undercity Zeppelin");
            pPlayer->SEND_GOSSIP_MENU(3520, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Weapon Master
            pPlayer->SEND_POI(1670.31, 324.66, 7, 6, 0, "Archibald");
            pPlayer->SEND_GOSSIP_MENU(4521, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Stable master
            pPlayer->SEND_POI(1634.18, 226.76, 7, 6, 0, "Anya Maulray");
            pPlayer->SEND_GOSSIP_MENU(5979, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Battlemaster
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(7527, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Class trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MAGE            , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARLOCK         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(3542, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Profession trainer
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_ENGINEERING     , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            pPlayer->SEND_GOSSIP_MENU(3541, pCreature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_undercity(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            pPlayer->SEND_POI(1329, 333.92, 7, 6, 0, "Grizzle Halfmane");
            pPlayer->SEND_GOSSIP_MENU(7525, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            pPlayer->SEND_POI(1283.3, 287.16, 7, 6, 0, "Sir Malory Wheeler");
            pPlayer->SEND_GOSSIP_MENU(7646, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            pPlayer->SEND_POI(1265, 351.18, 7, 6, 0, "Kurden Bloodclaw");
            pPlayer->SEND_GOSSIP_MENU(7526, pCreature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_undercity(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            pPlayer->SEND_POI(1781, 53, 7, 6, 0, "Undercity Mage Trainers");
            pPlayer->SEND_GOSSIP_MENU(3513, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Priest
            pPlayer->SEND_POI(1758.33, 401.5, 7, 6, 0, "Undercity Priest Trainers");
            pPlayer->SEND_GOSSIP_MENU(3521, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Rogue
            pPlayer->SEND_POI(1418.56, 65, 7, 6, 0, "Undercity Rogue Trainers");
            pPlayer->SEND_GOSSIP_MENU(3524, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warlock
            pPlayer->SEND_POI(1780.92, 53.16, 7, 6, 0, "Undercity Warlock Trainers");
            pPlayer->SEND_GOSSIP_MENU(3526, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            pPlayer->SEND_POI(1775.59, 418.19, 7, 6, 0, "Undercity Warrior Trainers");
            pPlayer->SEND_GOSSIP_MENU(3527, pCreature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_undercity(Player* pPlayer, Creature* pCreature, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            pPlayer->SEND_POI(1419.82, 417.19, 7, 6, 0, "The Apothecarium");
            pPlayer->SEND_GOSSIP_MENU(3528, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            pPlayer->SEND_POI(1696, 285, 7, 6, 0, "Undercity Blacksmithing Trainer");
            pPlayer->SEND_GOSSIP_MENU(3529, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            pPlayer->SEND_POI(1596.34, 274.68, 7, 6, 0, "Undercity Cooking Trainer");
            pPlayer->SEND_GOSSIP_MENU(3530, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            pPlayer->SEND_POI(1488.54, 280.19, 7, 6, 0, "Undercity Enchanting Trainer");
            pPlayer->SEND_GOSSIP_MENU(3531, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            pPlayer->SEND_POI(1408.58, 143.43, 7, 6, 0, "Undercity Engineering Trainer");
            pPlayer->SEND_GOSSIP_MENU(3532, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            pPlayer->SEND_POI(1519.65, 167.19, 7, 6, 0, "Undercity First Aid Trainer");
            pPlayer->SEND_GOSSIP_MENU(3533, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            pPlayer->SEND_POI(1679.9, 89, 7, 6, 0, "Undercity Fishing Trainer");
            pPlayer->SEND_GOSSIP_MENU(3534, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            pPlayer->SEND_POI(1558, 349.36, 7, 6, 0, "Undercity Herbalism Trainer");
            pPlayer->SEND_GOSSIP_MENU(3535, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            pPlayer->SEND_POI(1498.76, 196.43, 7, 6, 0, "Undercity Leatherworking Trainer");
            pPlayer->SEND_GOSSIP_MENU(3536, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            pPlayer->SEND_POI(1642.88, 335.58, 7, 6, 0, "Undercity Mining Trainer");
            pPlayer->SEND_GOSSIP_MENU(3537, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            pPlayer->SEND_POI(1498.6, 196.46, 7, 6, 0, "Undercity Skinning Trainer");
            pPlayer->SEND_GOSSIP_MENU(3538, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            pPlayer->SEND_POI(1689.55, 193, 7, 6, 0, "Undercity Tailoring Trainer");
            pPlayer->SEND_GOSSIP_MENU(3539, pCreature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_undercity(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiSender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_undercity(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_undercity(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_undercity(pPlayer, pCreature, uiAction); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_undercity(pPlayer, pCreature, uiAction); break;
    }
    return true;
}

/*******************************************************
 * guard_undercity end
 *******************************************************/

CreatureAI* GetAI_guard_undercity(Creature* pCreature)
{
    return new guardAI(pCreature);
}

/*******************************************************
 * AddSC
 *******************************************************/

void AddSC_guards()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "guard_contested";
    newscript->GetAI = &GetAI_guard_contested;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_darnassus";
    newscript->pGossipHello          = &GossipHello_guard_darnassus;
    newscript->pGossipSelect         = &GossipSelect_guard_darnassus;
    newscript->GetAI = &GetAI_guard_darnassus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_dunmorogh";
    newscript->pGossipHello          = &GossipHello_guard_dunmorogh;
    newscript->pGossipSelect         = &GossipSelect_guard_dunmorogh;
    newscript->GetAI = &GetAI_guard_dunmorogh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_durotar";
    newscript->pGossipHello          = &GossipHello_guard_durotar;
    newscript->pGossipSelect         = &GossipSelect_guard_durotar;
    newscript->GetAI = &GetAI_guard_durotar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_elwynnforest";
    newscript->pGossipHello          = &GossipHello_guard_elwynnforest;
    newscript->pGossipSelect         = &GossipSelect_guard_elwynnforest;
    newscript->GetAI = &GetAI_guard_elwynnforest;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_ironforge";
    newscript->pGossipHello          = &GossipHello_guard_ironforge;
    newscript->pGossipSelect         = &GossipSelect_guard_ironforge;
    newscript->GetAI = &GetAI_guard_ironforge;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_mulgore";
    newscript->pGossipHello          = &GossipHello_guard_mulgore;
    newscript->pGossipSelect         = &GossipSelect_guard_mulgore;
    newscript->GetAI = &GetAI_guard_mulgore;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_orgrimmar";
    newscript->pGossipHello          = &GossipHello_guard_orgrimmar;
    newscript->pGossipSelect         = &GossipSelect_guard_orgrimmar;
    newscript->GetAI = &GetAI_guard_orgrimmar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_stormwind";
    newscript->pGossipHello          = &GossipHello_guard_stormwind;
    newscript->pGossipSelect         = &GossipSelect_guard_stormwind;
    newscript->GetAI = &GetAI_guard_stormwind;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_teldrassil";
    newscript->pGossipHello          = &GossipHello_guard_teldrassil;
    newscript->pGossipSelect         = &GossipSelect_guard_teldrassil;
    newscript->GetAI = &GetAI_guard_teldrassil;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_tirisfal";
    newscript->pGossipHello          = &GossipHello_guard_tirisfal;
    newscript->pGossipSelect         = &GossipSelect_guard_tirisfal;
    newscript->GetAI = &GetAI_guard_tirisfal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "guard_undercity";
    newscript->pGossipHello          = &GossipHello_guard_undercity;
    newscript->pGossipSelect         = &GossipSelect_guard_undercity;
    newscript->GetAI = &GetAI_guard_undercity;
    newscript->RegisterSelf();
}
