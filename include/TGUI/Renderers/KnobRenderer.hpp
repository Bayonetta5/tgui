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


#ifndef TGUI_KNOB_BAR_RENDERER_HPP
#define TGUI_KNOB_BAR_RENDERER_HPP


#include <TGUI/Renderers/WidgetRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class TGUI_API KnobRenderer : public WidgetRenderer
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KnobRenderer() = default;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Construct the renderer from renderer data
        ///
        /// @param data  Renderer data to initialize the renderer with
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        KnobRenderer(const std::shared_ptr<RendererData>& data)
        {
            setData(data);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the borders
        ///
        /// @param borders  Size of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorders(const Borders& borders);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the borders
        ///
        /// @return border size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Borders getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the knob
        ///
        /// @param color  The new background color
        ///
        /// Note that this color is ignored when you set a background image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color of the knob
        ///
        /// @return Background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the thumb which you can move around the circle
        ///
        /// @param color  The new thumb color
        ///
        /// Note that this color is ignored when you set a foreground image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setThumbColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the thumb color of the thumb which you can move around the circle
        ///
        /// @return Thumb color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getThumbColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the border color
        ///
        /// @param color  The color that is used for the borders that are optionally drawn around the knob
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the border color
        ///
        /// @return Border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background image of the knob
        ///
        /// @param texture  The new background texture
        ///
        /// When this image is set then the background color property will be ignored.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBackground(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background image
        ///
        /// @return Background texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Texture& getTextureBackground() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the foreground image of the knob
        ///
        /// @param texture  The new foreground texture
        ///
        /// The foreground image is the part that is rotated around the center when the value changes.
        ///
        /// When this image is set then the thumb color property will be ignored.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureForeground(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the foreground image
        ///
        /// @return Foreground texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Texture& getTextureForeground() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the default rotation of the foreground texture
        ///
        /// @param rotation  Rotation of the foreground image, which is a value between 0 and 360
        ///
        /// This property defines in which direction the foreground image is pointing.
        /// The rotation is in degrees, starts from the right side and increases when going counter-clockwise.
        ///
        /// This property has no effect when
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setImageRotation(float rotation);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the default rotation of the foreground texture
        ///
        /// @return Rotation of the foreground image, which is a value between 0 and 360
        ///
        /// This property defines in which direction the foreground image is pointing.
        /// The rotation is in degrees, starts from the right side and increases when going counter-clockwise.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getImageRotation() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_KNOB_BAR_RENDERER_HPP