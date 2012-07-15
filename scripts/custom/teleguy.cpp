/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* Copyright (C) 2011 MangosR2
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* ScriptData
SDName: npc_teleguy
SD%Complete: 100%
SDComment: by tempura, modify by Asprorpsa
SDCategory: custom
EndScriptData */

#include "precompiled.h"
long long int money;
int costo;

bool GossipHello_mob_teleguy(Player* player, Creature* _Creature)
{
    if (player->GetTeam() == ALLIANCE)
    {
        player->ADD_GOSSIP_ITEM( 5, "Darnassus. 5 Platas" , GOSSIP_SENDER_MAIN, 1203);
        player->ADD_GOSSIP_ITEM( 5, "Exodar. 5 Platas" , GOSSIP_SENDER_MAIN, 1216);
        player->ADD_GOSSIP_ITEM( 5, "Ciudad de Ventormenta. 5 Platas" , GOSSIP_SENDER_MAIN, 1206);
        player->ADD_GOSSIP_ITEM( 5, "Forjaz. 5 Platas" , GOSSIP_SENDER_MAIN, 1224);
        player->ADD_GOSSIP_ITEM( 5, "Ciudad de Shattrath. 5 Platas" , GOSSIP_SENDER_MAIN, 1287);
        player->ADD_GOSSIP_ITEM( 5, "Dalaran. 5 Platas" , GOSSIP_SENDER_MAIN, 1205);
        player->ADD_GOSSIP_ITEM( 5, "Isla de Quel'Danas. 5 Platas" , GOSSIP_SENDER_MAIN, 1288);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Normales] ->" , GOSSIP_SENDER_MAIN, 5550);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Burning Crusade] ->" , GOSSIP_SENDER_MAIN, 5553);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5554);
        player->ADD_GOSSIP_ITEM( 7, "[Raids Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5555);
    }
    else
    {
        player->ADD_GOSSIP_ITEM( 5, "Orgrimmar. 5 Platas" , GOSSIP_SENDER_MAIN, 1215);
        player->ADD_GOSSIP_ITEM( 5, "Ciudad de Lunargenta. 5 Platas" , GOSSIP_SENDER_MAIN, 1217);
        player->ADD_GOSSIP_ITEM( 5, "Entra�as. 5 Platas" , GOSSIP_SENDER_MAIN, 1213);
        player->ADD_GOSSIP_ITEM( 5, "Cima del Trueno. 5 Platas" , GOSSIP_SENDER_MAIN, 1225);
        player->ADD_GOSSIP_ITEM( 5, "Ciudad de Shattrath. 5 Platas" , GOSSIP_SENDER_MAIN, 1287);
        player->ADD_GOSSIP_ITEM( 5, "Dalaran. 5 Platas" , GOSSIP_SENDER_MAIN, 1205);
        player->ADD_GOSSIP_ITEM( 5, "Isla de Quel'Danas. 5 Platas" , GOSSIP_SENDER_MAIN, 1288);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Normales] ->" , GOSSIP_SENDER_MAIN, 5550);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Burning Crusade] ->" , GOSSIP_SENDER_MAIN, 5553);
        player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5554);
        player->ADD_GOSSIP_ITEM( 7, "[Raids Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5555);
    }
    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
    return true;
}

