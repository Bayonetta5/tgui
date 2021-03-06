/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2017 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Tests.hpp"
#include <TGUI/Widgets/Panel.hpp>
#include <TGUI/Gui.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

using tgui::Layout;
using tgui::Layout2d;
using tgui::RelLayout;

TEST_CASE("[Layouts]")
{
    SECTION("constants")
    {
        Layout l1;
        REQUIRE(l1.toString() == "0");

        Layout l2(-20.3f);
        REQUIRE(l2.toString() == "-20.3");

        Layout l3{"60"};
        REQUIRE(l3.toString() == "60");

        Layout2d l4;
        REQUIRE(l4.toString() == "(0, 0)");

        Layout2d l5{10.f, "-50"};
        REQUIRE(l5.toString() == "(10, -50)");

        SECTION("updating parent size")
        {
            l1.updateParentSize(110);
            l2.updateParentSize(120);
            l3.updateParentSize(130);
            l4.updateParentSize({141, 142});
            l5.updateParentSize({153, 154});

            REQUIRE(l1.getValue() == 0);
            REQUIRE(l2.getValue() == -20.3f);
            REQUIRE(l3.getValue() == 60);
            REQUIRE(l4.getValue() == sf::Vector2f(0, 0));
            REQUIRE(l5.getValue() == sf::Vector2f(10, -50));
        }
    }

    SECTION("relative values")
    {
        Layout l1{"60%"};
        REQUIRE(l1.toString() == "60%");

        Layout2d l2{{"40%"}, {"5%"}};
        REQUIRE(l2.toString() == "(40%, 5%)");

        Layout2d l3{40, "25.3%"};
        REQUIRE(l3.toString() == "(40, 25.3%)");

        Layout l4{RelLayout{0.35f}};
        REQUIRE(l4.toString() == "35%");

        Layout l5{RelLayout{0.35f, -10}};
        REQUIRE(l5.toString() == "35% - 10");

        SECTION("updating parent size")
        {
            REQUIRE(l1.getValue() == 0);
            l1.updateParentSize(250);
            REQUIRE(l1.getValue() == 250*0.6f);
            l1.updateParentSize(100);
            REQUIRE(l1.getValue() == 100*0.6f);
            REQUIRE(l1.toString() == "60%");

            l2.updateParentSize({150, 120});
            REQUIRE(l2.x.getValue() == 150*0.4f);
            REQUIRE(l2.y.getValue() == 120*0.05f);
            REQUIRE(l2.toString() == "(40%, 5%)");

            l3.updateParentSize({300, 506});
            REQUIRE(l3.x.getValue() == 40);
            REQUIRE(l3.y.getValue() == 506*0.253f);
            REQUIRE(l3.toString() == "(40, 25.3%)");

            l4.updateParentSize(40);
            REQUIRE(l4.getValue() == 14);
            REQUIRE(l4.toString() == "35%");

            l5.updateParentSize(40);
            REQUIRE(l5.getValue() == 4);
            REQUIRE(l5.toString() == "35% - 10");
        }
    }

    SECTION("calculations")
    {
        Layout l{""};
        REQUIRE(l.getValue() == 0);

        Layout l2{"10 - 5% - 60 + 25.5% + 20 - 15"};
        REQUIRE(l2.toString() == "20.5% - 45");

        Layout l3{"+10.5 + 150 + -20%"};
        REQUIRE(l3.toString() == "-20% + 160.5");
    }
}
