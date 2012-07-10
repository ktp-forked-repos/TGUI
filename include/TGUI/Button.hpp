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


#ifndef _TGUI_BUTTON_INCLUDED_
#define _TGUI_BUTTON_INCLUDED_

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    struct TGUI_API Button : public OBJECT
    {
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Button();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Button(const Button& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ~Button();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Overload of assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Button& operator= (const Button& right);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// The path to the folder that contains the images.
        /// The folder must also contain an info.txt file, which will give more information about the button.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        bool load(const std::string pathname);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Changes the size of the button. Note that this function will undo all scaling, as it just
        /// calculates the correct scale factors for you. It is an alternative to setScale.
        /// Note that the button has to be loaded correctly before calling this function.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(float width, float height);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the size of the button, unaffected by scaling.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2u getSize() const;


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the size of the button, after the scaling transformation.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getScaledSize() const;


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the pathname that was used to load the button.
        /// When the button has not been loaded yet then this function will return an empty string.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        std::string getLoadedPathname();


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Changes the caption of the button.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        void setText(const std::string text);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the caption of the button.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        std::string getText();


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Changes the font of the text. When you don't call this function then the global font will be use.
        /// This global font can be changed by calling the setGlobalFont function from Panel.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextFont(const sf::Font& font);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the font of the text.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Font& getTextFont();


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Changes the color of the text.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(const sf::Color& color);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the color of the text.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        const sf::Color& getTextColor();


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Changes the character size of the text.
        /// If the size is 0 (default) then the text will be scaled to fit inside the button.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextSize(const unsigned int size);


        //////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Returns the character size of the text.
        /// It is possible that this function returns 0, which means that the text is auto-scaled.
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getTextSize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // These functions are used to receive callback from EventManager.
        // You normally don't need them, but you can use them to simulate an event.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool mouseOnObject(float x, float y);
        void leftMousePressed(float x, float y);
        void leftMouseReleased(float x, float y);
        void mouseMoved(float x, float y);
        void keyPressed(sf::Keyboard::Key key);
        void objectFocused();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Because this struct is derived from sf::Drawable, you can just call the Draw function from your sf::RenderTarget.
        /// This function will be called and it will draw the button on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        // The SFML textures
        sf::Texture* m_TextureNormal_L;
        sf::Texture* m_TextureMouseHover_L;
        sf::Texture* m_TextureMouseDown_L;
        sf::Texture* m_TextureFocused_L;

        sf::Texture* m_TextureNormal_M;
        sf::Texture* m_TextureMouseHover_M;
        sf::Texture* m_TextureMouseDown_M;
        sf::Texture* m_TextureFocused_M;

        sf::Texture* m_TextureNormal_R;
        sf::Texture* m_TextureMouseHover_R;
        sf::Texture* m_TextureMouseDown_R;
        sf::Texture* m_TextureFocused_R;

        // The SFML sprites
        sf::Sprite  m_SpriteNormal_L;
        sf::Sprite  m_SpriteMouseHover_L;
        sf::Sprite  m_SpriteMouseDown_L;
        sf::Sprite  m_SpriteFocused_L;

        sf::Sprite  m_SpriteNormal_M;
        sf::Sprite  m_SpriteMouseHover_M;
        sf::Sprite  m_SpriteMouseDown_M;
        sf::Sprite  m_SpriteFocused_M;

        sf::Sprite  m_SpriteNormal_R;
        sf::Sprite  m_SpriteMouseHover_R;
        sf::Sprite  m_SpriteMouseDown_R;
        sf::Sprite  m_SpriteFocused_R;

        // The pathname used to load the button
        std::string m_LoadedPathname;

        // If this is true then the L, M and R images will be used.
        // If it is false then the button is just one big image that will be stored in the M image.
        bool m_SplitImage;

        // Is there a separate hover image, or is it a semi-transparent image that is drawn on top of the others?
        bool m_SeparateHoverImage;

        // The SFML text
        sf::Text m_Text;

        // This will store the size of the text ( 0 to auto size )
        unsigned int m_TextSize;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif //_TGUI_BUTTON_INCLUDED_