void SendDefaultMenu_mob_teleguy(Player* player, Creature* _Creature, uint32 action)
{
    if (player->IsInCombat())
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->MonsterSay("�Est�s en combate!", LANG_UNIVERSAL);
        return;
    }

    if (player->getLevel() < 8)
    {
         player->CLOSE_GOSSIP_MENU();
        _Creature->MonsterSay("Debes estar a nivel 8+", LANG_UNIVERSAL);
        return;
    }

    money = player-> GetMoney();
    costo = 500;

    if (money < costo)
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->MonsterSay("No tiene suficiente dinero", LANG_UNIVERSAL);
        return;
    }

    switch(action)
    {
        case 5550: // Normal Instances
        {
            // Teleport to the points that are close to the enemy capital closed
            if (player->GetTeam() == ALLIANCE)
            {
                player->ADD_GOSSIP_ITEM( 5, "Las Mazmorras. 10 Platas" , GOSSIP_SENDER_MAIN, 1253);
                player->ADD_GOSSIP_ITEM( 5, "Gnomeregan. 10 Platas " , GOSSIP_SENDER_MAIN, 1222);
            }
            else
            {
                player->ADD_GOSSIP_ITEM( 5, "Monasterio Escarlata. 10 Platas" , GOSSIP_SENDER_MAIN, 1257);
                player->ADD_GOSSIP_ITEM( 5, "Sima �gnea. 10 Platas" , GOSSIP_SENDER_MAIN, 1248);
            }
            player->ADD_GOSSIP_ITEM( 5, "Cuevas de los Lamentos. 10 Platas" , GOSSIP_SENDER_MAIN, 1249);
            player->ADD_GOSSIP_ITEM( 5, "Minas de la Muerte. 10 Platas" , GOSSIP_SENDER_MAIN, 1250);
            player->ADD_GOSSIP_ITEM( 5, "Castillo de Colmillo Oscuro. 10 Platas" , GOSSIP_SENDER_MAIN, 1251);
            player->ADD_GOSSIP_ITEM( 5, "Cavernas de Brazanegra. 10 Platas" , GOSSIP_SENDER_MAIN, 1252);
            player->ADD_GOSSIP_ITEM( 5, "Horado Rajacieno. 20 Platas" , GOSSIP_SENDER_MAIN, 1254);
            player->ADD_GOSSIP_ITEM( 5, "Zahurda Rajacieno. 20 Platas" , GOSSIP_SENDER_MAIN, 1256);
            player->ADD_GOSSIP_ITEM( 7, "[Mas] ->" , GOSSIP_SENDER_MAIN, 5551);
            player->ADD_GOSSIP_ITEM( 7, "<- [Menu Principal]" , GOSSIP_SENDER_MAIN, 5552);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 5551: // More Normal Instances
        {
            player->ADD_GOSSIP_ITEM( 5, "Uldaman. 30 Platas" , GOSSIP_SENDER_MAIN, 1258);
            player->ADD_GOSSIP_ITEM( 5, "Zul'Farrak. 30 Platas" , GOSSIP_SENDER_MAIN, 1259);
            player->ADD_GOSSIP_ITEM( 5, "Maraudon. 40 Platas" , GOSSIP_SENDER_MAIN, 1260);
            player->ADD_GOSSIP_ITEM( 5, "Templo Sumergido. 40 Platas" , GOSSIP_SENDER_MAIN, 1261);
            player->ADD_GOSSIP_ITEM( 5, "Profundidades de Roca Negra. 40 Platas" , GOSSIP_SENDER_MAIN, 1262);
            player->ADD_GOSSIP_ITEM( 5, "La Masacre. 50 Platas" , GOSSIP_SENDER_MAIN, 1263);
            player->ADD_GOSSIP_ITEM( 5, "Cumbre de Roca Negra. 50 Platas" , GOSSIP_SENDER_MAIN, 1264);
            player->ADD_GOSSIP_ITEM( 5, "Stratholme. 50 Platas" , GOSSIP_SENDER_MAIN, 1265);
            player->ADD_GOSSIP_ITEM( 5, "Scholomance. 50 Platas" , GOSSIP_SENDER_MAIN, 1266);
            player->ADD_GOSSIP_ITEM( 5, "Ahn'Qiraj. 50 Platas" , GOSSIP_SENDER_MAIN, 1267);
            player->ADD_GOSSIP_ITEM( 5, "Zul'Gurub. 50 Platas" , GOSSIP_SENDER_MAIN, 1268);
            player->ADD_GOSSIP_ITEM( 7, "<- [Atras]" , GOSSIP_SENDER_MAIN, 5550);
            player->ADD_GOSSIP_ITEM( 7, "<- [Menu Principal]" , GOSSIP_SENDER_MAIN, 5552);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 5553: // Instances 60-70 BC
        {
            player->ADD_GOSSIP_ITEM( 5, "Auchindoun. 1 Oro" , GOSSIP_SENDER_MAIN, 4006);
            player->ADD_GOSSIP_ITEM( 5, "Karazhan. 1 Oro" , GOSSIP_SENDER_MAIN, 4007);
            player->ADD_GOSSIP_ITEM( 5, "Guarida de Gruul. 1 Oro" , GOSSIP_SENDER_MAIN, 4008);
            player->ADD_GOSSIP_ITEM( 5, "Ciudadela del Fuego Infernal. 1 Oro" , GOSSIP_SENDER_MAIN, 4009);
            player->ADD_GOSSIP_ITEM( 5, "Reserva Colmillo Torcido. 1 Oro" , GOSSIP_SENDER_MAIN, 4010);
            player->ADD_GOSSIP_ITEM( 5, "El Castillo de la Tempestad. 1 Oro" , GOSSIP_SENDER_MAIN, 4011);
            player->ADD_GOSSIP_ITEM( 5, "Zul'Aman. 1 Oro" , GOSSIP_SENDER_MAIN, 4016);
            player->ADD_GOSSIP_ITEM( 5, "Templo Oscuro. 1 Oro" , GOSSIP_SENDER_MAIN, 4013);
            player->ADD_GOSSIP_ITEM( 5, "Bancal del Magister. 2 Oros" , GOSSIP_SENDER_MAIN, 4017);
            player->ADD_GOSSIP_ITEM( 7, "<- [Menu Principal]" , GOSSIP_SENDER_MAIN, 5552);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 5554: // Instances 70-80 WotLK
        {
            player->ADD_GOSSIP_ITEM( 5, "Cavernas del Tiempo. 20 Oros" , GOSSIP_SENDER_MAIN, 4012);
            player->ADD_GOSSIP_ITEM( 5, "Fortaleza de Utgarde. 20 Oros" , GOSSIP_SENDER_MAIN, 4019);
            player->ADD_GOSSIP_ITEM( 5, "Azjol-Nerub. 20 Oros" , GOSSIP_SENDER_MAIN, 4021);
            player->ADD_GOSSIP_ITEM( 5, "El Antiguo Reino. 20 Oros" , GOSSIP_SENDER_MAIN, 4022);
            player->ADD_GOSSIP_ITEM( 5, "Fortaleza de Drak'Tharon. 20 Oros" , GOSSIP_SENDER_MAIN, 4023);
            player->ADD_GOSSIP_ITEM( 5, "Gundrak. 20 Oros" , GOSSIP_SENDER_MAIN, 4025);
            player->ADD_GOSSIP_ITEM( 5, "Pinaculo de Utgarde. 20 Oros" , GOSSIP_SENDER_MAIN, 4026);
            player->ADD_GOSSIP_ITEM( 5, "Camaras de Piedra. 20 Oros" , GOSSIP_SENDER_MAIN, 4032);
            player->ADD_GOSSIP_ITEM( 5, "Camaras de Relampagos. 20 Oros" , GOSSIP_SENDER_MAIN, 4033);
            player->ADD_GOSSIP_ITEM( 5, "Las Camaras Heladas. 20 Oros" , GOSSIP_SENDER_MAIN, 4034);
            player->ADD_GOSSIP_ITEM( 7, "<- [Menu Principal]" , GOSSIP_SENDER_MAIN, 5552);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 5555: // Raids 80 WotLK
        {
            player->ADD_GOSSIP_ITEM( 5, "El Nexo. 30 Oros" , GOSSIP_SENDER_MAIN, 4020);
            player->ADD_GOSSIP_ITEM( 5, "Campos del Torneo de Argenta. 30 Oros" , GOSSIP_SENDER_MAIN, 4024);
            player->ADD_GOSSIP_ITEM( 5, "Ulduar. 30 Oros" , GOSSIP_SENDER_MAIN, 4027);
            player->ADD_GOSSIP_ITEM( 5, "Templo del Reposo del Dragon . 40 Oros" , GOSSIP_SENDER_MAIN, 4028);
            player->ADD_GOSSIP_ITEM( 5, "Naxxramas. 30 Oros" , GOSSIP_SENDER_MAIN, 4029);
            player->ADD_GOSSIP_ITEM( 5, "Ciudadela Corona de Hielo. 40 Oros" , GOSSIP_SENDER_MAIN, 4030);
            player->ADD_GOSSIP_ITEM( 5, "Camara de Archavon. 40 Oros" , GOSSIP_SENDER_MAIN, 4031);
            player->ADD_GOSSIP_ITEM( 5, "Guarida de Onyxia. 40 Oros" , GOSSIP_SENDER_MAIN, 4035);
            player->ADD_GOSSIP_ITEM( 7, "<- [Menu Principal]" , GOSSIP_SENDER_MAIN, 5552);

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 5552: // Back To Main Menu
        {
            if (player->GetTeam() == ALLIANCE)
            {
                player->ADD_GOSSIP_ITEM( 5, "Darnassus. 5 Platas" , GOSSIP_SENDER_MAIN, 1203);
                player->ADD_GOSSIP_ITEM( 5, "Exodar. 5 Platas" , GOSSIP_SENDER_MAIN, 1216);
                player->ADD_GOSSIP_ITEM( 5, "Ciudad de Ventormenta. 5 Platas" , GOSSIP_SENDER_MAIN, 1206);
                player->ADD_GOSSIP_ITEM( 5, "Forjaz. 5 Platas" , GOSSIP_SENDER_MAIN, 1224);
                player->ADD_GOSSIP_ITEM( 5, "Ciudad de Shattrath. 5 Platas" , GOSSIP_SENDER_MAIN, 1287);
                player->ADD_GOSSIP_ITEM( 5, "Dalaran. 5 Platas" , GOSSIP_SENDER_MAIN, 1205);
                player->ADD_GOSSIP_ITEM( 5, "Isle Of Quel'Danas. 5 Platas" , GOSSIP_SENDER_MAIN, 1288);
                player->ADD_GOSSIP_ITEM( 7, "[Instancias Normales] ->" , GOSSIP_SENDER_MAIN, 5550);
                player->ADD_GOSSIP_ITEM( 7, "[Instancias Burning Crusade] ->" , GOSSIP_SENDER_MAIN, 5553);
                player->ADD_GOSSIP_ITEM( 7, "[Instancias Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5554);
                player->ADD_GOSSIP_ITEM( 7, "[Raids Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5555);
            }
            else
            {
                player->ADD_GOSSIP_ITEM( 5, "Orgrimmar. 5 Platas" , GOSSIP_SENDER_MAIN, 1215);
                player->ADD_GOSSIP_ITEM( 5, "Ciudad de Lunargenta. 5 Platas" , GOSSIP_SENDER_MAIN, 1217);
                player->ADD_GOSSIP_ITEM( 5, "Entra�as. 5 Platas" , GOSSIP_SENDER_MAIN, 1213);
                player->ADD_GOSSIP_ITEM( 5, "Cima del Trueno. 5 Platas" , GOSSIP_SENDER_MAIN, 1225);
                player->ADD_GOSSIP_ITEM( 5, "Ciudad de Shattrath. 5 Platas" , GOSSIP_SENDER_MAIN, 1287);
                player->ADD_GOSSIP_ITEM( 5, "Dalaran. 5 Platas" , GOSSIP_SENDER_MAIN, 1205);
                player->ADD_GOSSIP_ITEM( 5, "Isla de Quel'Danas. 5 Platas" , GOSSIP_SENDER_MAIN, 1288);
                player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Normales] ->" , GOSSIP_SENDER_MAIN, 5550);
                player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Burning Crusade] ->" , GOSSIP_SENDER_MAIN, 5553);
                player->ADD_GOSSIP_ITEM( 7, "[Mazmorras Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5554);
                player->ADD_GOSSIP_ITEM( 7, "[Raids Wrath of the Lich King] ->" , GOSSIP_SENDER_MAIN, 5555);
            }
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_Creature->GetObjectGuid());
        }
        break;

        case 1203: // Darnassus
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 9947.52f, 2482.73f, 1316.21f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1206: // Stormwind
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -8960.14f, 516.266f, 96.3568f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1205: // Dalaran
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(571, 5804.14f, 624.770f, 647.7670f, 1.64f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1213: // Undercity
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, 1819.71f, 238.79f, 60.5321f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1215: // Orgrimmar
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, 1552.5f, -4420.66f, 8.94802f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1216: // Exodar
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(530, -4073.03f, -12020.4f, -1.47f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1217: // Silvermoon
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(530, 9338.74f, -7277.27f, 13.7895f, 0.0f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1222: // Gnomeregan
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -5163.43f, 660.40f, 348.28f, 4.65f);
            player->ModifyMoney(-2*costo);
        }
        break;

        case 1224: // Ironforge
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(0, -4924.07f, -951.95f, 501.55f, 5.40f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1225: // Thunder Bluff
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(1, -1280.19f, 127.21f, 131.35f, 5.16f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1287: // Shattrath City
        {

            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(530, -1850.209961f, 5435.821777f, -10.961435f, 3.403913f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1288: // Isle Of Quel'Danas
        {
            player->CLOSE_GOSSIP_MENU();
            player->TeleportTo(530, 12947.4f, -6893.31f, 5.68398f, 3.09154f);
            player->ModifyMoney(-1*costo);
        }
        break;

        case 1248: // Ragefire Chasm
        {
            if(player->getLevel() >= 8)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 1800.53f, -4394.68f, -17.93f, 5.49f);
                player->ModifyMoney(-2*costo);
            }
        else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 8!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1249: // Wailing Caverns
        {
            if (player->getLevel() >= 10)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -722.53f, -2226.30f, 16.94f, 2.71f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 10!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1250: // Deadmines
        {
            if (player->getLevel() >= 10)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -11212.04f, 1658.58f, 25.67f, 1.45f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 10!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1251: // Shadowfang Keep
        {
            if (player->getLevel() >= 11)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -254.47f, 1524.68f, 76.89f, 1.56f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 11!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1252: // Blackfathom Deeps
        {
            if (player->getLevel() >= 15)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, 4254.58f, 664.74f, -29.04f, 1.97f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 15!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1253: // The Stockade
        {
            if (player->getLevel() >= 15)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -8769.76f, 813.08f, 97.63f, 2.26f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 15!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1254: // Razorfen Kraul
        {
            if (player->getLevel() >= 25)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -4484.04f, -1739.40f, 86.47f, 1.23f);
                player->ModifyMoney(-4*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 25!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1255: // Gnomeregan
        {
            if (player->getLevel() >= 19)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -5162.62f, 667.81f, 248.05f, 1.48f);
                player->ModifyMoney(-4*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 19!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1256: // Razorfen Downs
        {
            if (player->getLevel() >= 35)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -4645.08f, -2470.85f, 85.53f, 4.39f);
                player->ModifyMoney(-4*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 35!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1257: // Scarlet Monastery
        {
            if (player->getLevel() >= 21)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 2843.89f, -693.74f, 139.32f, 5.11f);
                player->ModifyMoney(-2*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 21!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1258: // Uldaman
        {
            if (player->getLevel() >= 30)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -6119.70f, -2957.30f, 204.11f, 0.03f);
                player->ModifyMoney(-6*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 30!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1259: // Zul'Farrak
        {
            if (player->getLevel() >= 39)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -6839.39f, -2911.03f, 8.87f, 0.41f);
                player->ModifyMoney(-6*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 39!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1260: // Maraudon
        {
            if (player->getLevel() >= 25)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -1433.33f, 2955.34f, 96.21f, 4.82f);
                player->ModifyMoney(-8*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 25!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1261: // Sunken Temple
        {
            if (player->getLevel() >= 45)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -10346.92f, -3851.90f, -43.41f, 6.09f);
                player->ModifyMoney(-8*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 45!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1262: // Blackrock Depths
        {
            if (player->getLevel() >= 42)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -7301.03f, -913.19f, 165.37f, 0.08f);
                player->ModifyMoney(-8*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 42!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1263: // Dire Maul
        {
            if (player->getLevel() >= 31)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -3982.47f, 1127.79f, 161.02f, 0.05f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 31!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1264: // Blackrock Spire
        {
            if (player->getLevel() >= 48)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -7535.43f, -1212.04f, 285.45f, 5.29f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 48!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1265: // Stratholme
        {
            if (player->getLevel() >= 37)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 3263.54f, -3379.46f, 143.59f, 0.00f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 37!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1266: // Scholomance
        {
            if (player->getLevel() >= 37)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, 1219.01f, -2604.66f, 85.61f, 0.50f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 37!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1267: // Ahn'Qiraj
        {
            if (player->getLevel() >= 50)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -8169.81f, 1528.11f, 4.195f, 2.948f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 50!", LANG_UNIVERSAL);
            }
        }
        break;

        case 1268: // Zul'Gurub
        {
            if (player->getLevel() >= 50)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -11916.1f, -1223.97f, 92.288f, 4.707f);
                player->ModifyMoney(-10*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 50!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4006: // Auchindoun
        {
            if (player->getLevel() >= 55)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -3304.64f, 4916.23f, -105.125f, 2.53837f);
                player->ModifyMoney(-40*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 55!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4007: // Karazhan
        {
            if (player->getLevel() >= 68)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(0, -11118.8f, -2010.84f, 47.0807f, 0.0f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 68!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4008: // Gruul's Lair
        {
            if (player->getLevel() >= 65)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 3539.007568f, 5082.357910f, 1.691071f, 0.0f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 65!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4009: // Hellfire Citadel
        {
            if (player->getLevel() >= 55)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -305.816223f, 3056.401611f, -2.473183f, 2.01f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 55!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4010: // Coilfang Reservoir
        {
            if (player->getLevel() >= 55)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 517.288025f, 6976.279785f, 32.007198f, 0.0f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 55!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4011: // Tempest Keep
        {
            if (player->getLevel() >= 65)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 3089.579346f, 1399.046509f, 187.653458f, 4.794070f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 65!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4012: // Caverns of Time
        {
            if (player->getLevel() >= 66)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -8173.66f, -4746.36f, 33.8423f, 4.93989f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 66!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4016: // Zul'Aman
        {
            if (player->getLevel() >= 68)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 6846.95f, -7954.5f, 170.028f, 4.61501f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 68!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4013: // Black Temple
        {
            if (player->getLevel() >= 70)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, -3610.719482f, 324.987579f, 37.400028f, 3.282981f);
                player->ModifyMoney(-20*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 70!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4017: // Magisters' Terrace
        {
            if (player->getLevel() >= 65)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(530, 12884.6f, -7317.69f, 65.5023f, 4.799f);
                player->ModifyMoney(-40*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 65!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4019: // Utgarde Keep
        {
            if (player->getLevel() >= 68)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 1219.720f, -4865.28f, 41.25f, 0.31f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 68!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4020: // The Nexus
        {
            if (player->getLevel() >= 66)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3776.950f, 6953.80f, 105.05f, 0.345f);
                player->ModifyMoney(-600*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 66!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4021: // Azjol-Nerub
        {
            if (player->getLevel() >= 67)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3675.430f, 2169.00f, 35.90f, 2.29f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 67!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4022: // The Old Kingdom
        {
            if (player->getLevel() >= 68)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3646.760f, 2045.17f, 1.79f, 4.37f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 68!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4023: // Drak'Tharon Keep
        {
            if (player->getLevel() >= 69)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 4450.860f, -2045.25f, 162.83f, 0.00f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 69!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4024: // Coliseum Vanguard
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 8551.76f, 635.458f, 548.063f, 3.557f);
                player->ModifyMoney(-600*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4025: // Gundrak
        {
            if (player->getLevel() >= 71)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 6937.540f, -4455.98f, 450.68f, 1.00f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 71!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4026: // Utgarde Pinnacle
        {
            if (player->getLevel() >= 75)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 1245.690f, -4856.59f, 216.86f, 3.45f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 75!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4027: // Ulduar
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 8976.240f, -1281.33f, 1059.01f, 0.58f);
                player->ModifyMoney(-600*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4028: // Wyrmrest Temple
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3625.780f, 280.40f, -120.14f, 3.25f);
                player->ModifyMoney(-800*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4029: // Naxxramas
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 3668.719f, -1262.460f, 243.63f, 5.03f);
                player->ModifyMoney(-600*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4030: // Icecrown Citadel
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5809.48f, 2080.53f, 636.064f, 3.599f);
                player->ModifyMoney(-800*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4031: // Vault of Archavon
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5321.13f, 2843.42f, 409.283f, 6.255f);
                player->ModifyMoney(-800*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4032: // Halls of Stone
        {
            if (player->getLevel() >= 72)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 8923.37f, -1036.56f, 1039.81f, 1.592f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 72!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4033: // Halls of Lightning
        {
            if (player->getLevel() >= 75)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 9121.08f, -1330.12f, 1060.32f, 5.577f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 75!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4034: // Frozen Halls
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(571, 5635.59f, 2052.15f, 798.045f, 4.580f);
                player->ModifyMoney(-400*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;

        case 4035: // Onyxia's Lair
        {
            if (player->getLevel() >= 80)
            {
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(1, -4640.93f, -3623.18f, 39.461f, 4.474f);
                player->ModifyMoney(-800*costo);
            }
            else
            {
                player->CLOSE_GOSSIP_MENU();
                _Creature->MonsterSay("�Debes estar al menos a nivel 80!", LANG_UNIVERSAL);
            }
        }
        break;
    }
}

bool GossipSelect_mob_teleguy(Player* player, Creature* _Creature, uint32 sender, uint32 action)
{
    // Main menu
    if (sender == GOSSIP_SENDER_MAIN)
    {
        player->PlayerTalkClass->ClearMenus();
        SendDefaultMenu_mob_teleguy(player, _Creature, action);
    }
    return true;
}

void AddSC_mob_teleguy()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "mob_teleguy";
    pNewScript->pGossipHello = &GossipHello_mob_teleguy;
    pNewScript->pGossipSelect = &GossipSelect_mob_teleguy;
    pNewScript->RegisterSelf();
}