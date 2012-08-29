/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (VDV_B@hotmail.com)
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


#ifndef _TGUI_ANIMATED_BUTTON_INCLUDED_
#define _TGUI_ANIMATED_BUTTON_INCLUDED_

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct TGUI_API AnimatedButton : public OBJECT, OBJECT_ANIMATION
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        AnimatedButton();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        AnimatedButton(const AnimatedButton& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~AnimatedButton();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        AnimatedButton& operator= (const AnimatedButton& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void initialize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual AnimatedButton* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Loads the button images and optionally a matching text color.
        ///
        /// All images should have the same size. In calculations, the size of the first normal image is always used.
        ///
        /// \param pathname  The path to the folder that contains the images.
        ///                  The folder must also contain an info.txt file, which will give more information about the button.
        ///
        /// \return
        ///        - true on success
        ///        - false when the pathname is empty
        ///        - false when the info.txt file was not found
        ///        - false when no normal image was loaded
        ///        - false when the images couldn't be loaded
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool load(const std::string pathname);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the button.
        ///
        /// This function will undo all scaling, as it just calculates the correct scale factors for you.
        /// The scaling factors will be based on the size of the first normal image.
        ///
        /// \param width   The new width of the button
        /// \param height  The new height of the button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the button, unaffected by scaling.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2u getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the size of the button, after the scaling transformation.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Vector2f getScaledSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the pathname that was used to load the button.
        ///
        /// When the button has not been loaded yet then this function will return an empty string.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual std::string getLoadedPathname() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the caption of the button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setText(const sf::String text);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the caption of the button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual sf::String getText() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the font of the text.
        ///
        /// When you don't call this function then the global font will be use.
        /// This global font can be changed by changing \a gloabalFont from the parent.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTextFont(const sf::Font& font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the font of the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Font* getTextFont();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the color of the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTextColor(const sf::Color& color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the color of the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual const sf::Color& getTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the character size of the text.
        ///
        /// If the size is 0 (default) then the text will be scaled to fit inside the button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setTextSize(const unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the character size of the text.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getTextSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Sets the animation at a specific frame.
        ///
        /// When there are less frames than \a frame, the last frame will be displayed.
        /// Both 0 and 1 will set the first frame.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setFrame(const unsigned int frame);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are used to receive callback from EventManager.
        // You normally don't need them, but you can use them to simulate an event.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual bool mouseOnObject(float x, float y);
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void keyPressed(sf::Keyboard::Key key);
        virtual void objectFocused();
        virtual void mouseNotOnObject();
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used internally by the load function.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual unsigned int getLoadingID(const std::string property);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // When the elapsed time changes then this function is called.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void update();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Because this struct is derived from sf::Drawable, you can just call the Draw function from your sf::RenderTarget.
        // This function will be called and it will draw the button on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        // The size of the button
        Vector2f m_Size;

        // The SFML textures
        std::vector<sf::Texture*> m_TexturesNormal;
        std::vector<sf::Texture*> m_TexturesMouseHover;
        std::vector<sf::Texture*> m_TexturesMouseDown;
        std::vector<sf::Texture*> m_TexturesFocused;

        // The SFML sprites
        std::vector<sf::Sprite>   m_SpritesNormal;
        std::vector<sf::Sprite>   m_SpritesMouseHover;
        std::vector<sf::Sprite>   m_SpritesMouseDown;
        std::vector<sf::Sprite>   m_SpritesFocused;

        // Frame durations (in milliseconds)
        std::vector<int> m_DurationsNormal;
        std::vector<int> m_DurationsMouseHover;
        std::vector<int> m_DurationsMouseDown;
        std::vector<int> m_DurationsFocused;

        // The pathname used to load the animated button
        std::string m_LoadedPathname;

        // Is there a separate hover image, or is it a semi-transparent image that is drawn on top of the others?
        bool m_SeparateHoverImage;

        // The SFML text
        sf::Text m_Text;

        // This will store the size of the text ( 0 to auto size )
        unsigned int m_TextSize;

        // The frame that is currently displayed
        unsigned int m_CurrentFrame;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_TGUI_ANIMATED_BUTTON_INCLUDED_

