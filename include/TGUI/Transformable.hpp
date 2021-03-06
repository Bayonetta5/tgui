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

#ifndef TGUI_TRANSFORMABLE_HPP
#define TGUI_TRANSFORMABLE_HPP


#include <TGUI/Layout.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class TGUI_API Transformable
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the position of the widget
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a transformable widget is (0, 0).
        ///
        /// @param position New position
        ///
        /// @see move, getPosition
        ///
        /// Usage examples:
        /// @code
        /// // Place the widget on an exact position
        /// widget->setPosition({40, 30});
        ///
        /// // Place the widget relative to the size of its parent
        /// widget->setPosition({"5%", "10%"});
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setPosition(const Layout2d& position)
        {
            m_position = position;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the position of the widget
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a transformable widget is (0, 0).
        ///
        /// @param x  New x coordinate
        /// @param y  New y coordinate
        ///
        /// @see move, getPosition
        ///
        /// Usage examples:
        /// @code
        /// // Place the widget on an exact position
        /// widget->setPosition(40, 30);
        ///
        /// // Place the widget relative to the size of its parent
        /// widget->setPosition("5%", "10%");
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPosition(Layout x, Layout y)
        {
            setPosition({std::move(x), std::move(y)});
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Gets the position of the widget
        ///
        /// @return Current position
        ///
        /// @see setPosition
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Vector2f getPosition() const
        {
            return m_position.getValue();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the widget
        ///
        /// @param size  Size of the widget
        ///
        /// Usage examples:
        /// @code
        /// // Give the widget an exact size
        /// widget->setSize({100, 25});
        ///
        /// // Give the widget a size relative to the size of its parent
        /// widget->setPosition({"20%", "5%"});
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(const Layout2d& size)
        {
            m_size = size;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the widget
        ///
        /// @param width   Width of the widget
        /// @param height  Height of the widget
        ///
        /// Usage examples:
        /// @code
        /// // Give the widget an exact size
        /// widget->setSize(100, 25);
        ///
        /// // Give the widget a size relative to the size of its parent
        /// widget->setPosition("20%", "5%");
        /// @endcode
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(Layout width, Layout height)
        {
            setSize({std::move(width), std::move(height)});
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the widget
        ///
        /// @return Size of the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        sf::Vector2f getSize() const
        {
            return m_size.getValue();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the entire size that the widget is using
        ///
        /// This function will return a value equal or greater than what getSize returns.
        /// If the widget would e.g. have borders around it then this function will return the size, including these borders.
        ///
        /// @return Full size of the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::Vector2f getFullSize() const
        {
            return getSize();
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Returns the layout object that is being used for the position
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Layout2d getPositionLayout() const
        {
            return m_position;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Returns the layout object that is being used for the size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Layout2d getSizeLayout() const
        {
            return m_size;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // @brief Updates the position
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updatePosition()
        {
            setPosition(m_position);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // @brief Updates the size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateSize()
        {
            setSize(m_size);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        Layout2d m_position;
        Layout2d m_size;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TRANSFORMABLE_HPP
